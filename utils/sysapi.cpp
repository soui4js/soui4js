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

    // ���ڼ�¼��һ���������ӽ��� ID
    static pid_t g_lastSoundPid = 0;

    BOOL JsPlaySound(LPCSTR filename, BOOL purge) {
        // ���ָ�� purge ���� filename Ϊ�գ�����ֹ֮ͣǰ���ŵ�����
        if (purge || filename == NULL || filename[0] == '\0') {
            if (g_lastSoundPid != 0) {
                kill(g_lastSoundPid, SIGTERM);
                waitpid(g_lastSoundPid, NULL, WNOHANG);
                g_lastSoundPid = 0;
            }
            // ��� filename Ϊ�գ��򷵻� TRUE ��ʾ����ִ�гɹ�
            if (filename == NULL || filename[0] == '\0')
                return TRUE;
        }

        // �� Linux ��ʹ�� aplay ���������ļ���Ҫ�������ļ�Ϊ WAV ��ʽ��
        pid_t pid = fork();
        if (pid < 0) {  // fork ʧ��
            return FALSE;
        }
        if (pid == 0) { // �ӽ�����
            // execlp �滻��ǰ����ӳ������������
            execlp("aplay", "aplay", filename, (char*)NULL);
            // ��� execlp ִ��ʧ�ܣ����˳��ӽ���
            _exit(127);
        }
        // �������б����ӽ��� ID �Ա�������� purge ��ֹ����
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