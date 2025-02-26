#ifndef __SATTRSTORAGE__H__
#define __SATTRSTORAGE__H__
#include <helper/obj-ref-impl.hpp>
#include <interface/SAttrStorage-i.h>
#include <souicoll.h>
#include <string/sstringw.h>

using namespace SOUI;

class JsAttrStorage : public TObjRefImpl<IAttrStorage> {
public:

    STDMETHOD_(void, OnSetAttribute)(THIS_ const IStringW* strName, const IStringW* strValue, BOOL bHandled) override {
        SStringW attrName(strName);
        SStringW attrValue(strValue);
        m_attrMap[attrName] = attrValue;
    }

    STDMETHOD_(BOOL, OnGetAttribute)(CTHIS_ const IStringW* strName, IStringW* strValue) SCONST override {
        SStringW attrName(strName);
        auto it = m_attrMap.Lookup(attrName);
        if(!it)
            return FALSE;
        else {
            strValue->Copy(&it->m_value);
            return TRUE;
        }
    }

protected:
    SMap<SStringW, SStringW> m_attrMap;
};

class JsAttrStorageFactory : public TObjRefImpl<IAttrStorageFactory> , public JsThisOwner {
public:
    JsAttrStorageFactory() {

    }

    STDMETHOD_(HRESULT, CreateAttrStorage)
        (CTHIS_ IWindow* owner, IAttrStorage** ppAttrStorage) SCONST override {
        if (!m_onNeedStorage.IsFunction())
            return E_FAIL;
        Context* ctx = m_onNeedStorage.context();
        Value args[] = {
            NewValue(*ctx,owner)
        };
        Value ret = ctx->Call(GetJsThis(), m_onNeedStorage, 1, args);
        bool test = ret.ToBool();
        if (!test)
            return S_FALSE;
        *ppAttrStorage = new JsAttrStorage();
        return S_OK;
    }

protected:
    virtual const WeakValue& GetJsThis() const {
        if (m_cbHandler.IsObject())
            return m_cbHandler;
        else
            return JsThisOwner::GetJsThis();
    }

public:
    static void Mark(JsAttrStorageFactory* pThis, JS_MarkFunc* mark_fun) {
        pThis->m_cbHandler.Mark(mark_fun);
        pThis->m_onNeedStorage.Mark(mark_fun);
    }

    Value m_cbHandler;
    Value m_onNeedStorage;
};
#endif // __SATTRSTORAGE__H__