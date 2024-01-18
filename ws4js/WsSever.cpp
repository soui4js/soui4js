#include "stdafx.h"
#include "WsClient.h"
#include "WsLoader.h"
#include <helper/SFunctor.hpp>
#include "WsSever.h"
#define kLogTag "WsServer"
SvrListener::SvrListener(WsServer* pOwner) :m_pOwner(pOwner)
{
}

bool SvrListener::onConnected(ISvrConnection* pConn, const char* uriPath, const char* uriArgs)
{
	return m_pOwner->onConnected(pConn,uriPath,uriArgs);
}

void SvrListener::onConnError(ISvrConnection* pConn, const char* errStr)
{
	m_pOwner->onConnError(pConn, errStr);
}

void SvrListener::onDisconnect(ISvrConnection* pConn)
{
	m_pOwner->onDisconnect(pConn);
}

void SvrListener::onDataSent(ISvrConnection* pConn, int nMsgId)
{
	m_pOwner->onDataSent(pConn, nMsgId);
}

void SvrListener::onDataRecv(ISvrConnection* pConn, const void* data, int len, bool bBinary)
{
	m_pOwner->onDataRecv(pConn, data,len,bBinary);
}

///////////////////////////////////////////////////////////
WsServer::WsServer() :m_svrListener(this)
{
	m_wsLoader = new WsLoader();
	m_wsServer.Attach(m_wsLoader->CreateWsServer(&m_svrListener));
}

WsServer::~WsServer()
{
	m_wsServer = nullptr;
	delete m_wsLoader;
}

int WsServer::start(LPCSTR protocol, int port, bool bSecure, LPCSTR cert, LPCSTR priv_key)
{
	SvrOption option = { bSecure,cert,priv_key };
	return m_wsServer->start(port, protocol, option);
}

void WsServer::quit()
{
	m_wsServer->quit();
}

void WsServer::onConnError(ISvrConnection* pConn, const char* errStr)
{
	if (!m_onConnError.IsFunction())
		return;
	Context* ctx = m_onConnError.context();
	Value args[] = {
		NewValue(*ctx,pConn),
		NewValue(*ctx,errStr)
	};
	ctx->EnqueueJob(GetJsThis(), m_onConnError, ARRAYSIZE(args), args);
}

bool WsServer::onConnected(ISvrConnection* pConn, const char* uriPath, const char* uriArgs)
{
	if (!m_onConnected.IsFunction())
		return false;
	Context* ctx = m_onConnected.context();
	Value args[] = {
		NewValue(*ctx,pConn),
		NewValue(*ctx,uriPath),
		NewValue(*ctx,uriArgs)
	};
	return ctx->SyncCall(GetJsThis(), m_onConnected, ARRAYSIZE(args), args,-1);
}

void WsServer::onDisconnect(ISvrConnection* pConn)
{
	if (!m_onDisconnect.IsFunction())
		return;
	Context* ctx = m_onDisconnect.context();
	Value args[] = {
		NewValue(*ctx,pConn)
	};
	ctx->EnqueueJob(GetJsThis(), m_onDisconnect, ARRAYSIZE(args), args);
}

void WsServer::onDataSent(ISvrConnection* pConn, int nMsgId)
{
	if (!m_onDataSent.IsFunction())
		return;
	Context* ctx = m_onDataSent.context();
	Value args[] = {
		NewValue(*ctx,pConn),
		NewValue(*ctx,nMsgId)
	};
	ctx->EnqueueJob(GetJsThis(), m_onDataSent, ARRAYSIZE(args), args);
}

void WsServer::onDataRecv(ISvrConnection* pConn, const void* data, int len, bool bBinary)
{
	if (bBinary) {
		if (!m_onBinary.IsFunction())
			return;
		Context* ctx = m_onBinary.context();
		Value args[] = {
			ctx->NewValue(pConn),
			ctx->NewArrayBuffer((const uint8_t*)data,len)
		};
		ctx->EnqueueJob(GetJsThis(), m_onBinary, ARRAYSIZE(args), args);
	}
	else {
		if (!m_onText.IsFunction())
			return;
		Context* ctx = m_onText.context();
		Value args[] = {
			NewValue(*ctx,pConn),
			NewValue(*ctx,std::string((const char*)data,len))
		};
		ctx->EnqueueJob(GetJsThis(), m_onText, ARRAYSIZE(args), args);
	}
}


