#ifndef __EXP_IWINDOW__H__
#define __EXP_IWINDOW__H__
#include <interface/SWindow-i.h>
#include "toobj.h"

Value IWindow_GetWindowText(Context* ctx, IWindow* _this, ArgList& args) {
	bool bRawText = FALSE;
	if (args.size() >= 1) bRawText = args[0].ToBool();
	SStringA strU8;
	_this->GetWindowTextU8(&strU8, bRawText);
	return ctx->NewString(strU8.c_str(), strU8.GetLength());
}

CRect IWindow_GetWindowRect(Context* ctx, IWindow* _this, ArgList& args) {
	CRect rc;
	_this->GetWindowRect(&rc);
	return rc;
}

CRect IWindow_GetClientRect(Context* ctx, IWindow* _this, ArgList& args) {
	CRect rc;
	_this->GetClientRect(&rc);
	return rc;
}

SIZE IWindow_GetDesiredSize(Context* ctx, IWindow* _this, ArgList& args) {
	SIZE ret = { 0,0 };
	int nWid = -1, nHei = -1;
	if (args.size() >= 1) nWid = args[0];
	if (args.size() >= 2) nHei = args[1];

	_this->GetDesiredSize(&ret, nWid, nHei);
	return ret;
}

CRect IWindow_GetChildrenLayoutRect(Context* ctx, IWindow* _this, ArgList& args) {
	CRect rc = { 0 };
	_this->GetChildrenLayoutRect(&rc);
	return rc;
}

LRESULT IWindow_SSendMessage(Context* ctx, IWindow* _this, ArgList& args) {
	if (args.size() == 0)
		return -1;
	int msg = args[0];
	WPARAM wp = 0;
	LPARAM lp = 0;
	if (args.size() > 1)
		wp = args[1];
	if (args.size() > 2)
		lp = args[2];
	return _this->SSendMessage(msg, wp, lp, NULL);
}

void IWindow_SDispatchMessage(Context* ctx, IWindow* _this, ArgList& args) {
	if (args.size() == 0)
		return;
	int msg = args[0];
	WPARAM wp = 0;
	LPARAM lp = 0;
	if (args.size() > 1)
		wp = args[1];
	if (args.size() > 2)
		lp = args[2];
	_this->SDispatchMessage(msg, wp, lp);
}

void Exp_IWindow(qjsbind::Module* module)
{
	JsClass<IWindow> jsCls = module->ExportClass<IWindow>("IWindow");
	jsCls.Init(JsClass<IObject>::class_id());

	jsCls.AddFunc("GetContainer", &IWindow::GetContainer);
	jsCls.AddFunc("SetContainer", &IWindow::SetContainer);
	jsCls.AddFunc("GetSwnd", &IWindow::GetSwnd);
	jsCls.AddFunc("GetLayout", &IWindow::GetLayout);
	jsCls.AddFunc("GetLayoutParam", &IWindow::GetLayoutParam);
	jsCls.AddFunc("SetLayoutParam", &IWindow::SetLayoutParam);
	jsCls.AddFunc("IsFloat", &IWindow::IsFloat);
	jsCls.AddFunc("IsDisplay", &IWindow::IsDisplay);
	jsCls.AddFunc("IsMsgTransparent", &IWindow::IsMsgTransparent);
	jsCls.AddFunc("IsClipClient", &IWindow::IsClipClient);
	jsCls.AddFunc("SetToolTipText", &IWindow::SetToolTipTextU8);
	jsCls.AddFunc("IsChecked", &IWindow::IsChecked);
	jsCls.AddFunc("SetCheck", &IWindow::SetCheck);
	jsCls.AddFunc("IsDisabled", &IWindow::IsDisabled);
	jsCls.AddFunc("EnableWindow", &IWindow::EnableWindow);

	jsCls.AddFunc("IsVisible", &IWindow::IsVisible);
	jsCls.AddFunc("SetVisible", &IWindow::SetVisible);
	jsCls.AddFunc("GetUserData", &IWindow::GetUserData);
	jsCls.AddFunc("SetUserData", &IWindow::SetUserData);
	jsCls.AddFunc("DoColorize", &IWindow::DoColorize);
	jsCls.AddFunc("GetColorizeColor", &IWindow::GetColorizeColor);
	jsCls.AddCFunc("SSendMessage", &IWindow_SSendMessage);
	jsCls.AddCFunc("SDispatchMessage", &IWindow_SDispatchMessage);
	jsCls.AddFunc("IsFocusable", &IWindow::IsFocusable);
	jsCls.AddFunc("IsFocused", &IWindow::IsFocused);
	jsCls.AddFunc("SetFocus", &IWindow::SetFocus);
	jsCls.AddFunc("KillFocus", &IWindow::KillFocus);
	jsCls.AddFunc("Invalidate", &IWindow::Invalidate);
	jsCls.AddFunc("InvalidateRect", &IWindow::InvalidateRect);

	jsCls.AddFunc("LockUpdate", &IWindow::LockUpdate);
	jsCls.AddFunc("UnlockUpdate", &IWindow::UnlockUpdate);
	jsCls.AddFunc("IsUpdateLocked", &IWindow::IsUpdateLocked);
	jsCls.AddFunc("Update", &IWindow::Update);
	jsCls.AddFunc("SetWindowRgn", &IWindow::SetWindowRgn);
	jsCls.AddFunc("GetWindowRgn", &IWindow::GetWindowRgn);
	jsCls.AddFunc("SetWindowPath", &IWindow::SetWindowPath);
	jsCls.AddFunc("GetWindowPath", &IWindow::GetWindowPath);
	jsCls.AddFunc("Move2", &IWindow::Move2);
	jsCls.AddFunc("Move", &IWindow::Move);
	jsCls.AddCFunc("GetWindowRect", &IWindow_GetWindowRect);
	jsCls.AddCFunc("GetClientRect", &IWindow_GetClientRect);

	jsCls.AddFunc("IsContainPoint", &IWindow::IsContainPoint);
	jsCls.AddFunc("SwndFromPoint", &IWindow::SwndFromPoint);
	jsCls.AddFunc("SetTimer", &IWindow::SetTimer);
	jsCls.AddFunc("KillTimer", &IWindow::KillTimer);
	jsCls.AddFunc("GetCapture", &IWindow::GetCapture);
	jsCls.AddFunc("SetCapture", &IWindow::SetCapture);
	jsCls.AddFunc("ReleaseCapture", &IWindow::ReleaseCapture);
	jsCls.AddFunc("SetAnimation", &IWindow::SetAnimation);
	jsCls.AddFunc("StartAnimation", &IWindow::StartAnimation);
	jsCls.AddFunc("GetAnimation", &IWindow::GetAnimation);
	jsCls.AddFunc("ClearAnimation", &IWindow::ClearAnimation);

	jsCls.AddFunc("SetAlpha", &IWindow::SetAlpha);
	jsCls.AddFunc("GetAlpha", &IWindow::GetAlpha);
	jsCls.AddFunc("SetMatrix", &IWindow::SetMatrix);
	jsCls.AddFunc("GetMatrix", &IWindow::GetMatrix);
	jsCls.AddFunc("GetScale", &IWindow::GetScale);
	jsCls.AddFunc("RequestRelayout", &IWindow::RequestRelayout);
	jsCls.AddFunc("UpdateLayout", &IWindow::UpdateLayout);
	jsCls.AddFunc("UpdateChildrenPosition", &IWindow::UpdateChildrenPosition);
	jsCls.AddFunc("IsLayoutDirty", &IWindow::IsLayoutDirty);
	jsCls.AddFunc("OnGetDlgCode", &IWindow::OnGetDlgCode);
	jsCls.AddFunc("GetIRoot", &IWindow::GetIRoot);
	jsCls.AddFunc("GetIParent", &IWindow::GetIParent);


	jsCls.AddFunc("GetIWindow", &IWindow::GetIWindow);
	jsCls.AddFunc("GetIChild", &IWindow::GetIChild);
	jsCls.AddFunc("GetChildrenCount", &IWindow::GetChildrenCount);
	jsCls.AddFunc("IsDescendant", &IWindow::IsDescendant);
	jsCls.AddFunc("SetIOwner", &IWindow::SetIOwner);
	jsCls.AddFunc("GetIOwner", &IWindow::GetIOwner);
	jsCls.AddFunc("BringWindowToTop", &IWindow::BringWindowToTop);
	jsCls.AddFunc("AdjustIZOrder", &IWindow::AdjustIZOrder);
	jsCls.AddFunc("InsertIChild", &IWindow::InsertIChild);
	jsCls.AddFunc("RemoveIChild", &IWindow::RemoveIChild);
	jsCls.AddFunc("CreateChildrenFromXml", &IWindow::CreateChildrenFromXml);
	jsCls.AddFunc("CreateChildrenFromResId", &IWindow::CreateChildrenFromResId);

	jsCls.AddFunc("FindIChildByID", &IWindow::FindIChildByID);
	jsCls.AddFunc("FindIChildByName", &IWindow::FindIChildByNameA);

	jsCls.AddFunc("DestroyIChild", &IWindow::DestroyIChild);
	jsCls.AddFunc("DestroyAllChildren", &IWindow::DestroyAllChildren);
	jsCls.AddFunc("Destroy", &IWindow::Destroy);
	jsCls.AddFunc("GetNextLayoutIChild", &IWindow::GetNextLayoutIChild);
	jsCls.AddCFunc("GetChildrenLayoutRect", &IWindow_GetChildrenLayoutRect);
	jsCls.AddFunc("GetBkgndColor", &IWindow::GetBkgndColor);
	jsCls.AddFunc("SetWindowText", &IWindow::SetWindowTextU8);
	jsCls.AddCFunc("GetWindowText", &IWindow_GetWindowText);
	jsCls.AddFunc("GetState", &IWindow::GetState);
	jsCls.AddFunc("ModifyState", &IWindow::ModifyState);

	jsCls.AddFunc("GetISelectedSiblingInGroup", &IWindow::GetISelectedSiblingInGroup);
	jsCls.AddFunc("GetISelectedChildInGroup", &IWindow::GetISelectedChildInGroup);
	jsCls.AddFunc("IsSiblingsAutoGroupped", &IWindow::IsSiblingsAutoGroupped);
	jsCls.AddFunc("CreateCaret", &IWindow::CreateCaret);
	jsCls.AddFunc("ShowCaret", &IWindow::ShowCaret);
	jsCls.AddFunc("SetCaretPos", &IWindow::SetCaretPos);
	jsCls.AddFunc("SetEventMute", &IWindow::SetEventMute);
	jsCls.AddFunc("SubscribeEvent", &IWindow::SubscribeEvent);
	jsCls.AddFunc("UnsubscribeEvent", &IWindow::UnsubscribeEvent);
	jsCls.AddFunc("AddEvent", &IWindow::AddEvent);
	jsCls.AddFunc("RemoveEvent", &IWindow::RemoveEvent);
	jsCls.AddFunc("FireEvent", &IWindow::FireEvent);
	jsCls.AddFunc("FireCommand", &IWindow::FireCommand);

	jsCls.AddFunc("FireCtxMenu", &IWindow::FireCtxMenu);
	jsCls.AddFunc("SwndProc", &IWindow::SwndProc);
	jsCls.AddFunc("SetSwndProc", &IWindow::SetSwndProc);
	jsCls.AddFunc("GetHostHwnd", &IWindow::GetHostHwnd);
	jsCls.AddFunc("GetContainer", &IWindow::GetContainer);
	jsCls.AddFunc("RegisterDragDrop", &IWindow::RegisterDragDrop);
	jsCls.AddFunc("UnregisterDragDrop", &IWindow::UnregisterDragDrop);
	jsCls.AddCFunc("GetDesiredSize", &IWindow_GetDesiredSize);

	DEF_CAST_IOBJ(module, IWindow);
}

#endif // __EXP_IWINDOW__H__