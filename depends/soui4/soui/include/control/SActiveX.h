﻿#pragma once
#include "core/SWnd.h"
#include "activex/flash10t.tlh"
#include <mshtmhst.h>

SNSBEGIN

class SOUI_EXP SActiveX : public SWindow {
    friend class SAxContainerImpl;

  public:
    DEF_SOBJECT(SWindow, L"activex")
    explicit SActiveX();
    virtual ~SActiveX();

    IUnknown *GetIUnknown();

  protected:
    virtual void OnAxActivate(IUnknown *pUnknwn)
    {
    }

    int OnCreate(LPVOID);
    void OnSize(UINT nType, CSize size);
    void OnPaint(IRenderTarget *pRT);
    LRESULT OnMouseEvent(UINT uMsg, WPARAM wp, LPARAM lp);
    LRESULT OnKeyEvent(UINT uMsg, WPARAM wp, LPARAM lp);
    void OnShowWindow(BOOL bShow, UINT nStatus);

    virtual UINT WINAPI OnGetDlgCode() const OVERRIDE
    {
        return SC_WANTALLKEYS;
    }

    virtual BOOL WINAPI IsFocusable() const OVERRIDE
    {
        return TRUE;
    }

    HRESULT OnAttrClsid(const SStringW &strValue, BOOL bLoading);
    SOUI_MSG_MAP_BEGIN()
        MSG_WM_PAINT_EX(OnPaint)
        MESSAGE_RANGE_HANDLER_EX(WM_MOUSEFIRST, WM_MOUSELAST, OnMouseEvent)
        MESSAGE_RANGE_HANDLER_EX(WM_KEYFIRST, WM_KEYLAST, OnKeyEvent)
        MSG_WM_CREATE(OnCreate)
        MSG_WM_SIZE(OnSize)
        MSG_WM_SHOWWINDOW(OnShowWindow)
    SOUI_MSG_MAP_END()

    SOUI_ATTRS_BEGIN()
        ATTR_CUSTOM(L"clsID", OnAttrClsid)
        ATTR_DWORD(L"clsCtx", m_clsCtx, FALSE)
        ATTR_UINT(L"delay", m_bDelayInit, FALSE)
    SOUI_ATTRS_END()

    virtual void OnInitActiveXFinished()
    {
    }

    BOOL InitActiveX();
    void SetActiveXVisible(BOOL bVisible);
    void SetExternalUIHandler(IDocHostUIHandler *pUiHandler);

  protected:
    SAxContainerImpl *m_axContainer;
    CLSID m_clsid;
    DWORD m_clsCtx;
    BOOL m_bDelayInit;
};

class SOUI_EXP SFlashCtrl : public SActiveX {
  public:
    DEF_SOBJECT(SActiveX, L"flash")
    SFlashCtrl();

    ShockwaveFlashObjects::IShockwaveFlash *GetFlashInterface() const
    {
        return flash_;
    }

    BOOL Play(LPCWSTR pszUrl);

  protected:
    virtual void OnAxActivate(IUnknown *pUnknwn);

    HRESULT OnAttrUrl(const SStringW &strValue, BOOL bLoading);

    SOUI_ATTRS_BEGIN()
        ATTR_CUSTOM(L"url", OnAttrUrl)
    SOUI_ATTRS_END()

    SStringW m_strUrl;

    SComQIPtr<ShockwaveFlashObjects::IShockwaveFlash> flash_;
};

SNSEND
