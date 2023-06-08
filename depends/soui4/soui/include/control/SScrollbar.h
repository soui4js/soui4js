﻿/**
 * Copyright (C) 2014-2050 SOUI团队
 * All rights reserved.
 *
 * @file       SScrollBar.h
 * @brief
 * @version    v1.0
 * @author     soui
 * @date       2014-07-08
 *
 * Describe
 */
#pragma once
#include <core/SWnd.h>
#include <core/SScrollBarHandler.h>

SNSBEGIN

/**
 * @class     SScrollBar
 * @brief     滚动条
 *
 * Describe   滚动条
 */
class SOUI_EXP SScrollBar
    : public SWindow
    , protected IScrollBarHost {
    DEF_SOBJECT(SWindow, L"scrollbar")
  public:
    /**
     * SScrollBar::SScrollBar
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SScrollBar();
    /**
     * SScrollBar::~SScrollBar
     * @brief    析构函数
     *
     * Describe  析构函数
     */
    virtual ~SScrollBar();

  public:
    /**
     * SScrollBar::IsVertical
     * @brief    是否是竖直
     * @return   返回BOOL
     *
     * Describe  是否是竖直
     */
    BOOL IsVertical() const;

    /**
     * SScrollBar::SetPos
     * @brief    设置位置
     *
     * Describe  设置位置
     */
    int SetPos(int nPos);

    /**
     * SScrollBar::GetPos
     * @brief    获取位置
     *
     * Describe  获取位置
     */
    int GetPos();

    /**
     * SScrollBar::GetMax
     * @brief    获取最大值
     *
     * Describe  获取最大值
     */
    int GetMax();

    /**
     * SScrollBar::GetMax
     * @brief    获取最小值
     *
     * Describe  获取最小值
     */
    int GetMin();

  protected:
	  STDMETHOD_(CRect, GetScrollBarRect)(CTHIS_ BOOL bVert) SCONST OVERRIDE;
	  STDMETHOD_(ISkinObj*,GetScrollBarSkin)(CTHIS_ BOOL bVert) SCONST OVERRIDE;
	  STDMETHOD_(const SCROLLINFO *,GetScrollBarInfo)(CTHIS_ BOOL bVert) SCONST OVERRIDE;
	  STDMETHOD_(int,GetScrollBarArrowSize)(CTHIS_ BOOL bVert) SCONST OVERRIDE;
	  STDMETHOD_(void,OnScrollUpdatePart)(THIS_ BOOL bVert, int iPart) OVERRIDE;
	  STDMETHOD_(void,OnScrollUpdateThumbTrack)(THIS_ BOOL bVert, int nPos) OVERRIDE;
	  STDMETHOD_(ISwndContainer*, GetScrollBarContainer)(THIS) OVERRIDE;
	  STDMETHOD_(BOOL, IsScrollBarEnable)(THIS_ BOOL bVertical) SCONST OVERRIDE;
	  STDMETHOD_(void,OnScrollCommand)(THIS_ BOOL bVert, int iCmd, int nPos) OVERRIDE;
	  STDMETHOD_(void,OnScrollSetTimer)(THIS_ BOOL bVert, char id, UINT uElapse) OVERRIDE;
	  STDMETHOD_(void,OnScrollKillTimer)(THIS_ BOOL bVert, char id) OVERRIDE;
	  STDMETHOD_(const IInterpolator *,GetScrollInterpolator)(CTHIS) SCONST OVERRIDE;
	  STDMETHOD_(int,GetScrollFadeFrames)(CTHIS) SCONST OVERRIDE;
	  STDMETHOD_(BYTE,GetScrollThumbTrackMinAlpha)(CTHIS) SCONST OVERRIDE;

  protected:
    /**
     * SScrollBar::OnInitFinished
     * @brief    初始化
     * @param    SXmlNode xmlNode  -- 初始化
     *
     * Describe  初始化
     */
    virtual void WINAPI OnInitFinished(IXmlNode *pNode);

    /**
     * SScrollBar::NotifySbCode
     * @brief    通知
     * @param    UINT uCode  -- 消息码
     * @param    int nPos  -- 坐标
     *
     * Describe  自定义消息响应函数
     */
    void NotifySbCode(int nCode, int nPos);

  protected:
    HRESULT OnAttrVertical(const SStringW &value, BOOL bLoading);

    SOUI_ATTRS_BEGIN()
        ATTR_SKIN(L"skin", m_pSkin, TRUE)
        ATTR_UINT(L"arrowSize", m_uAllowSize, TRUE)
        ATTR_INT(L"min", m_si.nMin, TRUE)
        ATTR_INT(L"max", m_si.nMax, TRUE)
        ATTR_INT(L"value", m_si.nPos, TRUE)
        ATTR_INT(L"page", m_si.nPage, TRUE)
        ATTR_CUSTOM(L"vertical", OnAttrVertical)
        ATTR_INT(L"fadeFrames", m_fadeFrames, FALSE)
        ATTR_INT(L"thumbTrackMinAlpha", m_byThumbTrackMinAlpha, FALSE)
        ATTR_INTERPOLATOR(L"fadeInterpolator", m_fadeInterpolator, FALSE)
        ATTR_CHAIN_PTR(m_fadeInterpolator, 0)
    SOUI_ATTRS_END()

  protected:
    /**
     * SScrollBar::OnPaint
     * @brief    绘制
     * @param    IRenderTarget * pRT  -- 绘画设备
     *
     * Describe  绘制
     */
    void OnPaint(IRenderTarget *pRT);

    /**
     * SScrollBar::OnLButtonUp
     * @brief    左键抬起
     * @param    UINT nFlags --  虚拟键标志
     * @param    CPoint point -- 坐标
     *
     * Describe  消息响应函数
     */
    void OnLButtonUp(UINT nFlags, CPoint point);

    /**
     * SScrollBar::OnLButtonDown
     * @brief    左键按下
     * @param    UINT nFlags --  虚拟键标志
     * @param    CPoint point -- 坐标
     *
     * Describe  消息响应函数
     */
    void OnLButtonDown(UINT nFlags, CPoint point);

    /**
     * SScrollBar::OnMouseMove
     * @brief    鼠标移动
     * @param    UINT nFlags --  虚拟键标志
     * @param    CPoint point -- 坐标
     *
     * Describe  消息响应函数
     */
    void OnMouseMove(UINT nFlags, CPoint point);

    /**
     * SScrollBar::OnTimer
     * @brief    定时器
     * @param    char nIDEvent  -- 定时器ID
     *
     * Describe  定时器ID
     */
    void OnTimer(char nIDEvent);

    /**
     * SScrollBar::OnMouseHover
     * @param    UINT nFlags --  虚拟键标志
     * @param    CPoint point -- 坐标
     * @brief    鼠标进入事件
     *
     * Describe  消息响应函数
     */
    void OnMouseHover(UINT nFlags, CPoint ptPos);

    /**
     * SScrollBar::OnMouseLeave
     * @brief    鼠标移动事件
     *
     * Describe  消息响应函数
     */
    void OnMouseLeave();

    /**
     * SScrollBar::OnSetScrollInfo
     * @brief    设置滚动条信息
     * @param    UINT uMsg  -- 消息码
     * @param    WPARAM wParam
     * @param    LPARAM lParam
     *
     * Describe  消息响应函数
     */
    LRESULT OnSetScrollInfo(UINT uMsg, WPARAM wParam, LPARAM lParam);

    /**
     * SScrollBar::OnGetScrollInfo
     * @brief    获取滚动条信息
     * @param    UINT uMsg  -- 消息码
     * @param    WPARAM wParam
     * @param    LPARAM lParam
     *
     * Describe  自定义消息响应函数
     */
    LRESULT OnGetScrollInfo(UINT uMsg, WPARAM wParam, LPARAM lParam);

    void OnDestroy();

    SOUI_MSG_MAP_BEGIN()
        MSG_WM_LBUTTONDOWN(OnLButtonDown)
        MSG_WM_LBUTTONDBLCLK(OnLButtonDown)
        MSG_WM_LBUTTONUP(OnLButtonUp)
        MSG_WM_MOUSEMOVE(OnMouseMove)
        MSG_WM_MOUSELEAVE(OnMouseLeave)
        MSG_WM_MOUSEHOVER(OnMouseHover)
        MSG_WM_TIMER_EX(OnTimer)
        MSG_WM_PAINT_EX(OnPaint)
        MSG_WM_DESTROY(OnDestroy)
        MESSAGE_HANDLER_EX(SBM_SETSCROLLINFO, OnSetScrollInfo)
        MESSAGE_HANDLER_EX(SBM_GETSCROLLINFO, OnGetScrollInfo)
    SOUI_MSG_MAP_END()

  protected:
    SAutoRefPtr<ISkinObj> m_pSkin; /**< 皮肤对象 */
    UINT m_uAllowSize;             /**< 大小 */

    SCROLLINFO m_si; /**< 结构体 */

    int m_fadeFrames;
    mutable SAutoRefPtr<IInterpolator> m_fadeInterpolator;
    BYTE m_byThumbTrackMinAlpha;
    SScrollBarHandler m_sbHandler;
};

SNSEND
