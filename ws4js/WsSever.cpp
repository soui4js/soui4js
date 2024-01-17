#include "stdafx.h"
#include "WsClient.h"
#include "WsLoader.h"
#include <helper/SFunctor.hpp>
#include "WsSever.h"
#define kLogTag "WsServer"
SvrListener::SvrListener(WsServer* pOwner) :m_pOwner(pOwner)
{
}

IConnGroup* SvrListener::onNewGroup(int id, IWsServer* pSvr)
{
	return m_pOwner->onNewGroup(id);
}

void SvrListener::onDelGroup(IConnGroup* pGroup)
{
	m_pOwner->onDelGroup(pGroup);
}

bool SvrListener::parseConnId(const char* uriPath, const char* uriArgs, int* groupId, int* connId)
{
	return m_pOwner->parseConnId(uriPath, uriArgs, groupId, connId);
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

bool WsServer::parseConnId(const char* uriPath, const char* uriArgs, int* groupId, int* connId)
{
	if (m_onParseConnId.IsFunction()) {
		Context* ctx = m_onParseConnId.context();
		qjsbind::Value args[] = {
			NewValue(*ctx, uriPath),
			NewValue(*ctx, uriArgs)
		};
		Value ids = ctx->AsynCall(GetJsThis(), m_onParseConnId, ARRAYSIZE(args), args);
		if (ids.IsObject() && ids.length() >= 2) {
			Value gid = ids.GetProperty(0u);
			Value cId = ids.GetProperty(1u);
			*connId = cId;
			*groupId = gid;
			return true;
		}
	}
	return false;
}

IConnGroup* WsServer::onNewGroup(int id)
{
	if (!m_onNewGroup.IsFunction()) {
		return nullptr;
	}
	Context* ctx = m_onNewGroup.context();
	Value args[] = {
		NewValue(*ctx,id)
	};
	Value ret = ctx->AsynCall(GetJsThis(), m_onNewGroup, ARRAYSIZE(args), args);
	return ret;
}

void WsServer::onDelGroup(IConnGroup* pGroup)
{
	if (!m_onDelGroup.IsFunction()) {
		SLOGW() << "onDelGroup not set";
		return;
	}
	Context* ctx = m_onNewGroup.context();
	Value arg = NewValue(*ctx,pGroup);
	ctx->AsynCall(GetJsThis(), m_onDelGroup, 1, &arg);
}


