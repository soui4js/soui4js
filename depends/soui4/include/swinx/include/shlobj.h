#ifndef __SHELL_OBJ_H__
#define __SHELL_OBJ_H__
#include <windows.h>
#include <shellapi.h>
#include <unknwn.h>
#include <guiddef.h>
#ifndef __IDragSourceHelper_FWD_DEFINED__
#define __IDragSourceHelper_FWD_DEFINED__
typedef interface IDragSourceHelper IDragSourceHelper;

#endif /* __IDragSourceHelper_FWD_DEFINED__ */

#pragma pack(push, 8)
typedef struct SHDRAGIMAGE
{
    SIZE sizeDragImage;
    POINT ptOffset;
    HBITMAP hbmpDragImage;
    COLORREF crColorKey;
} SHDRAGIMAGE;

typedef struct SHDRAGIMAGE *LPSHDRAGIMAGE;
#pragma pack(pop)

#ifndef __IDragSourceHelper_INTERFACE_DEFINED__
#define __IDragSourceHelper_INTERFACE_DEFINED__

/* interface IDragSourceHelper */
/* [object][unique][local][uuid] */

EXTERN_C const IID IID_IDragSourceHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)

DEFINE_GUID(IID_IDragSourceHelper, 0xDE5BF786, 0x477A, 0x11d2, 0x83, 0x9d, 0, 0xc0, 0x4f, 0xd9, 0x18, 0xd0);
struct IDragSourceHelper : public IUnknown
{
  public:
    virtual HRESULT STDMETHODCALLTYPE InitializeFromBitmap(
        /* [annotation][in] */
        _In_ LPSHDRAGIMAGE pshdi,
        /* [annotation][in] */
        _In_ IDataObject *pDataObject)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE InitializeFromWindow(
        /* [annotation][unique][in] */
        _In_opt_ HWND hwnd,
        /* [annotation][unique][in] */
        _In_opt_ POINT *ppt,
        /* [annotation][in] */
        _In_ IDataObject *pDataObject)
        = 0;
};

#else /* C style interface */

typedef struct IDragSourceHelperVtbl
{
    BEGIN_INTERFACE

    DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (IDragSourceHelper *This,
     /* [in] */ REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    DECLSPEC_XFGVIRT(IUnknown, AddRef)
    ULONG(STDMETHODCALLTYPE *AddRef)(IDragSourceHelper *This);

    DECLSPEC_XFGVIRT(IUnknown, Release)
    ULONG(STDMETHODCALLTYPE *Release)(IDragSourceHelper *This);

    DECLSPEC_XFGVIRT(IDragSourceHelper, InitializeFromBitmap)
    HRESULT(STDMETHODCALLTYPE *InitializeFromBitmap)
    (IDragSourceHelper *This,
     /* [annotation][in] */
     _In_ LPSHDRAGIMAGE pshdi,
     /* [annotation][in] */
     _In_ IDataObject *pDataObject);

    DECLSPEC_XFGVIRT(IDragSourceHelper, InitializeFromWindow)
    HRESULT(STDMETHODCALLTYPE *InitializeFromWindow)
    (IDragSourceHelper *This,
     /* [annotation][unique][in] */
     _In_opt_ HWND hwnd,
     /* [annotation][unique][in] */
     _In_opt_ POINT *ppt,
     /* [annotation][in] */
     _In_ IDataObject *pDataObject);

    END_INTERFACE
} IDragSourceHelperVtbl;

interface IDragSourceHelper
{
    CONST_VTBL struct IDragSourceHelperVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IDragSourceHelper_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IDragSourceHelper_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IDragSourceHelper_Release(This) ((This)->lpVtbl->Release(This))

#define IDragSourceHelper_InitializeFromBitmap(This, pshdi, pDataObject) ((This)->lpVtbl->InitializeFromBitmap(This, pshdi, pDataObject))

#define IDragSourceHelper_InitializeFromWindow(This, hwnd, ppt, pDataObject) ((This)->lpVtbl->InitializeFromWindow(This, hwnd, ppt, pDataObject))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IDragSourceHelper_INTERFACE_DEFINED__ */

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

    HRESULT WINAPI SHCreateStdEnumFmtEtc(_In_ UINT cfmt, _In_reads_(cfmt) const FORMATETC afmt[], _Outptr_ IEnumFORMATETC **ppenumFormatEtc);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__SHELL_OBJ_H__
