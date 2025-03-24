#ifndef _OAIDL_H_
#define _OAIDL_H_
#include <unknwn.h>

/* Forward Declarations */

#ifndef __ICreateTypeInfo_FWD_DEFINED__
#define __ICreateTypeInfo_FWD_DEFINED__
typedef interface ICreateTypeInfo ICreateTypeInfo;

#endif /* __ICreateTypeInfo_FWD_DEFINED__ */

#ifndef __ICreateTypeInfo2_FWD_DEFINED__
#define __ICreateTypeInfo2_FWD_DEFINED__
typedef interface ICreateTypeInfo2 ICreateTypeInfo2;

#endif /* __ICreateTypeInfo2_FWD_DEFINED__ */

#ifndef __ICreateTypeLib_FWD_DEFINED__
#define __ICreateTypeLib_FWD_DEFINED__
typedef interface ICreateTypeLib ICreateTypeLib;

#endif /* __ICreateTypeLib_FWD_DEFINED__ */

#ifndef __ICreateTypeLib2_FWD_DEFINED__
#define __ICreateTypeLib2_FWD_DEFINED__
typedef interface ICreateTypeLib2 ICreateTypeLib2;

#endif /* __ICreateTypeLib2_FWD_DEFINED__ */

#ifndef __IDispatch_FWD_DEFINED__
#define __IDispatch_FWD_DEFINED__
typedef interface IDispatch IDispatch;

#endif /* __IDispatch_FWD_DEFINED__ */

#ifndef __IEnumVARIANT_FWD_DEFINED__
#define __IEnumVARIANT_FWD_DEFINED__
typedef interface IEnumVARIANT IEnumVARIANT;

#endif /* __IEnumVARIANT_FWD_DEFINED__ */

#ifndef __ITypeComp_FWD_DEFINED__
#define __ITypeComp_FWD_DEFINED__
typedef interface ITypeComp ITypeComp;

#endif /* __ITypeComp_FWD_DEFINED__ */

#ifndef __ITypeInfo_FWD_DEFINED__
#define __ITypeInfo_FWD_DEFINED__
typedef interface ITypeInfo ITypeInfo;

#endif /* __ITypeInfo_FWD_DEFINED__ */

#ifndef __ITypeInfo2_FWD_DEFINED__
#define __ITypeInfo2_FWD_DEFINED__
typedef interface ITypeInfo2 ITypeInfo2;

#endif /* __ITypeInfo2_FWD_DEFINED__ */

#ifndef __ITypeLib_FWD_DEFINED__
#define __ITypeLib_FWD_DEFINED__
typedef interface ITypeLib ITypeLib;

#endif /* __ITypeLib_FWD_DEFINED__ */

#ifndef __ITypeLib2_FWD_DEFINED__
#define __ITypeLib2_FWD_DEFINED__
typedef interface ITypeLib2 ITypeLib2;

#endif /* __ITypeLib2_FWD_DEFINED__ */

#ifndef __ITypeChangeEvents_FWD_DEFINED__
#define __ITypeChangeEvents_FWD_DEFINED__
typedef interface ITypeChangeEvents ITypeChangeEvents;

#endif /* __ITypeChangeEvents_FWD_DEFINED__ */

#ifndef __IErrorInfo_FWD_DEFINED__
#define __IErrorInfo_FWD_DEFINED__
typedef interface IErrorInfo IErrorInfo;

#endif /* __IErrorInfo_FWD_DEFINED__ */

#ifndef __ICreateErrorInfo_FWD_DEFINED__
#define __ICreateErrorInfo_FWD_DEFINED__
typedef interface ICreateErrorInfo ICreateErrorInfo;

#endif /* __ICreateErrorInfo_FWD_DEFINED__ */

#ifndef __ISupportErrorInfo_FWD_DEFINED__
#define __ISupportErrorInfo_FWD_DEFINED__
typedef interface ISupportErrorInfo ISupportErrorInfo;

#endif /* __ISupportErrorInfo_FWD_DEFINED__ */

#ifndef __ITypeFactory_FWD_DEFINED__
#define __ITypeFactory_FWD_DEFINED__
typedef interface ITypeFactory ITypeFactory;

#endif /* __ITypeFactory_FWD_DEFINED__ */

#ifndef __ITypeMarshal_FWD_DEFINED__
#define __ITypeMarshal_FWD_DEFINED__
typedef interface ITypeMarshal ITypeMarshal;

#endif /* __ITypeMarshal_FWD_DEFINED__ */

#ifndef __IRecordInfo_FWD_DEFINED__
#define __IRecordInfo_FWD_DEFINED__
typedef interface IRecordInfo IRecordInfo;

#endif /* __IRecordInfo_FWD_DEFINED__ */

#ifndef __IErrorLog_FWD_DEFINED__
#define __IErrorLog_FWD_DEFINED__
typedef interface IErrorLog IErrorLog;

#endif /* __IErrorLog_FWD_DEFINED__ */

#ifndef __IPropertyBag_FWD_DEFINED__
#define __IPropertyBag_FWD_DEFINED__
typedef interface IPropertyBag IPropertyBag;

#endif /* __IPropertyBag_FWD_DEFINED__ */

#ifndef __ITypeLibRegistrationReader_FWD_DEFINED__
#define __ITypeLibRegistrationReader_FWD_DEFINED__
typedef interface ITypeLibRegistrationReader ITypeLibRegistrationReader;

#endif /* __ITypeLibRegistrationReader_FWD_DEFINED__ */

#ifndef __ITypeLibRegistration_FWD_DEFINED__
#define __ITypeLibRegistration_FWD_DEFINED__
typedef interface ITypeLibRegistration ITypeLibRegistration;

#endif /* __ITypeLibRegistration_FWD_DEFINED__ */

/* 0 == FALSE, -1 == TRUE */
typedef short VARIANT_BOOL;
typedef VARIANT_BOOL _VARIANT_BOOL;

#define VARIANT_TRUE  ((VARIANT_BOOL)-1)
#define VARIANT_FALSE ((VARIANT_BOOL)0)
#ifndef _tagBLOB_DEFINED
#define _tagBLOB_DEFINED
#define _BLOB_DEFINED
#define _LPBLOB_DEFINED
typedef struct tagBLOB
{
    ULONG cbSize;
    BYTE *pBlobData;
} BLOB;

typedef struct tagBLOB *LPBLOB;

#endif //_tagBLOB_DEFINED
typedef struct tagCLIPDATA
{
    ULONG cbSize;
    long ulClipFmt;
    BYTE *pClipData;
} CLIPDATA;

// Macro to calculate the size of the above pClipData
#define CBPCLIPDATA(clipdata) ((clipdata).cbSize - sizeof((clipdata).ulClipFmt))
typedef unsigned short VARTYPE;

typedef struct IDispatch IDispatch;

/*
 * VARENUM usage key,
 *
 * * [V] - may appear in a VARIANT
 * * [T] - may appear in a TYPEDESC
 * * [P] - may appear in an OLE property set
 * * [S] - may appear in a Safe Array
 *
 *
 *  VT_EMPTY            [V]   [P]     nothing
 *  VT_NULL             [V]   [P]     SQL style Null
 *  VT_I2               [V][T][P][S]  2 byte signed int
 *  VT_I4               [V][T][P][S]  4 byte signed int
 *  VT_R4               [V][T][P][S]  4 byte real
 *  VT_R8               [V][T][P][S]  8 byte real
 *  VT_CY               [V][T][P][S]  currency
 *  VT_DATE             [V][T][P][S]  date
 *  VT_BSTR             [V][T][P][S]  OLE Automation string
 *  VT_DISPATCH         [V][T]   [S]  IDispatch *
 *  VT_ERROR            [V][T][P][S]  SCODE
 *  VT_BOOL             [V][T][P][S]  True=-1, False=0
 *  VT_VARIANT          [V][T][P][S]  VARIANT *
 *  VT_UNKNOWN          [V][T]   [S]  IUnknown *
 *  VT_DECIMAL          [V][T]   [S]  16 byte fixed point
 *  VT_RECORD           [V]   [P][S]  user defined type
 *  VT_I1               [V][T][P][s]  signed char
 *  VT_UI1              [V][T][P][S]  unsigned char
 *  VT_UI2              [V][T][P][S]  unsigned short
 *  VT_UI4              [V][T][P][S]  unsigned long
 *  VT_I8                  [T][P]     signed 64-bit int
 *  VT_UI8                 [T][P]     unsigned 64-bit int
 *  VT_INT              [V][T][P][S]  signed machine int
 *  VT_UINT             [V][T]   [S]  unsigned machine int
 *  VT_INT_PTR             [T]        signed machine register size width
 *  VT_UINT_PTR            [T]        unsigned machine register size width
 *  VT_VOID                [T]        C style void
 *  VT_HRESULT             [T]        Standard return type
 *  VT_PTR                 [T]        pointer type
 *  VT_SAFEARRAY           [T]        (use VT_ARRAY in VARIANT)
 *  VT_CARRAY              [T]        C style array
 *  VT_USERDEFINED         [T]        user defined type
 *  VT_LPSTR               [T][P]     null terminated string
 *  VT_LPWSTR              [T][P]     wide null terminated string
 *  VT_FILETIME               [P]     FILETIME
 *  VT_BLOB                   [P]     Length prefixed bytes
 *  VT_STREAM                 [P]     Name of the stream follows
 *  VT_STORAGE                [P]     Name of the storage follows
 *  VT_STREAMED_OBJECT        [P]     Stream contains an object
 *  VT_STORED_OBJECT          [P]     Storage contains an object
 *  VT_VERSIONED_STREAM       [P]     Stream with a GUID version
 *  VT_BLOB_OBJECT            [P]     Blob contains an object
 *  VT_CF                     [P]     Clipboard format
 *  VT_CLSID                  [P]     A Class ID
 *  VT_VECTOR                 [P]     simple counted array
 *  VT_ARRAY            [V]           SAFEARRAY*
 *  VT_BYREF            [V]           void* for local use
 *  VT_BSTR_BLOB                      Reserved for system use
 */

enum VARENUM
{
    VT_EMPTY = 0,
    VT_NULL = 1,
    VT_I2 = 2,
    VT_I4 = 3,
    VT_R4 = 4,
    VT_R8 = 5,
    VT_CY = 6,
    VT_DATE = 7,
    VT_BSTR = 8,
    VT_DISPATCH = 9,
    VT_ERROR = 10,
    VT_BOOL = 11,
    VT_VARIANT = 12,
    VT_UNKNOWN = 13,
    VT_DECIMAL = 14,
    VT_I1 = 16,
    VT_UI1 = 17,
    VT_UI2 = 18,
    VT_UI4 = 19,
    VT_I8 = 20,
    VT_UI8 = 21,
    VT_INT = 22,
    VT_UINT = 23,
    VT_VOID = 24,
    VT_HRESULT = 25,
    VT_PTR = 26,
    VT_SAFEARRAY = 27,
    VT_CARRAY = 28,
    VT_USERDEFINED = 29,
    VT_LPSTR = 30,
    VT_LPWSTR = 31,
    VT_RECORD = 36,
    VT_INT_PTR = 37,
    VT_UINT_PTR = 38,
    VT_FILETIME = 64,
    VT_BLOB = 65,
    VT_STREAM = 66,
    VT_STORAGE = 67,
    VT_STREAMED_OBJECT = 68,
    VT_STORED_OBJECT = 69,
    VT_BLOB_OBJECT = 70,
    VT_CF = 71,
    VT_CLSID = 72,
    VT_VERSIONED_STREAM = 73,
    VT_BSTR_BLOB = 0xfff,
    VT_VECTOR = 0x1000,
    VT_ARRAY = 0x2000,
    VT_BYREF = 0x4000,
    VT_RESERVED = 0x8000,
    VT_ILLEGAL = 0xffff,
    VT_ILLEGALMASKED = 0xfff,
    VT_TYPEMASK = 0xfff
};
typedef ULONG PROPID;

typedef struct tagSAFEARRAYBOUND
{
    ULONG cElements;
    LONG lLbound;
} SAFEARRAYBOUND;

typedef struct tagSAFEARRAYBOUND *LPSAFEARRAYBOUND;

typedef struct tagSAFEARRAY
{
    USHORT cDims;
    USHORT fFeatures;
    ULONG cbElements;
    LONG cLocks;
    PVOID pvData;
    SAFEARRAYBOUND rgsabound[1];
} SAFEARRAY;

typedef /* [wire_marshal] */ SAFEARRAY *LPSAFEARRAY;

#define FADF_AUTO (0x1)

#define FADF_STATIC (0x2)

#define FADF_EMBEDDED (0x4)

#define FADF_FIXEDSIZE (0x10)

#define FADF_RECORD (0x20)

#define FADF_HAVEIID (0x40)

#define FADF_HAVEVARTYPE (0x80)

#define FADF_BSTR (0x100)

#define FADF_UNKNOWN (0x200)

#define FADF_DISPATCH (0x400)

#define FADF_VARIANT (0x800)

#define FADF_RESERVED (0xf008)

#define __tagVARIANT
#define __VARIANT_NAME_1
#define __VARIANT_NAME_2
#define __VARIANT_NAME_3
#define __tagBRECORD
#define __VARIANT_NAME_4

typedef LONG SCODE;

typedef SCODE *PSCODE;

typedef union tagCY {
    struct
    {
#ifdef _MAC
        long Hi;
        long Lo;
#else
        unsigned long Lo;
        long Hi;
#endif
    };
    LONGLONG int64;
} CY;

typedef CY *LPCY;

typedef double DATE;

typedef CY CURRENCY;

#ifndef _tagDEC_DEFINED
#define _tagDEC_DEFINED
/* real definition that makes the C++ compiler happy */
typedef struct tagDEC
{
    USHORT wReserved;
    union {
        struct
        {
            BYTE scale;
            BYTE sign;
        };
        USHORT signscale;
    };
    ULONG Hi32;
    union {
        struct
        {
#ifdef _MAC
            ULONG Mid32;
            ULONG Lo32;
#else
            ULONG Lo32;
            ULONG Mid32;
#endif
        };
        ULONGLONG Lo64;
    };
} DECIMAL;
#define DECIMAL_NEG ((BYTE)0x80)
#define DECIMAL_SETZERO(dec) \
    {                        \
        (dec).Lo64 = 0;      \
        (dec).Hi32 = 0;      \
        (dec).signscale = 0; \
    }
#endif /* _tagDEC_DEFINED */
typedef DECIMAL *LPDECIMAL;

typedef struct tagVARIANT VARIANT;
struct IRecordInfo;

struct tagVARIANT
{
    union {
        struct __tagVARIANT
        {
            VARTYPE vt;
            WORD wReserved1;
            WORD wReserved2;
            WORD wReserved3;
            union {
                LONGLONG llVal;
                LONG lVal;
                BYTE bVal;
                SHORT iVal;
                FLOAT fltVal;
                DOUBLE dblVal;
                VARIANT_BOOL boolVal;
                SCODE scode;
                CY cyVal;
                DATE date;
                BSTR bstrVal;
                IUnknown *punkVal;
                IDispatch *pdispVal;
                SAFEARRAY *parray;
                BYTE *pbVal;
                SHORT *piVal;
                LONG *plVal;
                LONGLONG *pllVal;
                FLOAT *pfltVal;
                DOUBLE *pdblVal;
                VARIANT_BOOL *pboolVal;
                _VARIANT_BOOL *pbool;
                SCODE *pscode;
                CY *pcyVal;
                DATE *pdate;
                BSTR *pbstrVal;
                IUnknown **ppunkVal;
                IDispatch **ppdispVal;
                SAFEARRAY **pparray;
                VARIANT *pvarVal;
                PVOID byref;
                CHAR cVal;
                USHORT uiVal;
                ULONG ulVal;
                ULONGLONG ullVal;
                INT intVal;
                UINT uintVal;
                DECIMAL *pdecVal;
                CHAR *pcVal;
                USHORT *puiVal;
                ULONG *pulVal;
                ULONGLONG *pullVal;
                INT *pintVal;
                UINT *puintVal;
                struct __tagBRECORD
                {
                    PVOID pvRecord;
                    IRecordInfo *pRecInfo;
                } __VARIANT_NAME_4;
            } __VARIANT_NAME_3;
        } __VARIANT_NAME_2;
        DECIMAL decVal;
    } __VARIANT_NAME_1;
};
typedef VARIANT *LPVARIANT;

typedef VARIANT VARIANTARG;

typedef VARIANT *LPVARIANTARG;

void WINAPI VariantInit(VARIANTARG *pvarg);
HRESULT WINAPI VariantClear(VARIANTARG *prop);
HRESULT WINAPI VariantCopy(VARIANTARG *dest, const VARIANTARG *src);

typedef LONG DISPID;

typedef DISPID MEMBERID;

typedef DWORD HREFTYPE;

typedef /* [v1_enum] */
    enum tagTYPEKIND
{
    TKIND_ENUM = 0,
    TKIND_RECORD = (TKIND_ENUM + 1),
    TKIND_MODULE = (TKIND_RECORD + 1),
    TKIND_INTERFACE = (TKIND_MODULE + 1),
    TKIND_DISPATCH = (TKIND_INTERFACE + 1),
    TKIND_COCLASS = (TKIND_DISPATCH + 1),
    TKIND_ALIAS = (TKIND_COCLASS + 1),
    TKIND_UNION = (TKIND_ALIAS + 1),
    TKIND_MAX = (TKIND_UNION + 1)
} TYPEKIND;

typedef struct tagTYPEDESC
{
    union {
        struct tagTYPEDESC *lptdesc;
        struct tagARRAYDESC *lpadesc;
        HREFTYPE hreftype;
        /* Empty union arm */
    };
    VARTYPE vt;
} TYPEDESC;

typedef struct tagARRAYDESC
{
    TYPEDESC tdescElem;
    USHORT cDims;
    SAFEARRAYBOUND rgbounds[1];
} ARRAYDESC;

typedef struct tagPARAMDESCEX
{
    ULONG cBytes;
    VARIANTARG varDefaultValue;
} PARAMDESCEX;

typedef struct tagPARAMDESCEX *LPPARAMDESCEX;

typedef struct tagPARAMDESC
{
    LPPARAMDESCEX pparamdescex;
    USHORT wParamFlags;
} PARAMDESC;

typedef struct tagPARAMDESC *LPPARAMDESC;

#define PARAMFLAG_NONE (0)

#define PARAMFLAG_FIN (0x1)

#define PARAMFLAG_FOUT (0x2)

#define PARAMFLAG_FLCID (0x4)

#define PARAMFLAG_FRETVAL (0x8)

#define PARAMFLAG_FOPT (0x10)

#define PARAMFLAG_FHASDEFAULT (0x20)

#define PARAMFLAG_FHASCUSTDATA (0x40)

typedef struct tagIDLDESC
{
    ULONG_PTR dwReserved;
    USHORT wIDLFlags;
} IDLDESC;

typedef struct tagIDLDESC *LPIDLDESC;

#define IDLFLAG_NONE (PARAMFLAG_NONE)

#define IDLFLAG_FIN (PARAMFLAG_FIN)

#define IDLFLAG_FOUT (PARAMFLAG_FOUT)

#define IDLFLAG_FLCID (PARAMFLAG_FLCID)

#define IDLFLAG_FRETVAL (PARAMFLAG_FRETVAL)

typedef struct tagTYPEATTR
{
    GUID guid;
    LCID lcid;
    DWORD dwReserved;
    MEMBERID memidConstructor;
    MEMBERID memidDestructor;
    LPOLESTR lpstrSchema;
    ULONG cbSizeInstance;
    TYPEKIND typekind;
    WORD cFuncs;
    WORD cVars;
    WORD cImplTypes;
    WORD cbSizeVft;
    WORD cbAlignment;
    WORD wTypeFlags;
    WORD wMajorVerNum;
    WORD wMinorVerNum;
    TYPEDESC tdescAlias;
    IDLDESC idldescType;
} TYPEATTR;

typedef struct tagTYPEATTR *LPTYPEATTR;

typedef struct tagDISPPARAMS
{
    VARIANTARG *rgvarg;
    DISPID *rgdispidNamedArgs;
    UINT cArgs;
    UINT cNamedArgs;
} DISPPARAMS;

typedef struct tagEXCEPINFO
{
    WORD wCode;
    WORD wReserved;
    BSTR bstrSource;
    BSTR bstrDescription;
    BSTR bstrHelpFile;
    DWORD dwHelpContext;
    PVOID pvReserved;
    HRESULT(__stdcall *pfnDeferredFillIn)(struct tagEXCEPINFO *);
    SCODE scode;
} EXCEPINFO, *LPEXCEPINFO;

typedef /* [v1_enum] */
    enum tagCALLCONV
{
    CC_FASTCALL = 0,
    CC_CDECL = 1,
    CC_MSCPASCAL = (CC_CDECL + 1),
    CC_PASCAL = CC_MSCPASCAL,
    CC_MACPASCAL = (CC_PASCAL + 1),
    CC_STDCALL = (CC_MACPASCAL + 1),
    CC_FPFASTCALL = (CC_STDCALL + 1),
    CC_SYSCALL = (CC_FPFASTCALL + 1),
    CC_MPWCDECL = (CC_SYSCALL + 1),
    CC_MPWPASCAL = (CC_MPWCDECL + 1),
    CC_MAX = (CC_MPWPASCAL + 1)
} CALLCONV;

typedef /* [v1_enum] */
    enum tagFUNCKIND
{
    FUNC_VIRTUAL = 0,
    FUNC_PUREVIRTUAL = (FUNC_VIRTUAL + 1),
    FUNC_NONVIRTUAL = (FUNC_PUREVIRTUAL + 1),
    FUNC_STATIC = (FUNC_NONVIRTUAL + 1),
    FUNC_DISPATCH = (FUNC_STATIC + 1)
} FUNCKIND;

typedef /* [v1_enum] */
    enum tagINVOKEKIND
{
    INVOKE_FUNC = 1,
    INVOKE_PROPERTYGET = 2,
    INVOKE_PROPERTYPUT = 4,
    INVOKE_PROPERTYPUTREF = 8
} INVOKEKIND;

typedef struct tagELEMDESC
{
    TYPEDESC tdesc; /* the type of the element */
    union {
        IDLDESC idldesc;     /* info for remoting the element */
        PARAMDESC paramdesc; /* info about the parameter */
    };
} ELEMDESC, *LPELEMDESC;

typedef struct tagFUNCDESC
{
    MEMBERID memid;
    SCODE *lprgscode;
    ELEMDESC *lprgelemdescParam;
    FUNCKIND funckind;
    INVOKEKIND invkind;
    CALLCONV callconv;
    SHORT cParams;
    SHORT cParamsOpt;
    SHORT oVft;
    SHORT cScodes;
    ELEMDESC elemdescFunc;
    WORD wFuncFlags;
} FUNCDESC;

typedef struct tagFUNCDESC *LPFUNCDESC;

typedef /* [v1_enum] */
    enum tagVARKIND
{
    VAR_PERINSTANCE = 0,
    VAR_STATIC = (VAR_PERINSTANCE + 1),
    VAR_CONST = (VAR_STATIC + 1),
    VAR_DISPATCH = (VAR_CONST + 1)
} VARKIND;

#define IMPLTYPEFLAG_FDEFAULT (0x1)

#define IMPLTYPEFLAG_FSOURCE (0x2)

#define IMPLTYPEFLAG_FRESTRICTED (0x4)

#define IMPLTYPEFLAG_FDEFAULTVTABLE (0x8)

typedef struct tagVARDESC
{
    MEMBERID memid;
    LPOLESTR lpstrSchema;
    union {
        ULONG oInst;
        VARIANT *lpvarValue;
    };
    ELEMDESC elemdescVar;
    WORD wVarFlags;
    VARKIND varkind;
} VARDESC;

typedef struct tagVARDESC *LPVARDESC;

typedef enum tagTYPEFLAGS
{
    TYPEFLAG_FAPPOBJECT = 0x1,
    TYPEFLAG_FCANCREATE = 0x2,
    TYPEFLAG_FLICENSED = 0x4,
    TYPEFLAG_FPREDECLID = 0x8,
    TYPEFLAG_FHIDDEN = 0x10,
    TYPEFLAG_FCONTROL = 0x20,
    TYPEFLAG_FDUAL = 0x40,
    TYPEFLAG_FNONEXTENSIBLE = 0x80,
    TYPEFLAG_FOLEAUTOMATION = 0x100,
    TYPEFLAG_FRESTRICTED = 0x200,
    TYPEFLAG_FAGGREGATABLE = 0x400,
    TYPEFLAG_FREPLACEABLE = 0x800,
    TYPEFLAG_FDISPATCHABLE = 0x1000,
    TYPEFLAG_FREVERSEBIND = 0x2000,
    TYPEFLAG_FPROXY = 0x4000
} TYPEFLAGS;

typedef enum tagFUNCFLAGS
{
    FUNCFLAG_FRESTRICTED = 0x1,
    FUNCFLAG_FSOURCE = 0x2,
    FUNCFLAG_FBINDABLE = 0x4,
    FUNCFLAG_FREQUESTEDIT = 0x8,
    FUNCFLAG_FDISPLAYBIND = 0x10,
    FUNCFLAG_FDEFAULTBIND = 0x20,
    FUNCFLAG_FHIDDEN = 0x40,
    FUNCFLAG_FUSESGETLASTERROR = 0x80,
    FUNCFLAG_FDEFAULTCOLLELEM = 0x100,
    FUNCFLAG_FUIDEFAULT = 0x200,
    FUNCFLAG_FNONBROWSABLE = 0x400,
    FUNCFLAG_FREPLACEABLE = 0x800,
    FUNCFLAG_FIMMEDIATEBIND = 0x1000
} FUNCFLAGS;

typedef enum tagVARFLAGS
{
    VARFLAG_FREADONLY = 0x1,
    VARFLAG_FSOURCE = 0x2,
    VARFLAG_FBINDABLE = 0x4,
    VARFLAG_FREQUESTEDIT = 0x8,
    VARFLAG_FDISPLAYBIND = 0x10,
    VARFLAG_FDEFAULTBIND = 0x20,
    VARFLAG_FHIDDEN = 0x40,
    VARFLAG_FRESTRICTED = 0x80,
    VARFLAG_FDEFAULTCOLLELEM = 0x100,
    VARFLAG_FUIDEFAULT = 0x200,
    VARFLAG_FNONBROWSABLE = 0x400,
    VARFLAG_FREPLACEABLE = 0x800,
    VARFLAG_FIMMEDIATEBIND = 0x1000
} VARFLAGS;

typedef /* [wire_marshal] */ struct tagCLEANLOCALSTORAGE
{
    IUnknown *pInterface;
    PVOID pStorage;
    DWORD flags;
} CLEANLOCALSTORAGE;

typedef struct tagCUSTDATAITEM
{
    GUID guid;
    VARIANTARG varValue;
} CUSTDATAITEM;

typedef struct tagCUSTDATAITEM *LPCUSTDATAITEM;

typedef struct tagCUSTDATA
{
    DWORD cCustData;
    LPCUSTDATAITEM prgCustData;
} CUSTDATA;

typedef struct tagCUSTDATA *LPCUSTDATA;

#ifndef __ITypeComp_INTERFACE_DEFINED__
#define __ITypeComp_INTERFACE_DEFINED__

/* interface ITypeComp */
/* [unique][uuid][object] */
struct ITypeComp;
typedef /* [unique] */ __RPC_unique_pointer struct ITypeComp *LPTYPECOMP;

typedef /* [v1_enum] */
    enum tagDESCKIND
{
    DESCKIND_NONE = 0,
    DESCKIND_FUNCDESC = (DESCKIND_NONE + 1),
    DESCKIND_VARDESC = (DESCKIND_FUNCDESC + 1),
    DESCKIND_TYPECOMP = (DESCKIND_VARDESC + 1),
    DESCKIND_IMPLICITAPPOBJ = (DESCKIND_TYPECOMP + 1),
    DESCKIND_MAX = (DESCKIND_IMPLICITAPPOBJ + 1)
} DESCKIND;

typedef union tagBINDPTR {
    FUNCDESC *lpfuncdesc;
    VARDESC *lpvardesc;
    ITypeComp *lptcomp;
} BINDPTR;

typedef union tagBINDPTR *LPBINDPTR;

struct ITypeInfo;

DEFINE_GUID(IID_ITypeComp, 0x00020403, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE ITypeComp
DECLARE_INTERFACE_(ITypeComp, IUnknown)
{
    DECLARE_CLASS_SIID(IID_ITypeComp)
  public:
    virtual /* [local] */ HRESULT STDMETHODCALLTYPE Bind(
        /* [in] */ LPOLESTR szName,
        /* [in] */ ULONG lHashVal,
        /* [in] */ WORD wFlags,
        /* [out] */ ITypeInfo * *ppTInfo,
        /* [out] */ DESCKIND * pDescKind,
        /* [out] */ BINDPTR * pBindPtr)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE BindType(
        /* [in] */ LPOLESTR szName,
        /* [in] */ ULONG lHashVal,
        /* [out] */ ITypeInfo * *ppTInfo,
        /* [out] */ ITypeComp * *ppTComp)
        = 0;
};

#else /* C style interface */

typedef struct ITypeCompVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (ITypeComp *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [iid_is][out] */
     __RPC__deref_out void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(ITypeComp *This);

    ULONG(STDMETHODCALLTYPE *Release)(ITypeComp *This);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *Bind)(ITypeComp *This,
                                                   /* [in] */ LPOLESTR szName,
                                                   /* [in] */ ULONG lHashVal,
                                                   /* [in] */ WORD wFlags,
                                                   /* [out] */ ITypeInfo **ppTInfo,
                                                   /* [out] */ DESCKIND *pDescKind,
                                                   /* [out] */ BINDPTR *pBindPtr);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *BindType)(ITypeComp *This,
                                                       /* [in] */ LPOLESTR szName,
                                                       /* [in] */ ULONG lHashVal,
                                                       /* [out] */ ITypeInfo **ppTInfo,
                                                       /* [out] */ ITypeComp **ppTComp);

    END_INTERFACE
} ITypeCompVtbl;

interface ITypeComp
{
    CONST_VTBL struct ITypeCompVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define ITypeComp_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define ITypeComp_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define ITypeComp_Release(This) ((This)->lpVtbl->Release(This))

#define ITypeComp_Bind(This, szName, lHashVal, wFlags, ppTInfo, pDescKind, pBindPtr) ((This)->lpVtbl->Bind(This, szName, lHashVal, wFlags, ppTInfo, pDescKind, pBindPtr))

#define ITypeComp_BindType(This, szName, lHashVal, ppTInfo, ppTComp) ((This)->lpVtbl->BindType(This, szName, lHashVal, ppTInfo, ppTComp))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __ITypeComp_INTERFACE_DEFINED__ */

#ifndef __ITypeLib_INTERFACE_DEFINED__
#define __ITypeLib_INTERFACE_DEFINED__

/* interface ITypeLib */
/* [unique][uuid][object] */

typedef /* [v1_enum] */
    enum tagSYSKIND
{
    SYS_WIN16 = 0,
    SYS_WIN32 = (SYS_WIN16 + 1),
    SYS_MAC = (SYS_WIN32 + 1),
    SYS_WIN64 = (SYS_MAC + 1)
} SYSKIND;

typedef /* [v1_enum] */
    enum tagLIBFLAGS
{
    LIBFLAG_FRESTRICTED = 0x1,
    LIBFLAG_FCONTROL = 0x2,
    LIBFLAG_FHIDDEN = 0x4,
    LIBFLAG_FHASDISKIMAGE = 0x8
} LIBFLAGS;

struct ITypeLib;
typedef /* [unique] */ __RPC_unique_pointer struct ITypeLib *LPTYPELIB;

typedef struct tagTLIBATTR
{
    GUID guid;
    LCID lcid;
    SYSKIND syskind;
    WORD wMajorVerNum;
    WORD wMinorVerNum;
    WORD wLibFlags;
} TLIBATTR;

typedef struct tagTLIBATTR *LPTLIBATTR;

DEFINE_GUID(IID_ITypeLib, 0x00020402, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE ITypeLib
DECLARE_INTERFACE_(ITypeLib, IUnknown)
{
    DECLARE_CLASS_SIID(IID_ITypeLib)
  public:
    virtual /* [local] */ UINT STDMETHODCALLTYPE GetTypeInfoCount(void) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(
        /* [in] */ UINT index,
        /* [out] */ __RPC__deref_out_opt ITypeInfo * *ppTInfo)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetTypeInfoType(
        /* [in] */ UINT index,
        /* [out] */ __RPC__out TYPEKIND * pTKind)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetTypeInfoOfGuid(
        /* [in] */ __RPC__in REFGUID guid,
        /* [out] */ __RPC__deref_out_opt ITypeInfo * *ppTinfo)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetLibAttr(
        /* [out] */ TLIBATTR * *ppTLibAttr)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetTypeComp(
        /* [out] */ __RPC__deref_out_opt ITypeComp * *ppTComp)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetDocumentation(
        /* [in] */ INT index,
        /* [out] */ BSTR * pBstrName,
        /* [out] */ BSTR * pBstrDocString,
        /* [out] */ DWORD * pdwHelpContext,
        /* [out] */ BSTR * pBstrHelpFile)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE IsName(
        /* [out][in] */ LPOLESTR szNameBuf,
        /* [in] */ ULONG lHashVal,
        /* [out] */ BOOL * pfName)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE FindName(
        /* [out][in] */ LPOLESTR szNameBuf,
        /* [in] */ ULONG lHashVal,
        /* [length_is][size_is][out] */ ITypeInfo * *ppTInfo,
        /* [length_is][size_is][out] */ MEMBERID * rgMemId,
        /* [out][in] */ USHORT * pcFound)
        = 0;

    virtual /* [local] */ void STDMETHODCALLTYPE ReleaseTLibAttr(
        /* [in] */ TLIBATTR * pTLibAttr)
        = 0;
};

#else /* C style interface */

typedef struct ITypeLibVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (ITypeLib *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [iid_is][out] */
     __RPC__deref_out void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(ITypeLib *This);

    ULONG(STDMETHODCALLTYPE *Release)(ITypeLib *This);

    /* [local] */ UINT(STDMETHODCALLTYPE *GetTypeInfoCount)(ITypeLib *This);

    HRESULT(STDMETHODCALLTYPE *GetTypeInfo)
    (ITypeLib *This,
     /* [in] */ UINT index,
     /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);

    HRESULT(STDMETHODCALLTYPE *GetTypeInfoType)
    (ITypeLib *This,
     /* [in] */ UINT index,
     /* [out] */ __RPC__out TYPEKIND *pTKind);

    HRESULT(STDMETHODCALLTYPE *GetTypeInfoOfGuid)
    (ITypeLib *This,
     /* [in] */ __RPC__in REFGUID guid,
     /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTinfo);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *GetLibAttr)(ITypeLib *This,
                                                         /* [out] */ TLIBATTR **ppTLibAttr);

    HRESULT(STDMETHODCALLTYPE *GetTypeComp)
    (ITypeLib *This,
     /* [out] */ __RPC__deref_out_opt ITypeComp **ppTComp);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *GetDocumentation)(ITypeLib *This,
                                                               /* [in] */ INT index,
                                                               /* [out] */ BSTR *pBstrName,
                                                               /* [out] */ BSTR *pBstrDocString,
                                                               /* [out] */ DWORD *pdwHelpContext,
                                                               /* [out] */ BSTR *pBstrHelpFile);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *IsName)(ITypeLib *This,
                                                     /* [out][in] */ LPOLESTR szNameBuf,
                                                     /* [in] */ ULONG lHashVal,
                                                     /* [out] */ BOOL *pfName);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *FindName)(ITypeLib *This,
                                                       /* [out][in] */ LPOLESTR szNameBuf,
                                                       /* [in] */ ULONG lHashVal,
                                                       /* [length_is][size_is][out] */ ITypeInfo **ppTInfo,
                                                       /* [length_is][size_is][out] */ MEMBERID *rgMemId,
                                                       /* [out][in] */ USHORT *pcFound);

    /* [local] */ void(STDMETHODCALLTYPE *ReleaseTLibAttr)(ITypeLib *This,
                                                           /* [in] */ TLIBATTR *pTLibAttr);

    END_INTERFACE
} ITypeLibVtbl;

interface ITypeLib
{
    CONST_VTBL struct ITypeLibVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define ITypeLib_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define ITypeLib_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define ITypeLib_Release(This) ((This)->lpVtbl->Release(This))

#define ITypeLib_GetTypeInfoCount(This) ((This)->lpVtbl->GetTypeInfoCount(This))

#define ITypeLib_GetTypeInfo(This, index, ppTInfo) ((This)->lpVtbl->GetTypeInfo(This, index, ppTInfo))

#define ITypeLib_GetTypeInfoType(This, index, pTKind) ((This)->lpVtbl->GetTypeInfoType(This, index, pTKind))

#define ITypeLib_GetTypeInfoOfGuid(This, guid, ppTinfo) ((This)->lpVtbl->GetTypeInfoOfGuid(This, guid, ppTinfo))

#define ITypeLib_GetLibAttr(This, ppTLibAttr) ((This)->lpVtbl->GetLibAttr(This, ppTLibAttr))

#define ITypeLib_GetTypeComp(This, ppTComp) ((This)->lpVtbl->GetTypeComp(This, ppTComp))

#define ITypeLib_GetDocumentation(This, index, pBstrName, pBstrDocString, pdwHelpContext, pBstrHelpFile) ((This)->lpVtbl->GetDocumentation(This, index, pBstrName, pBstrDocString, pdwHelpContext, pBstrHelpFile))

#define ITypeLib_IsName(This, szNameBuf, lHashVal, pfName) ((This)->lpVtbl->IsName(This, szNameBuf, lHashVal, pfName))

#define ITypeLib_FindName(This, szNameBuf, lHashVal, ppTInfo, rgMemId, pcFound) ((This)->lpVtbl->FindName(This, szNameBuf, lHashVal, ppTInfo, rgMemId, pcFound))

#define ITypeLib_ReleaseTLibAttr(This, pTLibAttr) ((This)->lpVtbl->ReleaseTLibAttr(This, pTLibAttr))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __ITypeLib_INTERFACE_DEFINED__ */

#ifndef __ITypeInfo_INTERFACE_DEFINED__
#define __ITypeInfo_INTERFACE_DEFINED__

/* interface ITypeInfo */
/* [unique][uuid][object] */

typedef /* [unique] */ __RPC_unique_pointer struct ITypeInfo *LPTYPEINFO;
struct ITypeLib;

DEFINE_GUID(IID_ITypeInfo, 0x00020401, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE ITypeInfo
DECLARE_INTERFACE_(ITypeInfo, IUnknown)
{
    DECLARE_CLASS_SIID(IID_ITypeInfo)
  public:
    virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetTypeAttr(
        /* [out] */ TYPEATTR * *ppTypeAttr)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetTypeComp(
        /* [out] */ __RPC__deref_out_opt ITypeComp * *ppTComp)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetFuncDesc(
        /* [in] */ UINT index,
        /* [out] */ FUNCDESC * *ppFuncDesc)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetVarDesc(
        /* [in] */ UINT index,
        /* [out] */ VARDESC * *ppVarDesc)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetNames(
        /* [in] */ MEMBERID memid,
        /* [length_is][size_is][out] */ BSTR * rgBstrNames,
        /* [in] */ UINT cMaxNames,
        /* [out] */ UINT * pcNames)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetRefTypeOfImplType(
        /* [in] */ UINT index,
        /* [out] */ __RPC__out HREFTYPE * pRefType)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetImplTypeFlags(
        /* [in] */ UINT index,
        /* [out] */ __RPC__out INT * pImplTypeFlags)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetIDsOfNames(
        /* [size_is][in] */ LPOLESTR * rgszNames,
        /* [in] */ UINT cNames,
        /* [size_is][out] */ MEMBERID * pMemId)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE Invoke(
        /* [in] */ PVOID pvInstance,
        /* [in] */ MEMBERID memid,
        /* [in] */ WORD wFlags,
        /* [out][in] */ DISPPARAMS * pDispParams,
        /* [out] */ VARIANT * pVarResult,
        /* [out] */ EXCEPINFO * pExcepInfo,
        /* [out] */ UINT * puArgErr)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetDocumentation(
        /* [in] */ MEMBERID memid,
        /* [out] */ BSTR * pBstrName,
        /* [out] */ BSTR * pBstrDocString,
        /* [out] */ DWORD * pdwHelpContext,
        /* [out] */ BSTR * pBstrHelpFile)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetDllEntry(
        /* [in] */ MEMBERID memid,
        /* [in] */ INVOKEKIND invKind,
        /* [out] */ BSTR * pBstrDllName,
        /* [out] */ BSTR * pBstrName,
        /* [out] */ WORD * pwOrdinal)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetRefTypeInfo(
        /* [in] */ HREFTYPE hRefType,
        /* [out] */ __RPC__deref_out_opt ITypeInfo * *ppTInfo)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE AddressOfMember(
        /* [in] */ MEMBERID memid,
        /* [in] */ INVOKEKIND invKind,
        /* [out] */ PVOID * ppv)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE CreateInstance(
        /* [in] */ IUnknown * pUnkOuter,
        /* [in] */ REFIID riid,
        /* [iid_is][out] */ PVOID * ppvObj)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetMops(
        /* [in] */ MEMBERID memid,
        /* [out] */ __RPC__deref_out_opt BSTR * pBstrMops)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetContainingTypeLib(
        /* [out] */ ITypeLib * *ppTLib,
        /* [out] */ UINT * pIndex)
        = 0;

    virtual /* [local] */ void STDMETHODCALLTYPE ReleaseTypeAttr(
        /* [in] */ TYPEATTR * pTypeAttr)
        = 0;

    virtual /* [local] */ void STDMETHODCALLTYPE ReleaseFuncDesc(
        /* [in] */ FUNCDESC * pFuncDesc)
        = 0;

    virtual /* [local] */ void STDMETHODCALLTYPE ReleaseVarDesc(
        /* [in] */ VARDESC * pVarDesc)
        = 0;
};

#else /* C style interface */

typedef struct ITypeInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (ITypeInfo *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [iid_is][out] */
     __RPC__deref_out void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(ITypeInfo *This);

    ULONG(STDMETHODCALLTYPE *Release)(ITypeInfo *This);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *GetTypeAttr)(ITypeInfo *This,
                                                          /* [out] */ TYPEATTR **ppTypeAttr);

    HRESULT(STDMETHODCALLTYPE *GetTypeComp)
    (ITypeInfo *This,
     /* [out] */ __RPC__deref_out_opt ITypeComp **ppTComp);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *GetFuncDesc)(ITypeInfo *This,
                                                          /* [in] */ UINT index,
                                                          /* [out] */ FUNCDESC **ppFuncDesc);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *GetVarDesc)(ITypeInfo *This,
                                                         /* [in] */ UINT index,
                                                         /* [out] */ VARDESC **ppVarDesc);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *GetNames)(ITypeInfo *This,
                                                       /* [in] */ MEMBERID memid,
                                                       /* [length_is][size_is][out] */ BSTR *rgBstrNames,
                                                       /* [in] */ UINT cMaxNames,
                                                       /* [out] */ UINT *pcNames);

    HRESULT(STDMETHODCALLTYPE *GetRefTypeOfImplType)
    (ITypeInfo *This,
     /* [in] */ UINT index,
     /* [out] */ __RPC__out HREFTYPE *pRefType);

    HRESULT(STDMETHODCALLTYPE *GetImplTypeFlags)
    (ITypeInfo *This,
     /* [in] */ UINT index,
     /* [out] */ __RPC__out INT *pImplTypeFlags);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *GetIDsOfNames)(ITypeInfo *This,
                                                            /* [size_is][in] */ LPOLESTR *rgszNames,
                                                            /* [in] */ UINT cNames,
                                                            /* [size_is][out] */ MEMBERID *pMemId);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *Invoke)(ITypeInfo *This,
                                                     /* [in] */ PVOID pvInstance,
                                                     /* [in] */ MEMBERID memid,
                                                     /* [in] */ WORD wFlags,
                                                     /* [out][in] */ DISPPARAMS *pDispParams,
                                                     /* [out] */ VARIANT *pVarResult,
                                                     /* [out] */ EXCEPINFO *pExcepInfo,
                                                     /* [out] */ UINT *puArgErr);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *GetDocumentation)(ITypeInfo *This,
                                                               /* [in] */ MEMBERID memid,
                                                               /* [out] */ BSTR *pBstrName,
                                                               /* [out] */ BSTR *pBstrDocString,
                                                               /* [out] */ DWORD *pdwHelpContext,
                                                               /* [out] */ BSTR *pBstrHelpFile);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *GetDllEntry)(ITypeInfo *This,
                                                          /* [in] */ MEMBERID memid,
                                                          /* [in] */ INVOKEKIND invKind,
                                                          /* [out] */ BSTR *pBstrDllName,
                                                          /* [out] */ BSTR *pBstrName,
                                                          /* [out] */ WORD *pwOrdinal);

    HRESULT(STDMETHODCALLTYPE *GetRefTypeInfo)
    (ITypeInfo *This,
     /* [in] */ HREFTYPE hRefType,
     /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *AddressOfMember)(ITypeInfo *This,
                                                              /* [in] */ MEMBERID memid,
                                                              /* [in] */ INVOKEKIND invKind,
                                                              /* [out] */ PVOID *ppv);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *CreateInstance)(ITypeInfo *This,
                                                             /* [in] */ IUnknown *pUnkOuter,
                                                             /* [in] */ REFIID riid,
                                                             /* [iid_is][out] */ PVOID *ppvObj);

    HRESULT(STDMETHODCALLTYPE *GetMops)
    (ITypeInfo *This,
     /* [in] */ MEMBERID memid,
     /* [out] */ __RPC__deref_out_opt BSTR *pBstrMops);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *GetContainingTypeLib)(ITypeInfo *This,
                                                                   /* [out] */ ITypeLib **ppTLib,
                                                                   /* [out] */ UINT *pIndex);

    /* [local] */ void(STDMETHODCALLTYPE *ReleaseTypeAttr)(ITypeInfo *This,
                                                           /* [in] */ TYPEATTR *pTypeAttr);

    /* [local] */ void(STDMETHODCALLTYPE *ReleaseFuncDesc)(ITypeInfo *This,
                                                           /* [in] */ FUNCDESC *pFuncDesc);

    /* [local] */ void(STDMETHODCALLTYPE *ReleaseVarDesc)(ITypeInfo *This,
                                                          /* [in] */ VARDESC *pVarDesc);

    END_INTERFACE
} ITypeInfoVtbl;

interface ITypeInfo
{
    CONST_VTBL struct ITypeInfoVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define ITypeInfo_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define ITypeInfo_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define ITypeInfo_Release(This) ((This)->lpVtbl->Release(This))

#define ITypeInfo_GetTypeAttr(This, ppTypeAttr) ((This)->lpVtbl->GetTypeAttr(This, ppTypeAttr))

#define ITypeInfo_GetTypeComp(This, ppTComp) ((This)->lpVtbl->GetTypeComp(This, ppTComp))

#define ITypeInfo_GetFuncDesc(This, index, ppFuncDesc) ((This)->lpVtbl->GetFuncDesc(This, index, ppFuncDesc))

#define ITypeInfo_GetVarDesc(This, index, ppVarDesc) ((This)->lpVtbl->GetVarDesc(This, index, ppVarDesc))

#define ITypeInfo_GetNames(This, memid, rgBstrNames, cMaxNames, pcNames) ((This)->lpVtbl->GetNames(This, memid, rgBstrNames, cMaxNames, pcNames))

#define ITypeInfo_GetRefTypeOfImplType(This, index, pRefType) ((This)->lpVtbl->GetRefTypeOfImplType(This, index, pRefType))

#define ITypeInfo_GetImplTypeFlags(This, index, pImplTypeFlags) ((This)->lpVtbl->GetImplTypeFlags(This, index, pImplTypeFlags))

#define ITypeInfo_GetIDsOfNames(This, rgszNames, cNames, pMemId) ((This)->lpVtbl->GetIDsOfNames(This, rgszNames, cNames, pMemId))

#define ITypeInfo_Invoke(This, pvInstance, memid, wFlags, pDispParams, pVarResult, pExcepInfo, puArgErr) ((This)->lpVtbl->Invoke(This, pvInstance, memid, wFlags, pDispParams, pVarResult, pExcepInfo, puArgErr))

#define ITypeInfo_GetDocumentation(This, memid, pBstrName, pBstrDocString, pdwHelpContext, pBstrHelpFile) ((This)->lpVtbl->GetDocumentation(This, memid, pBstrName, pBstrDocString, pdwHelpContext, pBstrHelpFile))

#define ITypeInfo_GetDllEntry(This, memid, invKind, pBstrDllName, pBstrName, pwOrdinal) ((This)->lpVtbl->GetDllEntry(This, memid, invKind, pBstrDllName, pBstrName, pwOrdinal))

#define ITypeInfo_GetRefTypeInfo(This, hRefType, ppTInfo) ((This)->lpVtbl->GetRefTypeInfo(This, hRefType, ppTInfo))

#define ITypeInfo_AddressOfMember(This, memid, invKind, ppv) ((This)->lpVtbl->AddressOfMember(This, memid, invKind, ppv))

#define ITypeInfo_CreateInstance(This, pUnkOuter, riid, ppvObj) ((This)->lpVtbl->CreateInstance(This, pUnkOuter, riid, ppvObj))

#define ITypeInfo_GetMops(This, memid, pBstrMops) ((This)->lpVtbl->GetMops(This, memid, pBstrMops))

#define ITypeInfo_GetContainingTypeLib(This, ppTLib, pIndex) ((This)->lpVtbl->GetContainingTypeLib(This, ppTLib, pIndex))

#define ITypeInfo_ReleaseTypeAttr(This, pTypeAttr) ((This)->lpVtbl->ReleaseTypeAttr(This, pTypeAttr))

#define ITypeInfo_ReleaseFuncDesc(This, pFuncDesc) ((This)->lpVtbl->ReleaseFuncDesc(This, pFuncDesc))

#define ITypeInfo_ReleaseVarDesc(This, pVarDesc) ((This)->lpVtbl->ReleaseVarDesc(This, pVarDesc))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __ITypeInfo_INTERFACE_DEFINED__ */

#ifndef __IDispatch_INTERFACE_DEFINED__
#define __IDispatch_INTERFACE_DEFINED__
/* interface IDispatch */
/* [unique][uuid][object] */

typedef struct IDispatch *LPDISPATCH;

/* DISPID reserved to indicate an "unknown" name */
/* only reserved for data members (properties); reused as a method dispid below */
#define DISPID_UNKNOWN (-1)

/* DISPID reserved for the "value" property */
#define DISPID_VALUE (0)

/* The following DISPID is reserved to indicate the param
 * that is the right-hand-side (or "put" value) of a PropertyPut
 */
#define DISPID_PROPERTYPUT (-3)

/* DISPID reserved for the standard "NewEnum" method */
#define DISPID_NEWENUM (-4)

/* DISPID reserved for the standard "Evaluate" method */
#define DISPID_EVALUATE (-5)

#define DISPID_CONSTRUCTOR (-6)

#define DISPID_DESTRUCTOR (-7)

#define DISPID_COLLECT (-8)

/* The range -500 through -999 is reserved for Controls */
/* The range 0x80010000 through 0x8001FFFF is reserved for Controls */
/* The range -5000 through -5499 is reserved for ActiveX Accessability */
/* The range -2000 through -2499 is reserved for VB5 */
/* The range -3900 through -3999 is reserved for Forms */
/* The range -5500 through -5550 is reserved for Forms */
/* The remainder of the negative DISPIDs are reserved for future use */

/* Flags for IDispatch::Invoke */
#define DISPATCH_METHOD         0x1
#define DISPATCH_PROPERTYGET    0x2
#define DISPATCH_PROPERTYPUT    0x4
#define DISPATCH_PROPERTYPUTREF 0x8

DEFINE_GUID(IID_IDispatch, 0x00020400, 0, 0, 0xC0, 0, 0, 0, 0, 0, 0, 0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE IDispatch
DECLARE_INTERFACE_(IDispatch, IUnknown)
{
    DECLARE_CLASS_SIID(IID_IDispatch)
  public:
    virtual HRESULT STDMETHODCALLTYPE GetTypeInfoCount(
        /* [out] */ __RPC__out UINT * pctinfo)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(
        /* [in] */ UINT iTInfo,
        /* [in] */ LCID lcid,
        /* [out] */ __RPC__deref_out_opt ITypeInfo * *ppTInfo)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetIDsOfNames(
        /* [in] */ __RPC__in REFIID riid,
        /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR * rgszNames,
        /* [range][in] */ UINT cNames,
        /* [in] */ LCID lcid,
        /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID * rgDispId)
        = 0;

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE Invoke(
        /* [in] */ DISPID dispIdMember,
        /* [in] */ REFIID riid,
        /* [in] */ LCID lcid,
        /* [in] */ WORD wFlags,
        /* [out][in] */ DISPPARAMS * pDispParams,
        /* [out] */ VARIANT * pVarResult,
        /* [out] */ EXCEPINFO * pExcepInfo,
        /* [out] */ UINT * puArgErr)
        = 0;
};

#else /* C style interface */

typedef struct IDispatchVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (IDispatch *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [iid_is][out] */
     __RPC__deref_out void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(IDispatch *This);

    ULONG(STDMETHODCALLTYPE *Release)(IDispatch *This);

    HRESULT(STDMETHODCALLTYPE *GetTypeInfoCount)
    (IDispatch *This,
     /* [out] */ __RPC__out UINT *pctinfo);

    HRESULT(STDMETHODCALLTYPE *GetTypeInfo)
    (IDispatch *This,
     /* [in] */ UINT iTInfo,
     /* [in] */ LCID lcid,
     /* [out] */ __RPC__deref_out_opt ITypeInfo **ppTInfo);

    HRESULT(STDMETHODCALLTYPE *GetIDsOfNames)
    (IDispatch *This,
     /* [in] */ __RPC__in REFIID riid,
     /* [size_is][in] */ __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
     /* [range][in] */ UINT cNames,
     /* [in] */ LCID lcid,
     /* [size_is][out] */ __RPC__out_ecount_full(cNames) DISPID *rgDispId);

    /* [local] */ HRESULT(STDMETHODCALLTYPE *Invoke)(IDispatch *This,
                                                     /* [in] */ DISPID dispIdMember,
                                                     /* [in] */ REFIID riid,
                                                     /* [in] */ LCID lcid,
                                                     /* [in] */ WORD wFlags,
                                                     /* [out][in] */ DISPPARAMS *pDispParams,
                                                     /* [out] */ VARIANT *pVarResult,
                                                     /* [out] */ EXCEPINFO *pExcepInfo,
                                                     /* [out] */ UINT *puArgErr);

    END_INTERFACE
} IDispatchVtbl;

interface IDispatch
{
    CONST_VTBL struct IDispatchVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IDispatch_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IDispatch_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IDispatch_Release(This) ((This)->lpVtbl->Release(This))

#define IDispatch_GetTypeInfoCount(This, pctinfo) ((This)->lpVtbl->GetTypeInfoCount(This, pctinfo))

#define IDispatch_GetTypeInfo(This, iTInfo, lcid, ppTInfo) ((This)->lpVtbl->GetTypeInfo(This, iTInfo, lcid, ppTInfo))

#define IDispatch_GetIDsOfNames(This, riid, rgszNames, cNames, lcid, rgDispId) ((This)->lpVtbl->GetIDsOfNames(This, riid, rgszNames, cNames, lcid, rgDispId))

#define IDispatch_Invoke(This, dispIdMember, riid, lcid, wFlags, pDispParams, pVarResult, pExcepInfo, puArgErr) ((This)->lpVtbl->Invoke(This, dispIdMember, riid, lcid, wFlags, pDispParams, pVarResult, pExcepInfo, puArgErr))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif //__IDispatch_INTERFACE_DEFINED__

#ifndef __IRecordInfo_INTERFACE_DEFINED__
#define __IRecordInfo_INTERFACE_DEFINED__

/* interface IRecordInfo */
/* [uuid][object][local] */

typedef /* [unique] */ struct IRecordInfo *LPRECORDINFO;

struct ITypeInfo;

DEFINE_GUID(IID_IRecordInfo, 0x0000002F, 0, 0, 0xc0, 0, 0, 0, 0, 0, 0, 0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)

#undef INTERFACE
#define INTERFACE IRecordInfo
DECLARE_INTERFACE_(IRecordInfo, IUnknown)
{
  public:
    virtual HRESULT STDMETHODCALLTYPE RecordInit(
        /* [out] */ PVOID pvNew)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE RecordClear(
        /* [in] */ PVOID pvExisting)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE RecordCopy(
        /* [in] */ PVOID pvExisting,
        /* [out] */ PVOID pvNew)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetGuid(
        /* [out] */ GUID * pguid)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetName(
        /* [out] */ BSTR * pbstrName)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetSize(
        /* [out] */ ULONG * pcbSize)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetTypeInfo(
        /* [out] */ ITypeInfo * *ppTypeInfo)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetField(
        /* [in] */ PVOID pvData,
        /* [in] */ LPCOLESTR szFieldName,
        /* [out] */ VARIANT * pvarField)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetFieldNoCopy(
        /* [in] */ PVOID pvData,
        /* [in] */ LPCOLESTR szFieldName,
        /* [out] */ VARIANT * pvarField,
        /* [out] */ PVOID * ppvDataCArray)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE PutField(
        /* [in] */ ULONG wFlags,
        /* [out][in] */ PVOID pvData,
        /* [in] */ LPCOLESTR szFieldName,
        /* [in] */ VARIANT * pvarField)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE PutFieldNoCopy(
        /* [in] */ ULONG wFlags,
        /* [out][in] */ PVOID pvData,
        /* [in] */ LPCOLESTR szFieldName,
        /* [in] */ VARIANT * pvarField)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE GetFieldNames(
        /* [out][in] */ ULONG * pcNames,
        /* [length_is][size_is][out] */ BSTR * rgBstrNames)
        = 0;

    virtual BOOL STDMETHODCALLTYPE IsMatchingType(
        /* [in] */ IRecordInfo * pRecordInfo)
        = 0;

    virtual PVOID STDMETHODCALLTYPE RecordCreate(void) = 0;

    virtual HRESULT STDMETHODCALLTYPE RecordCreateCopy(
        /* [in] */ PVOID pvSource,
        /* [out] */ PVOID * ppvDest)
        = 0;

    virtual HRESULT STDMETHODCALLTYPE RecordDestroy(
        /* [in] */ PVOID pvRecord)
        = 0;
};

#else /* C style interface */

typedef struct IRecordInfoVtbl
{
    BEGIN_INTERFACE

    HRESULT(STDMETHODCALLTYPE *QueryInterface)
    (IRecordInfo *This,
     /* [in] */ REFIID riid,
     /* [iid_is][out] */
     __RPC__deref_out void **ppvObject);

    ULONG(STDMETHODCALLTYPE *AddRef)(IRecordInfo *This);

    ULONG(STDMETHODCALLTYPE *Release)(IRecordInfo *This);

    HRESULT(STDMETHODCALLTYPE *RecordInit)
    (IRecordInfo *This,
     /* [out] */ PVOID pvNew);

    HRESULT(STDMETHODCALLTYPE *RecordClear)
    (IRecordInfo *This,
     /* [in] */ PVOID pvExisting);

    HRESULT(STDMETHODCALLTYPE *RecordCopy)
    (IRecordInfo *This,
     /* [in] */ PVOID pvExisting,
     /* [out] */ PVOID pvNew);

    HRESULT(STDMETHODCALLTYPE *GetGuid)
    (IRecordInfo *This,
     /* [out] */ GUID *pguid);

    HRESULT(STDMETHODCALLTYPE *GetName)
    (IRecordInfo *This,
     /* [out] */ BSTR *pbstrName);

    HRESULT(STDMETHODCALLTYPE *GetSize)
    (IRecordInfo *This,
     /* [out] */ ULONG *pcbSize);

    HRESULT(STDMETHODCALLTYPE *GetTypeInfo)
    (IRecordInfo *This,
     /* [out] */ ITypeInfo **ppTypeInfo);

    HRESULT(STDMETHODCALLTYPE *GetField)
    (IRecordInfo *This,
     /* [in] */ PVOID pvData,
     /* [in] */ LPCOLESTR szFieldName,
     /* [out] */ VARIANT *pvarField);

    HRESULT(STDMETHODCALLTYPE *GetFieldNoCopy)
    (IRecordInfo *This,
     /* [in] */ PVOID pvData,
     /* [in] */ LPCOLESTR szFieldName,
     /* [out] */ VARIANT *pvarField,
     /* [out] */ PVOID *ppvDataCArray);

    HRESULT(STDMETHODCALLTYPE *PutField)
    (IRecordInfo *This,
     /* [in] */ ULONG wFlags,
     /* [out][in] */ PVOID pvData,
     /* [in] */ LPCOLESTR szFieldName,
     /* [in] */ VARIANT *pvarField);

    HRESULT(STDMETHODCALLTYPE *PutFieldNoCopy)
    (IRecordInfo *This,
     /* [in] */ ULONG wFlags,
     /* [out][in] */ PVOID pvData,
     /* [in] */ LPCOLESTR szFieldName,
     /* [in] */ VARIANT *pvarField);

    HRESULT(STDMETHODCALLTYPE *GetFieldNames)
    (IRecordInfo *This,
     /* [out][in] */ ULONG *pcNames,
     /* [length_is][size_is][out] */ BSTR *rgBstrNames);

    BOOL(STDMETHODCALLTYPE *IsMatchingType)
    (IRecordInfo *This,
     /* [in] */ IRecordInfo *pRecordInfo);

    PVOID(STDMETHODCALLTYPE *RecordCreate)(IRecordInfo *This);

    HRESULT(STDMETHODCALLTYPE *RecordCreateCopy)
    (IRecordInfo *This,
     /* [in] */ PVOID pvSource,
     /* [out] */ PVOID *ppvDest);

    HRESULT(STDMETHODCALLTYPE *RecordDestroy)
    (IRecordInfo *This,
     /* [in] */ PVOID pvRecord);

    END_INTERFACE
} IRecordInfoVtbl;

interface IRecordInfo
{
    CONST_VTBL struct IRecordInfoVtbl *lpVtbl;
};

#ifdef COBJMACROS

#define IRecordInfo_QueryInterface(This, riid, ppvObject) ((This)->lpVtbl->QueryInterface(This, riid, ppvObject))

#define IRecordInfo_AddRef(This) ((This)->lpVtbl->AddRef(This))

#define IRecordInfo_Release(This) ((This)->lpVtbl->Release(This))

#define IRecordInfo_RecordInit(This, pvNew) ((This)->lpVtbl->RecordInit(This, pvNew))

#define IRecordInfo_RecordClear(This, pvExisting) ((This)->lpVtbl->RecordClear(This, pvExisting))

#define IRecordInfo_RecordCopy(This, pvExisting, pvNew) ((This)->lpVtbl->RecordCopy(This, pvExisting, pvNew))

#define IRecordInfo_GetGuid(This, pguid) ((This)->lpVtbl->GetGuid(This, pguid))

#define IRecordInfo_GetName(This, pbstrName) ((This)->lpVtbl->GetName(This, pbstrName))

#define IRecordInfo_GetSize(This, pcbSize) ((This)->lpVtbl->GetSize(This, pcbSize))

#define IRecordInfo_GetTypeInfo(This, ppTypeInfo) ((This)->lpVtbl->GetTypeInfo(This, ppTypeInfo))

#define IRecordInfo_GetField(This, pvData, szFieldName, pvarField) ((This)->lpVtbl->GetField(This, pvData, szFieldName, pvarField))

#define IRecordInfo_GetFieldNoCopy(This, pvData, szFieldName, pvarField, ppvDataCArray) ((This)->lpVtbl->GetFieldNoCopy(This, pvData, szFieldName, pvarField, ppvDataCArray))

#define IRecordInfo_PutField(This, wFlags, pvData, szFieldName, pvarField) ((This)->lpVtbl->PutField(This, wFlags, pvData, szFieldName, pvarField))

#define IRecordInfo_PutFieldNoCopy(This, wFlags, pvData, szFieldName, pvarField) ((This)->lpVtbl->PutFieldNoCopy(This, wFlags, pvData, szFieldName, pvarField))

#define IRecordInfo_GetFieldNames(This, pcNames, rgBstrNames) ((This)->lpVtbl->GetFieldNames(This, pcNames, rgBstrNames))

#define IRecordInfo_IsMatchingType(This, pRecordInfo) ((This)->lpVtbl->IsMatchingType(This, pRecordInfo))

#define IRecordInfo_RecordCreate(This) ((This)->lpVtbl->RecordCreate(This))

#define IRecordInfo_RecordCreateCopy(This, pvSource, ppvDest) ((This)->lpVtbl->RecordCreateCopy(This, pvSource, ppvDest))

#define IRecordInfo_RecordDestroy(This, pvRecord) ((This)->lpVtbl->RecordDestroy(This, pvRecord))

#endif /* COBJMACROS */

#endif /* C style interface */

#endif /* __IRecordInfo_INTERFACE_DEFINED__ */

#endif //_OAIDL_H_