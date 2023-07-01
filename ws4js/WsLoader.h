#pragma once
#include <ws-i.h>

using namespace SOUI;

typedef BOOL (* fun_Ws_CreateInstance)(IObjRef** ppRet);

class WsLoader
{
public:
	WsLoader();
	~WsLoader();

public:
	IWsClient* CreateWsClient(IConnListener *pListener);
	IWsServer* CreateWsServer(ISvrListener* pGroup);
private:
	HMODULE m_wsModule;
	fun_Ws_CreateInstance m_funWsCreateInst;
};

