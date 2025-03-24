﻿#ifndef __SSKIN__H__
#define __SSKIN__H__

#include <core/SSkinObjBase.h>
#include <layout/SLayoutSize.h>
#include <helper/SplitString.h>
#include <matrix/SPoint.h>
#include <sobject/Sobject.hpp>

SNSBEGIN

class SOUI_EXP SSkinImgList : public SSkinObjBase {
    DEF_SOBJECT(SSkinObjBase, L"imglist")

  public:
    SSkinImgList();
    virtual ~SSkinImgList();

    STDMETHOD_(SIZE, GetSkinSize)(THIS) SCONST OVERRIDE;
    STDMETHOD_(int, GetStates)(THIS) SCONST OVERRIDE;
    STDMETHOD_(void, OnColorize)(THIS_ COLORREF cr) OVERRIDE;

    virtual void SetStates(int nStates)
    {
        m_nStates = nStates;
    }

    virtual bool SetImage(IBitmapS *pImg);

    virtual IBitmapS *GetImage() const;

    virtual void SetTile(BOOL bTile)
    {
        m_bTile = bTile;
    }
    virtual BOOL IsTile() const
    {
        return m_bTile;
    }

    virtual void SetVertical(BOOL bVertical)
    {
        m_bVertical = bVertical;
    }
    virtual BOOL IsVertical() const
    {
        return m_bVertical;
    }

  protected:
    virtual UINT GetExpandMode() const;

  protected:
    STDMETHOD_(void, OnInitFinished)(THIS_ IXmlNode *pNode) OVERRIDE;
    void _DrawByIndex(IRenderTarget *pRT, LPCRECT rcDraw, int iState, BYTE byAlpha) const override;
    void _Scale(ISkinObj *skinObj, int nScale) override;

    int m_nStates; // skin 状态值
    BOOL m_bTile;
    BOOL m_bAutoFit;
    BOOL m_bVertical;
    SAutoRefPtr<IBitmapS> m_imgBackup; //色调调整前的备分
    FilterLevel m_filterLevel;

  protected:
    mutable SAutoRefPtr<IBitmapS> m_pImg;
    mutable SStringW m_strSrc;
    BOOL m_bLazyLoad;

  protected:
    HRESULT OnAttrSrc(const SStringW &value, BOOL bLoading);

    SOUI_ATTRS_BEGIN()
        ATTR_CUSTOM(L"src", OnAttrSrc)
        ATTR_BOOL(L"tile", m_bTile, FALSE)         //绘制是否平铺,0--位伸（默认），其它--平铺
        ATTR_BOOL(L"autoFit", m_bAutoFit, FALSE)   // autoFit为0时不自动适应绘图区大小
        ATTR_BOOL(L"vertical", m_bVertical, FALSE) //子图是否垂直排列，0--水平排列(默认), 其它--垂直排列
        ATTR_INT(L"states", m_nStates, FALSE)      //子图数量,默认为1
        ATTR_BOOL(L"lazyLoad", m_bLazyLoad, FALSE)
        ATTR_ENUM_BEGIN(L"filterLevel", FilterLevel, FALSE)
            ATTR_ENUM_VALUE(L"none", kNone_FilterLevel)
            ATTR_ENUM_VALUE(L"low", kLow_FilterLevel)
            ATTR_ENUM_VALUE(L"medium", kMedium_FilterLevel)
            ATTR_ENUM_VALUE(L"high", kHigh_FilterLevel)
        ATTR_ENUM_END(m_filterLevel)
    SOUI_ATTRS_END()
};

class SOUI_EXP SSkinImgCenter : public SSkinImgList {
    DEF_SOBJECT(SSkinImgList, L"imgCenter")
  public:
    SSkinImgCenter()
    {
    }

  protected:
    void _DrawByIndex(IRenderTarget *pRT, LPCRECT rcDraw, int iState, BYTE byAlpha) const override;
};

//////////////////////////////////////////////////////////////////////////
class SOUI_EXP SSkinImgFrame : public SSkinImgList {
    DEF_SOBJECT(SSkinImgList, L"imgframe")

  public:
    SSkinImgFrame();

    void SetMargin(const CRect rcMargin)
    {
        m_rcMargin = rcMargin;
    }

    CRect GetMargin()
    {
        return m_rcMargin;
    }

  protected:
    UINT GetExpandMode() const override;
    void _Scale(ISkinObj *skinObj, int nScale) override;
    void _DrawByIndex(IRenderTarget *pRT, LPCRECT rcDraw, int iState, BYTE byAlpha) const override;

    CRect m_rcMargin;

    SOUI_ATTRS_BEGIN()
        ATTR_RECT(L"margin", m_rcMargin, FALSE)                          //九宫格4周
        ATTR_INT(L"left", m_rcMargin.left, FALSE)                        //九宫格左边距
        ATTR_INT(L"top", m_rcMargin.top, FALSE)                          //九宫格上边距
        ATTR_INT(L"right", m_rcMargin.right, FALSE)                      //九宫格右边距
        ATTR_INT(L"bottom", m_rcMargin.bottom, FALSE)                    //九宫格下边距
        ATTR_INT(L"margin-x", m_rcMargin.left = m_rcMargin.right, FALSE) //九宫格左右边距
        ATTR_INT(L"margin-y", m_rcMargin.top = m_rcMargin.bottom, FALSE) //九宫格上下边距
        ATTR_MARGIN(L"margin2", m_rcMargin, FALSE)
    SOUI_ATTRS_END()
};

//////////////////////////////////////////////////////////////////////////
// 加载android .9的皮肤
class SOUI_EXP SSkinImgFrame2 : public SSkinImgFrame {
    DEF_SOBJECT(SSkinImgFrame, L"imgframe2")
  public:
    SOUI_ATTRS_BEGIN()
        ATTR_CUSTOM(L"src", OnAttrSrc)
    SOUI_ATTRS_END()
  protected:
    HRESULT OnAttrSrc(const SStringW &strValue, BOOL bLoading);
};

//////////////////////////////////////////////////////////////////////////
class SOUI_EXP SSkinButton : public SSkinObjBase {
    DEF_SOBJECT(SSkinObjBase, L"button")

    enum
    {
        ST_NORMAL = 0,
        ST_HOVER,
        ST_PUSHDOWN,
        ST_DISABLE,
    };

    struct BTNCOLORS
    {
        COLORREF m_crBorder[4];

        COLORREF m_crUp[4];
        COLORREF m_crDown[4];
    };

  public:
    SSkinButton();

    STDMETHOD_(int, GetStates)(THIS) SCONST OVERRIDE;
    STDMETHOD_(ISkinObj *, Scale)(THIS_ int nScale) OVERRIDE;
    STDMETHOD_(void, OnColorize)(THIS_ COLORREF cr) OVERRIDE;

    void SetColors(COLORREF crUp[4], COLORREF crDown[4], COLORREF crBorder[4]);

  protected:
    void _DrawByIndex(IRenderTarget *pRT, LPCRECT rcDraw, int iState, BYTE byAlpha) const override;
    BTNCOLORS m_colors;
    BTNCOLORS m_colorsBackup;

    int m_nCornerRadius;
    float m_fCornerPercent; // 圆角 百分比 0.5 半圆

    SOUI_ATTRS_BEGIN()
        ATTR_COLOR(L"colorBorder", m_colors.m_crBorder[0], TRUE)             //正常 边框颜色
        ATTR_COLOR(L"colorBorderHover", m_colors.m_crBorder[1], TRUE)        //浮动 边框颜色
        ATTR_COLOR(L"colorBorderPush", m_colors.m_crBorder[2], TRUE)         //下压 边框颜色
        ATTR_COLOR(L"colorBorderDisable", m_colors.m_crBorder[3], TRUE)      //禁用 边框颜色
        ATTR_COLOR(L"colorUp", m_colors.m_crUp[ST_NORMAL], TRUE)             //正常状态渐变起始颜色
        ATTR_COLOR(L"colorDown", m_colors.m_crDown[ST_NORMAL], TRUE)         //正常状态渐变终止颜色
        ATTR_COLOR(L"colorUpHover", m_colors.m_crUp[ST_HOVER], TRUE)         //浮动状态渐变起始颜色
        ATTR_COLOR(L"colorDownHover", m_colors.m_crDown[ST_HOVER], TRUE)     //浮动状态渐变终止颜色
        ATTR_COLOR(L"colorUpPush", m_colors.m_crUp[ST_PUSHDOWN], TRUE)       //下压状态渐变起始颜色
        ATTR_COLOR(L"colorDownPush", m_colors.m_crDown[ST_PUSHDOWN], TRUE)   //下压状态渐变终止颜色
        ATTR_COLOR(L"colorUpDisable", m_colors.m_crUp[ST_DISABLE], TRUE)     //禁用状态渐变起始颜色
        ATTR_COLOR(L"colorDownDisable", m_colors.m_crDown[ST_DISABLE], TRUE) //禁用状态渐变终止颜色
        ATTR_INT(L"cornerRadius", m_nCornerRadius, TRUE)                     //圆角大小
        ATTR_FLOAT(L"cornerPercent", m_fCornerPercent, TRUE)                 // 圆角 百分比 0.5 半圆 会覆盖 cornerRadius
    SOUI_ATTRS_END()
};

//////////////////////////////////////////////////////////////////////////

class SOUI_EXP SSkinGradation : public SSkinObjBase {
    DEF_SOBJECT(SSkinObjBase, L"gradation")
  public:
    SSkinGradation();

    void SetColorFrom(COLORREF crFrom)
    {
        m_crFrom = crFrom;
    }

    void SetColorTo(COLORREF crTo)
    {
        m_crTo = crTo;
    }

    void SetVertical(BOOL bVertical)
    {
        m_bVert = bVertical;
    }

  public:
    STDMETHOD_(ISkinObj *, Scale)(THIS_ int nScale) OVERRIDE;

  protected:
    void _DrawByIndex(IRenderTarget *pRT, LPCRECT prcDraw, int iState, BYTE byAlpha) const override;

    COLORREF m_crFrom;
    COLORREF m_crTo;
    BOOL m_bVert;

    SOUI_ATTRS_BEGIN()
        ATTR_COLOR(L"colorFrom", m_crFrom, TRUE) //渐变起始颜色
        ATTR_COLOR(L"colorTo", m_crTo, TRUE)     //渐变终止颜色
        ATTR_BOOL(L"vertical", m_bVert, TRUE)    //渐变方向,0--水平, 1--垂直(默认)
    SOUI_ATTRS_END()
};

class SOUI_EXP SGradientDesc {
  public:
    SGradientDesc();

  protected:
    SAutoRefPtr<IGradient> m_gradient;
    SLayoutSize m_radius;
    float m_ratio_radius;
    GradientType m_type;
    float m_angle;
    float m_centerX;
    float m_centerY;
    BOOL m_bFullArc;

  public:
    GradientInfo GetGradientInfo(int nScale, int wid, int hei) const;
    IGradient *GetGradient()
    {
        return m_gradient;
    }

  protected:
    SOUI_ATTRS_BEGIN()
        ATTR_ENUM_BEGIN(L"type", GradientType, TRUE)
            ATTR_ENUM_VALUE(L"linear", linear)
            ATTR_ENUM_VALUE(L"radial", radial)
            ATTR_ENUM_VALUE(L"sweep", sweep)
        ATTR_ENUM_END(m_type)
        ATTR_LAYOUTSIZE(L"radius", m_radius, TRUE)
        ATTR_FLOAT(L"ratio_radius", m_ratio_radius, TRUE)
        ATTR_FLOAT(L"angle", m_angle, TRUE)
        ATTR_FLOAT(L"centerX", m_centerX, TRUE)
        ATTR_FLOAT(L"centerY", m_centerY, TRUE)
        ATTR_BOOL(L"fullArc", m_bFullArc, TRUE)
        ATTR_GRADIENT(L"gradient", m_gradient, TRUE)
        ATTR_CHAIN_PTR(m_gradient, 0)
    SOUI_ATTRS_BREAK()
};

class SOUI_EXP SSkinGradation2
    : public SSkinObjBase
    , SGradientDesc {
    DEF_SOBJECT(SSkinObjBase, L"gradation2")
  public:
    SSkinGradation2();

  public:
    STDMETHOD_(ISkinObj *, Scale)(THIS_ int nScale) OVERRIDE;
    STDMETHOD_(void, OnInitFinished)(THIS_ IXmlNode *xmlNode) OVERRIDE;

  protected:
    void _DrawByIndex(IRenderTarget *pRT, LPCRECT prcDraw, int iState, BYTE byAlpha) const override;

    SPoint m_ptCorner;
    SLayoutSize m_szCorner[2];

  public:
    SOUI_ATTRS_BEGIN()
        ATTR_SPOINT(L"ratio_corners", m_ptCorner, TRUE)
        ATTR_LAYOUTSIZE2(L"corners", m_szCorner, TRUE)
        ATTR_CHAIN_CLASS(SGradientDesc)
    SOUI_ATTRS_END()
};

//////////////////////////////////////////////////////////////////////////
//
enum SBSTATE
{
    SBST_NORMAL = 0, //正常状态
    SBST_HOVER,      // hover状态
    SBST_PUSHDOWN,   //按下状态
    SBST_DISABLE,    //禁用状态
    SBST_INACTIVE,   //失活状态,主要针对两端的箭头
};

#define MAKESBSTATE(sbCode, nState1, bVertical) MAKELONG((sbCode), MAKEWORD((nState1), (bVertical)))
#define SB_CORNOR                               10
#define SB_THUMBGRIPPER                         11 //滚动条上的可拖动部分

#define THUMB_MINSIZE 18

class SOUI_EXP SSkinScrollbar : public SSkinImgList {
    DEF_SOBJECT(SSkinImgList, L"scrollbar")

  public:
    SSkinScrollbar();

    //指示滚动条皮肤是否支持显示上下箭头
    virtual BOOL HasArrow() const
    {
        return TRUE;
    }

    virtual int GetIdealSize() const;

  protected:
    //返回源指定部分在原位图上的位置。
    virtual CRect GetPartRect(int nSbCode, int nState, BOOL bVertical) const;

  protected:
    void _DrawByIndex(IRenderTarget *pRT, LPCRECT prcDraw, int iState, BYTE byAlpha) const override
    {
    }

    void _DrawByState(IRenderTarget *pRT, LPCRECT prcDraw, DWORD dwState, BYTE byAlpha) const override;
    void _Scale(ISkinObj *skinObj, int nScale) override;

    int m_nMargin;
    BOOL m_bHasGripper;
    BOOL m_bHasInactive; //有失活状态的箭头时，滚动条皮肤有必须有5行，否则可以是3行或者4行

    SOUI_ATTRS_BEGIN()
        ATTR_INT(L"margin", m_nMargin, FALSE)           //边缘不拉伸大小
        ATTR_INT(L"hasGripper", m_bHasGripper, FALSE)   //滑块上是否有帮手(gripper)
        ATTR_INT(L"hasInactive", m_bHasInactive, FALSE) //是否有禁用态
    SOUI_ATTRS_END()
};

//////////////////////////////////////////////////////////////////////////
class SOUI_EXP SSkinColorRect : public SSkinObjBase {
    DEF_SOBJECT(SSkinObjBase, L"colorrect")
  public:
    SSkinColorRect();
    virtual ~SSkinColorRect();

    STDMETHOD_(int, GetStates)(THIS) SCONST OVERRIDE;
    STDMETHOD_(ISkinObj *, Scale)(THIS_ int nScale) OVERRIDE;

  protected:
    void _DrawByIndex(IRenderTarget *pRT, LPCRECT prcDraw, int iState, BYTE byAlpha) const override;

    SOUI_ATTRS_BEGIN()
        ATTR_COLOR(L"normal", m_crStates[0], FALSE)
        ATTR_COLOR(L"hover", m_crStates[1], FALSE)
        ATTR_COLOR(L"pushdown", m_crStates[2], FALSE)
        ATTR_COLOR(L"disable", m_crStates[3], FALSE)
        ATTR_COLOR(L"normalBorder", m_crBorders[0], FALSE)
        ATTR_COLOR(L"hoverBorder", m_crBorders[1], FALSE)
        ATTR_COLOR(L"pushdownBorder", m_crBorders[2], FALSE)
        ATTR_COLOR(L"disableBorder", m_crBorders[3], FALSE)
        ATTR_INT(L"borderWidth", m_nBorderWidth, FALSE)
        ATTR_INT(L"cornerRadius", m_nRadius, FALSE)
        ATTR_FLOAT(L"cornerPercent", m_fCornerPercent,
                   FALSE) // 圆角 百分比 0.5 半圆 会覆盖 cornerRadius
    SOUI_ATTRS_END()

  protected:
    int m_nRadius;
    float m_fCornerPercent; // 圆角 百分比 0.5 半圆
    COLORREF m_crStates[4];
    COLORREF m_crBorders[4];
    int m_nBorderWidth;
};

//////////////////////////////////////////////////////////////////////////

class SOUI_EXP SSkinShape : public SSkinObjBase {
    DEF_SOBJECT(SSkinObjBase, L"shape")
    enum Shape
    {
        rectangle,
        oval,
        ring
    };

    class SShapeSolid : public TObjRefImpl<SObject> {
        DEF_SOBJECT(TObjRefImpl<SObject>, L"solid")

      public:
        SShapeSolid()
            : m_crSolid(CR_INVALID)
        {
        }
        SOUI_ATTRS_BEGIN()
            ATTR_COLOR(L"color", m_crSolid, TRUE)
        SOUI_ATTRS_END()

        IBrushS *CreateBrush(IRenderTarget *pRT, BYTE byAlpha);

      protected:
        COLORREF m_crSolid;
    };

    class SShapeBitmap : public TObjRefImpl<SObject> {
        DEF_SOBJECT(TObjRefImpl<SObject>, L"bitmap")
      public:
        SShapeBitmap()
            : m_tileX(kRepeat_TileMode)
            , m_tileY(kRepeat_TileMode)
        {
        }
        SOUI_ATTRS_BEGIN()
            ATTR_IMAGEAUTOREF(L"src", m_pImg, TRUE)
            ATTR_ENUM_BEGIN(L"tileX", TileMode, TRUE)
                ATTR_ENUM_VALUE(L"clamp", kClamp_TileMode)
                ATTR_ENUM_VALUE(L"repeat", kRepeat_TileMode)
                ATTR_ENUM_VALUE(L"mirror", kMirror_TileMode)
            ATTR_ENUM_END(m_tileX)
            ATTR_ENUM_BEGIN(L"tileY", TileMode, TRUE)
                ATTR_ENUM_VALUE(L"clamp", kClamp_TileMode)
                ATTR_ENUM_VALUE(L"repeat", kRepeat_TileMode)
                ATTR_ENUM_VALUE(L"mirror", kMirror_TileMode)
            ATTR_ENUM_END(m_tileY)
        SOUI_ATTRS_END()

        IBrushS *CreateBrush(IRenderTarget *pRT, BYTE byAlpha);

      protected:
        SAutoRefPtr<IBitmapS> m_pImg;
        TileMode m_tileX, m_tileY;
    };

    class SGradientBrush
        : public TObjRefImpl<SObject>
        , SGradientDesc {
        DEF_SOBJECT(TObjRefImpl<SObject>, L"gradient")
      public:
        SGradientBrush()
        {
        }

        IBrushS *CreateBrush(IRenderTarget *pRT, int nScale, BYTE byAlpha, int wid, int hei) const;

        STDMETHOD_(void, OnInitFinished)(THIS_ IXmlNode *xmlNode) override;

      public:
        SOUI_ATTRS_BEGIN()
            ATTR_CHAIN_CLASS(SGradientDesc)
        SOUI_ATTRS_END()
    };

    class SStroke : public TObjRefImpl<SObject> {
        DEF_SOBJECT(TObjRefImpl<SObject>, L"stroke")
      public:
        SStroke();

        SOUI_ATTRS_BEGIN()
            ATTR_LAYOUTSIZE(L"width", m_width, TRUE)
            ATTR_COLOR(L"color", m_color, TRUE)
            ATTR_ENUM_BEGIN(L"style", int, TRUE)
                ATTR_ENUM_VALUE(L"solid", PS_SOLID)
                ATTR_ENUM_VALUE(L"dash", PS_DASH)
                ATTR_ENUM_VALUE(L"dashDot", PS_DASHDOT)
                ATTR_ENUM_VALUE(L"dashDotDot", PS_DASHDOTDOT)
            ATTR_ENUM_END(m_style)

            ATTR_ENUM_BEGIN(L"endStyle", int, TRUE)
                ATTR_ENUM_VALUE(L"flat", PS_ENDCAP_FLAT)
                ATTR_ENUM_VALUE(L"round", PS_ENDCAP_ROUND)
                ATTR_ENUM_VALUE(L"square", PS_ENDCAP_SQUARE)
            ATTR_ENUM_END(m_endStyle)
            ATTR_ENUM_BEGIN(L"joinStyle", int, TRUE)
                ATTR_ENUM_VALUE(L"round", PS_JOIN_ROUND)
                ATTR_ENUM_VALUE(L"bevel", PS_JOIN_BEVEL)
                ATTR_ENUM_VALUE(L"miter", PS_JOIN_MITER)
            ATTR_ENUM_END(m_joinStyle)
        SOUI_ATTRS_END()
      public:
        SLayoutSize m_width; //描边的宽度
        COLORREF m_color;    //描边的颜色

        int GetStyle() const;

      private:
        int m_style; //线型
        int m_endStyle;
        int m_joinStyle;
    };

    class SCornerSize : public TObjRefImpl<SObject> {
        DEF_SOBJECT(TObjRefImpl<SObject>, L"corners")

      public:
        HRESULT OnAttrRadius(const SStringW strValue, BOOL bLoading);

        SOUI_ATTRS_BEGIN()
            ATTR_CUSTOM(L"radius", OnAttrRadius)
            ATTR_LAYOUTSIZE(L"radiusX", m_radiusX, TRUE)
            ATTR_LAYOUTSIZE(L"radiusY", m_radiusY, TRUE)
        SOUI_ATTRS_END()

        POINT GetConner(int nScale) const
        {
            return CPoint(m_radiusX.toPixelSize(nScale), m_radiusY.toPixelSize(nScale));
        }

        SLayoutSize m_radiusX, m_radiusY;
    };

    class SRatioCornerSize : public TObjRefImpl<SObject> {
        DEF_SOBJECT(TObjRefImpl<SObject>, L"ratio_corners")

      public:
        SRatioCornerSize()
        {
            m_radius.fX = m_radius.fY = 0.0f;
        }
        HRESULT OnAttrRadius(const SStringW strValue, BOOL bLoading);

        SOUI_ATTRS_BEGIN()
            ATTR_CUSTOM(L"radius", OnAttrRadius)
            ATTR_FLOAT(L"radiusX", m_radius.fX, TRUE)
            ATTR_FLOAT(L"radiusY", m_radius.fY, TRUE)
        SOUI_ATTRS_END()

        POINT GetConner(const CRect &rc) const
        {
            return CPoint((int)(rc.Width() / 2 * m_radius.fX), (int)(rc.Height() / 2 * m_radius.fY));
        }

        SPoint m_radius; // range from [0,1]
    };

    class SShapeSize : public TObjRefImpl<SObject> {
        DEF_SOBJECT(TObjRefImpl<SObject>, L"size")

      public:
        SOUI_ATTRS_BEGIN()
            ATTR_LAYOUTSIZE(L"width", m_width, TRUE)
            ATTR_LAYOUTSIZE(L"height", m_height, TRUE)
        SOUI_ATTRS_END()

        SLayoutSize m_width, m_height;
    };

    class SShapeRing : public TObjRefImpl<SObject> {
        DEF_SOBJECT(TObjRefImpl<SObject>, L"ring")

      public:
        SShapeRing()
            : m_startAngle(0.0f)
            , m_sweepAngle(360.0f)
        {
        }

        SOUI_ATTRS_BEGIN()
            ATTR_FLOAT(L"startAngle", m_startAngle, TRUE)
            ATTR_FLOAT(L"sweepAngle", m_sweepAngle, TRUE)
        SOUI_ATTRS_END()

        float m_startAngle;
        float m_sweepAngle;
    };

  public:
    SSkinShape();

    STDMETHOD_(SIZE, GetSkinSize)(THIS) SCONST OVERRIDE;
    STDMETHOD_(int, GetStates)(THIS) SCONST OVERRIDE;

    SOUI_ATTRS_BEGIN()
        ATTR_ENUM_BEGIN(L"shape", Shape, TRUE)
            ATTR_ENUM_VALUE(L"rectangle", rectangle)
            ATTR_ENUM_VALUE(L"oval", oval)
            ATTR_ENUM_VALUE(L"ring", ring)
        ATTR_ENUM_END(m_shape)
    SOUI_ATTRS_END()
  protected:
    STDMETHOD_(void, OnInitFinished)(THIS_ IXmlNode *pNode) OVERRIDE;

    void _DrawByIndex(IRenderTarget *pRT, LPCRECT rcDraw, int iState, BYTE byAlpha) const override;

    void _Scale(ISkinObj *pObj, int nScale) override;
    POINT GetCornerSize(const CRect &rc) const;

    Shape m_shape;

    SAutoRefPtr<SShapeSolid> m_solid;
    SAutoRefPtr<SShapeBitmap> m_bitmap;
    SAutoRefPtr<SGradientBrush> m_gradient;
    SAutoRefPtr<SShapeSize> m_shapeSize;
    SAutoRefPtr<SCornerSize> m_cornerSize;
    SAutoRefPtr<SRatioCornerSize> m_ratioCornerSize;
    SAutoRefPtr<SStroke> m_stroke;
    SAutoRefPtr<SShapeRing> m_ringParam;
};

class SOUI_EXP SSKinGroup : public SSkinObjBase {
    DEF_SOBJECT(SSkinObjBase, L"group")
  public:
    STDMETHOD_(SIZE, GetSkinSize)(CTHIS) SCONST OVERRIDE;
    STDMETHOD_(int, GetStates)(CTHIS) SCONST OVERRIDE;

    SOUI_ATTRS_BEGIN()
        ATTR_SKIN(L"normal", m_skins[0], FALSE)
        ATTR_SKIN(L"hover", m_skins[1], FALSE)
        ATTR_SKIN(L"pushDown", m_skins[2], FALSE)
        ATTR_SKIN(L"disable", m_skins[3], FALSE)
    SOUI_ATTRS_END()

  protected:
    void _DrawByIndex(IRenderTarget *pRT, LPCRECT rcDraw, int iState, BYTE byAlpha) const override;
    void _Scale(ISkinObj *skinObj, int nScale) override;
    SAutoRefPtr<ISkinObj> m_skins[4];
};

SNSEND
#endif // __SSKIN__H__