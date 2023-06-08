﻿/**
 * Copyright (C) 2014-2050 SOUI团队
 * All rights reserved.
 *
 * @file       SSplitWnd.h
 * @brief
 * @version    v1.0
 * @author     soui
 * @date       2014-07-08
 *
 * Describe
 */
#pragma once
#include <core/swnd.h>
#include <layout/slayoutsize.h>

SNSBEGIN

/**
 * @class     SSplitPane
 * @brief     分割窗口
 *
 * Describe   分割窗口
 */
class SOUI_EXP SSplitPane : public SWindow {
    friend class SSplitWnd;
    DEF_SOBJECT(SWindow, L"pane")
  public:
    /**
     * SSplitPane::SSplitPane
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SSplitPane();

    /**
     * SSplitPane::~SSplitPane
     * @brief    析构函数
     *
     * Describe  析构函数
     */

    virtual ~SSplitPane()
    {
    }

    void Move(CRect rc);

    SOUI_ATTRS_BEGIN()
        ATTR_LAYOUTSIZE(L"idealSize", m_nSizeIdeal, FALSE)
        ATTR_LAYOUTSIZE(L"minSize", m_nSizeMin, FALSE)
        ATTR_LAYOUTSIZE(L"maxSize", m_nSizeMax, FALSE)
        ATTR_INT(L"priority", m_nPriority, FALSE)
    SOUI_ATTRS_END()

  protected:
    SLayoutSize m_nSizeIdeal; /**< 理想大小 */
    SLayoutSize m_nSizeMin;   /**< 最小大小 */
    SLayoutSize m_nSizeMax;   /**< 最大大小 */
    int m_nPriority;          /**< 优先级,值越大优先级越高,优先级越高，窗格越先到达idealSize  */
};

/**
 * @class     SSplitWnd
 * @brief     分割窗口
 *
 * Describe   分割窗口
 */
class SOUI_EXP SSplitWnd : public SWindow {
    DEF_SOBJECT(SWindow, L"splitwnd")

    enum SPLIT_ORINTATION
    {
        Horizontal = 0,
        Vertical,
    };
    //窗口的SIZE信息
    struct PANESIZE
    {
        int actural;
        int preferred;
        int minimum;
        int maximum;
    };
    typedef SArray<PANESIZE> PANESIZELIST;

  protected:
    typedef SArray<SSplitPane *> SplitPaneList;
    SplitPaneList m_lstPane;     /**< 按显示顺序排序的分隔列表 */
    SplitPaneList m_lstPriority; /**< 按优先级排序的分隔列表 */
    int m_spliterSize;           /**< 分隔条的size */
    int m_orintation;            /**< 分割方向，参考 SPLIT_ORINTATION */

    BOOL m_bAdjustable;               /**< 是否支持拖动调节窗格大小 */
    SAutoRefPtr<ISkinObj> m_pSkinSep; /**< ISkinObj对象 */

    CPoint m_ptDragPrev; /**< 拖动调整的前一个位置 */
    int m_iDragSep;      /**< 正在拖动哪一根分隔条,-1代表没有拖动状态 */

  public:
    /**
     * SSplitWnd::SSplitWnd
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SSplitWnd(void);

    /**
     * SSplitWnd::~SSplitWnd
     * @brief    析构函数
     *
     * Describe  析构函数
     */
    virtual ~SSplitWnd(void);

    SSplitPane *GetPane(UINT iPane);

    /**
     * SSplitWnd::ShowPane
     * @brief    显示pane
     * @param    UINT iPane -- pane index
     * @return   返回BOOL
     *
     * Describe  显示pane
     */
    BOOL ShowPane(UINT iPane);

    /**
     * SSplitWnd::HidePane
     * @brief    隐藏pane
     * @param    UINT iPane -- panel index
     * @return   返回BOOL
     *
     * Describe  隐藏pane
     */
    BOOL HidePane(UINT iPane);

    /**
     * SSplitWnd::PaneIndex
     * @brief    获得一个Pane的索引
     * @param    const SStringW & strName --  Pane的name
     * @return   int -- Pane的索引
     * Describe
     */
    int PaneIndex(const SStringW &strName) const;

    /**
     * SSplitWnd::InsertItem
     * @brief    插入一个新的窗格
     * @param    SSplitPane* pane --  窗格指针
     * @param    int index --  插入位置，默认最后
     * @return   int -- Pane的索引
     * Describe
     */
    int InsertItem(SSplitPane *pane, int index = -1);

    /**
     * SSplitWnd::RemoveItem
     * @brief    删除一个窗格
     * @param    SSplitPane* pane --  窗格指针
     * @return   void
     * Describe
     */
    void RemoveItem(SSplitPane *pane);

  protected:
    STDMETHOD_(void, GetChildrenLayoutRect)(THIS_ RECT* prc) SCONST OVERRIDE;

    /**
     * SSplitWnd::UpdateChildrenPosition
     * @brief    更新子窗口位置
     *
     * Describe  更新子窗口位置
     */
    STDMETHOD_(void, UpdateChildrenPosition)(THIS) OVERRIDE;

    /**
     * SSplitWnd::CreateChildren
     * @brief    创建panel
     * @param    SXmlNode xmlNode -- xml文件
     * @return   返回BOOL
     *
     * Describe  创建panel
     */
    virtual BOOL CreateChildren(SXmlNode xmlNode);

    /**
     * SSplitWnd::OnSetCursor
     * @brief    设置坐标
     * @param    const CPoint &pt -- 坐标
     * @return   返回BOOL
     *
     * Describe  设置坐标
     */
    virtual BOOL OnSetCursor(const CPoint &pt);

    /**
     * SSplitWnd::OnPaint
     * @brief    绘制
     * @param    IRenderTarget * pRT -- 绘制设备
     *
     * Describe  绘制
     */
    void OnPaint(IRenderTarget *pRT);

    /**
     * SSplitWnd::OnLButtonDown
     * @brief    左键按下事件
     * @param    UINT nFlags -- 标志
     * @param    CPoint point -- 鼠标坐标
     *
     * Describe  此函数是消息响应函数
     */
    void OnLButtonDown(UINT nFlags, CPoint pt);

    /**
     * SSplitWnd::OnLButtonUp
     * @brief    左键抬起事件
     * @param    UINT nFlags -- 标志
     * @param    CPoint point -- 鼠标坐标
     *
     * Describe  此函数是消息响应函数
     */
    void OnLButtonUp(UINT nFlags, CPoint pt);

    /**
     * SSplitWnd::OnMouseMove
     * @brief    鼠标移动事件
     * @param    UINT nFlags -- 标志
     * @param    CPoint point -- 鼠标坐标
     *
     * Describe  此函数是消息响应函数
     */
    void OnMouseMove(UINT nFlags, CPoint pt);

  protected:
    // qsort比较函数
    static int FunComp(const void *p1, const void *p2);

    //将一个SplitPaneList按照优先级从大到小排序
    void SortPriorityList(SplitPaneList &lstPane);

    //从SplitPaneList获取size信息
    void FatchPaneSizeInfo(const SplitPaneList &lstPane, PANESIZELIST &lstPaneSize);

    //根据计算获得的窗格size信息设置窗格位置
    int ResetPanesPostion(SplitPaneList &lstPane, SplitPaneList &lstPanePriority, PANESIZELIST &lstPaneSize, int offset);

    //调整列表中控件的高度（宽度）
    int AdjustPanesSize(PANESIZELIST &lstPriority, int remain);

    //重新布局
    void Relayout(const CRect &rc, PANESIZELIST lstPaneSize = PANESIZELIST());

  public:
    SOUI_ATTRS_BEGIN()
        ATTR_INT(L"sepSize", m_spliterSize, TRUE)
        ATTR_SKIN(L"sepSkin", m_pSkinSep, TRUE)
        ATTR_BOOL(L"adjustable", m_bAdjustable, TRUE)
        ATTR_INT(L"vertical", m_orintation, TRUE)
    SOUI_ATTRS_END()

    SOUI_MSG_MAP_BEGIN()
        MSG_WM_PAINT_EX(OnPaint)
        MSG_WM_LBUTTONDOWN(OnLButtonDown)
        MSG_WM_LBUTTONUP(OnLButtonUp)
        MSG_WM_MOUSEMOVE(OnMouseMove)
    SOUI_MSG_MAP_END()
};

/**
 * @class     SSplitWnd_Col
 * @brief     垂直分割窗口
 *
 * Describe   垂直分割窗口
 */
class SOUI_EXP SSplitWnd_Col : public SSplitWnd {
    DEF_SOBJECT(SSplitWnd, L"splitcol")
  public:
    SSplitWnd_Col()
    {
        m_pSkinSep = GETBUILTINSKIN(SKIN_SYS_SPLIT_VERT);
        m_orintation = Vertical;
    }
};

/**
 * @class     SSplitWnd_Row
 * @brief     横向分割窗口
 *
 * Describe   横向分割窗口
 */
class SOUI_EXP SSplitWnd_Row : public SSplitWnd {
    DEF_SOBJECT(SSplitWnd, L"splitrow")
  public:
    SSplitWnd_Row()
    {
        m_pSkinSep = GETBUILTINSKIN(SKIN_SYS_SPLIT_HORZ);
        m_orintation = Horizontal;
    }
};

SNSEND
