#ifndef _HOOK_H_
#define _HOOK_H_

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

    typedef LRESULT(CALLBACK *HOOKPROC)(int code, WPARAM wParam, LPARAM lParam);
    typedef struct hook *HHOOK;

    HHOOK WINAPI SetWindowsHookA(INT id, HOOKPROC proc);

    HHOOK WINAPI SetWindowsHookW(INT id, HOOKPROC proc);

    HHOOK WINAPI SetWindowsHookExA(INT idHook, HOOKPROC lpfn, HINSTANCE hmod, tid_t dwThreadId);

    HHOOK WINAPI SetWindowsHookExW(INT idHook, HOOKPROC lpfn, HINSTANCE hmod, tid_t dwThreadId);

    BOOL WINAPI UnhookWindowsHookEx(HHOOK hhk);

    LRESULT WINAPI CallNextHookEx(HHOOK hhk, int nCode, WPARAM wParam, LPARAM lParam);
    BOOL WINAPI CallHook(INT id, int nCode, WPARAM wParam, LPARAM lParam);
#ifdef UNICODE
#define SetWindowsHookEx SetWindowsHookExW
#define SetWindowsHook   SetWindowsHookW
#else
#define SetWindowsHookEx SetWindowsHookExA
#define SetWindowsHook   SetWindowsHookA
#endif // UNICODE

#ifdef UNICODE
#define SetWindowsHook   SetWindowsHookW
#define SetWindowsHookEx SetWindowsHookExW
#else
#define SetWindowsHook   SetWindowsHookA
#define SetWindowsHookEx SetWindowsHookExA
#endif // UNICODE

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //_HOOK_H_