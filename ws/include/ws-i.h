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

struct IConnection : IObjRef
{
    virtual int isValid() const = 0;
    virtual int sendText(const char *text, int nLen = -1) = 0;
    virtual int sendBinary(const void *data, int nLen) = 0;
};

struct ISvrConnection : IConnection
{
    virtual void close(const char* reason) = 0;
    virtual void setId(int id) = 0;
    virtual int getId() const = 0;
    virtual void setGroupId(int id) = 0;
    virtual int getGroupId() const = 0;
};

struct IConnListener : IObjRef
{
    virtual void onConnected() = 0;
    virtual void onConnError(const char *errStr) = 0;
    virtual void onDisconnect() = 0;
    virtual void onDataSent(int nMsgId) = 0;
    virtual void onDataRecv(const void *data, int len, bool bBinary) = 0;
};

struct ISvrListener : IObjRef
{
    virtual bool onConnected(ISvrConnection* pConn, const char* uriPath, const char* uriArgs ) = 0;
    virtual void onConnError(ISvrConnection* pConn, const char* errStr) = 0;
    virtual void onDisconnect(ISvrConnection* pConn) = 0;
    virtual void onDataSent(ISvrConnection* pConn, int nMsgId) = 0;
    virtual void onDataRecv(ISvrConnection* pConn, const void* data, int len, bool bBinary) = 0;
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

typedef void(*WS_LogCallback)(int level, const char *log);

struct IWebsocket : IObjRef
{
    virtual IWsClient *CreateWsClient(IConnListener *pListener) = 0;
    virtual IWsServer *CreateWsServer(ISvrListener *pListener) = 0;
    virtual void SetWsLogCallback(WS_LogCallback cbLog) = 0;
};

namespace WS
{
SOUI_COM_C BOOL SOUI_COM_API SCreateInstance(IObjRef **ppRet);
}
SNSEND

SOUI_COM_C BOOL SOUI_COM_API Ws_CreateInstance(IObjRef **ppRet);

#endif // WS_LISTENER_H
