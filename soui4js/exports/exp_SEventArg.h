#pragma once
#include <event/SEvents.h>
#include "toobj.h"

void Exp_SEventArg(qjsbind::Module* module) {
	{
		JsClass<EventMenuCmd> jsCls = module->ExportClass<EventMenuCmd>("EventMenuCmd");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>(&"menuId"[0], &EventMenuCmd::menuId);
		DEF_CAST_IOBJ(module, EventMenuCmd);
	}
	{
		JsClass<EventTimer> jsCls = module->ExportClass<EventTimer>("EventTimer");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<unsigned int>("uID", &EventTimer::uID);
		DEF_CAST_IOBJ(module, EventTimer);
	}

	{
		JsClass<EventSwndSize> jsCls = module->ExportClass<EventSwndSize>("EventSwndSize");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<SIZE>("szWnd", &EventSwndSize::szWnd);
		DEF_CAST_IOBJ(module, EventSwndSize);
	}

	{
		JsClass<EventScroll> jsCls = module->ExportClass<EventScroll>("EventScroll");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("nSbCode", &EventScroll::nSbCode);
		jsCls.AddGetSet<int>("nPos", &EventScroll::nPos);
		jsCls.AddGetSet<BOOL>("bVertical", &EventScroll::bVertical);
		DEF_CAST_IOBJ(module, EventScroll);
	}


	{
		JsClass<EventSpinValue2String> jsCls = module->ExportClass<EventSpinValue2String>("EventSpinValue2String");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<BOOL>("bInit", &EventSpinValue2String::bInit);
		jsCls.AddGetSet<int>("nValue", &EventSpinValue2String::nValue);
		jsCls.AddGetSet<IStringT*>("strValue", &EventSpinValue2String::strValue);
		DEF_CAST_IOBJ(module, EventSpinValue2String);
	}

	{
		JsClass<EventSwndStateChanged> jsCls = module->ExportClass<EventSwndStateChanged>("EventSwndStateChanged");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<DWORD>("dwOldState", &EventSwndStateChanged::dwOldState);
		jsCls.AddGetSet<DWORD>("dwNewState", &EventSwndStateChanged::dwNewState);
		DEF_CAST_IOBJ(module, EventSwndStateChanged);
	}

	{
		JsClass<EventSwndCaptureChanged> jsCls = module->ExportClass<EventSwndCaptureChanged>("EventSwndCaptureChanged");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<BOOL>("bCaptured", &EventSwndCaptureChanged::bCaptured);
		DEF_CAST_IOBJ(module, EventSwndCaptureChanged);
	}

	{
		JsClass<EventSwndVisibleChanged> jsCls = module->ExportClass<EventSwndVisibleChanged>("EventSwndVisibleChanged");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<BOOL>("bVisible", &EventSwndVisibleChanged::bVisible);
		DEF_CAST_IOBJ(module, EventSwndVisibleChanged);
	}

	{
		JsClass<EventSwndAnimationStart> jsCls = module->ExportClass<EventSwndAnimationStart>("EventSwndAnimationStart");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<IAnimation*>("pAni", &EventSwndAnimationStart::pAni);
		DEF_CAST_IOBJ(module, EventSwndAnimationStart);
	}

	{
		JsClass<EventSwndAnimationStop> jsCls = module->ExportClass<EventSwndAnimationStop>("EventSwndAnimationStop");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<IAnimation*>("pAni", &EventSwndAnimationStop::pAni);
		DEF_CAST_IOBJ(module, EventSwndAnimationStop);
	}

	{
		JsClass<EventSwndAnimationRepeat> jsCls = module->ExportClass<EventSwndAnimationRepeat>("EventSwndAnimationRepeat");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<IAnimation*>("pAni", &EventSwndAnimationRepeat::pAni);
		DEF_CAST_IOBJ(module, EventSwndAnimationRepeat);
	}

	{
		JsClass<EventKeyDown> jsCls = module->ExportClass<EventKeyDown>("EventKeyDown");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<UINT>("nChar", &EventKeyDown::nChar);
		jsCls.AddGetSet<UINT>("nFlags", &EventKeyDown::nFlags);
		jsCls.AddGetSet<BOOL>("bCancel", &EventKeyDown::bCancel);
		DEF_CAST_IOBJ(module, EventKeyDown);
	}

	{
		JsClass<EventSwndUpdateTooltip> jsCls = module->ExportClass<EventSwndUpdateTooltip>("EventSwndUpdateTooltip");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<IStringT*>("strToolTip", &EventSwndUpdateTooltip::strToolTip);
		jsCls.AddGetSet<BOOL>("bUpdated", &EventSwndUpdateTooltip::bUpdated);
		DEF_CAST_IOBJ(module, EventSwndUpdateTooltip);
	}


	{
		JsClass<EventRadioGroupCheckChanged> jsCls = module->ExportClass<EventRadioGroupCheckChanged>("EventRadioGroupCheckChanged");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<IWindow*>("pChecked", &EventRadioGroupCheckChanged::pChecked);
		DEF_CAST_IOBJ(module, EventRadioGroupCheckChanged);
	}

	{
		JsClass<EventItemPanelRclick> jsCls = module->ExportClass<EventItemPanelRclick>("EventItemPanelRclick");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<WPARAM>("wParam", &EventItemPanelRclick::wParam);
		jsCls.AddGetSet<LPARAM>("lParam", &EventItemPanelRclick::lParam);
		DEF_CAST_IOBJ(module, EventItemPanelRclick);
	}

	{
		JsClass<EventItemPanelDbclick> jsCls = module->ExportClass<EventItemPanelDbclick>("EventItemPanelDbclick");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<WPARAM>("wParam", &EventItemPanelDbclick::wParam);
		jsCls.AddGetSet<LPARAM>("lParam", &EventItemPanelDbclick::lParam);
		DEF_CAST_IOBJ(module, EventItemPanelDbclick);
	}


	{
		JsClass<EventItemPanelClick> jsCls = module->ExportClass<EventItemPanelClick>("EventItemPanelClick");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<WPARAM>("wParam", &EventItemPanelClick::wParam);
		jsCls.AddGetSet<LPARAM>("lParam", &EventItemPanelClick::lParam);
		DEF_CAST_IOBJ(module, EventItemPanelClick);
	}

	{
		JsClass<EventItemPanelRclickUp> jsCls = module->ExportClass<EventItemPanelRclickUp>("EventItemPanelRclickUp");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<WPARAM>("wParam", &EventItemPanelRclickUp::wParam);
		jsCls.AddGetSet<LPARAM>("lParam", &EventItemPanelRclickUp::lParam);
		DEF_CAST_IOBJ(module, EventItemPanelRclickUp);
	}


	{
		JsClass<EventItemPanelClickUp> jsCls = module->ExportClass<EventItemPanelClickUp>("EventItemPanelClickUp");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<WPARAM>("wParam", &EventItemPanelClickUp::wParam);
		jsCls.AddGetSet<LPARAM>("lParam", &EventItemPanelClickUp::lParam);
		DEF_CAST_IOBJ(module, EventItemPanelClickUp);
	}

	{
		JsClass<EventItemPanelHover> jsCls = module->ExportClass<EventItemPanelHover>("EventItemPanelHover");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<WPARAM>("wParam", &EventItemPanelHover::wParam);
		jsCls.AddGetSet<LPARAM>("lParam", &EventItemPanelHover::lParam);
		DEF_CAST_IOBJ(module, EventItemPanelHover);
	}


	{
		JsClass<EventMouseClick> jsCls = module->ExportClass<EventMouseClick>("EventMouseClick");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGet<POINT>("pt", &EventMouseClick::pt);
		jsCls.AddGet<unsigned int>("uFlags", &EventMouseClick::uFlags);
		jsCls.AddGet<MouseClickId>("clickId", &EventMouseClick::clickId);
		jsCls.AddGet<BOOL>("bHover", &EventMouseClick::bHover);
		DEF_CAST_IOBJ(module, EventMouseClick);
	}

	{
		JsClass<EventCtxMenu> jsCls = module->ExportClass<EventCtxMenu>("EventCtxMenu");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<POINT>("pt", &EventCtxMenu::pt);
		jsCls.AddGetSet<BOOL>("bCancel", &EventCtxMenu::bCancel);
		DEF_CAST_IOBJ(module, EventCtxMenu);
	}

	{
		JsClass<EventSetFocus> jsCls = module->ExportClass<EventSetFocus>("EventSetFocus");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<SWND>("wndOld", &EventSetFocus::wndOld);
		DEF_CAST_IOBJ(module, EventSetFocus);
	}

	{
		JsClass<EventKillFocus> jsCls = module->ExportClass<EventKillFocus>("EventKillFocus");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<SWND>("wndFocus", &EventKillFocus::wndFocus);
		DEF_CAST_IOBJ(module, EventKillFocus);
	}


	{
		JsClass<EventScrollViewOriginChanged> jsCls = module->ExportClass<EventScrollViewOriginChanged>("EventScrollViewOriginChanged");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<POINT>("ptOldOrigin", &EventScrollViewOriginChanged::ptOldOrigin);
		jsCls.AddGetSet<POINT>("ptNewOrigin", &EventScrollViewOriginChanged::ptNewOrigin);
		DEF_CAST_IOBJ(module, EventScrollViewOriginChanged);
	}


	{
		JsClass<EventScrollViewSizeChanged> jsCls = module->ExportClass<EventScrollViewSizeChanged>("EventScrollViewSizeChanged");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<SIZE>("szOldViewSize", &EventScrollViewSizeChanged::szOldViewSize);
		jsCls.AddGetSet<SIZE>("szNewViewSize", &EventScrollViewSizeChanged::szNewViewSize);
		DEF_CAST_IOBJ(module, EventScrollViewSizeChanged);
	}

	{
		JsClass<EventOfEvent> jsCls = module->ExportClass<EventOfEvent>("EventOfEvent");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<IEvtArgs*>("pOrgEvt", &EventOfEvent::pOrgEvt);
		DEF_CAST_IOBJ(module, EventOfEvent);
	}

	{
		JsClass<EventOfPanel> jsCls = module->ExportClass<EventOfPanel>("EventOfPanel");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<IWindow*>("pPanel", &EventOfPanel::pPanel);
		jsCls.AddGetSet<IEvtArgs*>("pOrgEvt", &EventOfPanel::pOrgEvt);
		DEF_CAST_IOBJ(module, EventOfPanel);
	}

	{
		JsClass<EventTabSelChanging> jsCls = module->ExportClass<EventTabSelChanging>("EventTabSelChanging");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<unsigned int>("uOldSel", &EventTabSelChanging::uOldSel);
		jsCls.AddGetSet<unsigned int>("uNewSel", &EventTabSelChanging::uNewSel);
		jsCls.AddGetSet<BOOL>("bCancel", &EventTabSelChanging::bCancel);
		DEF_CAST_IOBJ(module, EventTabSelChanging);
	}

	{
		JsClass<EventTabSelChanged> jsCls = module->ExportClass<EventTabSelChanged>("EventTabSelChanged");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<unsigned int>("uOldSel", &EventTabSelChanged::uOldSel);
		jsCls.AddGetSet<unsigned int>("uNewSel", &EventTabSelChanged::uNewSel);
		DEF_CAST_IOBJ(module, EventTabSelChanged);
	}

	{
		JsClass<EventTabItemHover> jsCls = module->ExportClass<EventTabItemHover>("EventTabItemHover");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("iHover", &EventTabItemHover::iHover);
		DEF_CAST_IOBJ(module, EventTabItemHover);
	}

	{
		JsClass<EventTabItemLeave> jsCls = module->ExportClass<EventTabItemLeave>("EventTabItemLeave");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("iLeave", &EventTabItemLeave::iLeave);
		DEF_CAST_IOBJ(module, EventTabItemLeave);
	}

	{
		JsClass<EventLBSelChanging> jsCls = module->ExportClass<EventLBSelChanging>("EventLBSelChanging");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("nNewSel", &EventLBSelChanging::nNewSel);
		jsCls.AddGetSet<int>("nOldSel", &EventLBSelChanging::nOldSel);
		jsCls.AddGetSet<BOOL>("bCancel", &EventLBSelChanging::bCancel);
		DEF_CAST_IOBJ(module, EventLBSelChanging);
	}

	{
		JsClass<EventLBSelChanged> jsCls = module->ExportClass<EventLBSelChanged>("EventLBSelChanged");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("nNewSel", &EventLBSelChanged::nNewSel);
		jsCls.AddGetSet<int>("nOldSel", &EventLBSelChanged::nOldSel);
		DEF_CAST_IOBJ(module, EventLBSelChanged);
	}

	{
		JsClass<EventLBDbClick> jsCls = module->ExportClass<EventLBDbClick>("EventLBDbClick");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("nCurSel", &EventLBDbClick::nCurSel);
		DEF_CAST_IOBJ(module, EventLBDbClick);
	}

	{
		JsClass<EventLVSelChanged> jsCls = module->ExportClass<EventLVSelChanged>("EventLVSelChanged");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("iOldSel", &EventLVSelChanged::iOldSel);
		jsCls.AddGetSet<int>("iNewSel", &EventLVSelChanged::iNewSel);
		DEF_CAST_IOBJ(module, EventLVSelChanged);
	}

	{
		JsClass<EventLVSelChanging> jsCls = module->ExportClass<EventLVSelChanging>("EventLVSelChanging");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("iOldSel", &EventLVSelChanging::iOldSel);
		jsCls.AddGetSet<int>("iNewSel", &EventLVSelChanging::iNewSel);
		jsCls.AddGetSet<BOOL>("bCancel", &EventLVSelChanging::bCancel);
		DEF_CAST_IOBJ(module, EventLVSelChanging);
	}

	{
		JsClass<EventTVSelChanged> jsCls = module->ExportClass<EventTVSelChanged>("EventTVSelChanged");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<ULONG_PTR>("hOldSel", &EventTVSelChanged::hOldSel);
		jsCls.AddGetSet<ULONG_PTR>("hNewSel", &EventTVSelChanged::hNewSel);
		DEF_CAST_IOBJ(module, EventTVSelChanged);
	}

	{
		JsClass<EventTVSelChanging> jsCls = module->ExportClass<EventTVSelChanging>("EventTVSelChanging");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<ULONG_PTR>("hOldSel", &EventTVSelChanging::hOldSel);
		jsCls.AddGetSet<ULONG_PTR>("hNewSel", &EventTVSelChanging::hNewSel);
		jsCls.AddGetSet<BOOL>("bCancel", &EventTVSelChanging::bCancel);
		DEF_CAST_IOBJ(module, EventTVSelChanging);
	}

	{
		JsClass<EventRENotify> jsCls = module->ExportClass<EventRENotify>("EventRENotify");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<DWORD>("iNotify", &EventRENotify::iNotify);
		jsCls.AddGetSet<void*>("pv", &EventRENotify::pv);
		jsCls.AddGetSet<HRESULT>("hr", &EventRENotify::hr);
		DEF_CAST_IOBJ(module, EventRENotify);
	}


	{
		JsClass<EventREMenu> jsCls = module->ExportClass<EventREMenu>("EventREMenu");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<unsigned int>("uCmd", &EventREMenu::uCmd);
		DEF_CAST_IOBJ(module, EventREMenu);
	}

	{
		JsClass<EventSliderPos> jsCls = module->ExportClass<EventSliderPos>("EventSliderPos");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<SliderBarAction>("action", &EventSliderPos::action);
		jsCls.AddGetSet<int>("nPos", &EventSliderPos::nPos);
		DEF_CAST_IOBJ(module, EventSliderPos);
	}

	{
		JsClass<EventHeaderClick> jsCls = module->ExportClass<EventHeaderClick>("EventHeaderClick");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("iItem", &EventHeaderClick::iItem);
		DEF_CAST_IOBJ(module, EventHeaderClick);
	}

	{
		JsClass<EventHeaderItemChanging> jsCls = module->ExportClass<EventHeaderItemChanging>("EventHeaderItemChanging");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("iItem", &EventHeaderItemChanging::iItem);
		jsCls.AddGetSet<int>("nWidth", &EventHeaderItemChanging::nWidth);
		DEF_CAST_IOBJ(module, EventHeaderItemChanging);
	}

	{
		JsClass<EventHeaderItemChanged> jsCls = module->ExportClass<EventHeaderItemChanged>("EventHeaderItemChanged");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("iItem", &EventHeaderItemChanged::iItem);
		jsCls.AddGetSet<int>("nWidth", &EventHeaderItemChanged::nWidth);
		DEF_CAST_IOBJ(module, EventHeaderItemChanged);
	}

	{
		JsClass<EventHeaderItemSwap> jsCls = module->ExportClass<EventHeaderItemSwap>("EventHeaderItemSwap");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("iOldIndex", &EventHeaderItemSwap::iOldIndex);
		jsCls.AddGetSet<int>("iNewIndex", &EventHeaderItemSwap::iNewIndex);
		DEF_CAST_IOBJ(module, EventHeaderItemSwap);
	}


	{
		JsClass<EventCBSelChange> jsCls = module->ExportClass<EventCBSelChange>("EventCBSelChange");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("nCurSel", &EventCBSelChange::nCurSel);
		DEF_CAST_IOBJ(module, EventCBSelChange);
	}

	{
		JsClass<EventCBDropdown> jsCls = module->ExportClass<EventCBDropdown>("EventCBDropdown");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<void*>("pDropDown", &EventCBDropdown::pDropDown);
		DEF_CAST_IOBJ(module, EventCBDropdown);
	}

	{
		JsClass<EventCBBeforeCloseUp> jsCls = module->ExportClass<EventCBBeforeCloseUp>("EventCBBeforeCloseUp");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<BOOL>("bCloseBlock", &EventCBBeforeCloseUp::bCloseBlock);
		DEF_CAST_IOBJ(module, EventCBBeforeCloseUp);
	}

	{
		JsClass<EventLCSelChanging> jsCls = module->ExportClass<EventLCSelChanging>("EventLCSelChanging");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("nNewSel", &EventLCSelChanging::nNewSel);
		jsCls.AddGetSet<int>("nOldSel", &EventLCSelChanging::nOldSel);
		jsCls.AddGetSet<BOOL>("bCancel", &EventLCSelChanging::bCancel);
		DEF_CAST_IOBJ(module, EventLCSelChanging);
	}

	{
		JsClass<EventLCSelChanged> jsCls = module->ExportClass<EventLCSelChanged>("EventLCSelChanged");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("nNewSel", &EventLCSelChanged::nNewSel);
		jsCls.AddGetSet<int>("nOldSel", &EventLCSelChanged::nOldSel);
		DEF_CAST_IOBJ(module, EventLCSelChanged);
	}

	{
		JsClass<EventLCDbClick> jsCls = module->ExportClass<EventLCDbClick>("EventLCDbClick");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("nCurSel", &EventLCDbClick::nCurSel);
		DEF_CAST_IOBJ(module, EventLCDbClick);
	}

	{
		JsClass<EventLCItemDeleted> jsCls = module->ExportClass<EventLCItemDeleted>("EventLCItemDeleted");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<int>("nItem", &EventLCItemDeleted::nItem);
		jsCls.AddGetSet<LPARAM>("dwData", &EventLCItemDeleted::dwData);
		DEF_CAST_IOBJ(module, EventLCItemDeleted);
	}

	{
		JsClass<EventCalendarSelDay> jsCls = module->ExportClass<EventCalendarSelDay>("EventCalendarSelDay");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<WORD>("wOldDay", &EventCalendarSelDay::wOldDay);
		jsCls.AddGetSet<WORD>("wNewDay", &EventCalendarSelDay::wNewDay);
		DEF_CAST_IOBJ(module, EventCalendarSelDay);
	}

	{
		JsClass<EventCalendarExChanged> jsCls = module->ExportClass<EventCalendarExChanged>("EventCalendarExChanged");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<WORD>("iNewDay", &EventCalendarExChanged::iNewDay);
		jsCls.AddGetSet<WORD>("iNewMonth", &EventCalendarExChanged::iNewMonth);
		jsCls.AddGetSet<WORD>("iNewYear", &EventCalendarExChanged::iNewYear);
		jsCls.AddGetSet<int>("nBtnType", &EventCalendarExChanged::nBtnType);
		DEF_CAST_IOBJ(module, EventCalendarExChanged);
	}

	{
		JsClass<EventDateTimeChanged> jsCls = module->ExportClass<EventDateTimeChanged>("EventDateTimeChanged");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<SYSTEMTIME>("newTime", &EventDateTimeChanged::newTime);
		DEF_CAST_IOBJ(module, EventDateTimeChanged);
	}

	{
		JsClass<EventTCSelChanging> jsCls = module->ExportClass<EventTCSelChanging>("EventTCSelChanging");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<ULONG_PTR>("hOldSel", &EventTCSelChanging::hOldSel);
		jsCls.AddGetSet<ULONG_PTR>("hNewSel", &EventTCSelChanging::hNewSel);
		jsCls.AddGetSet<BOOL>("bCancel", &EventTCSelChanging::bCancel);
		DEF_CAST_IOBJ(module, EventTCSelChanging);
	}


	{
		JsClass<EventTCSelChanged> jsCls = module->ExportClass<EventTCSelChanged>("EventTCSelChanged");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<ULONG_PTR>("hOldSel", &EventTCSelChanged::hOldSel);
		jsCls.AddGetSet<ULONG_PTR>("hNewSel", &EventTCSelChanged::hNewSel);
		DEF_CAST_IOBJ(module, EventTCSelChanged);
	}

	{
		JsClass<EventTCCheckState> jsCls = module->ExportClass<EventTCCheckState>("EventTCCheckState");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<ULONG_PTR>("hItem", &EventTCCheckState::hItem);
		jsCls.AddGetSet<UINT>("uCheckState", &EventTCCheckState::uCheckState);
		DEF_CAST_IOBJ(module, EventTCCheckState);
	}

	{
		JsClass<EventTCExpand> jsCls = module->ExportClass<EventTCExpand>("EventTCExpand");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<ULONG_PTR>("hItem", &EventTCExpand::hItem);
		jsCls.AddGetSet<BOOL>("bCollapsed", &EventTCExpand::bCollapsed);
		DEF_CAST_IOBJ(module, EventTCExpand);
	}

	{
		JsClass<EventTCDbClick> jsCls = module->ExportClass<EventTCDbClick>("EventTCDbClick");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<ULONG_PTR>("hItem", &EventTCDbClick::hItem);
		jsCls.AddGetSet<BOOL>("bCancel", &EventTCDbClick::bCancel);
		DEF_CAST_IOBJ(module, EventTCDbClick);
	}

	{
		JsClass<EventSplitPaneMoved> jsCls = module->ExportClass<EventSplitPaneMoved>("EventSplitPaneMoved");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<RECT>("rcPane", &EventSplitPaneMoved::rcPane);
		DEF_CAST_IOBJ(module, EventSplitPaneMoved);
	}

	{
		JsClass<EventSelectMenu> jsCls = module->ExportClass<EventSelectMenu>("EventSelectMenu");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<UINT>("nMenuId", &EventSelectMenu::nMenuId);
		jsCls.AddGetSet<void*>("pMenu", &EventSelectMenu::pMenu);
		DEF_CAST_IOBJ(module, EventSelectMenu);
	}

	{
		JsClass<EventPopMenu> jsCls = module->ExportClass<EventPopMenu>("EventPopMenu");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<UINT>("nMenuIndex", &EventPopMenu::nMenuIndex);
		jsCls.AddGetSet<void*>("pMenu", &EventPopMenu::pMenu);
		DEF_CAST_IOBJ(module, EventPopMenu);
	}

	{
		JsClass<EventSetHotKey> jsCls = module->ExportClass<EventSetHotKey>("EventSetHotKey");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet<WORD>("vKey", &EventSetHotKey::vKey);
		jsCls.AddGetSet<WORD>("wModifiers", &EventSetHotKey::wModifiers);
		DEF_CAST_IOBJ(module, EventSetHotKey);
	}
}