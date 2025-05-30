﻿#ifndef __EXP_IHOSTWND__H__
#define __EXP_IHOSTWND__H__
#include <interface/shostwnd-i.h>

void Exp_IHostWnd(qjsbind::Module* module)
{
	JsClass<IHostWnd> jsCls = module->ExportClass<IHostWnd>("IHostWnd");
	jsCls.Init(JsClass<INativeWnd>::class_id());
	jsCls.AddFunc("CreateEx", &IHostWnd::CreateEx);
	jsCls.AddFunc("Create", &IHostWnd::Create);
	jsCls.AddFunc("InitFromXml", &IHostWnd::InitFromXml);
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
	jsCls.AddFunc("ShowHostWnd", &IHostWnd::ShowHostWnd);
	jsCls.AddFunc("EnablePrivateUiDef", &IHostWnd::EnablePrivateUiDef);
}

INT_PTR IHostDialog_DoModal(Context* ctx, IHostDialog* _this, ArgList& args)
{
	HWND hParent = 0;
	DWORD dwStyle = 0;
	DWORD dwExStyle = 0;
	if (args.size() >=1 ) {
		hParent = (HWND)args[0];
	}
	if (args.size() >= 2) {
		dwStyle = args[1].ToInt32();
	}
	if (args.size() >= 3) {
		dwExStyle = args[2].ToInt32();
	}
	return _this->DoModal(hParent, dwStyle, dwExStyle);
}

void Exp_IHostDialog(qjsbind::Module* module)
{
	JsClass<IHostDialog> jsCls = module->ExportClass<IHostDialog>("IHostDialog");
	jsCls.Init(JsClass<IHostWnd>::class_id());
	jsCls.AddCFunc("DoModal", &IHostDialog_DoModal);
	jsCls.AddFunc("EndDialog", &IHostDialog::EndDialog);

}
#endif // __EXP_IHOSTWND__H__