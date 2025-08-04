#include "stdafx.h"
#include "sysapi.h"
using namespace SOUI;

#ifdef WIN32
#include <Mmsystem.h>
#pragma comment(lib,"Winmm.lib")


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
}
#else
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

namespace sysapi {

    static pid_t g_lastSoundPid = 0;

    BOOL JsPlaySound(LPCSTR filename, BOOL purge) {
        if (purge || filename == NULL || filename[0] == '\0') {
            if (g_lastSoundPid != 0) {
                kill(g_lastSoundPid, SIGTERM);
                waitpid(g_lastSoundPid, NULL, WNOHANG);
                g_lastSoundPid = 0;
            }
            if (filename == NULL || filename[0] == '\0')
                return TRUE;
        }

        pid_t pid = fork();
        if (pid < 0) { 
            return FALSE;
        }
        if (pid == 0) { 
            execlp("aplay", "aplay", filename, (char*)NULL);
            _exit(127);
        }
        g_lastSoundPid = pid;
        return TRUE;
    }
}
#endif // WIN32

namespace sysapi {
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