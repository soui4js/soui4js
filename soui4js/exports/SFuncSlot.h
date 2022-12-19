#pragma once
#include <qjsbind.h>
using namespace qjsbind;
SNSBEGIN

class SFuncSlot : public TObjRefImpl<IEvtSlot>
{
public:
	//! Slot function type.
	SFuncSlot(const Value &jsThis,const Value & jsFun) 
		: m_jsThis(jsThis)
		, m_jsFun(jsFun)
	{}

	~SFuncSlot() {

	}

	STDMETHOD_(BOOL,Run)(THIS_ IEvtArgs *pArg) OVERRIDE
	{
		Context* pCtx = m_jsThis.context();
		Value arg = NewValue(*pCtx, pArg);
		Value ret = pCtx->Call(m_jsThis, m_jsFun, 1, &arg);
		return ret.ToBool();
	}
	STDMETHOD_(IEvtSlot*, Clone)(THIS) SCONST OVERRIDE
	{
		return new SFuncSlot(m_jsThis,m_jsFun);
	}
	STDMETHOD_(BOOL,Equal)(THIS_ const IEvtSlot * sour) SCONST OVERRIDE
	{
		if(sour->GetSlotType()!=GetSlotType()) return FALSE;
		const SFuncSlot *psour=static_cast<const SFuncSlot*>(sour);
		SASSERT(psour);
		return psour->m_jsFun==m_jsFun && psour->m_jsThis==m_jsThis;
	}

	STDMETHOD_(UINT,GetSlotType)(THIS) SCONST OVERRIDE
	{
		return SLOT_USER+2;
	}

	static void Mark(SFuncSlot* pThis, JS_MarkFunc* mark_fun) {
		pThis->m_jsFun.Mark(mark_fun);
		pThis->m_jsThis.Mark(mark_fun);
	}
private:
	Value m_jsFun;
	Value m_jsThis;
};

SNSEND