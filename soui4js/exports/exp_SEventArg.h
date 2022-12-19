#pragma once
#include <event/SEvents.h>
#include "toobj.h"

void Exp_SEventArg(qjsbind::Module* module) {
	{
		JsClass<EventTimer> jsCls = module->ExportClass<EventTimer>("EventTimer");
		jsCls.Init(JsClass<IEvtArgs>::class_id());
		jsCls.AddGetSet("uID", &EventTimer::uID);
		DEF_CAST_IOBJ(module, EventTimer);
	}

	{JsClass<EventSwndSize> jsCls = module->ExportClass<EventSwndSize>("EventSwndSize");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("szWnd", &EventSwndSize::szWnd);
	DEF_CAST_IOBJ(module, EventSwndSize); }

	{JsClass<EventScroll> jsCls = module->ExportClass<EventScroll>("EventScroll");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("nSbCode", &EventScroll::nSbCode);
	jsCls.AddGetSet("nPos", &EventScroll::nPos);
	jsCls.AddGetSet("bVertical", &EventScroll::bVertical);
	DEF_CAST_IOBJ(module, EventScroll); }
	

	{JsClass<EventSpinValue2String> jsCls = module->ExportClass<EventSpinValue2String>("EventSpinValue2String");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("bInit", &EventSpinValue2String::bInit);
	jsCls.AddGetSet("nValue", &EventSpinValue2String::nValue);
	jsCls.AddGetSet("strValue", &EventSpinValue2String::strValue);
	DEF_CAST_IOBJ(module, EventSpinValue2String); }

	{JsClass<EventSwndStateChanged> jsCls = module->ExportClass<EventSwndStateChanged>("EventSwndStateChanged");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("dwOldState", &EventSwndStateChanged::dwOldState);
	jsCls.AddGetSet("dwNewState", &EventSwndStateChanged::dwNewState);
	DEF_CAST_IOBJ(module, EventSwndStateChanged); }

	{JsClass<EventSwndCaptureChanged> jsCls = module->ExportClass<EventSwndCaptureChanged>("EventSwndCaptureChanged");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("bCaptured", &EventSwndCaptureChanged::bCaptured);
	DEF_CAST_IOBJ(module, EventSwndCaptureChanged); }

	{JsClass<EventSwndVisibleChanged> jsCls = module->ExportClass<EventSwndVisibleChanged>("EventSwndVisibleChanged");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("bVisible", &EventSwndVisibleChanged::bVisible);
	DEF_CAST_IOBJ(module, EventSwndVisibleChanged); }

	{JsClass<EventSwndAnimationStart> jsCls = module->ExportClass<EventSwndAnimationStart>("EventSwndAnimationStart");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("pAni", &EventSwndAnimationStart::pAni);
	DEF_CAST_IOBJ(module, EventSwndAnimationStart); }

	{JsClass<EventSwndAnimationStop> jsCls = module->ExportClass<EventSwndAnimationStop>("EventSwndAnimationStop");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("pAni", &EventSwndAnimationStop::pAni);
	DEF_CAST_IOBJ(module, EventSwndAnimationStop); }

	{JsClass<EventSwndAnimationRepeat> jsCls = module->ExportClass<EventSwndAnimationRepeat>("EventSwndAnimationRepeat");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("pAni", &EventSwndAnimationRepeat::pAni);
	DEF_CAST_IOBJ(module, EventSwndAnimationRepeat); }

	{JsClass<EventKeyDown> jsCls = module->ExportClass<EventKeyDown>("EventKeyDown");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("nChar", &EventKeyDown::nChar);
	jsCls.AddGetSet("nFlags", &EventKeyDown::nFlags);
	jsCls.AddGetSet("bCancel", &EventKeyDown::bCancel);
	DEF_CAST_IOBJ(module, EventKeyDown); }

	{JsClass<EventSwndUpdateTooltip> jsCls = module->ExportClass<EventSwndUpdateTooltip>("EventSwndUpdateTooltip");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("strToolTip", &EventSwndUpdateTooltip::strToolTip);
	jsCls.AddGetSet("bUpdated", &EventSwndUpdateTooltip::bUpdated);
	DEF_CAST_IOBJ(module, EventSwndUpdateTooltip); }


	{JsClass<EventRadioGroupCheckChanged> jsCls = module->ExportClass<EventRadioGroupCheckChanged>("EventRadioGroupCheckChanged");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("pChecked", &EventRadioGroupCheckChanged::pChecked);
	DEF_CAST_IOBJ(module, EventRadioGroupCheckChanged); }

	{JsClass<EventItemPanelRclick> jsCls = module->ExportClass<EventItemPanelRclick>("EventItemPanelRclick");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("wParam", &EventItemPanelRclick::wParam);
	jsCls.AddGetSet("lParam", &EventItemPanelRclick::lParam);
	DEF_CAST_IOBJ(module, EventItemPanelRclick); }

	{JsClass<EventItemPanelDbclick> jsCls = module->ExportClass<EventItemPanelDbclick>("EventItemPanelDbclick");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("wParam", &EventItemPanelDbclick::wParam);
	jsCls.AddGetSet("lParam", &EventItemPanelDbclick::lParam);
	DEF_CAST_IOBJ(module, EventItemPanelDbclick); }


	{JsClass<EventItemPanelClick> jsCls = module->ExportClass<EventItemPanelClick>("EventItemPanelClick");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("wParam", &EventItemPanelClick::wParam);
	jsCls.AddGetSet("lParam", &EventItemPanelClick::lParam);
	DEF_CAST_IOBJ(module, EventItemPanelClick); }

	{JsClass<EventItemPanelRclickUp> jsCls = module->ExportClass<EventItemPanelRclickUp>("EventItemPanelRclickUp");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("wParam", &EventItemPanelRclickUp::wParam);
	jsCls.AddGetSet("lParam", &EventItemPanelRclickUp::lParam);
	DEF_CAST_IOBJ(module, EventItemPanelRclickUp); }


	{JsClass<EventItemPanelClickUp> jsCls = module->ExportClass<EventItemPanelClickUp>("EventItemPanelClickUp");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("wParam", &EventItemPanelClickUp::wParam);
	jsCls.AddGetSet("lParam", &EventItemPanelClickUp::lParam);
	DEF_CAST_IOBJ(module, EventItemPanelClickUp); }

	{JsClass<EventItemPanelHover> jsCls = module->ExportClass<EventItemPanelHover>("EventItemPanelHover");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("wParam", &EventItemPanelHover::wParam);
	jsCls.AddGetSet("lParam", &EventItemPanelHover::lParam);
	DEF_CAST_IOBJ(module, EventItemPanelHover); }


	{JsClass<EventMouseClick> jsCls = module->ExportClass<EventMouseClick>("EventMouseClick");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGet("pt", &EventMouseClick::pt);
	jsCls.AddGet("uFlags", &EventMouseClick::uFlags);
	jsCls.AddGet("clickId", &EventMouseClick::clickId);
	jsCls.AddGet("bHover", &EventMouseClick::bHover);
	DEF_CAST_IOBJ(module, EventMouseClick); }

	{JsClass<EventCtxMenu> jsCls = module->ExportClass<EventCtxMenu>("EventCtxMenu");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("pt", &EventCtxMenu::pt);
	jsCls.AddGetSet("bCancel", &EventCtxMenu::bCancel);
	DEF_CAST_IOBJ(module, EventCtxMenu); }

	{JsClass<EventSetFocus> jsCls = module->ExportClass<EventSetFocus>("EventSetFocus");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("wndOld", &EventSetFocus::wndOld);
	DEF_CAST_IOBJ(module, EventSetFocus); }

	{JsClass<EventKillFocus> jsCls = module->ExportClass<EventKillFocus>("EventKillFocus");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("wndFocus", &EventKillFocus::wndFocus);
	DEF_CAST_IOBJ(module, EventKillFocus); }


	{JsClass<EventScrollViewOriginChanged> jsCls = module->ExportClass<EventScrollViewOriginChanged>("EventScrollViewOriginChanged");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("ptOldOrigin", &EventScrollViewOriginChanged::ptOldOrigin);
	jsCls.AddGetSet("ptNewOrigin", &EventScrollViewOriginChanged::ptNewOrigin);
	DEF_CAST_IOBJ(module, EventScrollViewOriginChanged); }


	{JsClass<EventScrollViewSizeChanged> jsCls = module->ExportClass<EventScrollViewSizeChanged>("EventScrollViewSizeChanged");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("szOldViewSize", &EventScrollViewSizeChanged::szOldViewSize);
	jsCls.AddGetSet("szNewViewSize", &EventScrollViewSizeChanged::szNewViewSize);
	DEF_CAST_IOBJ(module, EventScrollViewSizeChanged); }

	{JsClass<EventOfEvent> jsCls = module->ExportClass<EventOfEvent>("EventOfEvent");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("pOrgEvt", &EventOfEvent::pOrgEvt);
	DEF_CAST_IOBJ(module, EventOfEvent); }

	{JsClass<EventOfPanel> jsCls = module->ExportClass<EventOfPanel>("EventOfPanel");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("pPanel", &EventOfPanel::pPanel);
	jsCls.AddGetSet("pOrgEvt", &EventOfPanel::pOrgEvt);
	DEF_CAST_IOBJ(module, EventOfPanel); }

	{JsClass<EventTabSelChanging> jsCls = module->ExportClass<EventTabSelChanging>("EventTabSelChanging");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("uOldSel", &EventTabSelChanging::uOldSel);
	jsCls.AddGetSet("uNewSel", &EventTabSelChanging::uNewSel);
	jsCls.AddGetSet("bCancel", &EventTabSelChanging::bCancel);
	DEF_CAST_IOBJ(module, EventTabSelChanging); }

	{JsClass<EventTabSelChanged> jsCls = module->ExportClass<EventTabSelChanged>("EventTabSelChanged");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("uOldSel", &EventTabSelChanged::uOldSel);
	jsCls.AddGetSet("uNewSel", &EventTabSelChanged::uNewSel);
	DEF_CAST_IOBJ(module, EventTabSelChanged); }

	{JsClass<EventTabItemHover> jsCls = module->ExportClass<EventTabItemHover>("EventTabItemHover");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("iHover", &EventTabItemHover::iHover);
	DEF_CAST_IOBJ(module, EventTabItemHover); }

	{JsClass<EventTabItemLeave> jsCls = module->ExportClass<EventTabItemLeave>("EventTabItemLeave");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("iLeave", &EventTabItemLeave::iLeave);
	DEF_CAST_IOBJ(module, EventTabItemLeave); }

	{JsClass<EventLBSelChanging> jsCls = module->ExportClass<EventLBSelChanging>("EventLBSelChanging");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("nNewSel", &EventLBSelChanging::nNewSel);
	jsCls.AddGetSet("nOldSel", &EventLBSelChanging::nOldSel);
	jsCls.AddGetSet("bCancel", &EventLBSelChanging::bCancel);
	DEF_CAST_IOBJ(module, EventLBSelChanging); }

	{JsClass<EventLBSelChanged> jsCls = module->ExportClass<EventLBSelChanged>("EventLBSelChanged");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("nNewSel", &EventLBSelChanged::nNewSel);
	jsCls.AddGetSet("nOldSel", &EventLBSelChanged::nOldSel);
	DEF_CAST_IOBJ(module, EventLBSelChanged); }

	{JsClass<EventLBDbClick> jsCls = module->ExportClass<EventLBDbClick>("EventLBDbClick");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("nCurSel", &EventLBDbClick::nCurSel);
	DEF_CAST_IOBJ(module, EventLBDbClick); }

	{JsClass<EventLVSelChanged> jsCls = module->ExportClass<EventLVSelChanged>("EventLVSelChanged");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("iOldSel", &EventLVSelChanged::iOldSel);
	jsCls.AddGetSet("iNewSel", &EventLVSelChanged::iNewSel);
	DEF_CAST_IOBJ(module, EventLVSelChanged); }

	{JsClass<EventLVSelChanging> jsCls = module->ExportClass<EventLVSelChanging>("EventLVSelChanging");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("iOldSel", &EventLVSelChanging::iOldSel);
	jsCls.AddGetSet("iNewSel", &EventLVSelChanging::iNewSel);
	jsCls.AddGetSet("bCancel", &EventLVSelChanging::bCancel);
	DEF_CAST_IOBJ(module, EventLVSelChanging); }

	{JsClass<EventTVSelChanged> jsCls = module->ExportClass<EventTVSelChanged>("EventTVSelChanged");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("hOldSel", &EventTVSelChanged::hOldSel);
	jsCls.AddGetSet("hNewSel", &EventTVSelChanged::hNewSel);
	DEF_CAST_IOBJ(module, EventTVSelChanged); }

	{JsClass<EventTVSelChanging> jsCls = module->ExportClass<EventTVSelChanging>("EventTVSelChanging");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("hOldSel", &EventTVSelChanging::hOldSel);
	jsCls.AddGetSet("hNewSel", &EventTVSelChanging::hNewSel);
	jsCls.AddGetSet("bCancel", &EventTVSelChanging::bCancel);
	DEF_CAST_IOBJ(module, EventTVSelChanging); }

	{JsClass<EventRENotify> jsCls = module->ExportClass<EventRENotify>("EventRENotify");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("iNotify", &EventRENotify::iNotify);
	jsCls.AddGetSet("pv", &EventRENotify::pv);
	jsCls.AddGetSet("hr", &EventRENotify::hr);
	DEF_CAST_IOBJ(module, EventRENotify); }


	{JsClass<EventREMenu> jsCls = module->ExportClass<EventREMenu>("EventREMenu");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("uCmd", &EventREMenu::uCmd);
	DEF_CAST_IOBJ(module, EventREMenu); }

	{JsClass<EventSliderPos> jsCls = module->ExportClass<EventSliderPos>("EventSliderPos");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("nPos", &EventSliderPos::nPos);
	DEF_CAST_IOBJ(module, EventSliderPos); }

	{JsClass<EventHeaderClick> jsCls = module->ExportClass<EventHeaderClick>("EventHeaderClick");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("iItem", &EventHeaderClick::iItem);
	DEF_CAST_IOBJ(module, EventHeaderClick); }

	{JsClass<EventHeaderItemChanging> jsCls = module->ExportClass<EventHeaderItemChanging>("EventHeaderItemChanging");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("iItem", &EventHeaderItemChanging::iItem);
	jsCls.AddGetSet("nWidth", &EventHeaderItemChanging::nWidth);
	DEF_CAST_IOBJ(module, EventHeaderItemChanging); }

	{JsClass<EventHeaderItemChanged> jsCls = module->ExportClass<EventHeaderItemChanged>("EventHeaderItemChanged");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("iItem", &EventHeaderItemChanged::iItem);
	jsCls.AddGetSet("nWidth", &EventHeaderItemChanged::nWidth);
	DEF_CAST_IOBJ(module, EventHeaderItemChanged); }

	{JsClass<EventHeaderItemSwap> jsCls = module->ExportClass<EventHeaderItemSwap>("EventHeaderItemSwap");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("iOldIndex", &EventHeaderItemSwap::iOldIndex);
	jsCls.AddGetSet("iNewIndex", &EventHeaderItemSwap::iNewIndex);
	DEF_CAST_IOBJ(module, EventHeaderItemSwap); }


	{JsClass<EventCBSelChange> jsCls = module->ExportClass<EventCBSelChange>("EventCBSelChange");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("nCurSel", &EventCBSelChange::nCurSel);
	DEF_CAST_IOBJ(module, EventCBSelChange); }

	{JsClass<EventCBDropdown> jsCls = module->ExportClass<EventCBDropdown>("EventCBDropdown");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("pDropDown", &EventCBDropdown::pDropDown);
	DEF_CAST_IOBJ(module, EventCBDropdown); }

	{JsClass<EventCBBeforeCloseUp> jsCls = module->ExportClass<EventCBBeforeCloseUp>("EventCBBeforeCloseUp");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("bCloseBlock", &EventCBBeforeCloseUp::bCloseBlock);
	DEF_CAST_IOBJ(module, EventCBBeforeCloseUp); }

	{JsClass<EventLCSelChanging> jsCls = module->ExportClass<EventLCSelChanging>("EventLCSelChanging");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("nNewSel", &EventLCSelChanging::nNewSel);
	jsCls.AddGetSet("nOldSel", &EventLCSelChanging::nOldSel);
	jsCls.AddGetSet("bCancel", &EventLCSelChanging::bCancel);
	DEF_CAST_IOBJ(module, EventLCSelChanging); }

	{JsClass<EventLCSelChanged> jsCls = module->ExportClass<EventLCSelChanged>("EventLCSelChanged");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("nNewSel", &EventLCSelChanged::nNewSel);
	jsCls.AddGetSet("nOldSel", &EventLCSelChanged::nOldSel);
	DEF_CAST_IOBJ(module, EventLCSelChanged); }

	{JsClass<EventLCDbClick> jsCls = module->ExportClass<EventLCDbClick>("EventLCDbClick");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("nCurSel", &EventLCDbClick::nCurSel);
	DEF_CAST_IOBJ(module, EventLCDbClick); }

	{JsClass<EventLCItemDeleted> jsCls = module->ExportClass<EventLCItemDeleted>("EventLCItemDeleted");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("nItem", &EventLCItemDeleted::nItem);
	jsCls.AddGetSet("dwData", &EventLCItemDeleted::dwData);
	DEF_CAST_IOBJ(module, EventLCItemDeleted); }

	{JsClass<EventCalendarSelDay> jsCls = module->ExportClass<EventCalendarSelDay>("EventCalendarSelDay");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("wOldDay", &EventCalendarSelDay::wOldDay);
	jsCls.AddGetSet("wNewDay", &EventCalendarSelDay::wNewDay);
	DEF_CAST_IOBJ(module, EventCalendarSelDay); }

	{JsClass<EventCalendarExChanged> jsCls = module->ExportClass<EventCalendarExChanged>("EventCalendarExChanged");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("iNewDay", &EventCalendarExChanged::iNewDay);
	jsCls.AddGetSet("iNewMonth", &EventCalendarExChanged::iNewMonth);
	jsCls.AddGetSet("iNewYear", &EventCalendarExChanged::iNewYear);
	jsCls.AddGetSet("nBtnType", &EventCalendarExChanged::nBtnType);
	DEF_CAST_IOBJ(module, EventCalendarExChanged); }

	{JsClass<EventDateTimeChanged> jsCls = module->ExportClass<EventDateTimeChanged>("EventDateTimeChanged");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("newTime", &EventDateTimeChanged::newTime);
	DEF_CAST_IOBJ(module, EventDateTimeChanged); }

	{JsClass<EventTCSelChanging> jsCls = module->ExportClass<EventTCSelChanging>("EventTCSelChanging");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("hOldSel", &EventTCSelChanging::hOldSel);
	jsCls.AddGetSet("hNewSel", &EventTCSelChanging::hNewSel);
	jsCls.AddGetSet("bCancel", &EventTCSelChanging::bCancel);
	DEF_CAST_IOBJ(module, EventTCSelChanging); }


	{JsClass<EventTCSelChanged> jsCls = module->ExportClass<EventTCSelChanged>("EventTCSelChanged");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("hOldSel", &EventTCSelChanged::hOldSel);
	jsCls.AddGetSet("hNewSel", &EventTCSelChanged::hNewSel);
	DEF_CAST_IOBJ(module, EventTCSelChanged); }

	{JsClass<EventTCCheckState> jsCls = module->ExportClass<EventTCCheckState>("EventTCCheckState");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("hItem", &EventTCCheckState::hItem);
	jsCls.AddGetSet("uCheckState", &EventTCCheckState::uCheckState);
	DEF_CAST_IOBJ(module, EventTCCheckState); }

	{JsClass<EventTCExpand> jsCls = module->ExportClass<EventTCExpand>("EventTCExpand");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("hItem", &EventTCExpand::hItem);
	jsCls.AddGetSet("bCollapsed", &EventTCExpand::bCollapsed);
	DEF_CAST_IOBJ(module, EventTCExpand); }

	{JsClass<EventTCDbClick> jsCls = module->ExportClass<EventTCDbClick>("EventTCDbClick");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("hItem", &EventTCDbClick::hItem);
	jsCls.AddGetSet("bCancel", &EventTCDbClick::bCancel);
	DEF_CAST_IOBJ(module, EventTCDbClick); }

	{JsClass<EventSplitPaneMoved> jsCls = module->ExportClass<EventSplitPaneMoved>("EventSplitPaneMoved");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("rcPane", &EventSplitPaneMoved::rcPane);
	DEF_CAST_IOBJ(module, EventSplitPaneMoved); }

	{JsClass<EventSelectMenu> jsCls = module->ExportClass<EventSelectMenu>("EventSelectMenu");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("nMenuId", &EventSelectMenu::nMenuId);
	jsCls.AddGetSet("pMenu", &EventSelectMenu::pMenu);
	DEF_CAST_IOBJ(module, EventSelectMenu); }

	{JsClass<EventPopMenu> jsCls = module->ExportClass<EventPopMenu>("EventPopMenu");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("nMenuIndex", &EventPopMenu::nMenuIndex);
	jsCls.AddGetSet("pMenu", &EventPopMenu::pMenu);
	DEF_CAST_IOBJ(module, EventPopMenu); }

	{JsClass<EventSetHotKey> jsCls = module->ExportClass<EventSetHotKey>("EventSetHotKey");
	jsCls.Init(JsClass<IEvtArgs>::class_id());
	jsCls.AddGetSet("vKey", &EventSetHotKey::vKey);
	jsCls.AddGetSet("wModifiers", &EventSetHotKey::wModifiers);
	DEF_CAST_IOBJ(module, EventSetHotKey); }

}
