#include "stdafx.h"
#include "sysapi.h"

#ifdef WIN32
#include <Mmsystem.h>
#pragma comment(lib,"Winmm.lib")

using namespace SOUI;

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

    // 用于记录上一次启动的子进程 ID
    static pid_t g_lastSoundPid = 0;

    BOOL JsPlaySound(LPCSTR filename, BOOL purge) {
        // 如果指定 purge 或者 filename 为空，则先停止之前播放的声音
        if (purge || filename == NULL || filename[0] == '\0') {
            if (g_lastSoundPid != 0) {
                kill(g_lastSoundPid, SIGTERM);
                waitpid(g_lastSoundPid, NULL, WNOHANG);
                g_lastSoundPid = 0;
            }
            // 如果 filename 为空，则返回 TRUE 表示命令执行成功
            if (filename == NULL || filename[0] == '\0')
                return TRUE;
        }

        // 在 Linux 下使用 aplay 播放声音文件（要求声音文件为 WAV 格式）
        pid_t pid = fork();
        if (pid < 0) {  // fork 失败
            return FALSE;
        }
        if (pid == 0) { // 子进程中
            // execlp 替换当前进程映像来播放声音
            execlp("aplay", "aplay", filename, (char*)NULL);
            // 如果 execlp 执行失败，则退出子进程
            _exit(127);
        }
        // 父进程中保存子进程 ID 以便后续调用 purge 终止播放
        g_lastSoundPid = pid;
        return TRUE;
    }
}
#endif // WIN32
