#pragma once
#include <quickjs.h>
#include <quickjs-libc.h>
#include <utility>
#include <memory>
#include <map>
#include <unordered_map>
#include <string>
#include <array>
#include <functional>
#include <assert.h>
#include "jsvalue.h"
#include "jsarglist.h"
#include "jsclass.h"
#include "jscontext.h"
#include "jsruntime.h"
#include "jsgfunc.h"
#include "jsconstructor.h"

namespace qjsbind {

template<typename FUN>
JSValue CallCFun(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, int magic, JSValue* func_data) {
	ArgList arg_list(ctx, argc, argv);
	FUN fun;
	Value data(ctx, func_data[0]);
	int64_t addr = data.ToInt64();
	memcpy(&fun, &addr, sizeof(fun));
	ContextState ctxState(ctx);
	Context* context = Context::get(ctx);
	return CFun(*context,fun, arg_list).Release();
}

template<typename T,typename FUN>
JSValue CallCFun2(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, int magic, JSValue* func_data) {
	ArgList arg_list(ctx, argc, argv);
	FUN fun;
	Value data(ctx, func_data[0]);
	int64_t addr = data.ToInt64();
	memcpy(&fun, &addr, sizeof(fun));

	JsProxy<T>* pThis;
	if (!GetSafeThis(this_val, &pThis)) {
		JS_ThrowTypeError(ctx, "no this pointer exist");
		return JS_EXCEPTION;
	}

	ContextState ctxState(ctx);
	Context* context = Context::get(ctx);
	return CFun2(*context, fun, pThis->GetObj(), arg_list).Release();
}

//用于导出模块
class Module {
public:
	Module(JSContext* ctx, const char* name);
	~Module();

public:
	//导出到模块
	bool Export(const char* name, const Value& value);
	bool Export(const char* name, JSValue value);

public:
	template<typename Fun>
	bool ExportFunc(const char* name, Fun fun) {
		uint64_t funData = 0;
		memcpy(&funData, &fun, sizeof(fun));
		JSValue data = JS_NewInt64(context_, funData);
		JSCFunctionData* cfunc = &CallCFun<Fun>;
		JSValue func_value = JS_NewCFunctionData(context_, cfunc, 0, 0, 1, &data);

		return Export(name, func_value);
	}

	template<class T>
	JsClass<T> ExportClass(const char* name) {
		return JsClass<T>(context_, this, name);
	}

	bool ExportEnumInt32(const char* name, int value) {
		JSValue data = JS_NewInt32(context_, value);
		return Export(name, data);
	}
	
	bool ExportEnumUint32(const char* name, int value) {
		JSValue data = JS_NewUint32(context_, value);
		return Export(name, data);
	}

	bool ExportEnumUint64(const char* name, uint64_t value) {
		JSValue data = JS_NewInt64(context_, value);
		return Export(name, data);
	}

	Value GetImportMeta();

	JSModuleDef* module() {
		return module_;
	}

	inline JSContext* context() {
		return context_;
	}
private:
	QJS_DISALLOW_COPY_AND_ASSIGN(Module);
	static int OnInit(JSContext* ctx, JSModuleDef* m);
	JSContext* context_;
	JSModuleDef* module_;
	std::map<std::string, Value> exports_;
};


class Promise {
public:
	Promise(JSContext* ctx)
		:ctx_(ctx)
	{
		init();
	}

	Promise(Context& ctx)
		:ctx_(ctx.context())
	{
		init();
	}

	void init() {
		JSValue rfuncs[2];
		promise_ = JS_NewPromiseCapability(ctx_, rfuncs);
		if (JS_IsException(promise_)) {
			rfuncs_[0] = JS_UNDEFINED;
			rfuncs_[1] = JS_UNDEFINED;
		}
		else {
			rfuncs_[0] = rfuncs[0];
			rfuncs_[1] = rfuncs[1];
		}
	}
	~Promise() {
		JS_FreeValue(ctx_, rfuncs_[0]);
		JS_FreeValue(ctx_, rfuncs_[1]);
		JS_FreeValue(ctx_, promise_);
	}

	Value promise() {
		return Value(ctx_, promise_);
	}

	enum Type {
		kResolve,
		kReject,
	};

	void Mark(JS_MarkFunc* mark_func) {
		JSRuntime* runtime = JS_GetRuntime(ctx_);
		JS_MarkValue(runtime, promise_, mark_func);
		JS_MarkValue(runtime, rfuncs_[0], mark_func);
		JS_MarkValue(runtime, rfuncs_[1], mark_func);
	}

	Value Resolve(Value val) {
		JSValue argv = val;
		JSValue ret = JS_Call(ctx_, rfuncs_[kResolve], JS_UNDEFINED, 1, &argv);
		return Value(ctx_, std::move(ret));
	}

	Value Resolve() {
		JSValue ret = JS_Call(ctx_, rfuncs_[kResolve], JS_UNDEFINED, 0, NULL);
		return Value(ctx_, std::move(ret));
	}

	Value Reject(Value val) {
		JSValue argv = val;
		JSValue ret = JS_Call(ctx_, rfuncs_[kReject], JS_UNDEFINED, 1, &argv);
		return Value(ctx_, std::move(ret));
	}

	Value Reject() {
		JSValue ret = JS_Call(ctx_, rfuncs_[kReject], JS_UNDEFINED, 0, NULL);
		return Value(ctx_, std::move(ret));
	}

	void Clear() {
		JS_FreeValue(ctx_, rfuncs_[0]);
		rfuncs_[0] = JS_UNDEFINED;
		JS_FreeValue(ctx_, rfuncs_[1]);
		rfuncs_[1] = JS_UNDEFINED;
		JS_FreeValue(ctx_, promise_);
		promise_ = JS_UNDEFINED;
	}

	JSContext* context() { return ctx_; }
private:
	QJS_DISALLOW_COPY_AND_ASSIGN(Promise);
	JSContext* ctx_;
	JSValue promise_;
	JSValue rfuncs_[2];
};


}//namespace

