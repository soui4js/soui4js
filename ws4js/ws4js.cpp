// dui-demo.cpp : main source file
//

#include "stdafx.h"
#include <qjsbind.h>
#include "exp_ws.h"

extern "C"
__declspec(dllexport) JSModuleDef* js_init_module(JSContext* ctx, const char* module_name)
{
	qjsbind::Context* context = qjsbind::Context::get(ctx);
	if (!context)
		context = new qjsbind::Context(ctx);
	qjsbind::Module *module = context->NewModule(module_name);
	Exp_Ws(module);
	return module->module();
}

extern "C"
__declspec(dllexport) void js_uninit_module(JSContext * ctx)
{
	qjsbind::Context* context = qjsbind::Context::get(ctx);
	if (context && context->isAttached())
		delete context;
}
