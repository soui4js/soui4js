#ifndef __STRFUN_H_
#define __STRFUN_H_
#include <stdio.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>
#include <ctypes.h>
#include <errno.h>
#include <tchar.h>

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#define _vscprintf(fmt, argList) vsnprintf(nullptr, 0, fmt, argList)
#define _snprintf                snprintf
#define vsprintf_s               vsnprintf
#define sprintf_s                snprintf
#define strcat_s(dst, n, src)    strncat(dst, src, n)
#define wcscat_s(dst, n, src)    wcsncat(dst, src, n)

    const uint8_t *_mbsinc(const uint8_t *srcU8);

    uint8_t *_mbscvt(uint8_t *srcU8, BOOL bLower);

#define _mbslwr(x) _mbscvt((uint8_t *)(x), TRUE)
#define _mbsupr(x) _mbscvt((uint8_t *)(x), FALSE)

#define _mbsstr(s1, s2) strstr((const char *)(s1), (const char *)(s2))

#define _mbschr(s1, c)                 strchr((const char *)(s1), (c))
#define _mbsrchr(s1, c)                strrchr((const char *)(s1), (c))
#define _mbsicmp(s1, s2)               strcasecmp((const char *)(s1), (const char *)(s2))
#define _mbscmp(s1, s2)                strcmp((const char *)(s1), (const char *)(s2))
#define _ismbcspace                    isspace
#define vswprintf_s                    vswprintf
#define _wtoi(x)                       wcstol(x, NULL, 10)
#define memmove_s(dst, ndst, src, len) memmove(dst, src, len)
#define swscanf_s                      swscanf
#define snwprintf                      swprintf
#define lstrlenA                       strlen
#define lstrlenW                       wcslen
#define lstrcpyA                       strcpy
#define lstrcpyW                       wcscpy
#define lstrcatA                       strcat
#define lstrcatW                       wcscat

    wchar_t *WINAPI _wcslwr(wchar_t *s);

    wchar_t *WINAPI _wcsupr(wchar_t *s);

    void WINAPI strcpy_s(char *destination, size_t num, const char *source);

    void WINAPI wcscpy_s(wchar_t *destination, size_t num, const wchar_t *source);

    float WINAPI _wtof(const wchar_t *src);

    const char *WINAPI CharNextA(const char *src);

    const wchar_t *WINAPI CharNextW(const wchar_t *src);

#define _wcsicmp(s1, s2)       wcscasecmp(s1, s2)
#define _wcsnicmp(s1, s2, num) wcsncasecmp(s1, s2, num)
#define wcsnicmp               _wcsnicmp

#define stricmp(s1, s2)       strcasecmp(s1, s2)
#define strnicmp(s1, s2, num) strncasecmp(s1, s2, num)
#define wcsicmp               _wcsicmp
#define _snwprintf            swprintf

#define lstrcpynW wcsncpy
#define lstrcpynA strncpy

#define CP_ACP        0  // default to ANSI code page
#define CP_OEMCP      1  // default to OEM  code page
#define CP_MACCP      2  // default to MAC  code page
#define CP_THREAD_ACP 3  // current thread's ANSI code page
#define CP_SYMBOL     42 // SYMBOL translations

#define CP_UTF7 65000 // UTF-7 translation
#define CP_UTF8 65001 // UTF-8 translation

#define MB_PRECOMPOSED       0x00000001 // DEPRECATED: use single precomposed characters when possible.
#define MB_COMPOSITE         0x00000002 // DEPRECATED: use multiple discrete characters when possible.
#define MB_USEGLYPHCHARS     0x00000004 // DEPRECATED: use glyph chars, not ctrl chars
#define MB_ERR_INVALID_CHARS 0x00000008 // error for invalid chars

    BOOL WINAPI CharToOemBuffA(LPCSTR lpszSrc, LPSTR lpszDst, DWORD cchDstLength);

    BOOL WINAPI CharToOemBuffW(LPCWSTR lpszSrc, LPSTR lpszDst, DWORD cchDstLength);

    BOOL WINAPI OemToCharBuffA(LPCSTR lpszSrc, LPSTR lpszDst, DWORD cchDstLength);

    BOOL WINAPI OemToCharBuffW(LPCSTR lpszSrc, LPWSTR lpszDst, DWORD cchDstLength);

    BOOL WINAPI CharToOemA(LPCSTR s, LPSTR d);
    BOOL WINAPI CharToOemW(LPCWSTR s, LPSTR d);
    BOOL WINAPI OemToCharA(LPCSTR s, LPSTR d);
    BOOL WINAPI OemToCharW(LPCSTR s, LPWSTR d);

#ifdef UNICODE
#define CharToOemBuff CharToOemBuffW
#define OemToCharBuff OemToCharBuffW
#define CharToOem     CharToOemW
#define OemToChar     OemToCharW
#else
#define CharToOemBuff CharToOemBuffA
#define OemToCharBuff OemToCharBuffA
#define CharToOem     CharToOemA
#define OemToChar     OemToCharA
#endif // !UNICODE

    BOOL WINAPI GetStringTypeExW(_In_ LCID lcid, _In_ DWORD dwInfoType, _In_reads_(nLength) LPCWSTR pszSrc, _In_ int nLength, _Out_ LPWORD pwCharType);

    BOOL WINAPI GetStringTypeExA(_In_ LCID lcid, _In_ DWORD dwInfoType, _In_reads_(nLength) LPCSTR pszSrc, _In_ int nLength, _Out_ LPWORD pwCharType);

    LPWSTR WINAPI CharLowerW(LPWSTR lpsz);
    LPSTR WINAPI CharLowerA(LPSTR lpsz);

    DWORD WINAPI CharLowerBuffW(LPWSTR lpsz, DWORD cchLength);
    DWORD WINAPI CharLowerBuffA(LPSTR lpsz, DWORD cchLength);

    DWORD WINAPI CharUpperBuffW(LPWSTR lpsz, DWORD cchLength);
    DWORD WINAPI CharUpperBuffA(LPSTR lpsz, DWORD cchLength);

#ifdef UNICODE
#define GetStringTypeEx GetStringTypeExW
#define CharLower       CharLowerW
#define CharLowerBuff   CharLowerBuffW
#define CharUpperBuff   CharUpperBuffW
#else
#define GetStringTypeEx GetStringTypeExA
#define CharLower       CharLowerA
#define CharLowerBuff   CharLowerBuffA
#define CharUpperBuff   CharUpperBuffA
#endif // UNICODE

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__STRFUN_H_
