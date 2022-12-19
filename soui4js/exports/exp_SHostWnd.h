#pragma once
#include <core/SHostDialog.h>
#include <helper/SDpiHelper.hpp>

template<class T>
class JsHostWnd : public T, public JsThisOwner ,public SDpiHandler< JsHostWnd<T> >
{
	typedef SDpiHandler< JsHostWnd<T> > DpiHandler;
public:
	JsHostWnd(LPCSTR pszResID) :T(pszResID) {}

	void SetPresenter(void* presenter) {
		T::SetPresenter((IHostPresenter*)presenter);
	}
	int WINAPI GetScale() const {
		return T::GetScale();
	}
protected:
	BOOL _HandleEvent(IEvtArgs* pEvt) override {
		if (!m_onEvent.IsFunction()) {
			return T::_HandleEvent(pEvt);
		}
		Context* ctx = m_onEvent.context();
		Value args[] = { NewValue(*ctx,pEvt) };
		Value ret = ctx->Call(GetJsThis(), m_onEvent, 1, args);
		if (ret.ToBool())
			return TRUE;
		return T::_HandleEvent(pEvt);
	}

	BOOL ProcessWindowMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT& lResult, DWORD dwMsgMapID) override {
		DpiHandler::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, dwMsgMapID);
		if (!m_onMsg.IsObject())
			return T::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, dwMsgMapID);
		qjsbind::Context& ctx = *m_onMsg.context();
		MsgHandle msgHandle = { TRUE };
		qjsbind::Value args[] = {
			NewValue(ctx, hWnd),
			NewValue(ctx, uMsg),
			NewValue(ctx, wParam),
			NewValue(ctx, lParam),
			NewValue(ctx, &msgHandle)
		};
		Value ret = ctx.Call(GetJsThis(), m_onMsg, 5, args);
		if (ret.IsNumber()) {
			lResult = ret.ToInt32();
		}
		else {
			if (ret.IsException())
				ctx.DumpError();
			msgHandle.msgHandled = FALSE;
		}
		if (msgHandle.msgHandled)
			return TRUE;
		return T::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, dwMsgMapID);
	}

	const WeakValue& GetJsThis() const override {
		if (m_cbHandler.IsObject())
			return m_cbHandler;
		else
			return JsThisOwner::GetJsThis();
	}
public:
	static void Mark(JsHostWnd<T>* pThis, JS_MarkFunc* mark_fun) {
		pThis->m_cbHandler.Mark(mark_fun);
		pThis->m_onMsg.Mark(mark_fun);
		pThis->m_onEvent.Mark(mark_fun);
	}

	Value m_cbHandler;
	Value m_onMsg;
	Value m_onEvent;
};

void Exp_JsHostWnd(qjsbind::Module* module) {
	JsClass<JsHostWnd<SHostWnd> > jsCls = module->ExportClass<JsHostWnd<SHostWnd>>("JsHostWnd");
	jsCls.Init<JsHostWnd<SHostWnd>::Mark>(JsClass<IHostWnd>::class_id());
	jsCls.AddCtor<qjsbind::constructor<JsHostWnd<SHostWnd>, LPCSTR>>(TRUE);
	jsCls.AddFunc("SetPresenter", &JsHostWnd<SHostWnd>::SetPresenter);
	jsCls.AddFunc("GetScale", &JsHostWnd<SHostWnd>::GetScale);
	jsCls.AddGetSet("cbHandler", &JsHostWnd<SHostWnd>::m_cbHandler);
	jsCls.AddGetSet("onEvt", &JsHostWnd<SHostWnd>::m_onEvent);
	jsCls.AddGetSet("onMsg", &JsHostWnd<SHostWnd>::m_onMsg);
}

void Exp_JsHostDialog(qjsbind::Module* module) {
	JsClass<JsHostWnd<SHostDialog> > jsCls = module->ExportClass<JsHostWnd<SHostDialog>>("JsHostDialog");
	jsCls.Init<JsHostWnd<SHostDialog>::Mark>(JsClass<IHostDialog>::class_id());
	jsCls.AddCtor<qjsbind::constructor<JsHostWnd<SHostDialog>, LPCSTR>>(TRUE);
	jsCls.AddFunc("SetPresenter", &JsHostWnd<SHostDialog>::SetPresenter);
	jsCls.AddFunc("GetScale", &JsHostWnd<SHostDialog>::GetScale);
	jsCls.AddGetSet("cbHandler", &JsHostWnd<SHostDialog>::m_cbHandler);
	jsCls.AddGetSet("onEvt", &JsHostWnd<SHostDialog>::m_onEvent);
	jsCls.AddGetSet("onMsg", &JsHostWnd<SHostDialog>::m_onMsg);
}