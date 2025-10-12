#ifndef __MMSYSTEM_H__
#define __MMSYSTEM_H__

#include <ctypes.h>
#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

    DWORD WINAPI timeGetTime(void);

    typedef UINT MMRESULT;

    MMRESULT timeBeginPeriod(UINT uPeriod);

    typedef struct timecaps_tag
    {
        UINT wPeriodMin; /* minimum period supported  */
        UINT wPeriodMax; /* maximum period supported  */
    } TIMECAPS, *PTIMECAPS, NEAR *NPTIMECAPS, FAR *LPTIMECAPS;

#define MMSYSERR_BASE 0
#define WAVERR_BASE   32
#define MIDIERR_BASE  64
#define TIMERR_BASE   96
#define JOYERR_BASE   160
#define MCIERR_BASE   256

#define TIMERR_NOERROR (0)                /* no error */
#define TIMERR_NOCANDO (TIMERR_BASE + 1)  /* request not completed */
#define TIMERR_STRUCT  (TIMERR_BASE + 33) /* time struct size */

    MMRESULT WINAPI timeGetDevCaps(LPTIMECAPS ptc, UINT cbtc);
    MMRESULT WINAPI timeBeginPeriod(UINT uPeriod);
    MMRESULT WINAPI timeEndPeriod(UINT uPeriod);

#define SND_SYNC      0x0000
#define SND_ASYNC     0x0001
#define SND_NODEFAULT 0x0002
#define SND_MEMORY    0x0004
#define SND_LOOP      0x0008
#define SND_NOSTOP    0x0010
#define SND_NOWAIT    0x00002000
#define SND_PURGE     0x0040
#define SND_RESOURCE  0x00040000
#define SND_ALIAS     0x00010000
#define SND_ALIAS_ID  0x00110000
#define SND_FILENAME  0x00020000
#define SND_RESERVED  0x00080000

    BOOL WINAPI PlaySound(LPCSTR pszSound, HMODULE hmod, DWORD fdwSound);
#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__MMSYSTEM_H__