#pragma once
#include <interface/SNcPainter-i.h>

void Exp_INcPainter(qjsbind::Module* module)
{
	JsClass<INcPainter> jsCls = module->ExportClass<INcPainter>("INcPainter");
	jsCls.Init(JsClass<IObject>::class_id());
	jsCls.AddFunc("GetRoot", &INcPainter::GetRoot);
}