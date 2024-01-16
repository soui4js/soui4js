#pragma once
#include <qjsbind.h>
#include <ws-i.h>
#include <helper/obj-ref-impl.hpp>

using namespace qjsbind;

class WsServer;

class SvrListener : public TObjRefImpl<ISvrListener> {
    WsServer* m_pOwner;
public:
    SvrListener(WsServer* pOwner);
public:
    bool onConnected(ISvrConnection* pConn, const char* uriPath, const char* uriArgs) override;
    void onConnError(ISvrConnection* pConn, const char* errStr) override;
    void onDisconnect(ISvrConnection* pConn) override;
    void onDataSent(ISvrConnection* pConn, int nMsgId) override;
    void onDataRecv(ISvrConnection* pConn, const void* data, int len, bool bBinary) override;
};

class WsServer : public JsThisOwner
{
    WsLoader* m_wsLoader;
    friend class SvrListener;
public:
	WsServer();

	~WsServer();

    int start(LPCSTR protocol, int port, bool bSecure = false, LPCSTR cert = NULL, LPCSTR priv_key = NULL);
    void quit();
private:
    void onConnError(ISvrConnection* pConn, const char* errStr);

    bool onConnected(ISvrConnection* pConn, const char* uriPath, const char* uriArgs);

    void onDisconnect(ISvrConnection* pConn);

    void onDataSent(ISvrConnection* pConn, int nMsgId);

    void onDataRecv(ISvrConnection* pConn, const void* data, int len, bool bBinary);
protected:
    virtual const WeakValue& GetJsThis() const override {
        if (m_cbHandler.IsObject())
            return m_cbHandler;
        else
            return JsThisOwner::GetJsThis();
    }

public:
	static void Mark(WsServer* pThis, JS_MarkFunc* mark_fun) {
		pThis->m_cbHandler.Mark(mark_fun);

        pThis->m_onConnError.Mark(mark_fun);
        pThis->m_onConnected.Mark(mark_fun);
        pThis->m_onDisconnect.Mark(mark_fun);
        pThis->m_onDataSent.Mark(mark_fun);
        pThis->m_onText.Mark(mark_fun);
        pThis->m_onBinary.Mark(mark_fun);
    }
private:
    SvrListener  m_svrListener;
	SAutoRefPtr<IWsServer> m_wsServer;
public:
	Value m_cbHandler;

    Value m_onConnError;
    Value m_onConnected;
    Value m_onDisconnect;
    Value m_onDataSent;
    Value m_onText;
    Value m_onBinary;
};
