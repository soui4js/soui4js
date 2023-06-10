#pragma once
#pragma once
#include <helper/SAdapterBase.h>
#include <qjsbind.h>
using namespace qjsbind;

SNSBEGIN

class SLvAdapter : public SAdapterBase , public JsThisOwner
{
	int tag;
public:
	SLvAdapter():tag(100) {}

	void notifyDataSetChanged()
	{
		SAdapterBase::notifyDataSetChanged();
	}

	void notifyDataSetInvalidated()
	{
		SAdapterBase::notifyDataSetInvalidated();
	}

	void notifyItemDataChanged(int iItem)
	{
		SAdapterBase::notifyItemDataChanged(iItem);
	}

public:
	STDMETHOD_(void, getView)(int position, IWindow* pItem, IXmlNode* xmlTemplate) OVERRIDE {
		if(!m_funGetView.IsFunction())
			return;
		Context* ctx = m_funGetView.context();
		Value args[3];
		args[0] = NewValue(*ctx, position);
		args[1] = NewValue(*ctx, pItem);
		args[2] = NewValue(*ctx, xmlTemplate);
		ctx->Call(GetJsThis(), m_funGetView, 3, args);
	}

	STDMETHOD_(int, getCount)(THIS) OVERRIDE {
		if(!m_funGetCount.IsFunction())
			return 0;
		Context* ctx = m_funGetCount.context();
		Value ret = ctx->Call(GetJsThis(), m_funGetCount, 0, NULL);
		return ret.ToInt32();
	}

	STDMETHOD_(void, InitByTemplate)(IXmlNode* pXmlTemplate) OVERRIDE
	{
		if(!m_funInitByTemplate.IsFunction())
			return;
		Context* ctx = m_funInitByTemplate.context();
		Value args[1];
		args[0] = NewValue(*ctx, pXmlTemplate);
		ctx->Call(GetJsThis(), m_funInitByTemplate, 1, args);
	}

	STDMETHOD_(int, getViewTypeCount)() OVERRIDE
	{
		if(!m_funGetViewTypeCount.IsFunction())
			return 1;
		Context* ctx = m_funGetViewTypeCount.context();
		Value ret = ctx->Call(GetJsThis(), m_funGetViewTypeCount, 0, NULL);
		return ret.ToInt32();
	}

	STDMETHOD_(int, getItemViewType)(int position)
	{
		if(!m_funGetItemViewType.IsFunction())
			return 0;
		Context* ctx = m_funGetItemViewType.context();
		Value args[1];
		args[0] = NewValue(*ctx, position);
		Value ret = ctx->Call(GetJsThis(), m_funGetItemViewType, 1, args);
		return ret.ToInt32();
	}

	static void Mark(SLvAdapter* pThis, JS_MarkFunc* mark_fun) {
		pThis->m_cbHandler.Mark(mark_fun);
		pThis->m_funGetView.Mark(mark_fun);
		pThis->m_funGetItemViewType.Mark(mark_fun);
		pThis->m_funGetViewTypeCount.Mark(mark_fun);
		pThis->m_funGetCount.Mark(mark_fun);
		pThis->m_funInitByTemplate.Mark(mark_fun);
	}
public:
	virtual const WeakValue& GetJsThis() const override {
		if (m_cbHandler.IsObject())
			return m_cbHandler;
		else
			return JsThisOwner::GetJsThis();
	}
	Value m_cbHandler;
	Value m_funGetView;
	Value m_funGetItemViewType;
	Value m_funGetViewTypeCount;
	Value m_funGetCount;
	Value m_funInitByTemplate;
};

class SMcLvAdapter : public SMcAdapterBase, public JsThisOwner
{
public:
	SMcLvAdapter() {}
	void notifyDataSetChanged()
	{
		SMcAdapterBase::notifyDataSetChanged();
	}

	void notifyDataSetInvalidated()
	{
		SMcAdapterBase::notifyDataSetInvalidated();
	}

	void notifyItemDataChanged(int iItem)
	{
		SMcAdapterBase::notifyItemDataChanged(iItem);
	}

public:
	STDMETHOD_(void, getView)(int position, IWindow* pItem, IXmlNode* xmlTemplate) OVERRIDE {
		if(!m_funGetView.IsFunction())
			return;
		Context* ctx = m_funGetView.context();
		Value args[3];
		args[0] = NewValue(*ctx, position);
		args[1] = NewValue(*ctx, pItem);
		args[2] = NewValue(*ctx, xmlTemplate);
		ctx->Call(GetJsThis(), m_funGetView, 3, args);
	}

	STDMETHOD_(int, getCount)(THIS) OVERRIDE {
		if(!m_funGetCount.IsFunction())
			return 0;
		Context* ctx = m_funGetCount.context();
		Value ret =ctx->Call(GetJsThis(), m_funGetCount, 0, NULL);
		return ret.ToInt32();
	}

	STDMETHOD_(void, InitByTemplate)(IXmlNode* pXmlTemplate) OVERRIDE
	{
		if(!m_funInitByTemplate.IsFunction())
			return;
		Context* ctx = m_funInitByTemplate.context();
		Value args[1];
		args[0] = NewValue(*ctx, pXmlTemplate);
		ctx->Call(GetJsThis(), m_funInitByTemplate, 1, args);
	}

	STDMETHOD_(int, getViewTypeCount)() OVERRIDE
	{
		if(!m_funGetViewTypeCount.IsFunction())
			return 1;
		Context* ctx = m_funGetViewTypeCount.context();
		Value ret = ctx->Call(GetJsThis(), m_funGetViewTypeCount, 0, NULL);
		return ret.ToInt32();
	}

	STDMETHOD_(int, getItemViewType)(int position)
	{
		if(!m_funGetItemViewType.IsFunction())
			return 0;
		Context* ctx = m_funGetItemViewType.context();
		Value args[1];
		args[0] = NewValue(*ctx, position);
		Value ret =ctx->Call(GetJsThis(), m_funGetItemViewType, 1, args);
		return ret.ToInt32();
	}

	STDMETHOD_(BOOL, OnSort)(int iCol, UINT* pFmts, int nCols) OVERRIDE
	{
		if(!m_funOnSort.IsFunction())
			return FALSE;
		Context* ctx = m_funOnSort.context();
		Value args[2];
		args[0] = NewValue(*ctx, iCol);
		args[1] = ctx->NewArrayBuffer((const uint8_t*)pFmts,nCols*sizeof(UINT));
		Value ret = ctx->Call(GetJsThis(), m_funOnSort, 2, args);
		return ret.ToBool();
	}

	STDMETHOD_(SStringW, GetColumnName)(int iCol) SCONST
	{
		if(!m_funGetColumnName.IsFunction())
			return L"";
		Context* ctx = m_funGetColumnName.context();
		Value args[1];
		args[0] = NewValue(*ctx, iCol);
		Value ret = ctx->Call(GetJsThis(), m_funGetColumnName, 1, args);
		if (ret.IsString()) {
			return S_CA2W(ret.ToStdString().c_str(),CP_UTF8);
		}
		else {
			if (ret.IsException())
				ctx->DumpError();
			else
				SLOGI2("") << "invalid ret";
			return L"";
		}
	}

	STDMETHOD_(BOOL, IsColumnVisible)(THIS_ int iCol) SCONST OVERRIDE
	{
		if(!m_funIsColumnVisible.IsFunction())
			return TRUE;
		Context* ctx = m_funIsColumnVisible.context();
		Value args[1];
		args[0] = NewValue(*ctx, iCol);
		Value ret =ctx->Call(GetJsThis(), m_funIsColumnVisible, 1, args);
		if (ret.IsBool())
			return ret.ToBool();
		else
			return TRUE;
	}

	virtual const WeakValue& GetJsThis() const override {
		if (m_cbHandler.IsObject())
			return m_cbHandler;
		else
			return JsThisOwner::GetJsThis();
	}
public:
	static void Mark(SMcLvAdapter* pThis, JS_MarkFunc* mark_fun) {
		pThis->m_cbHandler.Mark(mark_fun);
		pThis->m_funGetView.Mark(mark_fun);
		pThis->m_funGetItemViewType.Mark(mark_fun);
		pThis->m_funGetViewTypeCount.Mark(mark_fun);
		pThis->m_funGetCount.Mark(mark_fun);
		pThis->m_funInitByTemplate.Mark(mark_fun);
		pThis->m_funOnSort.Mark(mark_fun);
		pThis->m_funGetColumnName.Mark(mark_fun);
		pThis->m_funIsColumnVisible.Mark(mark_fun);
	}

	Value m_cbHandler;
	Value m_funGetView;
	Value m_funGetItemViewType;
	Value m_funGetViewTypeCount;
	Value m_funGetCount;
	Value m_funInitByTemplate;
	Value m_funOnSort;
	Value m_funGetColumnName;
	Value m_funIsColumnVisible;
};

typedef int TvKey;
class STvAdapter : public STreeAdapterBase<TvKey>, public JsThisOwner
{
public:
	typedef STreeAdapterBase<TvKey> _baseCls;
public:
	STvAdapter()  {}

	void notifyBranchChanged(HSTREEITEM hBranch)
	{
		_baseCls::notifyBranchChanged(hBranch);
	}
	void notifyBranchInvalidated(HSTREEITEM hBranch, bool bInvalidParents = true, bool bInvalidChildren = true)
	{
		_baseCls::notifyBranchInvalidated(hBranch, bInvalidParents, bInvalidChildren);
	}

	void notifyBranchExpandChanged(HSTREEITEM hBranch, BOOL bExpandedOld, BOOL bExpandedNew)
	{
		_baseCls::notifyBranchExpandChanged(hBranch, bExpandedOld, bExpandedNew);
	}

	HSTREEITEM InsertItem(TvKey key, HSTREEITEM hParent, HSTREEITEM hInsertAfter) {
		return _baseCls::InsertItem(key, hParent, hInsertAfter);
	}

	HSTREEITEM GetChildItem(HSTREEITEM hParent,BOOL bFirst) const{
		return bFirst?_baseCls::GetFirstChildItem(hParent): _baseCls::GetLastChildItem(hParent);
	}

	HSTREEITEM WINAPI GetParentItem(HSTREEITEM hItem) const{
		return _baseCls::GetParentItem(hItem);
	}

	HSTREEITEM GetNextSibling(HSTREEITEM hItem) const {
		return _baseCls::GetNextSiblingItem(hItem);
	}

	HSTREEITEM GetPrevSibling(HSTREEITEM hItem) const {
		return _baseCls::GetPrevSiblingItem(hItem);
	}

	TvKey GetItemData(HSTREEITEM hItem) {
		return _baseCls::GetItemData(hItem);
	}

	void SetItemData(HSTREEITEM hItem, TvKey key) {
		_baseCls::SetItemData(hItem, key);
	}

	void DeleteItem(HSTREEITEM hItem,BOOL bNotifyChange) {
		_baseCls::DeleteItem(hItem, bNotifyChange);
	}

	void DeleteAllItems() {
		DeleteItem(STVI_ROOT,true);
	}

	void SetItemExpended(HSTREEITEM hItem, bool expended) {
		_baseCls::SetItemExpanded(hItem, expended);
	}

	bool IsItemExpended(HSTREEITEM hItem) {
		return _baseCls::IsItemExpanded(hItem)==TRUE;
	}

	void WINAPI ExpandItem(HSTREEITEM hItem, uint32_t mode) {
		_baseCls::ExpandItem(hItem, mode);
	}

public:
	STDMETHOD_(void, getView)(THIS_ HSTREEITEM hItem, IWindow* pItem, IXmlNode* pXmlTemplate) OVERRIDE
	{
		if(!m_funGetView.IsFunction())
			return;
		Context* ctx = m_funGetView.context();
		Value args[3];
		args[0] = NewValue(*ctx, hItem);
		args[1] = NewValue(*ctx, pItem);
		args[2] = NewValue(*ctx, pXmlTemplate);
		ctx->Call(GetJsThis(), m_funGetView, 3, args);
	}

	STDMETHOD_(int, getViewType)(HSTREEITEM hItem) const OVERRIDE
	{
		if(!m_funGetViewType.IsFunction())
			return 0;
		Context* ctx = m_funGetViewType.context();
		Value args[1];
		args[0] = NewValue(*ctx, hItem);
		Value ret = ctx->Call(GetJsThis(), m_funGetViewType, 1, args);
		if (ret.IsNumber()) {
			return ret.ToInt32();
		}
		else
		{
			return 0;
		}
	}

	STDMETHOD_(int, getViewTypeCount)() const OVERRIDE
	{
		if(!m_funGetViewTypeCount.IsFunction())
			return 1;
		Context* ctx = m_funGetViewTypeCount.context();
		Value ret = ctx->Call(GetJsThis(), m_funGetViewTypeCount, 0, NULL);
		return ret.ToInt32();
	}

	STDMETHOD_(void, InitByTemplate)(IXmlNode* pXmlTemplate) OVERRIDE
	{
		if(!m_funInitByTemplate.IsFunction())
			return;
		Context* ctx = m_funInitByTemplate.context();
		Value args[1];
		args[0] = NewValue(*ctx, pXmlTemplate);
		ctx->Call(GetJsThis(), m_funInitByTemplate, 1, args);
	}

	STDMETHOD_(BOOL, isViewWidthMatchParent)() const OVERRIDE
	{
		if(!m_funIsViewWidthMatchParent.IsFunction())
			return FALSE;
		Context* ctx = m_funIsViewWidthMatchParent.context();
		Value ret = ctx->Call(GetJsThis(), m_funIsViewWidthMatchParent, 0, NULL);
		return ret.ToBool();
	}

	virtual const WeakValue& GetJsThis() const override {
		if (m_cbHandler.IsObject())
			return m_cbHandler;
		else
			return JsThisOwner::GetJsThis();
	}
public:
	static void Mark(STvAdapter* pThis, JS_MarkFunc* mark_fun) {
		pThis->m_cbHandler.Mark(mark_fun);
		pThis->m_funGetView.Mark(mark_fun);
		pThis->m_funGetViewType.Mark(mark_fun);
		pThis->m_funGetViewTypeCount.Mark(mark_fun);
		pThis->m_funIsViewWidthMatchParent.Mark(mark_fun);
		pThis->m_funInitByTemplate.Mark(mark_fun);
	}

	Value m_cbHandler;
	Value m_funGetView,
		m_funInitByTemplate,
		m_funGetViewTypeCount,
		m_funGetViewType,
		m_funIsViewWidthMatchParent;
};

SNSEND

using namespace SOUI;

void Exp_SAdapter(qjsbind::Module* module) {
	{
		JsClass<SLvAdapter> jsCls = module->ExportClass<SLvAdapter>("SLvAdapter");
		jsCls.Init<SLvAdapter::Mark>();
		jsCls.AddCtor<constructor<SLvAdapter>>(TRUE);
		jsCls.AddFunc( "notifyDataSetChanged", &SLvAdapter::notifyDataSetChanged);
		jsCls.AddFunc("notifyItemDataChanged", &SLvAdapter::notifyItemDataChanged);
		jsCls.AddFunc( "notifyDataSetInvalidated", &SLvAdapter::notifyDataSetInvalidated);
		jsCls.AddGetSet("cbHandler", &SLvAdapter::m_cbHandler);
		jsCls.AddGetSet("onGetView", &SLvAdapter::m_funGetView);
		jsCls.AddGetSet("onGetItemViewType", &SLvAdapter::m_funGetItemViewType);
		jsCls.AddGetSet("onGetViewTypeCount", &SLvAdapter::m_funGetViewTypeCount);
		jsCls.AddGetSet("onGetCount", &SLvAdapter::m_funGetCount);
		jsCls.AddGetSet("onInitByTemplate", &SLvAdapter::m_funInitByTemplate);
	}
	{
		JsClass<SMcLvAdapter> jsCls = module->ExportClass<SMcLvAdapter>("SMcLvAdapter");
		jsCls.Init<SMcLvAdapter::Mark>();
		jsCls.AddCtor<constructor<SMcLvAdapter>>(TRUE);
		jsCls.AddFunc( "notifyDataSetChanged", &SMcLvAdapter::notifyDataSetChanged);
		jsCls.AddFunc( "notifyDataSetInvalidated", &SMcLvAdapter::notifyDataSetInvalidated);
		jsCls.AddFunc( "notifyItemDataChanged", &SMcLvAdapter::notifyItemDataChanged);
		jsCls.AddGetSet("cbHandler", &SMcLvAdapter::m_cbHandler);
		jsCls.AddGetSet("onGetView", &SMcLvAdapter::m_funGetView);
		jsCls.AddGetSet("onGetItemViewType", &SMcLvAdapter::m_funGetItemViewType);
		jsCls.AddGetSet("onGetViewTypeCount", &SMcLvAdapter::m_funGetViewTypeCount);
		jsCls.AddGetSet("onGetCount", &SMcLvAdapter::m_funGetCount);
		jsCls.AddGetSet("onInitByTemplate", &SMcLvAdapter::m_funInitByTemplate);	
		jsCls.AddGetSet("OnSort", &SMcLvAdapter::m_funOnSort);
		jsCls.AddGetSet("onGetColumnName", &SMcLvAdapter::m_funGetColumnName);
		jsCls.AddGetSet("onIsColumnVisible", &SMcLvAdapter::m_funIsColumnVisible);
	}
	{
		JsClass<STvAdapter> jsCls = module->ExportClass<STvAdapter>("STvAdapter");
		jsCls.Init<STvAdapter::Mark>();
		jsCls.AddCtor<constructor<STvAdapter>>(TRUE);
		jsCls.AddFunc( "notifyBranchChanged", &STvAdapter::notifyBranchChanged);
		jsCls.AddFunc( "notifyBranchInvalidated", &STvAdapter::notifyBranchInvalidated);
		jsCls.AddFunc( "notifyBranchExpandChanged", &STvAdapter::notifyBranchExpandChanged);
		jsCls.AddFunc("InsertItem", &STvAdapter::InsertItem);
		jsCls.AddFunc("GetItemData", &STvAdapter::GetItemData);
		jsCls.AddFunc("SetItemData", &STvAdapter::SetItemData);
		jsCls.AddFunc("DeleteItem", &STvAdapter::DeleteItem);
		jsCls.AddFunc("DeleteAllItems", &STvAdapter::DeleteAllItems);
		jsCls.AddFunc("SetItemExpended", &STvAdapter::SetItemExpended);
		jsCls.AddFunc("IsItemExpended", &STvAdapter::IsItemExpended);
		jsCls.AddFunc("ExpandItem", &STvAdapter::ExpandItem);
		jsCls.AddFunc("GetChildItem", &STvAdapter::GetChildItem);
		jsCls.AddFunc("GetParentItem", &STvAdapter::GetParentItem);
		jsCls.AddFunc("GetNextSibling", &STvAdapter::GetNextSibling);
		jsCls.AddFunc("GetPrevSibling", &STvAdapter::GetPrevSibling);


		jsCls.AddGetSet("cbHandler", &STvAdapter::m_cbHandler);
		jsCls.AddGetSet("onGetView", &STvAdapter::m_funGetView);
		jsCls.AddGetSet("onInitByTemplate", &STvAdapter::m_funInitByTemplate);
		jsCls.AddGetSet("onGetItemViewType", &STvAdapter::m_funGetViewType);
		jsCls.AddGetSet("onGetViewTypeCount", &STvAdapter::m_funGetViewTypeCount);
		jsCls.AddGetSet("onIsViewWidthMatchParent", &STvAdapter::m_funIsViewWidthMatchParent);
	}
}