#pragma once

#include <qjsbind.h>
#include <event/SEvents.h>
#include <core/SDefine.h>
#include "exp_SRegKey.h"
#include "exp_SValueAnimator.h"

using namespace SOUI;

#define SEnumInt(x) module->ExportEnumInt32(#x, x)
#define SEnumUint(x) module->ExportEnumUint32(#x, x)
#define SEnumUint64(x) module->ExportEnumUint64(#x, x)

void Exp_SEnum(qjsbind::Module* module){
//soui events
SEnumInt(EVT_INIT);
SEnumInt(EVT_EXIT);
SEnumInt(EVT_TIMER);
SEnumInt(EVT_SETFOCUS);
SEnumInt(EVT_KILLFOCUS);
SEnumInt(EVT_CREATE);
SEnumInt(EVT_INIT_FINISH);
SEnumInt(EVT_DESTROY);
SEnumInt(EVT_SIZE);
SEnumInt(EVT_VISIBLECHANGED);
SEnumInt(EVT_STATECHANGED);
SEnumInt(EVT_MOUSE_CLICK);
SEnumInt(EVT_UPDATE_TOOLTIP);
SEnumInt(EVT_ANIMATION_START);
SEnumInt(EVT_ANIMATION_STOP);
SEnumInt(EVT_ANIMATION_REPEAT);
SEnumInt(EVT_POS);
SEnumInt(EVT_KEYDOWN);
SEnumInt(EVT_MOUSE_HOVER);
SEnumInt(EVT_MOUSE_LEAVE);
SEnumInt(EVT_CMD);
SEnumInt(EVT_MENU_CMD);
SEnumInt(EVT_CTXMENU);
SEnumInt(EVT_SCROLLVIEW_ORIGINCHANGED);
SEnumInt(EVT_SCROLLVIEW_SIZECHANGED);
SEnumInt(EVT_SCROLL);
SEnumInt(EVT_OFEVENT);
SEnumInt(EVT_OFPANEL);
SEnumInt(EVT_ITEMPANEL_CLICK);
SEnumInt(EVT_ITEMPANEL_RCLICK);
SEnumInt(EVT_ITEMPANEL_CLICK_UP);
SEnumInt(EVT_ITEMPANEL_RCLICK_UP);
SEnumInt(EVT_ITEMPANEL_DBCLICK);
SEnumInt(EVT_ITEMPANEL_HOVER);
SEnumInt(EVT_ITEMPANEL_LEAVE);
SEnumInt(EVT_RADIOGROUP_CHECK_CHANGED);
SEnumInt(EVT_TAB_SELCHANGING);
SEnumInt(EVT_TAB_SELCHANGED);
SEnumInt(EVT_TAB_ITEMHOVER);
SEnumInt(EVT_TAB_ITEMLEAVE);
SEnumInt(EVT_LB_SELCHANGING);
SEnumInt(EVT_LB_SELCHANGED);
SEnumInt(EVT_LB_DBCLICK);
SEnumInt(EVT_LC_SELCHANGING);
SEnumInt(EVT_LC_SELCHANGED);
SEnumInt(EVT_LC_ITEMDELETED);
SEnumInt(EVT_LC_DBCLICK);
SEnumInt(EVT_TV_SELCHANGING);
SEnumInt(EVT_TV_SELCHANGED);
SEnumInt(EVT_TC_SELCHANGING);
SEnumInt(EVT_TC_SELCHANGED);
SEnumInt(EVT_TC_EXPAND);
SEnumInt(EVT_TC_CHECKSTATE);
SEnumInt(EVT_TC_DBCLICK);
SEnumInt(EVT_CB_BEFORE_CLOSEUP);
SEnumInt(EVT_LV_SELCHANGING);
SEnumInt(EVT_LV_SELCHANGED);
SEnumInt(EVT_LV_ITEMCLICK);
SEnumInt(EVT_RE_NOTIFY);
SEnumInt(EVT_RE_MENU);
SEnumInt(EVT_SLIDER_POS);
SEnumInt(EVT_HEADER_CLICK);
SEnumInt(EVT_HEADER_ITEMCHANGING);
SEnumInt(EVT_HEADER_ITEMCHANGED);
SEnumInt(EVT_HEADER_ITEMSWAP);
SEnumInt(EVT_HEADER_RELAYOUT);
SEnumInt(EVT_CB_SELCHANGE);
SEnumInt(EVT_CB_DROPDOWN);
SEnumInt(EVT_CALENDAR_SELDAY);
SEnumInt(EVT_CALENDAR_SETDATE);
SEnumInt(EVT_CALENDAREX_CHANGED);
SEnumInt(EVT_DATETIME_CHANGED);
SEnumInt(EVT_SPIN_VALUE2STRING);
SEnumInt(EVT_SPLIT_PANE_MOVED);
SEnumInt(EVT_HOT_KEY_SET);
SEnumInt(EVT_IMAGE_ANI_START);
SEnumInt(EVT_IMAGE_ANI_STOP);
SEnumInt(EVT_IMAGE_ANI_REPEAT);
SEnumInt(EVT_SELECTMENU);
SEnumInt(EVT_POPMENU);
SEnumInt(EVT_EXTERNAL_BEGIN);

SEnumUint64(STVI_ROOT);
SEnumUint64(STVI_FIRST);
SEnumUint64(STVI_LAST);

SEnumUint(TVC_COLLAPSE);
SEnumUint(TVC_EXPAND);
SEnumUint(TVC_TOGGLE);

SEnumUint(WndState_Normal);
SEnumUint(WndState_Hover);
SEnumUint(WndState_PushDown);
SEnumUint(WndState_Check);
SEnumUint(WndState_Invisible);
SEnumUint(WndState_Disable);

SEnumUint(kAniNone);
SEnumUint(kFadeInOut);
SEnumUint(kMoveInOut);
SEnumUint(kPushInOut);

//msgbox
SEnumUint(MB_OK);
SEnumUint(MB_OKCANCEL);
SEnumUint(MB_YESNO);
SEnumUint(MB_YESNOCANCEL);
SEnumUint(MB_RETRYCANCEL);
SEnumUint(MB_ICONWARNING);
SEnumUint(MB_ICONINFORMATION);
SEnumUint(MB_ICONQUESTION);
SEnumUint(MB_ICONSTOP);
SEnumUint(MB_ICONERROR);

SEnumUint(IDOK);
SEnumUint(IDCANCEL);
SEnumUint(IDABORT);
SEnumUint(IDRETRY);
SEnumUint(IDIGNORE);
SEnumUint(IDYES);
SEnumUint(IDNO);

//show window
SEnumUint(SW_SHOW);
SEnumUint(SW_HIDE);
SEnumUint(SW_SHOWDEFAULT);
SEnumUint(SW_SHOWNORMAL);
SEnumUint(SW_SHOWNOACTIVATE);
SEnumUint(SW_SHOWMAXIMIZED);
SEnumUint(SW_SHOWMINIMIZED);
SEnumUint(SW_RESTORE);
SEnumUint(SW_MAXIMIZE);
SEnumUint(SW_MINIMIZE);

//msg
SEnumUint(WM_INITDIALOG);
SEnumUint(WM_CREATE);
SEnumUint(WM_DESTROY);
SEnumUint(WM_CLOSE);
SEnumUint(WM_COMMAND);
SEnumUint(WM_SYSCOMMAND);


SEnumInt(SKEY_ROOT);
SEnumInt(SKEY_USER);
SEnumInt(SKEY_MACHINE);
SEnumInt(SKEY_USERS);

SEnumInt(REG_READ);
SEnumInt(REG_WRITE);

SEnumInt(MOUSE_LBTN_DOWN);
SEnumInt(MOUSE_LBTN_UP);
SEnumInt(MOUSE_LBTN_DBCLICK);
SEnumInt(MOUSE_RBTN_DOWN);
SEnumInt(MOUSE_RBTN_UP);
SEnumInt(MOUSE_RBTN_DBCLICK);
SEnumInt(MOUSE_MBTN_DOWN);
SEnumInt(MOUSE_MBTN_UP);
SEnumInt(MOUSE_MBTN_DBCLICK);

SEnumInt(MK_CONTROL);
SEnumInt(MK_LBUTTON);
SEnumInt(MK_RBUTTON);
SEnumInt(MK_MBUTTON);
SEnumInt(MK_SHIFT);

module->ExportEnumInt32("RepeatMode_Restart", RESTART);
module->ExportEnumInt32("RepeatMode_Reverse", REVERSE);

SEnumInt(GSW_FIRSTCHILD);
SEnumInt(GSW_LASTCHILD);
SEnumInt(GSW_PREVSIBLING);
SEnumInt(GSW_NEXTSIBLING);
SEnumInt(GSW_OWNER);
SEnumInt(GSW_PARENT);


SEnumInt(Ani_None);
SEnumInt(Ani_Int);
SEnumInt(Ani_Float);
SEnumInt(Ani_Color);
SEnumInt(Ani_Point);
SEnumInt(Ani_Size);
SEnumInt(Ani_Rect);
SEnumInt(Ani_Unknown);

SEnumInt(CP_UTF8);
SEnumInt(CP_ACP);
SEnumInt(CP_OEMCP);
SEnumInt(CP_MACCP);

SEnumInt(SBA_MOUSE_DOWN);
SEnumInt(SBA_MOUSE_MOVING);
SEnumInt(SBA_MOUSE_UP);

}