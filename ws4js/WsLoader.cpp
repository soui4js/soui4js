#include "stdafx.h"
#include "WsLoader.h"

WsLoader::WsLoader():m_funWsCreateInst(nullptr), m_wsModule(nullptr)
{
	m_wsModule = LoadLibraryA("ws.dll");
	if(m_wsModule!=nullptr)
		m_funWsCreateInst = (fun_Ws_CreateInstance)GetProcAddress(m_wsModule, "Ws_CreateInstance");
}

WsLoader::~WsLoader()
{
	FreeLibrary(m_wsModule);
}


IWsClient* WsLoader::CreateWsClient(IConnListener* pListener)
{
	SAutoRefPtr<IWebsocket> pWs;
	m_funWsCreateInst((IObjRef**)&pWs);
	return pWs->CreateWsClient(pListener);
}

IWsServer* WsLoader::CreateWsServer(ISvrListener* pListener)
{
	SAutoRefPtr<IWebsocket> pWs;
	m_funWsCreateInst((IObjRef**)&pWs);
	return pWs->CreateWsServer(pListener);
}
