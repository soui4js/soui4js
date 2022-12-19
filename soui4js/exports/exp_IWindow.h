#pragma once
#include <interface/SWindow-i.h>
#include "toobj.h"

Value IWindow_GetWindowText(Context* ctx, IWindow* _this, ArgList& args) {
	bool bRawText = FALSE;
	if (args.size() >= 1) bRawText = args[0].ToBool();
	SStringT str;
	int bufLen = _this->GetWindowText(NULL, 0, bRawText);
	TCHAR* buf = str.GetBufferSetLength(bufLen);
	_this->GetWindowText(buf, bufLen, bRawText);
	str.ReleaseBuffer();
	SStringA strU8 = S_CT2A(str, CP_UTF8);
	return ctx->NewString(strU8.c_str(), strU8.GetLength());
}

RECT IWindow_GetWindowRect(Context* ctx, IWindow* _this, ArgList& args) {
	RECT rc;
	_this->GetWindowRect(&rc);
	return rc;
}

RECT IWindow_GetClientRect(Context* ctx, IWindow* _this, ArgList& args) {
	RECT rc;
	_this->GetClientRect(&rc);
	return rc;
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
	jsCls.AddFunc("SetToolTipText", &IWindow::SetToolTipTextA);
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
	jsCls.AddFunc("SSendMessage", &IWindow::SSendMessage);
	jsCls.AddFunc("SDispatchMessage", &IWindow::SDispatchMessage);
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
	jsCls.AddFunc("GetChildrenLayoutRect", &IWindow::GetChildrenLayoutRect);
	jsCls.AddFunc("GetDesiredSize", &IWindow::GetDesiredSize);
	jsCls.AddFunc("GetBkgndColor", &IWindow::GetBkgndColor);
	jsCls.AddFunc("SetWindowText", &IWindow::SetWindowTextA);
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

	DEF_CAST_IOBJ2(module, IWindow,SWindow);
}
