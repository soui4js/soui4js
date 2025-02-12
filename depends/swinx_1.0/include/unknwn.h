#ifndef __UNKNWN_H_
#define __UNKNWN_H_
#include <ctypes.h>
#include <basetyps.h>
#include <guiddef.h>

#define __RPC__in
#define __RPC__deref_out_opt
#define __RPC__in_opt
#define __RPC__deref_opt_in_opt
#define __RPC__out
#define __RPC__in_ecount_full(x)
#define __RPC__out_ecount_full(x)
#define __RPC_unique_pointer

DEFINE_GUID(IID_IUnknown, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);
#undef INTERFACE
#define INTERFACE IUnknown
DECLARE_INTERFACE(IUnknown)
{
    DECLARE_CLASS_SIID(IID_IUnknown)
    STDMETHOD_(HRESULT, QueryInterface)(THIS_ REFGUID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
};

typedef /* [unique] */ IUnknown *LPUNKNOWN;

DEFINE_GUID(GUID_NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

#define IID_NULL   GUID_NULL
#define CLSID_NULL GUID_NULL
#define FMTID_NULL GUID_NULL

#endif //__UNKNWN_H_