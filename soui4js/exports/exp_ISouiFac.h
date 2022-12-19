#pragma once
#include <interface/SFactory-i.h>


void Exp_ISouiFactory(qjsbind::Module *module)
{
	JsClass<ISouiFactory> jsCls = module->ExportClass<ISouiFactory>("ISouiFactory");
	jsCls.Init(JsClass<IObjRef>::class_id());
	jsCls.AddFunc("CreateApp", &ISouiFactory::CreateApp);
	jsCls.AddFunc("CreateNativeWnd", &ISouiFactory::CreateNativeWnd);
	jsCls.AddFunc("CreateHostWnd", &ISouiFactory::CreateHostWnd);
	jsCls.AddFunc("CreateHostDialog", &ISouiFactory::CreateHostDialog);
	jsCls.AddFunc("CreateStringA", &ISouiFactory::CreateStringA);
	jsCls.AddFunc("CreateStringW", &ISouiFactory::CreateStringW);
	jsCls.AddFunc("CreateXmlDoc", &ISouiFactory::CreateXmlDoc);
	jsCls.AddFunc("CreateResProvider", &ISouiFactory::CreateResProvider);
	jsCls.AddFunc("CreateFuncSlot", &ISouiFactory::CreateFuncSlot);
	jsCls.AddFunc("CreateMenu", &ISouiFactory::CreateMenu);
	jsCls.AddFunc("CreateMenuEx", &ISouiFactory::CreateMenuEx);
	jsCls.AddFunc("CreateTimer", &ISouiFactory::CreateTimer);
}