#pragma once
#include <qjsbind.h>
#include <ws-i.h>
#include <helper/obj-ref-impl.hpp>

using namespace qjsbind;

class WsServer;

class ConnGroup : public TObjRefImpl<IConnGroup>, public JsThisOwner{
    int m_id;
    int m_autoId;
public:
    ConnGroup(int id)
        : m_id(id)
        , m_autoId(100000)
    {
    }

    ~ConnGroup() {

    }
public:
    int getId() const override
    {
        return m_id;
    }
    void onConnError(ISvrConnection* pConn, const char* errStr) override
    {
        if (!m_onConnError.IsFunction())
            return;
        Context* ctx = m_onConnError.context();
        Value args[] = {
            NewValue(*ctx,pConn),
            NewValue(*ctx,errStr)
        };
        ctx->EnqueueJob(GetJsThis(), m_onConnError, ARRAYSIZE(args), args);
    }

    bool onConnected(ISvrConnection* pConn) override
    {
        if (!m_onConnected.IsFunction())
            return false;
        Context* ctx = m_onConnected.context();
        Value args[] = {
            NewValue(*ctx,pConn)
        };
        return ctx->AsynCall(GetJsThis(), m_onConnected, ARRAYSIZE(args), args);
    }

    void onDisconnect(ISvrConnection* pConn) override
    {
        if (!m_onDisconnect.IsFunction())
            return;
        Context* ctx = m_onDisconnect.context();
        Value args[] = {
            NewValue(*ctx,pConn)
        };
        ctx->EnqueueJob(GetJsThis(), m_onDisconnect, ARRAYSIZE(args), args);
    }

    void onDataSent(ISvrConnection* pConn, int nMsgId) override
    {
        if (!m_onDataSent.IsFunction())
            return;
        Context* ctx = m_onDataSent.context();
        Value args[] = {
            NewValue(*ctx,pConn),
            NewValue(*ctx,nMsgId)
        };
        ctx->EnqueueJob(GetJsThis(), m_onDataSent, ARRAYSIZE(args), args);
    }

    void onDataRecv(ISvrConnection* pConn, const void* data, int len, bool bBinary) override
    {
        if (bBinary) {
            if (!m_onBinary.IsFunction())
                return;
            Context* ctx = m_onBinary.context();
            Value args[] = {
                ctx->NewValue(pConn->getId()),
                ctx->NewArrayBuffer((const uint8_t*)data,len)
            };
            ctx->EnqueueJob(GetJsThis(), m_onBinary, ARRAYSIZE(args), args);
        }
        else {
            if (!m_onText.IsFunction())
                return;
            Context* ctx = m_onText.context();
            Value args[] = {
                NewValue(*ctx,pConn->getId()),
                NewValue(*ctx,std::string((const char*)data,len))
            };
            ctx->EnqueueJob(GetJsThis(), m_onText, ARRAYSIZE(args), args);
        }
    }

    void boardcast(const void* data, int nLen, bool bBinary) override
    {
    }

    bool isEmpty() const override
    {
        if (!m_onIsEmpty.IsFunction())
            return true;
        Context* ctx = m_onIsEmpty.context();
        Value ret = ctx->AsynCall(GetJsThis(), m_onIsEmpty, 0, nullptr);
        return ret.IsBool() ? ret.ToBool() : true;
    }

    int generateConnId() override
    {
        return ++m_autoId;
    }

    protected:
        virtual const WeakValue& GetJsThis() const override {
            if (m_cbHandler.IsObject())
                return m_cbHandler;
            else
                return JsThisOwner::GetJsThis();
        }

public:
    static void Mark(ConnGroup* pThis, JS_MarkFunc* mark_fun) {
        pThis->m_cbHandler.Mark(mark_fun);
        pThis->m_onConnError.Mark(mark_fun);
        pThis->m_onConnected.Mark(mark_fun);
        pThis->m_onDisconnect.Mark(mark_fun);
        pThis->m_onDataSent.Mark(mark_fun);
        pThis->m_onText.Mark(mark_fun);
        pThis->m_onBinary.Mark(mark_fun);
        pThis->m_onIsEmpty.Mark(mark_fun);
    }
    Value m_cbHandler;

    Value m_onConnError;
    Value m_onConnected;
    Value m_onDisconnect;
    Value m_onDataSent;
    Value m_onText;
    Value m_onBinary;
    Value m_onIsEmpty;
};

class SvrListener : public TObjRefImpl<ISvrListener> {
    WsServer* m_pOwner;
public:
    SvrListener(WsServer* pOwner);
public:
	// Í¨¹ý ISvrListener ¼Ì³Ð
    IConnGroup* onNewGroup(int id, IWsServer* pSvr) override;
    void onDelGroup(IConnGroup* pGroup) override;
    bool parseConnId(const char* uriPath, const char* uriArgs, int* groupId, int* connId) override;
};

class WsServer : public JsThisOwner
{
    WsLoader* m_wsLoader;
    friend class SvrListener;
public:
	WsServer();

	~WsServer();

    int start(LPCSTR protocol, int port, bool bSecure = false, LPCSTR cert = NULL, LPCSTR priv_key = NULL);

    IWsServer* getIWsServer() { return m_wsServer; }
private:
    bool parseConnId(const char* uriPath, const char* uriArgs, int* groupId, int* connId);
    IConnGroup* onNewGroup(int id);
    void onDelGroup(IConnGroup* pGroup);

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

        pThis->m_onParseConnId.Mark(mark_fun);
        pThis->m_onNewGroup.Mark(mark_fun);
        pThis->m_onDelGroup.Mark(mark_fun);
    }
private:
    SvrListener  m_svrListener;
	SAutoRefPtr<IWsServer> m_wsServer;
public:
	Value m_cbHandler;
    Value m_onParseConnId;
    Value m_onNewGroup;
    Value m_onDelGroup;
};
