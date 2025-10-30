#include "stdafx.h"
#include "WsLoader.h"


WsLoader::WsLoader()
{
	
}

WsLoader::~WsLoader()
{
}

static void ws_log(int level,const char * log){
	SLOG("wslog", level)<<log;
}

IWsClient* WsLoader::CreateWsClient(IConnListener* pListener)
{
	SAutoRefPtr<IWebsocket> pWs;
	m_comLoader.CreateInstance(_T("ws"), (IObjRef**)&pWs);
	if (!pWs)
		return NULL;
	pWs->SetLogCallback(ws_log);
	return pWs->CreateWsClient(pListener);
}

IWsServer* WsLoader::CreateWsServer(ISvrListener* pListener)
{
	SAutoRefPtr<IWebsocket> pWs;
	m_comLoader.CreateInstance(_T("ws"), (IObjRef**)&pWs);
	if (!pWs)
		return NULL;
	pWs->SetLogCallback(ws_log);
	return pWs->CreateWsServer(pListener);
}
