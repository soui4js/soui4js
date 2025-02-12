

/* this ALWAYS GENERATED file contains the definitions for the interfaces */

/* File created by MIDL compiler version 7.00.0499 */
/* Compiler settings for comcat.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data
    VC __declspec() decoration level:
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning(disable : 4049) /* more than 64k source lines */

/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

//#include "rpc.h"
//#include "rpcndr.h"
//
//#ifndef __RPCNDR_H_VERSION__
//#error this stub requires an updated version of <rpcndr.h>
//#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __comcat_h__
#define __comcat_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */

#ifndef __IEnumGUID_FWD_DEFINED__
#define __IEnumGUID_FWD_DEFINED__
typedef interface IEnumGUID IEnumGUID;
#endif /* __IEnumGUID_FWD_DEFINED__ */

#ifndef __IEnumCATEGORYINFO_FWD_DEFINED__
#define __IEnumCATEGORYINFO_FWD_DEFINED__
typedef interface IEnumCATEGORYINFO IEnumCATEGORYINFO;
#endif /* __IEnumCATEGORYINFO_FWD_DEFINED__ */

#ifndef __ICatRegister_FWD_DEFINED__
#define __ICatRegister_FWD_DEFINED__
typedef interface ICatRegister ICatRegister;
#endif /* __ICatRegister_FWD_DEFINED__ */

#ifndef __ICatInformation_FWD_DEFINED__
#define __ICatInformation_FWD_DEFINED__
typedef interface ICatInformation ICatInformation;
#endif /* __ICatInformation_FWD_DEFINED__ */

/* header files for imported files */
#include "unknwn.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /* interface __MIDL_itf_comcat_0000_0000 */
    /* [local] */

    //=--------------------------------------------------------------------------=
    // ComCat.h
    //=--------------------------------------------------------------------------=
    // Copyright (c) Microsoft Corporation. All rights reserved.
    //
    // THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
    // ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
    // THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
    // PARTICULAR PURPOSE.
    //=--------------------------------------------------------------------------=

    //=--------------------------------------------------------------------------=
    // OLE Componet Categories Interfaces.
    //=--------------------------------------------------------------------------=
    //

    EXTERN_C const CLSID CLSID_StdComponentCategoriesMgr;

    ////////////////////////////////////////////////////////////////////////////
    //  Types
    typedef GUID CATID;

    typedef REFGUID REFCATID;

#define IID_IEnumCLSID                 IID_IEnumGUID
#define IEnumCLSID                     IEnumGUID
#define LPENUMCLSID                    LPENUMGUID
#define CATID_NULL                     GUID_NULL
#define IsEqualCATID(rcatid1, rcatid2) IsEqualGUID(rcatid1, rcatid2)
#define IID_IEnumCATID                 IID_IEnumGUID
#define IEnumCATID                     IEnumGUID

#define __RPC__out_ecount_part(a, b)

    ////////////////////////////////////////////////////////////////////////////
    //  Category IDs (link to uuid3.lib)
    EXTERN_C const CATID CATID_Insertable;
    EXTERN_C const CATID CATID_Control;
    EXTERN_C const CATID CATID_Programmable;
    EXTERN_C const CATID CATID_IsShortcut;
    EXTERN_C const CATID CATID_NeverShowExt;
    EXTERN_C const CATID CATID_DocObject;
    EXTERN_C const CATID CATID_Printable;
    EXTERN_C const CATID CATID_RequiresDataPathHost;
    EXTERN_C const CATID CATID_PersistsToMoniker;
    EXTERN_C const CATID CATID_PersistsToStorage;
    EXTERN_C const CATID CATID_PersistsToStreamInit;
    EXTERN_C const CATID CATID_PersistsToStream;
    EXTERN_C const CATID CATID_PersistsToMemory;
    EXTERN_C const CATID CATID_PersistsToFile;
    EXTERN_C const CATID CATID_PersistsToPropertyBag;
    EXTERN_C const CATID CATID_InternetAware;
    EXTERN_C const CATID CATID_DesignTimeUIActivatableControl;

////////////////////////////////////////////////////////////////////////////
//  Interface Definitions
#ifndef _LPENUMGUID_DEFINED
#define _LPENUMGUID_DEFINED

    // extern RPC_IF_HANDLE __MIDL_itf_comcat_0000_0000_v0_0_c_ifspec;
    // extern RPC_IF_HANDLE __MIDL_itf_comcat_0000_0000_v0_0_s_ifspec;

#ifndef __IEnumGUID_INTERFACE_DEFINED__
#define __IEnumGUID_INTERFACE_DEFINED__

    /* interface IEnumGUID */
    /* [unique][uuid][object] */

    typedef /* [unique] */ __RPC_unique_pointer IEnumGUID *LPENUMGUID;

#if defined(__cplusplus) && !defined(CINTERFACE)

    DEFINE_GUID(IID_IEnumGUID, 0x0002E000, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
    struct IEnumGUID : public IUnknown
    {
      public:
        virtual HRESULT STDMETHODCALLTYPE Next(
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pceltFetched) GUID *rgelt,
            /* [out] */ __RPC__out ULONG *pceltFetched)
            = 0;

        virtual HRESULT STDMETHODCALLTYPE Skip(
            /* [in] */ ULONG celt)
            = 0;

        virtual HRESULT STDMETHODCALLTYPE Reset(void) = 0;

        virtual HRESULT STDMETHODCALLTYPE Clone(
            /* [out] */ __RPC__deref_out_opt IEnumGUID **ppenum)
            = 0;
    };

#else /* C style interface */

    typedef struct IEnumGUIDVtbl
    {
        BEGIN_INTERFACE

        HRESULT(STDMETHODCALLTYPE *QueryInterface)
        (IEnumGUID *This,
         /* [in] */ __RPC__in REFIID riid,
         /* [iid_is][out] */
         __RPC__deref_out void **ppvObject);

        ULONG(STDMETHODCALLTYPE *AddRef)(IEnumGUID *This);

        ULONG(STDMETHODCALLTYPE *Release)(IEnumGUID *This);

        HRESULT(STDMETHODCALLTYPE *Next)
        (IEnumGUID *This,
         /* [in] */ ULONG celt,
         /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pceltFetched) GUID *rgelt,
         /* [out] */ __RPC__out ULONG *pceltFetched);

        HRESULT(STDMETHODCALLTYPE *Skip)
        (IEnumGUID *This,
         /* [in] */ ULONG celt);

        HRESULT(STDMETHODCALLTYPE *Reset)(IEnumGUID *This);

        HRESULT(STDMETHODCALLTYPE *Clone)
        (IEnumGUID *This,
         /* [out] */ __RPC__deref_out_opt IEnumGUID **ppenum);

        END_INTERFACE
    } IEnumGUIDVtbl;

    interface IEnumGUID
    {
        CONST_VTBL struct IEnumGUIDVtbl *lpVtbl;
    };

#ifdef COBJMACROS

#define IEnumGUID_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IEnumGUID_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IEnumGUID_Release(This) ((This)->lpVtbl->Release(This))

#define IEnumGUID_Next(This, celt, rgelt, pceltFetched) ((This)->lpVtbl->Next(This, celt, rgelt, pceltFetched))

#define IEnumGUID_Skip(This, celt) ((This)->lpVtbl->Skip(This, celt))

#define IEnumGUID_Reset(This) ((This)->lpVtbl->Reset(This))

#define IEnumGUID_Clone(This, ppenum) ((This)->lpVtbl->Clone(This, ppenum))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IEnumGUID_INTERFACE_DEFINED__ */

    /* interface __MIDL_itf_comcat_0000_0001 */
    /* [local] */

#endif
#ifndef _LPENUMCATEGORYINFO_DEFINED
#define _LPENUMCATEGORYINFO_DEFINED

    // extern RPC_IF_HANDLE __MIDL_itf_comcat_0000_0001_v0_0_c_ifspec;
    // extern RPC_IF_HANDLE __MIDL_itf_comcat_0000_0001_v0_0_s_ifspec;

#ifndef __IEnumCATEGORYINFO_INTERFACE_DEFINED__
#define __IEnumCATEGORYINFO_INTERFACE_DEFINED__

    /* interface IEnumCATEGORYINFO */
    /* [unique][uuid][object] */

    typedef /* [unique] */ __RPC_unique_pointer IEnumCATEGORYINFO *LPENUMCATEGORYINFO;

    typedef struct tagCATEGORYINFO
    {
        CATID catid;
        LCID lcid;
        OLECHAR szDescription[128];
    } CATEGORYINFO;

    typedef struct tagCATEGORYINFO *LPCATEGORYINFO;

#if defined(__cplusplus) && !defined(CINTERFACE)

    DEFINE_GUID(IID_IEnumCATEGORYINFO, 0x0002E011, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
    struct IEnumCATEGORYINFO : public IUnknown
    {
      public:
        virtual HRESULT STDMETHODCALLTYPE Next(
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pceltFetched) CATEGORYINFO *rgelt,
            /* [out] */ __RPC__out ULONG *pceltFetched)
            = 0;

        virtual HRESULT STDMETHODCALLTYPE Skip(
            /* [in] */ ULONG celt)
            = 0;

        virtual HRESULT STDMETHODCALLTYPE Reset(void) = 0;

        virtual HRESULT STDMETHODCALLTYPE Clone(
            /* [out] */ __RPC__deref_out_opt IEnumCATEGORYINFO **ppenum)
            = 0;
    };

#else /* C style interface */

    typedef struct IEnumCATEGORYINFOVtbl
    {
        BEGIN_INTERFACE

        HRESULT(STDMETHODCALLTYPE *QueryInterface)
        (IEnumCATEGORYINFO *This,
         /* [in] */ __RPC__in REFIID riid,
         /* [iid_is][out] */
         __RPC__deref_out void **ppvObject);

        ULONG(STDMETHODCALLTYPE *AddRef)(IEnumCATEGORYINFO *This);

        ULONG(STDMETHODCALLTYPE *Release)(IEnumCATEGORYINFO *This);

        HRESULT(STDMETHODCALLTYPE *Next)
        (IEnumCATEGORYINFO *This,
         /* [in] */ ULONG celt,
         /* [length_is][size_is][out] */ __RPC__out_ecount_part(celt, *pceltFetched) CATEGORYINFO *rgelt,
         /* [out] */ __RPC__out ULONG *pceltFetched);

        HRESULT(STDMETHODCALLTYPE *Skip)
        (IEnumCATEGORYINFO *This,
         /* [in] */ ULONG celt);

        HRESULT(STDMETHODCALLTYPE *Reset)(IEnumCATEGORYINFO *This);

        HRESULT(STDMETHODCALLTYPE *Clone)
        (IEnumCATEGORYINFO *This,
         /* [out] */ __RPC__deref_out_opt IEnumCATEGORYINFO **ppenum);

        END_INTERFACE
    } IEnumCATEGORYINFOVtbl;

    interface IEnumCATEGORYINFO
    {
        CONST_VTBL struct IEnumCATEGORYINFOVtbl *lpVtbl;
    };

#ifdef COBJMACROS

#define IEnumCATEGORYINFO_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IEnumCATEGORYINFO_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IEnumCATEGORYINFO_Release(This) ((This)->lpVtbl->Release(This))

#define IEnumCATEGORYINFO_Next(This, celt, rgelt, pceltFetched) ((This)->lpVtbl->Next(This, celt, rgelt, pceltFetched))

#define IEnumCATEGORYINFO_Skip(This, celt) ((This)->lpVtbl->Skip(This, celt))

#define IEnumCATEGORYINFO_Reset(This) ((This)->lpVtbl->Reset(This))

#define IEnumCATEGORYINFO_Clone(This, ppenum) ((This)->lpVtbl->Clone(This, ppenum))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IEnumCATEGORYINFO_INTERFACE_DEFINED__ */

    /* interface __MIDL_itf_comcat_0000_0002 */
    /* [local] */

#endif
#ifndef _LPCATREGISTER_DEFINED
#define _LPCATREGISTER_DEFINED

    // extern RPC_IF_HANDLE __MIDL_itf_comcat_0000_0002_v0_0_c_ifspec;
    // extern RPC_IF_HANDLE __MIDL_itf_comcat_0000_0002_v0_0_s_ifspec;

#ifndef __ICatRegister_INTERFACE_DEFINED__
#define __ICatRegister_INTERFACE_DEFINED__

    /* interface ICatRegister */
    /* [unique][uuid][object] */

    typedef /* [unique] */ __RPC_unique_pointer ICatRegister *LPCATREGISTER;

#if defined(__cplusplus) && !defined(CINTERFACE)

    DEFINE_GUID(IID_ICatRegister, 0x0002E012, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
    struct ICatRegister : public IUnknown
    {
      public:
        virtual HRESULT STDMETHODCALLTYPE RegisterCategories(
            /* [in] */ ULONG cCategories,
            /* [size_is][in] */ __RPC__in_ecount_full(cCategories) CATEGORYINFO rgCategoryInfo[])
            = 0;

        virtual HRESULT STDMETHODCALLTYPE UnRegisterCategories(
            /* [in] */ ULONG cCategories,
            /* [size_is][in] */ __RPC__in_ecount_full(cCategories) CATID rgcatid[])
            = 0;

        virtual HRESULT STDMETHODCALLTYPE RegisterClassImplCategories(
            /* [in] */ __RPC__in REFCLSID rclsid,
            /* [in] */ ULONG cCategories,
            /* [size_is][in] */ __RPC__in_ecount_full(cCategories) CATID rgcatid[])
            = 0;

        virtual HRESULT STDMETHODCALLTYPE UnRegisterClassImplCategories(
            /* [in] */ __RPC__in REFCLSID rclsid,
            /* [in] */ ULONG cCategories,
            /* [size_is][in] */ __RPC__in_ecount_full(cCategories) CATID rgcatid[])
            = 0;

        virtual HRESULT STDMETHODCALLTYPE RegisterClassReqCategories(
            /* [in] */ __RPC__in REFCLSID rclsid,
            /* [in] */ ULONG cCategories,
            /* [size_is][in] */ __RPC__in_ecount_full(cCategories) CATID rgcatid[])
            = 0;

        virtual HRESULT STDMETHODCALLTYPE UnRegisterClassReqCategories(
            /* [in] */ __RPC__in REFCLSID rclsid,
            /* [in] */ ULONG cCategories,
            /* [size_is][in] */ __RPC__in_ecount_full(cCategories) CATID rgcatid[])
            = 0;
    };

#else /* C style interface */

    typedef struct ICatRegisterVtbl
    {
        BEGIN_INTERFACE

        HRESULT(STDMETHODCALLTYPE *QueryInterface)
        (ICatRegister *This,
         /* [in] */ __RPC__in REFIID riid,
         /* [iid_is][out] */
         __RPC__deref_out void **ppvObject);

        ULONG(STDMETHODCALLTYPE *AddRef)(ICatRegister *This);

        ULONG(STDMETHODCALLTYPE *Release)(ICatRegister *This);

        HRESULT(STDMETHODCALLTYPE *RegisterCategories)
        (ICatRegister *This,
         /* [in] */ ULONG cCategories,
         /* [size_is][in] */ __RPC__in_ecount_full(cCategories) CATEGORYINFO rgCategoryInfo[]);

        HRESULT(STDMETHODCALLTYPE *UnRegisterCategories)
        (ICatRegister *This,
         /* [in] */ ULONG cCategories,
         /* [size_is][in] */ __RPC__in_ecount_full(cCategories) CATID rgcatid[]);

        HRESULT(STDMETHODCALLTYPE *RegisterClassImplCategories)
        (ICatRegister *This,
         /* [in] */ __RPC__in REFCLSID rclsid,
         /* [in] */ ULONG cCategories,
         /* [size_is][in] */ __RPC__in_ecount_full(cCategories) CATID rgcatid[]);

        HRESULT(STDMETHODCALLTYPE *UnRegisterClassImplCategories)
        (ICatRegister *This,
         /* [in] */ __RPC__in REFCLSID rclsid,
         /* [in] */ ULONG cCategories,
         /* [size_is][in] */ __RPC__in_ecount_full(cCategories) CATID rgcatid[]);

        HRESULT(STDMETHODCALLTYPE *RegisterClassReqCategories)
        (ICatRegister *This,
         /* [in] */ __RPC__in REFCLSID rclsid,
         /* [in] */ ULONG cCategories,
         /* [size_is][in] */ __RPC__in_ecount_full(cCategories) CATID rgcatid[]);

        HRESULT(STDMETHODCALLTYPE *UnRegisterClassReqCategories)
        (ICatRegister *This,
         /* [in] */ __RPC__in REFCLSID rclsid,
         /* [in] */ ULONG cCategories,
         /* [size_is][in] */ __RPC__in_ecount_full(cCategories) CATID rgcatid[]);

        END_INTERFACE
    } ICatRegisterVtbl;

    interface ICatRegister
    {
        CONST_VTBL struct ICatRegisterVtbl *lpVtbl;
    };

#ifdef COBJMACROS

#define ICatRegister_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define ICatRegister_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define ICatRegister_Release(This) ((This)->lpVtbl->Release(This))

#define ICatRegister_RegisterCategories(This, cCategories, rgCategoryInfo) ((This)->lpVtbl->RegisterCategories(This, cCategories, rgCategoryInfo))

#define ICatRegister_UnRegisterCategories(This, cCategories, rgcatid) ((This)->lpVtbl->UnRegisterCategories(This, cCategories, rgcatid))

#define ICatRegister_RegisterClassImplCategories(This, rclsid, cCategories, rgcatid) ((This)->lpVtbl->RegisterClassImplCategories(This, rclsid, cCategories, rgcatid))

#define ICatRegister_UnRegisterClassImplCategories(This, rclsid, cCategories, rgcatid) ((This)->lpVtbl->UnRegisterClassImplCategories(This, rclsid, cCategories, rgcatid))

#define ICatRegister_RegisterClassReqCategories(This, rclsid, cCategories, rgcatid) ((This)->lpVtbl->RegisterClassReqCategories(This, rclsid, cCategories, rgcatid))

#define ICatRegister_UnRegisterClassReqCategories(This, rclsid, cCategories, rgcatid) ((This)->lpVtbl->UnRegisterClassReqCategories(This, rclsid, cCategories, rgcatid))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __ICatRegister_INTERFACE_DEFINED__ */

    /* interface __MIDL_itf_comcat_0000_0003 */
    /* [local] */

#endif
#ifndef _LPCATINFORMATION_DEFINED
#define _LPCATINFORMATION_DEFINED

    // extern RPC_IF_HANDLE __MIDL_itf_comcat_0000_0003_v0_0_c_ifspec;
    // extern RPC_IF_HANDLE __MIDL_itf_comcat_0000_0003_v0_0_s_ifspec;

#ifndef __ICatInformation_INTERFACE_DEFINED__
#define __ICatInformation_INTERFACE_DEFINED__

    /* interface ICatInformation */
    /* [unique][uuid][object] */

    typedef /* [unique] */ __RPC_unique_pointer ICatInformation *LPCATINFORMATION;

#if defined(__cplusplus) && !defined(CINTERFACE)

    DEFINE_GUID(IID_ICatInformation, 0x0002E013, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
    struct ICatInformation : public IUnknown
    {
      public:
        virtual HRESULT STDMETHODCALLTYPE EnumCategories(
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt IEnumCATEGORYINFO **ppenumCategoryInfo)
            = 0;

        virtual HRESULT STDMETHODCALLTYPE GetCategoryDesc(
            /* [in] */ __RPC__in REFCATID rcatid,
            /* [in] */ LCID lcid,
            /* [out] */ __RPC__deref_out_opt LPWSTR *pszDesc)
            = 0;

        virtual /* [local] */ HRESULT STDMETHODCALLTYPE EnumClassesOfCategories(
            /* [in] */ ULONG cImplemented,
            /* [size_is][in] */ const CATID rgcatidImpl[],
            /* [in] */ ULONG cRequired,
            /* [size_is][in] */ const CATID rgcatidReq[],
            /* [out] */ IEnumGUID **ppenumClsid)
            = 0;

        virtual /* [local] */ HRESULT STDMETHODCALLTYPE IsClassOfCategories(
            /* [in] */ REFCLSID rclsid,
            /* [in] */ ULONG cImplemented,
            /* [size_is][in] */ const CATID rgcatidImpl[],
            /* [in] */ ULONG cRequired,
            /* [size_is][in] */ const CATID rgcatidReq[])
            = 0;

        virtual HRESULT STDMETHODCALLTYPE EnumImplCategoriesOfClass(
            /* [in] */ __RPC__in REFCLSID rclsid,
            /* [out] */ __RPC__deref_out_opt IEnumGUID **ppenumCatid)
            = 0;

        virtual HRESULT STDMETHODCALLTYPE EnumReqCategoriesOfClass(
            /* [in] */ __RPC__in REFCLSID rclsid,
            /* [out] */ __RPC__deref_out_opt IEnumGUID **ppenumCatid)
            = 0;
    };

#else /* C style interface */

    typedef struct ICatInformationVtbl
    {
        BEGIN_INTERFACE

        HRESULT(STDMETHODCALLTYPE *QueryInterface)
        (ICatInformation *This,
         /* [in] */ __RPC__in REFIID riid,
         /* [iid_is][out] */
         __RPC__deref_out void **ppvObject);

        ULONG(STDMETHODCALLTYPE *AddRef)(ICatInformation *This);

        ULONG(STDMETHODCALLTYPE *Release)(ICatInformation *This);

        HRESULT(STDMETHODCALLTYPE *EnumCategories)
        (ICatInformation *This,
         /* [in] */ LCID lcid,
         /* [out] */ __RPC__deref_out_opt IEnumCATEGORYINFO **ppenumCategoryInfo);

        HRESULT(STDMETHODCALLTYPE *GetCategoryDesc)
        (ICatInformation *This,
         /* [in] */ __RPC__in REFCATID rcatid,
         /* [in] */ LCID lcid,
         /* [out] */ __RPC__deref_out_opt LPWSTR *pszDesc);

        /* [local] */ HRESULT(STDMETHODCALLTYPE *EnumClassesOfCategories)(ICatInformation *This,
                                                                          /* [in] */ ULONG cImplemented,
                                                                          /* [size_is][in] */ const CATID rgcatidImpl[],
                                                                          /* [in] */ ULONG cRequired,
                                                                          /* [size_is][in] */ const CATID rgcatidReq[],
                                                                          /* [out] */ IEnumGUID **ppenumClsid);

        /* [local] */ HRESULT(STDMETHODCALLTYPE *IsClassOfCategories)(ICatInformation *This,
                                                                      /* [in] */ REFCLSID rclsid,
                                                                      /* [in] */ ULONG cImplemented,
                                                                      /* [size_is][in] */ const CATID rgcatidImpl[],
                                                                      /* [in] */ ULONG cRequired,
                                                                      /* [size_is][in] */ const CATID rgcatidReq[]);

        HRESULT(STDMETHODCALLTYPE *EnumImplCategoriesOfClass)
        (ICatInformation *This,
         /* [in] */ __RPC__in REFCLSID rclsid,
         /* [out] */ __RPC__deref_out_opt IEnumGUID **ppenumCatid);

        HRESULT(STDMETHODCALLTYPE *EnumReqCategoriesOfClass)
        (ICatInformation *This,
         /* [in] */ __RPC__in REFCLSID rclsid,
         /* [out] */ __RPC__deref_out_opt IEnumGUID **ppenumCatid);

        END_INTERFACE
    } ICatInformationVtbl;

    interface ICatInformation
    {
        CONST_VTBL struct ICatInformationVtbl *lpVtbl;
    };

#ifdef COBJMACROS

#define ICatInformation_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define ICatInformation_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define ICatInformation_Release(This) ((This)->lpVtbl->Release(This))

#define ICatInformation_EnumCategories(This, lcid, ppenumCategoryInfo) ((This)->lpVtbl->EnumCategories(This, lcid, ppenumCategoryInfo))

#define ICatInformation_GetCategoryDesc(This, rcatid, lcid, pszDesc) ((This)->lpVtbl->GetCategoryDesc(This, rcatid, lcid, pszDesc))

#define ICatInformation_EnumClassesOfCategories(This, cImplemented, rgcatidImpl, cRequired, rgcatidReq, ppenumClsid) ((This)->lpVtbl->EnumClassesOfCategories(This, cImplemented, rgcatidImpl, cRequired, rgcatidReq, ppenumClsid))

#define ICatInformation_IsClassOfCategories(This, rclsid, cImplemented, rgcatidImpl, cRequired, rgcatidReq) ((This)->lpVtbl->IsClassOfCategories(This, rclsid, cImplemented, rgcatidImpl, cRequired, rgcatidReq))

#define ICatInformation_EnumImplCategoriesOfClass(This, rclsid, ppenumCatid) ((This)->lpVtbl->EnumImplCategoriesOfClass(This, rclsid, ppenumCatid))

#define ICatInformation_EnumReqCategoriesOfClass(This, rclsid, ppenumCatid) ((This)->lpVtbl->EnumReqCategoriesOfClass(This, rclsid, ppenumCatid))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __ICatInformation_INTERFACE_DEFINED__ */

    /* interface __MIDL_itf_comcat_0000_0004 */
    /* [local] */

#endif

    /* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
