#ifndef _SYS_API_H
#define _SYS_API_H
#include <ctypes.h>
#include <unistd.h>
#include <malloc.h>

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

    typedef struct RTL_CRITICAL_SECTION
    {
        void *pMutex;
    } RTL_CRITICAL_SECTION;

    typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;
    typedef CRITICAL_SECTION *PCRITICAL_SECTION;
    typedef CRITICAL_SECTION *LPCRITICAL_SECTION;

    VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);

    VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);

    VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);

    BOOL WINAPI TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);

    VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);

    typedef struct _RTL_SRWLOCK
    {
        PVOID Ptr;
    } RTL_SRWLOCK, *PRTL_SRWLOCK;

    typedef RTL_SRWLOCK SRWLOCK, *PSRWLOCK;

    VOID WINAPI InitializeSRWLock(PSRWLOCK SRWLock);

    VOID WINAPI UninitializeSRWLock(PSRWLOCK SRWLock);

    VOID WINAPI AcquireSRWLockExclusive(PSRWLOCK SRWLock);

    VOID WINAPI ReleaseSRWLockExclusive(PSRWLOCK SRWLock);

    VOID WINAPI AcquireSRWLockShared(PSRWLOCK SRWLock);

    VOID WINAPI ReleaseSRWLockShared(PSRWLOCK SRWLock);

    LONG WINAPI InterlockedDecrement(LONG volatile *v);

    LONG WINAPI InterlockedIncrement(LONG volatile *v);

    void qsort_s(void *_Base, size_t _NumOfElements, size_t _SizeOfElements, int(__cdecl *_PtFuncCompare)(void *, const void *, const void *), void *_Context);

    BOOL IIDFromString(LPCWSTR s, GUID *id);

    void SetLastError(int e);

    int GetLastError();

    int MulDiv(int a, int b, int c);

    tid_t WINAPI GetCurrentThreadId();

    int MultiByteToWideChar(int cp, int flags, const char *src, int len, wchar_t *dst, int dstLen);

    int WideCharToMultiByte(int cp, int flags, const wchar_t *src, int len, char *dst, int dstLen, LPCSTR p1, BOOL *p2);

#define STIF_DEFAULT     0x00000000L
#define STIF_SUPPORT_HEX 0x00000001L
    BOOL StrToInt64ExW(const wchar_t *str, DWORD flags, LONGLONG *ret);
    BOOL StrToIntExW(const wchar_t *str, DWORD flags, INT *ret);

    BOOL StrToInt64ExA(const char *str, DWORD flags, LONGLONG *ret);
    BOOL StrToIntExA(const char *str, DWORD flags, INT *ret);

#ifdef UNICODE
#define StrToInt64Ex StrToInt64ExW
#define StrToIntEx   StrToIntExW
#else
#define StrToInt64Ex StrToInt64ExA
#define StrToIntEx   StrToIntExA
#endif // UNICODE



typedef struct _SECURITY_ATTRIBUTES
{
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

#define STARTF_USESHOWWINDOW       0x00000001
#define STARTF_USESIZE             0x00000002
#define STARTF_USEPOSITION         0x00000004
#define STARTF_USECOUNTCHARS       0x00000008
#define STARTF_USEFILLATTRIBUTE    0x00000010
#define STARTF_RUNFULLSCREEN       0x00000020  // ignored for non-x86 platforms
#define STARTF_FORCEONFEEDBACK     0x00000040
#define STARTF_FORCEOFFFEEDBACK    0x00000080
#define STARTF_USESTDHANDLES       0x00000100


typedef struct _STARTUPINFOA{
DWORD cb;
LPSTR lpReserved;
LPSTR lpDesktop;
LPSTR lpTitle;
DWORD dwX;
DWORD dwY;
DWORD dwXSize;
DWORD dwYSize;
DWORD dwXCountChars;
DWORD dwYCountChars;
DWORD dwFillAttribute;
DWORD dwFlags;
WORD wShowWindow;
WORD cbReserved2;
LPBYTE lpReserved2;
HANDLE hStdInput;
HANDLE hStdOutput;
HANDLE hStdError;    
}STARTUPINFOA, * LPSTARTUPINFOA;


typedef struct _STARTUPINFOW{
DWORD cb;
LPWSTR lpReserved;
LPWSTR lpDesktop;
LPWSTR lpTitle;
DWORD dwX;
DWORD dwY;
DWORD dwXSize;
DWORD dwYSize;
DWORD dwXCountChars;
DWORD dwYCountChars;
DWORD dwFillAttribute;
DWORD dwFlags;
WORD wShowWindow;
WORD cbReserved2;
LPBYTE lpReserved2;
HANDLE hStdInput;
HANDLE hStdOutput;
HANDLE hStdError;    
}STARTUPINFOW, * LPSTARTUPINFOW;

typedef struct _PROCESS_INFORMATION {
    HANDLE hProcess;  
    HANDLE hThread;  
    DWORD dwProcessId;  
    tid_t dwThreadId;
} PROCESS_INFORMATION,  *LPPROCESS_INFORMATION;


enum {
    Verb_Unknown=0,
    Verb_Open,
    Verb_RunAs, //root user
};

#define __in
#define __out
BOOL WINAPI CreateProcessAsUserA(
    __in          HANDLE hToken,
    __in          LPCSTR lpApplicationName,
    __in          LPSTR lpCommandLine,
    __in          LPSECURITY_ATTRIBUTES lpProcessAttributes,
    __in          LPSECURITY_ATTRIBUTES lpThreadAttributes,
    __in          BOOL bInheritHandles,
    __in          DWORD dwCreationFlags,
    __in          LPVOID lpEnvironment,
    __in          LPCSTR lpCurrentDirectory,
    __in          LPSTARTUPINFOA lpStartupInfo,
    __out         LPPROCESS_INFORMATION lpProcessInformation
  );

BOOL WINAPI CreateProcessAsUserW(
    __in          HANDLE hToken,
    __in          LPCWSTR lpApplicationName,
    __in          LPWSTR lpCommandLine,
    __in          LPSECURITY_ATTRIBUTES lpProcessAttributes,
    __in          LPSECURITY_ATTRIBUTES lpThreadAttributes,
    __in          BOOL bInheritHandles,
    __in          DWORD dwCreationFlags,
    __in          LPVOID lpEnvironment,
    __in          LPCWSTR lpCurrentDirectory,
    __in          LPSTARTUPINFOW lpStartupInfo,
    __out         LPPROCESS_INFORMATION lpProcessInformation
  );

  BOOL WINAPI CreateProcessA(
    __in          LPCSTR lpApplicationName,
    __in          LPSTR lpCommandLine,
    __in          LPSECURITY_ATTRIBUTES lpProcessAttributes,
    __in          LPSECURITY_ATTRIBUTES lpThreadAttributes,
    __in          BOOL bInheritHandles,
    __in          DWORD dwCreationFlags,
    __in          LPVOID lpEnvironment,
    __in          LPCSTR lpCurrentDirectory,
    __in          LPSTARTUPINFOA lpStartupInfo,
    __out         LPPROCESS_INFORMATION lpProcessInformation
  );
  BOOL WINAPI CreateProcessW(
    __in          LPCWSTR lpApplicationName,
    __in          LPWSTR lpCommandLine,
    __in          LPSECURITY_ATTRIBUTES lpProcessAttributes,
    __in          LPSECURITY_ATTRIBUTES lpThreadAttributes,
    __in          BOOL bInheritHandles,
    __in          DWORD dwCreationFlags,
    __in          LPVOID lpEnvironment,
    __in          LPCWSTR lpCurrentDirectory,
    __in          LPSTARTUPINFOW lpStartupInfo,
    __out         LPPROCESS_INFORMATION lpProcessInformation
  );

  #undef __in
  #undef __out

#ifdef UNICODE
#define STARTUPINFO STARTUPINFOW
#define CreateProcessAsUser CreateProcessAsUserW
#define CreateProcess CreateProcessW
#else
#define STARTUPINFO STARTUPINFOA
#define CreateProcessAsUser CreateProcessAsUserA
#define CreateProcess   CreateProcessA
#endif//UNICODE

    BOOL WINAPI GetExitCodeProcess(HANDLE hProcess, LPDWORD lpExitCode);

    // 读取指定PID的进程状态文件，获取其有效用户ID, 0-root, -1-failed.
    int WINAPI get_process_uid(int pid);

    pid_t WINAPI GetCurrentProcessId();

    pid_t WINAPI GetProcessId( HANDLE Process);
    HANDLE WINAPI GetCurrentProcess(void);

    void GetLocalTime(SYSTEMTIME *pSysTime);
    void GetSystemTime(SYSTEMTIME *lpSystemTime);

    time_t _mkgmtime(struct tm *_Tm);
    int _localtime64_s(struct tm *ptm, const __time64_t *ptime);

    void PostThreadMessageA(uint64_t tid, UINT msg, WPARAM wp, LPARAM lp);
    void PostThreadMessageW(uint64_t tid, UINT msg, WPARAM wp, LPARAM lp);
#ifdef UNICODE
#define PostThreadMessage PostThreadMessageW
#else
#define PostThreadMessage PostThreadMessageA
#endif // UNICODE

    BOOL WaitMessage();
    BOOL GetMessage(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
    BOOL PeekMessage(LPMSG pMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);

    BOOL TranslateMessage(const LPMSG pMsg);
    BOOL DispatchMessage(const LPMSG pMsg);

    int GetSystemScale();
    int GetSystemMetrics(int nIndex);

    HCURSOR SetCursor(HCURSOR hCursor);
    HCURSOR GetCursor(VOID);

    SHORT GetKeyState(int nVirtKey);

    BOOL CallMsgFilter(LPMSG lpMsg, int nCode);

    __time64_t _mktime64(const struct tm *ptime);

    __time64_t _time64(__time64_t *_Time);

    HCURSOR
    LoadCursor(HINSTANCE hInstance, LPCSTR lpCursorName);

    BOOL DestroyCursor(HCURSOR hCursor);

    BOOL WINAPI IsBadReadPtr(const void *ptr, size_t size);
    BOOL WINAPI IsBadWritePtr(const void *ptr, size_t size);

    BOOL WINAPI IsBadStringPtrA(LPCSTR lpsz, UINT_PTR ucchMax);

    BOOL WINAPI IsBadStringPtrW(LPCWSTR lpsz, UINT_PTR ucchMax);
#ifdef UNICODE
#define IsBadStringPtr IsBadStringPtrW
#else
#define IsBadStringPtr IsBadStringPtrA
#endif // UNICODE

    FILE *_wfopen(const wchar_t *path, const wchar_t *mode);

#define HEAP_NO_SERIALIZE             0x00000001
#define HEAP_GROWABLE                 0x00000002
#define HEAP_GENERATE_EXCEPTIONS      0x00000004
#define HEAP_ZERO_MEMORY              0x00000008
#define HEAP_REALLOC_IN_PLACE_ONLY    0x00000010
#define HEAP_TAIL_CHECKING_ENABLED    0x00000020
#define HEAP_FREE_CHECKING_ENABLED    0x00000040
#define HEAP_DISABLE_COALESCE_ON_FREE 0x00000080
#define HEAP_CREATE_ALIGN_16          0x00010000
#define HEAP_CREATE_ENABLE_TRACING    0x00020000
#define HEAP_CREATE_ENABLE_EXECUTE    0x00040000
#define HEAP_MAXIMUM_TAG              0x0FFF
#define HEAP_PSEUDO_TAG_FLAG          0x8000
#define HEAP_TAG_SHIFT                18
#define HEAP_CREATE_SEGMENT_HEAP      0x00000100
#define HEAP_CREATE_HARDENED          0x00000200

#define GMEM_FIXED          0x0000
#define GMEM_MOVEABLE       0x0002
#define GMEM_NOCOMPACT      0x0010
#define GMEM_NODISCARD      0x0020
#define GMEM_ZEROINIT       0x0040
#define GMEM_MODIFY         0x0080
#define GMEM_DISCARDABLE    0x0100
#define GMEM_NOT_BANKED     0x1000
#define GMEM_SHARE          0x2000
#define GMEM_DDESHARE       0x2000
#define GMEM_NOTIFY         0x4000
#define GMEM_LOWER          GMEM_NOT_BANKED
#define GMEM_DISCARDED      0x4000
#define GMEM_LOCKCOUNT      0x00ff
#define GMEM_INVALID_HANDLE 0x8000

#define GHND (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define GPTR (GMEM_FIXED | GMEM_ZEROINIT)

#define LMEM_FIXED          0
#define LMEM_MOVEABLE       0x0002
#define LMEM_NOCOMPACT      0x0010
#define LMEM_NODISCARD      0x0020
#define LMEM_ZEROINIT       0x0040
#define LMEM_MODIFY         0x0080
#define LMEM_DISCARDABLE    0x0F00
#define LMEM_DISCARDED      0x4000
#define LMEM_INVALID_HANDLE 0x8000
#define LMEM_LOCKCOUNT      0x00FF

#define LPTR (LMEM_FIXED | LMEM_ZEROINIT)
#define LHND (LMEM_MOVEABLE | LMEM_ZEROINIT)

    HANDLE WINAPI GetProcessHeap();

    HANDLE WINAPI HeapCreate(DWORD flOptions, size_t dwInitialSize, size_t dwMaximumSize);

    BOOL WINAPI HeapDestroy(HANDLE hHeap);

    BOOL WINAPI HeapLock(HANDLE hHeap);

    BOOL WINAPI HeapUnlock(HANDLE hHeap);

    LPVOID
    WINAPI
    HeapAlloc(HANDLE hHeap, DWORD dwFlags, size_t dwBytes);

    BOOL WINAPI HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);

    LPVOID WINAPI HeapReAlloc(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem, SIZE_T dwBytes);

    SIZE_T WINAPI HeapSize(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem);

    BOOL WINAPI HeapValidate(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem);

    BOOL WINAPI FlushInstructionCache(HANDLE hProcess, LPCVOID lpBaseAddress, size_t dwSize);

    HGLOBAL WINAPI GlobalAlloc(UINT flags, SIZE_T size);
    HGLOBAL WINAPI GlobalReAlloc(_In_ HGLOBAL hMem, _In_ SIZE_T dwBytes, _In_ UINT uFlags);
    HGLOBAL WINAPI GlobalFree(HLOCAL hmem);
    UINT WINAPI GlobalFlags(_In_ HGLOBAL hMem);
    HLOCAL WINAPI GlobalHandle(_In_ LPCVOID pMem);

    BOOL WINAPI GlobalUnlock(_In_ HGLOBAL hMem);

    LPVOID
    WINAPI
    GlobalLock(_In_ HGLOBAL hMem);

    SIZE_T
    WINAPI
    GlobalSize(_In_ HGLOBAL hMem);

    UINT WINAPI LocalSize(HLOCAL hMem);
    HLOCAL WINAPI LocalAlloc(UINT flags, SIZE_T size);
    HLOCAL WINAPI LocalReAlloc(HLOCAL hmem, SIZE_T size, UINT flags);
    HLOCAL WINAPI LocalFree(HLOCAL hmem);
    LPVOID WINAPI LocalLock(HLOCAL hmem);
    BOOL WINAPI LocalUnlock(HLOCAL hmem);
    UINT WINAPI LocalFlags(_In_ HLOCAL hMem);
    HLOCAL WINAPI LocalHandle(_In_ LPCVOID pMem);

    HANDLE
    WINAPI
    GetCurrentProcess(VOID);

    DWORD WINAPI GetModuleFileNameA(HMODULE hModule, LPSTR lpFilename, DWORD nSize);
    DWORD WINAPI GetModuleFileNameW(HMODULE hModule, LPWSTR lpFilename, DWORD nSize);

#ifdef UNICODE
#define GetModuleFileName GetModuleFileNameW
#else
#define GetModuleFileName GetModuleFileNameA
#endif // UNICODE

#ifdef __x86_64__
    typedef INT_PTR(FAR WINAPI *FARPROC)();
    typedef INT_PTR(NEAR WINAPI *NEARPROC)();
    typedef INT_PTR(WINAPI *PROC)();
#else
typedef int(FAR WINAPI *FARPROC)();
typedef int(NEAR WINAPI *NEARPROC)();
typedef int(WINAPI *PROC)();
#endif // __x86_64__

    HMODULE WINAPI LoadLibraryA(LPCSTR lpFileName);

    HMODULE WINAPI LoadLibraryW(LPCWSTR lpFileName);

#ifdef _UNICODE
#define LoadLibrary LoadLibraryW
#else
#define LoadLibrary LoadLibraryA
#endif

    static inline BOOL WINAPI FreeLibrary(HMODULE hModule)
    {
        return dlclose(hModule);
    }

    static inline FARPROC WINAPI GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
    {
        return (FARPROC)dlsym(hModule, lpProcName);
    }


    HANDLE WINAPI CreateSemaphoreA(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes, LONG lInitialCount, LONG lMaximumCount, LPCSTR name);

    HANDLE WINAPI CreateSemaphoreW(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes, LONG lInitialCount, LONG lMaximumCount, LPCWSTR lpName);

    HANDLE WINAPI OpenSemaphoreA(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCSTR lpName);

    HANDLE WINAPI OpenSemaphoreW(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCWSTR lpName);

    BOOL WINAPI ReleaseSemaphore(HANDLE hSemaphore, LONG lReleaseCount, LPLONG lpPreviousCount);

    HANDLE WINAPI CreateEventA(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState, LPCSTR lpName);

    HANDLE WINAPI CreateEventW(LPSECURITY_ATTRIBUTES lpEventAttributes, BOOL bManualReset, BOOL bInitialState, LPCWSTR lpName);

    HANDLE WINAPI OpenEventA(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCSTR lpName);

    HANDLE WINAPI OpenEventW(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCWSTR lpName);

    HANDLE WINAPI CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName);

    HANDLE WINAPI CreateMutexW(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCWSTR lpName);

    BOOL WINAPI ReleaseMutex(HANDLE hMutex);

    HANDLE WINAPI OpenMutexA(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCSTR lpName);

    HANDLE WINAPI OpenMutexW(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCWSTR lpName);

#ifdef _UNICODE
#define CreateEvent     CreateEventW
#define OpenEvent       OpenEventW
#define CreateSemaphore CreateSemaphoreW
#define OpenSemaphore   OpenSemaphoreW
#define CreateMutex     CreateMutexW
#define OpenMutex       OpenMutexW
#else
#define CreateEvent     CreateEventA
#define OpenEvent       OpenEventA
#define CreateSemaphore CreateSemaphoreA
#define OpenSemaphore   OpenSemaphoreA
#define CreateMutex     CreateMutexA
#define OpenMutex       OpenMutexA
#endif

    BOOL WINAPI CloseHandle(HANDLE h);

    BOOL WINAPI ResetEvent(HANDLE hEvent);

    BOOL WINAPI SetEvent(HANDLE hEvent);

    DWORD WINAPI WaitForSingleObject(HANDLE hHandle, DWORD dwMilliseconds);

    DWORD WINAPI WaitForMultipleObjects(DWORD nCount, const HANDLE *lpHandles, BOOL bWaitAll, DWORD dwMilliseconds);

    DWORD WINAPI MsgWaitForMultipleObjects(DWORD nCount, const HANDLE *pHandles, BOOL fWaitAll, DWORD dwMilliseconds, DWORD dwWakeMask);

    BOOL WINAPI GetHandleName(HANDLE h,char szName[1001]); 

    VOID WINAPI Sleep(DWORD dwMilliseconds);

    void WINAPI OutputDebugStringA(LPCSTR lpOutputString);

    void WINAPI OutputDebugStringW(LPCWSTR lpOutputString);

#ifdef _UNICODE
#define OutputDebugString OutputDebugStringW
#else
#define OutputDebugString OutputDebugStringA
#endif

#define EqualMemory(Destination, Source, Length) (!memcmp((Destination), (Source), (Length)))
#define MoveMemory(Destination, Source, Length)  memmove((Destination), (Source), (Length))
#define CopyMemory(Destination, Source, Length)  memcpy((Destination), (Source), (Length))
#define FillMemory(Destination, Length, Fill)    memset((Destination), (Fill), (Length))
#define ZeroMemory(Destination, Length)          memset((Destination), 0, (Length))

    void WINAPI set_error(int e);

#define SECTION_QUERY                0x0001
#define SECTION_MAP_WRITE            0x0002
#define SECTION_MAP_READ             0x0004
#define SECTION_MAP_EXECUTE          0x0008
#define SECTION_EXTEND_SIZE          0x0010
#define SECTION_MAP_EXECUTE_EXPLICIT 0x0020 // not included in SECTION_ALL_ACCESS

#define SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SECTION_QUERY | SECTION_MAP_WRITE | SECTION_MAP_READ | SECTION_MAP_EXECUTE | SECTION_EXTEND_SIZE)

#define FILE_MAP_WRITE      SECTION_MAP_WRITE
#define FILE_MAP_READ       SECTION_MAP_READ
#define FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS

#define FILE_MAP_EXECUTE SECTION_MAP_EXECUTE_EXPLICIT // not included in FILE_MAP_ALL_ACCESS

#define FILE_MAP_COPY 0x00000001

#define FILE_MAP_RESERVE         0x80000000
#define FILE_MAP_TARGETS_INVALID 0x40000000
#define FILE_MAP_LARGE_PAGES     0x20000000

#define PAGE_NOACCESS          0x01
#define PAGE_READONLY          0x02
#define PAGE_READWRITE         0x04
#define PAGE_WRITECOPY         0x08
#define PAGE_EXECUTE           0x10
#define PAGE_EXECUTE_READ      0x20
#define PAGE_EXECUTE_READWRITE 0x40
#define PAGE_EXECUTE_WRITECOPY 0x80
#define PAGE_GUARD             0x100
#define PAGE_NOCACHE           0x200
#define PAGE_WRITECOMBINE      0x400

    HANDLE WINAPI OpenFileMappingA(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCSTR lpName);

    HANDLE WINAPI OpenFileMappingW(DWORD dwDesiredAccess, BOOL bInheritHandle, LPCWSTR lpName);

    HANDLE WINAPI CreateFileMappingA(HANDLE hFile, LPSECURITY_ATTRIBUTES lpAttributes, DWORD flProtect, DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, LPCSTR lpName);

    HANDLE WINAPI CreateFileMappingW(HANDLE hFile, LPSECURITY_ATTRIBUTES lpAttributes, DWORD flProtect, DWORD dwMaximumSizeHigh, DWORD dwMaximumSizeLow, LPCWSTR lpName);

    LPVOID WINAPI MapViewOfFile(HANDLE hFileMappingObject, DWORD dwDesiredAccess, DWORD dwFileOffsetHigh, DWORD dwFileOffsetLow, size_t dwNumberOfBytesToMap);

    BOOL WINAPI UnmapViewOfFile(LPCVOID lpBaseAddress);

#ifdef UNICODE
#define OpenFileMapping   OpenFileMappingW
#define CreateFileMapping CreateFileMappingW
#else
#define OpenFileMapping   OpenFileMappingA
#define CreateFileMapping CreateFileMappingA
#endif // UNICODE

    BOOL WINAPI GetKeyboardState(PBYTE lpKeyState);

    SHORT WINAPI GetKeyState(int nVirtKey);
    SHORT WINAPI GetAsyncKeyState(int vKey);

    UINT WINAPI MapVirtualKey(UINT uCode, UINT uMapType);

    UINT WINAPI MapVirtualKeyEx(UINT uCode, UINT uMapType, HKL dwhkl);

    LONG WINAPI CompareFileTime(const FILETIME *ft1, const FILETIME *ft2);

    BOOL WINAPI SystemParametersInfoA(UINT action, UINT val, void *ptr, UINT winini);
    BOOL WINAPI SystemParametersInfoW(UINT action, UINT val, void *ptr, UINT winini);
#ifdef UNICODE
#define SystemParametersInfo SystemParametersInfoW
#else
#define SystemParametersInfo SystemParametersInfoA
#endif // UNICODE

    void WINAPI DebugBreak(void);
    VOID WINAPI DbgBreakPoint(VOID);

    UINT WINAPI GetDoubleClickTime(VOID);
    BOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency);
    BOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount);

#ifndef NOCLIPBOARD

/*
 * Clipboard Manager Functions
 */
#define WINUSERAPI

    WINUSERAPI
    BOOL WINAPI OpenClipboard(_In_opt_ HWND hWndNewOwner);

    WINUSERAPI
    BOOL WINAPI CloseClipboard(VOID);

#if (WINVER >= 0x0500)

    WINUSERAPI
    DWORD
    WINAPI
    GetClipboardSequenceNumber(VOID);

#endif /* WINVER >= 0x0500 */

    WINUSERAPI
    HWND WINAPI GetClipboardOwner(VOID);

    WINUSERAPI
    HWND WINAPI SetClipboardViewer(_In_ HWND hWndNewViewer);

    WINUSERAPI
    HWND WINAPI GetClipboardViewer(VOID);

    WINUSERAPI
    BOOL WINAPI ChangeClipboardChain(_In_ HWND hWndRemove, _In_ HWND hWndNewNext);

    WINUSERAPI
    HANDLE
    WINAPI
    SetClipboardData(_In_ UINT uFormat, _In_opt_ HANDLE hMem);

    WINUSERAPI
    HANDLE
    WINAPI
    GetClipboardData(_In_ UINT uFormat);

    WINUSERAPI
    UINT WINAPI RegisterClipboardFormatA(_In_ LPCSTR lpszFormat);
    WINUSERAPI
    UINT WINAPI RegisterClipboardFormatW(_In_ LPCWSTR lpszFormat);
#ifdef UNICODE
#define RegisterClipboardFormat RegisterClipboardFormatW
#else
#define RegisterClipboardFormat RegisterClipboardFormatA
#endif // !UNICODE

    WINUSERAPI
    int WINAPI CountClipboardFormats(VOID);

    WINUSERAPI
    UINT WINAPI EnumClipboardFormats(_In_ UINT format);

    WINUSERAPI
    int WINAPI GetClipboardFormatNameA(_In_ UINT format, _Out_writes_(cchMaxCount) LPSTR lpszFormatName, _In_ int cchMaxCount);
    WINUSERAPI
    int WINAPI GetClipboardFormatNameW(_In_ UINT format, _Out_writes_(cchMaxCount) LPWSTR lpszFormatName, _In_ int cchMaxCount);
#ifdef UNICODE
#define GetClipboardFormatName GetClipboardFormatNameW
#else
#define GetClipboardFormatName GetClipboardFormatNameA
#endif // !UNICODE

    WINUSERAPI
    BOOL WINAPI EmptyClipboard(VOID);

    WINUSERAPI
    BOOL WINAPI IsClipboardFormatAvailable(_In_ UINT format);

    WINUSERAPI
    int WINAPI GetPriorityClipboardFormat(_In_reads_(cFormats) UINT *paFormatPriorityList, _In_ int cFormats);

    WINUSERAPI
    HWND WINAPI GetOpenClipboardWindow(VOID);

#endif /* !NOCLIPBOARD */

    DWORD
    WINAPI
    GetTempPathA(_In_ DWORD nBufferLength, _Out_writes_to_opt_(nBufferLength, return +1) LPSTR lpBuffer);

    DWORD
    WINAPI
    GetTempPathW(_In_ DWORD nBufferLength, _Out_writes_to_opt_(nBufferLength, return +1) LPWSTR lpBuffer);

#ifdef UNICODE
#define GetTempPath GetTempPathW
#else
#define GetTempPath GetTempPathA
#endif

    BOOL WINAPI IsValidCodePage(UINT CodePage);

    UINT WINAPI GetKeyboardLayoutList(int nBuff, HKL *lpList);

    HKL WINAPI ActivateKeyboardLayout(HKL hkl, UINT Flags);

    UINT WINAPI GetACP(void);

    BOOL WINAPI IsDBCSLeadByte(BYTE c);

    HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
    HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);

    BOOL WINAPI SetEnvironmentVariableA(LPCSTR lpName, LPCSTR lpValue);
    BOOL WINAPI SetEnvironmentVariableW(LPCWSTR lpName, LPCWSTR lpValue);

    DWORD WINAPI GetEnvironmentVariableA(LPCSTR lpName, LPSTR lpBuffer, DWORD nSize);
    DWORD WINAPI GetEnvironmentVariableW(LPCWSTR lpName, LPWSTR lpBuffer, DWORD nSize);

#ifdef UNICODE
#define SetEnvironmentVariable SetEnvironmentVariableW
#define GetEnvironmentVariable GetEnvironmentVariableW
#define GetModuleHandle        GetModuleHandleW
#else
#define SetEnvironmentVariable SetEnvironmentVariableA
#define GetEnvironmentVariable GetEnvironmentVariableA
#define GetModuleHandle        GetModuleHandleA
#endif // UNICODE

    HANDLE WINAPI _get_osfhandle(int fd);

    LPSTR WINAPI GetCommandLineA(void);
    LPWSTR WINAPI GetCommandLineW(void);

    #ifdef UNICODE
    #define GetCommandLine GetCommandLineW
    #else
    #define GetCommandLine GetCommandLineA
    #endif // UNICODE

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //_SYSAPI_H_