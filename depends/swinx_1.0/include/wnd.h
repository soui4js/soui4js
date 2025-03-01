#ifndef _WND_H__
#define _WND_H__
#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#ifndef GET_X_LPARAM
#define GET_X_LPARAM(lParam) ((int)(short)LOWORD(lParam))
#endif
#ifndef GET_Y_LPARAM
#define GET_Y_LPARAM(lParam) ((int)(short)HIWORD(lParam))
#endif

#define CLS_WINDOW "window"

    /***********************************************************************
     *		CreateWindowExW (USER32.@)
     */
    HWND WINAPI CreateWindowExA(DWORD exStyle, LPCSTR className, LPCSTR windowName, DWORD style, INT x, INT y, INT width, INT height, HWND parent, HMENU menu, HINSTANCE instance, LPVOID data);
    HWND WINAPI CreateWindowExW(DWORD exStyle, LPCWSTR className, LPCWSTR windowName, DWORD style, INT x, INT y, INT width, INT height, HWND parent, HMENU menu, HINSTANCE instance, LPVOID data);

    HWND WINAPI CreateWindowA(LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
    HWND WINAPI CreateWindowW(LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
    int WINAPI GetClassNameA(HWND hWnd, LPSTR lpClassName, int nMaxCount);
    int WINAPI GetClassNameW(HWND hWnd, LPWSTR lpClassName, int nMaxCount);

#ifdef UNICODE
#define CreateWindow   CreateWindowW
#define CreateWindowEx CreateWindowExW
#define GetClassName   GetClassNameW
#else
#define CreateWindow   CreateWindowA
#define CreateWindowEx CreateWindowExA
#define GetClassName   GetClassNameA
#endif // UNICODE

    BOOL WINAPI DestroyWindow(HWND hWnd);

    BOOL WINAPI IsWindow(HWND hwnd);

    void WINAPI PostQuitMessage(int nExitCode);

    LRESULT WINAPI CallWindowProc(WNDPROC proc, HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

    BOOL WINAPI PostMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
    BOOL WINAPI PostMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

    LRESULT WINAPI SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
    LRESULT WINAPI SendMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

    LRESULT WINAPI SendMessageTimeoutA(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp, UINT fuFlags, UINT uTimeout, PDWORD_PTR lpdwResult);
    LRESULT WINAPI SendMessageTimeoutW(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp, UINT fuFlags, UINT uTimeout, PDWORD_PTR lpdwResult);

    typedef VOID(CALLBACK *SENDASYNCPROC)(HWND, UINT, ULONG_PTR, LRESULT);

    BOOL WINAPI SendMessageCallbackA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, SENDASYNCPROC lpCallBack, ULONG_PTR dwData);
    BOOL WINAPI SendMessageCallbackW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, SENDASYNCPROC lpCallBack, ULONG_PTR dwData);

    int WINAPI MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
    int WINAPI MessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType);

    BOOL SendNotifyMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
    BOOL SendNotifyMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

#ifdef UNICODE
#define PostMessage         PostMessageW
#define SendMessage         SendMessageW
#define SendMessageTimeout  SendMessageTimeoutW
#define SendMessageCallback SendMessageCallbackW
#define MessageBox          MessageBoxW
#define SendNotifyMessage   SendNotifyMessageW
#else
#define PostMessage         PostMessageA
#define SendMessage         SendMessageA
#define SendMessageTimeout  SendMessageTimeoutA
#define SendMessageCallback SendMessageCallbackW
#define MessageBox          MessageBoxA
#define SendNotifyMessage   SendNotifyMessageA

#endif // UNICODE
    tid_t WINAPI GetWindowThreadProcessId(HWND hWnd, LPDWORD lpdwProcessId);

    BOOL WINAPI SetForegroundWindow(HWND hWnd);

    HWND WINAPI GetForegroundWindow();

    BOOL WINAPI SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags);

    LONG GetWindowLongA(HWND hWnd, int nIndex);
    LONG GetWindowLongW(HWND hWnd, int nIndex);

    LONG SetWindowLongA(HWND hWnd, int nIndex, LONG data);
    LONG SetWindowLongW(HWND hWnd, int nIndex, LONG data);

    LONG_PTR GetWindowLongPtrA(HWND hWnd, int nIndex);
    LONG_PTR GetWindowLongPtrW(HWND hWnd, int nIndex);

    LONG_PTR SetWindowLongPtrA(HWND hWnd, int nIndex, LONG_PTR data);
    LONG_PTR SetWindowLongPtrW(HWND hWnd, int nIndex, LONG_PTR data);

#ifdef UNICODE
#define GetWindowLong    GetWindowLongW
#define SetWindowLong    SetWindowLongW
#define GetWindowLongPtr GetWindowLongPtrW
#define SetWindowLongPtr SetWindowLongPtrW
#else
#define GetWindowLong    GetWindowLongA
#define SetWindowLong    SetWindowLongA
#define GetWindowLongPtr GetWindowLongPtrA
#define SetWindowLongPtr SetWindowLongPtrA
#endif // UNICODE

    DWORD
    WINAPI
    GetClassLongA(_In_ HWND hWnd, _In_ int nIndex);

    DWORD
    WINAPI
    GetClassLongW(_In_ HWND hWnd, _In_ int nIndex);
#ifdef UNICODE
#define GetClassLong GetClassLongW
#else
#define GetClassLong GetClassLongA
#endif // !UNICODE

    DWORD
    WINAPI
    SetClassLongA(_In_ HWND hWnd, _In_ int nIndex, _In_ LONG dwNewLong);

    DWORD
    WINAPI
    SetClassLongW(_In_ HWND hWnd, _In_ int nIndex, _In_ LONG dwNewLong);
#ifdef UNICODE
#define SetClassLong SetClassLongW
#else
#define SetClassLong SetClassLongA
#endif // !UNICODE

    ULONG_PTR
    WINAPI
    GetClassLongPtrA(_In_ HWND hWnd, _In_ int nIndex);

    ULONG_PTR
    WINAPI
    GetClassLongPtrW(_In_ HWND hWnd, _In_ int nIndex);
#ifdef UNICODE
#define GetClassLongPtr GetClassLongPtrW
#else
#define GetClassLongPtr GetClassLongPtrA
#endif // !UNICODE

    ULONG_PTR
    WINAPI
    SetClassLongPtrA(_In_ HWND hWnd, _In_ int nIndex, _In_ LONG_PTR dwNewLong);

    ULONG_PTR
    WINAPI
    SetClassLongPtrW(_In_ HWND hWnd, _In_ int nIndex, _In_ LONG_PTR dwNewLong);
#ifdef UNICODE
#define SetClassLongPtr SetClassLongPtrW
#else
#define SetClassLongPtr SetClassLongPtrA
#endif // !UNICODE

    BOOL CreateCaret(HWND hWnd, HBITMAP hBitmap, int nWidth, int nHeight);

    BOOL DestroyCaret(VOID);

    BOOL HideCaret(HWND hWnd);

    BOOL ShowCaret(HWND hWnd);

    BOOL SetCaretPos(int X, int Y);

    BOOL GetCaretPos(LPPOINT lpPoint);

    void SetCaretBlinkTime(UINT blinkTime);
    UINT GetCaretBlinkTime();

    HWND GetActiveWindow();

    HWND GetDesktopWindow();

    BOOL IsWindowEnabled(HWND hWnd);

    BOOL EnableWindow(HWND hWnd, BOOL bEnable);

    HWND SetActiveWindow(HWND hWnd);

    HWND GetParent(HWND hwnd);
    HWND SetParent(HWND hWnd, HWND hParent);

    BOOL GetCursorPos(LPPOINT ppt);

    HWND WindowFromPoint(POINT pt);

    DWORD GetTickCount();

    uint64_t GetTickCount64();

    typedef VOID(CALLBACK *TIMERPROC)(HWND hwnd, UINT msg, UINT_PTR timerId, DWORD ts);

    UINT_PTR
    SetTimer(HWND hWnd, UINT_PTR nIDEvent, UINT uElapse, TIMERPROC lpTimerFunc);

    BOOL KillTimer(HWND hWnd, UINT_PTR uIDEvent);

    HWND GetFocus();

    HWND SetFocus(HWND hWnd);

    typedef struct _PAINTSTRUCT
    {
        HDC hdc;
        RECT rcPaint;
        BOOL fErase;
    } PAINTSTRUCT;

    HDC BeginPaint(HWND hWnd, PAINTSTRUCT *ps);
    BOOL EndPaint(HWND hWnd, const PAINTSTRUCT *ps);

    int GetUpdateRgn(HWND hWnd,  // handle to window
                     HRGN hRgn,  // handle to region
                     BOOL bErase // erase state
    );
    BOOL UpdateWindow(HWND hWnd);

    BOOL GetClientRect(HWND hWnd, RECT *lpRect);
    BOOL GetWindowRect(HWND hWnd, RECT *lpRect);
    BOOL InvalidateRect(HWND hWnd, const RECT *lpRect, BOOL bErase);

    BOOL ClientToScreen(HWND hWnd, LPPOINT ppt);
    BOOL ScreenToClient(HWND hWnd, LPPOINT ppt);

    LRESULT DefWindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

    BOOL ShowWindow(HWND hWnd, int nCmdShow);

    BOOL MoveWindow(HWND hWnd, int x, int y, int nWidth, int nHeight, BOOL bRepaint);

    BOOL IsWindowVisible(HWND hWnd);

    BOOL IsZoomed(HWND hWnd);
    BOOL IsIconic(HWND hWnd);
    int GetWindowTextA(HWND hWnd, LPSTR lpszStringBuf, int nMaxCount);
    int GetWindowTextW(HWND hWnd, LPWSTR lpszStringBuf, int nMaxCount);

    int GetWindowTextLengthA(HWND hWnd);
    int GetWindowTextLengthW(HWND hWnd);
    BOOL SetWindowTextA(HWND hWnd, LPCSTR lpszString);
    BOOL SetWindowTextW(HWND hWnd, LPCWSTR lpszString);
#ifdef UNICODE
#define GetWindowTextLength GetWindowTextLengthW
#define GetWindowText       GetWindowTextW
#define SetWindowText       SetWindowTextW
#else
#define GetWindowTextLength GetWindowTextLengthA
#define GetWindowText       GetWindowTextA
#define SetWindowText       SetWindowTextA
#endif // UNICODE

    HDC GetDC(HWND hWnd);

#define DCX_WINDOW           0x0001
#define DCX_LOCKWINDOWUPDATE 0x0002
#define DCX_CACHE            0x0004
#define DCX_OP_MASK          0xffff
#define DCX_INTERSECTRGN     0x10000
#define DCX_EXCLUDERGN       0x20000
#define DCX_RGN_MASK         0xf0000

    HDC GetDCEx(HWND hWnd, HRGN hrgnClip, DWORD flags);
    HDC GetWindowDC(HWND hWnd);

    int ReleaseDC(HWND hWnd, HDC hdc);

    int MapWindowPoints(HWND hWndFrom, HWND hWndTo, LPPOINT lpPoint, UINT nCount);

    HWND WINAPI SetCapture(HWND hWnd);

    BOOL WINAPI ReleaseCapture();

    HWND WINAPI GetCapture();

    UINT WINAPI GetDpiForWindow(HWND hWnd);

    BOOL WINAPI SetLayeredWindowAttributes(HWND hwnd, COLORREF crKey, BYTE bAlpha, DWORD dwFlags);

    int WINAPI SetWindowRgn(HWND hWnd,   // handle to window
                            HRGN hRgn,   // handle to region
                            BOOL bRedraw // window redraw option
    );

    HWND WINAPI GetWindow(HWND hWnd, UINT uCmd);

    //------------------------------------------------

#define SB_HORZ 1
#define SB_VERT 2
#define SB_BOTH (SB_HORZ | SB_VERT)

    BOOL WINAPI EnableScrollBar(HWND hWnd, UINT wSBflags, UINT wArrows);

    BOOL WINAPI ShowScrollBar(HWND hWnd, int wBar, BOOL bShow);

    int WINAPI SetScrollInfo(HWND hwnd, int fnBar, LPCSCROLLINFO lpsi, BOOL fRedraw);

    BOOL WINAPI GetScrollInfo(HWND hwnd, int fnBar, LPSCROLLINFO lpsi);

    int WINAPI GetScrollPos(HWND hWnd, int nBar);

    int WINAPI SetScrollPos(HWND hWnd, int nBar, int nPos, BOOL bRedraw);

    BOOL WINAPI GetScrollRange(HWND hWnd, int nBar, LPINT lpMinPos, LPINT lpMaxPos);

    BOOL WINAPI SetScrollRange(HWND hWnd, int nBar, int nMinPos, int nMaxPos, BOOL bRedraw);

    BOOL WINAPI AdjustWindowRectEx(LPRECT rect, DWORD style, BOOL menu, DWORD exStyle);

    int WINAPI GetDlgCtrlID(HWND hwndCtl);

    LONG WINAPI GetMessageTime(VOID);
    DWORD WINAPI GetMessagePos(VOID);

    BOOL WINAPI IsChild(HWND hWndParent, HWND hWnd);

    HWND WINAPI GetDlgItem(_In_opt_ HWND hDlg, _In_ int nIDDlgItem);

    int WINAPI ScrollWindowEx(HWND hWnd, int dx, int dy, const RECT *prcScroll, const RECT *prcClip, HRGN hrgnUpdate, LPRECT prcUpdate, UINT flags);

    UINT WINAPI RegisterWindowMessageA(_In_ LPCSTR lpString);
    UINT WINAPI RegisterWindowMessageW(_In_ LPCWSTR lpString);
#ifdef UNICODE
#define RegisterWindowMessage RegisterWindowMessageW
#else
#define RegisterWindowMessage RegisterWindowMessageA
#endif // !UNICODE

    BOOL WINAPI IsWindowUnicode(HWND hWnd);

    typedef BOOL(CALLBACK *WNDENUMPROC)(HWND hwnd, LPARAM lParam);

    BOOL WINAPI EnumWindows(WNDENUMPROC lpEnumFunc, LPARAM lParam);

    typedef struct
    {
        UINT cbSize;
        HWND hwnd;
        DWORD dwFlags;
        UINT uCount;
        DWORD dwTimeout;
    } FLASHWINFO, *PFLASHWINFO;

#define FLASHW_CAPTION   0x00000001
#define FLASHW_TRAY      0x00000002
#define FLASHW_ALL       0x00000003
#define FLASHW_STOP      0
#define FLASHW_TIMER     0x00000004
#define FLASHW_TIMERNOFG 0x0000000C

    BOOL WINAPI FlashWindowEx(PFLASHWINFO pfwi);
    BOOL WINAPI FlashWindow(HWND hWnd, BOOL bInvert);

    BOOL WINAPI AnimateWindow(HWND hwnd, DWORD time, DWORD flags);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //_WND_H__