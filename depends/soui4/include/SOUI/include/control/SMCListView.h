﻿/**
 * Copyright (C) 2014-2050 SOUI团队
 * All rights reserved.
 *
 * @file       SMCListView.h
 * @brief
 * @version    v1.0
 * @author     soui
 * @date       2014-07-06
 *
 * Describe    ListCtrl控件
 */
#ifndef __SMCLISTVIEW__H__
#define __SMCLISTVIEW__H__
#include "core/SPanel.h"
#include "core/SItemPanel.h"
#include "SHeaderCtrl.h"

SNSBEGIN

//////////////////////////////////////////////////////////////////////////
//  SMCListView
class SOUI_EXP SMCListView
    : public TPanelProxy<IMcListView>
    , protected SHostProxy
    , protected IItemContainer {
    DEF_SOBJECT(SPanel, L"mclistview")
    friend class SMCListViewDataSetObserver;

  public:
    /**
     * SMCListView::SMCListView
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SMCListView();

    /**
     * SMCListView::~SMCListView
     * @brief    析构函数
     *
     * Describe  析构函数
     */
    virtual ~SMCListView();

  public:
    STDMETHOD_(BOOL, SetAdapter)(THIS_ IMcAdapter *adapter) OVERRIDE;

    STDMETHOD_(IMcAdapter *, GetAdapter)(THIS) SCONST OVERRIDE;

    STDMETHOD_(IListViewItemLocator *, GetItemLocator)(THIS) SCONST OVERRIDE;

    STDMETHOD_(void, SetItemLocator)(THIS_ IListViewItemLocator *pItemLocator) OVERRIDE;

    STDMETHOD_(void, EnsureVisible)(THIS_ int iItem) OVERRIDE;

    STDMETHOD_(void, SetSel)(THIS_ int iItem, BOOL bNotify = FALSE) OVERRIDE;

    STDMETHOD_(int, GetSel)(THIS) SCONST OVERRIDE;

    STDMETHOD_(IItemPanel *, HitTest)(THIS_ const POINT *pt) SCONST OVERRIDE;

    STDMETHOD_(IHeaderCtrl *, GetIHeaderCtrl)(THIS) SCONST OVERRIDE;

    STDMETHOD_(int, InsertColumn)
    (THIS_ int nIndex, LPCTSTR pszText, int nWidth, UINT fmt, LPARAM lParam = 0, BOOL bDpiAware = TRUE, float fWeight = 0.0f) OVERRIDE;

    STDMETHOD_(void, DeleteColumn)(THIS_ int iCol) OVERRIDE;

    STDMETHOD_(int, GetColumnCount)(THIS) SCONST OVERRIDE;

    STDMETHOD_(void, GetDesiredSize)(THIS_ SIZE *psz, int nParentWid, int nParentHei) OVERRIDE;

  public:
    SItemPanel *HitTest(CPoint &pt) const;

    SHeaderCtrl *GetHeaderCtrl() const;
    void UpdateVisibleItems();
    void UpdateVisibleItem(int iItem);

  protected:
    virtual void OnItemSetCapture(SOsrPanel *pItem, BOOL bCapture);
    virtual BOOL OnItemGetRect(const SOsrPanel *pItem, CRect &rcItem) const;
    virtual BOOL IsItemRedrawDelay() const;

  protected:
    void onDataSetChanged();
    void onDataSetInvalidated();
    void onItemDataChanged(int iItem);

  protected:
    BOOL OnItemClick(IEvtArgs *pEvt);

  protected:
    virtual BOOL OnScroll(BOOL bVertical, UINT uCode, int nPos);
    virtual int GetScrollLineSize(BOOL bVertical);
    virtual BOOL CreateChildren(SXmlNode xmlNode);

    virtual BOOL UpdateToolTip(CPoint pt, SwndToolTipInfo &tipInfo);
    virtual UINT WINAPI OnGetDlgCode() const;
    virtual BOOL OnSetCursor(const CPoint &pt);
    virtual void OnColorize(COLORREF cr);
    virtual void OnScaleChanged(int nScale);
    virtual HRESULT OnLanguageChanged();
    virtual void OnRebuildFont();

  protected:
    void DispatchMessage2Items(UINT uMsg, WPARAM wParam, LPARAM lParam);

    void UpdateScrollBar();
    void RedrawItem(SOsrPanel *pItem);
    SItemPanel *GetItemPanel(int iItem);

    void OnPaint(IRenderTarget *pRT);
    void OnSize(UINT nType, CSize size);
    void OnDestroy();

    LRESULT OnMouseEvent(UINT uMsg, WPARAM wParam, LPARAM lParam);

    LRESULT OnKeyEvent(UINT uMsg, WPARAM wParam, LPARAM lParam);
    void OnKeyDown(TCHAR nChar, UINT nRepCnt, UINT nFlags);

    void OnMouseLeave();

    BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
    void OnKillFocus(SWND wndFocus);
    void OnSetFocus(SWND wndOld);
    void OnShowWindow(BOOL bShow, UINT nStatus);

    SOUI_MSG_MAP_BEGIN()
        MSG_WM_PAINT_EX(OnPaint)
        MSG_WM_SIZE(OnSize)
        MSG_WM_DESTROY(OnDestroy)
        MSG_WM_MOUSEWHEEL(OnMouseWheel)
        MSG_WM_MOUSELEAVE(OnMouseLeave)
        MSG_WM_KEYDOWN(OnKeyDown)
        MSG_WM_SETFOCUS_EX(OnSetFocus)
        MSG_WM_KILLFOCUS_EX(OnKillFocus)
        MSG_WM_SHOWWINDOW(OnShowWindow)
        MESSAGE_RANGE_HANDLER_EX(WM_MOUSEFIRST, WM_MOUSELAST, OnMouseEvent)
        MESSAGE_RANGE_HANDLER_EX(WM_KEYFIRST, WM_KEYLAST, OnKeyEvent)
        MESSAGE_RANGE_HANDLER_EX(WM_IME_STARTCOMPOSITION, WM_IME_KEYLAST, OnKeyEvent)
        MESSAGE_HANDLER_EX(WM_IME_CHAR, OnKeyEvent)
        MESSAGE_HANDLER_EX(WM_IME_REQUEST, OnKeyEvent)
    SOUI_MSG_MAP_END()

    SOUI_ATTRS_BEGIN()
        ATTR_LAYOUTSIZE(L"headerHeight", m_nHeaderHeight, FALSE)
        ATTR_INT(L"hotTrack", m_bHotTrack, FALSE)
        ATTR_SKIN(L"dividerSkin", m_pSkinDivider, TRUE)
        ATTR_LAYOUTSIZE(L"dividerSize", m_nDividerSize, FALSE)
        ATTR_INT(L"wantTab", m_bWantTab, FALSE)
        ATTR_COLOR(L"colorGrid", m_crGrid, TRUE)
    SOUI_ATTRS_END()
  protected:
    SAutoRefPtr<IMcAdapter> m_adapter;
    SAutoRefPtr<ILvDataSetObserver> m_observer;
    SAutoRefPtr<IListViewItemLocator> m_lvItemLocator; //列表项定位接口
    struct ItemInfo
    {
        SItemPanel *pItem;
        int nType;
    };

    bool m_bPendingUpdate;    // response for data set changed in OnShowWindow.
    int m_iPendingUpdateItem; //-1 for all. -2 for nothing
    int m_iPendingViewItem;   //-1 for init

    int m_iFirstVisible;        //第一个显示项索引
    SList<ItemInfo> m_lstItems; //当前正在显示的项
    SOsrPanel *m_itemCapture;   // The item panel that has been set capture.

    int m_iSelItem;
    SOsrPanel *m_pHoverItem;

    SArray<SList<SItemPanel *> *> m_itemRecycle; // item回收站,每一种样式在回收站中保持一个列表，以便重复利用

    SXmlDoc m_xmlTemplate;
    SAutoRefPtr<ISkinObj> m_pSkinDivider;
    SLayoutSize m_nDividerSize;
    BOOL m_bWantTab;
    BOOL m_bDatasetInvalidated;
    COLORREF m_crGrid;

  protected:
    /**
     * SMCListView::OnHeaderClick
     * @brief    列表头单击事件 --
     * @param    EventArgs *pEvt
     *
     * Describe  列表头单击事件
     */
    BOOL OnHeaderClick(IEvtArgs *pEvt);
    /**
     * SMCListView::OnHeaderSizeChanging
     * @brief    列表头大小改变
     * @param    EventArgs *pEvt --
     *
     * Describe  列表头大小改变
     */
    BOOL OnHeaderSizeChanging(IEvtArgs *pEvt);
    /**
     * SMCListView::OnHeaderSwap
     * @brief    列表头交换
     * @param    EventArgs *pEvt --
     *
     * Describe  列表头交换
     */
    BOOL OnHeaderSwap(IEvtArgs *pEvt);

    /**
     * SMCListView::GetListRect
     * @brief    获取list位置
     * @return   返回CRect
     *
     * Describe  获取list位置
     */
    CRect GetListRect();

    /**
     * SMCListView::UpdateHeaderCtrl
     * @brief    更新列表头控件
     *
     * Describe  更新列表头控件
     */
    void UpdateHeaderCtrl();
    STDMETHOD_(void, UpdateChildrenPosition)(THIS) OVERRIDE;

    int GetHeaderHeight() const;

  protected:
    CRect _OnItemGetRect(int iPosition) const;
    void _UpdateAdapterColumnsWidth() const;

  protected:
    SHeaderCtrl *m_pHeader;
    SLayoutSize m_nHeaderHeight; /**< 列表头高度 */
    BOOL m_bHotTrack;            /**<  */
};

SNSEND

#endif // __SMCLISTVIEW__H__