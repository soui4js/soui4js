#pragma once
#include <interface/SEvtArgs-i.h>

void Exp_IEvtArg(qjsbind::Module* module)
{
	JsClass<IEvtArgs> jsCls = module->ExportClass<IEvtArgs>("IEvtArgs");
	jsCls.Init(JsClass<IObject>::class_id());
	jsCls.AddFunc("Sender", &IEvtArgs::Sender);
	jsCls.AddFunc("IdFrom", &IEvtArgs::IdFrom);
	jsCls.AddFunc("SetIdFrom", &IEvtArgs::SetIdFrom);
	jsCls.AddFunc("NameFrom", &IEvtArgs::NameFrom);
	jsCls.AddFunc("SetNameFrom", &IEvtArgs::SetNameFrom);
	jsCls.AddFunc("IsBubbleUp", &IEvtArgs::IsBubbleUp);
	jsCls.AddFunc("SetBubbleUp", &IEvtArgs::SetBubbleUp);
	jsCls.AddFunc("HandleCount", &IEvtArgs::HandleCount);
	jsCls.AddFunc("IncreaseHandleCount", &IEvtArgs::IncreaseHandleCount);
	jsCls.AddFunc("Data", &IEvtArgs::Data);
}

void Exp_IEvtSlot(qjsbind::Module* module)
{
	JsClass<IEvtSlot> jsCls = module->ExportClass<IEvtSlot>("IEvtSlot");
	jsCls.Init(JsClass<IObject>::class_id());

	jsCls.AddFunc( "Run", &IEvtSlot::Run);
	jsCls.AddFunc( "Clone", &IEvtSlot::Clone);
	jsCls.AddFunc( "Equal", &IEvtSlot::Equal);
	jsCls.AddFunc( "GetSlotType", &IEvtSlot::GetSlotType);

}
