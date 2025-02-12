#include <ws-i.h>
#include "wsClient.h"
#include "wsServer.h"

SNSBEGIN

class Websocket : public TObjRefImpl<IWebsocket> {
  public:
    IWsClient *CreateWsClient(IConnListener *pListener) override
    {
        return new WsClient(pListener);
    }
    IWsServer *CreateWsServer(ISvrListener *pListener) override
    {
        return new WsServer(pListener);
    }

    void SetWsLogCallback(WS_LogCallback cbLog) override{
        lws_set_log_level(LLL_ERR | LLL_WARN | LLL_NOTICE,cbLog);
    }

};

SOUI_COM_C BOOL SOUI_COM_API SCreateInstance(IObjRef **ppRet)
{
    *ppRet = new Websocket();
    return TRUE;
}

SNSEND

SOUI_COM_C BOOL SOUI_COM_API Ws_CreateInstance(IObjRef **ppRet)
{
    return SOUI::SCreateInstance(ppRet);
}
