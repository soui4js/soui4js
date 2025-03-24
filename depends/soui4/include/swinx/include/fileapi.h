#include <windows.h>
#ifndef _FILE_API_H_
#define _FILE_API_H_

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#define DELETE       (0x00010000L)
#define READ_CONTROL (0x00020000L)
#define WRITE_DAC    (0x00040000L)
#define WRITE_OWNER  (0x00080000L)
#define SYNCHRONIZE  (0x00100000L)

#define STANDARD_RIGHTS_REQUIRED (0x000F0000L)

#define STANDARD_RIGHTS_READ    (READ_CONTROL)
#define STANDARD_RIGHTS_WRITE   (READ_CONTROL)
#define STANDARD_RIGHTS_EXECUTE (READ_CONTROL)

#define STANDARD_RIGHTS_ALL (0x001F0000L)

#define SPECIFIC_RIGHTS_ALL (0x0000FFFFL)

#define FILE_READ_DATA      (0x0001) // file & pipe
#define FILE_LIST_DIRECTORY (0x0001) // directory

#define FILE_WRITE_DATA (0x0002) // file & pipe
#define FILE_ADD_FILE   (0x0002) // directory

#define FILE_APPEND_DATA          (0x0004) // file
#define FILE_ADD_SUBDIRECTORY     (0x0004) // directory
#define FILE_CREATE_PIPE_INSTANCE (0x0004) // named pipe

#define FILE_READ_EA (0x0008) // file & directory

#define FILE_WRITE_EA (0x0010) // file & directory

#define FILE_EXECUTE  (0x0020) // file
#define FILE_TRAVERSE (0x0020) // directory

#define FILE_DELETE_CHILD (0x0040) // directory

#define FILE_READ_ATTRIBUTES (0x0080) // all

#define FILE_WRITE_ATTRIBUTES (0x0100) // all

#define FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)

#define FILE_GENERIC_READ (STANDARD_RIGHTS_READ | FILE_READ_DATA | FILE_READ_ATTRIBUTES | FILE_READ_EA | SYNCHRONIZE)

#define GENERIC_READ FILE_GENERIC_READ

#define FILE_GENERIC_WRITE (STANDARD_RIGHTS_WRITE | FILE_WRITE_DATA | FILE_WRITE_ATTRIBUTES | FILE_WRITE_EA | FILE_APPEND_DATA | SYNCHRONIZE)

#define GENERIC_WRITE        FILE_GENERIC_WRITE
#define FILE_GENERIC_EXECUTE (STANDARD_RIGHTS_EXECUTE | FILE_READ_ATTRIBUTES | FILE_EXECUTE | SYNCHRONIZE)
#define GENERIC_EXECUTE      FILE_GENERIC_EXECUTE
// end_access
#define FILE_SHARE_READ   0x00000001
#define FILE_SHARE_WRITE  0x00000002
#define FILE_SHARE_DELETE 0x00000004

//
// Constants
//
#define CREATE_NEW        1
#define CREATE_ALWAYS     2
#define OPEN_EXISTING     3
#define OPEN_ALWAYS       4
#define TRUNCATE_EXISTING 5

#define FILE_FLAG_WRITE_THROUGH       0x80000000
#define FILE_FLAG_OVERLAPPED          0x40000000
#define FILE_FLAG_NO_BUFFERING        0x20000000
#define FILE_FLAG_RANDOM_ACCESS       0x10000000
#define FILE_FLAG_SEQUENTIAL_SCAN     0x08000000
#define FILE_FLAG_DELETE_ON_CLOSE     0x04000000
#define FILE_FLAG_BACKUP_SEMANTICS    0x02000000
#define FILE_FLAG_POSIX_SEMANTICS     0x01000000
#define FILE_FLAG_SESSION_AWARE       0x00800000
#define FILE_FLAG_OPEN_REPARSE_POINT  0x00200000
#define FILE_FLAG_OPEN_NO_RECALL      0x00100000
#define FILE_FLAG_FIRST_PIPE_INSTANCE 0x00080000

    HANDLE
    WINAPI
    CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);

    HANDLE WINAPI CreateFileW(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);

    int WINAPI _open_osfhandle(HANDLE hFile,int flags );
#ifdef UNICODE
#define CreateFile CreateFileW
#else
#define CreateFile CreateFileA
#endif // !UNICODE

    BOOL WINAPI GetFileSizeEx(HANDLE hFile, PLARGE_INTEGER lpFileSize);

    DWORD WINAPI GetFileSize(HANDLE hFile, LPDWORD lpFileSizeHigh);

    BOOL WINAPI GetFileTime(HANDLE hFile, LPFILETIME lpCreationTime, LPFILETIME lpLastAccessTime, LPFILETIME lpLastWriteTime);

    typedef struct _OVERLAPPED
    {
        ULONG_PTR Internal;
        ULONG_PTR InternalHigh;
        union {
            struct
            {
                DWORD Offset;
                DWORD OffsetHigh;
            } DUMMYSTRUCTNAME;
            PVOID Pointer;
        } DUMMYUNIONNAME;

        HANDLE hEvent;
    } OVERLAPPED, *LPOVERLAPPED;

    typedef struct _OVERLAPPED_ENTRY
    {
        ULONG_PTR lpCompletionKey;
        LPOVERLAPPED lpOverlapped;
        ULONG_PTR Internal;
        DWORD dwNumberOfBytesTransferred;
    } OVERLAPPED_ENTRY, *LPOVERLAPPED_ENTRY;

    BOOL WINAPI ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);

    BOOL WINAPI WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);

    DWORD WINAPI SetFilePointer(HANDLE file, LONG distance, LONG *highword, DWORD method);
    BOOL WINAPI SetFilePointerEx(
            HANDLE hFile,
            LARGE_INTEGER liDistanceToMove,
            PLARGE_INTEGER lpNewFilePointer,
            DWORD dwMoveMethod
    );

    BOOL WINAPI SetEndOfFile(HANDLE file);
    BOOL WINAPI DosDateTimeToFileTime(WORD fatdate, WORD fattime, FILETIME *ft);
    BOOL WINAPI FileTimeToDosDateTime(const FILETIME *ft, WORD *fatdate, WORD *fattime);

    DWORD WINAPI GetFileAttributesA(LPCSTR lpFileName);
    DWORD WINAPI GetFileAttributesW(LPCWSTR lpFileName);

#ifdef UNICODE
#define GetFileAttribute GetFileAttributesW
#else
#define GetFileAttributes GetFileAttributesA
#endif // UNICODE

    UINT WINAPI GetProfileIntA(LPCSTR section, LPCSTR entry, INT def_val);
    UINT WINAPI GetProfileIntW(LPCWSTR section, LPCWSTR entry, INT def_val);
    INT WINAPI GetPrivateProfileStringW(LPCWSTR section, LPCWSTR entry, LPCWSTR def_val, LPWSTR buffer, UINT len, LPCWSTR filename);
    INT WINAPI GetPrivateProfileStringA(LPCSTR section, LPCSTR entry, LPCSTR def_val, LPSTR buffer, UINT len, LPCSTR filename);
    INT WINAPI GetProfileStringA(LPCSTR section, LPCSTR entry, LPCSTR def_val, LPSTR buffer, UINT len);
    INT WINAPI GetProfileStringW(LPCWSTR section, LPCWSTR entry, LPCWSTR def_val, LPWSTR buffer, UINT len);
    BOOL WINAPI WriteProfileStringA(LPCSTR section, LPCSTR entry, LPCSTR string);
    BOOL WINAPI WriteProfileStringW(LPCWSTR section, LPCWSTR entry, LPCWSTR string);
    UINT WINAPI GetPrivateProfileIntW(LPCWSTR section, LPCWSTR entry, INT def_val, LPCWSTR filename);

    UINT WINAPI GetPrivateProfileIntA(LPCSTR section, LPCSTR entry, INT def_val, LPCSTR filename);

    INT WINAPI GetPrivateProfileSectionW(LPCWSTR section, LPWSTR buffer, DWORD len, LPCWSTR filename);
    INT WINAPI GetPrivateProfileSectionA(LPCSTR section, LPSTR buffer, DWORD len, LPCSTR filename);
    INT WINAPI GetProfileSectionA(LPCSTR section, LPSTR buffer, DWORD len);
    INT WINAPI GetProfileSectionW(LPCWSTR section, LPWSTR buffer, DWORD len);
    BOOL WINAPI WritePrivateProfileStringW(LPCWSTR section, LPCWSTR entry, LPCWSTR string, LPCWSTR filename);
    BOOL WINAPI WritePrivateProfileStringA(LPCSTR section, LPCSTR entry, LPCSTR string, LPCSTR filename);
    BOOL WINAPI WritePrivateProfileSectionW(LPCWSTR section, LPCWSTR string, LPCWSTR filename);
    DWORD WINAPI GetPrivateProfileSectionNamesW(LPWSTR buffer, DWORD size, LPCWSTR filename);
    DWORD WINAPI GetPrivateProfileSectionNamesA(LPSTR buffer, DWORD size, LPCSTR filename);
    BOOL WINAPI GetPrivateProfileStructW(LPCWSTR section, LPCWSTR key, LPVOID buf, UINT len, LPCWSTR filename);
    BOOL WINAPI GetPrivateProfileStructA(LPCSTR section, LPCSTR key, LPVOID buffer, UINT len, LPCSTR filename);
    BOOL WINAPI WritePrivateProfileStructW(LPCWSTR section, LPCWSTR key, LPVOID buf, UINT bufsize, LPCWSTR filename);
    BOOL WINAPI WritePrivateProfileStructA(LPCSTR section, LPCSTR key, LPVOID buf, UINT bufsize, LPCSTR filename);

    BOOL WINAPI SetCurrentDirectoryA(LPCSTR lpPathName);
    BOOL WINAPI SetCurrentDirectoryW(LPCWSTR lpPathName);
    DWORD WINAPI GetCurrentDirectoryA(DWORD nBufferLength, LPSTR lpBuffer);

    DWORD WINAPI GetCurrentDirectoryW(DWORD nBufferLength, LPWSTR lpBuffer);

#ifdef UNICODE
#define SetCurrentDirectory SetCurrentDirectoryW
#define GetCurrentDirectory GetCurrentDirectoryW
#else
#define SetCurrentDirectory SetCurrentDirectoryA
#define GetCurrentDirectory GetCurrentDirectoryA
#endif // UNICODE

    BOOL WINAPI CreateDirectoryA(LPCSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);

    BOOL WINAPI CreateDirectoryW(LPCWSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);

#ifdef UNICODE
#define CreateDirectory CreateDirectoryW
#else
#define CreateDirectory CreateDirectoryA
#endif // !UNICODE

    typedef struct _WIN32_FIND_DATAA
    {
        DWORD dwFileAttributes;
        FILETIME ftCreationTime;
        FILETIME ftLastAccessTime;
        FILETIME ftLastWriteTime;
        DWORD nFileSizeHigh;
        DWORD nFileSizeLow;
        DWORD dwReserved0;
        DWORD dwReserved1;
        CHAR cFileName[MAX_PATH];
        CHAR cAlternateFileName[14];
#ifdef _MAC
        DWORD dwFileType;
        DWORD dwCreatorType;
        WORD wFinderFlags;
#endif
    } WIN32_FIND_DATAA, *PWIN32_FIND_DATAA, *LPWIN32_FIND_DATAA;
    typedef struct _WIN32_FIND_DATAW
    {
        DWORD dwFileAttributes;
        FILETIME ftCreationTime;
        FILETIME ftLastAccessTime;
        FILETIME ftLastWriteTime;
        DWORD nFileSizeHigh;
        DWORD nFileSizeLow;
        DWORD dwReserved0;
        DWORD dwReserved1;
        WCHAR cFileName[MAX_PATH];
        WCHAR cAlternateFileName[14];
#ifdef _MAC
        DWORD dwFileType;
        DWORD dwCreatorType;
        WORD wFinderFlags;
#endif
    } WIN32_FIND_DATAW, *PWIN32_FIND_DATAW, *LPWIN32_FIND_DATAW;
#ifdef UNICODE
    typedef WIN32_FIND_DATAW WIN32_FIND_DATA;
    typedef PWIN32_FIND_DATAW PWIN32_FIND_DATA;
    typedef LPWIN32_FIND_DATAW LPWIN32_FIND_DATA;
#else
typedef WIN32_FIND_DATAA WIN32_FIND_DATA;
typedef PWIN32_FIND_DATAA PWIN32_FIND_DATA;
typedef LPWIN32_FIND_DATAA LPWIN32_FIND_DATA;
#endif // UNICODE

    typedef enum _FINDEX_INFO_LEVELS
    {
        FindExInfoStandard,
        FindExInfoBasic,
        FindExInfoMaxInfoLevel
    } FINDEX_INFO_LEVELS;

#define FIND_FIRST_EX_CASE_SENSITIVE 1
#define FIND_FIRST_EX_LARGE_FETCH    2

    typedef enum _FINDEX_SEARCH_OPS
    {
        FindExSearchNameMatch,
        FindExSearchLimitToDirectories,
        FindExSearchLimitToDevices,
        FindExSearchMaxSearchOp
    } FINDEX_SEARCH_OPS;

    HANDLE
    WINAPI
    FindFirstFileA(_In_ LPCSTR lpFileName, _Out_ LPWIN32_FIND_DATAA lpFindFileData);

    HANDLE
    WINAPI
    FindFirstFileW(_In_ LPCWSTR lpFileName, _Out_ LPWIN32_FIND_DATAW lpFindFileData);

#ifdef UNICODE
#define FindFirstFile FindFirstFileW
#else
#define FindFirstFile FindFirstFileA
#endif // !UNICODE

    BOOL WINAPI FindNextFileA(_In_ HANDLE hFindFile, _Out_ LPWIN32_FIND_DATAA lpFindFileData);

    BOOL WINAPI FindNextFileW(_In_ HANDLE hFindFile, _Out_ LPWIN32_FIND_DATAW lpFindFileData);

    HANDLE WINAPI FindFirstFileExA(const char *filename, FINDEX_INFO_LEVELS level, void *data, FINDEX_SEARCH_OPS search_op, void *filter, DWORD flags);

    HANDLE WINAPI FindFirstFileExW(const wchar_t *filename, FINDEX_INFO_LEVELS level, void *data, FINDEX_SEARCH_OPS search_op, void *filter, DWORD flags);

#ifdef UNICODE
#define FindNextFile FindNextFileW
#else
#define FindNextFile FindNextFileA
#endif // !UNICODE

    BOOL WINAPI FindClose(HANDLE hFindFile);

    BOOL WINAPI CopyFileW(
        LPCWSTR lpExistingFileName,
        LPCWSTR lpNewFileName,
        BOOL bFailIfExists
    );

    BOOL WINAPI CopyFileA(
        LPCSTR lpExistingFileName,
        LPCSTR lpNewFileName,
        BOOL bFailIfExists
    );

    int WINAPI CopyDirA(const char *src_dir, const char *dest_dir);
    int WINAPI CopyDirW(const wchar_t *src_dir, const wchar_t *dest_dir);

    BOOL WINAPI DeleteFileA(
      LPCSTR lpFileName
    );

    BOOL WINAPI DeleteFileW(
        LPCWSTR lpFileName
    );

    int WINAPI DelDirA(const char *src_dir, BOOL bAllowUndo);
    int WINAPI DelDirW(const wchar_t *src_dir, BOOL bAllowUndo);

#ifdef UNICODE
#define CopyFile CopyFileW
#define CopyDir CopyDirW
#define DeleteFile DeleteFileW
#define DelDir DelDirW
#else
#define CopyFile CopyFileA
#define CopyDir CopyDirA
#define DeleteFile DeleteFileA
#define DelDir DelDirA
#endif // !UNICODE

#ifdef __cplusplus
}
#endif //__cplusplus

#endif // _FILE_API_H_