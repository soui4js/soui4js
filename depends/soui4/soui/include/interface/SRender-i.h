﻿#ifndef __SRENDER_I__H__
#define __SRENDER_I__H__

#include <interface/obj-ref-i.h>
#include <interface/sobject-i.h>
#include <interface/SPathEffect-i.h>
#include <interface/SImgDecoder-i.h>
#include <interface/sxml-i.h>

SNSBEGIN

typedef struct IRenderFactory IRenderFactory;

typedef enum EXPEND_MODE
{
    EM_NULL = 0, /*<不变*/
    EM_STRETCH,  /*<拉伸*/
    EM_TILE,     /*<平铺*/
} EXPEND_MODE;

typedef enum FilterLevel
{
    kUndef_FilterLevel = 100, // don't use -1 as filter level will pass to render in word and will get 65535
    kNone_FilterLevel = 0,
    kLow_FilterLevel,
    kMedium_FilterLevel,
    kHigh_FilterLevel
} FilterLevel;

typedef enum GradientType
{
    linear = 0, /*<线性渐变*/
    radial,     /*<辐射渐变*/
    sweep       /*<扫描渐变*/
} GradientType;

typedef enum RopMode
{
    kClear_Mode,    //!< [0, 0]
    kSrc_Mode,      //!< [Sa, Sc]
    kDst_Mode,      //!< [Da, Dc]
    kSrcOver_Mode,  //!< [Sa + Da - Sa*Da, Rc = Sc + (1 - Sa)*Dc]
    kDstOver_Mode,  //!< [Sa + Da - Sa*Da, Rc = Dc + (1 - Da)*Sc]
    kSrcIn_Mode,    //!< [Sa * Da, Sc * Da]
    kDstIn_Mode,    //!< [Sa * Da, Sa * Dc]
    kSrcOut_Mode,   //!< [Sa * (1 - Da), Sc * (1 - Da)]
    kDstOut_Mode,   //!< [Da * (1 - Sa), Dc * (1 - Sa)]
    kSrcATop_Mode,  //!< [Da, Sc * Da + (1 - Sa) * Dc]
    kDstATop_Mode,  //!< [Sa, Sa * Dc + Sc * (1 - Da)]
    kXor_Mode,      //!< [Sa + Da - 2 * Sa * Da, Sc * (1 - Da) + (1 - Sa) * Dc]
    kPlus_Mode,     //!< [Sa + Da, Sc + Dc]
    kModulate_Mode, // multiplies all components (= alpha and color)

    // Following blend modes are defined in the CSS Compositing standard:
    // https://dvcs.w3.org/hg/FXTF/rawfile/tip/compositing/index.html#blending
    kScreen_Mode,
    kLastCoeffMode = kScreen_Mode,

    kOverlay_Mode,
    kDarken_Mode,
    kLighten_Mode,
    kColorDodge_Mode,
    kColorBurn_Mode,
    kHardLight_Mode,
    kSoftLight_Mode,
    kDifference_Mode,
    kExclusion_Mode,
    kMultiply_Mode,
    kLastSeparableMode = kMultiply_Mode,

    kHue_Mode,
    kSaturation_Mode,
    kColor_Mode,
    kLuminosity_Mode,

    // extend xfermode
    kSrcCopy = SRCCOPY,
    kDstInvert = DSTINVERT,
    kSrcInvert = SRCINVERT,
    kSrcAnd = SRCAND,
} RopMode;

typedef struct fPoint
{
    float fX, fY;
} fPoint;

typedef struct fRect
{
    float fLeft, fTop, fRight, fBottom;
} fRect;

typedef enum _BlurStyle
{
    kNone_BLurStyle = -1,
    kNormal_BlurStyle = 0, //!< fuzzy inside and outside
    kSolid_BlurStyle,      //!< solid inside, fuzzy outside
    kOuter_BlurStyle,      //!< nothing inside, fuzzy outside
    kInner_BlurStyle,      //!< fuzzy inside, nothing outside

    kLastEnum_BlurStyle = kInner_BlurStyle
} BlurStyle;

typedef enum _BlurFlags
{
    kNone_BlurFlag = 0x00,
    /** The blur layer's radius is not affected by transforms */
    kIgnoreTransform_BlurFlag = 0x01,
    /** Use a smother, higher qulity blur algorithm */
    kHighQuality_BlurFlag = 0x02,
    /** mask for all blur flags */
    kAll_BlurFlag = 0x03
} BlurFlags;

#undef INTERFACE
#define INTERFACE IMaskFilter
DECLARE_INTERFACE_(IMaskFilter, IObjRef)
{
    STDMETHOD_(void *, GetPtr)(THIS) PURE;
};

typedef enum _OBJTYPE
{
    OT_NULL = 0,
    OT_PEN,
    OT_BRUSH,
    OT_BITMAP,
    OT_FONT,
    OT_RGN,
    OT_PATH,
} OBJTYPE;

/**
 * @struct     IRenderObj
 * @brief      渲染对象基类
 *
 * Describe    所有渲染对象全部使用引用计数管理生命周期
 */
#undef INTERFACE
#define INTERFACE IRenderObj
DECLARE_INTERFACE_(IRenderObj, IObjRef)
{
    //!添加引用
    /*!
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    //!释放引用
    /*!
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    //!释放对象
    /*!
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    /**
     * GetRenderFactory
     * @brief    获得创建该渲染对象的类厂
     * @return   IRenderFactory * -- 类厂
     * Describe
     */
    STDMETHOD_(IRenderFactory *, GetRenderFactory)(CTHIS) SCONST PURE;

    /**
     * ObjectType
     * @brief    查询对象类型
     * @return   const UINT
     * Describe
     */
    STDMETHOD_(OBJTYPE, ObjectType)(CTHIS) SCONST PURE;
};

typedef enum _BrushType
{
    Brush_Color = 0, //颜色画刷
    Brush_Bitmap,    //位图画刷
    Brush_Shader,    //渐变画刷
} BrushType;

typedef enum _TileMode
{
    /** replicate the edge color if the shader draws outside of its
     *  original bounds
     */
    kClamp_TileMode = 0,

    /** repeat the shader's image horizontally and vertically */
    kRepeat_TileMode,

    /** repeat the shader's image horizontally and vertically, alternating
     *  mirror images so that adjacent images always seam
     */
    kMirror_TileMode,
} TileMode;

/**
 * @struct     IBrush
 * @brief      画刷对象
 *
 * Describe
 */
#undef INTERFACE
#define INTERFACE IBrushS
DECLARE_INTERFACE_(IBrushS, IRenderObj)
{
    //!添加引用
    /*!
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    //!释放引用
    /*!
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    //!释放对象
    /*!
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    /**
     * GetRenderFactory
     * @brief    获得创建该渲染对象的类厂
     * @return   IRenderFactory * -- 类厂
     * Describe
     */
    STDMETHOD_(IRenderFactory *, GetRenderFactory)(CTHIS) SCONST PURE;

    /**
     * ObjectType
     * @brief    查询对象类型
     * @return   OBJTYPE
     * Describe
     */
    STDMETHOD_(OBJTYPE, ObjectType)(CTHIS) SCONST PURE;

    /**
     * ObjectType
     * @brief    查询画刷类型
     * @return   BrushType
     * Describe
     */
    STDMETHOD_(BrushType, GetBrushType)(CTHIS) SCONST PURE;
};

/**
 * @struct     IPen
 * @brief      画笔对象
 *
 * Describe
 */
#undef INTERFACE
#define INTERFACE IPenS
DECLARE_INTERFACE_(IPenS, IRenderObj)
{
    //!添加引用
    /*!
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    //!释放引用
    /*!
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    //!释放对象
    /*!
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    /**
     * GetRenderFactory
     * @brief    获得创建该渲染对象的类厂
     * @return   IRenderFactory * -- 类厂
     * Describe
     */
    STDMETHOD_(IRenderFactory *, GetRenderFactory)(CTHIS) SCONST PURE;

    /**
     * ObjectType
     * @brief    查询对象类型
     * @return   OBJTYPE
     * Describe
     */
    STDMETHOD_(OBJTYPE, ObjectType)(CTHIS) SCONST PURE;

    STDMETHOD_(int, GetWidth)(CTHIS) SCONST PURE;

    STDMETHOD_(void, SetWidth)(THIS_ int nWid) PURE;

    STDMETHOD_(int, GetStyle)(CTHIS) SCONST PURE;

    STDMETHOD_(void, SetStyle)(THIS_ int nStyle) PURE;

    STDMETHOD_(COLORREF, GetColor)(CTHIS) SCONST PURE;

    STDMETHOD_(void, SetColor)(THIS_ COLORREF cr) PURE;
};

/**
 * @struct     IBitmap
 * @brief      位图对象
 *
 * Describe
 */
#undef INTERFACE
#define INTERFACE IBitmapS
DECLARE_INTERFACE_(IBitmapS, IRenderObj)
{
    //!添加引用
    /*!
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    //!释放引用
    /*!
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    //!释放对象
    /*!
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    /**
     * GetRenderFactory
     * @brief    获得创建该渲染对象的类厂
     * @return   IRenderFactory * -- 类厂
     * Describe
     */
    STDMETHOD_(IRenderFactory *, GetRenderFactory)(CTHIS) SCONST PURE;

    /**
     * ObjectType
     * @brief    查询对象类型
     * @return   OBJTYPE
     * Describe
     */
    STDMETHOD_(OBJTYPE, ObjectType)(CTHIS) SCONST PURE;

    /**
     * Init
     * @brief    从32位的位图数据初始化IBitmap
     * @param    int nWid --  图片宽度
     * @param    int nHei --  图片高度
     * @param    const LPVOID pBits --  位图数据,以ARGB形式存储
     * @return   HRESULT -- 成功返回S_OK,失败返回错误代码
     * Describe
     */
    STDMETHOD_(HRESULT, Init)(THIS_ int nWid, int nHei, const LPVOID pBits) PURE;

    /**
     * Init2
     * @brief    从IImgFrame初始化位图
     * @param    IImgFrame * pImgFrame --  IImgFrame指针
     * @return   HRESULT -- 成功返回S_OK,失败返回错误代码
     * Describe
     */
    STDMETHOD_(HRESULT, Init2)(THIS_ IImgFrame * pImgFrame) PURE;

    /**
     * LoadFromFile
     * @brief    从文件中加载位图
     * @param    LPCTSTR pszFileName --  文件名
     * @return   HRESULT -- 成功返回S_OK,失败返回错误代码
     * Describe
     */
    STDMETHOD_(HRESULT, LoadFromFile)(THIS_ LPCTSTR pszFileName) PURE;

    /**
     * LoadFromMemory
     * @brief    从内存中加载位图
     * @param    LPBYTE pBuf --  内存地址
     * @param    size_t szLen --  内存大小
     * @return   HRESULT -- 成功返回S_OK,失败返回错误代码
     * Describe
     */
    STDMETHOD_(HRESULT, LoadFromMemory)(THIS_ LPBYTE pBuf, size_t szLen) PURE;

    /**
     * Width
     * @brief    获得图片宽度
     * @return   UINT -- 图片宽度
     * Describe
     */
    STDMETHOD_(UINT, Width)(CTHIS) SCONST PURE;

    /**
     * Height
     * @brief    获得图片高度
     * @return   UINT -- 图片高度
     * Describe
     */
    STDMETHOD_(UINT, Height)(CTHIS) SCONST PURE;

    /**
     * Size
     * @brief    获得图片高度及宽度
     * @return   SIZE -- 图片高度及宽度
     * Describe
     */
    STDMETHOD_(SIZE, Size)(CTHIS) SCONST PURE;

    /**
     * LockPixelBits
     * @brief    锁定位图的数据
     * @return   LPVOID -- 位图数据地址
     * Describe
     */
    STDMETHOD_(LPVOID, LockPixelBits)(THIS) PURE;

    /**
     * UnlockPixelBits
     * @brief    解除数据锁定
     * @param    LPVOID --  由LockPixelBits返回的位图数据地址
     * @return   void
     * Describe  与LockPixelBits配对使用
     */
    STDMETHOD_(void, UnlockPixelBits)(THIS_ LPVOID pBuf) PURE;

    /**
     * GetPixelBits
     * @brief    以只读方式获取位图数据
     * @return   LPVOID -- 位图数据地址
     * Describe
     */
    STDMETHOD_(const LPVOID, GetPixelBits)(CTHIS) SCONST PURE;

    /**
     * Clone
     * @brief    克隆一个新位图对象
     * @param    IBitmap **ppClone --  返回的IBitmap* 对象
     * @return   HRESULT
     * Describe  成功后，调用者执行IBitmap::Release
     */
    STDMETHOD_(HRESULT, Clone)(CTHIS_ IBitmapS * *ppClone) SCONST PURE;

    /**
     * Scale
     * @brief    缩放克隆一个新位图对象
     * @param    IBitmap **pOutput --  返回的IBitmap* 对象
     * @param	 int nScale -- 缩放比例, 100代表不缩放
     * @param    FilterLevel filterLevel--插值算法,render-skia支持选择算法
     * @return   HRESULT
     * Describe  成功后，调用者执行IBitmap::Release
     */
    STDMETHOD_(HRESULT, Scale)
    (CTHIS_ IBitmapS * *pOutput, int nScale, FilterLevel filterLevel) SCONST PURE;

    /**
     * Scale
     * @brief    缩放克隆一个新位图对象
     * @param    IBitmap **pOutput --  返回的IBitmap* 对象
     * @param	 int nWid -- 宽度
     * @param	 int nHei -- 高度
     * @param    FilterLevel filterLevel--插值算法,render-skia支持选择算法
     * @return   HRESULT
     * Describe  成功后，调用者执行IBitmap::Release
     */
    STDMETHOD_(HRESULT, Scale2)
    (CTHIS_ IBitmapS * *pOutput, int nWid, int nHei, FilterLevel filterLevel) SCONST PURE;

    /**
     * 将位图保存到文件
     * @brief    Save
     * @param    LPCWSTR pszFileName --  File name
     * @param    const LPVOID *pFormat --  image format
     * @return   HRESULT -- S_OK: succeed
     * Describe
     */
    STDMETHOD_(HRESULT, Save)(CTHIS_ LPCWSTR pszFileName, const LPVOID pFormat) SCONST PURE;

    STDMETHOD_(HRESULT, Save2)(CTHIS_ LPCWSTR pszFileName, ImgFmt imgFmt) SCONST PURE;
};

typedef IBitmapS *IBitmapPtr;

typedef enum _FillStyle
{
    kFill_Style = 0,
    kStroke_Style = 1,
    kStrokeAndFill_Style = 2,
} FillStyle;
/**
 * @struct     IFont
 * @brief      字体对象
 *
 * Describe
 */
#undef INTERFACE
#define INTERFACE IFontS
DECLARE_INTERFACE_(IFontS, IRenderObj)
{
    //!添加引用
    /*!
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    //!释放引用
    /*!
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    //!释放对象
    /*!
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    /**
     * GetRenderFactory
     * @brief    获得创建该渲染对象的类厂
     * @return   IRenderFactory * -- 类厂
     * Describe
     */
    STDMETHOD_(IRenderFactory *, GetRenderFactory)(CTHIS) SCONST PURE;

    /**
     * ObjectType
     * @brief    查询对象类型
     * @return   const UINT
     * Describe
     */
    STDMETHOD_(OBJTYPE, ObjectType)(CTHIS) SCONST PURE;

    /**
     * LogFont
     * @brief    获得字体的LOGFONT
     * @return   const LOGFONT * -- 包含字体信息的LOGFONT*
     * Describe
     */
    STDMETHOD_(const LOGFONT *, LogFont)(CTHIS) SCONST PURE;

    /**
     * FamilyName
     * @brief    获取字体名
     * @return   LPCTSTR -- 字体名
     * Describe
     */
    STDMETHOD_(LPCTSTR, FamilyName)(CTHIS) SCONST PURE;

    /**
     * TextSize
     * @brief    获取字体大小
     * @return   int -- 字体大小
     * Describe
     */
    STDMETHOD_(int, TextSize)(CTHIS) SCONST PURE;

    /**
     * IsBold
     * @brief    查询是否为粗体
     * @return   BOOL -- true为粗体，false正常
     * Describe
     */
    STDMETHOD_(BOOL, IsBold)(CTHIS) SCONST PURE;

    /**
     * IsUnderline
     * @brief    查询字体下划线状态
     * @return   BOOL -- true有下划线，false正常
     * Describe
     */
    STDMETHOD_(BOOL, IsUnderline)(CTHIS) SCONST PURE;

    /**
     * IsItalic
     * @brief    查询字体的斜体状态
     * @return   BOOL -- true为斜体，false正常
     * Describe
     */
    STDMETHOD_(BOOL, IsItalic)(CTHIS) SCONST PURE;

    /**
     * StrikeOut
     * @brief    查询字体的删除线状态
     * @return   BOOL -- true有删除线
     * Describe
     */
    STDMETHOD_(BOOL, IsStrikeOut)(CTHIS) SCONST PURE;

    STDMETHOD_(BOOL, UpdateFont)(THIS_ const LOGFONT *pLogFont) PURE;

    STDMETHOD_(void, SetProp)(THIS_ IXmlNode * pXmlNode) PURE;
};

/**
 * @struct     IRegion
 * @brief      Region对象
 *
 * Describe
 */
#undef INTERFACE
#define INTERFACE IRegionS
DECLARE_INTERFACE_(IRegionS, IRenderObj)
{
    //!添加引用
    /*!
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    //!释放引用
    /*!
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    //!释放对象
    /*!
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    /**
     * GetRenderFactory
     * @brief    获得创建该渲染对象的类厂
     * @return   IRenderFactory * -- 类厂
     * Describe
     */
    STDMETHOD_(IRenderFactory *, GetRenderFactory)(CTHIS) SCONST PURE;

    /**
     * ObjectType
     * @brief    查询对象类型
     * @return   const UINT
     * Describe
     */
    STDMETHOD_(OBJTYPE, ObjectType)(CTHIS) SCONST PURE;

    /**
     * CombineRect
     * @brief    将一个矩形与this组合
     * @param    LPCRECT lprect --  要组合的矩形
     * @param    int nCombineMode --  组合模式
     * @return   void
     * Describe  组合模式同Win32 API CombineRect
     */
    STDMETHOD_(void, CombineRect)(THIS_ LPCRECT lprect, int nCombineMode) PURE;

    /**
     * CombineRect
     * @brief    将一个矩形与this组合
     * @param    const IRegion * pRgnSrc --  要组合的Region
     * @param    int nCombineMode --  组合模式
     * @return   void
     * Describe  组合模式同Win32 API CombineRgn
     */
    STDMETHOD_(void, CombineRgn)(THIS_ const IRegionS *pRgnSrc, int nCombineMode) PURE;

    STDMETHOD_(void, CombineRoundRect)(THIS_ LPCRECT lprect, POINT ptConner, int nCombineMode) PURE;

    STDMETHOD_(void, CombineEllipse)(THIS_ LPCRECT lprect, int nCombineMode) PURE;

    STDMETHOD_(void, CombinePolygon)
    (THIS_ const POINT *pts, int count, int nPolygonMode, int nCombineMode) PURE;
    /**
     * PtInRegion
     * @brief    检测一个点是否在region范围内
     * @param    POINT pt --  被检测的点
     * @return   BOOL -- true在region内
     * Describe
     */
    STDMETHOD_(BOOL, PtInRegion)(CTHIS_ POINT pt) SCONST PURE;

    /**
     * RectInRegion
     * @brief    检测一个矩形是否与this相交
     * @param    LPCRECT lprect --  被检测的的矩形。
     * @return   BOOL -- true在region内
     * Describe
     */
    STDMETHOD_(BOOL, RectInRegion)(CTHIS_ LPCRECT lprect) SCONST PURE;

    /**
     * GetRgnBox
     * @brief    获得this的外包矩形
     * @param [out] LPRECT lprect --  外包矩形
     * @return   void
     * Describe
     */
    STDMETHOD_(void, GetRgnBox)(CTHIS_ LPRECT lprect) SCONST PURE;

    /**
     * IsEmpty
     * @brief    查询region是否为空
     * @return   BOOL -- true为空
     * Describe
     */
    STDMETHOD_(BOOL, IsEmpty)(CTHIS) SCONST PURE;

    /**
     * Offset
     * @brief    将this整体平移
     * @param    POINT pt --  平移在x,y方向的的位移
     * @return   void
     * Describe
     */
    STDMETHOD_(void, Offset)(THIS_ POINT pt) PURE;

    /**
     * Clear
     * @brief    清空region
     * @return   void
     * Describe
     */
    STDMETHOD_(void, Clear)(THIS) PURE;
};

typedef enum _xFormIndex
{
    kMScaleX = 0,
    kMSkewX,
    kMTransX,
    kMSkewY,
    kMScaleY,
    kMTransY,
    kMPersp0,
    kMPersp1,
    kMPersp2,
    kMCount,
} xFormIndex;

typedef struct _IxForm
{
    float fMat[kMCount];
} IxForm;

typedef enum _FillType
{
    /** Specifies that "inside" is computed by a non-zero sum of signed
    edge crossings
    */
    kWinding_FillType,
    /** Specifies that "inside" is computed by an odd number of edge
    crossings
    */
    kEvenOdd_FillType,
    /** Same as Winding, but draws outside of the path, rather than inside
     */
    kInverseWinding_FillType,
    /** Same as EvenOdd, but draws outside of the path, rather than inside
     */
    kInverseEvenOdd_FillType
} FillType;

typedef enum _Direction
{
    /** Direction either has not been or could not be computed */
    kUnknown_Direction,
    /** clockwise direction for adding closed contours */
    kCW_Direction,
    /** counter-clockwise direction for adding closed contours */
    kCCW_Direction,
} Direction;

#undef INTERFACE
#define INTERFACE IPathS
DECLARE_INTERFACE_(IPathS, IRenderObj)
{
    //!添加引用
    /*!
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    //!释放引用
    /*!
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    //!释放对象
    /*!
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    /**
     * GetRenderFactory
     * @brief    获得创建该渲染对象的类厂
     * @return   IRenderFactory * -- 类厂
     * Describe
     */
    STDMETHOD_(IRenderFactory *, GetRenderFactory)(CTHIS) SCONST PURE;

    /**
     * ObjectType
     * @brief    查询对象类型
     * @return   const UINT
     * Describe
     */
    STDMETHOD_(OBJTYPE, ObjectType)(CTHIS) SCONST PURE;

    /** Return the path's fill type. This is used to define how "inside" is
    computed. The default value is kWinding_FillType.

    @return the path's fill type
    */
    STDMETHOD_(FillType, getFillType)(CTHIS) SCONST PURE;

    /** Set the path's fill type. This is used to define how "inside" is
    computed. The default value is kWinding_FillType.

    @param ft The new fill type for this path
    */
    STDMETHOD_(void, setFillType)(THIS_ FillType ft) PURE;

    /** Clear any lines and curves from the path, making it empty. This frees up
    internal storage associated with those segments.
    On Android, does not change fSourcePath.
    */
    STDMETHOD_(void, reset)(THIS) PURE;

    /** Returns true if the path is empty (contains no lines or curves)

    @return true if the path is empty (contains no lines or curves)
    */
    STDMETHOD_(BOOL, isEmpty)(CTHIS) SCONST PURE;

    /** Returns the bounds of the path's points. If the path contains 0 or 1
    points, the bounds is set to (0,0,0,0), and isEmpty() will return true.
    Note: this bounds may be larger than the actual shape, since curves
    do not extend as far as their control points.
    */
    STDMETHOD_(void, getBounds)(CTHIS_ LPRECT prc) SCONST PURE;

    //  Construction methods

    /** Set the beginning of the next contour to the point (x,y).

    @param x    The x-coordinate of the start of a new contour
    @param y    The y-coordinate of the start of a new contour
    */
    STDMETHOD_(void, moveTo)(THIS_ float x, float y) PURE;

    /** Set the beginning of the next contour relative to the last point on the
    previous contour. If there is no previous contour, this is treated the
    same as moveTo().

    @param dx   The amount to add to the x-coordinate of the end of the
    previous contour, to specify the start of a new contour
    @param dy   The amount to add to the y-coordinate of the end of the
    previous contour, to specify the start of a new contour
    */
    STDMETHOD_(void, rMoveTo)(THIS_ float dx, float dy) PURE;

    /** Add a line from the last point to the specified point (x,y). If no
    moveTo() call has been made for this contour, the first point is
    automatically set to (0,0).

    @param x    The x-coordinate of the end of a line
    @param y    The y-coordinate of the end of a line
    */
    STDMETHOD_(void, lineTo)(THIS_ float x, float y) PURE;

    /** Same as lineTo, but the coordinates are considered relative to the last
    point on this contour. If there is no previous point, then a moveTo(0,0)
    is inserted automatically.
        virtual void SetMaskFilter(IMaskFilter *pMaskFilter) = 0;
        virtual IMaskFilter *GetMaskFilter() = 0;
    @param dx   The amount to add to the x-coordinate of the previous point
    on this contour, to specify a line
    @param dy   The amount to add to the y-coordinate of the previous point
    on this contour, to specify a line
    */
    STDMETHOD_(void, rLineTo)(THIS_ float dx, float dy) PURE;

    /** Add a quadratic bezier from the last point, approaching control point
    (x1,y1), and ending at (x2,y2). If no moveTo() call has been made for
    this contour, the first point is automatically set to (0,0).
        virtual void SetMaskFilter(IMaskFilter *pMaskFilter) = 0;
        virtual IMaskFilter *GetMaskFilter() = 0;
    @param x1   The x-coordinate of the control point on a quadratic curve
    @param y1   The y-coordinate of the control point on a quadratic curve
    @param x2   The x-coordinate of the end point on a quadratic curve
    @param y2   The y-coordinate of the end point on a quadratic curve
    */
    STDMETHOD_(void, quadTo)(THIS_ float x1, float y1, float x2, float y2) PURE;

    /** Same as quadTo, but the coordinates are considered relative to the last
    point on this contour. If there is no previous point, then a moveTo(0,0)
    is inserted automatically.

    @param dx1   The amount to add to the x-coordinate of the last point on
    this contour, to specify the control point of a quadratic curve
    @param dy1   The amount to add to the y-coordinate of the last point on
    this contour, to specify the control point of a quadratic curve
    @param dx2   The amount to add to the x-coordinate of the last point on
    this contour, to specify the end point of a quadratic curve
    @param dy2   The amount to add to the y-coordinate of the last point on
    this contour, to specify the end point of a quadratic curve
    */
    STDMETHOD_(void, rQuadTo)(THIS_ float dx1, float dy1, float dx2, float dy2) PURE;

    STDMETHOD_(void, conicTo)(THIS_ float x1, float y1, float x2, float y2, float w) PURE;
    STDMETHOD_(void, rConicTo)(THIS_ float dx1, float dy1, float dx2, float dy2, float w) PURE;

    /** Add a cubic bezier from the last point, approaching control points
    (x1,y1) and (x2,y2), and ending at (x3,y3). If no moveTo() call has been
    made for this contour, the first point is automatically set to (0,0).

    @param x1   The x-coordinate of the 1st control point on a cubic curve
    @param y1   The y-coordinate of the 1st control point on a cubic curve
    @param x2   The x-coordinate of the 2nd control point on a cubic curve
    @param y2   The y-coordinate of the 2nd control point on a cubic curve
    @param x3   The x-coordinate of the end point on a cubic curve
    @param y3   The y-coordinate of the end point on a cubic curve
    */
    STDMETHOD_(void, cubicTo)
    (THIS_ float x1, float y1, float x2, float y2, float x3, float y3) PURE;

    /** Same as cubicTo, but the coordinates are considered relative to the
    current point on this contour. If there is no previous point, then a
    moveTo(0,0) is inserted automatically.

    @param dx1   The amount to add to the x-coordinate of the last point on
    this contour, to specify the 1st control point of a cubic curve
    @param dy1   The amount to add to the y-coordinate of the last point on
    this contour, to specify the 1st control point of a cubic curve
    @param dx2   The amount to add to the x-coordinate of the last point on
    this contour, to specify the 2nd control point of a cubic curve
    @param dy2   The amount to add to the y-coordinate of the last point on
    this contour, to specify the 2nd control point of a cubic curve
    @param dx3   The amount to add to the x-coordinate of the last point on
    this contour, to specify the end point of a cubic curve
    @param dy3   The amount to add to the y-coordinate of the last point on
    this contour, to specify the end point of a cubic curve
    */
    STDMETHOD_(void, rCubicTo)
    (THIS_ float x1, float y1, float x2, float y2, float x3, float y3) PURE;

    /**
     *  Add a closed rectangle contour to the path
     *  @param rect The rectangle to add as a closed contour to the path
     *  @param dir  The direction to wind the rectangle's contour. Cannot be
     *              kUnknown_Direction.
     */
    STDMETHOD_(void, addRect)(THIS_ const RECT *rect, Direction dir DEF_VAL(kCW_Direction)) PURE;

    /**
     *  Add a closed rectangle contour to the path
     *
     *  @param left     The left side of a rectangle to add as a closed contour
     *                  to the path
     *  @param top      The top of a rectangle to add as a closed contour to the
     *                  path
     *  @param right    The right side of a rectangle to add as a closed contour
     *                  to the path
     *  @param bottom   The bottom of a rectangle to add as a closed contour to
     *                  the path
     *  @param dir  The direction to wind the rectangle's contour. Cannot be
     *              kUnknown_Direction.
     */
    STDMETHOD_(void, addRect2)
    (THIS_ float left, float top, float right, float bottom, Direction dir DEF_VAL(kCW_Direction)) PURE;

    /**
     *  Add a closed oval contour to the path
     *
     *  @param oval The bounding oval to add as a closed contour to the path
     *  @param dir  The direction to wind the oval's contour. Cannot be
     *              kUnknown_Direction.
     */
    STDMETHOD_(void, addOval)(THIS_ const RECT *oval, Direction dir DEF_VAL(kCW_Direction)) PURE;

    STDMETHOD_(void, addOval2)(THIS_ float left, float top, float right, float bottom, Direction dir DEF_VAL(kCW_Direction)) PURE;

    /**
     *  Add a closed circle contour to the path
     *
     *  @param x        The x-coordinate of the center of a circle to add as a
     *                  closed contour to the path
     *  @param y        The y-coordinate of the center of a circle to add as a
     *                  closed contour to the path
     *  @param radius   The radius of a circle to add as a closed contour to the
     *                  path
     *  @param dir  The direction to wind the circle's contour. Cannot be
     *              kUnknown_Direction.
     */
    STDMETHOD_(void, addCircle)
    (THIS_ float x, float y, float radius, Direction dir DEF_VAL(kCW_Direction)) PURE;

    /** Add the specified arc to the path as a new contour.

    @param oval The bounds of oval used to define the size of the arc
    @param startAngle Starting angle (in degrees) where the arc begins
    @param sweepAngle Sweep angle (in degrees) measured clockwise
    */
    STDMETHOD_(void, addArc)(THIS_ const RECT *oval, float startAngle, float sweepAngle) PURE;

    STDMETHOD_(void, addArc2)(THIS_ float left, float top, float right, float bottom, float startAngle, float sweepAngle) PURE;

    /**
     *  Add a closed round-rectangle contour to the path
     *  @param rect The bounds of a round-rectangle to add as a closed contour
     *  @param rx   The x-radius of the rounded corners on the round-rectangle
     *  @param ry   The y-radius of the rounded corners on the round-rectangle
     *  @param dir  The direction to wind the rectangle's contour. Cannot be
     *              kUnknown_Direction.
     */
    STDMETHOD_(void, addRoundRect)
    (THIS_ const RECT *rect, float rx, float ry, Direction dir DEF_VAL(kCW_Direction)) PURE;

    /**
     *  Add a closed round-rectangle contour to the path. Each corner receives
     *  two radius values [X, Y]. The corners are ordered top-left, top-right,
     *  bottom-right, bottom-left.
     *  @param left,top,right and bottom, The bounds of a round-rectangle to add as a closed contour
     *  @param radii Array of 8 scalars, 4 [X,Y] pairs for each corner
     *  @param dir  The direction to wind the rectangle's contour. Cannot be
     *              kUnknown_Direction.
     * Note: The radii here now go through the same constraint handling as the
     *       SkRRect radii (i.e., either radii at a corner being 0 implies a
     *       sqaure corner and oversized radii are proportionally scaled down).
     */
    STDMETHOD_(void, addRoundRect2)
    (THIS_ float left, float top, float right, float bottom, float rx, float ry, Direction dir DEF_VAL(kCW_Direction)) PURE;

    /**
     *  Add a new contour made of just lines. This is just a fast version of
     *  the following:
     *      this->moveTo(pts[0]);
     *      for (int i = 1; i < count; ++i) {
     *          this->lineTo(pts[i]);
     *      }
     *      if (close) {
     *          this->close();
     *      }
     */
    STDMETHOD_(void, addPoly)(THIS_ const POINT pts[], int count, BOOL close) PURE;

    /** Offset the path by (dx,dy), returning true on success

    @param dx   The amount in the X direction to offset the entire path
    @param dy   The amount in the Y direction to offset the entire path
    */
    STDMETHOD_(void, offset)(THIS_ float dx, float dy) PURE;

    /** Transform the points in this path by matrix

    @param matrix The matrix to apply to the path
    */
    STDMETHOD_(void, transform)(THIS_ const IxForm *matrix) PURE;

    /** Return the last point on the path. If no points have been added, (0,0)
    is returned. If there are no points, this returns false, otherwise it
    returns true.

    @param lastPt   The last point on the path is returned here
    */
    STDMETHOD_(BOOL, getLastPt)(CTHIS_ fPoint * lastPt) SCONST PURE;

    STDMETHOD_(void, addString)
    (THIS_ LPCTSTR pszText, int nLen, float x, float y, const IFontS *pFont) PURE;

    STDMETHOD_(IPathS *, clone)(CTHIS) SCONST PURE;

    STDMETHOD_(BOOL, beginFigure)(THIS_ float x, float y, BOOL bFill DEF_VAL(TRUE)) PURE;

    STDMETHOD_(BOOL, endFigure)(THIS_ BOOL bClose) PURE;

    STDMETHOD_(float, getLength)(CTHIS) SCONST PURE;

    STDMETHOD_(BOOL, getPosTan)(CTHIS_ float distance, fPoint *pos, fPoint *vec) SCONST PURE;

    /** Close the current path to stop edit
     */
    STDMETHOD_(void, close)(THIS) PURE;

    STDMETHOD_(BOOL, hitTest)(CTHIS_ float x, float y) SCONST PURE;

    STDMETHOD_(BOOL, hitTestStroke)(CTHIS_ float x, float y, float strokeSize) SCONST PURE;
};

typedef struct _GradientItem
{
    COLORREF cr;
    float pos;
} GradientItem;

typedef struct _GradientInfo
{
    GradientType type;
    union {
        float angle;  // for linear
        float radius; // radical
        struct
        {
            float fX;
            float fY;
        } center; // sweep;
    };
} GradientInfo;

/**
 * @struct     IRenderTarget
 * @brief      RenderTarget对象
 *
 * Describe    实现各位渲染接口并创建设备相关资源
 */
#undef INTERFACE
#define INTERFACE IRenderTarget
DECLARE_INTERFACE_(IRenderTarget, IObjRef)
{
    //!添加引用
    /*!
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    //!释放引用
    /*!
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    //!释放对象
    /*!
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    STDMETHOD_(void, BeginDraw)(THIS) PURE;
    STDMETHOD_(void, EndDraw)(THIS) PURE;

    STDMETHOD_(BOOL, IsOffscreen)(CTHIS) SCONST PURE;

    STDMETHOD_(HRESULT, CreatePen)(THIS_ int iStyle, COLORREF cr, int cWidth, IPenS **ppPen) PURE;
    STDMETHOD_(HRESULT, CreateSolidColorBrush)(THIS_ COLORREF cr, IBrushS * *ppBrush) PURE;
    STDMETHOD_(HRESULT, CreateBitmapBrush)(THIS_ IBitmapS * pBmp, TileMode xtm, TileMode ytm, IBrushS * *ppBrush) PURE;
    STDMETHOD_(HRESULT, CreateGradientBrush)(THIS_ const GradientItem *pGradients, int nCount, const GradientInfo *info, BYTE byAlpha, TileMode tileMode, IBrushS **ppBrush) PURE;

    STDMETHOD_(HRESULT, CreateRegion)(THIS_ IRegionS * *ppRegion) PURE;

    STDMETHOD_(HRESULT, Resize)(THIS_ SIZE sz) PURE;

    STDMETHOD_(HRESULT, OffsetViewportOrg)
    (THIS_ int xOff, int yOff, LPPOINT lpPoint DEF_VAL(NULL)) PURE;
    STDMETHOD_(HRESULT, GetViewportOrg)(THIS_ LPPOINT lpPoint) PURE;
    STDMETHOD_(HRESULT, SetViewportOrg)(THIS_ POINT pt) PURE;

    STDMETHOD_(HRESULT, PushClipRect)(THIS_ LPCRECT pRect, UINT mode DEF_VAL(RGN_AND)) PURE;
    STDMETHOD_(HRESULT, PushClipRegion)(THIS_ IRegionS * pRegion, UINT mode DEF_VAL(RGN_AND)) PURE;
    STDMETHOD_(HRESULT, PopClip)(THIS) PURE;

    STDMETHOD_(HRESULT, ExcludeClipRect)(THIS_ LPCRECT pRc) PURE;

    STDMETHOD_(HRESULT, SaveClip)(THIS_ int *pnState) PURE;
    STDMETHOD_(HRESULT, RestoreClip)(THIS_ int nState DEF_VAL(-1)) PURE;

    STDMETHOD_(HRESULT, GetClipRegion)(THIS_ IRegionS * *ppRegion) PURE;
    STDMETHOD_(HRESULT, GetClipBox)(THIS_ LPRECT prc) PURE;

    STDMETHOD_(HRESULT, DrawText)(THIS_ LPCTSTR pszText, int cchLen, LPRECT pRc, UINT uFormat) PURE;
    STDMETHOD_(HRESULT, MeasureText)(THIS_ LPCTSTR pszText, int cchLen, SIZE *psz) PURE;
    STDMETHOD_(HRESULT, TextOut)(THIS_ int x, int y, LPCTSTR lpszString, int nCount) PURE;

    STDMETHOD_(HRESULT, DrawRectangle)(THIS_ LPCRECT pRect) PURE;
    STDMETHOD_(HRESULT, FillRectangle)(THIS_ LPCRECT pRect) PURE;
    STDMETHOD_(HRESULT, FillSolidRect)(THIS_ LPCRECT pRect, COLORREF cr) PURE;
    STDMETHOD_(HRESULT, DrawRoundRect)(THIS_ LPCRECT pRect, POINT pt) PURE;
    STDMETHOD_(HRESULT, FillRoundRect)(THIS_ LPCRECT pRect, POINT pt) PURE;
    STDMETHOD_(HRESULT, FillSolidRoundRect)(THIS_ LPCRECT pRect, POINT pt, COLORREF cr) PURE;
    STDMETHOD_(HRESULT, ClearRect)(THIS_ LPCRECT pRect, COLORREF cr) PURE;
    STDMETHOD_(HRESULT, InvertRect)(THIS_ LPCRECT pRect) PURE;
    STDMETHOD_(HRESULT, DrawEllipse)(THIS_ LPCRECT pRect) PURE;
    STDMETHOD_(HRESULT, FillEllipse)(THIS_ LPCRECT pRect) PURE;
    STDMETHOD_(HRESULT, FillSolidEllipse)(THIS_ LPCRECT pRect, COLORREF cr) PURE;

    STDMETHOD_(HRESULT, DrawArc)
    (THIS_ LPCRECT pRect, float startAngle, float sweepAngle, BOOL useCenter) PURE;
    STDMETHOD_(HRESULT, FillArc)(THIS_ LPCRECT pRect, float startAngle, float sweepAngle) PURE;

    STDMETHOD_(HRESULT, DrawLines)(THIS_ LPPOINT pPt, size_t nCount) PURE;
    STDMETHOD_(HRESULT, DrawGradientRect)
    (THIS_ LPCRECT pRect, BOOL bVert, POINT ptRoundCorner, const GradientItem *pGradients, int nCount, BYTE byAlpha DEF_VAL(0xFF)) PURE;
    STDMETHOD_(HRESULT, DrawGradientRectEx)
    (THIS_ LPCRECT pRect, POINT ptRoundCorner, const GradientItem *pGradients, int nCount, const GradientInfo *info, BYTE byAlpha DEF_VAL(0xFF)) PURE;
    STDMETHOD_(HRESULT, DrawGradientPath)
    (THIS_ const IPathS *path, const GradientItem *pGradients, int nCount, const GradientInfo *info, BYTE byAlpha DEF_VAL(0xFF)) PURE;

    STDMETHOD_(HRESULT, DrawIconEx)
    (THIS_ int xLeft, int yTop, HICON hIcon, int cxWidth, int cyWidth, UINT diFlags) PURE;
    STDMETHOD_(HRESULT, DrawBitmap)
    (THIS_ LPCRECT pRcDest, const IBitmapS *pBitmap, int xSrc, int ySrc, BYTE byAlpha DEF_VAL(0xFF)) PURE;
    STDMETHOD_(HRESULT, DrawBitmapEx)
    (THIS_ LPCRECT pRcDest, const IBitmapS *pBitmap, LPCRECT pRcSrc, UINT expendMode, BYTE byAlpha DEF_VAL(0xFF)) PURE;
    STDMETHOD_(HRESULT, DrawBitmap9Patch)
    (THIS_ LPCRECT pRcDest, const IBitmapS *pBitmap, LPCRECT pRcSrc, LPCRECT pRcSourMargin, UINT expendMode, BYTE byAlpha DEF_VAL(0xFF)) PURE;
    STDMETHOD_(HRESULT, BitBlt)
    (THIS_ LPCRECT pRcDest, IRenderTarget * pRTSour, int xSrc, int ySrc, DWORD dwRop DEF_VAL(kSrcCopy)) PURE;
    STDMETHOD_(HRESULT, AlphaBlend)
    (THIS_ LPCRECT pRcDest, IRenderTarget * pRTSrc, LPCRECT pRcSrc, BYTE byAlpha) PURE;
    STDMETHOD_(IRenderObj *, GetCurrentObject)(THIS_ OBJTYPE uType) PURE;
    //将指定的RenderObj恢复为默认状态
    STDMETHOD_(HRESULT, SelectDefaultObject)
    (THIS_ OBJTYPE objType, IRenderObj * *pOldObj DEF_VAL(NULL)) PURE;
    STDMETHOD_(HRESULT, SelectObject)
    (THIS_ IRenderObj * pObj, IRenderObj * *pOldObj DEF_VAL(NULL)) PURE;
    STDMETHOD_(COLORREF, GetTextColor)(THIS) PURE;
    STDMETHOD_(COLORREF, SetTextColor)(THIS_ COLORREF color) PURE;
    STDMETHOD_(void, SetMaskFilter)(THIS_ IMaskFilter * pMaskFilter) PURE;
    STDMETHOD_(IMaskFilter *, GetMaskFilter)(THIS) PURE;

    //两个兼容GDI操作的接口
    STDMETHOD_(HDC, GetDC)(THIS_ UINT uFlag) PURE;
    STDMETHOD_(void, ReleaseDC)(THIS_ HDC hdc, LPCRECT pRc DEF_VAL(NULL)) PURE;

    /**
     * SetTransform
     * @brief    设置坐标变换矩阵
     * @param    const IxForm * pXForm --  3*3变换矩阵
     * @param    IxForm * pOldXFrom --  原变换矩阵
     * @return   HRESULT -- 成功返回S_OK
     *
     * Describe
     */
    STDMETHOD_(HRESULT, SetTransform)
    (THIS_ const float matrix[9], float oldMatrix[9] DEF_VAL(NULL)) PURE;

    /**
     * SetTransform
     * @brief    获取当前坐标变换矩阵
     * @param    IxForm * pXForm --  2*3变换矩阵
     * @return   HRESULT -- 成功返回S_OK
     *
     * Describe
     */
    STDMETHOD_(HRESULT, GetTransform)(CTHIS_ float matrix[9]) SCONST PURE;

    /**
     * GetPixel
     * @brief    获取指定像素颜色值
     * @param    int x -- x
     * @param    int y -- y
     * @return   COLORREF -- 像素颜色值
     *
     * Describe  和::GetPixel一致
     */
    STDMETHOD_(COLORREF, GetPixel)(THIS_ int x, int y) PURE;

    /**
     * SetPixel
     * @brief    设置指定像素颜色值
     * @param    int x -- x
     * @param    int y -- y
     * @param    COLORREF cr -- 设置的颜色值
     * @return   COLORREF -- 原像素颜色值
     *
     * Describe  和::SetPixel一致
     */
    STDMETHOD_(COLORREF, SetPixel)(THIS_ int x, int y, COLORREF cr) PURE;

    /**
     *  Modify the current clip with the specified path.
     *  @param path The path to combine with the current clip
     *  @param mode The region op to apply to the current clip
     *  @param doAntiAlias true if the clip should be anti aliased
     */
    STDMETHOD_(HRESULT, PushClipPath)
    (THIS_ const IPathS *path, UINT mode, BOOL doAntiAlias DEF_VAL(FALSE)) PURE;

    /** Draw the specified path frame using current selected pen
    @param path     The path to be drawn
    */
    STDMETHOD_(HRESULT, DrawPath)
    (THIS_ const IPathS *path, IPathEffect *pathEffect DEF_VAL(NULL)) PURE;

    /** Fill the specified path frame using current selected brush
    @param path     The path to be drawn
    */
    STDMETHOD_(HRESULT, FillPath)(THIS_ const IPathS *path) PURE;

    STDMETHOD_(HRESULT, SetXfermode)(THIS_ int mode, int *pOldMode DEF_VAL(NULL)) PURE;
    STDMETHOD_(BOOL, SetAntiAlias)(THIS_ BOOL bAntiAlias) PURE;
    STDMETHOD_(BOOL, GetAntiAlias)(CTHIS) SCONST PURE;
};

/**
 * @struct     IRenderFactory
 * @brief      RenderFactory对象
 *
 * Describe
 */
#undef INTERFACE
#define INTERFACE IRenderFactory
DECLARE_INTERFACE_(IRenderFactory, IObjRef)
{
    //!添加引用
    /*!
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    //!释放引用
    /*!
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    //!释放对象
    /*!
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    STDMETHOD_(IImgDecoderFactory *, GetImgDecoderFactory)(THIS) PURE;
    STDMETHOD_(void, SetImgDecoderFactory)(THIS_ IImgDecoderFactory * pImgDecoderFac) PURE;
    STDMETHOD_(BOOL, CreateRenderTarget)
    (THIS_ IRenderTarget * *ppRenderTarget, int nWid DEF_VAL(0), int nHei DEF_VAL(0)) PURE;

    STDMETHOD_(BOOL, CreateRenderTarget2)
    (THIS_ IRenderTarget * *ppRenderTarget, HWND hWnd) PURE;

    /**
     * CreateFont
     * @brief    创建字体
     * @param [out] IFont ** ppFont -- 字体对象
     * @param [in] const LOGFONT &lf -- 字体属性
     * @param [in] const IPropBag * pPropBag --  字体扩展属性，由渲染引擎解析
     * @return   BOOL -- TRUE:SUCCEED, FASLE:FAILED
     *
     * Describe
     */
    STDMETHOD_(BOOL, CreateFont)(THIS_ IFontS * *ppFont, const LOGFONT *lf) PURE;

    STDMETHOD_(BOOL, CreateBitmap)(THIS_ IBitmapS * *ppBitmap) PURE;

    STDMETHOD_(BOOL, CreateRegion)(THIS_ IRegionS * *ppRgn) PURE;

    STDMETHOD_(BOOL, CreatePath)(THIS_ IPathS * *ppPath) PURE;

    STDMETHOD_(HRESULT, CreateBlurMaskFilter)
    (THIS_ float radius, BlurStyle style, BlurFlags flag, IMaskFilter **ppMaskFilter) PURE;

    STDMETHOD_(HRESULT, CreateEmbossMaskFilter)
    (THIS_ float direction[3], float ambient, float specular, float blurRadius, IMaskFilter **ppMaskFilter) PURE;

    STDMETHOD_(BOOL, CreatePathEffect)(THIS_ REFGUID guidEffect, IPathEffect * *ppPathEffect) PURE;
};

#ifdef __cplusplus
// remove suffix of S for RenderObj to make it compatible with soui3 without conflicted with system
// interface.
typedef IFontS IFont;
typedef IPenS IPen;
typedef IBrushS IBrush;
typedef IBitmapS IBitmap;
typedef IRegionS IRegion;
typedef IPathS IPath;
#endif //__cplusplus

SNSEND
typedef BOOL (*FontFallback)(LPCSTR u8FontName, wchar_t text, char u8FontNameFallback[100], int *charset);

#endif // __SRENDER_I__H__