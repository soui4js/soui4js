#ifndef WS_LISTENER_H
#define WS_LISTENER_H

#define _WINSOCKAPI_
#include <interface/obj-ref-i.h>
#include <stdint.h>

SNSBEGIN

enum
{
    kAllGroupId = -1,
    kDefGroupId = 0,
    kSocketBufSize = 4096,
};

struct IConnGroup;
struct IConnection : IObjRef
{
    virtual int isValid() const = 0;
    virtual int sendText(const char *text, int nLen = -1) = 0;
    virtual int sendBinary(const void *data, int nLen) = 0;
};

struct IConnListener : IObjRef
{
    virtual void onConnected() = 0;
    virtual void onConnError(const char *errStr) = 0;
    virtual void onDisconnect() = 0;
    virtual void onDataSent(int nMsgId) = 0;
    virtual void onDataRecv(const void *data, int len, bool bBinary) = 0;
};

struct ISvrConnection : IConnection
{
    virtual int getId() const = 0;
    virtual int getGroupId() const = 0;
};

struct IConnGroup : IObjRef
{
    virtual bool onConnected(ISvrConnection*pConn) = 0;
    virtual void onConnError(ISvrConnection*pConn, const char *errStr) = 0;
    virtual void onDisconnect(ISvrConnection*pConn) = 0;
    virtual void onDataSent(ISvrConnection*pConn, int nMsgId) = 0;
    virtual void onDataRecv(ISvrConnection*pConn, const void *data, int len, bool bBinary) = 0;
    virtual void boardcast(const void *data, int nLen, bool bBinary) = 0;
    virtual bool isEmpty() const = 0;
    virtual int getId() const = 0;
    virtual int generateConnId() = 0;
};

struct IWsServer;
struct ISvrListener : IObjRef
{
    virtual IConnGroup *onNewGroup(int id, IWsServer*pSvr) = 0;
    virtual void onDelGroup(IConnGroup *pGroup) = 0;
    virtual bool parseConnId(const char *uriPath, const char *uriArgs, int *groupId, int *connId) = 0;
};

struct SvrOption
{
    bool bSecure;
    const char *cert_u8;
    const char *priv_key_u8;
};

struct IWsServer : IObjRef
{
    virtual int start(uint16_t port, const char *protocolName, SvrOption option) = 0;
    virtual void broadcast(const void *text, int len, bool bBinary, int groupId = kAllGroupId) = 0;
    virtual bool wait(int timeout) = 0;
    virtual void quit() = 0;
};

struct ClientOption
{
    bool bSecure;
    const char *ca_u8;
    bool allowSelfSigned;
    bool skipServerCertHostnameCheck;
    bool allowExpired;
};

struct IWsClient : IConnection
{
    virtual int connectTo(const char *pszSvr, const char *pszPath, uint16_t nPort, const char *pszProtocol, ClientOption option) = 0;
    virtual void disconnect() = 0;
    virtual bool wait(int timeoutMs) = 0;
};

struct IWebsocket : IObjRef
{
    virtual IWsClient *CreateWsClient(IConnListener *pListener) = 0;
    virtual IWsServer *CreateWsServer(ISvrListener *pListener) = 0;
};

namespace WS
{
SOUI_COM_C BOOL SOUI_COM_API SCreateInstance(IObjRef **ppRet);
}
SNSEND

SOUI_COM_C BOOL SOUI_COM_API Ws_CreateInstance(IObjRef **ppRet);

#endif // WS_LISTENER_H
