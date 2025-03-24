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

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__MMSYSTEM_H__