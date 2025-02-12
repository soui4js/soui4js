#ifndef __QJSBIND__H__
#define __QJSBIND__H__
//gcc判断是否是64位
#if defined(__x86_64__) && !defined(_WIN64) 
#define _WIN64
#endif
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


#endif // __QJSBIND__H__