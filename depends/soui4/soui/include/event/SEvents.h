﻿/**
 * Copyright (C) 2014-2050
 * All rights reserved.
 *
 * @file       Events.h
 * @brief
 * @version    v1.0
 * @author     SOUI group
 * @date       2014/08/02
 *
 * Describe    SOUI系统中使用的事件系统
 */

#ifndef __SEVENTS__H__
#define __SEVENTS__H__

#include <interface/SEvtArgs-i.h>
#include <interface/sstring-i.h>
#ifdef __cplusplus
#include <sobject/Sobject.hpp>
#include <helper/obj-ref-impl.hpp>
#endif

SNSBEGIN

typedef struct IWindow IWindow;
typedef enum _SOUI_EVENTS
{
    EVT_INIT = 8000,
    EVT_EXIT,
    EVT_TIMER,
    EVT_GET_CARET,

    //基本窗口事件
    EVT_SETFOCUS = 8100,
    EVT_KILLFOCUS,
    EVT_CREATE,
    EVT_INIT_FINISH,
    EVT_DESTROY,
    EVT_SIZE,
    EVT_VISIBLECHANGED,
    EVT_STATECHANGED,
    EVT_CAPTURECHANGED,
    EVT_MOUSE_CLICK,
    EVT_UPDATE_TOOLTIP,
    EVT_ANIMATION_START,
    EVT_ANIMATION_STOP,
    EVT_ANIMATION_REPEAT,
    EVT_POS,

    EVT_KEYDOWN = 8200,

    //两个窗口鼠标状态事件
    EVT_MOUSE_HOVER = 9000,
    EVT_MOUSE_LEAVE,

    EVT_CMD = 10000,
    EVT_MENU_CMD,
    EVT_CTXMENU,

    //增加两个滚动VIEW的事件
    EVT_SCROLLVIEW_ORIGINCHANGED,
    EVT_SCROLLVIEW_SIZECHANGED,

    EVT_SCROLL,
    EVT_OFEVENT, //消息二次包装
    EVT_OFPANEL, //一个itemPanel中的消息的二次包装

    //增加4个itempanel相关的事件,经过EVT_OFPANEL到达应用层
    EVT_ITEMPANEL_CLICK,
    EVT_ITEMPANEL_RCLICK,
    EVT_ITEMPANEL_CLICK_UP,
    EVT_ITEMPANEL_RCLICK_UP,
    EVT_ITEMPANEL_DBCLICK,
    EVT_ITEMPANEL_HOVER,
    EVT_ITEMPANEL_LEAVE,

    EVT_RADIOGROUP_CHECK_CHANGED = 10100,

    EVT_TAB_SELCHANGING = 11000,
    EVT_TAB_SELCHANGED,
    EVT_TAB_ITEMHOVER,
    EVT_TAB_ITEMLEAVE,

    EVT_LB_SELCHANGING = 12000,
    EVT_LB_SELCHANGED,
    EVT_LB_DBCLICK,

    EVT_LC_SELCHANGING = 13000,
    EVT_LC_SELCHANGED,
    EVT_LC_ITEMDELETED,
    EVT_LC_DBCLICK,

    EVT_TV_SELCHANGING = 14000,
    EVT_TV_SELCHANGED,

    EVT_TC_SELCHANGING = 15000,
    EVT_TC_SELCHANGED,
    EVT_TC_EXPAND,
    EVT_TC_CHECKSTATE,
    EVT_TC_DBCLICK,
    EVT_CB_BEFORE_CLOSEUP,

    EVT_LV_SELCHANGING = 15100,
    EVT_LV_SELCHANGED,
    EVT_LV_ITEMCLICK,

    EVT_RE_NOTIFY = 16000,
    EVT_RE_MENU,

    EVT_SLIDER_POS = 17000,

    EVT_HEADER_CLICK = 18000,
    EVT_HEADER_ITEMCHANGING,
    EVT_HEADER_ITEMCHANGED,
    EVT_HEADER_ITEMSWAP,
    EVT_HEADER_RELAYOUT,

    EVT_CB_SELCHANGE = 19000,
    EVT_CB_DROPDOWN,

    EVT_CALENDAR_SELDAY = 20000,
    EVT_CALENDAR_SETDATE,
    EVT_CALENDAREX_CHANGED,
    EVT_DATETIME_CHANGED,

    EVT_SPIN_VALUE2STRING = 21000,

    EVT_SPLIT_PANE_MOVED = 22000,

    EVT_HOT_KEY_SET = 23000,

    //图片动画开始，结束事件
    EVT_IMAGE_ANI_START = 22100,
    EVT_IMAGE_ANI_STOP,
    EVT_IMAGE_ANI_REPEAT,

    EVT_SELECTMENU = 22150,
    EVT_POPMENU,

    EVT_EXTERNAL_BEGIN = 10000000,
} SOUI_EVENTS;

typedef enum _MouseClickId
{
    MOUSE_LBTN_DOWN = 0,
    MOUSE_LBTN_UP,
    MOUSE_LBTN_DBCLICK,
    MOUSE_RBTN_DOWN,
    MOUSE_RBTN_UP,
    MOUSE_RBTN_DBCLICK,
    MOUSE_MBTN_DOWN,
    MOUSE_MBTN_UP,
    MOUSE_MBTN_DBCLICK,
} MouseClickId;

#ifdef __cplusplus
class SOUI_EXP SEvtArgs : public TObjRefImpl<SObjectImpl<IEvtArgs>> {
    DEF_SOBJECT(SObjectImpl<IEvtArgs>, L"event")
  public:
    UINT handled;
    BOOL bubbleUp;
    int idFrom;
    LPCWSTR nameFrom;
    IObject *sender;

    STDMETHOD_(IObject *, Sender)(THIS)
    {
        return sender;
    }
    STDMETHOD_(int, IdFrom)(THIS) SCONST
    {
        return idFrom;
    }
    STDMETHOD_(void, SetIdFrom)(THIS_ int id)
    {
        idFrom = id;
    }
    STDMETHOD_(LPCWSTR, NameFrom)(THIS) SCONST
    {
        return nameFrom;
    }
    STDMETHOD_(void, SetNameFrom)(THIS_ LPCWSTR name)
    {
        nameFrom = name;
    }
    STDMETHOD_(BOOL, IsBubbleUp)(THIS) SCONST
    {
        return bubbleUp;
    }
    STDMETHOD_(void, SetBubbleUp)(THIS_ BOOL bSet)
    {
        bubbleUp = bSet;
    }
    STDMETHOD_(UINT, HandleCount)(THIS) SCONST
    {
        return handled;
    }
    STDMETHOD_(void, IncreaseHandleCount)(THIS)
    {
        handled++;
    }
    STDMETHOD_(LPVOID, Data)(THIS)
    {
        return NULL;
    }

  public:
    SEvtArgs(IObject *pSender)
        : handled(0)
        , sender(pSender)
        , bubbleUp(true)
    {
        if (NULL != sender)
        {
            idFrom = sender->GetID();
            nameFrom = sender->GetName();
            sender->AddRef();
        }
        else
        {
            idFrom = 0;
            nameFrom = NULL;
        }
    }

    virtual ~SEvtArgs()
    {
        if (sender)
        {
            sender->Release();
            sender = NULL;
        }
    }
};

//定义一组事件定义的宏，简化事件的定义。
#define DEF_EVT_CLASS(evt, id, evt_name, evtData, api) \
    class api evt                                      \
        : public SEvtArgs                              \
        , public evtData {                             \
        DEF_SOBJECT(SEvtArgs, WIDESTR(evt_name))       \
      public:                                          \
        STDMETHOD_(int, GetID)(THIS) const             \
        {                                              \
            return evt::EventID;                       \
        }                                              \
        STDMETHOD_(LPCWSTR, GetName)(THIS) const       \
        {                                              \
            return evt::GetClassName();                \
        }                                              \
        STDMETHOD_(LPVOID, Data)(THIS)                 \
        {                                              \
            return (evtData *)this;                    \
        }                                              \
        enum                                           \
        {                                              \
            EventID = id                               \
        };                                             \
        evt(SOUI::IObject *pSender = NULL)             \
            : SEvtArgs(pSender)                        \
        {                                              \
        }                                              \
    };

#define EVENTID(x) x::EventID, x::GetClassName()
#endif //__cplusplus

#define DEF_EVT_STRUCT(n, x) typedef struct n x n;

#ifdef __cplusplus
#define DEF_EVENT(evt, id, name, x, api) \
    DEF_EVT_STRUCT(St##evt, x)           \
    DEF_EVT_CLASS(evt, id, name, St##evt, api)
#else
#define DEF_EVENT(evt, id, name, x, api) DEF_EVT_STRUCT(St##evt, x)
#endif //__cplusplus

#define DEF_EVT(evt, id, name, x) DEF_EVENT(evt, id, name, x, SOUI_EXP)
#define DEF_EVT_EXT(evt, id, x)   DEF_EVENT(evt, id, on_##evt, x, )

DEF_EVT(EventInit, EVT_INIT, on_init, { int fake; })

DEF_EVT(EventExit, EVT_EXIT, on_exit, { int fake; })

DEF_EVT(EventTimer, EVT_TIMER, on_timer, {
    UINT uID;
    LPARAM uData;
})

DEF_EVT(EventGetCaret, EVT_GET_CARET, on_get_caret, { IStringW *strCaret; })

DEF_EVT(EventScroll, EVT_SCROLL, on_scroll, {
    int nSbCode;
    int nPos;
    BOOL bVertical;
})

DEF_EVT(EventSpinValue2String, EVT_SPIN_VALUE2STRING, on_spin_valuetostring, {
    BOOL bInit;
    int nValue;
    IStringT *strValue;
})

DEF_EVT(EventSwndCreate, EVT_CREATE, on_create, { int fake; })
DEF_EVT(EventSwndInitFinish, EVT_INIT_FINISH, on_init_finish, { int fake; })
DEF_EVT(EventSwndDestroy, EVT_DESTROY, on_destroy, { int fake; })

DEF_EVT(EventSwndSize, EVT_SIZE, on_size, { SIZE szWnd; })
DEF_EVT(EventSwndPos, EVT_POS, on_pos, { RECT rcWnd; })

DEF_EVT(EventSwndStateChanged, EVT_STATECHANGED, on_state_changed, {
    DWORD dwOldState;
    DWORD dwNewState;
})

#ifdef __cplusplus
inline BOOL EventSwndStateChanged_CheckState(EventSwndStateChanged *pEvt, DWORD dwState)
{
    return (pEvt->dwOldState & dwState) != (pEvt->dwNewState & dwState);
}
#endif

DEF_EVT(EventSwndCaptureChanged, EVT_CAPTURECHANGED, on_capture_changed, { BOOL bCaptured; })

DEF_EVT(EventSwndVisibleChanged, EVT_VISIBLECHANGED, on_visible_changed, { BOOL bVisible; })

DEF_EVT(EventSwndAnimationStart, EVT_ANIMATION_START, on_animation_start, { IAnimation *pAni; })

DEF_EVT(EventSwndAnimationStop, EVT_ANIMATION_STOP, on_animation_stop, { IAnimation *pAni; })
DEF_EVT(EventSwndAnimationRepeat, EVT_ANIMATION_REPEAT, on_animation_repeat, { IAnimation *pAni; })

DEF_EVT(EventKeyDown, EVT_KEYDOWN, on_key_down, {
    UINT nChar;
    UINT nFlags;
    BOOL bCancel;
})

DEF_EVT(EventSwndMouseLeave, EVT_MOUSE_LEAVE, on_mouse_leave, { int fake; })

DEF_EVT(EventSwndMouseHover, EVT_MOUSE_HOVER, on_mouse_hover, { int fake; })

DEF_EVT(EventSwndUpdateTooltip, EVT_UPDATE_TOOLTIP, on_update_tooltip, {
    IStringT *strToolTip;
    BOOL bUpdated;
})

DEF_EVT(EventRadioGroupCheckChanged, EVT_RADIOGROUP_CHECK_CHANGED, on_radiogroup_check_changed, { IWindow *pChecked; })

DEF_EVT(EventItemPanelRclick, EVT_ITEMPANEL_RCLICK, on_itemparem_rclick, {
    WPARAM wParam;
    LPARAM lParam;
})

DEF_EVT(EventItemPanelDbclick, EVT_ITEMPANEL_DBCLICK, on_itempanel_dbclick, {
    WPARAM wParam;
    LPARAM lParam;
})

DEF_EVT(EventItemPanelClick, EVT_ITEMPANEL_CLICK, on_itempanel_click, {
    WPARAM wParam;
    LPARAM lParam;
})

DEF_EVT(EventItemPanelRclickUp, EVT_ITEMPANEL_RCLICK_UP, on_itemparem_rclick_up, {
    WPARAM wParam;
    LPARAM lParam;
})

DEF_EVT(EventItemPanelClickUp, EVT_ITEMPANEL_CLICK_UP, on_itempanel_click_up, {
    WPARAM wParam;
    LPARAM lParam;
})

DEF_EVT(EventItemPanelHover, EVT_ITEMPANEL_HOVER, on_itempanel_hover, {
    WPARAM wParam;
    LPARAM lParam;
})

//注：在EventItemPanelLeave中从IItemPanel中通过GetItemIndex获取表项索引时需要检查索引有效性。
DEF_EVT(EventItemPanelLeave, EVT_ITEMPANEL_LEAVE, on_itempanel_leave, { int fake; })

DEF_EVT(EventMouseClick, EVT_MOUSE_CLICK, on_mouse_click, {
    POINT pt;
    UINT uFlags;
    MouseClickId clickId;
    BOOL bHover;
})

DEF_EVT(EventCmd, EVT_CMD, on_command, { int fake; })

DEF_EVT(EventMenuCmd, EVT_MENU_CMD, on_menu_command, { int menuId; })

DEF_EVT(EventCtxMenu, EVT_CTXMENU, on_conext_menu, {
    POINT pt;
    BOOL bCancel;
})

DEF_EVT(EventSetFocus, EVT_SETFOCUS, on_set_focus, { SWND wndOld; })

DEF_EVT(EventKillFocus, EVT_KILLFOCUS, on_kill_focus, { SWND wndFocus; })

DEF_EVT(EventScrollViewOriginChanged, EVT_SCROLLVIEW_ORIGINCHANGED, on_scrollview_origin_changed, {
    POINT ptOldOrigin;
    POINT ptNewOrigin;
})

DEF_EVT(EventScrollViewSizeChanged, EVT_SCROLLVIEW_SIZECHANGED, on_scrollview_size_changed, {
    SIZE szOldViewSize;
    SIZE szNewViewSize;
})

DEF_EVT(EventOfEvent, EVT_OFEVENT, on_event_of_event, { IEvtArgs *pOrgEvt; })

DEF_EVT(EventOfPanel, EVT_OFPANEL, on_event_of_panel, {
    IWindow *pPanel;
    IEvtArgs *pOrgEvt;
})

DEF_EVT(EventTabSelChanging, EVT_TAB_SELCHANGING, on_tab_sel_changing, {
    UINT uOldSel;
    UINT uNewSel;
    BOOL bCancel;
})

DEF_EVT(EventTabSelChanged, EVT_TAB_SELCHANGED, on_tab_sel_changed, {
    UINT uOldSel;
    UINT uNewSel;
})

DEF_EVT(EventTabItemHover, EVT_TAB_ITEMHOVER, on_tab_item_hover, { int iHover; })

DEF_EVT(EventTabItemLeave, EVT_TAB_ITEMLEAVE, on_tab_item_leave, { int iLeave; })

DEF_EVT(EventLBSelChanging, EVT_LB_SELCHANGING, on_listbox_sel_changing, {
    int nNewSel;
    int nOldSel;
    BOOL bCancel;
})

DEF_EVT(EventLBSelChanged, EVT_LB_SELCHANGED, on_listbox_sel_changed, {
    int nNewSel;
    int nOldSel;
})

DEF_EVT(EventLBDbClick, EVT_LB_DBCLICK, on_listbox_item_dbclick, { int nCurSel; })

DEF_EVT(EventLVSelChanged, EVT_LV_SELCHANGED, on_listview_select_changed, {
    int iOldSel; //原选中项
    int iNewSel; //新选中项
})

DEF_EVT(EventLVSelChanging, EVT_LV_SELCHANGING, on_listview_select_changing, {
    int iOldSel; //原选中项
    int iNewSel; //新选中项
    BOOL bCancel;
})

DEF_EVT(EventTVSelChanged, EVT_TV_SELCHANGED, on_treeview_select_changed, {
    ULONG_PTR hOldSel; //原选中项
    ULONG_PTR hNewSel; //新选中项
})

DEF_EVT(EventTVSelChanging, EVT_TV_SELCHANGING, on_treeview_select_changing, {
    ULONG_PTR hOldSel; //原选中项
    ULONG_PTR hNewSel; //新选中项
    BOOL bCancel;
})

DEF_EVT(EventRENotify, EVT_RE_NOTIFY, on_richedit_notify, {
    DWORD iNotify;
    LPVOID pv;
    HRESULT hr;
})

DEF_EVT(EventREMenu, EVT_RE_MENU, on_richedit_menu, { UINT uCmd; })

typedef enum _SliderBarAction
{
    SBA_MOUSE_DOWN = 0,
    SBA_MOUSE_MOVING,
    SBA_MOUSE_UP
} SliderBarAction;
DEF_EVT(EventSliderPos, EVT_SLIDER_POS, on_slider_pos, {
    int nPos;
    SliderBarAction action;
})

//点击表头
DEF_EVT(EventHeaderClick, EVT_HEADER_CLICK, on_header_click, { int iItem; })

//表头宽度改变中
DEF_EVT(EventHeaderItemChanging, EVT_HEADER_ITEMCHANGING, on_header_item_changing, {
    int iItem;
    int nWidth;
})

//表头宽度改变
DEF_EVT(EventHeaderItemChanged, EVT_HEADER_ITEMCHANGED, on_header_item_changed, {
    int iItem;
    int nWidth;
})

//拖动表项调整位置
DEF_EVT(EventHeaderItemSwap, EVT_HEADER_ITEMSWAP, on_header_item_swap, {
    int iOldIndex;
    int iNewIndex;
})

DEF_EVT(EventHeaderRelayout, EVT_HEADER_RELAYOUT, on_header_relayout, { int fake; })

DEF_EVT(EventCBSelChange, EVT_CB_SELCHANGE, on_combobox_sel_change, { int nCurSel; })

DEF_EVT(EventCBDropdown, EVT_CB_DROPDOWN, on_combobox_dropdown, { void *pDropDown; })

DEF_EVT(EventCBBeforeCloseUp, EVT_CB_BEFORE_CLOSEUP, on_combobox_before_closeup, { BOOL bCloseBlock; })

DEF_EVT(EventLCSelChanging, EVT_LC_SELCHANGING, on_listctrl_sel_changing, {
    int nNewSel;
    int nOldSel;
    BOOL bCancel;
})

DEF_EVT(EventLCSelChanged, EVT_LC_SELCHANGED, on_listctrl_sel_changed, {
    int nNewSel;
    int nOldSel;
})

DEF_EVT(EventLCDbClick, EVT_LC_DBCLICK, on_listctrl_item_dbclick, { int nCurSel; })

DEF_EVT(EventLCItemDeleted, EVT_LC_ITEMDELETED, on_listctrl_del_item, {
    int nItem;
    LPARAM dwData;
})

DEF_EVT(EventCalendarSelDay, EVT_CALENDAR_SELDAY, on_calendar_sel_day, {
    WORD wOldDay;
    WORD wNewDay;
})

DEF_EVT(EventCalendarSetDate, EVT_CALENDAR_SETDATE, on_calendar_set_date, { int fake; })

DEF_EVT(EventCalendarExChanged, EVT_CALENDAREX_CHANGED, on_calendarex_changed, {
    WORD iNewDay;
    WORD iNewMonth;
    WORD iNewYear;
    int nBtnType; // 按钮 类型
})

DEF_EVT(EventDateTimeChanged, EVT_DATETIME_CHANGED, on_datetime_changed, { SYSTEMTIME newTime; })

DEF_EVT(EventTCSelChanging, EVT_TC_SELCHANGING, on_treectrl_sel_changing, {
    HSTREEITEM hOldSel;
    HSTREEITEM hNewSel;
    BOOL bCancel;
})

DEF_EVT(EventTCSelChanged, EVT_TC_SELCHANGED, on_treectrl_sel_changed, {
    HSTREEITEM hOldSel;
    HSTREEITEM hNewSel;
})

DEF_EVT(EventTCCheckState, EVT_TC_CHECKSTATE, on_treectrl_item_check, {
    HSTREEITEM hItem;
    UINT uCheckState;
})

DEF_EVT(EventTCExpand, EVT_TC_EXPAND, on_treectrl_item_expand, {
    HSTREEITEM hItem;
    BOOL bCollapsed;
})

//双击treectrl的叶子节点 add by zhaosheng
DEF_EVT(EventTCDbClick, EVT_TC_DBCLICK, on_treectrl_item_dbclick, {
    HSTREEITEM hItem; //双击选中的节点
    BOOL bCancel;
})

DEF_EVT(EventSplitPaneMoved, EVT_SPLIT_PANE_MOVED, on_split_pane_moved, { RECT rcPane; })

DEF_EVT(EventImageAnimateStart, EVT_IMAGE_ANI_START, on_image_animate_start, { int fake; })

DEF_EVT(EventImageAnimateStop, EVT_IMAGE_ANI_STOP, on_image_animate_stop, { int fake; })

DEF_EVT(EventImageAnimateRepeat, EVT_IMAGE_ANI_REPEAT, on_image_animate_repeat, { int fake; })

DEF_EVT(EventSelectMenu, EVT_SELECTMENU, on_select_menu, {
    UINT nMenuId;
    void *pMenu;
})
DEF_EVT(EventPopMenu, EVT_POPMENU, on_pop_menu, {
    UINT nMenuIndex;
    void *pMenu;
})

DEF_EVT(EventSetHotKey, EVT_HOT_KEY_SET, on_hot_key_set_event, {
    WORD vKey;
    WORD wModifiers;
})

SNSEND

#endif // __SEVENTS__H__