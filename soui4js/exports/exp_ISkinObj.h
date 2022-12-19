#pragma once
#include <interface/SSkinobj-i.h>

void Exp_ISkinObj(qjsbind::Module* module){
	JsClass<ISkinObj> jsCls = module->ExportClass<ISkinObj>("ISkinObj");
	jsCls.Init(JsClass<IObject>::class_id());
    jsCls.AddFunc("DrawByState2", &ISkinObj::DrawByState2);
    jsCls.AddFunc("DrawByState", &ISkinObj::DrawByState);
    jsCls.AddFunc("DrawByIndex2", &ISkinObj::DrawByIndex2);
    jsCls.AddFunc("DrawByIndex", &ISkinObj::DrawByIndex);
    jsCls.AddFunc("GetSkinSize", &ISkinObj::GetSkinSize);
    jsCls.AddFunc("GetStates", &ISkinObj::GetStates);
    jsCls.AddFunc("GetAlpha", &ISkinObj::GetAlpha);
    jsCls.AddFunc("SetAlpha", &ISkinObj::SetAlpha);
    jsCls.AddFunc("GetScale", &ISkinObj::GetScale);
    jsCls.AddFunc("Scale", &ISkinObj::Scale);
}