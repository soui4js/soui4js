#pragma once
#include <qjsbind.h>

using namespace qjsbind;

BOOL QjsFunMsgHandler(const LPMSG pMsg, LRESULT* pRes, void* ctx);

struct MsgHandle {
	BOOL msgHandled;
};

class MsgHandlerProxy {
public:
	MsgHandlerProxy(){
	}

	~MsgHandlerProxy() {
	}
public:
	BOOL OnMsg(HWND hWnd, UINT uMsg, WPARAM wp, LPARAM lp,LRESULT *pRes) {
		if (!m_msgHandler.IsObject())
			return FALSE;
		MsgHandle msgHandle = { TRUE };
		qjsbind::Value args[5];
		qjsbind::Context & ctx = *m_msgHandler.context();
		args[0] = NewValue(ctx,hWnd);
		args[1] = NewValue(ctx, uMsg);
		args[2]= NewValue(ctx, wp);
		args[3] = NewValue(ctx, lp);
		args[4] = NewValue(ctx, &msgHandle);
		Value ret = m_msgHandler.context()->Call(m_thisObj,m_msgHandler, 5, args);
		if (ret.IsNumber()) {
			*pRes = ret.ToInt32();
			return msgHandle.msgHandled;
		}
		else {
			if(ret.IsException())
				ctx.DumpError();
			return FALSE;
		}
	}

	bool InstallHook(INativeWnd* pNativeWnd, qjsbind::Value& thisObj, qjsbind::Value& fun) {
		if (!(thisObj.IsObject() && fun.IsFunction()))
			return false;
		m_thisObj = thisObj;
		m_msgHandler = fun;
		pNativeWnd->SetMsgHandler(QjsFunMsgHandler, this);
		return true;
	}

	void UninstallHook(INativeWnd* pNativeWnd) {
		pNativeWnd->SetMsgHandler(NULL, NULL);
		m_thisObj = Value();
		m_msgHandler = Value();
	}
private:
	qjsbind::Value m_thisObj;
	qjsbind::Value m_msgHandler;
};

BOOL QjsFunMsgHandler(const LPMSG pMsg, LRESULT* pRes, void* ctx) {
	MsgHandlerProxy* proxy = (MsgHandlerProxy*)ctx;
	return proxy->OnMsg(pMsg->hwnd, pMsg->message, pMsg->wParam, pMsg->lParam, pRes);
}

void Exp_MsgHandlerProxy(qjsbind::Module *module) {
	{
		JsClass<MsgHandlerProxy> jsCls = module->ExportClass<MsgHandlerProxy>("MsgHandlerProxy");
		jsCls.Init();
		jsCls.AddCtor<constructor<MsgHandlerProxy>>();
		jsCls.AddFunc("InstallHook", &MsgHandlerProxy::InstallHook);
		jsCls.AddFunc("UninstallHook", &MsgHandlerProxy::UninstallHook);
	}
	{
		JsClass<MsgHandle> jsCls = module->ExportClass<MsgHandle>("MsgHandle");
		jsCls.Init();
		jsCls.AddGetSet("msgHandled",&MsgHandle::msgHandled);
	}
}