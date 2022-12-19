#pragma once
#include <interface/SAdapter-i.h>

namespace qjsbind {
	//下面几个adapter指针，强制转换成number，用来作为jsadapter的id
	template<>
	inline Value NewValue(Context& context, ILvAdapter* v)
	{
#ifdef WIN64
		return Value(context.context(), JS_NewBigUint64(context.context(), (uint64_t)v));
#else
		return Value(context.context(), JS_NewUint32(context.context(), (uint32_t)v));
#endif
	}

	template<>
	inline Value NewValue(Context& context, IMcAdapter* v)
	{
#ifdef WIN64
		return Value(context.context(), JS_NewBigUint64(context.context(), (uint64_t)v));
#else
		return Value(context.context(), JS_NewUint32(context.context(), (uint32_t)v));
#endif
	}

	template<>
	inline Value NewValue(Context& context, ITvAdapter* v)
	{
#ifdef WIN64
		return Value(context.context(), JS_NewBigUint64(context.context(), (uint64_t)v));
#else
		return Value(context.context(), JS_NewUint32(context.context(), (uint32_t)v));
#endif
	}

}

void Exp_IAdapter(qjsbind::Module* module)
{
	{
		JsClass<ILvAdapter> jsCls = module->ExportClass<ILvAdapter>("ILvAdapter");
		jsCls.Init(JsClass<IObjRef>::class_id());

		jsCls.AddFunc("registerDataSetObserver", &ILvAdapter::registerDataSetObserver);
		jsCls.AddFunc("unregisterDataSetObserver", &ILvAdapter::unregisterDataSetObserver);
		jsCls.AddFunc("getCount", &ILvAdapter::getCount);
		jsCls.AddFunc("getView", &ILvAdapter::getView);
		jsCls.AddFunc("getItemViewType", &ILvAdapter::getItemViewType);
		jsCls.AddFunc("getViewTypeCount", &ILvAdapter::getViewTypeCount);
		jsCls.AddFunc("getViewDesiredSize", &ILvAdapter::getViewDesiredSize);
		jsCls.AddFunc("isEmpty", &ILvAdapter::isEmpty);
		jsCls.AddFunc("getItemDesc", &ILvAdapter::getItemDesc);
		jsCls.AddFunc("getItemDesc", &ILvAdapter::getItemDesc);
		jsCls.AddFunc("InitByTemplate", &ILvAdapter::InitByTemplate);
		jsCls.AddFunc("QueryInterface", &ILvAdapter::QueryInterface);
	}
	{
		JsClass<IMcAdapter> jsCls = module->ExportClass<IMcAdapter>("IMcAdapter");
		jsCls.Init(JsClass<IObjRef>::class_id());

		jsCls.AddFunc("registerDataSetObserver", &IMcAdapter::registerDataSetObserver);
		jsCls.AddFunc("unregisterDataSetObserver", &IMcAdapter::unregisterDataSetObserver);
		jsCls.AddFunc("getCount", &IMcAdapter::getCount);
		jsCls.AddFunc("getView", &IMcAdapter::getView);
		jsCls.AddFunc("getItemViewType", &IMcAdapter::getItemViewType);
		jsCls.AddFunc("getViewTypeCount", &IMcAdapter::getViewTypeCount);
		jsCls.AddFunc("getViewDesiredSize", &IMcAdapter::getViewDesiredSize);
		jsCls.AddFunc("isEmpty", &IMcAdapter::isEmpty);
		jsCls.AddFunc("getItemDesc", &IMcAdapter::getItemDesc);
		jsCls.AddFunc("getItemDesc", &IMcAdapter::getItemDesc);
		jsCls.AddFunc("InitByTemplate", &IMcAdapter::InitByTemplate);
		jsCls.AddFunc("QueryInterface", &IMcAdapter::QueryInterface);
		jsCls.AddFunc("GetColumnName", &IMcAdapter::GetColumnName);
		jsCls.AddFunc("IsColumnVisible", &IMcAdapter::IsColumnVisible);
		jsCls.AddFunc("OnSort", &IMcAdapter::OnSort);
	}
	{
		JsClass<ITvAdapter> jsCls = module->ExportClass<ITvAdapter>("ITvAdapter");
		jsCls.Init(JsClass<IObjRef>::class_id());
		jsCls.AddFunc("registerDataSetObserver", &ITvAdapter::registerDataSetObserver);
		jsCls.AddFunc("unregisterDataSetObserver", &ITvAdapter::unregisterDataSetObserver);
		jsCls.AddFunc("GetItemDataByIndex", &ITvAdapter::GetItemDataByIndex);
		jsCls.AddFunc("SetItemDataByIndex", &ITvAdapter::SetItemDataByIndex);
		jsCls.AddFunc("GetParentItem", &ITvAdapter::GetParentItem);
		jsCls.AddFunc("GetFirstChildItem", &ITvAdapter::GetFirstChildItem);
		jsCls.AddFunc("GetLastChildItem", &ITvAdapter::GetLastChildItem);
		jsCls.AddFunc("GetPrevSiblingItem", &ITvAdapter::GetPrevSiblingItem);
		jsCls.AddFunc("GetNextSiblingItem", &ITvAdapter::GetNextSiblingItem);
		jsCls.AddFunc("HasChildren", &ITvAdapter::HasChildren);
		jsCls.AddFunc("IsItemVisible", &ITvAdapter::IsItemVisible);
		jsCls.AddFunc("GetFirstVisibleItem", &ITvAdapter::GetFirstVisibleItem);
		jsCls.AddFunc("GetLastVisibleItem", &ITvAdapter::GetLastVisibleItem);
		jsCls.AddFunc("GetPrevVisibleItem", &ITvAdapter::GetPrevVisibleItem);
		jsCls.AddFunc("GetNextVisibleItem", &ITvAdapter::GetNextVisibleItem);
		jsCls.AddFunc("ExpandItem", &ITvAdapter::ExpandItem);
		jsCls.AddFunc("IsItemExpanded", &ITvAdapter::IsItemExpanded);
		jsCls.AddFunc("SetItemExpanded", &ITvAdapter::SetItemExpanded);
		jsCls.AddFunc("getView", &ITvAdapter::getView);
		jsCls.AddFunc("getViewType", &ITvAdapter::getViewType);
		jsCls.AddFunc("getViewTypeCount", &ITvAdapter::getViewTypeCount);
		jsCls.AddFunc("getViewDesiredSize", &ITvAdapter::getViewDesiredSize);
		jsCls.AddFunc("isViewWidthMatchParent", &ITvAdapter::isViewWidthMatchParent);
		jsCls.AddFunc("InitByTemplate", &ITvAdapter::InitByTemplate);
		jsCls.AddFunc("QueryInterface", &ITvAdapter::QueryInterface);
	}
}