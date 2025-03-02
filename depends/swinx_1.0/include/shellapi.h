#ifndef _SHELL_API_H_
#define _SHELL_API_H_

#include <windows.h>
#include <guiddef.h>

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

    UINT WINAPI DragQueryFileA(_In_ HDROP hDrop, _In_ UINT iFile, _Out_writes_opt_(cch) LPSTR lpszFile, _In_ UINT cch);
    UINT WINAPI DragQueryFileW(_In_ HDROP hDrop, _In_ UINT iFile, _Out_writes_opt_(cch) LPWSTR lpszFile, _In_ UINT cch);
#ifdef UNICODE
#define DragQueryFile DragQueryFileW
#else
#define DragQueryFile DragQueryFileA
#endif // !UNICODE
    BOOL WINAPI DragQueryPoint(_In_ HDROP hDrop, _Out_ POINT *ppt);
    void WINAPI DragFinish(_In_ HDROP hDrop);
    void WINAPI DragAcceptFiles(_In_ HWND hWnd, _In_ BOOL fAccept);

    typedef struct _NOTIFYICONDATAA
    {
        DWORD cbSize;
        HWND hWnd;
        UINT uID;
        UINT uFlags;
        UINT uCallbackMessage;
        HICON hIcon;
        char szTip[128];
        DWORD dwState;
        DWORD dwStateMask;
        char szInfo[256];
        union {
            UINT uTimeout;
            UINT uVersion;
        } DUMMYUNIONNAME;
        char szInfoTitle[64];
        DWORD dwInfoFlags;
        GUID guidItem;
        HICON hBalloonIcon;
    } NOTIFYICONDATAA, *PNOTIFYICONDATAA;

    typedef struct _NOTIFYICONDATAW
    {
        DWORD cbSize;
        HWND hWnd;
        UINT uID;
        UINT uFlags;
        UINT uCallbackMessage;
        HICON hIcon;
        wchar_t szTip[128];
        DWORD dwState;
        DWORD dwStateMask;
        wchar_t szInfo[256];
        union {
            UINT uTimeout;
            UINT uVersion;
        } DUMMYUNIONNAME;
        wchar_t szInfoTitle[64];
        DWORD dwInfoFlags;
        GUID guidItem;
        HICON hBalloonIcon;
    } NOTIFYICONDATAW, *PNOTIFYICONDATAW;

#define NIM_ADD        0x00000000
#define NIM_MODIFY     0x00000001
#define NIM_DELETE     0x00000002
#define NIM_SETFOCUS   0x00000003
#define NIM_SETVERSION 0x00000004

    BOOL WINAPI Shell_NotifyIconA(DWORD dwMessage, PNOTIFYICONDATAA lpData);

    BOOL WINAPI Shell_NotifyIconW(DWORD dwMessage, PNOTIFYICONDATAW lpData);

#define NIF_MESSAGE 0x00000001

#define NIF_ICON 0x00000002

#define NIF_TIP 0x00000004

#define NIF_STATE 0x00000008

#define NIF_INFO 0x00000010

#define NIF_GUID 0x00000020

#define NIF_REALTIME 0x00000040

#define NIF_SHOWTIP 0x00000080

#ifdef UNICODE
#define NOTIFYICONDATA   NOTIFYICONDATAW
#define Shell_NotifyIcon Shell_NotifyIconW
#else
#define NOTIFYICONDATA   NOTIFYICONDATAA
#define Shell_NotifyIcon Shell_NotifyIconA
#endif

// Flags for PathMatchSpecEx
#define PMSF_NORMAL            0x00000000  //The pszSpec parameter consists of a single specification to be matched.
#define PMSF_MULTIPLE          0x00000001  //The pszSpec parameter consists of a semicolon-delimited list of specifications to be matched.
#define PMSF_DONT_STRIP_SPACES 0x00010000  // modifies either of the above

BOOL WINAPI PathMatchSpecExW(
    LPCWSTR pszFile,
    LPCWSTR pszSpec,
    DWORD   dwFlags
  );

BOOL WINAPI PathMatchSpecExA(
    LPCSTR pszFile,
    LPCSTR pszSpec,
    DWORD   dwFlags
  );

BOOL WINAPI PathMatchSpecW(
    LPCWSTR pszFile,
    LPCWSTR pszSpec
  );

BOOL WINAPI PathMatchSpecA(
    LPCSTR pszFile,
    LPCSTR pszSpec
  );

#ifdef UNICODE
#define PathMatchSpec   PathMatchSpecW
#define PathMatchSpecEx PathMatchSpecExW
#else
#define PathMatchSpec   PathMatchSpecA
#define PathMatchSpecEx PathMatchSpecExA
#endif


// Note CLASSKEY overrides CLASSNAME
#define SEE_MASK_DEFAULT           0x00000000
#define SEE_MASK_CLASSNAME         0x00000001   // SHELLEXECUTEINFO.lpClass is valid
#define SEE_MASK_CLASSKEY          0x00000003   // SHELLEXECUTEINFO.hkeyClass is valid
// Note SEE_MASK_INVOKEIDLIST(0xC) implies SEE_MASK_IDLIST(0x04)
#define SEE_MASK_IDLIST            0x00000004   // SHELLEXECUTEINFO.lpIDList is valid
#define SEE_MASK_INVOKEIDLIST      0x0000000c   // enable IContextMenu based verbs
#define SEE_MASK_ICON              0x00000010   // not used
#define SEE_MASK_HOTKEY            0x00000020   // SHELLEXECUTEINFO.dwHotKey is valid
#define SEE_MASK_NOCLOSEPROCESS    0x00000040   // SHELLEXECUTEINFO.hProcess
#define SEE_MASK_CONNECTNETDRV     0x00000080   // enables re-connecting disconnected network drives
#define SEE_MASK_NOASYNC           0x00000100   // block on the call until the invoke has completed, use for callers that exit after calling ShellExecuteEx()
#define SEE_MASK_FLAG_DDEWAIT      SEE_MASK_NOASYNC // Use SEE_MASK_NOASYNC instead of SEE_MASK_FLAG_DDEWAIT as it more accuratly describes the behavior
#define SEE_MASK_DOENVSUBST        0x00000200   // indicates that SHELLEXECUTEINFO.lpFile contains env vars that should be expanded
#define SEE_MASK_FLAG_NO_UI        0x00000400   // disable UI including error messages
#define SEE_MASK_UNICODE           0x00004000
#define SEE_MASK_NO_CONSOLE        0x00008000
#define SEE_MASK_ASYNCOK           0x00100000
#define SEE_MASK_HMONITOR          0x00200000   // SHELLEXECUTEINFO.hMonitor
#define SEE_MASK_NOZONECHECKS      0x00800000
#define SEE_MASK_NOQUERYCLASSSTORE 0x01000000
#define SEE_MASK_WAITFORINPUTIDLE  0x02000000
#define SEE_MASK_FLAG_LOG_USAGE    0x04000000

  BOOL WINAPI ShellExecuteA(HWND hwnd, LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd);

  BOOL WINAPI ShellExecuteW(HWND hwnd, LPCWSTR lpOperation, LPCWSTR lpFile, LPCWSTR lpParameters, LPCWSTR lpDirectory, INT nShowCmd);

typedef struct _SHELLEXECUTEINFOA {
    DWORD cbSize;
    ULONG fMask;
    HWND hwnd;
    LPCSTR lpVerb;
    LPCSTR lpFile;
    LPCSTR lpParameters;
    LPCSTR lpDirectory;
    int nShow;
    HINSTANCE hInstApp;
    LPVOID lpIDList;
    LPCSTR lpClass;
    HKEY hkeyClass;
    DWORD dwHotKey;
    union {
        HANDLE hIcon;
        HANDLE hMonitor;
    } DUMMYUNIONNAME;
    HANDLE hProcess;
} SHELLEXECUTEINFOA, *LPSHELLEXECUTEINFOA;

typedef struct _SHELLEXECUTEINFOW {
    DWORD cbSize;
    ULONG fMask;
    HWND hwnd;
    LPCWSTR lpVerb;
    LPCWSTR lpFile;
    LPCWSTR lpParameters;
    LPCWSTR lpDirectory;
    int nShow;
    HINSTANCE hInstApp;
    LPVOID lpIDList;
    LPCWSTR lpClass;
    HKEY hkeyClass;
    DWORD dwHotKey;
    union {
        HANDLE hIcon;
        HANDLE hMonitor;
    } DUMMYUNIONNAME;
    HANDLE hProcess;
} SHELLEXECUTEINFOW, *LPSHELLEXECUTEINFOW;

    BOOL WINAPI ShellExecuteExA(LPSHELLEXECUTEINFOA lpExecInfo);
    BOOL WINAPI ShellExecuteExW(LPSHELLEXECUTEINFOW lpExecInfo);


#ifdef UNICODE
#define SHELLEXECUTEINFO    SHELLEXECUTEINFOW
#define ShellExecute ShellExecuteW
#define ShellExecuteEx ShellExecuteExW
#else
#define SHELLEXECUTEINFO SHELLEXECUTEINFOA
#define ShellExecute    ShellExecuteA
#define ShellExecuteEx ShellExecuteExA
#endif//UNICODE

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //_SHELL_API_H_