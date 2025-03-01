#ifndef __DATA_OBJECT_I_H_
#define __DATA_OBJECT_I_H_

#include <unknwn.h>

/* Forward Declarations */

#ifndef __IMarshal_FWD_DEFINED__
#define __IMarshal_FWD_DEFINED__
typedef interface IMarshal IMarshal;

#endif /* __IMarshal_FWD_DEFINED__ */

#ifndef __INoMarshal_FWD_DEFINED__
#define __INoMarshal_FWD_DEFINED__
typedef interface INoMarshal INoMarshal;

#endif /* __INoMarshal_FWD_DEFINED__ */

#ifndef __IAgileObject_FWD_DEFINED__
#define __IAgileObject_FWD_DEFINED__
typedef interface IAgileObject IAgileObject;

#endif /* __IAgileObject_FWD_DEFINED__ */

#ifndef __IActivationFilter_FWD_DEFINED__
#define __IActivationFilter_FWD_DEFINED__
typedef interface IActivationFilter IActivationFilter;

#endif /* __IActivationFilter_FWD_DEFINED__ */

#ifndef __IMarshal2_FWD_DEFINED__
#define __IMarshal2_FWD_DEFINED__
typedef interface IMarshal2 IMarshal2;

#endif /* __IMarshal2_FWD_DEFINED__ */

#ifndef __IMalloc_FWD_DEFINED__
#define __IMalloc_FWD_DEFINED__
typedef interface IMalloc IMalloc;

#endif /* __IMalloc_FWD_DEFINED__ */

#ifndef __IStdMarshalInfo_FWD_DEFINED__
#define __IStdMarshalInfo_FWD_DEFINED__
typedef interface IStdMarshalInfo IStdMarshalInfo;

#endif /* __IStdMarshalInfo_FWD_DEFINED__ */

#ifndef __IExternalConnection_FWD_DEFINED__
#define __IExternalConnection_FWD_DEFINED__
typedef interface IExternalConnection IExternalConnection;

#endif /* __IExternalConnection_FWD_DEFINED__ */

#ifndef __IMultiQI_FWD_DEFINED__
#define __IMultiQI_FWD_DEFINED__
typedef interface IMultiQI IMultiQI;

#endif /* __IMultiQI_FWD_DEFINED__ */

#ifndef __AsyncIMultiQI_FWD_DEFINED__
#define __AsyncIMultiQI_FWD_DEFINED__
typedef interface AsyncIMultiQI AsyncIMultiQI;

#endif /* __AsyncIMultiQI_FWD_DEFINED__ */

#ifndef __IInternalUnknown_FWD_DEFINED__
#define __IInternalUnknown_FWD_DEFINED__
typedef interface IInternalUnknown IInternalUnknown;

#endif /* __IInternalUnknown_FWD_DEFINED__ */

#ifndef __IEnumUnknown_FWD_DEFINED__
#define __IEnumUnknown_FWD_DEFINED__
typedef interface IEnumUnknown IEnumUnknown;

#endif /* __IEnumUnknown_FWD_DEFINED__ */

#ifndef __IEnumString_FWD_DEFINED__
#define __IEnumString_FWD_DEFINED__
typedef interface IEnumString IEnumString;

#endif /* __IEnumString_FWD_DEFINED__ */

#ifndef __ISequentialStream_FWD_DEFINED__
#define __ISequentialStream_FWD_DEFINED__
typedef interface ISequentialStream ISequentialStream;

#endif /* __ISequentialStream_FWD_DEFINED__ */

#ifndef __IStream_FWD_DEFINED__
#define __IStream_FWD_DEFINED__
typedef interface IStream IStream;

#endif /* __IStream_FWD_DEFINED__ */

#ifndef __IRpcChannelBuffer_FWD_DEFINED__
#define __IRpcChannelBuffer_FWD_DEFINED__
typedef interface IRpcChannelBuffer IRpcChannelBuffer;

#endif /* __IRpcChannelBuffer_FWD_DEFINED__ */

#ifndef __IRpcChannelBuffer2_FWD_DEFINED__
#define __IRpcChannelBuffer2_FWD_DEFINED__
typedef interface IRpcChannelBuffer2 IRpcChannelBuffer2;

#endif /* __IRpcChannelBuffer2_FWD_DEFINED__ */

#ifndef __IAsyncRpcChannelBuffer_FWD_DEFINED__
#define __IAsyncRpcChannelBuffer_FWD_DEFINED__
typedef interface IAsyncRpcChannelBuffer IAsyncRpcChannelBuffer;

#endif /* __IAsyncRpcChannelBuffer_FWD_DEFINED__ */

#ifndef __IRpcChannelBuffer3_FWD_DEFINED__
#define __IRpcChannelBuffer3_FWD_DEFINED__
typedef interface IRpcChannelBuffer3 IRpcChannelBuffer3;

#endif /* __IRpcChannelBuffer3_FWD_DEFINED__ */

#ifndef __IRpcSyntaxNegotiate_FWD_DEFINED__
#define __IRpcSyntaxNegotiate_FWD_DEFINED__
typedef interface IRpcSyntaxNegotiate IRpcSyntaxNegotiate;

#endif /* __IRpcSyntaxNegotiate_FWD_DEFINED__ */

#ifndef __IRpcProxyBuffer_FWD_DEFINED__
#define __IRpcProxyBuffer_FWD_DEFINED__
typedef interface IRpcProxyBuffer IRpcProxyBuffer;

#endif /* __IRpcProxyBuffer_FWD_DEFINED__ */

#ifndef __IRpcStubBuffer_FWD_DEFINED__
#define __IRpcStubBuffer_FWD_DEFINED__
typedef interface IRpcStubBuffer IRpcStubBuffer;

#endif /* __IRpcStubBuffer_FWD_DEFINED__ */

#ifndef __IPSFactoryBuffer_FWD_DEFINED__
#define __IPSFactoryBuffer_FWD_DEFINED__
typedef interface IPSFactoryBuffer IPSFactoryBuffer;

#endif /* __IPSFactoryBuffer_FWD_DEFINED__ */

#ifndef __IChannelHook_FWD_DEFINED__
#define __IChannelHook_FWD_DEFINED__
typedef interface IChannelHook IChannelHook;

#endif /* __IChannelHook_FWD_DEFINED__ */

#ifndef __IClientSecurity_FWD_DEFINED__
#define __IClientSecurity_FWD_DEFINED__
typedef interface IClientSecurity IClientSecurity;

#endif /* __IClientSecurity_FWD_DEFINED__ */

#ifndef __IServerSecurity_FWD_DEFINED__
#define __IServerSecurity_FWD_DEFINED__
typedef interface IServerSecurity IServerSecurity;

#endif /* __IServerSecurity_FWD_DEFINED__ */

#ifndef __IRpcOptions_FWD_DEFINED__
#define __IRpcOptions_FWD_DEFINED__
typedef interface IRpcOptions IRpcOptions;

#endif /* __IRpcOptions_FWD_DEFINED__ */

#ifndef __IGlobalOptions_FWD_DEFINED__
#define __IGlobalOptions_FWD_DEFINED__
typedef interface IGlobalOptions IGlobalOptions;

#endif /* __IGlobalOptions_FWD_DEFINED__ */

#ifndef __ISurrogate_FWD_DEFINED__
#define __ISurrogate_FWD_DEFINED__
typedef interface ISurrogate ISurrogate;

#endif /* __ISurrogate_FWD_DEFINED__ */

#ifndef __IGlobalInterfaceTable_FWD_DEFINED__
#define __IGlobalInterfaceTable_FWD_DEFINED__
typedef interface IGlobalInterfaceTable IGlobalInterfaceTable;

#endif /* __IGlobalInterfaceTable_FWD_DEFINED__ */

#ifndef __ISynchronize_FWD_DEFINED__
#define __ISynchronize_FWD_DEFINED__
typedef interface ISynchronize ISynchronize;

#endif /* __ISynchronize_FWD_DEFINED__ */

#ifndef __ISynchronizeHandle_FWD_DEFINED__
#define __ISynchronizeHandle_FWD_DEFINED__
typedef interface ISynchronizeHandle ISynchronizeHandle;

#endif /* __ISynchronizeHandle_FWD_DEFINED__ */

#ifndef __ISynchronizeEvent_FWD_DEFINED__
#define __ISynchronizeEvent_FWD_DEFINED__
typedef interface ISynchronizeEvent ISynchronizeEvent;

#endif /* __ISynchronizeEvent_FWD_DEFINED__ */

#ifndef __ISynchronizeContainer_FWD_DEFINED__
#define __ISynchronizeContainer_FWD_DEFINED__
typedef interface ISynchronizeContainer ISynchronizeContainer;

#endif /* __ISynchronizeContainer_FWD_DEFINED__ */

#ifndef __ISynchronizeMutex_FWD_DEFINED__
#define __ISynchronizeMutex_FWD_DEFINED__
typedef interface ISynchronizeMutex ISynchronizeMutex;

#endif /* __ISynchronizeMutex_FWD_DEFINED__ */

#ifndef __ICancelMethodCalls_FWD_DEFINED__
#define __ICancelMethodCalls_FWD_DEFINED__
typedef interface ICancelMethodCalls ICancelMethodCalls;

#endif /* __ICancelMethodCalls_FWD_DEFINED__ */

#ifndef __IAsyncManager_FWD_DEFINED__
#define __IAsyncManager_FWD_DEFINED__
typedef interface IAsyncManager IAsyncManager;

#endif /* __IAsyncManager_FWD_DEFINED__ */

#ifndef __ICallFactory_FWD_DEFINED__
#define __ICallFactory_FWD_DEFINED__
typedef interface ICallFactory ICallFactory;

#endif /* __ICallFactory_FWD_DEFINED__ */

#ifndef __IRpcHelper_FWD_DEFINED__
#define __IRpcHelper_FWD_DEFINED__
typedef interface IRpcHelper IRpcHelper;

#endif /* __IRpcHelper_FWD_DEFINED__ */

#ifndef __IReleaseMarshalBuffers_FWD_DEFINED__
#define __IReleaseMarshalBuffers_FWD_DEFINED__
typedef interface IReleaseMarshalBuffers IReleaseMarshalBuffers;

#endif /* __IReleaseMarshalBuffers_FWD_DEFINED__ */

#ifndef __IWaitMultiple_FWD_DEFINED__
#define __IWaitMultiple_FWD_DEFINED__
typedef interface IWaitMultiple IWaitMultiple;

#endif /* __IWaitMultiple_FWD_DEFINED__ */

#ifndef __IAddrTrackingControl_FWD_DEFINED__
#define __IAddrTrackingControl_FWD_DEFINED__
typedef interface IAddrTrackingControl IAddrTrackingControl;

#endif /* __IAddrTrackingControl_FWD_DEFINED__ */

#ifndef __IAddrExclusionControl_FWD_DEFINED__
#define __IAddrExclusionControl_FWD_DEFINED__
typedef interface IAddrExclusionControl IAddrExclusionControl;

#endif /* __IAddrExclusionControl_FWD_DEFINED__ */

#ifndef __IPipeByte_FWD_DEFINED__
#define __IPipeByte_FWD_DEFINED__
typedef interface IPipeByte IPipeByte;

#endif /* __IPipeByte_FWD_DEFINED__ */

#ifndef __AsyncIPipeByte_FWD_DEFINED__
#define __AsyncIPipeByte_FWD_DEFINED__
typedef interface AsyncIPipeByte AsyncIPipeByte;

#endif /* __AsyncIPipeByte_FWD_DEFINED__ */

#ifndef __IPipeLong_FWD_DEFINED__
#define __IPipeLong_FWD_DEFINED__
typedef interface IPipeLong IPipeLong;

#endif /* __IPipeLong_FWD_DEFINED__ */

#ifndef __AsyncIPipeLong_FWD_DEFINED__
#define __AsyncIPipeLong_FWD_DEFINED__
typedef interface AsyncIPipeLong AsyncIPipeLong;

#endif /* __AsyncIPipeLong_FWD_DEFINED__ */

#ifndef __IPipeDouble_FWD_DEFINED__
#define __IPipeDouble_FWD_DEFINED__
typedef interface IPipeDouble IPipeDouble;

#endif /* __IPipeDouble_FWD_DEFINED__ */

#ifndef __AsyncIPipeDouble_FWD_DEFINED__
#define __AsyncIPipeDouble_FWD_DEFINED__
typedef interface AsyncIPipeDouble AsyncIPipeDouble;

#endif /* __AsyncIPipeDouble_FWD_DEFINED__ */

#ifndef __IEnumContextProps_FWD_DEFINED__
#define __IEnumContextProps_FWD_DEFINED__
typedef interface IEnumContextProps IEnumContextProps;

#endif /* __IEnumContextProps_FWD_DEFINED__ */

#ifndef __IContext_FWD_DEFINED__
#define __IContext_FWD_DEFINED__
typedef interface IContext IContext;

#endif /* __IContext_FWD_DEFINED__ */

#ifndef __IObjContext_FWD_DEFINED__
#define __IObjContext_FWD_DEFINED__
typedef interface IObjContext IObjContext;

#endif /* __IObjContext_FWD_DEFINED__ */

#ifndef __IComThreadingInfo_FWD_DEFINED__
#define __IComThreadingInfo_FWD_DEFINED__
typedef interface IComThreadingInfo IComThreadingInfo;

#endif /* __IComThreadingInfo_FWD_DEFINED__ */

#ifndef __IProcessInitControl_FWD_DEFINED__
#define __IProcessInitControl_FWD_DEFINED__
typedef interface IProcessInitControl IProcessInitControl;

#endif /* __IProcessInitControl_FWD_DEFINED__ */

#ifndef __IFastRundown_FWD_DEFINED__
#define __IFastRundown_FWD_DEFINED__
typedef interface IFastRundown IFastRundown;

#endif /* __IFastRundown_FWD_DEFINED__ */

#ifndef __IMarshalingStream_FWD_DEFINED__
#define __IMarshalingStream_FWD_DEFINED__
typedef interface IMarshalingStream IMarshalingStream;

#endif /* __IMarshalingStream_FWD_DEFINED__ */

#ifndef __IAgileReference_FWD_DEFINED__
#define __IAgileReference_FWD_DEFINED__
typedef interface IAgileReference IAgileReference;

#endif /* __IAgileReference_FWD_DEFINED__ */

#ifndef __IMachineGlobalObjectTable_FWD_DEFINED__
#define __IMachineGlobalObjectTable_FWD_DEFINED__
typedef interface IMachineGlobalObjectTable IMachineGlobalObjectTable;

#endif /* __IMachineGlobalObjectTable_FWD_DEFINED__ */

#ifndef __ISupportAllowLowerTrustActivation_FWD_DEFINED__
#define __ISupportAllowLowerTrustActivation_FWD_DEFINED__
typedef interface ISupportAllowLowerTrustActivation ISupportAllowLowerTrustActivation;

#endif /* __ISupportAllowLowerTrustActivation_FWD_DEFINED__ */

#ifndef __IMallocSpy_FWD_DEFINED__
#define __IMallocSpy_FWD_DEFINED__
typedef interface IMallocSpy IMallocSpy;

#endif /* __IMallocSpy_FWD_DEFINED__ */

#ifndef __IBindCtx_FWD_DEFINED__
#define __IBindCtx_FWD_DEFINED__
typedef interface IBindCtx IBindCtx;

#endif /* __IBindCtx_FWD_DEFINED__ */

#ifndef __IEnumMoniker_FWD_DEFINED__
#define __IEnumMoniker_FWD_DEFINED__
typedef interface IEnumMoniker IEnumMoniker;

#endif /* __IEnumMoniker_FWD_DEFINED__ */

#ifndef __IRunnableObject_FWD_DEFINED__
#define __IRunnableObject_FWD_DEFINED__
typedef interface IRunnableObject IRunnableObject;

#endif /* __IRunnableObject_FWD_DEFINED__ */

#ifndef __IRunningObjectTable_FWD_DEFINED__
#define __IRunningObjectTable_FWD_DEFINED__
typedef interface IRunningObjectTable IRunningObjectTable;

#endif /* __IRunningObjectTable_FWD_DEFINED__ */

#ifndef __IPersist_FWD_DEFINED__
#define __IPersist_FWD_DEFINED__
typedef interface IPersist IPersist;

#endif /* __IPersist_FWD_DEFINED__ */

#ifndef __IPersistStream_FWD_DEFINED__
#define __IPersistStream_FWD_DEFINED__
typedef interface IPersistStream IPersistStream;

#endif /* __IPersistStream_FWD_DEFINED__ */

#ifndef __IMoniker_FWD_DEFINED__
#define __IMoniker_FWD_DEFINED__
typedef interface IMoniker IMoniker;

#endif /* __IMoniker_FWD_DEFINED__ */

#ifndef __IROTData_FWD_DEFINED__
#define __IROTData_FWD_DEFINED__
typedef interface IROTData IROTData;

#endif /* __IROTData_FWD_DEFINED__ */

#ifndef __IEnumSTATSTG_FWD_DEFINED__
#define __IEnumSTATSTG_FWD_DEFINED__
typedef interface IEnumSTATSTG IEnumSTATSTG;

#endif /* __IEnumSTATSTG_FWD_DEFINED__ */

#ifndef __IStorage_FWD_DEFINED__
#define __IStorage_FWD_DEFINED__
typedef interface IStorage IStorage;

#endif /* __IStorage_FWD_DEFINED__ */

#ifndef __IPersistFile_FWD_DEFINED__
#define __IPersistFile_FWD_DEFINED__
typedef interface IPersistFile IPersistFile;

#endif /* __IPersistFile_FWD_DEFINED__ */

#ifndef __IPersistStorage_FWD_DEFINED__
#define __IPersistStorage_FWD_DEFINED__
typedef interface IPersistStorage IPersistStorage;

#endif /* __IPersistStorage_FWD_DEFINED__ */

#ifndef __ILockBytes_FWD_DEFINED__
#define __ILockBytes_FWD_DEFINED__
typedef interface ILockBytes ILockBytes;

#endif /* __ILockBytes_FWD_DEFINED__ */

#ifndef __IEnumFORMATETC_FWD_DEFINED__
#define __IEnumFORMATETC_FWD_DEFINED__
typedef interface IEnumFORMATETC IEnumFORMATETC;

#endif /* __IEnumFORMATETC_FWD_DEFINED__ */

#ifndef __IEnumSTATDATA_FWD_DEFINED__
#define __IEnumSTATDATA_FWD_DEFINED__
typedef interface IEnumSTATDATA IEnumSTATDATA;

#endif /* __IEnumSTATDATA_FWD_DEFINED__ */

#ifndef __IRootStorage_FWD_DEFINED__
#define __IRootStorage_FWD_DEFINED__
typedef interface IRootStorage IRootStorage;

#endif /* __IRootStorage_FWD_DEFINED__ */

#ifndef __IAdviseSink_FWD_DEFINED__
#define __IAdviseSink_FWD_DEFINED__
typedef interface IAdviseSink IAdviseSink;

#endif /* __IAdviseSink_FWD_DEFINED__ */

#ifndef __AsyncIAdviseSink_FWD_DEFINED__
#define __AsyncIAdviseSink_FWD_DEFINED__
typedef interface AsyncIAdviseSink AsyncIAdviseSink;

#endif /* __AsyncIAdviseSink_FWD_DEFINED__ */

#ifndef __IAdviseSink2_FWD_DEFINED__
#define __IAdviseSink2_FWD_DEFINED__
typedef interface IAdviseSink2 IAdviseSink2;

#endif /* __IAdviseSink2_FWD_DEFINED__ */

#ifndef __AsyncIAdviseSink2_FWD_DEFINED__
#define __AsyncIAdviseSink2_FWD_DEFINED__
typedef interface AsyncIAdviseSink2 AsyncIAdviseSink2;

#endif /* __AsyncIAdviseSink2_FWD_DEFINED__ */

#ifndef __IDataObject_FWD_DEFINED__
#define __IDataObject_FWD_DEFINED__
typedef interface IDataObject IDataObject;

#endif /* __IDataObject_FWD_DEFINED__ */

#ifndef __IDataAdviseHolder_FWD_DEFINED__
#define __IDataAdviseHolder_FWD_DEFINED__
typedef interface IDataAdviseHolder IDataAdviseHolder;

#endif /* __IDataAdviseHolder_FWD_DEFINED__ */

#ifndef __IMessageFilter_FWD_DEFINED__
#define __IMessageFilter_FWD_DEFINED__
typedef interface IMessageFilter IMessageFilter;

#endif /* __IMessageFilter_FWD_DEFINED__ */

#ifndef __IClassActivator_FWD_DEFINED__
#define __IClassActivator_FWD_DEFINED__
typedef interface IClassActivator IClassActivator;

#endif /* __IClassActivator_FWD_DEFINED__ */

#ifndef __IFillLockBytes_FWD_DEFINED__
#define __IFillLockBytes_FWD_DEFINED__
typedef interface IFillLockBytes IFillLockBytes;

#endif /* __IFillLockBytes_FWD_DEFINED__ */

#ifndef __IProgressNotify_FWD_DEFINED__
#define __IProgressNotify_FWD_DEFINED__
typedef interface IProgressNotify IProgressNotify;

#endif /* __IProgressNotify_FWD_DEFINED__ */

#ifndef __ILayoutStorage_FWD_DEFINED__
#define __ILayoutStorage_FWD_DEFINED__
typedef interface ILayoutStorage ILayoutStorage;

#endif /* __ILayoutStorage_FWD_DEFINED__ */

#ifndef __IBlockingLock_FWD_DEFINED__
#define __IBlockingLock_FWD_DEFINED__
typedef interface IBlockingLock IBlockingLock;

#endif /* __IBlockingLock_FWD_DEFINED__ */

#ifndef __ITimeAndNoticeControl_FWD_DEFINED__
#define __ITimeAndNoticeControl_FWD_DEFINED__
typedef interface ITimeAndNoticeControl ITimeAndNoticeControl;

#endif /* __ITimeAndNoticeControl_FWD_DEFINED__ */

#ifndef __IOplockStorage_FWD_DEFINED__
#define __IOplockStorage_FWD_DEFINED__
typedef interface IOplockStorage IOplockStorage;

#endif /* __IOplockStorage_FWD_DEFINED__ */

#ifndef __IDirectWriterLock_FWD_DEFINED__
#define __IDirectWriterLock_FWD_DEFINED__
typedef interface IDirectWriterLock IDirectWriterLock;

#endif /* __IDirectWriterLock_FWD_DEFINED__ */

#ifndef __IUrlMon_FWD_DEFINED__
#define __IUrlMon_FWD_DEFINED__
typedef interface IUrlMon IUrlMon;

#endif /* __IUrlMon_FWD_DEFINED__ */

#ifndef __IForegroundTransfer_FWD_DEFINED__
#define __IForegroundTransfer_FWD_DEFINED__
typedef interface IForegroundTransfer IForegroundTransfer;

#endif /* __IForegroundTransfer_FWD_DEFINED__ */

#ifndef __IThumbnailExtractor_FWD_DEFINED__
#define __IThumbnailExtractor_FWD_DEFINED__
typedef interface IThumbnailExtractor IThumbnailExtractor;

#endif /* __IThumbnailExtractor_FWD_DEFINED__ */

#ifndef __IDummyHICONIncluder_FWD_DEFINED__
#define __IDummyHICONIncluder_FWD_DEFINED__
typedef interface IDummyHICONIncluder IDummyHICONIncluder;

#endif /* __IDummyHICONIncluder_FWD_DEFINED__ */

#ifndef __IProcessLock_FWD_DEFINED__
#define __IProcessLock_FWD_DEFINED__
typedef interface IProcessLock IProcessLock;

#endif /* __IProcessLock_FWD_DEFINED__ */

#ifndef __ISurrogateService_FWD_DEFINED__
#define __ISurrogateService_FWD_DEFINED__
typedef interface ISurrogateService ISurrogateService;

#endif /* __ISurrogateService_FWD_DEFINED__ */

#ifndef __IInitializeSpy_FWD_DEFINED__
#define __IInitializeSpy_FWD_DEFINED__
typedef interface IInitializeSpy IInitializeSpy;

#endif /* __IInitializeSpy_FWD_DEFINED__ */

#ifndef __IApartmentShutdown_FWD_DEFINED__
#define __IApartmentShutdown_FWD_DEFINED__
typedef interface IApartmentShutdown IApartmentShutdown;

#endif /* __IApartmentShutdown_FWD_DEFINED__ */

#define _COM_Outptr_
#define __RPC__in
#define __RPC__inout

#ifndef __ISequentialStream_INTERFACE_DEFINED__
#define __ISequentialStream_INTERFACE_DEFINED__

/* interface ISequentialStream */
/* [unique][uuid][object] */

struct ISequentialStream;

DEFINE_GUID(IID_ISequentialStream, 0x0c733a30, 0x2a1c, 0x11ce, 0xad, 0xe5, 0, 0xaa, 0, 0x44, 0x77, 0x3d);

#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE ISequentialStream
DECLARE_INTERFACE_(ISequentialStream, IUnknown)
{
  public:
    DECLARE_CLASS_SIID(IID_ISequentialStream)

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE Read(
        /* [annotation] */
        _Out_writes_bytes_to_(cb, *pcbRead) void *pv,
        /* [annotation][in] */
        _In_ ULONG cb,
        /* [annotation] */
        _Out_opt_ ULONG *pcbRead)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE Write(
        /* [annotation] */
        _In_reads_bytes_(cb) const void *pv,
        /* [annotation][in] */
        _In_ ULONG cb,
        /* [annotation] */
        _Out_opt_ ULONG *pcbWritten)
        = 0;
};

#else /* C style interface */

typedef struct ISequentialStreamVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in ISequentialStream *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in ISequentialStream *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in ISequentialStream *This);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *Read)(ISequentialStream *This,
                                                   /* [annotation] */
                                                   _Out_writes_bytes_to_(cb, *pcbRead) void *pv,
                                                   /* [annotation][in] */
                                                   _In_ ULONG cb,
                                                   /* [annotation] */
                                                   _Out_opt_ ULONG *pcbRead);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *Write)(ISequentialStream *This,
                                                    /* [annotation] */
                                                    _In_reads_bytes_(cb) const void *pv,
                                                    /* [annotation][in] */
                                                    _In_ ULONG cb,
                                                    /* [annotation] */
                                                    _Out_opt_ ULONG *pcbWritten);

    END_INTERFACE
} ISequentialStreamVtbl;

interface ISequentialStream
{
    CONST_VTBL struct ISequentialStreamVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define ISequentialStream_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define ISequentialStream_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define ISequentialStream_Release(This) ((This)->lpVtbl->Release(This))

#define ISequentialStream_Read(This, pv, cb, pcbRead) ((This)->lpVtbl->Read(This, pv, cb, pcbRead))

#define ISequentialStream_Write(This, pv, cb, pcbWritten) ((This)->lpVtbl->Write(This, pv, cb, pcbWritten))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __ISequentialStream_INTERFACE_DEFINED__ */

#ifndef __IStream_INTERFACE_DEFINED__
#define __IStream_INTERFACE_DEFINED__

/* interface IStream */
/* [unique][uuid][object] */

typedef /* [unique] */ struct IStream *LPSTREAM;

typedef struct tagSTATSTG
{
    LPOLESTR pwcsName;
    DWORD type;
    ULARGE_INTEGER cbSize;
    FILETIME mtime;
    FILETIME ctime;
    FILETIME atime;
    DWORD grfMode;
    DWORD grfLocksSupported;
    CLSID clsid;
    DWORD grfStateBits;
    DWORD reserved;
} STATSTG;

typedef enum tagSTGTY
{
    STGTY_STORAGE = 1,
    STGTY_STREAM = 2,
    STGTY_LOCKBYTES = 3,
    STGTY_PROPERTY = 4
} STGTY;

typedef enum tagSTREAM_SEEK
{
    STREAM_SEEK_SET = 0,
    STREAM_SEEK_CUR = 1,
    STREAM_SEEK_END = 2
} STREAM_SEEK;

typedef enum tagLOCKTYPE
{
    LOCK_WRITE = 1,
    LOCK_EXCLUSIVE = 2,
    LOCK_ONLYONCE = 4
} LOCKTYPE;

#define _Out_opt_
#define _COM_Outptr_

DEFINE_GUID(IID_IStream, 0x0000000c, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE IStream
DECLARE_INTERFACE_(IStream, ISequentialStream)
{
  public:
    DECLARE_CLASS_SIID(IID_IStream)

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE Seek(
        /* [in] */ LARGE_INTEGER dlibMove,
        /* [in] */ DWORD dwOrigin,
        /* [annotation] */
        /*_Out_opt_*/ ULARGE_INTEGER * plibNewPosition)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE SetSize(
        /* [in] */ ULARGE_INTEGER libNewSize)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE CopyTo(
        /* [annotation][unique][in] */
        _In_ IStream * pstm,
        /* [in] */ ULARGE_INTEGER cb,
        /* [annotation] */
        _Out_opt_ ULARGE_INTEGER * pcbRead,
        /* [annotation] */
        _Out_opt_ ULARGE_INTEGER * pcbWritten)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Commit(
        /* [in] */ DWORD grfCommitFlags)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Revert(void) = 0;

    virtual HRESULT STDMETHODCALLTYPE LockRegion(
        /* [in] */ ULARGE_INTEGER libOffset,
        /* [in] */ ULARGE_INTEGER cb,
        /* [in] */ DWORD dwLockType)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE UnlockRegion(
        /* [in] */ ULARGE_INTEGER libOffset,
        /* [in] */ ULARGE_INTEGER cb,
        /* [in] */ DWORD dwLockType)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Stat(
        /* [out] */ __RPC__out STATSTG * pstatstg,
        /* [in] */ DWORD grfStatFlag)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Clone(
        /* [out] */ __RPC__deref_out_opt IStream * *ppstm)
        = 0;
};

#else /* C style interface */

typedef struct IStreamVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in IStream *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in IStream *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in IStream *This);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *Read)(IStream *This,
                                                   /* [annotation] */
                                                   _Out_writes_bytes_to_(cb, *pcbRead) void *pv,
                                                   /* [annotation][in] */
                                                   _In_ ULONG cb,
                                                   /* [annotation] */
                                                   _Out_opt_ ULONG *pcbRead);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *Write)(IStream *This,
                                                    /* [annotation] */
                                                    _In_reads_bytes_(cb) const void *pv,
                                                    /* [annotation][in] */
                                                    _In_ ULONG cb,
                                                    /* [annotation] */
                                                    _Out_opt_ ULONG *pcbWritten);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *Seek)(IStream *This,
                                                   /* [in] */ LARGE_INTEGER dlibMove,
                                                   /* [in] */ DWORD dwOrigin,
                                                   /* [annotation] */
                                                   _Out_opt_ ULARGE_INTEGER *plibNewPosition);

    HRESULT(STDMETHODCALLTYPE *SetSize)
    (__RPC__in IStream *This,
     /* [in] */ ULARGE_INTEGER libNewSize);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *CopyTo)(IStream *This,
                                                     /* [annotation][unique][in] */
                                                     _In_ IStream *pstm,
                                                     /* [in] */ ULARGE_INTEGER cb,
                                                     /* [annotation] */
                                                     _Out_opt_ ULARGE_INTEGER *pcbRead,
                                                     /* [annotation] */
                                                     _Out_opt_ ULARGE_INTEGER *pcbWritten);

    HRESULT(STDMETHODCALLTYPE *Commit)
    (__RPC__in IStream *This,
     /* [in] */ DWORD grfCommitFlags);

    HRESULT(STDMETHODCALLTYPE *Revert)(__RPC__in IStream *This);

    HRESULT(STDMETHODCALLTYPE *LockRegion)
    (__RPC__in IStream *This,
     /* [in] */ ULARGE_INTEGER libOffset,
     /* [in] */ ULARGE_INTEGER cb,
     /* [in] */ DWORD dwLockType);

    HRESULT(STDMETHODCALLTYPE *UnlockRegion)
    (__RPC__in IStream *This,
     /* [in] */ ULARGE_INTEGER libOffset,
     /* [in] */ ULARGE_INTEGER cb,
     /* [in] */ DWORD dwLockType);

    HRESULT(STDMETHODCALLTYPE *Stat)
    (__RPC__in IStream *This,
     /* [out] */ __RPC__out STATSTG *pstatstg,
     /* [in] */ DWORD grfStatFlag);

    HRESULT(STDMETHODCALLTYPE *Clone)
    (__RPC__in IStream *This,
     /* [out] */ __RPC__deref_out_opt IStream **ppstm);

    END_INTERFACE
} IStreamVtbl;

interface IStream
{
    CONST_VTBL struct IStreamVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IStream_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IStream_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IStream_Release(This) ((This)->lpVtbl->Release(This))

#define IStream_Read(This, pv, cb, pcbRead) ((This)->lpVtbl->Read(This, pv, cb, pcbRead))

#define IStream_Write(This, pv, cb, pcbWritten) ((This)->lpVtbl->Write(This, pv, cb, pcbWritten))

#define IStream_Seek(This, dlibMove, dwOrigin, plibNewPosition) ((This)->lpVtbl->Seek(This, dlibMove, dwOrigin, plibNewPosition))

#define IStream_SetSize(This, libNewSize) ((This)->lpVtbl->SetSize(This, libNewSize))

#define IStream_CopyTo(This, pstm, cb, pcbRead, pcbWritten) ((This)->lpVtbl->CopyTo(This, pstm, cb, pcbRead, pcbWritten))

#define IStream_Commit(This, grfCommitFlags) ((This)->lpVtbl->Commit(This, grfCommitFlags))

#define IStream_Revert(This) ((This)->lpVtbl->Revert(This))

#define IStream_LockRegion(This, libOffset, cb, dwLockType) ((This)->lpVtbl->LockRegion(This, libOffset, cb, dwLockType))

#define IStream_UnlockRegion(This, libOffset, cb, dwLockType) ((This)->lpVtbl->UnlockRegion(This, libOffset, cb, dwLockType))

#define IStream_Stat(This, pstatstg, grfStatFlag) ((This)->lpVtbl->Stat(This, pstatstg, grfStatFlag))

#define IStream_Clone(This, ppstm) ((This)->lpVtbl->Clone(This, ppstm))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IStream_INTERFACE_DEFINED__ */

#ifndef __IEnumSTATSTG_INTERFACE_DEFINED__
#define __IEnumSTATSTG_INTERFACE_DEFINED__
#define _Out_writes_to_(a, b)

/* interface IEnumSTATSTG */
/* [unique][uuid][object] */

typedef /* [unique] */ struct IEnumSTATSTG *LPENUMSTATSTG;

DEFINE_GUID(IID_IEnumSTATSTG, 0x0000000d, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);

#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE IEnumSTATSTG
DECLARE_INTERFACE_(IEnumSTATSTG, IUnknown)
{
  public:
    DECLARE_CLASS_SIID(IID_IEnumSTATSTG)

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE Next(
        /* [in] */ ULONG celt,
        /* [annotation] */
        _Out_writes_to_(celt, *pceltFetched) STATSTG * rgelt,
        /* [annotation] */
        _Out_opt_ ULONG * pceltFetched)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Skip(
        /* [in] */ ULONG celt)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Reset(void) = 0;

    virtual HRESULT STDMETHODCALLTYPE Clone(
        /* [out] */ __RPC__deref_out_opt IEnumSTATSTG * *ppenum)
        = 0;
};

#else /* C style interface */

typedef struct IEnumSTATSTGVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in IEnumSTATSTG *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in IEnumSTATSTG *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in IEnumSTATSTG *This);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *Next)(IEnumSTATSTG *This,
                                                   /* [in] */ ULONG celt,
                                                   /* [annotation] */
                                                   _Out_writes_to_(celt, *pceltFetched) STATSTG *rgelt,
                                                   /* [annotation] */
                                                   _Out_opt_ ULONG *pceltFetched);

    HRESULT(STDMETHODCALLTYPE *Skip)
    (__RPC__in IEnumSTATSTG *This,
     /* [in] */ ULONG celt);

    HRESULT(STDMETHODCALLTYPE *Reset)(__RPC__in IEnumSTATSTG *This);

    HRESULT(STDMETHODCALLTYPE *Clone)
    (__RPC__in IEnumSTATSTG *This,
     /* [out] */ __RPC__deref_out_opt IEnumSTATSTG **ppenum);

    END_INTERFACE
} IEnumSTATSTGVtbl;

interface IEnumSTATSTG
{
    CONST_VTBL struct IEnumSTATSTGVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IEnumSTATSTG_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IEnumSTATSTG_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IEnumSTATSTG_Release(This) ((This)->lpVtbl->Release(This))

#define IEnumSTATSTG_Next(This, celt, rgelt, pceltFetched) ((This)->lpVtbl->Next(This, celt, rgelt, pceltFetched))

#define IEnumSTATSTG_Skip(This, celt) ((This)->lpVtbl->Skip(This, celt))

#define IEnumSTATSTG_Reset(This) ((This)->lpVtbl->Reset(This))

#define IEnumSTATSTG_Clone(This, ppenum) ((This)->lpVtbl->Clone(This, ppenum))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IEnumSTATSTG_INTERFACE_DEFINED__ */

#ifndef __IStorage_INTERFACE_DEFINED__
#define __IStorage_INTERFACE_DEFINED__
#define __RPC__in_string
#define _Null_terminated_
/* interface IStorage */
/* [unique][uuid][object] */

typedef /* [unique] */ struct IStorage *LPSTORAGE;

typedef struct tagRemSNB
{
    ULONG ulCntStr;
    ULONG ulCntChar;
    /* [size_is] */ OLECHAR rgString[1];
} RemSNB;

typedef /* [unique] */ RemSNB *wireSNB;

typedef /* [annotation][wire_marshal] */ _Null_terminated_ LPOLESTR *SNB;

DEFINE_GUID(IID_IStorage, 0x0000000b, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
#define __RPC__in_opt_string
#define _In_z_
#define _Reserved_
#define _In_reads_opt_(a)

#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE IStorage
DECLARE_INTERFACE_(IStorage, IUnknown)
{
  public:
    DECLARE_CLASS_SIID(IID_IStorage)

    virtual HRESULT STDMETHODCALLTYPE CreateStream(
        /* [string][in] */ __RPC__in_string const OLECHAR *pwcsName,
        /* [in] */ DWORD grfMode,
        /* [in] */ DWORD reserved1,
        /* [in] */ DWORD reserved2,
        /* [out] */ __RPC__deref_out_opt IStream **ppstm)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE OpenStream(
        /* [annotation][string][in] */
        _In_z_ const OLECHAR *pwcsName,
        /* [annotation][unique][in] */
        _Reserved_ void *reserved1,
        /* [in] */ DWORD grfMode,
        /* [in] */ DWORD reserved2,
        /* [annotation][out] */
        _Outptr_ IStream **ppstm)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE CreateStorage(
        /* [string][in] */ __RPC__in_string const OLECHAR *pwcsName,
        /* [in] */ DWORD grfMode,
        /* [in] */ DWORD reserved1,
        /* [in] */ DWORD reserved2,
        /* [out] */ __RPC__deref_out_opt IStorage **ppstg)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE OpenStorage(
        /* [string][unique][in] */ __RPC__in_opt_string const OLECHAR *pwcsName,
        /* [unique][in] */ __RPC__in_opt IStorage *pstgPriority,
        /* [in] */ DWORD grfMode,
        /* [unique][in] */ __RPC__deref_opt_in_opt SNB snbExclude,
        /* [in] */ DWORD reserved,
        /* [out] */ __RPC__deref_out_opt IStorage **ppstg)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE CopyTo(
        /* [in] */ DWORD ciidExclude,
        /* [annotation][size_is][unique][in] */
        _In_reads_opt_(ciidExclude) const IID *rgiidExclude,
        /* [annotation][unique][in] */
        _In_opt_ SNB snbExclude,
        /* [annotation][unique][in] */
        _In_ IStorage *pstgDest)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE MoveElementTo(
        /* [string][in] */ __RPC__in_string const OLECHAR *pwcsName,
        /* [unique][in] */ __RPC__in_opt IStorage *pstgDest,
        /* [string][in] */ __RPC__in_string const OLECHAR *pwcsNewName,
        /* [in] */ DWORD grfFlags)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Commit(
        /* [in] */ DWORD grfCommitFlags)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Revert(void) = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE EnumElements(
        /* [annotation][in] */
        _Reserved_ DWORD reserved1,
        /* [annotation][size_is][unique][in] */
        _Reserved_ void *reserved2,
        /* [annotation][in] */
        _Reserved_ DWORD reserved3,
        /* [annotation][out] */
        _Outptr_ IEnumSTATSTG **ppenum)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE DestroyElement(
        /* [string][in] */ __RPC__in_string const OLECHAR *pwcsName)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE RenameElement(
        /* [string][in] */ __RPC__in_string const OLECHAR *pwcsOldName,
        /* [string][in] */ __RPC__in_string const OLECHAR *pwcsNewName)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE SetElementTimes(
        /* [string][unique][in] */ __RPC__in_opt_string const OLECHAR *pwcsName,
        /* [unique][in] */ __RPC__in_opt const FILETIME *pctime,
        /* [unique][in] */ __RPC__in_opt const FILETIME *patime,
        /* [unique][in] */ __RPC__in_opt const FILETIME *pmtime)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE SetClass(
        /* [in] */ __RPC__in REFCLSID clsid)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE SetStateBits(
        /* [in] */ DWORD grfStateBits,
        /* [in] */ DWORD grfMask)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Stat(
        /* [out] */ __RPC__out STATSTG * pstatstg,
        /* [in] */ DWORD grfStatFlag)
        = 0;
};

#else /* C style interface */

typedef struct IStorageVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in IStorage *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in IStorage *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in IStorage *This);

    HRESULT(STDMETHODCALLTYPE *CreateStream)
    (__RPC__in IStorage *This,
     /* [string][in] */ __RPC__in_string const OLECHAR *pwcsName,
     /* [in] */ DWORD grfMode,
     /* [in] */ DWORD reserved1,
     /* [in] */ DWORD reserved2,
     /* [out] */ __RPC__deref_out_opt IStream **ppstm);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *OpenStream)(IStorage *This,
                                                         /* [annotation][string][in] */
                                                         _In_z_ const OLECHAR *pwcsName,
                                                         /* [annotation][unique][in] */
                                                         _Reserved_ void *reserved1,
                                                         /* [in] */ DWORD grfMode,
                                                         /* [in] */ DWORD reserved2,
                                                         /* [annotation][out] */
                                                         _Outptr_ IStream **ppstm);

    HRESULT(STDMETHODCALLTYPE *CreateStorage)
    (__RPC__in IStorage *This,
     /* [string][in] */ __RPC__in_string const OLECHAR *pwcsName,
     /* [in] */ DWORD grfMode,
     /* [in] */ DWORD reserved1,
     /* [in] */ DWORD reserved2,
     /* [out] */ __RPC__deref_out_opt IStorage **ppstg);

    HRESULT(STDMETHODCALLTYPE *OpenStorage)
    (__RPC__in IStorage *This,
     /* [string][unique][in] */ __RPC__in_opt_string const OLECHAR *pwcsName,
     /* [unique][in] */ __RPC__in_opt IStorage *pstgPriority,
     /* [in] */ DWORD grfMode,
     /* [unique][in] */ __RPC__deref_opt_in_opt SNB snbExclude,
     /* [in] */ DWORD reserved,
     /* [out] */ __RPC__deref_out_opt IStorage **ppstg);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *CopyTo)(IStorage *This,
                                                     /* [in] */ DWORD ciidExclude,
                                                     /* [annotation][size_is][unique][in] */
                                                     _In_reads_opt_(ciidExclude) const IID *rgiidExclude,
                                                     /* [annotation][unique][in] */
                                                     _In_opt_ SNB snbExclude,
                                                     /* [annotation][unique][in] */
                                                     _In_ IStorage *pstgDest);

    HRESULT(STDMETHODCALLTYPE *MoveElementTo)
    (__RPC__in IStorage *This,
     /* [string][in] */ __RPC__in_string const OLECHAR *pwcsName,
     /* [unique][in] */ __RPC__in_opt IStorage *pstgDest,
     /* [string][in] */ __RPC__in_string const OLECHAR *pwcsNewName,
     /* [in] */ DWORD grfFlags);

    HRESULT(STDMETHODCALLTYPE *Commit)
    (__RPC__in IStorage *This,
     /* [in] */ DWORD grfCommitFlags);

    HRESULT(STDMETHODCALLTYPE *Revert)(__RPC__in IStorage *This);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *EnumElements)(IStorage *This,
                                                           /* [annotation][in] */
                                                           _Reserved_ DWORD reserved1,
                                                           /* [annotation][size_is][unique][in] */
                                                           _Reserved_ void *reserved2,
                                                           /* [annotation][in] */
                                                           _Reserved_ DWORD reserved3,
                                                           /* [annotation][out] */
                                                           _Outptr_ IEnumSTATSTG **ppenum);

    HRESULT(STDMETHODCALLTYPE *DestroyElement)
    (__RPC__in IStorage *This,
     /* [string][in] */ __RPC__in_string const OLECHAR *pwcsName);

    HRESULT(STDMETHODCALLTYPE *RenameElement)
    (__RPC__in IStorage *This,
     /* [string][in] */ __RPC__in_string const OLECHAR *pwcsOldName,
     /* [string][in] */ __RPC__in_string const OLECHAR *pwcsNewName);

    HRESULT(STDMETHODCALLTYPE *SetElementTimes)
    (__RPC__in IStorage *This,
     /* [string][unique][in] */ __RPC__in_opt_string const OLECHAR *pwcsName,
     /* [unique][in] */ __RPC__in_opt const FILETIME *pctime,
     /* [unique][in] */ __RPC__in_opt const FILETIME *patime,
     /* [unique][in] */ __RPC__in_opt const FILETIME *pmtime);

    HRESULT(STDMETHODCALLTYPE *SetClass)
    (__RPC__in IStorage *This,
     /* [in] */ __RPC__in REFCLSID clsid);

    HRESULT(STDMETHODCALLTYPE *SetStateBits)
    (__RPC__in IStorage *This,
     /* [in] */ DWORD grfStateBits,
     /* [in] */ DWORD grfMask);

    HRESULT(STDMETHODCALLTYPE *Stat)
    (__RPC__in IStorage *This,
     /* [out] */ __RPC__out STATSTG *pstatstg,
     /* [in] */ DWORD grfStatFlag);

    END_INTERFACE
} IStorageVtbl;

interface IStorage
{
    CONST_VTBL struct IStorageVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IStorage_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IStorage_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IStorage_Release(This) ((This)->lpVtbl->Release(This))

#define IStorage_CreateStream(This, pwcsName, grfMode, reserved1, reserved2, ppstm) ((This)->lpVtbl->CreateStream(This, pwcsName, grfMode, reserved1, reserved2, ppstm))

#define IStorage_OpenStream(This, pwcsName, reserved1, grfMode, reserved2, ppstm) ((This)->lpVtbl->OpenStream(This, pwcsName, reserved1, grfMode, reserved2, ppstm))

#define IStorage_CreateStorage(This, pwcsName, grfMode, reserved1, reserved2, ppstg) ((This)->lpVtbl->CreateStorage(This, pwcsName, grfMode, reserved1, reserved2, ppstg))

#define IStorage_OpenStorage(This, pwcsName, pstgPriority, grfMode, snbExclude, reserved, ppstg) ((This)->lpVtbl->OpenStorage(This, pwcsName, pstgPriority, grfMode, snbExclude, reserved, ppstg))

#define IStorage_CopyTo(This, ciidExclude, rgiidExclude, snbExclude, pstgDest) ((This)->lpVtbl->CopyTo(This, ciidExclude, rgiidExclude, snbExclude, pstgDest))

#define IStorage_MoveElementTo(This, pwcsName, pstgDest, pwcsNewName, grfFlags) ((This)->lpVtbl->MoveElementTo(This, pwcsName, pstgDest, pwcsNewName, grfFlags))

#define IStorage_Commit(This, grfCommitFlags) ((This)->lpVtbl->Commit(This, grfCommitFlags))

#define IStorage_Revert(This) ((This)->lpVtbl->Revert(This))

#define IStorage_EnumElements(This, reserved1, reserved2, reserved3, ppenum) ((This)->lpVtbl->EnumElements(This, reserved1, reserved2, reserved3, ppenum))

#define IStorage_DestroyElement(This, pwcsName) ((This)->lpVtbl->DestroyElement(This, pwcsName))

#define IStorage_RenameElement(This, pwcsOldName, pwcsNewName) ((This)->lpVtbl->RenameElement(This, pwcsOldName, pwcsNewName))

#define IStorage_SetElementTimes(This, pwcsName, pctime, patime, pmtime) ((This)->lpVtbl->SetElementTimes(This, pwcsName, pctime, patime, pmtime))

#define IStorage_SetClass(This, clsid) ((This)->lpVtbl->SetClass(This, clsid))

#define IStorage_SetStateBits(This, grfStateBits, grfMask) ((This)->lpVtbl->SetStateBits(This, grfStateBits, grfMask))

#define IStorage_Stat(This, pstatstg, grfStatFlag) ((This)->lpVtbl->Stat(This, pstatstg, grfStatFlag))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IStorage_INTERFACE_DEFINED__ */

#ifndef __IEnumFORMATETC_INTERFACE_DEFINED__
#define __IEnumFORMATETC_INTERFACE_DEFINED__

/* interface IEnumFORMATETC */
/* [unique][uuid][object] */

typedef /* [unique] */ struct IEnumFORMATETC *LPENUMFORMATETC;

typedef struct tagDVTARGETDEVICE
{
    DWORD tdSize;
    WORD tdDriverNameOffset;
    WORD tdDeviceNameOffset;
    WORD tdPortNameOffset;
    WORD tdExtDevmodeOffset;
    /* [size_is] */ BYTE tdData[1];
} DVTARGETDEVICE;

typedef /* [wire_marshal] */ WORD CLIPFORMAT;
typedef CLIPFORMAT *LPCLIPFORMAT;

typedef struct tagFORMATETC
{
    CLIPFORMAT cfFormat;
    /* [unique] */ DVTARGETDEVICE *ptd;
    DWORD dwAspect;
    LONG lindex;
    DWORD tymed;
} FORMATETC;

typedef struct tagFORMATETC *LPFORMATETC;

DEFINE_GUID(IID_IEnumFORMATETC, 0x00000103, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);

#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE IEnumFORMATETC
DECLARE_INTERFACE_(IEnumFORMATETC, IUnknown)
{
  public:
    DECLARE_CLASS_SIID(IID_IEnumFORMATETC)

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE Next(
        /* [in] */ ULONG celt,
        /* [annotation] */
        _Out_writes_to_(celt, *pceltFetched) FORMATETC * rgelt,
        /* [annotation] */
        _Out_opt_ ULONG * pceltFetched)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Skip(
        /* [in] */ ULONG celt)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Reset(void) = 0;

    virtual HRESULT STDMETHODCALLTYPE Clone(
        /* [out] */ __RPC__deref_out_opt IEnumFORMATETC * *ppenum)
        = 0;
};

#else /* C style interface */

typedef struct IEnumFORMATETCVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in IEnumFORMATETC *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in IEnumFORMATETC *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in IEnumFORMATETC *This);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *Next)(IEnumFORMATETC *This,
                                                   /* [in] */ ULONG celt,
                                                   /* [annotation] */
                                                   _Out_writes_to_(celt, *pceltFetched) FORMATETC *rgelt,
                                                   /* [annotation] */
                                                   _Out_opt_ ULONG *pceltFetched);

    HRESULT(STDMETHODCALLTYPE *Skip)
    (__RPC__in IEnumFORMATETC *This,
     /* [in] */ ULONG celt);

    HRESULT(STDMETHODCALLTYPE *Reset)(__RPC__in IEnumFORMATETC *This);

    HRESULT(STDMETHODCALLTYPE *Clone)
    (__RPC__in IEnumFORMATETC *This,
     /* [out] */ __RPC__deref_out_opt IEnumFORMATETC **ppenum);

    END_INTERFACE
} IEnumFORMATETCVtbl;

interface IEnumFORMATETC
{
    CONST_VTBL struct IEnumFORMATETCVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IEnumFORMATETC_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IEnumFORMATETC_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IEnumFORMATETC_Release(This) ((This)->lpVtbl->Release(This))

#define IEnumFORMATETC_Next(This, celt, rgelt, pceltFetched) ((This)->lpVtbl->Next(This, celt, rgelt, pceltFetched))

#define IEnumFORMATETC_Skip(This, celt) ((This)->lpVtbl->Skip(This, celt))

#define IEnumFORMATETC_Reset(This) ((This)->lpVtbl->Reset(This))

#define IEnumFORMATETC_Clone(This, ppenum) ((This)->lpVtbl->Clone(This, ppenum))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IEnumFORMATETC_INTERFACE_DEFINED__ */

// typedef struct tagFORMATETC *LPFORMATETC;
#ifndef __IAdviseSink_INTERFACE_DEFINED__
#define __IAdviseSink_INTERFACE_DEFINED__

/* interface IAdviseSink */
/* [unique][async_uuid][uuid][object] */

typedef struct IAdviseSink *LPADVISESINK;
struct IMoniker;
typedef /* [v1_enum] */
    enum tagTYMED
{
    TYMED_HGLOBAL = 1,
    TYMED_FILE = 2,
    TYMED_ISTREAM = 4,
    TYMED_ISTORAGE = 8,
    TYMED_GDI = 16,
    TYMED_MFPICT = 32,
    TYMED_ENHMF = 64,
    TYMED_NULL = 0
} TYMED;

#ifndef RC_INVOKED
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning(disable : 4200)
#endif
typedef struct tagRemSTGMEDIUM
{
    DWORD tymed;
    DWORD dwHandleType;
    ULONG pData;
    ULONG pUnkForRelease;
    ULONG cbData;
    /* [size_is] */ byte data[1];
} RemSTGMEDIUM;

#ifndef RC_INVOKED
#if _MSC_VER >= 1200
#pragma warning(pop)
#else
#pragma warning(default : 4200)
#endif
#endif

#ifdef NONAMELESSUNION
typedef struct tagSTGMEDIUM
{
    DWORD tymed;
    union {
        HBITMAP hBitmap;
        // HMETAFILEPICT hMetaFilePict;
        // HENHMETAFILE hEnhMetaFile;
        HGLOBAL hGlobal;
        LPOLESTR lpszFileName;
        IStream *pstm;
        IStorage *pstg;
    } u;
    IUnknown *pUnkForRelease;
} uSTGMEDIUM;
#else
typedef struct tagSTGMEDIUM
{
    DWORD tymed;
    /* [switch_is][switch_type] */ union {
        /* [case()] */ HBITMAP hBitmap;
        /* [case()] */ // HMETAFILEPICT hMetaFilePict;
        /* [case()] */ // HENHMETAFILE hEnhMetaFile;
        /* [case()] */ HGLOBAL hGlobal;
        /* [case()] */ LPOLESTR lpszFileName;
        /* [case()] */ IStream *pstm;
        /* [case()] */ IStorage *pstg;
        /* [default] */ /* Empty union arm */
    } DUMMYUNIONNAME;
    /* [unique] */ IUnknown *pUnkForRelease;
} uSTGMEDIUM;

#endif /* !NONAMELESSUNION */

// todo:hjx
#define wireHBITMAP HBITMAP
#define wireHGLOBAL HGLOBAL

typedef struct _GDI_OBJECT
{
    DWORD ObjectType;
    /* [switch_is] */ /* [switch_type] */ union __MIDL_IAdviseSink_0002 {
        /* [case()] */ wireHBITMAP hBitmap;
        /* [default] */ wireHGLOBAL hGeneric;
    } u;
} GDI_OBJECT;

typedef struct _BYTE_BLOB
{
    ULONG clSize;
    /* [size_is] */ byte abData[1];
} BYTE_BLOB;

typedef struct _userSTGMEDIUM
{
    struct _STGMEDIUM_UNION
    {
        DWORD tymed;
        /* [switch_is] */ /* [switch_type] */ union __MIDL_IAdviseSink_0003 {
            /* [case()] */ /* Empty union arm */
            /* [case()] */ // wireHMETAFILEPICT hMetaFilePict;
            /* [case()] */ // wireHENHMETAFILE hHEnhMetaFile;
            /* [case()] */ GDI_OBJECT *hGdiHandle;
            /* [case()] */ wireHGLOBAL hGlobal;
            /* [case()] */ LPOLESTR lpszFileName;
            /* [case()] */ BYTE_BLOB *pstm;
            /* [case()] */ BYTE_BLOB *pstg;
        } u;
    } DUMMYUNIONNAME;
    IUnknown *pUnkForRelease;
} userSTGMEDIUM;

typedef /* [unique] */ __RPC_unique_pointer userSTGMEDIUM *wireSTGMEDIUM;

typedef /* [wire_marshal] */ uSTGMEDIUM STGMEDIUM;

typedef /* [unique] */ __RPC_unique_pointer userSTGMEDIUM *wireASYNC_STGMEDIUM;

typedef /* [wire_marshal] */ STGMEDIUM ASYNC_STGMEDIUM;

typedef STGMEDIUM *LPSTGMEDIUM;

typedef struct _userFLAG_STGMEDIUM
{
    LONG ContextFlags;
    LONG fPassOwnership;
    userSTGMEDIUM Stgmed;
} userFLAG_STGMEDIUM;

typedef /* [unique] */ __RPC_unique_pointer userFLAG_STGMEDIUM *wireFLAG_STGMEDIUM;

typedef /* [wire_marshal] */ struct _FLAG_STGMEDIUM
{
    LONG ContextFlags;
    LONG fPassOwnership;
    STGMEDIUM Stgmed;
} FLAG_STGMEDIUM;

DEFINE_GUID(IID_IAdviseSink, 0x0000010f, 0, 0, 0xc0, 0, 0, 0, 0, 0, 0, 0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE IAdviseSink
DECLARE_INTERFACE_(IAdviseSink, IUnknown)
{
  public:
    DECLARE_CLASS_SIID(IID_IAdviseSink)

    virtual /* [local] */ void STDMETHODCALLTYPE OnDataChange(
        /* [annotation][unique][in] */
        _In_ FORMATETC * pFormatetc,
        /* [annotation][unique][in] */
        _In_ STGMEDIUM * pStgmed)
        = 0;

    virtual /* [local] */ void STDMETHODCALLTYPE OnViewChange(
        /* [in] */ DWORD dwAspect,
        /* [in] */ LONG lindex)
        = 0;

    virtual /* [local] */ void STDMETHODCALLTYPE OnRename(
        /* [annotation][in] */
        _In_ IMoniker * pmk)
        = 0;

    virtual /* [local] */ void STDMETHODCALLTYPE OnSave(void) = 0;

    virtual /* [local] */ void STDMETHODCALLTYPE OnClose(void) = 0;
};

#else /* C style interface */

typedef struct IAdviseSinkVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in IAdviseSink *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in IAdviseSink *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in IAdviseSink *This);

    /* [local] */ void(STDMETHODCALLTYPE *OnDataChange)(IAdviseSink *This,
                                                        /* [annotation][unique][in] */
                                                        _In_ FORMATETC *pFormatetc,
                                                        /* [annotation][unique][in] */
                                                        _In_ STGMEDIUM *pStgmed);

    /* [local] */ void(STDMETHODCALLTYPE *OnViewChange)(IAdviseSink *This,
                                                        /* [in] */ DWORD dwAspect,
                                                        /* [in] */ LONG lindex);

    /* [local] */ void(STDMETHODCALLTYPE *OnRename)(IAdviseSink *This,
                                                    /* [annotation][in] */
                                                    _In_ IMoniker *pmk);

    /* [local] */ void(STDMETHODCALLTYPE *OnSave)(IAdviseSink *This);

    /* [local] */ void(STDMETHODCALLTYPE *OnClose)(IAdviseSink *This);

    END_INTERFACE
} IAdviseSinkVtbl;

interface IAdviseSink
{
    CONST_VTBL struct IAdviseSinkVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IAdviseSink_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IAdviseSink_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IAdviseSink_Release(This) ((This)->lpVtbl->Release(This))

#define IAdviseSink_OnDataChange(This, pFormatetc, pStgmed) ((This)->lpVtbl->OnDataChange(This, pFormatetc, pStgmed))

#define IAdviseSink_OnViewChange(This, dwAspect, lindex) ((This)->lpVtbl->OnViewChange(This, dwAspect, lindex))

#define IAdviseSink_OnRename(This, pmk) ((This)->lpVtbl->OnRename(This, pmk))

#define IAdviseSink_OnSave(This) ((This)->lpVtbl->OnSave(This))

#define IAdviseSink_OnClose(This) ((This)->lpVtbl->OnClose(This))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IAdviseSink_INTERFACE_DEFINED__ */

#ifndef __IEnumSTATDATA_INTERFACE_DEFINED__
#define __IEnumSTATDATA_INTERFACE_DEFINED__

/* interface IEnumSTATDATA */
/* [unique][uuid][object] */

typedef /* [unique] */ struct IEnumSTATDATA *LPENUMSTATDATA;

typedef enum tagADVF
{
    ADVF_NODATA = 1,
    ADVF_PRIMEFIRST = 2,
    ADVF_ONLYONCE = 4,
    ADVF_DATAONSTOP = 64,
    ADVFCACHE_NOHANDLER = 8,
    ADVFCACHE_FORCEBUILTIN = 16,
    ADVFCACHE_ONSAVE = 32
} ADVF;

typedef struct tagSTATDATA
{
    FORMATETC formatetc;
    DWORD advf;
    /* [unique] */ IAdviseSink *pAdvSink;
    DWORD dwConnection;
} STATDATA;

typedef STATDATA *LPSTATDATA;

DEFINE_GUID(IID_IEnumSTATDATA, 0x00000105, 0, 0, 0xc0, 0, 0, 0, 0, 0, 0, 0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE IEnumSTATDATA
DECLARE_INTERFACE_(IEnumSTATDATA, IUnknown)
{
  public:
    DECLARE_CLASS_SIID(IID_IEnumSTATDATA)

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE Next(
        /* [in] */ ULONG celt,
        /* [annotation] */
        _Out_writes_to_(celt, *pceltFetched) STATDATA * rgelt,
        /* [annotation] */
        _Out_opt_ ULONG * pceltFetched)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Skip(
        /* [in] */ ULONG celt)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Reset(void) = 0;

    virtual HRESULT STDMETHODCALLTYPE Clone(
        /* [out] */ __RPC__deref_out_opt IEnumSTATDATA * *ppenum)
        = 0;
};

#else /* C style interface */

typedef struct IEnumSTATDATAVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in IEnumSTATDATA *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in IEnumSTATDATA *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in IEnumSTATDATA *This);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *Next)(IEnumSTATDATA *This,
                                                   /* [in] */ ULONG celt,
                                                   /* [annotation] */
                                                   _Out_writes_to_(celt, *pceltFetched) STATDATA *rgelt,
                                                   /* [annotation] */
                                                   _Out_opt_ ULONG *pceltFetched);

    HRESULT(STDMETHODCALLTYPE *Skip)
    (__RPC__in IEnumSTATDATA *This,
     /* [in] */ ULONG celt);

    HRESULT(STDMETHODCALLTYPE *Reset)(__RPC__in IEnumSTATDATA *This);

    HRESULT(STDMETHODCALLTYPE *Clone)
    (__RPC__in IEnumSTATDATA *This,
     /* [out] */ __RPC__deref_out_opt IEnumSTATDATA **ppenum);

    END_INTERFACE
} IEnumSTATDATAVtbl;

interface IEnumSTATDATA
{
    CONST_VTBL struct IEnumSTATDATAVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IEnumSTATDATA_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IEnumSTATDATA_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IEnumSTATDATA_Release(This) ((This)->lpVtbl->Release(This))

#define IEnumSTATDATA_Next(This, celt, rgelt, pceltFetched) ((This)->lpVtbl->Next(This, celt, rgelt, pceltFetched))

#define IEnumSTATDATA_Skip(This, celt) ((This)->lpVtbl->Skip(This, celt))

#define IEnumSTATDATA_Reset(This) ((This)->lpVtbl->Reset(This))

#define IEnumSTATDATA_Clone(This, ppenum) ((This)->lpVtbl->Clone(This, ppenum))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IEnumSTATDATA_INTERFACE_DEFINED__ */

#ifndef __IDataObject_INTERFACE_DEFINED__
#define __IDataObject_INTERFACE_DEFINED__

/* interface IDataObject */
/* [unique][uuid][object] */

typedef /* [unique] */ struct IDataObject *LPDATAOBJECT;

typedef enum tagDATADIR
{
    DATADIR_GET = 1,
    DATADIR_SET = 2
} DATADIR;

DEFINE_GUID(IID_IDataObject, 0x0000010e, 0, 0, 0xc0, 0, 0, 0, 0, 0, 0, 0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE IDataObject
DECLARE_INTERFACE_(IDataObject, IUnknown)
{
  public:
    DECLARE_CLASS_SIID(IID_IDataObject)

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetData(
        /* [annotation][unique][in] */
        _In_ FORMATETC * pformatetcIn,
        /* [annotation][out] */
        _Out_ STGMEDIUM * pmedium)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetDataHere(
        /* [annotation][unique][in] */
        _In_ FORMATETC * pformatetc,
        /* [annotation][out][in] */
        _Inout_ STGMEDIUM * pmedium)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE QueryGetData(
        /* [unique][in] */ __RPC__in_opt FORMATETC * pformatetc)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetCanonicalFormatEtc(
        /* [unique][in] */ __RPC__in_opt FORMATETC * pformatectIn,
        /* [out] */ __RPC__out FORMATETC * pformatetcOut)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetData(
        /* [annotation][unique][in] */
        _In_ FORMATETC * pformatetc,
        /* [annotation][unique][in] */
        _In_ STGMEDIUM * pmedium,
        /* [in] */ BOOL fRelease)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE EnumFormatEtc(
        /* [in] */ DWORD dwDirection,
        /* [out] */ __RPC__deref_out_opt IEnumFORMATETC * *ppenumFormatEtc)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE DAdvise(
        /* [in] */ __RPC__in FORMATETC * pformatetc,
        /* [in] */ DWORD advf,
        /* [unique][in] */ __RPC__in_opt IAdviseSink * pAdvSink,
        /* [out] */ __RPC__out DWORD * pdwConnection)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE DUnadvise(
        /* [in] */ DWORD dwConnection)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE EnumDAdvise(
        /* [out] */ __RPC__deref_out_opt IEnumSTATDATA * *ppenumAdvise)
        = 0;
};

#else /* C style interface */

typedef struct IDataObjectVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in IDataObject *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in IDataObject *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in IDataObject *This);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *GetData)(IDataObject *This,
                                                      /* [annotation][unique][in] */
                                                      _In_ FORMATETC *pformatetcIn,
                                                      /* [annotation][out] */
                                                      _Out_ STGMEDIUM *pmedium);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *GetDataHere)(IDataObject *This,
                                                          /* [annotation][unique][in] */
                                                          _In_ FORMATETC *pformatetc,
                                                          /* [annotation][out][in] */
                                                          _Inout_ STGMEDIUM *pmedium);

    HRESULT(STDMETHODCALLTYPE *QueryGetData)
    (__RPC__in IDataObject *This,
     /* [unique][in] */ __RPC__in_opt FORMATETC *pformatetc);

    HRESULT(STDMETHODCALLTYPE *GetCanonicalFormatEtc)
    (__RPC__in IDataObject *This,
     /* [unique][in] */ __RPC__in_opt FORMATETC *pformatectIn,
     /* [out] */ __RPC__out FORMATETC *pformatetcOut);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *SetData)(IDataObject *This,
                                                      /* [annotation][unique][in] */
                                                      _In_ FORMATETC *pformatetc,
                                                      /* [annotation][unique][in] */
                                                      _In_ STGMEDIUM *pmedium,
                                                      /* [in] */ BOOL fRelease);

    HRESULT(STDMETHODCALLTYPE *EnumFormatEtc)
    (__RPC__in IDataObject *This,
     /* [in] */ DWORD dwDirection,
     /* [out] */ __RPC__deref_out_opt IEnumFORMATETC **ppenumFormatEtc);

    HRESULT(STDMETHODCALLTYPE *DAdvise)
    (__RPC__in IDataObject *This,
     /* [in] */ __RPC__in FORMATETC *pformatetc,
     /* [in] */ DWORD advf,
     /* [unique][in] */ __RPC__in_opt IAdviseSink *pAdvSink,
     /* [out] */ __RPC__out DWORD *pdwConnection);

    HRESULT(STDMETHODCALLTYPE *DUnadvise)
    (__RPC__in IDataObject *This,
     /* [in] */ DWORD dwConnection);

    HRESULT(STDMETHODCALLTYPE *EnumDAdvise)
    (__RPC__in IDataObject *This,
     /* [out] */ __RPC__deref_out_opt IEnumSTATDATA **ppenumAdvise);

    END_INTERFACE
} IDataObjectVtbl;

interface IDataObject
{
    CONST_VTBL struct IDataObjectVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IDataObject_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IDataObject_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IDataObject_Release(This) ((This)->lpVtbl->Release(This))

#define IDataObject_GetData(This, pformatetcIn, pmedium) ((This)->lpVtbl->GetData(This, pformatetcIn, pmedium))

#define IDataObject_GetDataHere(This, pformatetc, pmedium) ((This)->lpVtbl->GetDataHere(This, pformatetc, pmedium))

#define IDataObject_QueryGetData(This, pformatetc) ((This)->lpVtbl->QueryGetData(This, pformatetc))

#define IDataObject_GetCanonicalFormatEtc(This, pformatectIn, pformatetcOut) ((This)->lpVtbl->GetCanonicalFormatEtc(This, pformatectIn, pformatetcOut))

#define IDataObject_SetData(This, pformatetc, pmedium, fRelease) ((This)->lpVtbl->SetData(This, pformatetc, pmedium, fRelease))

#define IDataObject_EnumFormatEtc(This, dwDirection, ppenumFormatEtc) ((This)->lpVtbl->EnumFormatEtc(This, dwDirection, ppenumFormatEtc))

#define IDataObject_DAdvise(This, pformatetc, advf, pAdvSink, pdwConnection) ((This)->lpVtbl->DAdvise(This, pformatetc, advf, pAdvSink, pdwConnection))

#define IDataObject_DUnadvise(This, dwConnection) ((This)->lpVtbl->DUnadvise(This, dwConnection))

#define IDataObject_EnumDAdvise(This, ppenumAdvise) ((This)->lpVtbl->EnumDAdvise(This, ppenumAdvise))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IDataObject_INTERFACE_DEFINED__ */

#ifndef __IMalloc_INTERFACE_DEFINED__
#define __IMalloc_INTERFACE_DEFINED__

/* interface IMalloc */
/* [uuid][object][local] */

typedef struct IMalloc *LPMALLOC;

DEFINE_GUID(IID_IMalloc, 0x00000002, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE IMalloc
DECLARE_INTERFACE_(IMalloc, IUnknown)
{
    DECLARE_CLASS_SIID(IID_IMalloc)
  public:
    virtual void *STDMETHODCALLTYPE Alloc(
        /* [annotation][in] */
        _In_ SIZE_T cb)
        = 0;

    virtual void *STDMETHODCALLTYPE Realloc(
        /* [annotation][in] */
        _In_opt_ void *pv,
        /* [annotation][in] */
        _In_ SIZE_T cb)
        = 0;

    virtual void STDMETHODCALLTYPE Free(
        /* [annotation][in] */
        _In_opt_ void *pv)
        = 0;

    virtual SIZE_T STDMETHODCALLTYPE GetSize(
        /* [annotation][in] */
        _In_opt_ _Post_writable_byte_size_(return ) void *pv)
        = 0;

    virtual int STDMETHODCALLTYPE DidAlloc(
        /* [annotation][in] */
        _In_opt_ void *pv)
        = 0;

    virtual void STDMETHODCALLTYPE HeapMinimize(void) = 0;
};

#else /* C style interface */

typedef struct IMallocVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (IMalloc *This,
     /* [in] */ REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(IMalloc *This);

    ULONG(STDMETHODCALLTYPE *Release)(IMalloc *This);

    void *(STDMETHODCALLTYPE *Alloc)(IMalloc *This,
                                     /* [annotation][in] */
                                     _In_ SIZE_T cb);

    void *(STDMETHODCALLTYPE *Realloc)(IMalloc *This,
                                       /* [annotation][in] */
                                       _In_opt_ void *pv,
                                       /* [annotation][in] */
                                       _In_ SIZE_T cb);

    void(STDMETHODCALLTYPE *Free)(IMalloc *This,
                                  /* [annotation][in] */
                                  _In_opt_ void *pv);

    SIZE_T(STDMETHODCALLTYPE *GetSize)
    (IMalloc *This,
     /* [annotation][in] */
     _In_opt_ _Post_writable_byte_size_(return ) void *pv);

    int(STDMETHODCALLTYPE *DidAlloc)(IMalloc *This,
                                     /* [annotation][in] */
                                     _In_opt_ void *pv);

    void(STDMETHODCALLTYPE *HeapMinimize)(IMalloc *This);

    END_INTERFACE
} IMallocVtbl;

interface IMalloc
{
    CONST_VTBL struct IMallocVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IMalloc_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IMalloc_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IMalloc_Release(This) ((This)->lpVtbl->Release(This))

#define IMalloc_Alloc(This, cb) ((This)->lpVtbl->Alloc(This, cb))

#define IMalloc_Realloc(This, pv, cb) ((This)->lpVtbl->Realloc(This, pv, cb))

#define IMalloc_Free(This, pv) ((This)->lpVtbl->Free(This, pv))

#define IMalloc_GetSize(This, pv) ((This)->lpVtbl->GetSize(This, pv))

#define IMalloc_DidAlloc(This, pv) ((This)->lpVtbl->DidAlloc(This, pv))

#define IMalloc_HeapMinimize(This) ((This)->lpVtbl->HeapMinimize(This))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IMalloc_INTERFACE_DEFINED__ */

#ifndef __IMallocSpy_INTERFACE_DEFINED__
#define __IMallocSpy_INTERFACE_DEFINED__

/* interface IMallocSpy */
/* [uuid][object][local] */

typedef struct IMallocSpy *LPMALLOCSPY;

DEFINE_GUID(IID_IMallocSpy, 0x0000001d, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);

#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE IMallocSpy
DECLARE_INTERFACE_(IMallocSpy, IUnknown)
{
    DECLARE_CLASS_SIID(IID_IMallocSpy)
  public:
    virtual SIZE_T STDMETHODCALLTYPE PreAlloc(
        /* [annotation][in] */
        _In_ SIZE_T cbRequest)
        = 0;

    virtual void *STDMETHODCALLTYPE PostAlloc(
        /* [annotation][in] */
        _In_ void *pActual)
        = 0;

    virtual void *STDMETHODCALLTYPE PreFree(
        /* [annotation][in] */
        _In_ void *pRequest,
        /* [annotation][in] */
        _In_ BOOL fSpyed)
        = 0;

    virtual void STDMETHODCALLTYPE PostFree(
        /* [annotation][in] */
        _In_ BOOL fSpyed)
        = 0;

    virtual SIZE_T STDMETHODCALLTYPE PreRealloc(
        /* [annotation][in] */
        _In_ void *pRequest,
        /* [annotation][in] */
        _In_ SIZE_T cbRequest,
        /* [annotation][out] */
        _Outptr_ void **ppNewRequest,
        /* [annotation][in] */
        _In_ BOOL fSpyed)
        = 0;

    virtual void *STDMETHODCALLTYPE PostRealloc(
        /* [annotation][in] */
        _In_ void *pActual,
        /* [annotation][in] */
        _In_ BOOL fSpyed)
        = 0;

    virtual void *STDMETHODCALLTYPE PreGetSize(
        /* [annotation][in] */
        _In_ void *pRequest,
        /* [annotation][in] */
        _In_ BOOL fSpyed)
        = 0;

    virtual SIZE_T STDMETHODCALLTYPE PostGetSize(
        /* [annotation][in] */
        _In_ SIZE_T cbActual,
        /* [annotation][in] */
        _In_ BOOL fSpyed)
        = 0;

    virtual void *STDMETHODCALLTYPE PreDidAlloc(
        /* [annotation][in] */
        _In_ void *pRequest,
        /* [annotation][in] */
        _In_ BOOL fSpyed)
        = 0;

    virtual int STDMETHODCALLTYPE PostDidAlloc(
        /* [annotation][in] */
        _In_ void *pRequest,
        /* [annotation][in] */
        _In_ BOOL fSpyed,
        /* [annotation][in] */
        _In_ int fActual)
        = 0;

    virtual void STDMETHODCALLTYPE PreHeapMinimize(void) = 0;

    virtual void STDMETHODCALLTYPE PostHeapMinimize(void) = 0;
};

#else /* C style interface */

typedef struct IMallocSpyVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (IMallocSpy *This,
     /* [in] */ REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(IMallocSpy *This);

    ULONG(STDMETHODCALLTYPE *Release)(IMallocSpy *This);

    SIZE_T(STDMETHODCALLTYPE *PreAlloc)
    (IMallocSpy *This,
     /* [annotation][in] */
     _In_ SIZE_T cbRequest);

    void *(STDMETHODCALLTYPE *PostAlloc)(IMallocSpy *This,
                                         /* [annotation][in] */
                                         _In_ void *pActual);

    void *(STDMETHODCALLTYPE *PreFree)(IMallocSpy *This,
                                       /* [annotation][in] */
                                       _In_ void *pRequest,
                                       /* [annotation][in] */
                                       _In_ BOOL fSpyed);

    void(STDMETHODCALLTYPE *PostFree)(IMallocSpy *This,
                                      /* [annotation][in] */
                                      _In_ BOOL fSpyed);

    SIZE_T(STDMETHODCALLTYPE *PreRealloc)
    (IMallocSpy *This,
     /* [annotation][in] */
     _In_ void *pRequest,
     /* [annotation][in] */
     _In_ SIZE_T cbRequest,
     /* [annotation][out] */
     _Outptr_ void **ppNewRequest,
     /* [annotation][in] */
     _In_ BOOL fSpyed);

    void *(STDMETHODCALLTYPE *PostRealloc)(IMallocSpy *This,
                                           /* [annotation][in] */
                                           _In_ void *pActual,
                                           /* [annotation][in] */
                                           _In_ BOOL fSpyed);

    void *(STDMETHODCALLTYPE *PreGetSize)(IMallocSpy *This,
                                          /* [annotation][in] */
                                          _In_ void *pRequest,
                                          /* [annotation][in] */
                                          _In_ BOOL fSpyed);

    SIZE_T(STDMETHODCALLTYPE *PostGetSize)
    (IMallocSpy *This,
     /* [annotation][in] */
     _In_ SIZE_T cbActual,
     /* [annotation][in] */
     _In_ BOOL fSpyed);

    void *(STDMETHODCALLTYPE *PreDidAlloc)(IMallocSpy *This,
                                           /* [annotation][in] */
                                           _In_ void *pRequest,
                                           /* [annotation][in] */
                                           _In_ BOOL fSpyed);

    int(STDMETHODCALLTYPE *PostDidAlloc)(IMallocSpy *This,
                                         /* [annotation][in] */
                                         _In_ void *pRequest,
                                         /* [annotation][in] */
                                         _In_ BOOL fSpyed,
                                         /* [annotation][in] */
                                         _In_ int fActual);

    void(STDMETHODCALLTYPE *PreHeapMinimize)(IMallocSpy *This);

    void(STDMETHODCALLTYPE *PostHeapMinimize)(IMallocSpy *This);

    END_INTERFACE
} IMallocSpyVtbl;

interface IMallocSpy
{
    CONST_VTBL struct IMallocSpyVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IMallocSpy_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IMallocSpy_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IMallocSpy_Release(This) ((This)->lpVtbl->Release(This))

#define IMallocSpy_PreAlloc(This, cbRequest) ((This)->lpVtbl->PreAlloc(This, cbRequest))

#define IMallocSpy_PostAlloc(This, pActual) ((This)->lpVtbl->PostAlloc(This, pActual))

#define IMallocSpy_PreFree(This, pRequest, fSpyed) ((This)->lpVtbl->PreFree(This, pRequest, fSpyed))

#define IMallocSpy_PostFree(This, fSpyed) ((This)->lpVtbl->PostFree(This, fSpyed))

#define IMallocSpy_PreRealloc(This, pRequest, cbRequest, ppNewRequest, fSpyed) ((This)->lpVtbl->PreRealloc(This, pRequest, cbRequest, ppNewRequest, fSpyed))

#define IMallocSpy_PostRealloc(This, pActual, fSpyed) ((This)->lpVtbl->PostRealloc(This, pActual, fSpyed))

#define IMallocSpy_PreGetSize(This, pRequest, fSpyed) ((This)->lpVtbl->PreGetSize(This, pRequest, fSpyed))

#define IMallocSpy_PostGetSize(This, cbActual, fSpyed) ((This)->lpVtbl->PostGetSize(This, cbActual, fSpyed))

#define IMallocSpy_PreDidAlloc(This, pRequest, fSpyed) ((This)->lpVtbl->PreDidAlloc(This, pRequest, fSpyed))

#define IMallocSpy_PostDidAlloc(This, pRequest, fSpyed, fActual) ((This)->lpVtbl->PostDidAlloc(This, pRequest, fSpyed, fActual))

#define IMallocSpy_PreHeapMinimize(This) ((This)->lpVtbl->PreHeapMinimize(This))

#define IMallocSpy_PostHeapMinimize(This) ((This)->lpVtbl->PostHeapMinimize(This))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IMallocSpy_INTERFACE_DEFINED__ */

#ifndef __IEnumString_INTERFACE_DEFINED__
#define __IEnumString_INTERFACE_DEFINED__

/* interface IEnumString */
/* [unique][uuid][object] */

typedef /* [unique] */ __RPC_unique_pointer struct IEnumString *LPENUMSTRING;

#if defined(__cplusplus) && !defined(CINTERFACE)
DEFINE_GUID(IID_IEnumString, 0x00000101, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
struct IEnumString : public IUnknown
{
  public:
    virtual /* [local] */ HRESULT STDMETHODCALLTYPE Next(
        /* [in] */ ULONG celt,
        /* [annotation] */
        _Out_writes_to_(celt, *pceltFetched) LPOLESTR *rgelt,
        /* [annotation] */
        _Out_opt_ ULONG *pceltFetched)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Skip(
        /* [in] */ ULONG celt)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Reset(void) = 0;

    virtual HRESULT STDMETHODCALLTYPE Clone(
        /* [out] */ __RPC__deref_out_opt IEnumString **ppenum)
        = 0;
};

#else /* C style interface */

typedef struct IEnumStringVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in IEnumString *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in IEnumString *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in IEnumString *This);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *Next)(IEnumString *This,
                                                   /* [in] */ ULONG celt,
                                                   /* [annotation] */
                                                   _Out_writes_to_(celt, *pceltFetched) LPOLESTR *rgelt,
                                                   /* [annotation] */
                                                   _Out_opt_ ULONG *pceltFetched);

    HRESULT(STDMETHODCALLTYPE *Skip)
    (__RPC__in IEnumString *This,
     /* [in] */ ULONG celt);

    HRESULT(STDMETHODCALLTYPE *Reset)(__RPC__in IEnumString *This);

    HRESULT(STDMETHODCALLTYPE *Clone)
    (__RPC__in IEnumString *This,
     /* [out] */ __RPC__deref_out_opt IEnumString **ppenum);

    END_INTERFACE
} IEnumStringVtbl;

interface IEnumString
{
    CONST_VTBL struct IEnumStringVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IEnumString_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IEnumString_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IEnumString_Release(This) ((This)->lpVtbl->Release(This))

#define IEnumString_Next(This, celt, rgelt, pceltFetched) ((This)->lpVtbl->Next(This, celt, rgelt, pceltFetched))

#define IEnumString_Skip(This, celt) ((This)->lpVtbl->Skip(This, celt))

#define IEnumString_Reset(This) ((This)->lpVtbl->Reset(This))

#define IEnumString_Clone(This, ppenum) ((This)->lpVtbl->Clone(This, ppenum))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IEnumString_INTERFACE_DEFINED__ */

#ifndef __IPersist_INTERFACE_DEFINED__
#define __IPersist_INTERFACE_DEFINED__

/* interface IPersist */
/* [uuid][object] */

typedef /* [unique] */ __RPC_unique_pointer struct IPersist *LPPERSIST;

#if defined(__cplusplus) && !defined(CINTERFACE)

DEFINE_GUID(IID_IPersist, 0x0000010c, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
struct IPersist : public IUnknown
{
  public:
    virtual HRESULT STDMETHODCALLTYPE GetClassID(
        /* [out] */ __RPC__out CLSID *pClassID)
        = 0;
};

#else /* C style interface */

typedef struct IPersistVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in IPersist *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in IPersist *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in IPersist *This);

    HRESULT(STDMETHODCALLTYPE *GetClassID)
    (__RPC__in IPersist *This,
     /* [out] */ __RPC__out CLSID *pClassID);

    END_INTERFACE
} IPersistVtbl;

interface IPersist
{
    CONST_VTBL struct IPersistVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IPersist_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IPersist_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IPersist_Release(This) ((This)->lpVtbl->Release(This))

#define IPersist_GetClassID(This, pClassID) ((This)->lpVtbl->GetClassID(This, pClassID))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IPersist_INTERFACE_DEFINED__ */

#ifndef __IPersistStorage_INTERFACE_DEFINED__
#define __IPersistStorage_INTERFACE_DEFINED__

/* interface IPersistStorage */
/* [unique][uuid][object] */

typedef /* [unique] */ __RPC_unique_pointer struct IPersistStorage *LPPERSISTSTORAGE;

#if defined(__cplusplus) && !defined(CINTERFACE)

DEFINE_GUID(IID_IPersistStorage, 0x0000010a, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
struct IPersistStorage : public IPersist
{
  public:
    virtual HRESULT STDMETHODCALLTYPE IsDirty(void) = 0;

    virtual HRESULT STDMETHODCALLTYPE InitNew(
        /* [unique][in] */ __RPC__in_opt IStorage *pStg)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Load(
        /* [unique][in] */ __RPC__in_opt IStorage *pStg)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Save(
        /* [unique][in] */ __RPC__in_opt IStorage *pStgSave,
        /* [in] */ BOOL fSameAsLoad)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE SaveCompleted(
        /* [unique][in] */ __RPC__in_opt IStorage *pStgNew)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE HandsOffStorage(void) = 0;
};

#else /* C style interface */

typedef struct IPersistStorageVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in IPersistStorage *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in IPersistStorage *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in IPersistStorage *This);

    HRESULT(STDMETHODCALLTYPE *GetClassID)
    (__RPC__in IPersistStorage *This,
     /* [out] */ __RPC__out CLSID *pClassID);

    HRESULT(STDMETHODCALLTYPE *IsDirty)(__RPC__in IPersistStorage *This);

    HRESULT(STDMETHODCALLTYPE *InitNew)
    (__RPC__in IPersistStorage *This,
     /* [unique][in] */ __RPC__in_opt IStorage *pStg);

    HRESULT(STDMETHODCALLTYPE *Load)
    (__RPC__in IPersistStorage *This,
     /* [unique][in] */ __RPC__in_opt IStorage *pStg);

    HRESULT(STDMETHODCALLTYPE *Save)
    (__RPC__in IPersistStorage *This,
     /* [unique][in] */ __RPC__in_opt IStorage *pStgSave,
     /* [in] */ BOOL fSameAsLoad);

    HRESULT(STDMETHODCALLTYPE *SaveCompleted)
    (__RPC__in IPersistStorage *This,
     /* [unique][in] */ __RPC__in_opt IStorage *pStgNew);

    HRESULT(STDMETHODCALLTYPE *HandsOffStorage)(__RPC__in IPersistStorage *This);

    END_INTERFACE
} IPersistStorageVtbl;

interface IPersistStorage
{
    CONST_VTBL struct IPersistStorageVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IPersistStorage_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IPersistStorage_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IPersistStorage_Release(This) ((This)->lpVtbl->Release(This))

#define IPersistStorage_GetClassID(This, pClassID) ((This)->lpVtbl->GetClassID(This, pClassID))

#define IPersistStorage_IsDirty(This) ((This)->lpVtbl->IsDirty(This))

#define IPersistStorage_InitNew(This, pStg) ((This)->lpVtbl->InitNew(This, pStg))

#define IPersistStorage_Load(This, pStg) ((This)->lpVtbl->Load(This, pStg))

#define IPersistStorage_Save(This, pStgSave, fSameAsLoad) ((This)->lpVtbl->Save(This, pStgSave, fSameAsLoad))

#define IPersistStorage_SaveCompleted(This, pStgNew) ((This)->lpVtbl->SaveCompleted(This, pStgNew))

#define IPersistStorage_HandsOffStorage(This) ((This)->lpVtbl->HandsOffStorage(This))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IPersistStorage_INTERFACE_DEFINED__ */

#ifndef __IPersistStream_INTERFACE_DEFINED__
#define __IPersistStream_INTERFACE_DEFINED__

/* interface IPersistStream */
/* [unique][uuid][object] */

typedef /* [unique] */ __RPC_unique_pointer struct IPersistStream *LPPERSISTSTREAM;

DEFINE_GUID(IID_IPersistStream, 0x00000109, 0, 0, 0xc0, 0, 0, 0, 0, 0, 0, 0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE IPersistStream
DECLARE_INTERFACE_(IPersistStream, IPersist)
{
  public:
    DECLARE_CLASS_SIID(IID_IPersistStream)

    virtual HRESULT STDMETHODCALLTYPE IsDirty(void) = 0;

    virtual HRESULT STDMETHODCALLTYPE Load(
        /* [unique][in] */ __RPC__in_opt IStream * pStm)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Save(
        /* [unique][in] */ __RPC__in_opt IStream * pStm,
        /* [in] */ BOOL fClearDirty)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetSizeMax(
        /* [out] */ __RPC__out ULARGE_INTEGER * pcbSize)
        = 0;
};

#else /* C style interface */

typedef struct IPersistStreamVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in IPersistStream *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in IPersistStream *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in IPersistStream *This);

    HRESULT(STDMETHODCALLTYPE *GetClassID)
    (__RPC__in IPersistStream *This,
     /* [out] */ __RPC__out CLSID *pClassID);

    HRESULT(STDMETHODCALLTYPE *IsDirty)(__RPC__in IPersistStream *This);

    HRESULT(STDMETHODCALLTYPE *Load)
    (__RPC__in IPersistStream *This,
     /* [unique][in] */ __RPC__in_opt IStream *pStm);

    HRESULT(STDMETHODCALLTYPE *Save)
    (__RPC__in IPersistStream *This,
     /* [unique][in] */ __RPC__in_opt IStream *pStm,
     /* [in] */ BOOL fClearDirty);

    HRESULT(STDMETHODCALLTYPE *GetSizeMax)
    (__RPC__in IPersistStream *This,
     /* [out] */ __RPC__out ULARGE_INTEGER *pcbSize);

    END_INTERFACE
} IPersistStreamVtbl;

interface IPersistStream
{
    CONST_VTBL struct IPersistStreamVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IPersistStream_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IPersistStream_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IPersistStream_Release(This) ((This)->lpVtbl->Release(This))

#define IPersistStream_GetClassID(This, pClassID) ((This)->lpVtbl->GetClassID(This, pClassID))

#define IPersistStream_IsDirty(This) ((This)->lpVtbl->IsDirty(This))

#define IPersistStream_Load(This, pStm) ((This)->lpVtbl->Load(This, pStm))

#define IPersistStream_Save(This, pStm, fClearDirty) ((This)->lpVtbl->Save(This, pStm, fClearDirty))

#define IPersistStream_GetSizeMax(This, pcbSize) ((This)->lpVtbl->GetSizeMax(This, pcbSize))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IPersistStream_INTERFACE_DEFINED__ */

#ifndef __IRunningObjectTable_INTERFACE_DEFINED__
#define __IRunningObjectTable_INTERFACE_DEFINED__

/* interface IRunningObjectTable */
/* [uuid][object] */

typedef /* [unique] */ __RPC_unique_pointer struct IRunningObjectTable *LPRUNNINGOBJECTTABLE;

struct IMoniker;
struct IEnumMoniker;
#if defined(__cplusplus) && !defined(CINTERFACE)

DEFINE_GUID(IID_IRunningObjectTable, 0x00000010, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
struct IRunningObjectTable : public IUnknown
{
  public:
    virtual HRESULT STDMETHODCALLTYPE Register(
        /* [in] */ DWORD grfFlags,
        /* [unique][in] */ __RPC__in_opt IUnknown *punkObject,
        /* [unique][in] */ __RPC__in_opt IMoniker *pmkObjectName,
        /* [out] */ __RPC__out DWORD *pdwRegister)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Revoke(
        /* [in] */ DWORD dwRegister)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE IsRunning(
        /* [unique][in] */ __RPC__in_opt IMoniker *pmkObjectName)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetObject(
        /* [unique][in] */ __RPC__in_opt IMoniker *pmkObjectName,
        /* [out] */ __RPC__deref_out_opt IUnknown **ppunkObject)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE NoteChangeTime(
        /* [in] */ DWORD dwRegister,
        /* [in] */ __RPC__in FILETIME *pfiletime)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetTimeOfLastChange(
        /* [unique][in] */ __RPC__in_opt IMoniker *pmkObjectName,
        /* [out] */ __RPC__out FILETIME *pfiletime)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE EnumRunning(
        /* [out] */ __RPC__deref_out_opt IEnumMoniker **ppenumMoniker)
        = 0;
};

#else /* C style interface */

typedef struct IRunningObjectTableVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in IRunningObjectTable *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in IRunningObjectTable *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in IRunningObjectTable *This);

    HRESULT(STDMETHODCALLTYPE *Register)
    (__RPC__in IRunningObjectTable *This,
     /* [in] */ DWORD grfFlags,
     /* [unique][in] */ __RPC__in_opt IUnknown *punkObject,
     /* [unique][in] */ __RPC__in_opt IMoniker *pmkObjectName,
     /* [out] */ __RPC__out DWORD *pdwRegister);

    HRESULT(STDMETHODCALLTYPE *Revoke)
    (__RPC__in IRunningObjectTable *This,
     /* [in] */ DWORD dwRegister);

    HRESULT(STDMETHODCALLTYPE *IsRunning)
    (__RPC__in IRunningObjectTable *This,
     /* [unique][in] */ __RPC__in_opt IMoniker *pmkObjectName);

    HRESULT(STDMETHODCALLTYPE *GetObject)
    (__RPC__in IRunningObjectTable *This,
     /* [unique][in] */ __RPC__in_opt IMoniker *pmkObjectName,
     /* [out] */ __RPC__deref_out_opt IUnknown **ppunkObject);

    HRESULT(STDMETHODCALLTYPE *NoteChangeTime)
    (__RPC__in IRunningObjectTable *This,
     /* [in] */ DWORD dwRegister,
     /* [in] */ __RPC__in FILETIME *pfiletime);

    HRESULT(STDMETHODCALLTYPE *GetTimeOfLastChange)
    (__RPC__in IRunningObjectTable *This,
     /* [unique][in] */ __RPC__in_opt IMoniker *pmkObjectName,
     /* [out] */ __RPC__out FILETIME *pfiletime);

    HRESULT(STDMETHODCALLTYPE *EnumRunning)
    (__RPC__in IRunningObjectTable *This,
     /* [out] */ __RPC__deref_out_opt IEnumMoniker **ppenumMoniker);

    END_INTERFACE
} IRunningObjectTableVtbl;

interface IRunningObjectTable
{
    CONST_VTBL struct IRunningObjectTableVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IRunningObjectTable_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IRunningObjectTable_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IRunningObjectTable_Release(This) ((This)->lpVtbl->Release(This))

#define IRunningObjectTable_Register(This, grfFlags, punkObject, pmkObjectName, pdwRegister) ((This)->lpVtbl->Register(This, grfFlags, punkObject, pmkObjectName, pdwRegister))

#define IRunningObjectTable_Revoke(This, dwRegister) ((This)->lpVtbl->Revoke(This, dwRegister))

#define IRunningObjectTable_IsRunning(This, pmkObjectName) ((This)->lpVtbl->IsRunning(This, pmkObjectName))

#define IRunningObjectTable_GetObject(This, pmkObjectName, ppunkObject) ((This)->lpVtbl->GetObject(This, pmkObjectName, ppunkObject))

#define IRunningObjectTable_NoteChangeTime(This, dwRegister, pfiletime) ((This)->lpVtbl->NoteChangeTime(This, dwRegister, pfiletime))

#define IRunningObjectTable_GetTimeOfLastChange(This, pmkObjectName, pfiletime) ((This)->lpVtbl->GetTimeOfLastChange(This, pmkObjectName, pfiletime))

#define IRunningObjectTable_EnumRunning(This, ppenumMoniker) ((This)->lpVtbl->EnumRunning(This, ppenumMoniker))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IRunningObjectTable_INTERFACE_DEFINED__ */

#ifndef __IBindCtx_INTERFACE_DEFINED__
#define __IBindCtx_INTERFACE_DEFINED__

#define _Struct_size_bytes_(x)

typedef struct _COAUTHIDENTITY
{
    /* [size_is] */ USHORT *User;
    /* [range] */ ULONG UserLength;
    /* [size_is] */ USHORT *Domain;
    /* [range] */ ULONG DomainLength;
    /* [size_is] */ USHORT *Password;
    /* [range] */ ULONG PasswordLength;
    ULONG Flags;
} COAUTHIDENTITY;

typedef struct _COAUTHINFO
{
    DWORD dwAuthnSvc;
    DWORD dwAuthzSvc;
    LPWSTR pwszServerPrincName;
    DWORD dwAuthnLevel;
    DWORD dwImpersonationLevel;
    COAUTHIDENTITY *pAuthIdentityData;
    DWORD dwCapabilities;
} COAUTHINFO;

typedef struct _COSERVERINFO
{
    DWORD dwReserved1;
    LPWSTR pwszName;
    COAUTHINFO *pAuthInfo;
    DWORD dwReserved2;
} COSERVERINFO;

/* interface IBindCtx */
/* [unique][uuid][object] */

typedef /* [unique] */ __RPC_unique_pointer struct IBindCtx *LPBC;

typedef /* [unique] */ __RPC_unique_pointer struct IBindCtx *LPBINDCTX;

#if defined(__cplusplus)
typedef _Struct_size_bytes_(cbStruct) struct tagBIND_OPTS
{
    DWORD cbStruct;
    DWORD grfFlags;
    DWORD grfMode;
    DWORD dwTickCountDeadline;
} BIND_OPTS, *LPBIND_OPTS;
#else
typedef struct tagBIND_OPTS
{
    DWORD cbStruct;
    DWORD grfFlags;
    DWORD grfMode;
    DWORD dwTickCountDeadline;
} BIND_OPTS;

typedef struct tagBIND_OPTS *LPBIND_OPTS;

#endif
#if defined(__cplusplus)
typedef struct tagBIND_OPTS2 : tagBIND_OPTS
{
    DWORD dwTrackFlags;
    DWORD dwClassContext;
    LCID locale;
    COSERVERINFO *pServerInfo;
} BIND_OPTS2, *LPBIND_OPTS2;
#else

typedef struct tagBIND_OPTS2
{
    DWORD cbStruct;
    DWORD grfFlags;
    DWORD grfMode;
    DWORD dwTickCountDeadline;
    DWORD dwTrackFlags;
    DWORD dwClassContext;
    LCID locale;
    COSERVERINFO *pServerInfo;
} BIND_OPTS2;

typedef struct tagBIND_OPTS2 *LPBIND_OPTS2;

#endif
#if defined(__cplusplus)
typedef struct tagBIND_OPTS3 : tagBIND_OPTS2
{
    HWND hwnd;
} BIND_OPTS3, *LPBIND_OPTS3;
#else
typedef struct tagBIND_OPTS3
{
    DWORD cbStruct;
    DWORD grfFlags;
    DWORD grfMode;
    DWORD dwTickCountDeadline;
    DWORD dwTrackFlags;
    DWORD dwClassContext;
    LCID locale;
    COSERVERINFO *pServerInfo;
    HWND hwnd;
} BIND_OPTS3;

typedef struct tagBIND_OPTS3 *LPBIND_OPTS3;

#endif
typedef enum tagBIND_FLAGS
{
    BIND_MAYBOTHERUSER = 1,
    BIND_JUSTTESTEXISTENCE = 2
} BIND_FLAGS;

#if defined(__cplusplus) && !defined(CINTERFACE)
DEFINE_GUID(IID_IBindCtx, 0x0000000e, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
struct IBindCtx : public IUnknown
{
  public:
    virtual HRESULT STDMETHODCALLTYPE RegisterObjectBound(
        /* [unique][in] */ __RPC__in_opt IUnknown *punk)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE RevokeObjectBound(
        /* [unique][in] */ __RPC__in_opt IUnknown *punk)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE ReleaseBoundObjects(void) = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetBindOptions(
        /* [annotation][in] */
        _In_ BIND_OPTS *pbindopts)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetBindOptions(
        /* [annotation][out][in] */
        _Inout_ BIND_OPTS *pbindopts)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetRunningObjectTable(
        /* [out] */ __RPC__deref_out_opt IRunningObjectTable **pprot)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE RegisterObjectParam(
        /* [in] */ __RPC__in LPOLESTR pszKey,
        /* [unique][in] */ __RPC__in_opt IUnknown *punk)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetObjectParam(
        /* [in] */ __RPC__in LPOLESTR pszKey,
        /* [out] */ __RPC__deref_out_opt IUnknown **ppunk)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE EnumObjectParam(
        /* [out] */ __RPC__deref_out_opt IEnumString **ppenum)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE RevokeObjectParam(
        /* [in] */ __RPC__in LPOLESTR pszKey)
        = 0;
};

#else /* C style interface */

typedef struct IBindCtxVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in IBindCtx *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in IBindCtx *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in IBindCtx *This);

    HRESULT(STDMETHODCALLTYPE *RegisterObjectBound)
    (__RPC__in IBindCtx *This,
     /* [unique][in] */ __RPC__in_opt IUnknown *punk);

    HRESULT(STDMETHODCALLTYPE *RevokeObjectBound)
    (__RPC__in IBindCtx *This,
     /* [unique][in] */ __RPC__in_opt IUnknown *punk);

    HRESULT(STDMETHODCALLTYPE *ReleaseBoundObjects)(__RPC__in IBindCtx *This);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *SetBindOptions)(IBindCtx *This,
                                                             /* [annotation][in] */
                                                             _In_ BIND_OPTS *pbindopts);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *GetBindOptions)(IBindCtx *This,
                                                             /* [annotation][out][in] */
                                                             _Inout_ BIND_OPTS *pbindopts);

    HRESULT(STDMETHODCALLTYPE *GetRunningObjectTable)
    (__RPC__in IBindCtx *This,
     /* [out] */ __RPC__deref_out_opt IRunningObjectTable **pprot);

    HRESULT(STDMETHODCALLTYPE *RegisterObjectParam)
    (__RPC__in IBindCtx *This,
     /* [in] */ __RPC__in LPOLESTR pszKey,
     /* [unique][in] */ __RPC__in_opt IUnknown *punk);

    HRESULT(STDMETHODCALLTYPE *GetObjectParam)
    (__RPC__in IBindCtx *This,
     /* [in] */ __RPC__in LPOLESTR pszKey,
     /* [out] */ __RPC__deref_out_opt IUnknown **ppunk);

    HRESULT(STDMETHODCALLTYPE *EnumObjectParam)
    (__RPC__in IBindCtx *This,
     /* [out] */ __RPC__deref_out_opt IEnumString **ppenum);

    HRESULT(STDMETHODCALLTYPE *RevokeObjectParam)
    (__RPC__in IBindCtx *This,
     /* [in] */ __RPC__in LPOLESTR pszKey);

    END_INTERFACE
} IBindCtxVtbl;

interface IBindCtx
{
    CONST_VTBL struct IBindCtxVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IBindCtx_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IBindCtx_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IBindCtx_Release(This) ((This)->lpVtbl->Release(This))

#define IBindCtx_RegisterObjectBound(This, punk) ((This)->lpVtbl->RegisterObjectBound(This, punk))

#define IBindCtx_RevokeObjectBound(This, punk) ((This)->lpVtbl->RevokeObjectBound(This, punk))

#define IBindCtx_ReleaseBoundObjects(This) ((This)->lpVtbl->ReleaseBoundObjects(This))

#define IBindCtx_SetBindOptions(This, pbindopts) ((This)->lpVtbl->SetBindOptions(This, pbindopts))

#define IBindCtx_GetBindOptions(This, pbindopts) ((This)->lpVtbl->GetBindOptions(This, pbindopts))

#define IBindCtx_GetRunningObjectTable(This, pprot) ((This)->lpVtbl->GetRunningObjectTable(This, pprot))

#define IBindCtx_RegisterObjectParam(This, pszKey, punk) ((This)->lpVtbl->RegisterObjectParam(This, pszKey, punk))

#define IBindCtx_GetObjectParam(This, pszKey, ppunk) ((This)->lpVtbl->GetObjectParam(This, pszKey, ppunk))

#define IBindCtx_EnumObjectParam(This, ppenum) ((This)->lpVtbl->EnumObjectParam(This, ppenum))

#define IBindCtx_RevokeObjectParam(This, pszKey) ((This)->lpVtbl->RevokeObjectParam(This, pszKey))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IBindCtx_INTERFACE_DEFINED__ */

#ifndef __IMoniker_INTERFACE_DEFINED__
#define __IMoniker_INTERFACE_DEFINED__

/* interface IMoniker */
/* [unique][uuid][object] */

typedef /* [unique] */ __RPC_unique_pointer struct IMoniker *LPMONIKER;

typedef enum tagMKSYS
{
    MKSYS_NONE = 0,
    MKSYS_GENERICCOMPOSITE = 1,
    MKSYS_FILEMONIKER = 2,
    MKSYS_ANTIMONIKER = 3,
    MKSYS_ITEMMONIKER = 4,
    MKSYS_POINTERMONIKER = 5,
    MKSYS_CLASSMONIKER = 7,
    MKSYS_OBJREFMONIKER = 8,
    MKSYS_SESSIONMONIKER = 9,
    MKSYS_LUAMONIKER = 10
} MKSYS;

typedef /* [v1_enum] */
    enum tagMKREDUCE
{
    MKRREDUCE_ONE = (3 << 16),
    MKRREDUCE_TOUSER = (2 << 16),
    MKRREDUCE_THROUGHUSER = (1 << 16),
    MKRREDUCE_ALL = 0
} MKRREDUCE;

DEFINE_GUID(IID_IMoniker, 0x0000000f, 0, 0, 0xc0, 0, 0, 0, 0, 0, 0, 0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE IMoniker
DECLARE_INTERFACE_(IMoniker, IPersistStream)
{
  public:
    DECLARE_CLASS_SIID(IID_IMoniker)

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE BindToObject(
        /* [annotation][unique][in] */
        _In_ IBindCtx * pbc,
        /* [annotation][unique][in] */
        _In_opt_ IMoniker * pmkToLeft,
        /* [annotation][in] */
        _In_ REFIID riidResult,
        /* [annotation][iid_is][out] */
        _Outptr_ void **ppvResult)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE BindToStorage(
        /* [annotation][unique][in] */
        _In_ IBindCtx * pbc,
        /* [annotation][unique][in] */
        _In_opt_ IMoniker * pmkToLeft,
        /* [annotation][in] */
        _In_ REFIID riid,
        /* [annotation][iid_is][out] */
        _Outptr_ void **ppvObj)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Reduce(
        /* [unique][in] */ __RPC__in_opt IBindCtx * pbc,
        /* [in] */ DWORD dwReduceHowFar,
        /* [unique][out][in] */ __RPC__deref_opt_inout_opt IMoniker * *ppmkToLeft,
        /* [out] */ __RPC__deref_out_opt IMoniker * *ppmkReduced)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE ComposeWith(
        /* [unique][in] */ __RPC__in_opt IMoniker * pmkRight,
        /* [in] */ BOOL fOnlyIfNotGeneric,
        /* [out] */ __RPC__deref_out_opt IMoniker * *ppmkComposite)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Enum(
        /* [in] */ BOOL fForward,
        /* [out] */ __RPC__deref_out_opt IEnumMoniker * *ppenumMoniker)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE IsEqual(
        /* [unique][in] */ __RPC__in_opt IMoniker * pmkOtherMoniker)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Hash(
        /* [out] */ __RPC__out DWORD * pdwHash)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE IsRunning(
        /* [unique][in] */ __RPC__in_opt IBindCtx * pbc,
        /* [unique][in] */ __RPC__in_opt IMoniker * pmkToLeft,
        /* [unique][in] */ __RPC__in_opt IMoniker * pmkNewlyRunning)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetTimeOfLastChange(
        /* [unique][in] */ __RPC__in_opt IBindCtx * pbc,
        /* [unique][in] */ __RPC__in_opt IMoniker * pmkToLeft,
        /* [out] */ __RPC__out FILETIME * pFileTime)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Inverse(
        /* [out] */ __RPC__deref_out_opt IMoniker * *ppmk)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE CommonPrefixWith(
        /* [unique][in] */ __RPC__in_opt IMoniker * pmkOther,
        /* [out] */ __RPC__deref_out_opt IMoniker * *ppmkPrefix)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE RelativePathTo(
        /* [unique][in] */ __RPC__in_opt IMoniker * pmkOther,
        /* [out] */ __RPC__deref_out_opt IMoniker * *ppmkRelPath)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetDisplayName(
        /* [unique][in] */ __RPC__in_opt IBindCtx * pbc,
        /* [unique][in] */ __RPC__in_opt IMoniker * pmkToLeft,
        /* [out] */ __RPC__deref_out_opt LPOLESTR * ppszDisplayName)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE ParseDisplayName(
        /* [unique][in] */ __RPC__in_opt IBindCtx * pbc,
        /* [unique][in] */ __RPC__in_opt IMoniker * pmkToLeft,
        /* [in] */ __RPC__in LPOLESTR pszDisplayName,
        /* [out] */ __RPC__out ULONG * pchEaten,
        /* [out] */ __RPC__deref_out_opt IMoniker * *ppmkOut)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE IsSystemMoniker(
        /* [out] */ __RPC__out DWORD * pdwMksys)
        = 0;
};

#else /* C style interface */

typedef struct IMonikerVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in IMoniker *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in IMoniker *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in IMoniker *This);

    HRESULT(STDMETHODCALLTYPE *GetClassID)
    (__RPC__in IMoniker *This,
     /* [out] */ __RPC__out CLSID *pClassID);

    HRESULT(STDMETHODCALLTYPE *IsDirty)(__RPC__in IMoniker *This);

    HRESULT(STDMETHODCALLTYPE *Load)
    (__RPC__in IMoniker *This,
     /* [unique][in] */ __RPC__in_opt IStream *pStm);

    HRESULT(STDMETHODCALLTYPE *Save)
    (__RPC__in IMoniker *This,
     /* [unique][in] */ __RPC__in_opt IStream *pStm,
     /* [in] */ BOOL fClearDirty);

    HRESULT(STDMETHODCALLTYPE *GetSizeMax)
    (__RPC__in IMoniker *This,
     /* [out] */ __RPC__out ULARGE_INTEGER *pcbSize);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *BindToObject)(IMoniker *This,
                                                           /* [annotation][unique][in] */
                                                           _In_ IBindCtx *pbc,
                                                           /* [annotation][unique][in] */
                                                           _In_opt_ IMoniker *pmkToLeft,
                                                           /* [annotation][in] */
                                                           _In_ REFIID riidResult,
                                                           /* [annotation][iid_is][out] */
                                                           _Outptr_ void **ppvResult);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *BindToStorage)(IMoniker *This,
                                                            /* [annotation][unique][in] */
                                                            _In_ IBindCtx *pbc,
                                                            /* [annotation][unique][in] */
                                                            _In_opt_ IMoniker *pmkToLeft,
                                                            /* [annotation][in] */
                                                            _In_ REFIID riid,
                                                            /* [annotation][iid_is][out] */
                                                            _Outptr_ void **ppvObj);

    HRESULT(STDMETHODCALLTYPE *Reduce)
    (__RPC__in IMoniker *This,
     /* [unique][in] */ __RPC__in_opt IBindCtx *pbc,
     /* [in] */ DWORD dwReduceHowFar,
     /* [unique][out][in] */ __RPC__deref_opt_inout_opt IMoniker **ppmkToLeft,
     /* [out] */ __RPC__deref_out_opt IMoniker **ppmkReduced);

    HRESULT(STDMETHODCALLTYPE *ComposeWith)
    (__RPC__in IMoniker *This,
     /* [unique][in] */ __RPC__in_opt IMoniker *pmkRight,
     /* [in] */ BOOL fOnlyIfNotGeneric,
     /* [out] */ __RPC__deref_out_opt IMoniker **ppmkComposite);

    HRESULT(STDMETHODCALLTYPE *Enum)
    (__RPC__in IMoniker *This,
     /* [in] */ BOOL fForward,
     /* [out] */ __RPC__deref_out_opt IEnumMoniker **ppenumMoniker);

    HRESULT(STDMETHODCALLTYPE *IsEqual)
    (__RPC__in IMoniker *This,
     /* [unique][in] */ __RPC__in_opt IMoniker *pmkOtherMoniker);

    HRESULT(STDMETHODCALLTYPE *Hash)
    (__RPC__in IMoniker *This,
     /* [out] */ __RPC__out DWORD *pdwHash);

    HRESULT(STDMETHODCALLTYPE *IsRunning)
    (__RPC__in IMoniker *This,
     /* [unique][in] */ __RPC__in_opt IBindCtx *pbc,
     /* [unique][in] */ __RPC__in_opt IMoniker *pmkToLeft,
     /* [unique][in] */ __RPC__in_opt IMoniker *pmkNewlyRunning);

    HRESULT(STDMETHODCALLTYPE *GetTimeOfLastChange)
    (__RPC__in IMoniker *This,
     /* [unique][in] */ __RPC__in_opt IBindCtx *pbc,
     /* [unique][in] */ __RPC__in_opt IMoniker *pmkToLeft,
     /* [out] */ __RPC__out FILETIME *pFileTime);

    HRESULT(STDMETHODCALLTYPE *Inverse)
    (__RPC__in IMoniker *This,
     /* [out] */ __RPC__deref_out_opt IMoniker **ppmk);

    HRESULT(STDMETHODCALLTYPE *CommonPrefixWith)
    (__RPC__in IMoniker *This,
     /* [unique][in] */ __RPC__in_opt IMoniker *pmkOther,
     /* [out] */ __RPC__deref_out_opt IMoniker **ppmkPrefix);

    HRESULT(STDMETHODCALLTYPE *RelativePathTo)
    (__RPC__in IMoniker *This,
     /* [unique][in] */ __RPC__in_opt IMoniker *pmkOther,
     /* [out] */ __RPC__deref_out_opt IMoniker **ppmkRelPath);

    HRESULT(STDMETHODCALLTYPE *GetDisplayName)
    (__RPC__in IMoniker *This,
     /* [unique][in] */ __RPC__in_opt IBindCtx *pbc,
     /* [unique][in] */ __RPC__in_opt IMoniker *pmkToLeft,
     /* [out] */ __RPC__deref_out_opt LPOLESTR *ppszDisplayName);

    HRESULT(STDMETHODCALLTYPE *ParseDisplayName)
    (__RPC__in IMoniker *This,
     /* [unique][in] */ __RPC__in_opt IBindCtx *pbc,
     /* [unique][in] */ __RPC__in_opt IMoniker *pmkToLeft,
     /* [in] */ __RPC__in LPOLESTR pszDisplayName,
     /* [out] */ __RPC__out ULONG *pchEaten,
     /* [out] */ __RPC__deref_out_opt IMoniker **ppmkOut);

    HRESULT(STDMETHODCALLTYPE *IsSystemMoniker)
    (__RPC__in IMoniker *This,
     /* [out] */ __RPC__out DWORD *pdwMksys);

    END_INTERFACE
} IMonikerVtbl;

interface IMoniker
{
    CONST_VTBL struct IMonikerVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IMoniker_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IMoniker_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IMoniker_Release(This) ((This)->lpVtbl->Release(This))

#define IMoniker_GetClassID(This, pClassID) ((This)->lpVtbl->GetClassID(This, pClassID))

#define IMoniker_IsDirty(This) ((This)->lpVtbl->IsDirty(This))

#define IMoniker_Load(This, pStm) ((This)->lpVtbl->Load(This, pStm))

#define IMoniker_Save(This, pStm, fClearDirty) ((This)->lpVtbl->Save(This, pStm, fClearDirty))

#define IMoniker_GetSizeMax(This, pcbSize) ((This)->lpVtbl->GetSizeMax(This, pcbSize))

#define IMoniker_BindToObject(This, pbc, pmkToLeft, riidResult, ppvResult) ((This)->lpVtbl->BindToObject(This, pbc, pmkToLeft, riidResult, ppvResult))

#define IMoniker_BindToStorage(This, pbc, pmkToLeft, riid, ppvObj) ((This)->lpVtbl->BindToStorage(This, pbc, pmkToLeft, riid, ppvObj))

#define IMoniker_Reduce(This, pbc, dwReduceHowFar, ppmkToLeft, ppmkReduced) ((This)->lpVtbl->Reduce(This, pbc, dwReduceHowFar, ppmkToLeft, ppmkReduced))

#define IMoniker_ComposeWith(This, pmkRight, fOnlyIfNotGeneric, ppmkComposite) ((This)->lpVtbl->ComposeWith(This, pmkRight, fOnlyIfNotGeneric, ppmkComposite))

#define IMoniker_Enum(This, fForward, ppenumMoniker) ((This)->lpVtbl->Enum(This, fForward, ppenumMoniker))

#define IMoniker_IsEqual(This, pmkOtherMoniker) ((This)->lpVtbl->IsEqual(This, pmkOtherMoniker))

#define IMoniker_Hash(This, pdwHash) ((This)->lpVtbl->Hash(This, pdwHash))

#define IMoniker_IsRunning(This, pbc, pmkToLeft, pmkNewlyRunning) ((This)->lpVtbl->IsRunning(This, pbc, pmkToLeft, pmkNewlyRunning))

#define IMoniker_GetTimeOfLastChange(This, pbc, pmkToLeft, pFileTime) ((This)->lpVtbl->GetTimeOfLastChange(This, pbc, pmkToLeft, pFileTime))

#define IMoniker_Inverse(This, ppmk) ((This)->lpVtbl->Inverse(This, ppmk))

#define IMoniker_CommonPrefixWith(This, pmkOther, ppmkPrefix) ((This)->lpVtbl->CommonPrefixWith(This, pmkOther, ppmkPrefix))

#define IMoniker_RelativePathTo(This, pmkOther, ppmkRelPath) ((This)->lpVtbl->RelativePathTo(This, pmkOther, ppmkRelPath))

#define IMoniker_GetDisplayName(This, pbc, pmkToLeft, ppszDisplayName) ((This)->lpVtbl->GetDisplayName(This, pbc, pmkToLeft, ppszDisplayName))

#define IMoniker_ParseDisplayName(This, pbc, pmkToLeft, pszDisplayName, pchEaten, ppmkOut) ((This)->lpVtbl->ParseDisplayName(This, pbc, pmkToLeft, pszDisplayName, pchEaten, ppmkOut))

#define IMoniker_IsSystemMoniker(This, pdwMksys) ((This)->lpVtbl->IsSystemMoniker(This, pdwMksys))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IMoniker_INTERFACE_DEFINED__ */

#ifndef __IEnumMoniker_INTERFACE_DEFINED__
#define __IEnumMoniker_INTERFACE_DEFINED__

/* interface IEnumMoniker */
/* [unique][uuid][object] */

typedef /* [unique] */ __RPC_unique_pointer struct IEnumMoniker *LPENUMMONIKER;

EXTERN_C const IID IID_IEnumMoniker;

#if defined(__cplusplus) && !defined(CINTERFACE)

DEFINE_GUID(IID_IEnumMoniker, 0x00000102, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
struct IEnumMoniker : public IUnknown
{
  public:
    virtual /* [local] */ HRESULT STDMETHODCALLTYPE Next(
        /* [in] */ ULONG celt,
        /* [annotation] */
        _Out_writes_to_(celt, *pceltFetched) IMoniker **rgelt,
        /* [annotation] */
        _Out_opt_ ULONG *pceltFetched)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Skip(
        /* [in] */ ULONG celt)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Reset(void) = 0;

    virtual HRESULT STDMETHODCALLTYPE Clone(
        /* [out] */ __RPC__deref_out_opt IEnumMoniker **ppenum)
        = 0;
};

#else /* C style interface */

typedef struct IEnumMonikerVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in IEnumMoniker *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in IEnumMoniker *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in IEnumMoniker *This);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *Next)(IEnumMoniker *This,
                                                   /* [in] */ ULONG celt,
                                                   /* [annotation] */
                                                   _Out_writes_to_(celt, *pceltFetched) IMoniker **rgelt,
                                                   /* [annotation] */
                                                   _Out_opt_ ULONG *pceltFetched);

    HRESULT(STDMETHODCALLTYPE *Skip)
    (__RPC__in IEnumMoniker *This,
     /* [in] */ ULONG celt);

    HRESULT(STDMETHODCALLTYPE *Reset)(__RPC__in IEnumMoniker *This);

    HRESULT(STDMETHODCALLTYPE *Clone)
    (__RPC__in IEnumMoniker *This,
     /* [out] */ __RPC__deref_out_opt IEnumMoniker **ppenum);

    END_INTERFACE
} IEnumMonikerVtbl;

interface IEnumMoniker
{
    CONST_VTBL struct IEnumMonikerVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IEnumMoniker_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IEnumMoniker_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IEnumMoniker_Release(This) ((This)->lpVtbl->Release(This))

#define IEnumMoniker_Next(This, celt, rgelt, pceltFetched) ((This)->lpVtbl->Next(This, celt, rgelt, pceltFetched))

#define IEnumMoniker_Skip(This, celt) ((This)->lpVtbl->Skip(This, celt))

#define IEnumMoniker_Reset(This) ((This)->lpVtbl->Reset(This))

#define IEnumMoniker_Clone(This, ppenum) ((This)->lpVtbl->Clone(This, ppenum))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IEnumMoniker_INTERFACE_DEFINED__ */

#ifndef __ILockBytes_INTERFACE_DEFINED__
#define __ILockBytes_INTERFACE_DEFINED__

/* interface ILockBytes */
/* [unique][uuid][object] */

typedef /* [unique] */ __RPC_unique_pointer struct ILockBytes *LPLOCKBYTES;

#if defined(__cplusplus) && !defined(CINTERFACE)
DEFINE_GUID(IID_ILockBytes, 0x0000000a, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);

struct ILockBytes : public IUnknown
{
  public:
    virtual /* [local] */ HRESULT STDMETHODCALLTYPE ReadAt(
        /* [in] */ ULARGE_INTEGER ulOffset,
        /* [annotation][length_is][size_is][out] */
        _Out_writes_bytes_to_(cb, *pcbRead) void *pv,
        /* [in] */ ULONG cb,
        /* [annotation][out] */
        _Out_opt_ ULONG *pcbRead)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE WriteAt(
        /* [in] */ ULARGE_INTEGER ulOffset,
        /* [annotation][size_is][in] */
        _In_reads_bytes_(cb) const void *pv,
        /* [in] */ ULONG cb,
        /* [annotation][out] */
        _Out_opt_ ULONG *pcbWritten)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Flush(void) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetSize(
        /* [in] */ ULARGE_INTEGER cb)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE LockRegion(
        /* [in] */ ULARGE_INTEGER libOffset,
        /* [in] */ ULARGE_INTEGER cb,
        /* [in] */ DWORD dwLockType)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE UnlockRegion(
        /* [in] */ ULARGE_INTEGER libOffset,
        /* [in] */ ULARGE_INTEGER cb,
        /* [in] */ DWORD dwLockType)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE Stat(
        /* [out] */ __RPC__out STATSTG *pstatstg,
        /* [in] */ DWORD grfStatFlag)
        = 0;
};

#else /* C style interface */

typedef struct ILockBytesVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (__RPC__in ILockBytes *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [annotation][iid_is][out] */
     _COM_Outptr_ void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(__RPC__in ILockBytes *This);

    ULONG(STDMETHODCALLTYPE *Release)(__RPC__in ILockBytes *This);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *ReadAt)(ILockBytes *This,
                                                     /* [in] */ ULARGE_INTEGER ulOffset,
                                                     /* [annotation][length_is][size_is][out] */
                                                     _Out_writes_bytes_to_(cb, *pcbRead) void *pv,
                                                     /* [in] */ ULONG cb,
                                                     /* [annotation][out] */
                                                     _Out_opt_ ULONG *pcbRead);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *WriteAt)(ILockBytes *This,
                                                      /* [in] */ ULARGE_INTEGER ulOffset,
                                                      /* [annotation][size_is][in] */
                                                      _In_reads_bytes_(cb) const void *pv,
                                                      /* [in] */ ULONG cb,
                                                      /* [annotation][out] */
                                                      _Out_opt_ ULONG *pcbWritten);

    HRESULT(STDMETHODCALLTYPE *Flush)(__RPC__in ILockBytes *This);

    HRESULT(STDMETHODCALLTYPE *SetSize)
    (__RPC__in ILockBytes *This,
     /* [in] */ ULARGE_INTEGER cb);

    HRESULT(STDMETHODCALLTYPE *LockRegion)
    (__RPC__in ILockBytes *This,
     /* [in] */ ULARGE_INTEGER libOffset,
     /* [in] */ ULARGE_INTEGER cb,
     /* [in] */ DWORD dwLockType);

    HRESULT(STDMETHODCALLTYPE *UnlockRegion)
    (__RPC__in ILockBytes *This,
     /* [in] */ ULARGE_INTEGER libOffset,
     /* [in] */ ULARGE_INTEGER cb,
     /* [in] */ DWORD dwLockType);

    HRESULT(STDMETHODCALLTYPE *Stat)
    (__RPC__in ILockBytes *This,
     /* [out] */ __RPC__out STATSTG *pstatstg,
     /* [in] */ DWORD grfStatFlag);

    END_INTERFACE
} ILockBytesVtbl;

interface ILockBytes
{
    CONST_VTBL struct ILockBytesVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define ILockBytes_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define ILockBytes_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define ILockBytes_Release(This) ((This)->lpVtbl->Release(This))

#define ILockBytes_ReadAt(This, ulOffset, pv, cb, pcbRead) ((This)->lpVtbl->ReadAt(This, ulOffset, pv, cb, pcbRead))

#define ILockBytes_WriteAt(This, ulOffset, pv, cb, pcbWritten) ((This)->lpVtbl->WriteAt(This, ulOffset, pv, cb, pcbWritten))

#define ILockBytes_Flush(This) ((This)->lpVtbl->Flush(This))

#define ILockBytes_SetSize(This, cb) ((This)->lpVtbl->SetSize(This, cb))

#define ILockBytes_LockRegion(This, libOffset, cb, dwLockType) ((This)->lpVtbl->LockRegion(This, libOffset, cb, dwLockType))

#define ILockBytes_UnlockRegion(This, libOffset, cb, dwLockType) ((This)->lpVtbl->UnlockRegion(This, libOffset, cb, dwLockType))

#define ILockBytes_Stat(This, pstatstg, grfStatFlag) ((This)->lpVtbl->Stat(This, pstatstg, grfStatFlag))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __ILockBytes_INTERFACE_DEFINED__ */

#endif