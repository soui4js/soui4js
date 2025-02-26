#ifndef _JS_MODULE_H_
#define _JS_MODULE_H_

#include <quickjs.h>
#include <quickjs-libc.h>
#include <utility>
#include <memory>
#include <map>
#include <assert.h>
#include "jsvalue.h"
#include "jscontext.h"

namespace qjsbind{
    
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
    
}

#endif//_JS_MODULE_H_