#pragma once
#include "WsClient.h"
#include "WsSever.h"


Value IConn_SendBinary(Context* ctx, IConnection* pConn, ArgList& args) {
	if (args.size() == 0 || !args[0].IsArrayBuffer())
		return exception_value;
	size_t size=0;
	const uint8_t * buf= args[0].GetArrayBuffer(&size);
	int ret = pConn->sendBinary(buf, size);
	return NewValue(*ctx, ret);
}

Value IConn_SendText(Context* ctx, IConnection* pConn, ArgList& args) {
	if (args.size() == 0)
		return exception_value;
	const char* buf = args[0];
	int nLen = -1;
	if (args.size() > 1)
		nLen = args[1];
	int ret = pConn->sendText(buf, nLen);
	return NewValue(*ctx, ret);
}

int WsServer_Start(Context* ctx, WsServer* pServer, ArgList& args) {
	if (args.size() < 2)
		return -1;
	const char* protocol = args[0];
	int port = args[1];
	bool bSecure = false;
	std::string cert, priv_key;
	if (args.size() >= 5) {
		bSecure = args[2];
		cert = (const char*)args[3];
		priv_key = (const char*)args[4];
	}
	return pServer->start(protocol, port, bSecure, cert.c_str(), priv_key.c_str());
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
	{
		JsClass<IObjRef> jsCls = module->ExportClass<IObjRef>("IObjRef");
		jsCls.Init();
		jsCls.AddFunc("AddRef", &IObjRef::AddRef);
		jsCls.AddFunc("Release", &IObjRef::Release);
	}
	{
		JsClass<IConnection> jsCls = module->ExportClass<IConnection>("IConnection");
		jsCls.Init(JsClass<IObjRef>::class_id());
		jsCls.AddFunc("isValid", &IConnection::isValid);
		jsCls.AddCFunc("sendText", &IConn_SendText);
		jsCls.AddCFunc("sendBinary", &IConn_SendBinary);
	}
	{
		JsClass<ISvrConnection> jsCls = module->ExportClass<ISvrConnection>("ISvrConnection");
		jsCls.Init(JsClass<IConnection>::class_id());
		jsCls.AddFunc("getId", &ISvrConnection::getId);
		jsCls.AddFunc("getGroupId", &ISvrConnection::getGroupId);
		jsCls.AddFunc("setId", &ISvrConnection::setId);
		jsCls.AddFunc("setGroupId", &ISvrConnection::setGroupId);
		jsCls.AddFunc("close", &ISvrConnection::close);
	}
	{
		JsClass<WsServer> jsCls = module->ExportClass<WsServer>("WsServer");
		jsCls.Init<WsServer::Mark>();
		jsCls.AddCtor<qjsbind::constructor>(TRUE);
		jsCls.AddCFunc("start",&WsServer_Start);
		jsCls.AddFunc("quit", &WsServer::quit);
		jsCls.AddGetSet("cbHandler", &WsServer::m_cbHandler);
		jsCls.AddGetSet("onConnError", &WsServer::m_onConnError);
		jsCls.AddGetSet("onConnected", &WsServer::m_onConnected);
		jsCls.AddGetSet("onDisconnect", &WsServer::m_onDisconnect);
		jsCls.AddGetSet("onText", &WsServer::m_onText);
		jsCls.AddGetSet("onBinary", &WsServer::m_onBinary);
	}
}