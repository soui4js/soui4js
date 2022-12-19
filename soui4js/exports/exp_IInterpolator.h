#pragma once
#include <interface/sinterpolator-i.h>


void Exp_IInterpolator(qjsbind::Module* module)
{
	JsClass<IInterpolator> jsCls = module->ExportClass<IInterpolator>("IInterpolator");
	jsCls.Init(JsClass<IObject>::class_id());
	jsCls.AddFunc("getInterpolation", &IInterpolator::getInterpolation);
}