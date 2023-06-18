#pragma once
#include "jscontext.h"
#include "jsmemfunc.h"
#include "jsproxy.h"
namespace qjsbind {

	template<class T>
	bool GetSafeThis(Context* context, JSValueConst this_val, JsProxy<T>** ptr, JSClassID cid) {
		if (!JS_IsObject(this_val)) {
			return false;
		}

		JSClassID id = JS_GetClassID(this_val);
		if (cid) {
			JSClassID pid = id;
			while (pid) {
				if (pid == cid) {
					//如果id或者其父class id与class_id_相同则允许转换
					*ptr = reinterpret_cast<JsProxy<T>*>(JS_GetOpaque(this_val, id));
					return ptr->valid();
				}
				pid = context->GetParentClassId(pid);
			}
			return false;
		}
		*ptr = reinterpret_cast<JsProxy<T>*>(JS_GetOpaque(this_val, id));
		return ptr->valid();
	}


	template<class T>
	bool GetSafeThis(JSValueConst this_val, JsProxy<T>** ptr) {
		if (!JS_IsObject(this_val)) {
			return false;
		}
		JSClassID id = JS_GetClassID(this_val);

		*ptr = reinterpret_cast<JsProxy<T>*>(JS_GetOpaque(this_val, id));
		return true;
	}


	template<class T>
	void SetSafeThis(JSValueConst this_val, JsProxy<T>* pThis) {
		JS_SetOpaque(this_val, pThis);
	}

	template<typename T, typename FUN>
	JSValue MemFun(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, int magic, JSValue* func_data)
	{
		FUN fun=0;
		Value data(ctx, func_data[0]);
		int64_t addr = data.ToInt64();
		memcpy(&fun, &addr, sizeof(addr));
		JsProxy<T>* pThis;
		if (!GetSafeThis(this_val, &pThis)) {
			JS_ThrowTypeError(ctx, "no this pointer exist");
			return JS_EXCEPTION;
		}

		Context* context = Context::get(ctx);
		ContextState ctxState(ctx);
		ArgList arglist(ctx, argc, argv);
		T* obj = pThis->GetObj();
		return MemFunC(obj, *context, fun, arglist).Release();
	}

	template<typename T, typename MEM>
	JSValue MemGet(JSContext* ctx, JSValueConst this_val, int magic)
	{
		MEM T::* member = NULL;
		memcpy(&member, &magic, 4);
		JsProxy<T> * pThis;
		if (!GetSafeThis(this_val, &pThis)) {
			JS_ThrowTypeError(ctx, "no this pointer exist");
			return JS_EXCEPTION;
		}

		Context* context = Context::get(ctx);
		ContextState ctxState(ctx);
		return NewValue(*context, pThis->GetObj()->*(member)).Release();
	}

	template<typename T>
	void SetValue(T& dst, const Value &src) {
		dst = src;
	}

	template<typename T, typename MEM>
	JSValue MemSet(JSContext* ctx, JSValueConst this_val, JSValueConst val, int magic)
	{
		MEM T::* member = NULL;
		memcpy(&member, &magic, 4);

		JsProxy<T> * pThis;
		if (!GetSafeThis(this_val, &pThis)) {
			JS_ThrowTypeError(ctx, "no this pointer exist");
			return JS_EXCEPTION;
		}

		Context* context = Context::get(ctx);
		ContextState ctxState(ctx);
		Value arg(ctx, val);
		SetValue(pThis->GetObj()->*(member), arg);
		return JS_UNDEFINED;
	}

	template<class T>
	void ObjFinalizer(JSRuntime* rt, JSValue val) {
		JsProxy<T> * pThis;
		if (GetSafeThis(val, &pThis)) {
			delete pThis;
			JS_SetOpaque(val, NULL);
		}
	}
	template<class T, void Mark(T*, JS_MarkFunc*)>
	void ObjMark(JSRuntime* rt, JSValueConst val, JS_MarkFunc* mark_func) {
		JsProxy<T>* pThis;
		if (Mark && GetSafeThis(val, &pThis) && pThis->IsOwner()) {
			Mark(pThis->GetObj(), mark_func);
		}
	}

	template<class T, class RegClass,T* CTor(ArgList &)>
	JSValue ObjConstructor(JSContext* ctx,
		JSValueConst new_target,
		int argc, JSValueConst* argv, int magic) {

		Value proto(ctx, JS_GetPropertyStr(ctx, new_target, "prototype"));
		if (proto.IsException()) {
			return JS_EXCEPTION;
		}
		Value obj(ctx, JS_NewObjectProtoClass(ctx, proto, RegClass::class_id()));
		if (obj.IsException()) {
			return JS_EXCEPTION;
		}

		Context* context = Context::get(ctx);
		ContextState ctxState(ctx);
		ArgList arg_list(ctx, argc, argv);
		T* pObj = CTor(arg_list);
		if (!pObj) {
			return JS_ThrowOutOfMemory(ctx);
		}
		JsProxy<T>* jsPtr = new JsProxy<T>(pObj,true);
		SetSafeThis(obj, jsPtr);
		if (magic != 0) {
			JsThisOwner* pJsThisOwner = (JsThisOwner*)(jsPtr->GetObj());
			pJsThisOwner->SetJsThis(obj);
		}
		return obj.Release();
	}

	template<class T>
	class JsClass {
	protected:
		JSContext* context_;
		Value prototype_;
		Module* module_;
		bool class_inited_;
		const char* class_name_;
	public:
		JsClass(JSContext* context, Module* module, const char* name)
			:context_(context),
			prototype_(context, JS_NewObject(context)),
			module_(module), class_inited_(false), class_name_(name)
		{
			if (class_id_ == 0) {
				JS_NewClassID(&class_id_);
			}
		}
		~JsClass() {
			assert(class_inited_);
		}

		template<void Mark(T*,JS_MarkFunc* markFun)=0>
		void Init(JSClassID parent_id = 0) {
			assert(!class_inited_);

			JSClassDef class_def = {
				class_name_,ObjFinalizer<T>,ObjMark<T,Mark>,nullptr,nullptr
			};

			NewClass(&class_def, parent_id);
		}

		template<T *CTor(ArgList &)=0>
		void AddCtor(BOOL bSetThis=FALSE) {
			JSCFunctionMagic* fun = &ObjConstructor<T, JsClass<T>, CTor>;
			JSValue constructor = JS_NewCFunctionMagic(context_, fun, class_name_, 0, JS_CFUNC_constructor_magic, bSetThis ?1:0);
			JS_SetConstructor(context_, constructor, prototype_);
			module_->Export(class_name_, constructor);
		}

		template<typename MemFunc>
		void AddFunc(const char* name, MemFunc fun) {
			uint64_t magic = 0;
#ifdef _WIN64
			memcpy(&magic, &fun, sizeof(uint64_t));
#else
			memcpy(&magic, &fun, sizeof(fun));
#endif
			JSCFunctionData* mem_func = &MemFun<T, MemFunc>;
			JSValue data = JS_NewInt64(context_, magic);
			JSValue func_value = JS_NewCFunctionData(context_, mem_func, 0, 0, 1, &data);

			JS_DefinePropertyValueStr(context_, prototype_, name, func_value, 0);
			JS_FreeValue(context_, data);
		}

		template<typename Fun>
		void AddCFunc(const char* name, Fun fun) {
			uint64_t magic = 0;
			memcpy(&magic, &fun, sizeof(fun));
			JSValue data = JS_NewInt64(context_, magic);
			JSCFunctionData* cfunc = &CallCFun2<T,Fun>;
			JSValue func_value = JS_NewCFunctionData(context_, cfunc, 0, 0, 1, &data);
			JS_DefinePropertyValueStr(context_, prototype_, name, func_value, 0);
			JS_FreeValue(context_, data);
		}

		template<typename MEM>
		void AddGetSet(const char* name, MEM T::* val) {
			JSCFunctionType get_func;
			get_func.getter_magic = &MemGet<T, MEM>;
			int magic = 0;
			memcpy(&magic, &val, 4);
			JSValue get_func_value = JS_NewCFunction2(context_, get_func.generic, name, 0, JS_CFUNC_getter_magic, magic);
			JSCFunctionType set_func;
			set_func.setter_magic = &MemSet<T, MEM>;
			JSValue set_func_value = JS_NewCFunction2(context_, set_func.generic, name, 1, JS_CFUNC_setter_magic, magic);
			auto atom = JS_NewAtom(context_, name);
			JS_DefinePropertyGetSet(context_, prototype_, atom, get_func_value, set_func_value, 0);
			JS_FreeAtom(context_, atom);
		}

		template<typename MEM>
		void AddGet(const char* name, MEM T::* val) {
			JSCFunctionType get_func;
			get_func.getter_magic = &MemGet<T, MEM>;
			int magic = 0;
			memcpy(&magic, &val, 4);
			JSValue get_func_value = JS_NewCFunction2(context_, get_func.generic, name, 0, JS_CFUNC_getter_magic, magic);
			auto atom = JS_NewAtom(context_, name);
			JS_DefineProperty(context_, prototype_, atom, JS_UNDEFINED, get_func_value, JS_UNDEFINED,
				JS_PROP_HAS_GET | JS_PROP_HAS_CONFIGURABLE | JS_PROP_HAS_ENUMERABLE);
			JS_FreeValue(context_, get_func_value);
			JS_FreeAtom(context_, atom);

		}

		template<typename MEM>
		void AddSet(const char* name, MEM T::* val) {
			int magic = 0;
			memcpy(&magic, &val, 4);
			JSCFunctionType set_func;
			set_func.setter_magic = &MemSet<T, MEM>;
			JSValue set_func_value = JS_NewCFunction2(context_, set_func.generic, name, 1, JS_CFUNC_setter_magic, magic);
			auto atom = JS_NewAtom(context_, name);
			JS_DefineProperty(context_, prototype_, atom, JS_UNDEFINED, JS_UNDEFINED, set_func_value,
				JS_PROP_HAS_SET | JS_PROP_HAS_CONFIGURABLE | JS_PROP_HAS_ENUMERABLE);
			JS_FreeValue(context_, set_func_value);
			JS_FreeAtom(context_, atom);
		}

		static JSClassID class_id() {
			return class_id_;
		}
	private:
		void NewClass(JSClassDef* class_def, JSClassID parent_id = 0) {
			assert(!class_inited_);
			JS_NewClass(JS_GetRuntime(context_), class_id_, class_def);
			JS_SetClassProto(context_, class_id_, prototype_.CopyValue());
			class_inited_ = true;

			if (parent_id) {
				Context::get(context_)->AddClassId(class_id_, parent_id);
				JSValue parent = JS_GetClassProto(context_, parent_id);
				if (JS_IsObject(parent)) {
					JS_SetPrototype(context_, prototype_, parent);
				}
				else {
					JS_ThrowInternalError(context_, "invalied parent class id %u", parent_id);
				}
				JS_FreeValue(context_, parent);
			}
		}

		static JSClassID class_id_;
	};


	template<class T>
	JSClassID JsClass<T>::class_id_ = 0;

}//namespace


