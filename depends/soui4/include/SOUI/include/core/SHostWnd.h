﻿//////////////////////////////////////////////////////////////////////////
//  Class Name: SHostWnd
//    Description: Real Container of SWindow
//////////////////////////////////////////////////////////////////////////

#ifndef __SHOSTWND__H__
#define __SHOSTWND__H__

#include <core/SWndContainerImpl.h>
#include <core/SNativeWnd.h>
#include <core/SDropTargetDispatcher.h>
#include <event/SEventCrack.h>
#include <interface/stooltip-i.h>
#include <interface/shostwnd-i.h>
#include <interface/SHostPresenter-i.h>
#include <core/SCaret.h>
#include <core/SNcPainter.h>
#include <layout/SLayoutSize.h>
#include <helper/SplitString.h>
#include <helper/swndspy.h>
#include <helper/STimerGenerator.h>
#include <proxy/SNativeWndProxy.h>
SNSBEGIN

// disable swnd spy for release by default.
#ifndef DISABLE_SWNDSPY
#ifndef _DEBUG
#define DISABLE_SWNDSPY 1
#else
#define DISABLE_SWNDSPY 0
#endif
#endif

class SOUI_EXP SHostWndAttr : public TObjRefImpl<SObject> {
    DEF_SOBJECT(TObjRefImpl<SObject>, L"SHostWndAttr")
    enum WndType
    {
        WT_UNDEFINE = 0,
        WT_APPMAIN = 1,
        WT_NORMAL = 2
    };
    friend class SHostWnd;
    friend class SRootWindow;
    friend class SNcPainter;
    friend class SHostPresenter;

  public:
    SHostWndAttr(void);

    ~SHostWndAttr();

    void Init();

    virtual LPCWSTR GetTrCtx() const;

    CRect GetMaxInset(int nScale) const;

    CRect GetMargin(int nScale) const;

    CSize GetMinSize(int nScale) const;

    void SetTranslucent(bool bTranslucent);

    void SetTrCtx(const SStringW &strTrCtx);

    void SetSendWheel2Hover(bool value);

    SOUI_ATTRS_BEGIN()
        ATTR_STRINGW(L"trCtx", m_strTrCtx, FALSE)
        ATTR_STRINGW(L"title", m_strTitle, FALSE)
        ATTR_LAYOUTSIZE4(L"maxInset", m_rcMaxInset, FALSE)
        ATTR_LAYOUTSIZE4(L"margin", m_rcMargin, FALSE)
        ATTR_LAYOUTSIZE2(L"minsize", m_szMin, FALSE)
        ATTR_DWORD(L"wndStyle", m_dwStyle, FALSE)
        ATTR_DWORD(L"wndStyleEx", m_dwExStyle, FALSE)
        ATTR_BOOL(L"resizable", m_bResizable, FALSE)
        ATTR_BOOL(L"translucent", m_bTranslucent, FALSE)
        ATTR_BOOL(L"autoShape", m_bAutoShape, FALSE)
        ATTR_BOOL(L"sendWheel2Hover", m_bSendWheel2Hover, FALSE)
        ATTR_BOOL(L"appWnd", m_bAppWnd, FALSE)
        ATTR_BOOL(L"toolWindow", m_bToolWnd, FALSE)
        ATTR_ICON(L"smallIcon", m_hAppIconSmall, FALSE)
        ATTR_ICON(L"bigIcon", m_hAppIconBig, FALSE)
        ATTR_BOOL(L"allowSpy", m_bAllowSpy, FALSE)
        ATTR_BOOL(L"hasMsgLoop", m_bHasMsgLoop, FALSE)
        ATTR_ENUM_BEGIN(L"wndType", WndType, FALSE)
            ATTR_ENUM_VALUE(L"undefine", WT_UNDEFINE)
            ATTR_ENUM_VALUE(L"appMain", WT_APPMAIN)
            ATTR_ENUM_VALUE(L"normal", WT_NORMAL)
        ATTR_ENUM_END(m_wndType)
    SOUI_ATTRS_END()

  protected:
    SLayoutSize m_rcMargin[4];   //窗口拉伸的边缘检测大小
    SLayoutSize m_szMin[2];      //窗口最小值
    SLayoutSize m_rcMaxInset[4]; //窗口最大化时超出屏幕的边缘大小。经测试，WS_OVERLAPPED
                                 // style的窗口该属性无效

    WndType m_wndType;       // 主窗口标志,有该标志的窗口关闭时自动发送WM_QUIT
    BOOL m_bResizable;       //窗口大小可调节
    BOOL m_bAppWnd;          // APP窗口，在任务栏上显示按钮
    BOOL m_bToolWnd;         // 设置WS_ES_TOOLWINDOW属性
    BOOL m_bTranslucent;     // 窗口的半透明属性
    BOOL m_bAutoShape;       // auto build shape for translucent window (valid for linux)
    BOOL m_bAllowSpy;        // 允许spy
    BOOL m_bSendWheel2Hover; // 将滚轮消息发送到hover窗口
    BOOL m_bHasMsgLoop;      // 窗口有的MsgLoop标志，主要影响tooltip的RelayEvent时机
    DWORD m_dwStyle;
    DWORD m_dwExStyle;

    SStringW m_strTrCtx; //在语言翻译时作为context使用
    SStringW m_strTitle;
    HICON m_hAppIconSmall;
    HICON m_hAppIconBig;
};

class SOUI_EXP SRootWindow : public SWindow {
    DEF_SOBJECT(SWindow, L"root")
    friend class SHostWnd;

  public:
    SRootWindow(SHostWnd *pHostWnd);

  public:
    SHostWnd *GetHostWnd() const;

    void FireMenuCmd(int menuID);

  public:
    STDMETHOD_(void, UpdateLayout)(THIS) OVERRIDE;

  protected:
    STDMETHOD_(void, OnAnimationStop)(THIS_ IAnimation *pAni) OVERRIDE;

    virtual void OnAnimationInvalidate(IAnimation *pAni, bool bErase);

  protected: // Swindow 虚方法
    virtual void BeforePaint(IRenderTarget *pRT, SPainter &painter);
    virtual void AfterPaint(IRenderTarget *pRT, SPainter &painter);
    virtual BOOL IsLayeredWindow() const
    {
        return FALSE;
    }
    virtual HRESULT OnLanguageChanged();
    virtual void OnScaleChanged(int scale);
    virtual void RequestRelayout(SWND hSource, BOOL bSourceResizable);

  public:
    SOUI_ATTRS_BEGIN()
        ATTR_ANIMATION(L"enterAnimation", m_aniEnter, FALSE)
        ATTR_ANIMATION(L"exitAnimation", m_aniExit, FALSE)
    SOUI_ATTRS_END()
  protected:
    SAutoRefPtr<IAnimation> m_aniEnter, m_aniExit;
    SHostWnd *m_pHostWnd;
};

class SDummyWnd;
class SOUI_EXP SHostWnd
    : public TNativeWndProxy<IHostWnd>
    , public SwndContainerImpl {
    friend class SDummyWnd;
    friend class SRootWindow;
    friend class SNcPainter;

  protected:
    SDummyWnd *m_dummyWnd;   /**<半透明窗口使用的一个响应WM_PAINT消息的窗口*/
    SHostWndAttr m_hostAttr; /**<host属性，对应XML中的SOUI结点 */
    SStringT m_strXmlLayout; /**<布局资源名称,如xml:main_wnd */

    BOOL m_bTrackFlag; /**< 跟踪鼠标标志 */

    BOOL m_bNeedRepaint;    /**<缓存脏标志*/
    BOOL m_bNeedAllRepaint; /**<缓存全部更新标志*/

    IToolTip *m_pTipCtrl; /**<tip接口*/

    SAutoRefPtr<IRegionS> m_rgnInvalidate;      /**<脏区域*/
    SAutoRefPtr<IRenderTarget> m_memRT;         /**<绘制缓存*/
    SAutoRefPtr<IUiDefInfo> m_privateUiDefInfo; /** 局部uidefinfo*/
    int m_cEnableUiDefCount;                    /** 局部uidefinfo enable count*/
    SAutoRefPtr<IScriptModule> m_pScriptModule; /**<脚本模块*/
    SAutoRefPtr<SNcPainter> m_pNcPainter;       /**<非客户区绘制模块*/

    MSG m_msgMouse; /**<上一次鼠标按下消息*/

    CSize m_szAppSetted; /**<应用层设置的窗口大小 */
    CSize m_szPrev;
    int m_nAutoSizing; /**<自动计算大小触发的WM_SIZE消息 */
    bool m_bResizing;  /**<执行WM_SIZE*/

    SAutoRefPtr<IAnimation> m_hostAnimation;
    DWORD m_AniState;
    BOOL m_bFirstShow;
    tid_t m_dwThreadID;
    SRootWindow *m_pRoot;

    EventHandlerInfo m_evtHandler;
    SAutoRefPtr<IHostPresenter> m_presenter;

    //几个异步任务相关的对象，由于msgloop的异步任务依赖msgloop，在dll中使用soui可能没有soui自己的msgloop
    SCriticalSection m_cs;
    SList<IRunnable *> m_runnables;
    SCriticalSection m_csRunningQueue;
    SList<IRunnable *> m_runningQueue;
    IXmlNode *m_xmlInit;
    static BOOL s_HideLocalUiDef;  /**<隐藏局部uidef对象全局标志  */
    static int s_TaskQueueBufSize; /**<异步任务等待长度,默认为5  */
  public:
    SHostWnd(LPCWSTR pszResName = NULL);
    SHostWnd(LPCSTR pszResName);
    virtual ~SHostWnd();

    /************************************************************************/
    /*用来设置是否隐藏窗口的局部布局属性，整个程序只应在窗口初始化前调用一次*/
    /************************************************************************/
    static void SetHideLocalUiDef(BOOL bHide);
    static void SetTaskQueueBufSize(int nBufSize);

  public:
    enum
    {
        kPulseTimer = 4321, // soui timer. don't use it in app
        kPulseInterval = 10,
        kNcCheckTimer = 4322,
        kNcCheckInterval = 50,
        kTaskTimer = 4323,
        kTaskInterval = 100,
    };

  public:
    STDMETHOD_(BOOL, InitFromXml)(THIS_ IXmlNode *pNode) OVERRIDE;

    STDMETHOD_(BOOL, DestroyWindow)(THIS) OVERRIDE;

    STDMETHOD_(void, SetLayoutId)(THIS_ LPCTSTR pszLayoutId) OVERRIDE
    {
        m_strXmlLayout = pszLayoutId;
    }

    STDMETHOD_(IWindow *, GetIRoot)(THIS) OVERRIDE
    {
        return m_pRoot;
    }

    STDMETHOD_(BOOL, IsTranslucent)(CTHIS) SCONST OVERRIDE;
    STDMETHOD_(IHostPresenter *, GetPresenter)(THIS) OVERRIDE;

    STDMETHOD_(void, SetPresenter)(THIS_ IHostPresenter *pPresenter) OVERRIDE;
    STDMETHOD_(IMessageLoop *, GetMsgLoop)(THIS) OVERRIDE;

    STDMETHOD_(IWindow *, FindIChildByID)(THIS_ int nId) OVERRIDE
    {
        return m_pRoot->FindIChildByID(nId);
    }

    STDMETHOD_(IWindow *, FindIChildByName)(THIS_ LPCWSTR pszName) OVERRIDE
    {
        return m_pRoot->FindIChildByName(pszName);
    }

    STDMETHOD_(IWindow *, FindIChildByNameA)(THIS_ LPCSTR pszName) OVERRIDE
    {
        return m_pRoot->FindIChildByNameA(pszName);
    }

    STDMETHOD_(INcPainter *, GetNcPainter)(THIS) OVERRIDE
    {
        return m_pNcPainter;
    }

    STDMETHOD_(BOOL, ShowWindow)(THIS_ int nCmdShow) OVERRIDE;

    STDMETHOD_(HWND, CreateEx)
    (THIS_ HWND hWndParent, DWORD dwStyle, DWORD dwExStyle, int x, int y, int nWidth, int nHeight, IXmlNode *xmlInit DEF_VAL(NULL)) OVERRIDE;
    STDMETHOD_(HWND, Create)
    (THIS_ HWND hWndParent, int x = 0, int y = 0, int nWidth = 0, int nHeight = 0) OVERRIDE;

    STDMETHOD_(void, SetEventHandler)(THIS_ FunCallback fun, void *ctx) OVERRIDE;

    STDMETHOD_(EventHandlerInfo *, GetEventHandler)(THIS) OVERRIDE;

    STDMETHOD_(BOOL, AnimateHostWindow)(THIS_ DWORD dwTime, DWORD dwFlags) OVERRIDE;
    STDMETHOD_(void, EnableDragDrop)(THIS) OVERRIDE;

    STDMETHOD_(void, ShowHostWnd)(THIS_ int uShowCmd, BOOL bWaitAniDone) OVERRIDE;
    STDMETHOD_(void, EnablePrivateUiDef)(THIS_ BOOL bEnable) OVERRIDE;

    STDMETHOD_(void, SetScale)(THIS_ int nScale, LPCRECT pDestRect) OVERRIDE;

  public:
    SWindow *FindChildByName(LPCWSTR strName, int nDeep = -1)
    {
        return GetRoot()->FindChildByName(strName, nDeep);
    }

    SWindow *FindChildByName(LPCSTR strName, int nDeep = -1)
    {
        return GetRoot()->FindChildByName(strName, nDeep);
    }

    template <class T>
    T *FindChildByName2(LPCWSTR pszName, int nDeep = -1)
    {
        return GetRoot()->FindChildByName2<T>(pszName, nDeep);
    }

    template <class T>
    T *FindChildByName2(LPCSTR pszName, int nDeep = -1)
    {
        return GetRoot()->FindChildByName2<T>(pszName, nDeep);
    }

    SWindow *FindChildByID(int nID, int nDeep = -1)
    {
        return GetRoot()->FindChildByID(nID, nDeep);
    }

    template <class T>
    T *FindChildByID2(int nID, int nDeep = -1)
    {
        return GetRoot()->FindChildByID2<T>(nID, nDeep);
    }

    template <class T>
    T *FindChildByClass(int nDeep = -1) const
    {
        return GetRoot()->FindChildByClass<T>(nDeep);
    }

    SWindow *GetRoot() const
    {
        return m_pRoot;
    }

    SNativeWnd *GetNative()
    {
        return this;
    }

    CRect GetWindowRect() const;
    CRect GetClientRect() const;

    SHostWndAttr &GetHostAttr()
    {
        return m_hostAttr;
    }
    IToolTip *GetToolTip() const
    {
        return m_pTipCtrl;
    }

    bool StartHostAnimation(IAnimation *pAni);
    bool StopHostAnimation();
    void UpdateAutoSizeCount(bool bInc);

  protected:
    class SHostAnimationHandler : public ITimelineHandler {
      public:
        SHostWnd *m_pHostWnd;
        CRect m_rcInit;

      protected:
        STDMETHOD_(void, OnNextFrame)(THIS_) OVERRIDE;
    } m_hostAnimationHandler;

    virtual void OnHostAnimationStarted(IAnimation *pAni);
    virtual void OnHostAnimationStoped(IAnimation *pAni);

  protected: //辅助函数
    void _RedrawRegion(IRegionS *pRgn, CRect &rcInvalid);
    void _Redraw();
    void _RestoreClickState();
    void _Invalidate(LPCRECT prc);
    void _SetToolTipInfo(const SwndToolTipInfo *info, BOOL bNcTip);
    void _Init();
    void _ExcludeVideoCanvasFromPaint(IRenderTarget *pRT);
    void _PaintVideoCanvasForeground(IRenderTarget *pRT);

  protected:
    //////////////////////////////////////////////////////////////////////////
    // Message handler

    void OnPrint(HDC dc, UINT uFlags = 0);

    void OnPaint(HDC dc);

    BOOL OnEraseBkgnd(HDC dc);

    int OnCreate(LPCREATESTRUCT lpCreateStruct);

    void OnDestroy();

    void OnSize(UINT nType, CSize size);

    void OnMouseMove(UINT nFlags, CPoint point);

    void OnMouseLeave();

    BOOL OnSetCursor(HWND hWnd, UINT nHitTest, UINT message);

    void OnTimer(UINT_PTR idEvent);

    LRESULT OnMouseEvent(UINT uMsg, WPARAM wParam, LPARAM lParam);

    LRESULT OnKeyEvent(UINT uMsg, WPARAM wParam, LPARAM lParam);

    LRESULT OnActivateApp(UINT uMsg, WPARAM wParam, LPARAM lParam);

    BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);

    void OnActivate(UINT nState, BOOL bMinimized, HWND wndOther);

    void OnGetMinMaxInfo(LPMINMAXINFO lpMMI);

    void OnSetFocus(HWND wndOld);
    void OnKillFocus(HWND wndFocus);

    void UpdatePresenter(HDC dc, IRenderTarget *pRT, LPCRECT rc, BYTE byAlpha = 255, UINT uFlag = 0);

    void OnCaptureChanged(HWND wnd);

    LRESULT OnMenuExEvent(UINT uMsg, WPARAM wParam, LPARAM lParam);

    void OnWindowPosChanging(LPWINDOWPOS lpWndPos);
    void OnWindowPosChanged(LPWINDOWPOS lpWndPos);

    LRESULT OnGetObject(UINT uMsg, WPARAM wParam, LPARAM lParam);
    void OnSysCommand(UINT nID, CPoint lParam);
    void OnCommand(UINT uNotifyCode, int nID, HWND wndCtl);

#if (!DISABLE_SWNDSPY)
  protected:
    LRESULT OnSpyMsgSetSpy(UINT uMsg, WPARAM wParam, LPARAM lParam);

    LRESULT OnSpyMsgSwndEnum(UINT uMsg, WPARAM wParam, LPARAM lParam);

    LRESULT OnSpyMsgSwndSpy(UINT uMsg, WPARAM wParam, LPARAM lParam);

    LRESULT OnSpyMsgHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam);

    HWND m_hSpyWnd;
#endif

  public: // IContainer
    STDMETHOD_(BOOL, OnFireEvent)(IEvtArgs *evt) OVERRIDE;

    STDMETHOD_(void, GetContainerRect)(CTHIS_ RECT *ret) const OVERRIDE;

    STDMETHOD_(HWND, GetHostHwnd)() OVERRIDE;

    STDMETHOD_(LPCWSTR, GetTranslatorContext)() const OVERRIDE;

    STDMETHOD_(void, UpdateRegion)(IRegionS *rgn) OVERRIDE;

    STDMETHOD_(void, OnRedraw)(LPCRECT rc, BOOL bClip) OVERRIDE;

    STDMETHOD_(BOOL, OnReleaseSwndCapture)() OVERRIDE;

    STDMETHOD_(SWND, OnSetSwndCapture)(SWND swnd) OVERRIDE;

    // STDMETHOD_(BOOL, IsTranslucent)() const; same as IHostWnd::IsTranslucent

    STDMETHOD_(BOOL, IsSendWheel2Hover)() const OVERRIDE;

    STDMETHOD_(BOOL, UpdateWindow)(BOOL bForce DEF_VAL(TRUE)) OVERRIDE;

    STDMETHOD_(void, UpdateTooltip)() OVERRIDE;
    STDMETHOD_(void, SetToolTip)(THIS_ LPCRECT rc, UINT tipAlign, LPCTSTR pszTip) OVERRIDE;

    STDMETHOD_(BOOL, RegisterTimelineHandler)(THIS_ ITimelineHandler *pHandler) OVERRIDE;
    STDMETHOD_(BOOL, UnregisterTimelineHandler)(THIS_ ITimelineHandler *pHandler) OVERRIDE;
    STDMETHOD_(void, EnableHostPrivateUiDef)(THIS_ BOOL bEnable) OVERRIDE;

    // STDMETHOD_(IMessageLoop *, GetMsgLoop)(); same as IHostWnd::GetMsgLoop

    STDMETHOD_(IScriptModule *, GetScriptModule)() OVERRIDE;

    STDMETHOD_(int, GetScale)() const OVERRIDE;

    STDMETHOD_(void, EnableIME)(BOOL bEnable) OVERRIDE;

    STDMETHOD_(void, OnUpdateCursor)() OVERRIDE;

    STDMETHOD_(BOOL, PostTask)(THIS_ IRunnable *runable, BOOL bAsync DEF_VAL(TRUE)) OVERRIDE;

    STDMETHOD_(int, RemoveTasksForObject)(THIS_ void *pObj) OVERRIDE;

  protected:
    virtual IToolTip *CreateTooltip() const;
    virtual void DestroyTooltip(IToolTip *pTooltip) const;

  protected:
    virtual BOOL OnLoadLayoutFromResourceID(SXmlDoc &xmlDoc);
    virtual SXmlNode OnGetInitXmlNode(SXmlDoc &xmlDoc);
    virtual void OnUserXmlNode(SXmlNode xmlUser);
    virtual SRootWindow *CreateRoot();

  public:
    virtual BOOL onRootResize(IEvtArgs *e);

  public: //事件处理接口
    virtual BOOL _HandleEvent(IEvtArgs *pEvt);

  protected:
    LRESULT OnSetLanguage(UINT uMsg, WPARAM wp, LPARAM lp);
    LRESULT OnUpdateFont(UINT uMsg, WPARAM wp, LPARAM lp);
    LRESULT OnRunTasks(UINT uMsg, WPARAM wp, LPARAM lp);

    BEGIN_MSG_MAP_EX(SHostWnd)
        MSG_WM_SIZE(OnSize)
        MSG_WM_PRINT(OnPrint)
        MSG_WM_PAINT(OnPaint)
        MSG_WM_CREATE(OnCreate)
        MSG_WM_DESTROY(OnDestroy)
        MSG_WM_ERASEBKGND(OnEraseBkgnd)
        MSG_WM_MOUSELEAVE(OnMouseLeave)
        MSG_WM_MOUSEMOVE(OnMouseMove)
        MSG_WM_MOUSEWHEEL(OnMouseWheel)
        MSG_WM_ACTIVATE(OnActivate)
        MSG_WM_SETFOCUS(OnSetFocus)
        MSG_WM_KILLFOCUS(OnKillFocus)
        MESSAGE_RANGE_HANDLER_EX(WM_MOUSEFIRST, WM_MOUSELAST, OnMouseEvent)
        MESSAGE_RANGE_HANDLER_EX(WM_KEYFIRST, WM_KEYLAST, OnKeyEvent)
        MESSAGE_RANGE_HANDLER_EX(WM_IME_STARTCOMPOSITION, WM_IME_KEYLAST, OnKeyEvent)
        MESSAGE_HANDLER_EX(WM_IME_CHAR, OnKeyEvent)
        MESSAGE_HANDLER_EX(WM_IME_REQUEST, OnKeyEvent)
        MESSAGE_HANDLER_EX(WM_ACTIVATEAPP, OnActivateApp)
        MSG_WM_SETCURSOR(OnSetCursor)
        MSG_WM_TIMER(OnTimer)
        MSG_WM_GETMINMAXINFO(OnGetMinMaxInfo)
        MSG_WM_CAPTURECHANGED(OnCaptureChanged)
        MESSAGE_HANDLER_EX(UM_MENUEVENT, OnMenuExEvent)
        MSG_WM_WINDOWPOSCHANGING(OnWindowPosChanging)
        MSG_WM_WINDOWPOSCHANGED(OnWindowPosChanged)
        MESSAGE_HANDLER_EX(WM_GETOBJECT, OnGetObject)
        MSG_WM_COMMAND(OnCommand)
        MSG_WM_SYSCOMMAND(OnSysCommand)
        MESSAGE_HANDLER_EX(UM_UPDATEFONT, OnUpdateFont)
        MESSAGE_HANDLER_EX(UM_SETLANGUAGE, OnSetLanguage)
        MESSAGE_HANDLER_EX(UM_RUN_TASKS, OnRunTasks)
        CHAIN_MSG_MAP_MEMBER(*m_pNcPainter)
#if (!DISABLE_SWNDSPY)
        MESSAGE_HANDLER_EX(SPYMSG_SETSPY, OnSpyMsgSetSpy)
        MESSAGE_HANDLER_EX(SPYMSG_SWNDENUM, OnSpyMsgSwndEnum)
        MESSAGE_HANDLER_EX(SPYMSG_SWNDINFO, OnSpyMsgSwndSpy)
        MESSAGE_HANDLER_EX(SPYMSG_HITTEST, OnSpyMsgHitTest)
#endif // DISABLE_SWNDSPY
        REFLECT_NOTIFY_CODE(NM_CUSTOMDRAW)
    END_MSG_MAP()
};

SNSEND
#endif // __SHOSTWND__H__