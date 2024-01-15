﻿/**
 * Copyright (C) 2014-2050 SOUI团队
 * All rights reserved.
 *
 * @file       SCmnCtrl.h
 * @brief      通用控件
 * @version    v1.0
 * @author     soui
 * @date       2014-05-28
 *
 * Describe    此文件中定义了很多通用控件:静态文本，超链接，按钮，单选按钮等
 */

#ifndef __SCMNCTRL__H__
#define __SCMNCTRL__H__
#include "core/SWnd.h"
#include "core/SAccelerator.h"
#include "core/SFocusManager.h"
#include <interface/SCtrl-i.h>

SNSBEGIN

/**
 * @class      SStatic
 * @brief      静态文本控件类
 *
 * Describe    静态文本控件可支持多行，有多行属性时，\n可以强制换行
 * Usage       <text>inner text example</text>
 */
class SOUI_EXP SStatic : public SWindow {
    DEF_SOBJECT(SWindow, L"text")
  public:
    /**
     * SStatic::SStatic
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SStatic();
    /**
     * SStatic::SDrawText
     * @brief    绘制文本
     * @param    IRenderTarget *pRT -- 绘制设备句柄
     * @param    LPCTSTR pszBuf -- 文本内容字符串
     * @param    int cchText -- 字符串长度
     * @param    LPRECT pRect -- 指向矩形结构RECT的指针
     * @param    UINT uFormat --  正文的绘制选项
     *
     * Describe  对DrawText封装
     */
    virtual void DrawText(IRenderTarget *pRT, LPCTSTR pszBuf, int cchText, LPRECT pRect, UINT uFormat);

  protected:
    virtual void OnDrawLine(IRenderTarget *pRT, LPCTSTR pszBuf, int iBegin, int cchText, LPRECT pRect, UINT uFormat);
    virtual SIZE OnMeasureText(IRenderTarget *pRT, LPCTSTR pszBuf, int cchText);

    void DrawMultiLine(IRenderTarget *pRT, LPCTSTR pszBuf, int cchText, LPRECT pRect, UINT uFormat);

    int m_nLineInter; /**< 行间距 */
    bool m_bWordbreak;
    SOUI_ATTRS_BEGIN()
        ATTR_INT(L"interHeight", m_nLineInter, TRUE)
        ATTR_BOOL(L"wordBreak", m_bWordbreak, TRUE)
    SOUI_ATTRS_END()
};

/**
 * @class      SLink
 * @brief      超链接控件类
 *
 * Describe    Only For Header Drag Test
 * Usage       <link>inner text example</link>
 */
class SOUI_EXP SLink : public SWindow {
    DEF_SOBJECT(SWindow, L"link")

  public:
    /**
     * SLink::SLink
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SLink();

  protected:
    /**
     * SLink::OnAttributeFinish
     * @brief    解析xml设置属性
     *
     * Describe  根据xml文件设置相关属性
     */
    virtual void WINAPI OnInitFinished(IXmlNode *pNode);
    /**
     * SLink::SDrawText
     * @brief    绘制文本
     * @param    IRenderTarget *pRT -- 绘制设备句柄
     * @param    LPCTSTR pszBuf -- 文本内容字符串
     * @param    int cchText -- 字符串长度
     * @param    LPRECT pRect -- 指向矩形结构RECT的指针
     * @param    UINT uFormat --  正文的绘制选项
     *
     * Describe  对DrawText封装
     */
    virtual void DrawText(IRenderTarget *pRT, LPCTSTR pszBuf, int cchText, LPRECT pRect, UINT uFormat);

    /**
     * SLink::OnSetCursor
     * @brief    设置光标样式和位置
     * @param    CPoint &pt -- 设置光标位置
     * @return   返回值BOOL 成功--TRUE 失败--FALSE
     *
     * Describe  函数内部会加载光标样式
     */
    virtual BOOL OnSetCursor(const CPoint &pt);

    void OnLButtonDown(UINT nFlags, CPoint pt);
    void OnLButtonUp(UINT nFlags, CPoint pt);
    void OnMouseMove(UINT nFlags, CPoint pt);
    void OnMouseHover(WPARAM wParam, CPoint ptPos);

    SOUI_ATTRS_BEGIN()
        ATTR_STRINGT(L"href", m_strLinkUrl, FALSE)
    SOUI_ATTRS_END()

    SOUI_MSG_MAP_BEGIN()
        MSG_WM_LBUTTONDOWN(OnLButtonDown)
        MSG_WM_LBUTTONUP(OnLButtonUp)
        MSG_WM_MOUSEMOVE(OnMouseMove)
        MSG_WM_MOUSEHOVER(OnMouseHover)
    SOUI_MSG_MAP_END()

  protected:
    CRect m_rcText;        /**< 文本显示所在位置 */
    SStringT m_strLinkUrl; /**< 窗口URL */
};

/**
 * @class      SButton
 * @brief      按钮控件类
 *
 * Describe    通过属性ID绑定click事件 Use id attribute to process click event
 * Usage       <button id=xx>inner text example</button>
 */
class SOUI_EXP SButton
    : public SWindow
    , public IAcceleratorTarget
    , public ITimelineHandler {
    DEF_SOBJECT(SWindow, L"button")
  public:
    /**
     * SButton::SButton
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SButton();

  protected:
    /**
     * SButton::NeedRedrawWhenStateChange
     * @brief    状态变化需要重画
     * @return   返回值BOOL 成功--TRUE 失败--FALSE
     *
     * Describe  当按钮状态发生变化时候需要重新绘制 默认返回TRUE
     */
    virtual BOOL NeedRedrawWhenStateChange()
    {
        return TRUE;
    }
    /**
     * SButton::OnGetDlgCode
     * @brief    获得编码
     *
     * Describe  返回宏定义SC_WANTCHARS代表需要WM_CHAR消息
     */
    virtual UINT WINAPI OnGetDlgCode() const
    {
        return SC_WANTCHARS;
    }

    /**
     * SButton::OnAcceleratorPressed
     * @brief    加速键按下
     * @param    CAccelerator& accelerator -- 加速键相关结构体
     * @return   返回值BOOL 成功--TRUE 失败--FALSE
     *
     * Describe  处理加速键响应消息
     */
    virtual BOOL WINAPI OnAcceleratorPressed(const IAccelerator *accelerator) OVERRIDE;
    virtual BOOL WINAPI InitFromXml(IXmlNode *pNode) OVERRIDE;

  protected:
    /**
     * SButton::OnStateChanged
     * @brief    状态改变处理函数
     * @param    DWORD dwOldState -- 旧状态
     * @param    DWORD dwNewState -- 新状态
     *
     * Describe  状态改变处理函数
     */
    virtual void OnStateChanged(DWORD dwOldState, DWORD dwNewState);
    virtual void OnContainerChanged(ISwndContainer *pOldContainer, ISwndContainer *pNewContainer);

    void OnPaint(IRenderTarget *pRT);

    void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

    void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);

    void OnDestroy();

    void OnSize(UINT nType, CSize size);

    BOOL OnEraseBkgnd(IRenderTarget *pRT)
    {
        return TRUE;
    }

    HRESULT OnAttrAccel(SStringW strAccel, BOOL bLoading);

  protected:
    STDMETHOD_(void, OnNextFrame)(THIS_) OVERRIDE;

    /**
     * SLink::StopCurAnimate
     * @brief    停止动画
     *
     * Describe  停止动画
     */
    void StopCurAnimate();

    DWORD m_accel;
    BOOL m_bAnimate;                 /**< 动画标志 */
    WORD m_byAlphaAni;               /**< 动画状态 */
    BYTE m_nAniStep;                 /**< alpha for an animate step */
    BOOL m_bDisableAccelIfInvisible; /**< disable accel if invisible */
  public:
    SOUI_ATTRS_BEGIN()
        ATTR_CUSTOM(L"accel", OnAttrAccel)
        ATTR_BOOL(L"animate", m_bAnimate, FALSE)
        ATTR_INT(L"animateStep", m_nAniStep, FALSE)
        ATTR_BOOL(L"disableAccelIfInvisible", m_bDisableAccelIfInvisible, FALSE)
    SOUI_ATTRS_END()

    SOUI_MSG_MAP_BEGIN()
        MSG_WM_PAINT_EX(OnPaint)
        MSG_WM_ERASEBKGND_EX(OnEraseBkgnd)
        MSG_WM_LBUTTONDBLCLK(OnLButtonDown) //将双击消息处理为单击
        MSG_WM_KEYDOWN(OnKeyDown)
        MSG_WM_KEYUP(OnKeyUp)
        MSG_WM_DESTROY(OnDestroy)
        MSG_WM_SIZE(OnSize)
    SOUI_MSG_MAP_END()
};

/**
 * @class      SImageButton
 * @brief      图片按钮类
 *
 * Describe    图片按钮类，继承SButton
 */
class SOUI_EXP SImageButton : public SButton {
    DEF_SOBJECT(SButton, L"imgbtn")
  public:
    SImageButton();

  protected:
    SIZE MeasureContent(int wid, int hei) override;
};

/**
 * @class      SImageWnd
 * @brief      图片控件类
 *
 * Describe    Image Control 图片控件类
 * Usage       Usage: <img skin="skin" sub="0"/>
 */
class SOUI_EXP SImageWnd : public TWindowProxy<IImageWnd> {
    DEF_SOBJECT(SWindow, L"img")
  public:
    /**
     * SImageWnd::SImageWnd
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SImageWnd();

    /**
     * SImageWnd::~SImageWnd
     * @brief    析构函数
     *
     * Describe  析构函数
     */
    virtual ~SImageWnd();

  public:
    /**
     * @brief 设置skin
     * @param pSkin -- skin对象
     * @param iFrame -- skin的子图索引
     * @param bAutoFree -- 控件管理pSkin标志，为TRUE时调用方可以释放该Skin
     * @return BOOL TRUE-成功，FALSE-失败
     */
    STDMETHOD_(BOOL, SetSkin)(THIS_ ISkinObj *pSkin, int iFrame DEF_VAL(0), BOOL bAutoFree DEF_VAL(TRUE)) OVERRIDE;

    /**
     * SImageWnd::GetSkin
     * @brief    获取资源
     * @return   返回值ISkinObj指针
     *
     * Describe  获取资源
     */
    STDMETHOD_(ISkinObj *, GetSkin)(THIS) OVERRIDE;

    /**
     * SImageWnd::SetImage
     * @param    IBitmap * pBitmap -- 图片对象
     * @param    FilterLevel fl -- FilterLevel
     * @return   void
     *
     * Describe  设置绘制图片
     */
    STDMETHOD_(void, SetImage)(THIS_ IBitmapS *pBitmap, FilterLevel fl DEF_VAL(kNone_FilterLevel)) OVERRIDE;

    /**
     * @brief 获取当前设置的IBitmapS对象
     * @return IBitmapS * -- 当前设置的IBitmapS对象
     */
    STDMETHOD_(IBitmapS *, GetImage)(THIS) OVERRIDE;

    /**
     * SImageWnd::SetIcon
     * @param    int nSubID -- 子图在Skin中的索引号
     * @brief    设置图标
     * @return   返回值BOOL 成功--TRUE 失败--FALSE
     *
     * Describe  设置图标
     */
    STDMETHOD_(BOOL, SetIcon)(THIS_ int nSubID) OVERRIDE;

  protected:
    virtual void OnColorize(COLORREF cr);

    virtual void OnScaleChanged(int scale);
    virtual SIZE MeasureContent(int nParentWid, int nParentHei);

    int m_iTile;                   /**<绘制是否平铺,0--位伸（默认），1--不变常规绘制, 2--平铺 */
    BOOL m_bManaged;               /**< 是否要自动释放当前的m_pSkin对象 */
    int m_iIcon;                   /**< 绘制状态索引 */
    SAutoRefPtr<ISkinObj> m_pSkin; /**< ISkinObj对象 */
    SAutoRefPtr<IBitmapS> m_pImg;  /**<使用代码设定的图片*/
    FilterLevel m_fl;              /**<绘制图片的放大精度*/
    bool m_bKeepAspect;            /**< keep aspect ratio */

    SOUI_ATTRS_BEGIN()
        ATTR_SKIN(L"skin", m_pSkin, TRUE)
        ATTR_INT(L"iconIndex", m_iIcon, FALSE)
        ATTR_INT(L"tile", m_iTile, TRUE)
        ATTR_BOOL(L"keepAspect", m_bKeepAspect, TRUE)
    SOUI_ATTRS_END()

  protected:
    void OnPaint(IRenderTarget *pRT);

    SOUI_MSG_MAP_BEGIN()
        MSG_WM_PAINT_EX(OnPaint)
    SOUI_MSG_MAP_END()
};

/**
 * @class      SAnimateImgWnd
 * @brief      动画图片窗口
 *
 * Describe    此窗口支持动画效果
 */
class SOUI_EXP SAnimateImgWnd
    : public TWindowProxy<IAnimateImgWnd>
    , public ITimelineHandler {
    DEF_SOBJECT(SWindow, L"animateimg")
  public:
    /**
     * SAnimateImgWnd::SAnimateImgWnd
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SAnimateImgWnd();

    /**
     * SAnimateImgWnd::~SAnimateImgWnd
     * @brief    析构函数
     *
     * Describe  析构函数
     */
    virtual ~SAnimateImgWnd()
    {
    }

    /**
     * SAnimateImgWnd::Start
     * @brief    启动动画
     *
     * Describe  启动动画
     */
    void WINAPI Start();
    /**
     * SAnimateImgWnd::Stop
     * @brief    停止动画
     *
     * Describe  停止动画
     */
    void WINAPI Stop();

    /**
     * SAnimateImgWnd::IsPlaying
     * @brief    判断动画运行状态
     * @return   返回值是动画状态 TRUE -- 运行中
     *
     * Describe  判断动画运行状态
     */
    BOOL WINAPI IsPlaying() SCONST
    {
        return m_bPlaying;
    }

  protected:
    virtual SIZE MeasureContent(int wid, int hei);
    STDMETHOD_(void, OnNextFrame)(THIS_) OVERRIDE;
    virtual void OnColorize(COLORREF cr);
    virtual void OnContainerChanged(ISwndContainer *pOldContainer, ISwndContainer *pNewContainer);
    void OnScaleChanged(int scale) override;
    void OnPaint(IRenderTarget *pRT);

    void OnShowWindow(BOOL bShow, UINT nStatus);
    void OnDestroy();

    SOUI_MSG_MAP_BEGIN()
        MSG_WM_PAINT_EX(OnPaint)
        MSG_WM_DESTROY(OnDestroy)
        MSG_WM_SHOWWINDOW(OnShowWindow)
    SOUI_MSG_MAP_END()

    SOUI_ATTRS_BEGIN()
        ATTR_SKIN(L"skin", m_pSkin, TRUE)
        ATTR_UINT(L"speed", m_nSpeed, FALSE)
        ATTR_BOOL(L"autoStart", m_bAutoStart, FALSE)
        ATTR_INT(L"repeat", m_nRepeat, FALSE)
    SOUI_ATTRS_END()

  protected:
    SAutoRefPtr<ISkinObj> m_pSkin; /**< 动画图片 */
    int m_nSpeed;                  /**< 速度 */
    int m_iCurFrame;               /**< 当前帧 */
    BOOL m_bAutoStart;             /**< 是否自动启动 */
    BOOL m_bPlaying;               /**< 是否运行中 */
    int m_iTimeFrame;              /**< OnNextFrame的执行次数 */
    int m_nRepeat;                 /**< 播放循环次数,-1代表无限循环 */
    int m_iRepeat;                 /**< 当前播放循环轮次 */
};

/**
 * @class      SProgress
 * @brief      进度条类
 *
 * Describe    进度条类
 * Usage: <progress bgskin=xx posskin=xx min=0 max=100 value=10,showpercent=0/>
 */
class SOUI_EXP SProgress : public TWindowProxy<IProgress> {
    DEF_SOBJECT(SWindow, L"progress")
  public:
    /**
     * SProgress::SProgress
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SProgress();

    /**
     * SProgress::SetValue
     * @brief    设置进度条进度值
     * @param    int nValue  --  进度值
     * @return   返回值是 TRUE -- 设置成功
     *
     * Describe  设置进度条进度值
     */
    STDMETHOD_(BOOL, SetValue)(THIS_ int nValue) OVERRIDE;
    /**
     * SProgress::GetValue
     * @brief    获取进度值
     * @return   返回值是int
     *
     * Describe  获取进度值
     */
    STDMETHOD_(int, GetValue)(CTHIS) SCONST OVERRIDE
    {
        return m_nValue;
    }

    /**
     * SProgress::SetRange
     * @param    int nMin  --  进度最小值
     * @param    int nMax  --  进度最大值
     * @brief    设置进度值最小大值
     *
     * Describe  设置进度值
     */
    STDMETHOD_(void, SetRange)(THIS_ int nMin, int nMax) OVERRIDE;
    /**
     * SProgress::GetRange
     * @param    int nMin  --  进度最小值
     * @param    int nMax  --  进度最大值
     * @brief    获取进度值最小大值
     *
     * Describe  获取进度值
     */
    STDMETHOD_(void, GetRange)(CTHIS_ int *pMin, int *pMax) SCONST OVERRIDE;
    /**
     * SProgress::IsVertical
     * @brief    判断进度条是否为竖直状态
     * @return   返回值是 TRUE -- 竖直状态
     *
     * Describe  获取进度值
     */
    STDMETHOD_(BOOL, IsVertical)(CTHIS) SCONST OVERRIDE
    {
        return m_bVertical;
    }

  protected:
    /**
     * SProgress::GetDesiredSize
     * @brief    获取预期大小
     * @param    int wid -- 容器宽度
     * @param    int hei -- 容器高度
     * @return   返回值 CSize对象
     *
     * Describe  根据矩形的大小，获取预期大小(解释有点不对)
     */
    STDMETHOD_(void, GetDesiredSize)(THIS_ SIZE *psz, int wid, int hei) OVERRIDE;
    virtual void OnColorize(COLORREF cr);
    virtual void OnScaleChanged(int scale);

    void OnPaint(IRenderTarget *pRT);
    int OnCreate(void *);

    int m_nMinValue; /**< 进度最小值 */
    int m_nMaxValue; /**< 进度最大值 */
    int m_nValue;    /**< 进度值 */

    BOOL m_bShowPercent; /**< 是否显示百分比 */
    BOOL m_bVertical;    /**< 是否竖直状态 */

    SAutoRefPtr<ISkinObj> m_pSkinBg;  /**< 背景资源 */
    SAutoRefPtr<ISkinObj> m_pSkinPos; /**< 前景资源 */

    SOUI_MSG_MAP_BEGIN()
        MSG_WM_PAINT_EX(OnPaint)
        MSG_WM_CREATE(OnCreate)
    SOUI_MSG_MAP_END()

    SOUI_ATTRS_BEGIN()
        ATTR_SKIN(L"bkgndSkin", m_pSkinBg, TRUE)
        ATTR_SKIN(L"posSkin", m_pSkinPos, TRUE)
        ATTR_INT(L"min", m_nMinValue, FALSE)
        ATTR_INT(L"max", m_nMaxValue, FALSE)
        ATTR_INT(L"value", m_nValue, FALSE)
        ATTR_BOOL(L"vertical", m_bVertical, FALSE)
        ATTR_BOOL(L"showPercent", m_bShowPercent, FALSE)
    SOUI_ATTRS_END()
};

/**
 * @class      SLine
 * @brief      线条控件
 *
 * Describe    线条控件
 * Usage: <hr size=1 mode="vert" lineStyle="dash"/>
 */
class SOUI_EXP SLine : public SWindow {
    DEF_SOBJECT(SWindow, L"hr")

  public:
    /**
     * SLine::SLine
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SLine();

    void OnPaint(IRenderTarget *pRT);

  protected:
    int m_nLineStyle;
    int m_nLineSize;

    COLORREF m_crLine;

    enum HRMODE
    {
        HR_HORZ = 0,
        HR_VERT,
        HR_TILT,
    } m_mode;

    SOUI_ATTRS_BEGIN()
        ATTR_COLOR(L"colorLine", m_crLine, FALSE)
        ATTR_COLOR(L"lineColor", m_crLine, FALSE)
        ATTR_INT(L"lineSize", m_nLineSize, FALSE)
        ATTR_ENUM_BEGIN(L"mode", HRMODE, FALSE)
            ATTR_ENUM_VALUE(L"vertical", HR_VERT)
            ATTR_ENUM_VALUE(L"horizontal", HR_HORZ)
            ATTR_ENUM_VALUE(L"tilt", HR_TILT)
        ATTR_ENUM_END(m_mode)
        ATTR_ENUM_BEGIN(L"lineStyle", int, FALSE)
            ATTR_ENUM_VALUE(L"solid", PS_SOLID)           // default
            ATTR_ENUM_VALUE(L"dash", PS_DASH)             /* -------  */
            ATTR_ENUM_VALUE(L"dot", PS_DOT)               /* .......  */
            ATTR_ENUM_VALUE(L"dashdot", PS_DASHDOT)       /* _._._._  */
            ATTR_ENUM_VALUE(L"dashdotdot", PS_DASHDOTDOT) /* _.._.._  */
        ATTR_ENUM_END(m_nLineStyle)
    SOUI_ATTRS_END()

    SOUI_MSG_MAP_BEGIN()
        MSG_WM_PAINT_EX(OnPaint)
    SOUI_MSG_MAP_END()
};

/**
 * @class      SCheckBox
 * @brief      复选框控件
 *
 * Describe    复选框控件
 * Usage: <check checked="1">This is a check-box</check>
 */
class SOUI_EXP SCheckBox : public SWindow {
    DEF_SOBJECT(SWindow, L"check")

    enum
    {
        CheckBoxSpacing = 4,
    };

  public:
    /**
     * SCheckBox::SCheckBox
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SCheckBox();

  protected:
    SAutoRefPtr<ISkinObj> m_pSkin;      /**< 状态图片资源 */
    SAutoRefPtr<ISkinObj> m_pFocusSkin; /**< 焦点状态资源 */
    /**
     * SCheckBox::GetCheckRect
     * @brief    获得复选框矩形
     * @return   返回值CRect矩形框
     *
     * Describe  获取复选框矩形
     */
    CRect GetCheckRect();

    SIZE MeasureContent(int wid, int hei) override;
    /**
     * SCheckBox::GetTextRect
     * @brief    获取文本大小
     * @param    LPRECT pRect  --  内容矩形框
     *
     * Describe  设置矩形的大小
     */
    virtual void GetTextRect(LPRECT pRect);
    /**
     * SCheckBox::NeedRedrawWhenStateChange
     * @brief    判断状态改变是否需要重画
     * @return   返回值 BOOL
     *
     * Describe  状态改变是否需要重画
     */
    virtual BOOL NeedRedrawWhenStateChange()
    {
        return TRUE;
    }

    /**
     * SCheckBox::OnGetDlgCode
     * @brief    返回对应消息码
     * @return   返回值 UINT
     *
     * Describe  返回对应消息码
     */
    virtual UINT WINAPI OnGetDlgCode() const
    {
        return SC_WANTCHARS;
    }
    /**
     * SCheckBox::DrawFocus
     * @brief    绘制获取焦点
     * @param    IRenderTarget *pRT  --  设备句柄
     *
     * Describe  返回对应消息码
     */
    virtual void DrawFocus(IRenderTarget *pRT);

    virtual void OnColorize(COLORREF cr);

    virtual void OnScaleChanged(int nScale);

    void OnLButtonUp(UINT nFlags, CPoint point);

    void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

    void OnPaint(IRenderTarget *pRT);

    HRESULT OnAttrCheck(const SStringW &strValue, BOOL bLoading);

    SOUI_ATTRS_BEGIN()
        ATTR_SKIN(L"skin", m_pSkin, FALSE)
        ATTR_SKIN(L"focusSkin", m_pFocusSkin, FALSE)
        ATTR_CUSTOM(L"checked", OnAttrCheck)
    SOUI_ATTRS_END()

    SOUI_MSG_MAP_BEGIN()
        MSG_WM_PAINT_EX(OnPaint)
        MSG_WM_LBUTTONDBLCLK(OnLButtonDown)
        MSG_WM_LBUTTONUP(OnLButtonUp)
        MSG_WM_KEYDOWN(OnKeyDown)
    SOUI_MSG_MAP_END()
};

/**
 * @class      SIconWnd
 * @brief      图标控件
 *
 * Describe    图标控件
 * Usage: <icon src="icon:16" />
 */
class SOUI_EXP SIconWnd : public TWindowProxy<IIconWnd> {
    DEF_SOBJECT(SWindow, L"icon")
  public:
    /**
     * SIconWnd::SIconWnd
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SIconWnd();
    virtual ~SIconWnd();

  public:
    STDMETHOD_(void, SetIcon)(THIS_ HICON hIcon) OVERRIDE;

  protected:
    SIZE MeasureContent(int wid, int hei) override;

    void OnPaint(IRenderTarget *pRT);

    SOUI_MSG_MAP_BEGIN()
        MSG_WM_PAINT_EX(OnPaint)
    SOUI_MSG_MAP_END()

  public:
    SOUI_ATTRS_BEGIN()
        ATTR_CUSTOM(L"src", OnAttrIcon)
    SOUI_ATTRS_END()
  protected:
    HRESULT OnAttrIcon(const SStringW &value, BOOL bLoading);

    void OnScaleChanged(int scale) override;

  protected:
    SStringW m_strIconSrc;
    HICON m_theIcon; /**< 图标资源句柄 */
};

/**
 * @class      SRadioBox
 * @brief      单选框控件
 *
 * Describe    单选框控件
 * Usage: <radio checked="1">This is a check-box</radio>
 */
class SOUI_EXP SRadioBox : public SWindow {
    DEF_SOBJECT(SWindow, L"radio")

  public:
    /**
     * SRadioBox::SRadioBox
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SRadioBox();

  protected:
    /**
     * SRadioBox::GetRadioRect
     * @brief    获取radio显示位置
     *
     * Describe
     */
    CRect GetRadioRect();

    /**
     * SRadioBox::GetTextRect
     * @brief    获得文本大小
     * @param    LPRECT pRect -- 文本大小Rect
     *
     * Describe
     */
    virtual void GetTextRect(LPRECT pRect);

    SIZE MeasureContent(int wid, int hei) OVERRIDE;
    /**
     * SRadioBox::OnGetDlgCode
     * @brief    获取消息编码
     * @return   返回编码值
     *
     * Describe  获取消息编码
     */
    STDMETHOD_(UINT, OnGetDlgCode)(THIS) SCONST OVERRIDE
    {
        return 0;
    }
    /**
     * SRadioBox::IsSiblingsAutoGroupped
     * @brief    是否自动添加到同一组
     * @return   返回BOOL
     *
     * Describe  相同名称的单选按钮是否自动添加到同一组中
     */
    STDMETHOD_(BOOL, IsSiblingsAutoGroupped)(THIS) SCONST OVERRIDE
    {
        return TRUE;
    }

    /**
     * SRadioBox::NeedRedrawWhenStateChange
     * @brief    当状态改变时候是否需要重绘
     * @return   返回BOOL
     *
     * Describe  当状态改变时候是否需要重绘
     */
    virtual BOOL NeedRedrawWhenStateChange();
    /**
     * SRadioBox::DrawFocus
     * @brief    绘制焦点样式
     * @param    IRenderTarget *pRT -- 绘制设备
     *
     * Describe  当获得焦点时候需要绘制
     */
    virtual void DrawFocus(IRenderTarget *pRT);

    /**
     * SRadioBox::GetSelectedSiblingInGroup
     * @brief    获取一个group中有选中状态的兄弟
     * @return   返回选中状态的兄弟窗口指针
     *
     * Describe  没有选中状态兄弟时返回NULL
     */
    virtual SWindow *GetSelectedSiblingInGroup();

    /**
     * OnStateChanging
     * @brief    状态发生变化
     * @param    DWORD dwOldState --  原状态
     * @param    DWORD dwNewState --  新状态
     * @return   void
     *
     * Describe
     */
    virtual void OnStateChanging(DWORD dwOldState, DWORD dwNewState);

    virtual void OnColorize(COLORREF cr);

    virtual void OnScaleChanged(int nScale);

  protected:
    void OnSetFocus(SWND wndOld, SFocusManager::FocusChangeReason reason);

    void OnLButtonUp(UINT nFlags, CPoint pt);

    void OnPaint(IRenderTarget *pRT);

    HRESULT OnAttrCheck(const SStringW &strValue, BOOL bLoading);

    SOUI_ATTRS_BEGIN()
        ATTR_SKIN(L"skin", m_pSkin, FALSE)
        ATTR_SKIN(L"focusSkin", m_pFocusSkin, FALSE)
        ATTR_CUSTOM(L"checked", OnAttrCheck)
        ATTR_ENUM_BEGIN(L"iconAlign", UINT, TRUE)
            ATTR_ENUM_VALUE(L"left", SwndStyle::Align_Left)
            ATTR_ENUM_VALUE(L"center", SwndStyle::Align_Center)
            ATTR_ENUM_VALUE(L"right", SwndStyle::Align_Right)
        ATTR_ENUM_END(m_uIconAlign)
        ATTR_ENUM_BEGIN(L"iconValign", UINT, TRUE)
            ATTR_ENUM_VALUE(L"top", SwndStyle::VAlign_Top)
            ATTR_ENUM_VALUE(L"middle", SwndStyle::VAlign_Middle)
            ATTR_ENUM_VALUE(L"bottom", SwndStyle::VAlign_Bottom)
        ATTR_ENUM_END(m_uIconVAlign)
        ATTR_INT(L"sep", m_nRadioBoxSpacing, TRUE)
    SOUI_ATTRS_END()

    SOUI_MSG_MAP_BEGIN()
        MSG_WM_PAINT_EX(OnPaint)
        MSG_WM_LBUTTONUP(OnLButtonUp)
        MSG_WM_SETFOCUS_EX2(OnSetFocus)
    SOUI_MSG_MAP_END()

  protected:
    SAutoRefPtr<ISkinObj> m_pSkin;      /**< 皮肤资源 */
    SAutoRefPtr<ISkinObj> m_pFocusSkin; /**< 焦点皮肤资源 */
    UINT m_uIconAlign;
    UINT m_uIconVAlign;
    int m_nRadioBoxSpacing;
};

class SOUI_EXP SRadioGroup : public SWindow {
    DEF_SOBJECT(SWindow, L"radioGroup")
  public:
    SRadioGroup();

    BOOL Check(int nID);
    BOOL Check(LPCTSTR pszName);

    BOOL ClearCheck();

  protected:
    STDMETHOD_(BOOL, FireEvent)(THIS_ IEvtArgs *evt) OVERRIDE;

    virtual void OnAfterInsertChild(SWindow *pChild);
    virtual void OnBeforeRemoveChild(SWindow *pChild);
};

/**
 * @class      SToggle
 * @brief      Toggle控件
 *
 * Describe    Toggle控件
 */
class SOUI_EXP SToggle : public SCheckBox {
    DEF_SOBJECT(SCheckBox, L"toggle")
  public:
    /**
     * SToggle::SToggle
     * @brief    构造函数
     *
     * Describe  构造函数
     */
    SToggle();
    /**
     * SToggle::SetToggle
     * @brief    设置Toggle属性
     * @param    BOOL bToggle -- 是否启用Toggle特效
     * @param    BOOL bUpdate -- 是否更新 默认值TRUE
     *
     * Describe  设置Toggle属性
     */
    void SetToggle(BOOL bToggle, BOOL bUpdate = TRUE);
    /**
     * SToggle::GetToggle
     * @brief    获取Toggle属性
     * @return   返回值BOOL
     *
     * Describe  获取Toggle属性 主要是获取是否Toggle
     */
    BOOL GetToggle();

  protected:
    SIZE MeasureContent(int nParentWid, int nParentHei) override;
    virtual BOOL NeedRedrawWhenStateChange()
    {
        return TRUE;
    }

  protected:
    void OnPaint(IRenderTarget *pRT);

    SOUI_MSG_MAP_BEGIN()
        MSG_WM_PAINT_EX(OnPaint)
    SOUI_MSG_MAP_END()
};

/**
 * @class      SGroup
 * @brief      组控件
 *
 * Describe    组控件
 * Usage       <group colorLine1="#b8d5e2" colorLine2="#999999">group text</>
 */
class SOUI_EXP SGroup : public SWindow {
    DEF_SOBJECT(SWindow, L"group")
  public:
    SGroup();

  protected:
    STDMETHOD_(void, GetChildrenLayoutRect)(THIS_ RECT *prc) SCONST OVERRIDE;
    STDMETHOD_(void, GetDesiredSize)(THIS_ SIZE *psz, int wid, int hei) OVERRIDE;

    void OnPaint(IRenderTarget *pRT);

    COLORREF m_crLine1, m_crLine2; /**< group 3D显示使用的两种颜色 */
    SLayoutSize m_nRound;          /**< 圆角半径 */
    SLayoutSize m_nHeaderHeight;   /**< 头部高度 */
  public:
    SOUI_ATTRS_BEGIN()
        ATTR_COLOR(L"colorLine1", m_crLine1, FALSE)
        ATTR_COLOR(L"colorLine2", m_crLine2, FALSE)
        ATTR_LAYOUTSIZE(L"round", m_nRound, FALSE)
        ATTR_LAYOUTSIZE(L"headerHeight", m_nHeaderHeight, TRUE)
    SOUI_ATTRS_END()

    SOUI_MSG_MAP_BEGIN()
        MSG_WM_PAINT_EX(OnPaint)
    SOUI_MSG_MAP_END()
};

SNSEND

#endif // __SCMNCTRL__H__