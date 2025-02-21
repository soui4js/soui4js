#ifndef __SGUID_H_
#define __SGUID_H_

#include <memory.h>
#include <stdint.h>
typedef struct _GUID
{
    uint32_t Data1;
    uint16_t Data2;
    uint16_t Data3;
    uint8_t Data4[8];
} GUID;

typedef GUID IID;
typedef IID *LPIID;
typedef GUID CLSID;
typedef CLSID *LPCLSID;
typedef GUID FMTID;
typedef FMTID *LPFMTID;

#define IsEqualGUID(id1, id2)          (memcmp(&id1, &id2, sizeof(GUID)) == 0)
#define IsEqualIID(riid1, riid2)       IsEqualGUID(riid1, riid2)
#define IsEqualCLSID(rclsid1, rclsid2) IsEqualGUID(rclsid1, rclsid2)
#define IsEqualFMTID(rfmtid1, rfmtid2) IsEqualGUID(rfmtid1, rfmtid2)

#ifdef __cplusplus

inline bool operator==(const GUID &id1, const GUID &id2)
{
    return IsEqualGUID(id1, id2);
}

#ifdef __cplusplus
#define DECLARE_CLASS_SIID(cls_id) \
    static const GUID &GetIID()    \
    {                              \
        return cls_id;             \
    }
#else
#define DECLARE_CLASS_SIID(cls_id)
#endif //__cplusplus

#define __suidof(ClassName) ClassName::GetIID()
#define __uuidof(ClassName) ClassName::GetIID()

#else

#define DECLARE_CLASS_SIID(cls_id)

#endif

#ifdef __cplusplus
#define REFGUID const GUID &
#else
#define REFGUID const GUID *
#endif

#define REFIID   REFGUID
#define REFCLSID REFGUID

#endif //__SGUID_H_

#ifdef DEFINE_GUID
#undef DEFINE_GUID
#endif

//#define SELECT_ANY __attribute__((select_any))
#define SELECT_ANY

#ifdef INITGUID
#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) EXTERN_C const GUID SELECT_ANY name = { l, w1, w2, { b1, b2, b3, b4, b5, b6, b7, b8 } }
#else
#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) EXTERN_C const GUID name
#endif // INITGUID

#ifndef DEFINE_OLEGUID
#define DEFINE_OLEGUID(name, l, w1, w2) DEFINE_GUID(name, l, w1, w2, 0xC0, 0, 0, 0, 0, 0, 0, 0x46)
#endif // DEFINE_OLEGUID