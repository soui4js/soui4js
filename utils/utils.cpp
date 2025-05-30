// dui-demo.cpp : main source file
//

#include "stdafx.h"
#include <quickjs.h>
#include <qjsbind.h>
#include "exp_utils.h"

#ifdef _WIN32
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API __attribute__((visibility("default")))
#endif
#ifdef _WIN32
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
#endif
extern "C"
EXPORT_API JSModuleDef* js_init_module(JSContext* ctx, const char* module_name)
{
	qjsbind::Context* context = qjsbind::Context::get(ctx);
	if(!context)
		context = new qjsbind::Context(ctx);
	qjsbind::Module *module = context->NewModule(module_name);
	Exp_Utils(module);
	return module->module();
}

extern "C"
EXPORT_API void js_uninit_module(JSContext * ctx)
{
	qjsbind::Context* context = qjsbind::Context::get(ctx);
	if(context && context->isAttached())
		delete context;
}
