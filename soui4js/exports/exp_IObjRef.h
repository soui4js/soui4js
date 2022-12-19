#pragma once
#include <interface/obj-ref-i.h>

void Exp_IObjRef(qjsbind::Module* module)
{
	JsClass<IObjRef> jsCls = module->ExportClass<IObjRef>("IObjRef");
	jsCls.Init();
	jsCls.AddFunc("AddRef", &IObjRef::AddRef);
	jsCls.AddFunc("Release", &IObjRef::Release);
	jsCls.AddFunc("OnFinalRelease", &IObjRef::OnFinalRelease);
}
