#pragma once
#include <qjsbind.h>
#include <ws-i.h>

using namespace qjsbind;
using namespace SOUI;

class WsClient;
class WsConnListener : public TObjRefImpl<IConnListener> {
	WsClient* m_pOwner;
public:
	WsConnListener(WsClient* pOwner);

protected:
	void onConnected() override;
	void onConnError(const char* errStr) override;
	void onDisconnect() override;
	void onDataSent(int nMsgId) override;
	void onDataRecv(const void* data, int len, bool bBinary) override;
};

enum {
	allowSelfSigned=1,
	skipServerCertHostnameCheck=2,
	allowExpired=4
};

class WsLoader;
class WsClient : public JsThisOwner
{
	WsLoader* m_wsLoader;
	friend class WsConnListener;
public:
	WsClient(LPCSTR url, LPCSTR protocol, int opt=0, LPCSTR ca=NULL);

	~WsClient();

	int sendText(LPCSTR pszText,int len);
	int sendBinary(const void *buf, int len);
protected:
	virtual const WeakValue& GetJsThis() const override {
		if (m_cbHandler.IsObject())
			return m_cbHandler;
		else
			return JsThisOwner::GetJsThis();
	}

public:
	static void Mark(WsClient* pThis, JS_MarkFunc* mark_fun) {
		pThis->m_cbHandler.Mark(mark_fun);
		pThis->m_onConnected.Mark(mark_fun);
		pThis->m_onClose.Mark(mark_fun);
		pThis->m_onError.Mark(mark_fun);
		pThis->m_onText.Mark(mark_fun);
		pThis->m_onBinary.Mark(mark_fun);
		pThis->m_onDataSent.Mark(mark_fun);
	}

protected:
	void onConnected() ;
	void onConnError(const char* errStr) ;
	void onDisconnect() ;
	void onDataSent(int nMsgId) ;
	void onDataRecv(const void* data, int len, bool bBinary) ;

protected:
	void _onConnected();
	void _onConnError(const std::string& errStr);
	void _onDisconnect();
	void _onDataSent(int nMsgId);
	void _onDataRecv(const std::string& buf, bool bBinary);
private:
	struct UrlInfo {
		bool bSecure;
		std::string addr;
		std::string path;
		int  port;
	};
	void parseUrl(std::string url, UrlInfo &info);
private:
	WsConnListener  m_connListener;
	SAutoRefPtr<IWsClient> m_wsClient;
	SAutoRefPtr<IMessageLoop> m_msgLoop;

public:
	Value m_cbHandler;

	Value m_onConnected;
	Value m_onClose;
	Value m_onError;
	Value m_onText;
	Value m_onBinary;
	Value m_onDataSent;
};

WsClient* WsClientCtor(ArgList& args);
Value WsClient_SendBinary(Context* ctx, WsClient* _this, ArgList& args);
Value WsClient_SendText(Context* ctx, WsClient* _this, ArgList& args);
