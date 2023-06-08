﻿/**
 * Copyright (C) 2014-2050 SOUI团队
 * All rights reserved.
 *
 * @file       SSliderBar.h
 * @brief
 * @version    v1.0
 * @author     soui
 * @date       2014-07-08
 *
 * Describe
 */
#pragma once
#include "SCmnCtrl.h"

SNSBEGIN
/**
 * @class     SSliderBar
 * @brief     滑块工具条
 *
 * Describe   滑块工具条
 */
class SOUI_EXP SSliderBar : public SProgress {
    DEF_SOBJECT(SProgress, L"sliderbar")

    struct RANGE
    {
        int value1;
        int value2;
    };

  public:
    /**
     * SSliderBar::SSliderBar
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SSliderBar();

    /**
     * SSliderBar::~SSliderBar
     * @brief    析构函数
     *
     * Describe  析构函数
     */
    ~SSliderBar();

    enum
    {
        SC_RAIL,
        SC_SELECT,
        SC_THUMB,
        SC_RAILBACK,
    };

  protected:
    /**
     * SSliderBar::HitTest
     * @brief    测试点
     * @param    CPoint pt  --  坐标
     *
     * Describe  测试某个点是否在滚动条上
     */
    int HitTest(CPoint pt);

  protected:
    BOOL m_bDrag;     /**< 是否允许拖动 */
    CPoint m_ptDrag;  /**< 拖动位置     */
    int m_nDragValue; /**< 拖动距离 */
    int m_uHtPrev;    /**< 上次的鼠标位置 */

    SAutoRefPtr<ISkinObj> m_pSkinThumb; /**< 皮肤对象 */
    BOOL m_bThumbInRail;                /**< 滑块包含在轨道中 */
  protected:
    /**
     * SSliderBar::NotifyPos
     * @brief    通知
     * @param    UINT uCode  -- 消息码
     * @param    int nPos  -- 坐标
     *
     * Describe  自定义消息响应函数
     */
    LRESULT NotifyPos(UINT uCode, int nPos);

    /**
     * SSliderBar::GetDesiredSize
     * @brief    获取大小
     * @param    int wid -- 容器宽度
     * @param    int hei -- 容器高度
     * @return   返回CSize
     *
     * Describe  获取大小
     */
    STDMETHOD_(SIZE, GetDesiredSize)(THIS_ int nParentWid, int nParentHei);

    virtual void OnColorize(COLORREF cr);

    virtual void OnScaleChanged(int scale);

    /**
     * SSliderBar::GetPartRect
     * @brief
     * @param    UINT uSBCode
     *
     * Describe
     */
    CRect GetPartRect(UINT uSBCode);

    RANGE _GetPartRange(int nLength, int nThumbSize, BOOL bThumbInRail, int nMin, int nMax, int nValue, UINT uSBCode);

    /**
     * SSliderBar::OnPaint
     * @brief    绘制
     * @param    IRenderTarget * pRT  -- 绘画设备
     *
     * Describe  绘制
     */
    void OnPaint(IRenderTarget *pRT);

    /**
     * SSliderBar::OnLButtonUp
     * @brief    左键抬起
     * @param    UINT nFlags --  虚拟键标志
     * @param    CPoint point -- 坐标
     *
     * Describe  消息响应函数
     */
    void OnLButtonUp(UINT nFlags, CPoint point);

    /**
     * SSliderBar::OnLButtonDown
     * @brief    左键按下
     * @param    UINT nFlags --  虚拟键标志
     * @param    CPoint point -- 坐标
     *
     * Describe  消息响应函数
     */
    void OnLButtonDown(UINT nFlags, CPoint point);

    /**
     * SSliderBar::OnMouseMove
     * @brief    鼠标移动
     * @param    UINT nFlags --  虚拟键标志
     * @param    CPoint point -- 坐标
     *
     * Describe  消息响应函数
     */
    void OnMouseMove(UINT nFlags, CPoint point);

    /**
     * SSliderBar::OnMouseLeave
     * @brief    鼠标移动事件
     *
     * Describe  消息响应函数
     */
    void OnMouseLeave();

    SOUI_MSG_MAP_BEGIN()
        MSG_WM_LBUTTONDOWN(OnLButtonDown)
        MSG_WM_LBUTTONUP(OnLButtonUp)
        MSG_WM_MOUSEMOVE(OnMouseMove)
        MSG_WM_MOUSELEAVE(OnMouseLeave)
        MSG_WM_PAINT_EX(OnPaint)
    SOUI_MSG_MAP_END()

    SOUI_ATTRS_BEGIN()
        ATTR_SKIN(L"thumbSkin", m_pSkinThumb, TRUE)
        ATTR_BOOL(L"thumbInRail", m_bThumbInRail, TRUE)
    SOUI_ATTRS_END()
};

SNSEND
