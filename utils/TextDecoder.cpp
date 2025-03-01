#include "stdafx.h"
#include <qjsbind.h>
#include <windows.h>
#include "TextDecoder.h"

using namespace qjsbind;
qjsbind::Value WString2String(qjsbind::Context* ctx, qjsbind::ArgList& args) {
	if (args.size() == 0)
		return exception_value;
	size_t szInput = 0;
	uint8_t* pInput = args[0].ToBuffer(&szInput);
	if(!pInput)
		return exception_value;

	int cp = CP_UTF8;
	if (args.size() >= 2) {
		cp = args[1];
	}
	int len = WideCharToMultiByte(cp, 0, (LPCWSTR)pInput, (int)szInput / sizeof(wchar_t), NULL, 0, NULL, NULL);
	char* pOut = (char*)malloc(len);
	len = WideCharToMultiByte(cp, 0, (LPCWSTR)pInput, (int)szInput / sizeof(wchar_t), pOut, len, NULL, NULL);
	Value ret = ctx->NewArrayBuffer((const uint8_t*)pOut, len);
	{
		size_t szInput = 0;
		uint8_t* pInput = ret.ToBuffer(&szInput);
		szInput = 0;
	}
	free(pOut);
	return ret;
}

qjsbind::Value String2WString(qjsbind::Context* ctx, qjsbind::ArgList& args)
{
	if (args.size() == 0)
		return exception_value;
	size_t szInput = 0;
	uint8_t* pInput = args[0].ToBuffer(&szInput);
	if (!pInput)
		return exception_value;
	int cp = CP_UTF8;
	if (args.size() >= 2) {
		cp = args[1];
	}
	int len = MultiByteToWideChar(cp, 0, (LPCSTR)pInput, (int)szInput , NULL, 0);
	wchar_t* pOut = (wchar_t*)malloc(len*sizeof(wchar_t));
	len = MultiByteToWideChar(cp, 0, (LPCSTR)pInput, (int)szInput, pOut, len);
	Value ret = ctx->NewArrayBuffer((const uint8_t*)pOut, len*sizeof(wchar_t));
	{
		size_t szInput = 0;
		uint8_t* pInput = ret.ToBuffer(&szInput);
		szInput = 0;
	}

	free(pOut);
	return ret;
}

qjsbind::Value Buffer2String(qjsbind::Context* ctx, qjsbind::ArgList& args)
{
	if (args.size() == 0)
		return exception_value;
	size_t szInput = 0;
	uint8_t* pInput = args[0].ToBuffer(&szInput);
	if (!pInput)
		return exception_value;
	return ctx->NewString((const char*)pInput, szInput);
}
