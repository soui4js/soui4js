#pragma once
#include "jsvalue.h"

namespace qjsbind {
	class Runtime {
	public:
		Runtime()
			:runtime_(JS_NewRuntime())
		{
			JS_SetModuleLoaderFunc(runtime_, NULL, js_module_loader, js_module_unloader,NULL);
			js_std_init_handlers(runtime_);
			JS_SetHostPromiseRejectionTracker(runtime_, PromiseRejectionTracker, NULL);
		}

		~Runtime() {
			js_std_free_handlers(runtime_);
			JS_FreeRuntime(runtime_);
		}

		void SetRuntimeInfo(const char* info) {
			JS_SetRuntimeInfo(runtime_, info);
		}

		void SetMemoryLimit(size_t limit) {
			JS_SetMemoryLimit(runtime_, limit);
		}

		void SetGCThreshold(size_t gc_threshold) {
			JS_SetGCThreshold(runtime_, gc_threshold);
		}

		void SetMaxStackSize(size_t stack_size) {
			JS_SetMaxStackSize(runtime_, stack_size);
		}

		JSRuntime* runtime() {
			return runtime_;
		}
	private:
		static void PromiseRejectionTracker(JSContext* ctx, JSValueConst promise,
			JSValueConst reason,
			JS_BOOL is_handled, void* opaque);
		friend class Context;
		QJS_DISALLOW_COPY_AND_ASSIGN(Runtime);
		JSRuntime* runtime_;
	};


}