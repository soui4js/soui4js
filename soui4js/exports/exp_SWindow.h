#pragma once
#include <core/SWnd.h>
#include "toobj.h"

void Exp_SWindow(qjsbind::Module* module) {
	JsClass<SWindow> jsCls = module->ExportClass<SWindow>("SWindow");
	jsCls.Init(JsClass<IWindow>::class_id());
	jsCls.AddFunc("GetWindow", &SWindow::GetWindow);
	jsCls.AddFunc("GetParent", &SWindow::GetParent);
	jsCls.AddFunc("FindChildByID", &SWindow::FindChildByID);
	jsCls.AddFunc("FindChildByName", (SWindow * (SWindow::*)(LPCSTR, int))&SWindow::FindChildByName);
	jsCls.AddFunc( "GetWindowRect2", (CRect(SWindow::*)() const) & SWindow::GetWindowRect);
	jsCls.AddFunc( "GetClientRect2", (CRect(SWindow::*)()const) & SWindow::GetClientRect);
	DEF_CAST_IOBJ(module, SWindow);
}