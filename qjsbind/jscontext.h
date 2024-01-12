#pragma once
#include <unordered_map>
#include <functional>
#include <memory>
#include <stack>
#include "jsvalue.h"
#include "jsarglist.h"

namespace qjsbind {
	class Runtime;
	class Module;
	class ContextState {
	public:
		ContextState(JSContext* ctx) {
			s_ctxStack.push(ctx);
		}
		~ContextState() {
			s_ctxStack.pop();
		}

		static JSContext* GetCurrentCtx() {
			if (s_ctxStack.empty())
				return NULL;
			return s_ctxStack.top();
		}
	private:
		static std::stack<JSContext*> s_ctxStack;
	};

	typedef void (*LogFun)(const char* log);

	class Context {
	public:
		Context(Runtime* runtime);
		Context(JSContext* context);
		~Context();

		bool isAttached() const { return is_attach_; }

		JSRuntime* runtime() {
			return JS_GetRuntime(context_);
		}

		JSContext* context() {
			return context_;
		}

		static Context* get(JSContext* ctx) {
			return reinterpret_cast<Context*>(
				JS_GetContextOpaque(ctx));
		}

		void SetLogFunc(LogFun func) {
			log_func_ = func;
		}

		Value ParseJson(const char* buf, size_t buf_len,
			const char* filename);

		//new
		Value NewNull();

		Value NewBool(bool v);
		Value NewInt32(int32_t v);
		Value NewInt64(int64_t v);
		Value NewUint32(uint32_t v);
		Value NewBigInt64(int32_t v);
		Value NewBigUint64(int64_t v);
		Value NewFloat64(double v);

		Value NewString(const char* str, size_t len);


		Value NewObject();
		Value NewArray();

		template<typename T>
		Value NewValue(T v) {
			return undefined_value;
		}
		template<>
		Value NewValue(int32_t v) {
			return NewInt32(v);
		}
		template<>
		Value NewValue(char v) {
			return NewInt32(v);
		}
		template<>
		Value NewValue(unsigned char v) {
			return NewInt32(v);
		}
		template<>
		Value NewValue(short v) {
			return NewInt32(v);
		}
		template<>
		Value NewValue(unsigned short v) {
			return NewInt32(v);
		}
		template<>
		Value NewValue(uint32_t v) {
			return NewUint32(v);
		}
		template<>
		Value NewValue(float v) {
			return NewFloat64(v);
		}
		template<>
		Value NewValue(double v) {
			return NewFloat64(v);
		}
		template<typename T>
		Value NewArray(const T* v, int len) {
			Value ret = NewArray();
			for (int i = 0; i < 6; i++) {
				JS_SetPropertyInt64(context_, ret, i, NewValue(v[i]));
			}
			JS_SetProperty(context_, ret, 48, NewInt64(6));//48 == JS_Atom_length
			return ret;
		}

		//创建class的对象
		Value NewClassObject(JSClassID class_id);

		Value NewArrayBuffer(const uint8_t* buf, size_t len);

		Value NewUint8ArrayBuffer(const uint8_t* buf, size_t len);

		/* Note: at least 'length' arguments will be readable in 'argv' */
		Value NewCFunction(JSCFunction* func, const char* name, size_t length);


		Value Global();

		Value Eval(const char* input, int input_len,
			const char* filename, int flags= JS_EVAL_TYPE_MODULE | JS_EVAL_FLAG_STRICT);

		Value Compile(const char* input, int input_len,
			const char* filename);

		Value Call(const WeakValue &thisObj, const Value &fun, int cArg, Value* pArg) const {
			if (!fun.IsFunction())
				return Value(context_, JS_EXCEPTION);
			JSValue* pArgValue = NULL;
			if (cArg > 0) {
				pArgValue = new JSValue[cArg];
				for (int i = 0; i < cArg; i++) {
					pArgValue[i] = (JSValue)pArg[i];
				}
			}

			JSValue rslt = JS_Call(context_, fun, thisObj, cArg, pArgValue);
			if (pArgValue) {
				delete[]pArgValue;
			}
			if (JS_IsException(rslt)) {
				DumpError();
			}
			return Value(context_, rslt);
		}

		Value Invoke(Value thiz,const char* func_name,int cArg, Value *pArg) const {
			auto atom = JS_NewAtom(context_, func_name);
			JSValue* pArgValue = NULL;
			if (cArg > 0) {
				pArgValue = new JSValue[cArg];
				for (int i = 0; i < cArg; i++) {
					pArgValue[i] = (JSValue)pArg[i];
				}
			}
			JSValue thisObj = thiz;
			if (thiz.IsNull())
				thisObj = JS_GetGlobalObject(context_);
			JSValue rslt = JS_Invoke(context_, thisObj, atom, cArg, pArgValue);
			JS_FreeAtom(context_, atom);
			if (pArgValue) {
				delete[]pArgValue;
			}
			if (JS_IsException(rslt)) {
				DumpError();
			}
			return Value(context_, rslt);
		}

		//返回false，调用DumpError()查看错误
		bool LoadByteCode(const uint8_t* buf, size_t buf_len);

		void ExecuteJobs();

		void DumpError() const;

		//创建模块
		Module* NewModule(const char* name);

		Value ThrowOutOfMemory();

		void RunGC() {
			JS_RunGC(JS_GetRuntime(context_));
		}

		void Log(const std::string& msg) {
			if (log_func_)
				log_func_(msg.c_str());
		}

		void AddClassId(JSClassID classid, JSClassID parent_classid);
		JSClassID GetParentClassId(JSClassID classid);

	private:
		QJS_DISALLOW_COPY_AND_ASSIGN(Context);

		friend class Value;
		friend class Module;

		std::unique_ptr<Module> GetModule(JSModuleDef* m);

		JSContext* context_;
		std::map<JSModuleDef*, std::unique_ptr<Module>> modules_;

		LogFun log_func_;
		bool   is_attach_;
		//存储classid，及其父classid
		std::unordered_map<JSClassID, JSClassID> class_ids_;
	};


	inline 	Value Context::ParseJson(const char* buf, size_t buf_len,
		const char* filename) {
		return Value(context_, JS_ParseJSON(context_, buf, buf_len, filename));
	}

	inline Value Context::NewNull() {
		return Value(context_, JS_NULL);
	}

	inline Value Context::NewBool(bool v) {
		return Value(context_, JS_NewBool(context_, v));
	}


	inline Value Context::NewInt32(int32_t v) {
		return Value(context_, JS_NewInt32(context_, v));
	}


	inline Value Context::NewInt64(int64_t v) {
		return Value(context_, JS_NewInt64(context_, v));
	}


	inline Value Context::NewUint32(uint32_t v) {
		return Value(context_, JS_NewUint32(context_, v));
	}


	inline Value Context::NewBigInt64(int32_t v) {
		return Value(context_, JS_NewBigInt64(context_, v));
	}


	inline Value Context::NewBigUint64(int64_t v) {
		return Value(context_, JS_NewBigUint64(context_, v));
	}


	inline Value Context::NewFloat64(double v) {
		return Value(context_, JS_NewFloat64(context_, v));
	}
	inline Value Context::NewString(const char* str, size_t len) {
		return Value(context_, JS_NewStringLen(context_, str, len));
	}

	inline Value Context::NewObject() {
		return Value(context_, JS_NewObject(context_));
	}

	inline Value Context::NewArray() {
		return Value(context_, JS_NewArray(context_));
	}

	inline Value Context::NewClassObject(JSClassID class_id) {
		return Value(context_, JS_NewObjectClass(context_, class_id));
	}

	inline Value Context::NewArrayBuffer(const uint8_t* buf, size_t len) {
		return Value(context_, JS_NewArrayBufferCopy(context_, buf, len));
	}

	inline Value Context::NewCFunction(JSCFunction* func, const char* name, size_t length) {
		return Value(context_, JS_NewCFunction(context_, func, name, (int)length));
	}


	inline Value Context::Global() {
		return Value(context_, JS_GetGlobalObject(context_));
	}

	inline Value Context::Eval(const char* input, int input_len,
		const char* filename, int flags) {
		if (input_len <= 0) input_len = (int)strlen(input);
		return Value(context_, JS_Eval(context_, input, input_len, filename,
			flags));
	}


	inline Value Context::Compile(const char* input, int input_len,
		const char* filename) {
		if (input_len <= 0) input_len = (int)strlen(input);
		return Value(context_, JS_Eval(context_, input, input_len, filename,
			JS_EVAL_TYPE_MODULE | JS_EVAL_FLAG_STRICT | JS_EVAL_FLAG_COMPILE_ONLY));
	}
}
