#ifndef __OBJBASE_H_
#define __OBJBASE_H_
#include <guiddef.h>
#include <unknwn.h>
#include <objidl.h>

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

    typedef enum tagCLSCTX
    {
        CLSCTX_INPROC_SERVER = 0x1,
        CLSCTX_INPROC_HANDLER = 0x2,
        CLSCTX_LOCAL_SERVER = 0x4,
        CLSCTX_INPROC_SERVER16 = 0x8,
        CLSCTX_REMOTE_SERVER = 0x10,
        CLSCTX_INPROC_HANDLER16 = 0x20,
        CLSCTX_RESERVED1 = 0x40,
        CLSCTX_RESERVED2 = 0x80,
        CLSCTX_RESERVED3 = 0x100,
        CLSCTX_RESERVED4 = 0x200,
        CLSCTX_NO_CODE_DOWNLOAD = 0x400,
        CLSCTX_RESERVED5 = 0x800,
        CLSCTX_NO_CUSTOM_MARSHAL = 0x1000,
        CLSCTX_ENABLE_CODE_DOWNLOAD = 0x2000,
        CLSCTX_NO_FAILURE_LOG = 0x4000,
        CLSCTX_DISABLE_AAA = 0x8000,
        CLSCTX_ENABLE_AAA = 0x10000,
        CLSCTX_FROM_DEFAULT_CONTEXT = 0x20000,
        CLSCTX_ACTIVATE_32_BIT_SERVER = 0x40000,
        CLSCTX_ACTIVATE_64_BIT_SERVER = 0x80000,
        CLSCTX_ENABLE_CLOAKING = 0x100000,
        CLSCTX_PS_DLL = 0x80000000
    } CLSCTX;

#define CLSCTX_ALL    (CLSCTX_INPROC_SERVER | CLSCTX_INPROC_HANDLER | CLSCTX_LOCAL_SERVER | CLSCTX_REMOTE_SERVER)
#define CLSCTX_INPROC (CLSCTX_INPROC_SERVER | CLSCTX_INPROC_HANDLER)

#define __in
#define __out
#define __in_opt
#define __deref_out

    HRESULT WINAPI CLSIDFromProgID(__in LPCOLESTR lpszProgID, __out LPCLSID lpclsid);
    HRESULT WINAPI CoCreateInstance(__in REFCLSID rclsid, __in_opt LPUNKNOWN pUnkOuter, __in DWORD dwClsContext, __in REFIID riid, __deref_out LPVOID FAR *ppv);

    typedef enum tagMEMCTX
    {
        MEMCTX_TASK = 1,
        MEMCTX_SHARED = 2,
        MEMCTX_MACSYSTEM = 3,
        MEMCTX_UNKNOWN = -1,
        MEMCTX_SAME = -2
    } MEMCTX;

    HRESULT WINAPI CoGetMalloc(DWORD dwMemContext, LPMALLOC *lpMalloc);
    LPVOID WINAPI CoTaskMemAlloc(SIZE_T size);
    void WINAPI CoTaskMemFree(LPVOID ptr);
    LPVOID WINAPI CoTaskMemRealloc(LPVOID ptr, SIZE_T size);

    HRESULT WINAPI OleInitialize(LPVOID reserved);
    void WINAPI OleUninitialize(void);

    HRESULT WINAPI CoCreateGuid(GUID *pguid);

#undef __deref_out
#undef __in_opt
#undef __in
#undef __out

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__OBJBASE_H_