#ifndef __EXP_SHOSTWND__H__
#define __EXP_SHOSTWND__H__
#include <core/SHostDialog.h>
#include <helper/SDpiHelper.hpp>
#include <set>
#include "exp_MsgHandlerProxy.h"

#define ANY_CTRL_ID -1
#define ANY_CTRL_NAME "*"

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

	void RequireEventForCtrlID(int evt,int nCtrlId, bool bSet) {
		std::pair<int,int> data = std::make_pair(evt, nCtrlId);
		if (bSet)
			m_cbEvt4Ids.insert(data);
		else
			m_cbEvt4Ids.erase(data);
	}

	void RequireEventForCtrlName(int evt, LPCSTR pszCtrlName, bool bSet) {
		std::pair<int,std::string> data = std::make_pair(evt, std::string(pszCtrlName));
		if (bSet)
			m_cbEvt4Names.insert(data);
		else
			m_cbEvt4Names.erase(data);
	}

	void RequireMessage(UINT msg, bool bSet) {
		if (bSet)
			m_cbMsgs.insert(msg);
		else
			m_cbMsgs.erase(msg);
	}
protected:
	BOOL _HandleEvent(IEvtArgs* pEvt) override {
		if(!pEvt || !pEvt->Sender() || !m_onEvent.IsFunction()) {
			return T::_HandleEvent(pEvt);
		}
		BOOL bJsEvt = m_cbEvt4Names.empty() && m_cbEvt4Ids.empty();
		if(pEvt->GetID() == EventInit::EventID || pEvt->GetID()==EventExit::EventID){
			// 处理初始化和退出事件
			bJsEvt = TRUE;
		}
		if(!bJsEvt && pEvt->Sender()->GetName()) {
			auto it = m_cbEvt4Names.find(std::make_pair(pEvt->GetID(), std::string(S_CW2A(pEvt->Sender()->GetName(),CP_UTF8))));
			if (it != m_cbEvt4Names.end()) {
				bJsEvt = TRUE;
			}else{
				it = m_cbEvt4Names.find(std::make_pair(pEvt->GetID(), std::string(ANY_CTRL_NAME)));
				if (it != m_cbEvt4Names.end()) {
					bJsEvt = TRUE;
				}
			}
		}
		if (!bJsEvt) {
			auto it = m_cbEvt4Ids.find(std::make_pair(pEvt->GetID(), pEvt->Sender()->GetID()));
			if (it != m_cbEvt4Ids.end()) {
				bJsEvt = TRUE;
			}
			else
			{
				it = m_cbEvt4Ids.find(std::make_pair(pEvt->GetID(), ANY_CTRL_ID));
				if (it != m_cbEvt4Ids.end()) {
					bJsEvt = TRUE;
				}
			}
		}
		if (bJsEvt) {
			Context* ctx = m_onEvent.context();
			Value args[] = { NewValue(*ctx,pEvt) };
			Value ret = ctx->Call(GetJsThis(), m_onEvent, 1, args);
			if (ret.ToBool())
				return TRUE;
		}
		return T::_HandleEvent(pEvt);
	}

	BOOL ProcessWindowMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT& lResult, DWORD dwMsgMapID) override {
		DpiHandler::ProcessWindowMessage(hWnd, uMsg, wParam, lParam, lResult, dwMsgMapID);
		BOOL bHandled = FALSE;
		do {
			if (!m_onMsg.IsObject())
				break;
			if (!m_cbMsgs.empty() && m_cbMsgs.find(uMsg) == m_cbMsgs.end())
				break;
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
			bHandled = msgHandle.msgHandled;
		} while (FALSE);
		if (bHandled) {
			return TRUE;
		}
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
	std::set<std::pair<int,int>> m_cbEvt4Ids;
	std::set<std::pair<int, std::string>> m_cbEvt4Names;
	std::set<int> m_cbMsgs;
};

void Exp_JsHostWnd(qjsbind::Module* module) {
	JsClass<JsHostWnd<SHostWnd> > jsCls = module->ExportClass<JsHostWnd<SHostWnd>>("JsHostWnd");
	jsCls.Init<JsHostWnd<SHostWnd>::Mark>(JsClass<IHostWnd>::class_id());
	jsCls.AddCtor<qjsbind::constructor<JsHostWnd<SHostWnd>, LPCSTR>>(TRUE);
	jsCls.AddFunc("RequireEventForCtrlID", &JsHostWnd<SHostWnd>::RequireEventForCtrlID);
	jsCls.AddFunc("RequireEventForCtrlName", &JsHostWnd<SHostWnd>::RequireEventForCtrlName);
	jsCls.AddFunc("RequireMessage", &JsHostWnd<SHostWnd>::RequireMessage);
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
	jsCls.AddFunc("RequireEventForCtrlID", &JsHostWnd<SHostDialog>::RequireEventForCtrlID);
	jsCls.AddFunc("RequireEventForCtrlName", &JsHostWnd<SHostDialog>::RequireEventForCtrlName);
	jsCls.AddFunc("RequireMessage", &JsHostWnd<SHostDialog>::RequireMessage);
	jsCls.AddFunc("SetPresenter", &JsHostWnd<SHostDialog>::SetPresenter);
	jsCls.AddFunc("GetScale", &JsHostWnd<SHostDialog>::GetScale);
	jsCls.AddGetSet("cbHandler", &JsHostWnd<SHostDialog>::m_cbHandler);
	jsCls.AddGetSet("onEvt", &JsHostWnd<SHostDialog>::m_onEvent);
	jsCls.AddGetSet("onMsg", &JsHostWnd<SHostDialog>::m_onMsg);
}
#endif // __EXP_SHOSTWND__H__