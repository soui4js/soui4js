#include "stdafx.h"
#include "sysapi.h"
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