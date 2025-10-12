#ifndef __TCHAR_H_
#define __TCHAR_H_

#include <ctypes.h>
#include <wchar.h>

#ifndef _UNICODE
#define TCHAR                char
#define LPCTSTR              LPCSTR
#define LPTSTR               LPSTR
#define _tcscpy_s(p1, n, p2) strcpy(p1, p2)
#define _tcslwr              _mbslwr
#define _tcscmp              strcmp
#define _T(x)                x
#define _tcsftime            strftime
#define _tfopen              fopen
#define _tprintf             printf
#else
#define TCHAR                wchar_t
#define LPCTSTR              LPCWSTR
#define LPTSTR               LPWSTR
#define _tcscpy_s(p1, n, p2) wcscpy(p1, p2)
#define _tcslwr              _wcslwr
#define _tcscmp              wcscmp
#define _T(x)                L##x
#define _tcsftime            wcsftime
#define _tfopen              _wfopen
#define _tprintf             wprintf
#endif

#ifdef _UNICODE
#define lstrlen   lstrlenW
#define lstrcpy   lstrcpyW
#define _tcsncmp  wcsncmp
#define _tcslen   wcslen
#define _ttoi     _wtoi
#define _tcsdup   wcsdup
#define _tcsicmp  _wcsicmp
#define _tcsnicmp _wcsnicmp
#define _tcscpy   wcscpy
inline wchar_t *_wcsstok(wchar_t *strToken, const wchar_t *strDelimit)
{
    wchar_t *saveptr = NULL;
    return wcstok(strToken, strDelimit, &saveptr);
}
#define _tcstok    _wcsstok
#define _tcsncpy   wcsncpy
#define _tcsrchr   wcsrchr
#define _tcsstr    wcsstr
#define CharNext   CharNextW
#define _stprintf  wprintf
#define lstrcpyn   lstrcpynW
#define _tcstol    wcstol
#define _stscanf   swscanf
#define _sntprintf swprintf
#define _tcschr    wcschr
#define _tcscat    wcscat
#define _tstoi     _wtoi
#define _tstof     _wtof
#define _istdigit  iswdigit
#define _istspace  iswspace
#define _istalnum  iswalnum
#define _istprint  iswprint
#define _istalpha  iswalpha
#else
#define lstrlen    lstrlenA
#define lstrcpy    lstrcpyA
#define _tcsncmp   strncmp
#define _tcslen    strlen
#define _ttoi      atoi
#define _tcsdup    strdup
#define _tcsicmp   stricmp
#define _tcsnicmp  strnicmp
#define _tcscpy    strcpy
#define _tcstok    strtok
#define _tcsncpy   strncpy
#define _tcsrchr   strrchr
#define _tcsstr    strstr
#define CharNext   CharNextA
#define _stprintf  sprintf
#define lstrcpyn   lstrcpynA
#define _tcstol    strtol
#define _stscanf   sscanf
#define _sntprintf snprintf
#define _tcschr    strchr
#define _tcscat    strcat
#define _tstoi     atoi
#define _tstof     atof
#define _istdigit  isdigit
#define _istspace  isspace
#define _istalnum  isalnum
#define _istprint  isprint
#define _istalpha  isalpha
#define _trename   rename
#endif

#endif //__TCHAR_H_