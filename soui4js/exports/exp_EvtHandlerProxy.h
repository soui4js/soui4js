#pragma once
#include <qjsbind.h>

using namespace qjsbind;

BOOL QjsEvtHandler(IEvtArgs* pEvt, void* ctx);

class EvtHandlerProxy {
public:
	EvtHandlerProxy(){
	}
	~EvtHandlerProxy() {
	}

public:
	BOOL OnEvent(IEvtArgs* e) {
		if (!m_evtHandler.IsObject())
			return FALSE;
		qjsbind::Context& ctx = *m_evtHandler.context();
		qjsbind::Value arg = NewValue(ctx, e);
		Value ret = m_evtHandler.context()->Call(m_thisObj, m_evtHandler, 1, &arg);
		if (ret.IsBool()) {
			return ret.ToBool();
		}
		else {
			if (ret.IsException())
				ctx.DumpError();
			return FALSE;
		}
	}

	bool InstallHook(IHostWnd* pHostWnd, qjsbind::Value& thisObj, qjsbind::Value& fun) {
		if (!(thisObj.IsObject() && fun.IsFunction()))
			return false;

		m_thisObj = thisObj;
		m_evtHandler = fun;
		pHostWnd->SetEventHandler(QjsEvtHandler, this);
		return true;
	}

	void UninstallHook(IHostWnd* pHostWnd) {
		pHostWnd->SetEventHandler(NULL, NULL);
		m_thisObj = Value();
		m_evtHandler = Value();
	}
private:
	qjsbind::Value m_thisObj;
	qjsbind::Value m_evtHandler;
};

BOOL QjsEvtHandler(IEvtArgs* pEvt, void* ctx) {
	EvtHandlerProxy* proxy = (EvtHandlerProxy*)ctx;
	return proxy->OnEvent(pEvt);
}

void Exp_EvtHandlerProxy(qjsbind::Module *module) {
	JsClass<EvtHandlerProxy> jsCls = module->ExportClass<EvtHandlerProxy>("EvtHandlerProxy");
	jsCls.Init();
	jsCls.AddCtor<constructor<EvtHandlerProxy>>();
	jsCls.AddFunc("InstallHook", &EvtHandlerProxy::InstallHook);
	jsCls.AddFunc("UninstallHook", &EvtHandlerProxy::UninstallHook);
}