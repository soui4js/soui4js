#pragma once
#include <interface/ws-i.h>
#include <com-loader.hpp>

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
	SComLoader m_comLoader;
};

