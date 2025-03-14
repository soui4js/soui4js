﻿/**
 * Copyright (C) 2014-2050
 * All rights reserved.
 *
 * @file       SWindowMgr.h
 * @brief
 * @version    v1.0
 * @author     SOUI group
 * @date       2014/08/02
 *
 * Describe    SOUI系统中的DUI窗口管理模块
 */

#ifndef __SWINDOWMGR__H__
#define __SWINDOWMGR__H__
#include <core/SSingletonMap.h>
#include <core/SDefine.h>
#include <helper/SCriticalSection.h>

SNSBEGIN

class SWindow;

class SOUI_EXP SWindowMgr : public SSingletonMap<SWindowMgr, SWindow *, SWND> {
    SINGLETON2_TYPE(SINGLETON_SWNDMGR)
  public:
    enum
    {
        SWND_INVALID = 0
    };

    SWindowMgr();

    ~SWindowMgr();

    // Get SWindow pointer from handle
    static SWindow *GetWindow(SWND swnd);

    static bool IsWindow(SWND swnd);

    // Specify a handle to a SWindow
    static SWND NewWindow(SWindow *pWnd);

    // Destroy SWindow
    static BOOL DestroyWindow(SWND swnd);

  protected:
    SCriticalSection m_lockWndMap;

    SWND m_hNextWnd;
};

SNSEND
#endif // __SWINDOWMGR__H__