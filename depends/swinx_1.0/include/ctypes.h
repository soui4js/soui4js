#ifndef __PLATFORM_LINUX_
#define __PLATFORM_LINUX_
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <limits.h>
#include <time.h>
#undef NULL
#define NULL 0

#define _I8_MIN  (-127 - 1)
#define _I8_MAX  127
#define _UI8_MAX 0xffU

#define _I16_MIN  (-32767 - 1)
#define _I16_MAX  32767
#define _UI16_MAX 0xffffU

#define _I32_MIN  (-2147483647 - 1)
#define _I32_MAX  2147483647
#define _UI32_MAX 0xffffffffU

#define _I64_MIN  (-9223372036854775807L - 1)
#define _I64_MAX  9223372036854775807L
#define _UI64_MAX 0xffffffffffffffffU

#define FAR
#define NEAR
#define CONST const

#define _Outptr_
#define _Out_writes_bytes_to_(p1, p2)
#define _Out_writes_bytes_(p)
#define _Out_writes_opt_(cch)
#define _Out_opt_
#define _In_reads_bytes_(x)
#define _In_
#define _In_opt_
#define _Post_writable_byte_size_(x)
#define _Out_
#define _Inout_
#define _Out_writes_(x)
#define _In_reads_(x)
#define _Null_
#define IN
#define OUT
#define __out_bcount_opt(x)
#define _In_reads_bytes_opt_(x)
#define _Out_writes_to_opt_(x, y)
#define __RPC__deref_opt_inout_opt

#define __RPC__deref_out

#ifndef _INTPTR_T
#ifndef __intptr_t_defined
typedef __INTPTR_TYPE__ intptr_t;
#define __intptr_t_defined
#define _INTPTR_T
#endif
#endif

#ifndef _UINTPTR_T
#ifndef __UINTPTR_TYPE__
typedef __UINTPTR_TYPE__ uintptr_t;
#endif
#define _UINTPTR_T
#endif

typedef unsigned int UINT;
#ifndef DEFINED_INT64
#define DEFINED_INT64
typedef int64_t __int64;
#endif // DEFINED_INT64

typedef uint32_t ULONG;
typedef uint8_t BYTE;
typedef uint8_t byte;
typedef BYTE *LPBYTE;
typedef uint32_t DWORD;
typedef uint16_t WORD;
typedef int32_t LONG;
typedef int64_t LONGLONG;
typedef uint64_t ULONGLONG;
typedef int32_t INT;
typedef wchar_t WCHAR;
typedef void *LPVOID;
typedef intptr_t INT_PTR;
typedef intptr_t LONG_PTR;
typedef uintptr_t UINT_PTR;
typedef intptr_t LONG_PTR;
typedef uintptr_t UINT_PTR;
typedef uintptr_t ULONG_PTR;
typedef intptr_t DWORD_PTR;
typedef LONG_PTR LRESULT;
typedef LONG HRESULT;
typedef UINT_PTR WPARAM;
typedef LONG_PTR LPARAM;
typedef uint16_t USHORT;
typedef uint64_t ULONG64;
typedef uint64_t UINT64;
typedef int64_t INT64;
typedef void VOID;
typedef void *LPVOID;
typedef void *PVOID;
typedef char CHAR;
typedef uint8_t UCHAR;
typedef DWORD_PTR *PDWORD_PTR;
typedef int BOOL;
typedef float FLOAT;
typedef FLOAT *PFLOAT;
typedef double DOUBLE;
typedef BOOL *PBOOL;
typedef BOOL *LPBOOL;
typedef BYTE *PBYTE;
typedef BYTE *LPBYTE;
typedef int *PINT;
typedef int *LPINT;
typedef WORD *PWORD;
typedef WORD *LPWORD;
typedef LONG *LPLONG;
typedef DWORD *PDWORD;
typedef DWORD *LPDWORD;
typedef void *LPVOID;
typedef CONST void *LPCVOID;

typedef WORD LCID;    // todo:hjx
typedef DWORD HACCEL; // todo:hjx
typedef DWORD HKEY;   // todo:hjx

typedef int INT;
typedef unsigned int UINT;
typedef unsigned int *PUINT;

typedef int64_t __time64_t;

typedef struct _SYSTEMTIME
{
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME;

#define RGB(r, g, b)     ((r) | (g) << 8 | (b) << 16) | (0xffu << 24)
#define RGBA(r, g, b, a) ((r) | (g) << 8 | (b) << 16 | ((uint32_t)a) << 24)
#define GetRValue(rgb)   (LOBYTE(rgb))
#define GetGValue(rgb)   (LOBYTE(rgb >> 8))
#define GetBValue(rgb)   (LOBYTE(rgb >> 16))
#define GetAValue(rgb)   (LOBYTE(rgb >> 24))

typedef int BOOL;
#define FALSE 0
#define TRUE  1

#define MINCHAR     0x80
#define MAXCHAR     0x7f
#define MINSHORT    0x8000
#define MAXSHORT    0x7fff
#define MINLONG     0x80000000
#define MAXLONG     0x7fffffff
#define MAXBYTE     0xff
#define MAXWORD     0xffff
#define MAXDWORD    0xffffffff
#define MAXLONGLONG (((LONGLONG)0x7fffffff << 32) | 0xffffffff)

#define UNICODE_STRING_MAX_CHARS 32767

#define IDOK       1
#define IDCANCEL   2
#define IDABORT    3
#define IDRETRY    4
#define IDIGNORE   5
#define IDYES      6
#define IDNO       7
#define IDCLOSE    8
#define IDHELP     9
#define IDTRYAGAIN 10
#define IDCONTINUE 11

#define IDOK       1
#define IDCANCEL   2
#define IDABORT    3
#define IDRETRY    4
#define IDIGNORE   5
#define IDYES      6
#define IDNO       7
#define IDCLOSE    8
#define IDHELP     9
#define IDTRYAGAIN 10
#define IDCONTINUE 11

typedef void *HINSTANCE;
typedef void *HMODULE;

typedef UINT_PTR HWND;
typedef struct _Handle *HGDIOBJ;
typedef struct _IMContext * HIMC; 

typedef HGDIOBJ HPEN;
typedef HGDIOBJ HFONT;
typedef HGDIOBJ HBRUSH;
typedef HGDIOBJ HBITMAP;
typedef HGDIOBJ HRGN;
typedef HGDIOBJ HPALETTE;
typedef HGDIOBJ HMETAFILE;

typedef struct _IconObj *HICON;

typedef UINT_PTR tid_t;
typedef struct _SDC *HDC;
typedef int HRSRC;
typedef DWORD HKL;

typedef struct _IconObj *HCURSOR;

typedef struct _Handle *HANDLE;

typedef HWND HMENU;

#define ATOM int
typedef HANDLE HMONITOR;

typedef char *PSTR;
typedef FAR char *LPSTR;
typedef wchar_t *PWSTR;
typedef wchar_t *PWCHAR;
typedef FAR wchar_t *LPWSTR;
typedef const char *LPCSTR;
typedef const wchar_t *LPCWSTR, *PCWSTR;
typedef size_t SIZE_T;

#ifndef _LANGID_DEFINED
#define _LANGID_DEFINED
typedef USHORT LANGID;
#endif // !_LANGID_DEFINED

#ifdef UNICODE
#define __TEXT(quote) L##quote
#else /* UNICODE */
#define __TEXT(quote) quote
#endif /* UNICODE */
#define TEXT(quote) __TEXT(quote)

#define __cdecl   //__attribute__((cdecl))
#define __stdcall //__attribute__((stdcall))
#define PASCAL         __stdcall
#define WINAPI         __stdcall
#define CALLBACK       __stdcall
#define STDAPI         HRESULT __stdcall
#define STDAPICALLTYPE __stdcall

#define ARRAYSIZE(x) (sizeof((x)) / sizeof((x)[0]))

#define UNREFERENCED_PARAMETER(x)

typedef DWORD COLORREF;
typedef DWORD *LPCOLORREF;
typedef int16_t SHORT;

#define HFILE_ERROR ((HFILE)-1)

typedef struct tagRECT
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT, *PRECT, *NPRECT, *LPRECT;

typedef const RECT *LPCRECT;

typedef struct _RECTL /* rcl */
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECTL, *PRECTL, *LPRECTL;

typedef const RECTL *LPCRECTL;

typedef struct tagPOINT
{
    LONG x;
    LONG y;
} POINT, *PPOINT, *NPPOINT, *LPPOINT;

typedef struct _POINTL /* ptl  */
{
    LONG x;
    LONG y;
} POINTL, *PPOINTL;

typedef struct tagSIZE
{
    LONG cx;
    LONG cy;
} SIZE, *PSIZE, *LPSIZE;

typedef SIZE SIZEL;
typedef SIZE *PSIZEL, *LPSIZEL;

typedef struct tagPOINTS
{
#ifndef _MAC
    SHORT x;
    SHORT y;
#else
    SHORT y;
    SHORT x;
#endif
} POINTS, *PPOINTS, *LPPOINTS;

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif

#define INFINITE (UINT) - 1

typedef struct tagMSG
{
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
} MSG;

typedef struct tagMSG *PMSG;
typedef struct tagMSG *LPMSG;

#define AC_SRC_OVER 0x00

//
// alpha format flags
//

#define AC_SRC_ALPHA 0x01
typedef struct _BLENDFUNCTION
{
    BYTE BlendOp;
    BYTE BlendFlags;
    BYTE SourceConstantAlpha;
    BYTE AlphaFormat;
} BLENDFUNCTION, *PBLENDFUNCTION, *LPBLENDFUNCTION;

/* Pen Styles */
#define PS_SOLID       0
#define PS_DASH        1 /* -------  */
#define PS_DOT         2 /* .......  */
#define PS_DASHDOT     3 /* _._._._  */
#define PS_DASHDOTDOT  4 /* _.._.._  */
#define PS_NULL        5
#define PS_INSIDEFRAME 6
#define PS_USERSTYLE   7
#define PS_ALTERNATE   8
#define PS_STYLE_MASK  0x0000000F

#define PS_ENDCAP_ROUND  0x00000000
#define PS_ENDCAP_SQUARE 0x00000100
#define PS_ENDCAP_FLAT   0x00000200
#define PS_ENDCAP_MASK   0x00000F00

#define PS_JOIN_ROUND 0x00000000
#define PS_JOIN_BEVEL 0x00001000
#define PS_JOIN_MITER 0x00002000
#define PS_JOIN_MASK  0x0000F000

#define PS_COSMETIC  0x00000000
#define PS_GEOMETRIC 0x00010000
#define PS_TYPE_MASK 0x000F0000

#define AD_COUNTERCLOCKWISE 1
#define AD_CLOCKWISE        2

typedef HANDLE HGLOBAL;
typedef HANDLE HLOCAL;
typedef HANDLE HDROP;

typedef struct _FILETIME
{
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME, *PFILETIME, *LPFILETIME;

typedef wchar_t OLECHAR;
typedef OLECHAR **SNB;
typedef /* [string] */ OLECHAR *LPOLESTR;
typedef /* [string] */ const OLECHAR *LPCOLESTR;
#define OLESTR(str) L##str

typedef /* [wire_marshal] */ OLECHAR *BSTR;
typedef BSTR *LPBSTR;

#define FILE_ATTRIBUTE_READONLY            0x00000001
#define FILE_ATTRIBUTE_HIDDEN              0x00000002
#define FILE_ATTRIBUTE_SYSTEM              0x00000004
#define FILE_ATTRIBUTE_DIRECTORY           0x00000010
#define FILE_ATTRIBUTE_ARCHIVE             0x00000020
#define FILE_ATTRIBUTE_DEVICE              0x00000040
#define FILE_ATTRIBUTE_NORMAL              0x00000080
#define FILE_ATTRIBUTE_TEMPORARY           0x00000100
#define FILE_ATTRIBUTE_SPARSE_FILE         0x00000200
#define FILE_ATTRIBUTE_REPARSE_POINT       0x00000400
#define FILE_ATTRIBUTE_COMPRESSED          0x00000800
#define FILE_ATTRIBUTE_OFFLINE             0x00001000
#define FILE_ATTRIBUTE_NOT_CONTENT_INDEXED 0x00002000
#define FILE_ATTRIBUTE_ENCRYPTED           0x00004000
#define FILE_ATTRIBUTE_INTEGRITY_STREAM    0x00008000
#define FILE_ATTRIBUTE_VIRTUAL             0x00010000
#define FILE_ATTRIBUTE_NO_SCRUB_DATA       0x00020000
#define FILE_ATTRIBUTE_EA                  0x00040000

#define INVALID_HANDLE_VALUE     ((HANDLE)(LONG_PTR)-1)
#define INVALID_FILE_SIZE        ((DWORD)0xFFFFFFFF)
#define INVALID_SET_FILE_POINTER ((DWORD)-1)
#define INVALID_FILE_ATTRIBUTES  ((DWORD)-1)

#define FILE_BEGIN   0
#define FILE_CURRENT 1
#define FILE_END     2

typedef union _LARGE_INTEGER {
    struct
    {
#ifdef WORDS_BIGENDIAN
        LONG HighPart;
        DWORD LowPart;
#else
        DWORD LowPart;
        LONG HighPart;
#endif
    } u;
#ifndef NONAMELESSSTRUCT
    struct
    {
#ifdef WORDS_BIGENDIAN
        LONG HighPart;
        DWORD LowPart;
#else
        DWORD LowPart;
        LONG HighPart;
#endif
    };
#endif
    LONGLONG QuadPart;
} LARGE_INTEGER, *PLARGE_INTEGER;

typedef union _ULARGE_INTEGER {
    struct
    {
#ifdef WORDS_BIGENDIAN
        DWORD HighPart;
        DWORD LowPart;
#else
        DWORD LowPart;
        DWORD HighPart;
#endif
    } u;
#ifndef NONAMELESSSTRUCT
    struct
    {
#ifdef WORDS_BIGENDIAN
        DWORD HighPart;
        DWORD LowPart;
#else
        DWORD LowPart;
        DWORD HighPart;
#endif
    };
#endif
    ULONGLONG QuadPart;
} ULARGE_INTEGER, *PULARGE_INTEGER;

//
// For compilers that don't support nameless unions
//
#ifndef __cplusplus
#define NONAMELESSUNION
#endif //__cplusplus
#ifndef DUMMYUNIONNAME
#ifdef NONAMELESSUNION
#define DUMMYUNIONNAME  u
#define DUMMYUNIONNAME2 u2
#define DUMMYUNIONNAME3 u3
#define DUMMYUNIONNAME4 u4
#define DUMMYUNIONNAME5 u5
#else
#define DUMMYUNIONNAME
#define DUMMYUNIONNAME2
#define DUMMYUNIONNAME3
#define DUMMYUNIONNAME4
#define DUMMYUNIONNAME5
#endif
#endif // DUMMYUNIONNAME

typedef enum tagDVASPECT
{
    DVASPECT_CONTENT = 1,
    DVASPECT_THUMBNAIL = 2,
    DVASPECT_ICON = 4,
    DVASPECT_DOCPRINT = 8
} DVASPECT;

typedef enum tagSTGC
{
    STGC_DEFAULT = 0,
    STGC_OVERWRITE = 1,
    STGC_ONLYIFCURRENT = 2,
    STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE = 4,
    STGC_CONSOLIDATE = 8
} STGC;

typedef enum tagSTGMOVE
{
    STGMOVE_MOVE = 0,
    STGMOVE_COPY = 1,
    STGMOVE_SHALLOWCOPY = 2
} STGMOVE;

typedef enum tagSTATFLAG
{
    STATFLAG_DEFAULT = 0,
    STATFLAG_NONAME = 1,
    STATFLAG_NOOPEN = 2
} STATFLAG;

typedef /* [context_handle] */ void *HCONTEXT;

#endif //__PLATFORM_LINUX_