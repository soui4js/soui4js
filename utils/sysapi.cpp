#include "stdafx.h"
#include "sysapi.h"
#include <mmsystem.h>
using namespace SOUI;

#ifdef WIN32
#pragma comment(lib,"Winmm.lib")
#endif

namespace sysapi {
	BOOL JsPlaySound(LPCSTR filename, BOOL purge) {
		SStringT str = S_CA2T(filename, CP_UTF8);
		if (str.IsEmpty()) {
			return ::PlaySound(NULL, NULL, SND_ASYNC | SND_PURGE);
		}
		else
		{
			DWORD flag = SND_FILENAME | SND_ASYNC;
			if (purge) flag |= SND_PURGE;
			return ::PlaySound(str, NULL, flag);
		}
	}
    std::string JsGetModuleFileName(HMODULE hModule){
        WCHAR szPath[MAX_PATH] = { 0 };
        GetModuleFileNameW(hModule, szPath, MAX_PATH);
        return S_CW2A(szPath,CP_UTF8).c_str();
    }
    
    std::string JsGetEnv(LPCSTR envKey){
        DWORD len = GetEnvironmentVariableA(envKey,NULL,0);
        if(len == 0)
            return "";
        char * buf = (char*)malloc(len);
        GetEnvironmentVariableA(envKey,buf,len);
        std::string ret(buf,len);
        free(buf);
        return ret;
    }
}