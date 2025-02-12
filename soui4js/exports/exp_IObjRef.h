#ifndef __EXP_IOBJREF__H__
#define __EXP_IOBJREF__H__
#include <interface/obj-ref-i.h>

void Exp_IObjRef(qjsbind::Module* module)
{
	JsClass<IObjRef> jsCls = module->ExportClass<IObjRef>("IObjRef");
	jsCls.Init();
	jsCls.AddFunc("AddRef", &IObjRef::AddRef);
	jsCls.AddFunc("Release", &IObjRef::Release);
	jsCls.AddFunc("OnFinalRelease", &IObjRef::OnFinalRelease);
}

#endif // __EXP_IOBJREF__H__