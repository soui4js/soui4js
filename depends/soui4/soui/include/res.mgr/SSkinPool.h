﻿/**
 * Copyright (C) 2014-2050 SOUI团队
 * All rights reserved.
 *
 * @file       SSkinPool.h
 * @brief      SkinObj Pool
 * @version    v1.0
 * @author     soui
 * @date       2014-05-28
 *
 * Describe    管理Skin Object
 */

#pragma once
#include <core/SSingletonMap.h>
#include <interface/Sskinobj-i.h>
#include <helper/obj-ref-impl.hpp>

SNSBEGIN
//系统内置皮肤名称
enum SYS_SKIN
{
    SKIN_SYS_CHECKBOX = 0,    // L"_skin.sys.checkbox",
    SKIN_SYS_RADIO,           // L"_skin.sys.radio",
    SKIN_SYS_FOCUSCHECKBOX,   // L"_skin.sys.focuscheckbox",
    SKIN_SYS_FOCUSRADIO,      // L"_skin.sys.focusradio",
    SKIN_SYS_BTN_NORMAL,      // L"_skin.sys.btn.normal",
    SKIN_SYS_SCROLLBAR,       // L"_skin.sys.scrollbar",
    SKIN_SYS_BORDER,          // L"_skin.sys.border",
    SKIN_SYS_DROPBTN,         // L"_skin.sys.dropbtn",
    SKIN_SYS_TREE_TOGGLE,     // L"_skin.sys.tree.toggle",
    SKIN_SYS_TREE_CHECKBOX,   // L"_skin.sys.tree.checkbox"
    SKIN_SYS_TREE_LINES,      // L"_skin.sys.tree.lines"
    SKIN_SYS_TAB_PAGE,        // L"_skin.sys.tab.page",
    SKIN_SYS_HEADER,          // L"_skin.sys.header"
    SKIN_SYS_SPLIT_VERT,      // L"_skin.sys.split.vert",
    SKIN_SYS_SPLIT_HORZ,      // L"_skin.sys.split.horz",
    SKIN_SYS_PROG_BKGND,      // L"_skin.sys.prog.bkgnd",
    SKIN_SYS_PROG_BAR,        // L"_skin.sys.prog.bar",
    SKIN_SYS_VERT_PROG_BKGND, // L"_skin.sys.vert.prog.bkgnd",
    SKIN_SYS_VERT_PROG_BAR,   // L"_skin.sys.vert.prog.bar",
    SKIN_SYS_SLIDER_THUMB,    // L"_skin.sys.slider.thumb",

    SKIN_SYS_BTN_CLOSE,    // L"_skin.sys.btn.close",
    SKIN_SYS_BTN_MINIMIZE, // L"_skin.sys.btn.minimize",
    SKIN_SYS_BTN_MAXMIZE,  // L"_skin.sys.btn.maxmize",
    SKIN_SYS_BTN_RESTORE,  // L"_skin.sys.btn.restore",

    SKIN_SYS_MENU_CHECK,  // L"_skin.sys.menu.check",
    SKIN_SYS_MENU_SEP,    // L"_skin.sys.menu.sep",
    SKIN_SYS_MENU_ARROW,  // L"_skin.sys.menu.arrow",
    SKIN_SYS_MENU_BORDER, // L"_skin.sys.menu.border",
    SKIN_SYS_MENU_SKIN,   // L"_skin.sys.menu.skin",
    SKIN_SYS_ICONS,       // L"_skin.sys.icons",
    SKIN_SYS_WND_BKGND,   // L"_skin.sys.wnd.bkgnd",

    SKIN_SYS_BTN_PREV,
    SKIN_SYS_BTN_NEXT,
    SKIN_SYS_SPIN_DOWN,
    SKIN_SYS_SPIN_UP,

    SKIN_SYS_COUNT,
};

typedef ISkinObj *SSkinPtr;

class SkinKey {
  public:
    SStringW strName;
    int scale;
};

template <>
class CElementTraits<SkinKey> : public CElementTraitsBase<SkinKey> {
  public:
    static ULONG Hash(INARGTYPE skinKey)
    {
        ULONG nHash = CElementTraits<SStringW>::Hash(skinKey.strName);

        nHash <<= 5;
        nHash += skinKey.scale;
        return (nHash);
    }

    static bool CompareElements(INARGTYPE element1, INARGTYPE element2)
    {
        return element1.strName == element2.strName && element1.scale == element2.scale;
    }

    static int CompareElementsOrdered(INARGTYPE element1, INARGTYPE element2)
    {
        int nRet = element1.strName.CompareNoCase(element2.strName);
        if (nRet == 0)
            nRet = element1.scale - element2.scale;
        return nRet;
    }
};

/**
 * @class      SSkinPool
 * @brief      name和ISkinObj的映射表
 *
 * Describe
 */
class SOUI_EXP SSkinPool
    : public SCmnMap<SSkinPtr, SkinKey>
    , public TObjRefImpl<IObjRef> {
  public:
    SSkinPool();

    virtual ~SSkinPool();

    /**
     * GetSkin
     * @brief    获得与指定name匹配的SkinObj
     * @param    LPCWSTR strSkinName --    Name of Skin Object
     * @return   ISkinObj*  -- 找到的Skin Object
     * Describe
     */
    ISkinObj *GetSkin(const SStringW &strSkinName, int nScale);

    /**
     * LoadSkins
     * @brief    从XML中加载Skin列表
     * @param    SXmlNode xmlNode --  描述SkinObj的XML表
     * @return   int -- 成功加载的SkinObj数量
     * Describe
     */
    int LoadSkins(SXmlNode xmlNode);

    /**
     * AddSkin
     * @brief    增加一个skinObj对象到SkinPool
     * @param    ISkinObj* --  SkinObj
     * @return   BOOL -- 加入是否成功,重名加入失败
     * Describe
     */
    BOOL AddSkin(ISkinObj *skin);

  protected:
    static void OnKeyRemoved(const SSkinPtr &obj);

#ifdef _DEBUG
    SMap<SkinKey, int> m_mapSkinUseCount; //皮肤使用计数
#endif
};


SNSEND