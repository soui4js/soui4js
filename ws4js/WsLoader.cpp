#include "stdafx.h"
#include "WsLoader.h"

#ifdef WIN32
#define WS_DLL_NAME "ws.dll"
#elif defined(__APPLE__)
#define WS_DLL_NAME "libws.dylib"
#else
#define WS_DLL_NAME "libws.so"
#endif

WsLoader::WsLoader():m_funWsCreateInst(nullptr), m_wsModule(nullptr)
{
	m_wsModule = LoadLibraryA(WS_DLL_NAME);
	if(m_wsModule!=nullptr)
		m_funWsCreateInst = (fun_Ws_CreateInstance)GetProcAddress(m_wsModule, "Ws_CreateInstance");
	else{
		#ifndef _WIN32
		const char* err = dlerror();
		perror(err);
		#endif//_WIN32
	}
}

WsLoader::~WsLoader()
{
	FreeLibrary(m_wsModule);
}

#define LLL_ERR			(1 << 0)
#define	LLL_WARN		(1 << 1)
#define	LLL_NOTICE		(1 << 2)
#define	LLL_INFO		(1 << 3)
#define	LLL_DEBUG		(1 << 4)

static void ws_log(int level,const char * log){
	int slevel = 0;
	switch(level){
		case LLL_ERR:
		slevel = LOG_LEVEL_ERROR;
		break;
		case LLL_WARN:
		slevel = LOG_LEVEL_WARN;
		break;
		case LLL_DEBUG:
		slevel = LOG_LEVEL_DEBUG;
		case LLL_NOTICE:
		case LLL_INFO:
		default:
		slevel = LOG_LEVEL_INFO;
		break;
	}
	SLOG("wslog",slevel)<<log;
}

IWsClient* WsLoader::CreateWsClient(IConnListener* pListener)
{
	SAutoRefPtr<IWebsocket> pWs;
	m_funWsCreateInst((IObjRef**)&pWs);
	pWs->SetWsLogCallback(ws_log);
	return pWs->CreateWsClient(pListener);
}

IWsServer* WsLoader::CreateWsServer(ISvrListener* pListener)
{
	SAutoRefPtr<IWebsocket> pWs;
	m_funWsCreateInst((IObjRef**)&pWs);
	pWs->SetWsLogCallback(ws_log);
	return pWs->CreateWsServer(pListener);
}
