#pragma once
#include "WsClient.h"

int IConn_SendBinary(Context* ctx, IConnection* pConn, ArgList& args) {
	if (args.size() == 0 || !args[0].IsArrayBuffer())
		return 0;
	size_t size=0;
	const uint8_t * buf= args[0].GetArrayBuffer(&size);
	return pConn->sendBinary(buf, size);
}

void Exp_Ws(qjsbind::Module* module) {
	{
		JsClass<WsClient> jsCls = module->ExportClass<WsClient>("WebSocket");
		jsCls.Init<WsClient::Mark>();
		jsCls.AddCtor<WsClientCtor>(TRUE);
		jsCls.AddCFunc("sendText", &WsClient_SendText);
		jsCls.AddCFunc("sendBinary", &WsClient_SendBinary);
		jsCls.AddGetSet("cbHandler", &WsClient::m_cbHandler);
		jsCls.AddGetSet("onConnected", &WsClient::m_onConnected);
		jsCls.AddGetSet("onClose", &WsClient::m_onClose);
		jsCls.AddGetSet("onError", &WsClient::m_onError);
		jsCls.AddGetSet("onText", &WsClient::m_onText);
		jsCls.AddGetSet("onBinary", &WsClient::m_onBinary);
		jsCls.AddGetSet("onDataSent", &WsClient::m_onDataSent);
	}
}