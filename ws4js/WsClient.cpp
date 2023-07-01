#include "stdafx.h"
#include "WsClient.h"
#include "WsLoader.h"
#include <helper/SFunctor.hpp>

WsConnListener::WsConnListener(WsClient* pOwner):m_pOwner(pOwner)
{
}

void WsConnListener::onConnected()
{
	m_pOwner->onConnected();
}

void WsConnListener::onConnError(const char* errStr)
{
	m_pOwner->onConnError(errStr);
}

void WsConnListener::onDisconnect()
{
	m_pOwner->onDisconnect();
}

void WsConnListener::onDataSent(int nMsgId)
{
	m_pOwner->onDataSent(nMsgId);
}

void WsConnListener::onDataRecv(const void* data, int len, bool bBinary)
{
	m_pOwner->onDataRecv(data, len, bBinary);
}


///////////////////////////////////////////////////////////
WsClient::WsClient(LPCSTR url, LPCSTR protocol,int opt,LPCSTR ca):m_connListener(this)
{
	m_wsLoader = new WsLoader();
	m_msgLoop = SApplication::getSingletonPtr()->GetMsgLoop();
	SASSERT(m_msgLoop);
	m_wsClient.Attach(m_wsLoader->CreateWsClient(&m_connListener));
	UrlInfo urlInfo;
	parseUrl(url, urlInfo);
	ClientOption option;
	option.bSecure = urlInfo.bSecure;
	if (option.bSecure) {
		option.allowExpired = !!(opt & allowExpired);
		option.allowSelfSigned = !!(opt & allowSelfSigned);
		option.skipServerCertHostnameCheck = !!(opt & skipServerCertHostnameCheck);
		option.ca_u8 = ca;
	}
	m_wsClient->connectTo(urlInfo.addr.c_str(), urlInfo.addr.c_str(), urlInfo.port, protocol, option);
}

WsClient::~WsClient()
{
	delete m_wsLoader;
}

int WsClient::sendText(LPCSTR pszText,int nLen)
{
	return m_wsClient->sendText(pszText, nLen);
}

int WsClient::sendBinary(const void* buf, int len)
{
	return m_wsClient->sendBinary(buf, len);
}

void WsClient::_onConnected()
{
	if (!m_onConnected.IsFunction()) {
		return ;
	}
	Context* ctx = m_onConnected.context();
	ctx->Call(GetJsThis(), m_onConnected, 0, nullptr);
}

void WsClient::_onConnError(const std::string & errStr)
{
	if (!m_onError.IsFunction()) {
		return;
	}
	Context* ctx = m_onError.context();
	qjsbind::Value args[] = {
		NewValue(*ctx, errStr)
	};
	ctx->Call(GetJsThis(), m_onError, ARRAYSIZE(args), args);
}

void WsClient::_onDisconnect()
{
	if (!m_onClose.IsFunction()) {
		return;
	}
	Context* ctx = m_onClose.context();
	ctx->Call(GetJsThis(), m_onClose, 0, nullptr);
}

void WsClient::_onDataSent(int nMsgId)
{
	if (!m_onDataSent.IsFunction()) {
		return;
	}
	Context* ctx = m_onDataSent.context();
	qjsbind::Value args[] = {
		NewValue(*ctx, nMsgId)
	};
	ctx->Call(GetJsThis(), m_onDataSent, ARRAYSIZE(args), args);
}

void WsClient::_onDataRecv(const std::string &buf, bool bBinary)
{
	Value cb = bBinary ? m_onBinary : m_onText;
	if (!cb.IsFunction()) {
		return;
	}
	Context* ctx = cb.context();
	if (bBinary) {
		qjsbind::Value args[] = {
				ctx->NewArrayBuffer((const uint8_t*)buf.data(), buf.length() * sizeof(wchar_t))
		};
		ctx->Call(GetJsThis(), cb, ARRAYSIZE(args), args);
	}
	else
	{
		qjsbind::Value args[] = {
			NewValue(*ctx, buf)
		};
		ctx->Call(GetJsThis(), cb, ARRAYSIZE(args), args);
	}
}

void WsClient::onConnected()
{
	STaskHelper::post(m_msgLoop, this, &WsClient::_onConnected);
}

void WsClient::onConnError(const char* errStr)
{
	STaskHelper::post(m_msgLoop, this, &WsClient::_onConnError, std::string(errStr));
}

void WsClient::onDisconnect()
{
	STaskHelper::post(m_msgLoop, this, &WsClient::_onDisconnect);
}

void WsClient::onDataSent(int nMsgId)
{
	STaskHelper::post(m_msgLoop, this, &WsClient::_onDataSent, nMsgId);
}

void WsClient::onDataRecv(const void* data, int len, bool bBinary)
{
	STaskHelper::post(m_msgLoop, this, &WsClient::_onDataRecv, std::string((const char*)data, len), bBinary);
}

void WsClient::parseUrl(std::string url, UrlInfo& info)
{
	if (url.substr(0, 6) == "wss://") {
		info.bSecure = true;
		url = url.substr(6);
	}
	else if (url.substr(0, 5) == "ws://"){
		info.bSecure = false;
		url = url.substr(5);
	}
	int pos = url.find('/');
	std::string addr;
	if (pos == -1) {
		addr = url;
		info.path = "/";
	}
	else
	{
		addr = url.substr(0, pos);
		info.path = url.substr(pos + 1);
	}
	pos = addr.find(':');
	if (pos != -1) {
		info.addr = addr.substr(0, pos);
		std::string strPort = addr.substr(pos + 1);
		info.port = atoi(strPort.c_str());
	}
	else {
		info.addr = addr;
		info.port = info.bSecure ? 443 : 80;
	}
}

WsClient* WsClientCtor(ArgList& args) {
	if(args.size()==0)
		return nullptr;
	if (!SApplication::getSingletonPtr()->GetMsgLoop())
		return nullptr;//only run on ui thread

	const char* url = args[0];
	std::string protocol;
	std::string ca;
	if (args.size() > 1)
		protocol = (const char*)args[1];
	if (args.size() > 2)
		ca = (const char*)args[2];
	bool bAllowSelfSigned = false,
		bSkipServerCertHostnameCheck = false,
		bAllowExpired=false;
	if (args.size() > 5) {
		bAllowSelfSigned = args[3];
		bSkipServerCertHostnameCheck = args[4];
		bAllowExpired = args[5];
	}
	int opt=0;
	if (bAllowSelfSigned) opt |= allowSelfSigned;
	if (bSkipServerCertHostnameCheck) opt |= skipServerCertHostnameCheck;
	if (bAllowExpired) opt |= allowExpired;
	return new WsClient(url, protocol.c_str(), opt, ca.c_str());
}

Value WsClient_SendBinary(Context * ctx,WsClient* _this, ArgList& args)
{
	if (args.size() == 0)
		return exception_value;
	size_t szInput = 0;
	uint8_t* pInput = args[0].ToBuffer(&szInput);
	if (!pInput)
		return exception_value;
	int ret = _this->sendBinary(pInput, szInput);
	return NewValue(*ctx, ret);
}

Value WsClient_SendText(Context* ctx, WsClient* _this, ArgList& args)
{
	if (args.size() == 0 || !args[0].IsString())
		return exception_value;
	const char* str = args[0];
	int nLen = -1;
	if (args.size() > 1)
		nLen = args[1];
	int ret = _this->sendText(str, nLen);
	return NewValue(*ctx, ret);
}
