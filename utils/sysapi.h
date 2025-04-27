#pragma once
#include <string>
namespace sysapi
{
	BOOL JsPlaySound(LPCSTR filename,BOOL purge);
	std::string JsGetModuleFileName(HMODULE hModule);
};

