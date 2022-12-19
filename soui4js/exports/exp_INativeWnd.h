#pragma once
#include <interface/SNativeWnd-i.h>

void Exp_INativeWnd(qjsbind::Module* module)
{
	JsClass<INativeWnd> jsCls = module->ExportClass<INativeWnd>("INativeWnd");
	jsCls.Init(JsClass<IObjRef>::class_id());
	jsCls.AddFunc("CreateNative", &INativeWnd::CreateNative);
	jsCls.AddFunc("GetHwnd", &INativeWnd::GetHwnd);
	jsCls.AddFunc("SubclassWindow", &INativeWnd::SubclassWindow);
	jsCls.AddFunc("UnsubclassWindow", &INativeWnd::UnsubclassWindow);
	jsCls.AddFunc("GetCurrentMessage", &INativeWnd::GetCurrentMessage);
	jsCls.AddFunc("GetDlgCtrlID", &INativeWnd::GetDlgCtrlID);
	jsCls.AddFunc("GetStyle", &INativeWnd::GetStyle);
	jsCls.AddFunc("GetExStyle", &INativeWnd::GetExStyle);
	jsCls.AddFunc("GetWindowLongPtr", &INativeWnd::GetWindowLongPtr);
	jsCls.AddFunc("SetWindowLongPtr", &INativeWnd::SetWindowLongPtr);

	jsCls.AddFunc("GetParent", &INativeWnd::GetParent);
	jsCls.AddFunc("SetParent", &INativeWnd::SetParent);
	jsCls.AddFunc("IsWindowEnabled", &INativeWnd::IsWindowEnabled);
	jsCls.AddFunc("ModifyStyle", &INativeWnd::ModifyStyle);
	jsCls.AddFunc("ModifyStyleEx", &INativeWnd::ModifyStyleEx);
	jsCls.AddFunc("SetWindowPos", &INativeWnd::SetWindowPos);
	jsCls.AddFunc("CenterWindow", &INativeWnd::CenterWindow);
	jsCls.AddFunc("DestroyWindow", &INativeWnd::DestroyWindow);
	jsCls.AddFunc("IsWindow", &INativeWnd::IsWindow);
	jsCls.AddFunc("Invalidate", &INativeWnd::Invalidate);
	jsCls.AddFunc("InvalidateRect", &INativeWnd::InvalidateRect);
	jsCls.AddFunc("GetWindowRect", &INativeWnd::GetWindowRect);
	jsCls.AddFunc("GetClientRect", &INativeWnd::GetClientRect);
	jsCls.AddFunc("ClientToScreen", &INativeWnd::ClientToScreen);
	jsCls.AddFunc("ClientToScreen2", &INativeWnd::ClientToScreen2);
	jsCls.AddFunc("ScreenToClient", &INativeWnd::ScreenToClient);
	jsCls.AddFunc("ScreenToClient2", &INativeWnd::ScreenToClient2);
	jsCls.AddFunc("MapWindowPoints", &INativeWnd::MapWindowPoints);
	jsCls.AddFunc("MapWindowRect", &INativeWnd::MapWindowRect);
	jsCls.AddFunc("SetTimer", &INativeWnd::SetTimer);
	jsCls.AddFunc("KillTimer", &INativeWnd::KillTimer);

	jsCls.AddFunc("GetDC", &INativeWnd::GetDC);
	jsCls.AddFunc("GetWindowDC", &INativeWnd::GetWindowDC);
	jsCls.AddFunc("ReleaseDC", &INativeWnd::ReleaseDC);
	jsCls.AddFunc("CreateCaret", &INativeWnd::CreateCaret);
	jsCls.AddFunc("HideCaret", &INativeWnd::HideCaret);
	jsCls.AddFunc("ShowCaret", &INativeWnd::ShowCaret);
	jsCls.AddFunc("GetCapture", &INativeWnd::GetCapture);
	jsCls.AddFunc("SetCapture", &INativeWnd::SetCapture);
	jsCls.AddFunc("ReleaseCapture", &INativeWnd::ReleaseCapture);
	jsCls.AddFunc("SetFocus", &INativeWnd::SetFocus);
	jsCls.AddFunc("SendMessage", &INativeWnd::SendMessage);
	jsCls.AddFunc("PostMessage", &INativeWnd::PostMessage);
	jsCls.AddFunc("SendNotifyMessage", &INativeWnd::SendNotifyMessage);
	jsCls.AddFunc("SetWindowText", &INativeWnd::SetWindowText);
	jsCls.AddFunc("GetWindowText", &INativeWnd::GetWindowText);
	jsCls.AddFunc("IsIconic", &INativeWnd::IsIconic);

	jsCls.AddFunc("IsZoomed", &INativeWnd::IsZoomed);
	jsCls.AddFunc("IsWindowVisible", &INativeWnd::IsWindowVisible);
	jsCls.AddFunc("MoveWindow", &INativeWnd::MoveWindow);
	jsCls.AddFunc("MoveWindow2", &INativeWnd::MoveWindow2);
	jsCls.AddFunc("ShowWindow", &INativeWnd::ShowWindow);
	jsCls.AddFunc("SetWindowRgn", &INativeWnd::SetWindowRgn);
	jsCls.AddFunc("SetLayeredWindowAttributes", &INativeWnd::SetLayeredWindowAttributes);
	jsCls.AddFunc("UpdateLayeredWindow", &INativeWnd::UpdateLayeredWindow);
	jsCls.AddFunc("SetMsgHandler", &INativeWnd::SetMsgHandler);
	jsCls.AddFunc("GetMsgHandler", &INativeWnd::GetMsgHandler);
}
