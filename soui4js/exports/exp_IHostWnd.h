#pragma once
#include <interface/SHostWnd-i.h>

void Exp_IHostWnd(qjsbind::Module* module)
{
	JsClass<IHostWnd> jsCls = module->ExportClass<IHostWnd>("IHostWnd");
	jsCls.Init(JsClass<INativeWnd>::class_id());
	jsCls.AddFunc("CreateEx", &IHostWnd::CreateEx);
	jsCls.AddFunc("Create", &IHostWnd::Create);
	jsCls.AddFunc("SetLayoutId", &IHostWnd::SetLayoutId);
	jsCls.AddFunc("GetIRoot", &IHostWnd::GetIRoot);
	jsCls.AddFunc("FindIChildByID", &IHostWnd::FindIChildByID);
	jsCls.AddFunc("FindIChildByName", &IHostWnd::FindIChildByNameA);
	jsCls.AddFunc("GetNcPainter", &IHostWnd::GetNcPainter);
	jsCls.AddFunc("SetEventHandler", &IHostWnd::SetEventHandler);
	jsCls.AddFunc("GetEventHandler", &IHostWnd::GetEventHandler);
	jsCls.AddFunc("AnimateHostWindow", &IHostWnd::AnimateHostWindow);
	jsCls.AddFunc("GetPresenter", &IHostWnd::GetPresenter);
	jsCls.AddFunc("SetPresenter", &IHostWnd::SetPresenter);
	jsCls.AddFunc("GetMsgLoop", &IHostWnd::GetMsgLoop);
	jsCls.AddFunc("EnableDragDrop", &IHostWnd::EnableDragDrop);

}

void Exp_IHostDialog(qjsbind::Module* module)
{
	JsClass<IHostDialog> jsCls = module->ExportClass<IHostDialog>("IHostDialog");
	jsCls.Init(JsClass<IHostWnd>::class_id());
	jsCls.AddFunc("DoModal", &IHostDialog::DoModal);
	jsCls.AddFunc("EndDialog", &IHostDialog::EndDialog);

}