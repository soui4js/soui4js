#pragma once
#include "WsClient.h"
#include "WsSever.h"


int IConn_SendBinary(Context* ctx, IConnection* pConn, ArgList& args) {
	if (args.size() == 0 || !args[0].IsArrayBuffer())
		return 0;
	size_t size=0;
	const uint8_t * buf= args[0].GetArrayBuffer(&size);
	return pConn->sendBinary(buf, size);
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
		jsCls.AddFunc("sendText", &IConnection::sendText);
		jsCls.AddCFunc("sendBinary", &IConn_SendBinary);
	}
	{
		JsClass<ISvrConnection> jsCls = module->ExportClass<ISvrConnection>("ISvrConnection");
		jsCls.Init(JsClass<IConnection>::class_id());
		jsCls.AddFunc("getId", &ISvrConnection::getId);
		jsCls.AddFunc("getGroupId", &ISvrConnection::getGroupId);
	}
	{
		JsClass<IConnGroup> jsCls = module->ExportClass<IConnGroup>("IConnGroup");
		jsCls.Init(JsClass<IObjRef>::class_id());
		jsCls.AddFunc("boardcast", &IConnGroup::boardcast);
		jsCls.AddFunc("isEmpty", &IConnGroup::isEmpty);
		jsCls.AddFunc("getId", &IConnGroup::getId);
	}
	{
		JsClass<ConnGroup> jsCls = module->ExportClass<ConnGroup>("ConnGroup");
		jsCls.Init(JsClass<IConnGroup>::class_id());
		jsCls.AddCtor<qjsbind::constructor<ConnGroup,int>>(TRUE);
		jsCls.AddGetSet("cbHandler", &ConnGroup::m_cbHandler);
		jsCls.AddGetSet("onConnError", &ConnGroup::m_onConnError);
		jsCls.AddGetSet("onConnected", &ConnGroup::m_onConnected);
		jsCls.AddGetSet("onDisconnect", &ConnGroup::m_onDisconnect);
		jsCls.AddGetSet("onText", &ConnGroup::m_onText);
		jsCls.AddGetSet("onBinary", &ConnGroup::m_onBinary);
		jsCls.AddGetSet("IsEmpty", &ConnGroup::m_onIsEmpty);
	}
	{
		JsClass<WsServer> jsCls = module->ExportClass<WsServer>("WsServer");
		jsCls.Init<WsServer::Mark>();
		jsCls.AddCtor<qjsbind::constructor>(TRUE);
		jsCls.AddCFunc("start",&WsServer_Start);
		jsCls.AddGetSet("cbHandler", &WsServer::m_cbHandler);
		jsCls.AddGetSet("onParseConnId", &WsServer::m_onParseConnId);
		jsCls.AddGetSet("onNewGroup", &WsServer::m_onNewGroup);
		jsCls.AddGetSet("onDelGroup", &WsServer::m_onDelGroup);
	}
}