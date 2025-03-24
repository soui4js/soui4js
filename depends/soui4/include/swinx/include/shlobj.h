#ifndef __SHELL_OBJ_H__
#define __SHELL_OBJ_H__
#include <windows.h>
#include <shellapi.h>

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

    HRESULT WINAPI SHCreateStdEnumFmtEtc(_In_ UINT cfmt, _In_reads_(cfmt) const FORMATETC afmt[], _Outptr_ IEnumFORMATETC **ppenumFormatEtc);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__SHELL_OBJ_H__
