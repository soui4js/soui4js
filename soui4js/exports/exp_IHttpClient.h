#pragma once
#include <interface/SHttpClient-i.h>
#include <helper/SFunctor.hpp>

#include <map>
#include <string>
#include <atomic>
using namespace std;

IHttpClient* CreateHttpClient();
class HttpRequest : public TObjRefImpl< IHttpCallback>{
private:
	SAutoRefPtr<IHttpClient> m_http;
	string m_url;
	string m_method;
	map<string, string> m_headers;
	SAutoRefPtr<IMessageLoop> m_msgLoop;
	BOOL m_bAsync;
	volatile BOOL m_bCanceled;
	int  m_timeout[3];
	int  m_opaque;
	HANDLE m_evt;
	atomic_bool m_bRunning;
public:
	Value m_cbHandler;
	Value m_onResp;
	Value m_onError;
	Value m_onProg;

	static void Mark(HttpRequest* pThis, JS_MarkFunc* mark_fun)
	{
		pThis->m_cbHandler.Mark(mark_fun);
		pThis->m_onResp.Mark(mark_fun);
		pThis->m_onError.Mark(mark_fun);
		pThis->m_onProg.Mark(mark_fun);
	}

private:
	void OnSucceed(int respCode, const string& resp) {
		if (m_onResp.IsFunction()) {
			Context* ctx = m_onResp.context();
			Value args[3] = {
				NewValue(*ctx, m_opaque),
				NewValue(*ctx, respCode),
				NewValue(*ctx, resp),
			};
			ctx->Call(m_cbHandler, m_onResp, 3, args);
		}
	}
	void OnError(int err) {
		if (m_onError.IsFunction()) {
			Context* ctx = m_onError.context();
			Value args[2] = { 
				NewValue(*ctx, m_opaque),
				NewValue(*ctx, err) 
			};
			ctx->Call(m_cbHandler, m_onError, 2, args);
		}
	}
	BOOL OnProg(DownloadState state, uint64_t nTotalSize, uint64_t nLoadSize) {
		if (m_onProg.IsFunction()) {
			Context* ctx = m_onProg.context();
			Value args[4] = { 
				NewValue(*ctx, m_opaque),
				NewValue(*ctx, int(state)),
				NewValue(*ctx, nTotalSize),
				NewValue(*ctx, nLoadSize),
			};
			Value ret = ctx->Call(m_cbHandler, m_onProg, 4, args);
			return ret.ToBool();
		}
		return TRUE;
	}
public:
	HttpRequest(LPCSTR pszUrl, LPCSTR pszMethod):m_bAsync(FALSE), m_bCanceled(FALSE){
		m_http.Attach(CreateHttpClient());
		m_url = pszUrl;
		m_method = pszMethod;
		m_opaque = 0;
		m_bRunning = false;
		m_evt = CreateEvent(NULL, FALSE, FALSE, NULL);
		m_timeout[0] = m_timeout[1] = m_timeout[2] = 1000;
		m_msgLoop = SApplication::getSingletonPtr()->GetMsgLoop();//get main msg loop
	}
	~HttpRequest() {
		if (m_bRunning) {
			WaitForSingleObject(m_evt, INFINITE);
		}
		CloseHandle(m_evt);
		m_msgLoop->RemoveTasksForObject(this);
	}
	void SetTimeout(int dwConnectTime, int dwSendTime, int dwRecvTime) {
		m_timeout[0] = dwConnectTime;
		m_timeout[1] = dwSendTime;
		m_timeout[2] = dwRecvTime;
	}

	void SetHeader(LPCSTR pszKey, LPCSTR pszValue) {
		m_headers[pszKey] = pszValue;
	}

	void SetOpaque(int opaque) {
		m_opaque = opaque;
	}

	BOOL DownloadFile(LPCSTR pszFileName) {
		return Run(pszFileName);
	}

	BOOL Execute() {
		return Run(NULL);
	}

	void Cancel() {
		if (m_bAsync) {
			m_bCanceled = TRUE;
			WaitForSingleObject(m_evt, INFINITE);
		}
	}
protected:
	BOOL Run(LPCSTR pszFileName) {
		if (m_bRunning)
			return FALSE;
		std::string strFileName(pszFileName? pszFileName:"");
		if (m_http) {
			m_http->SetDownloadCallback(this);
			m_http->SetTimeOut(m_timeout[0], m_timeout[1], m_timeout[2]);
			for (auto it : m_headers) {
				m_http->SetHeader(it.first.c_str(), it.second.c_str());
			}
			ITaskLoop* pTaskLoop = SApplication::getSingletonPtr()->GetTaskLoop();
			m_bCanceled = FALSE;
			if (!pTaskLoop) {
				m_bAsync = FALSE;
				if (!strFileName.empty()) {
					BOOL bRet = m_http->DownloadFile(m_url.c_str(), strFileName.c_str());
					_OnResult(bRet, "");
				}
				else {
					SStringA ret;
					BOOL bRet = m_http->Request(&ret, m_url.c_str(), m_method.compare("get") == 0 ? Hr_Get : Hr_Post);
					_OnResult(bRet, string(ret.c_str(), ret.GetLength()));
				}
			}
			else {
				m_bAsync = TRUE;
				m_bRunning = true;
				ResetEvent(m_evt);	//clear event state.
				STaskHelper::post(pTaskLoop, this, &HttpRequest::_OnExecute, strFileName, false);
			}
		}
		return TRUE;
	}

	STDMETHOD_(BOOL, OnDownloadCallback)(THIS_  DownloadState state, uint64_t nTotalSize, uint64_t nLoadSize) OVERRIDE {
		if (m_bAsync) {
			//run on task loop
			if (m_bCanceled)
				return FALSE;
			STaskHelper::post(m_msgLoop, this, &HttpRequest::_OnDownloadCallback,  state, nTotalSize, nLoadSize);
			return TRUE;
		}
		else {
			//run on main thread
			return _OnDownloadCallback(state, nTotalSize, nLoadSize);
		}
	}
private:
	void _OnExecute(const std::string &strFileName) //run on task loop
	{
		if (strFileName.empty()) {
			SStringA ret;
			BOOL bRet = m_http->Request(&ret, m_url.c_str(), m_method.compare("get") == 0 ? Hr_Get : Hr_Post);
			STaskHelper::post(m_msgLoop, this, &HttpRequest::_OnResult, bRet, string(ret.c_str(), ret.GetLength()));//switch to main thread
		}
		else {
			BOOL bRet = m_http->DownloadFile(m_url.c_str(), strFileName.c_str());
			STaskHelper::post(m_msgLoop, this, &HttpRequest::_OnResult, bRet, "");//switch to main thread
		}
		m_bRunning = false;
		SetEvent(m_evt);
	}
	
	BOOL _OnDownloadCallback(DownloadState state, uint64_t nTotalSize, uint64_t nLoadSize){
		return !OnProg(state, nTotalSize, nLoadSize);
	}

	void _OnResult(BOOL bSucceed, const string& resp) {
		if (bSucceed) {
			OnSucceed(m_http->GetHttpCode(), resp);
		}
		else {
			OnError(m_http->GetErrorCode());
		}
	}
};

void Exp_IHttpClient(qjsbind::Module* module)
{
	JsClass<IHttpClient> jsCls = module->ExportClass<IHttpClient>("IHttpClient");
	jsCls.Init(JsClass<IObjRef>::class_id());
	jsCls.AddFunc("SetDownloadCallback", &IHttpClient::SetDownloadCallback);
	jsCls.AddFunc("DownloadFile", &IHttpClient::DownloadFile);
	jsCls.AddFunc("DownloadToMem", &IHttpClient::DownloadToMem);
	jsCls.AddFunc("GetErrorCode", &IHttpClient::GetErrorCode);
	jsCls.AddFunc("Request", &IHttpClient::Request);
	jsCls.AddFunc("GetHttpCode", &IHttpClient::GetHttpCode);
}

void Exp_HttpRequest(qjsbind::Module* module) {
	JsClass<HttpRequest> jsCls = module->ExportClass<HttpRequest>("HttpRequest");
	jsCls.Init(JsClass<IObjRef>::class_id());
	jsCls.AddCtor<constructor<HttpRequest, LPCSTR, LPCSTR>>();
	jsCls.AddFunc("SetHeader", &HttpRequest::SetHeader);
	jsCls.AddFunc("SetTimeout", &HttpRequest::SetTimeout);
	jsCls.AddFunc("Execute", &HttpRequest::Execute);
	jsCls.AddFunc("DownloadFile", &HttpRequest::DownloadFile);
	jsCls.AddFunc("SetOpaque", &HttpRequest::SetOpaque);
	jsCls.AddFunc("Cancel", &HttpRequest::Cancel);
	jsCls.AddGetSet("cbHandler", &HttpRequest::m_cbHandler);
	jsCls.AddGetSet("onResp", &HttpRequest::m_onResp);
	jsCls.AddGetSet("onError", &HttpRequest::m_onError);
	jsCls.AddGetSet("onProg", &HttpRequest::m_onProg);
}