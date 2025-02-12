#ifndef __EXP_ITIMER__H__
#define __EXP_ITIMER__H__
#include <interface/STimer-i.h>

void Exp_ITimer(qjsbind::Module* module)
{
	JsClass<ITimer> jsCls = module->ExportClass<ITimer>("ITimer");
	jsCls.Init(JsClass<IObjRef>::class_id());
	jsCls.AddFunc("StartTimer", &ITimer::StartTimer);
	jsCls.AddFunc("KillTimer", &ITimer::KillTimer);
}

#endif // __EXP_ITIMER__H__