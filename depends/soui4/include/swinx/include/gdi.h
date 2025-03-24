#ifndef _LINUX_GDI_H_
#define _LINUX_GDI_H_
#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#define OBJ_PEN      1
#define OBJ_BRUSH    2
#define OBJ_DC       3
#define OBJ_FONT     6
#define OBJ_BITMAP   7
#define OBJ_REGION   8
#define OBJ_PAL      9
#define OBJ_METAFILE 10

    HGDIOBJ InitGdiObj(int type, void *ptr);
    void *GetGdiObjPtr(HGDIOBJ hgdiobj);
    void SetGdiObjPtr(HGDIOBJ hgdiObj, void *ptr);
    HGDIOBJ RefGdiObj(HGDIOBJ hgdiObj);

    typedef struct _XFORM
    {
        FLOAT eM11;
        FLOAT eM12;
        FLOAT eM21;
        FLOAT eM22;
        FLOAT eDx;
        FLOAT eDy;
    } XFORM, *PXFORM, *LPXFORM;

    typedef struct _FIXED
    {
#ifndef _MAC
        WORD fract;
        short value;
#else
    short value;
    WORD fract;
#endif
    } FIXED;

#define GDI_ERROR (0xFFFFFFFFL)

#define SRCCOPY   (DWORD)0x00CC0020 /* dest = source                   */
#define SRCPAINT  (DWORD)0x00EE0086 /* dest = source OR dest           */
#define SRCAND    (DWORD)0x008800C6 /* dest = source AND dest          */
#define SRCINVERT (DWORD)0x00660046 /* dest = source XOR dest          */
#define DSTINVERT (DWORD)0x00550009 /* dest = (NOT dest)               */

#define PATCOPY   (DWORD)0x00F00021 /* dest = pattern                  */
#define PATPAINT  (DWORD)0x00FB0A09 /* dest = DPSnoo                   */
#define PATINVERT (DWORD)0x005A0049 /* dest = pattern XOR dest         */
#define DSTINVERT (DWORD)0x00550009 /* dest = (NOT dest)               */
#define BLACKNESS (DWORD)0x00000042 /* dest = BLACK                    */
#define WHITENESS (DWORD)0x00FF0062 /* dest = WHITE                    */

    typedef struct _MAT2
    {
        FIXED eM11;
        FIXED eM12;
        FIXED eM21;
        FIXED eM22;
    } MAT2, FAR *LPMAT2;

    typedef struct _GLYPHMETRICS
    {
        UINT gmBlackBoxX;
        UINT gmBlackBoxY;
        POINT gmptGlyphOrigin;
        short gmCellIncX;
        short gmCellIncY;
    } GLYPHMETRICS, FAR *LPGLYPHMETRICS;

    //  GetGlyphOutline constants

#define GGO_METRICS 0
#define GGO_BITMAP  1
#define GGO_NATIVE  2
#define GGO_BEZIER  3

#if (WINVER >= 0x0400)
#define GGO_GRAY2_BITMAP 4
#define GGO_GRAY4_BITMAP 5
#define GGO_GRAY8_BITMAP 6
#define GGO_GLYPH_INDEX  0x0080
#endif /* WINVER >= 0x0400 */

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN2K)
#define GGO_UNHINTED 0x0100
#endif // (_WIN32_WINNT >= _WIN32_WINNT_WIN2K)

#define TT_POLYGON_TYPE 24

#define TT_PRIM_LINE    1
#define TT_PRIM_QSPLINE 2
#define TT_PRIM_CSPLINE 3

/* tmPitchAndFamily flags */
#define TMPF_FIXED_PITCH 0x01
#define TMPF_VECTOR      0x02
#define TMPF_DEVICE      0x08
#define TMPF_TRUETYPE    0x04

#define ANSI_CHARSET        0
#define DEFAULT_CHARSET     1
#define SYMBOL_CHARSET      2
#define SHIFTJIS_CHARSET    128
#define HANGEUL_CHARSET     129
#define HANGUL_CHARSET      129
#define GB2312_CHARSET      134
#define CHINESEBIG5_CHARSET 136
#define OEM_CHARSET         255
#if (WINVER >= 0x0400)
#define JOHAB_CHARSET      130
#define HEBREW_CHARSET     177
#define ARABIC_CHARSET     178
#define GREEK_CHARSET      161
#define TURKISH_CHARSET    162
#define VIETNAMESE_CHARSET 163
#define THAI_CHARSET       222
#define EASTEUROPE_CHARSET 238
#define RUSSIAN_CHARSET    204
#endif // WINVER

/* Font Families */
#define FF_DONTCARE (0 << 4)   /* Don't care or don't know. */
#define FF_ROMAN    (1 << 4)   /* Variable stroke width, serifed. */
                               /* Times Roman, Century Schoolbook, etc. */
#define FF_SWISS (2 << 4)      /* Variable stroke width, sans-serifed. */
                               /* Helvetica, Swiss, etc. */
#define FF_MODERN (3 << 4)     /* Constant stroke width, serifed or sans-serifed. */
                               /* Pica, Elite, Courier, etc. */
#define FF_SCRIPT     (4 << 4) /* Cursive, etc. */
#define FF_DECORATIVE (5 << 4) /* Old English, etc. */

/* Font Weights */
#define FW_DONTCARE   0
#define FW_THIN       100
#define FW_EXTRALIGHT 200
#define FW_LIGHT      300
#define FW_NORMAL     400
#define FW_MEDIUM     500
#define FW_SEMIBOLD   600
#define FW_BOLD       700
#define FW_EXTRABOLD  800
#define FW_HEAVY      900

#define FW_ULTRALIGHT FW_EXTRALIGHT
#define FW_REGULAR    FW_NORMAL
#define FW_DEMIBOLD   FW_SEMIBOLD
#define FW_ULTRABOLD  FW_EXTRABOLD
#define FW_BLACK      FW_HEAVY

#define LF_FACESIZE 32
    typedef struct tagLOGFONTA
    {
        LONG lfHeight;
        LONG lfWidth;
        LONG lfEscapement;
        LONG lfOrientation;
        LONG lfWeight;
        BYTE lfItalic;
        BYTE lfUnderline;
        BYTE lfStrikeOut;
        BYTE lfCharSet;
        BYTE lfOutPrecision;
        BYTE lfClipPrecision;
        BYTE lfQuality;
        BYTE lfPitchAndFamily;
        char lfFaceName[LF_FACESIZE];
    } LOGFONTA, *PLOGFONTA, NEAR *NPLOGFONTA, FAR *LPLOGFONTA;

    typedef struct tagLOGFONTW
    {
        LONG lfHeight;
        LONG lfWidth;
        LONG lfEscapement;
        LONG lfOrientation;
        LONG lfWeight;
        BYTE lfItalic;
        BYTE lfUnderline;
        BYTE lfStrikeOut;
        BYTE lfCharSet;
        BYTE lfOutPrecision;
        BYTE lfClipPrecision;
        BYTE lfQuality;
        BYTE lfPitchAndFamily;
        wchar_t lfFaceName[LF_FACESIZE];
    } LOGFONTW, *PLOGFONTW, NEAR *NPLOGFONTW, FAR *LPLOGFONTW;

#define LF_FULLFACESIZE 64

    /* Structure passed to FONTENUMPROC */
    typedef struct tagENUMLOGFONTA
    {
        LOGFONTA elfLogFont;
        BYTE elfFullName[LF_FULLFACESIZE];
        BYTE elfStyle[LF_FACESIZE];
    } ENUMLOGFONTA, FAR *LPENUMLOGFONTA;
    /* Structure passed to FONTENUMPROC */
    typedef struct tagENUMLOGFONTW
    {
        LOGFONTW elfLogFont;
        WCHAR elfFullName[LF_FULLFACESIZE];
        WCHAR elfStyle[LF_FACESIZE];
    } ENUMLOGFONTW, FAR *LPENUMLOGFONTW;
#ifdef UNICODE
    typedef LOGFONTW LOGFONT;
    typedef ENUMLOGFONTW ENUMLOGFONT;
    typedef LPENUMLOGFONTW LPENUMLOGFONT;
#else
typedef LOGFONTA LOGFONT;
typedef ENUMLOGFONTA ENUMLOGFONT;
typedef LPENUMLOGFONTA LPENUMLOGFONT;
#endif // UNICODE

    /* Logical Brush (or Pattern) */
    typedef struct tagLOGBRUSH
    {
        UINT lbStyle;
        COLORREF lbColor;
        UINT_PTR lbHatch; // Sundown: lbHatch could hold a HANDLE
    } LOGBRUSH, *PLOGBRUSH, NEAR *NPLOGBRUSH, FAR *LPLOGBRUSH;

#define BS_SOLID         0
#define BS_NULL          1
#define BS_HOLLOW        BS_NULL
#define BS_HATCHED       2
#define BS_PATTERN       3
#define BS_INDEXED       4
#define BS_DIBPATTERN    5
#define BS_DIBPATTERNPT  6
#define BS_PATTERN8X8    7
#define BS_DIBPATTERN8X8 8
#define BS_MONOPATTERN   9
#define BS_GRADIENT      10

    HPEN WINAPI ExtCreatePen(DWORD iPenStyle, DWORD cWidth, CONST LOGBRUSH *plbrush, DWORD cStyle, CONST DWORD *pstyle);

    int WINAPI GetObjectA(HGDIOBJ h, int c, LPVOID pv);
    int WINAPI GetObjectW(HGDIOBJ h, int c, LPVOID pv);
#ifdef UNICODE
#define GetObject GetObjectW
#else
#define GetObject GetObjectA
#endif // UNICODE

    int WINAPI GetObjectType(HGDIOBJ hgdiobj);
    /* Logical Pen */
    typedef struct tagLOGPEN
    {
        UINT lopnStyle;
        POINT lopnWidth;
        COLORREF lopnColor;
    } LOGPEN, *PLOGPEN, NEAR *NPLOGPEN, FAR *LPLOGPEN;

    HPEN WINAPI CreatePen(int iStyle, int cWidth, COLORREF color);
    HPEN WINAPI CreatePenIndirect(CONST LOGPEN *plpen);

    HFONT WINAPI CreateFontIndirectA(CONST LOGFONTA *lplf);
    HFONT WINAPI CreateFontIndirectW(CONST LOGFONTW *lplf);
    HFONT WINAPI CreateFontA(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut, DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision, DWORD iQuality, DWORD iPitchAndFamily, LPCSTR pszFaceName);
    HFONT WINAPI CreateFontW(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut, DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision, DWORD iQuality, DWORD iPitchAndFamily, LPCWSTR pszFaceName);

#ifdef UNICODE
#define CreateFont         CreateFontW
#define CreateFontIndirect CreateFontIndirectW
#else
#define CreateFont         CreateFontA
#define CreateFontIndirect CreateFontIndirectA
#endif // UNICODE

#pragma pack(push,1)
    /* Bitmap Header Definition */
    typedef struct tagBITMAP
    {
        LONG bmType;
        LONG bmWidth;
        LONG bmHeight;
        LONG bmWidthBytes;
        WORD bmPlanes;
        WORD bmBitsPixel;
        LPVOID bmBits;
    } BITMAP, *PBITMAP, NEAR *NPBITMAP, FAR *LPBITMAP;

    typedef struct tagBITMAPINFOHEADER
    {
        DWORD biSize;
        LONG biWidth;
        LONG biHeight;
        WORD biPlanes;
        WORD biBitCount;
        DWORD biCompression;
        DWORD biSizeImage;
        LONG biXPelsPerMeter;
        LONG biYPelsPerMeter;
        DWORD biClrUsed;
        DWORD biClrImportant;
    } BITMAPINFOHEADER, FAR *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;

    typedef LONG FXPT16DOT16, *LPFXPT16DOT16;
    typedef LONG FXPT2DOT30, *LPFXPT2DOT30;
    typedef LONG LCSCSTYPE;
    typedef LONG LCSGAMUTMATCH;

    typedef struct tagCIEXYZ
    {
        FXPT2DOT30 ciexyzX;
        FXPT2DOT30 ciexyzY;
        FXPT2DOT30 ciexyzZ;
    } CIEXYZ, *LPCIEXYZ;

    typedef struct tagCIEXYZTRIPLE
    {
        CIEXYZ ciexyzRed;
        CIEXYZ ciexyzGreen;
        CIEXYZ ciexyzBlue;
    } CIEXYZTRIPLE, *LPCIEXYZTRIPLE;

    typedef struct
    {
        DWORD bV4Size;
        LONG bV4Width;
        LONG bV4Height;
        WORD bV4Planes;
        WORD bV4BitCount;
        DWORD bV4V4Compression;
        DWORD bV4SizeImage;
        LONG bV4XPelsPerMeter;
        LONG bV4YPelsPerMeter;
        DWORD bV4ClrUsed;
        DWORD bV4ClrImportant;
        DWORD bV4RedMask;
        DWORD bV4GreenMask;
        DWORD bV4BlueMask;
        DWORD bV4AlphaMask;
        DWORD bV4CSType;
        CIEXYZTRIPLE bV4Endpoints;
        DWORD bV4GammaRed;
        DWORD bV4GammaGreen;
        DWORD bV4GammaBlue;
    } BITMAPV4HEADER, *PBITMAPV4HEADER;

    typedef struct
    {
        DWORD bV5Size;
        LONG bV5Width;
        LONG bV5Height;
        WORD bV5Planes;
        WORD bV5BitCount;
        DWORD bV5Compression;
        DWORD bV5SizeImage;
        LONG bV5XPelsPerMeter;
        LONG bV5YPelsPerMeter;
        DWORD bV5ClrUsed;
        DWORD bV5ClrImportant;
        DWORD bV5RedMask;
        DWORD bV5GreenMask;
        DWORD bV5BlueMask;
        DWORD bV5AlphaMask;
        DWORD bV5CSType;
        CIEXYZTRIPLE bV5Endpoints;
        DWORD bV5GammaRed;
        DWORD bV5GammaGreen;
        DWORD bV5GammaBlue;
        DWORD bV5Intent;
        DWORD bV5ProfileData;
        DWORD bV5ProfileSize;
        DWORD bV5Reserved;
    } BITMAPV5HEADER, *LPBITMAPV5HEADER, *PBITMAPV5HEADER;

    typedef struct tagBITMAPFILEHEADER
    {
        WORD bfType;
        DWORD bfSize;
        WORD bfReserved1;
        WORD bfReserved2;
        DWORD bfOffBits;
    } BITMAPFILEHEADER, *PBITMAPFILEHEADER;

    typedef struct
    {
        DWORD bcSize;
        WORD bcWidth;
        WORD bcHeight;
        WORD bcPlanes;
        WORD bcBitCount;
    } BITMAPCOREHEADER, *PBITMAPCOREHEADER, *LPBITMAPCOREHEADER;

    typedef struct tagRGBTRIPLE
    {
        BYTE rgbtBlue;
        BYTE rgbtGreen;
        BYTE rgbtRed;
    } RGBTRIPLE;

    typedef struct
    {
        BITMAPCOREHEADER bmciHeader;
        RGBTRIPLE bmciColors[1];
    } BITMAPCOREINFO, *PBITMAPCOREINFO, *LPBITMAPCOREINFO;

#pragma pack(pop)

/* constants for the biCompression field */
#define BI_RGB       0L
#define BI_RLE8      1L
#define BI_RLE4      2L
#define BI_BITFIELDS 3L
#define BI_JPEG      4L
#define BI_PNG       5L

    typedef struct tagBITMAPINFO
    {
        BITMAPINFOHEADER bmiHeader;
        RGBQUAD bmiColors[1];
    } BITMAPINFO, FAR *LPBITMAPINFO, *PBITMAPINFO;

    typedef struct tagDIBSECTION
    {
        BITMAP dsBm;
        BITMAPINFOHEADER dsBmih;
        DWORD dsBitfields[3];
        HANDLE dshSection;
        DWORD dsOffset;
    } DIBSECTION, *PDIBSECTION, *LPDIBSECTION;

    typedef struct tagGRADIENTITEM
    {
        COLORREF cr;
        float pos;
    } GRADIENTITEM, FAR *LPGRADIENTITEM, *PGRADIENTITEM;

    typedef enum tagGRADIENTTYPE
    {
        grad_linear = 0, /*<���Խ���*/
        grad_radial,     /*<���佥��*/
    } GRADIENTTYPE;

    typedef struct tagGRADIENTINFO
    {
        GRADIENTTYPE type;
        union {
            float angle; // for linear
            struct
            {
                float radius;  // radical
                float centerX; // 0.0 -> 1.0, 0.5 is center of x
                float centerY; // 0.0 -> 1.0, 0.5 is center of y
            } radial;
            struct
            {
                BOOL bFullArc; // true(default) indicator gradient is rendered for full circle.
                float centerX; // 0.0 -> 1.0, 0.5 is center of x
                float centerY; // 0.0 -> 1.0, 0.5 is center of y
            } sweep;           // sweep;
        };
    } GRADIENTINFO, FAR *LPGRADIENTINFO, *PGRADIENTINFO;

    typedef enum tagTILEMODE
    {
        /** replicate the edge color if the shader draws outside of its
         *  original bounds
         */
        kTileMode_Clamp = 0,

        /** repeat the shader's image horizontally and vertically */
        kTileMode_Repeat,

        /** repeat the shader's image horizontally and vertically, alternating
         *  mirror images so that adjacent images always seam
         */
        kTileMode_Mirror,
    } TILEMODE;

#define DIB_RGB_COLORS 0 /* color table in RGBs */
#define DIB_PAL_COLORS 1 /* color table in palette indices */

#define CBM_INIT 0x04L /* initialize bitmap */

    /* StretchBlt() modes */
#define BLACKONWHITE      1
#define WHITEONBLACK      2
#define COLORONCOLOR      3
#define HALFTONE          4
#define MAXSTRETCHBLTMODE 4

#define STRETCH_ANDSCANS    BLACKONWHITE
#define STRETCH_ORSCANS     WHITEONBLACK
#define STRETCH_DELETESCANS COLORONCOLOR
#define STRETCH_HALFTONE    HALFTONE

    HBITMAP WINAPI CreateBitmap(int nWidth,         // bitmap width, in pixels
                                int nHeight,        // bitmap height, in pixels
                                UINT cPlanes,       // number of color planes
                                UINT cBitsPerPel,   // number of bits to identify color
                                CONST VOID *lpvBits // color data array
    );
    HBITMAP WINAPI CreateDIBitmap(HDC hdc, CONST BITMAPINFOHEADER *pbmih, DWORD flInit, CONST VOID *pjBits, CONST BITMAPINFO *pbmi, UINT iUsage);
    HBRUSH WINAPI CreateDIBPatternBrush(HGLOBAL h, UINT iUsage);
    HBRUSH WINAPI CreateDIBPatternBrushPt(CONST VOID *lpPackedDIB, UINT iUsage);
    HBRUSH WINAPI CreateSolidBrush(COLORREF color);
    HBRUSH WINAPI CreatePatternBrush(HBITMAP bmp);
    HBRUSH WINAPI CreatePatternBrush2(HBITMAP bmp, TILEMODE tileMode);
    HBRUSH WINAPI CreateGradientBrush(const GRADIENTITEM *pGradients, int nCount, const GRADIENTINFO *info, BYTE byAlpha, TILEMODE tileMode);

    HBITMAP WINAPI CreateDIBSection(HDC hdc, CONST BITMAPINFO *lpbmi, UINT usage, VOID **ppvBits, HANDLE hSection, DWORD offset);
    BOOL WINAPI UpdateDIBPixmap(HBITMAP bmp, int wid, int hei, int bitsPixel, int stride, CONST VOID *pjBits);
    void WINAPI MarkPixmapDirty(HBITMAP bmp);

    HDC WINAPI CreateCompatibleDC(HDC hdc);
    BOOL WINAPI DeleteDC(HDC hdc);

/* Background Modes */
#define TRANSPARENT 1
#define OPAQUE      2
#define BKMODE_LAST 2

    /* Graphics Modes */

#define GM_COMPATIBLE 1
#define GM_ADVANCED   2
#define GM_LAST       2

    int WINAPI SetBkMode(HDC hdc, int mode);
    int WINAPI GetBkMode(HDC hdc);
    int WINAPI SetGraphicsMode(HDC hdc, int iMode);

    COLORREF WINAPI GetBkColor(HDC hdc);
    COLORREF WINAPI SetBkColor(HDC hdc, COLORREF cr);

    HBITMAP WINAPI CreateCompatibleBitmap(HDC hdc, int cx, int cy);
    HGDIOBJ WINAPI SelectObject(HDC hdc, HGDIOBJ h);
    BOOL WINAPI DeleteObject(HGDIOBJ ho);
    int WINAPI SaveDC(HDC hdc);
    int WINAPI SelectClipRgn(HDC hdc, HRGN hrgn);
    int WINAPI ExtSelectClipRgn(HDC hdc, HRGN hrgn, int mode);
    int WINAPI ExcludeClipRect(HDC hdc, int left, int top, int right, int bottom);
    int WINAPI IntersectClipRect(HDC hdc, int left, int top, int right, int bottom);
    BOOL WINAPI RestoreDC(HDC hdc, int nSavedDC);

    BOOL WINAPI InvertRgn(HDC hdc,  // handle to device context
                          HRGN hrgn // handle to region to be inverted
    );
    int WINAPI GetClipBox(HDC hdc, LPRECT lprect);
    int WINAPI GetClipRgn(HDC hdc, HRGN hrgn);

    BOOL WINAPI FillRgn(HDC hdc,   // handle to device context
                        HRGN hrgn, // handle to region to be filled
                        HBRUSH hbr // handle to brush used to fill the region
    );

    BOOL WINAPI PaintRgn(HDC hdc,  // handle to device context
                         HRGN hrgn // handle to region to be painted
    );

    BOOL WINAPI FrameRgn(HDC hdc,    // handle to device context
                         HRGN hrgn,  // handle to region to be framed
                         HBRUSH hbr, // handle to brush used to draw border
                         int nWidth, // width of region frame
                         int nHeight // height of region frame
    );

    BOOL WINAPI DrawFocusRect(HDC hDC,         // handle to device context
                              CONST RECT *lprc // logical coordinates
    );

    HGDIOBJ WINAPI GetCurrentObject(HDC hdc, UINT type);
    int WINAPI GetDIBits(HDC hdc, HBITMAP hbm, UINT start, UINT cLines, LPVOID lpvBits, LPBITMAPINFO lpbmi, UINT usage); // SAL actual size of lpbmi is computed from structure elements

    HICON WINAPI CreateIconIndirect(PICONINFO iconinfo);

    BOOL WINAPI BitBlt(HDC hdc, int x, int y, int cx, int cy, HDC hdcSrc, int x1, int y1, DWORD rop);

    BOOL WINAPI StretchBlt(HDC hdc, int x, int y, int cx, int cy, HDC hdcSrc, int x1, int y1, int cx2, int cy2, DWORD rop);

    BOOL WINAPI PatBlt(_In_ HDC hdc, _In_ int x, _In_ int y, _In_ int w, _In_ int h, _In_ DWORD rop);

    BOOL WINAPI DrawIcon(HDC hdc, INT x, INT y, HICON hIcon);

    BOOL WINAPI DrawIconEx(HDC hdc, INT x0, INT y0, HICON icon, INT width, INT height, UINT step, HBRUSH brush, UINT flags);

    INT WINAPI StretchDIBits(HDC hdc, INT x_dst, INT y_dst, INT width_dst, INT height_dst, INT x_src, INT y_src, INT width_src, INT height_src, const void *bits, const BITMAPINFO *bmi, UINT coloruse, DWORD rop);

    int WINAPI DrawTextA(HDC hdc, LPCSTR lpchText, int cchText, LPRECT lprc, UINT format);
    int WINAPI DrawTextW(HDC hdc, LPCWSTR lpchText, int cchText, LPRECT lprc, UINT format);

    BOOL WINAPI GetTextExtentPoint32A(HDC hdc, LPCSTR lpString, int c, LPSIZE psizl);
    BOOL WINAPI GetTextExtentPoint32W(HDC hdc, LPCWSTR lpString, int c, LPSIZE psizl);
#define GetTextExtentPointA GetTextExtentPoint32A
#define GetTextExtentPointW GetTextExtentPoint32W

    BOOL WINAPI GetTextExtentExPointA(HDC hdc, LPCSTR lpszString, int cchString, int nMaxExtent, LPINT lpnFit, LPINT lpnDx, LPSIZE lpSize);
    BOOL WINAPI GetTextExtentExPointW(HDC hdc, LPCWSTR lpszString, int cchString, int nMaxExtent, LPINT lpnFit, LPINT lpnDx, LPSIZE lpSize);

#ifdef UNICODE
#define GetTextExtentPoint   GetTextExtentPoint32W
#define GetTextExtentExPoint GetTextExtentExPointW
#define DrawText             DrawTextW
#define GetTextExtentPoint32 GetTextExtentPoint32W
#else
#define GetTextExtentPoint   GetTextExtentPoint32A
#define GetTextExtentExPoint GetTextExtentExPointA
#define DrawText             DrawTextA
#define GetTextExtentPoint32 GetTextExtentPoint32A
#endif // UNICODE

/* Stock Logical Objects */
#define WHITE_BRUSH         0
#define LTGRAY_BRUSH        1
#define GRAY_BRUSH          2
#define DKGRAY_BRUSH        3
#define BLACK_BRUSH         4
#define NULL_BRUSH          5
#define HOLLOW_BRUSH        NULL_BRUSH
#define WHITE_PEN           6
#define BLACK_PEN           7
#define NULL_PEN            8
#define OEM_FIXED_FONT      10
#define ANSI_FIXED_FONT     11
#define ANSI_VAR_FONT       12
#define SYSTEM_FONT         13
#define DEVICE_DEFAULT_FONT 14
#define DEFAULT_PALETTE     15
#define SYSTEM_FIXED_FONT   16
#define DEFAULT_GUI_FONT    17
#define NULL_BITMAP         20

    HGDIOBJ WINAPI GetStockObject(int i);

    COLORREF WINAPI GetSysColor(int i);
    HBRUSH WINAPI GetSysColorBrush(int i);
    HPEN WINAPI GetSysColorPen(int i);

    BOOL WINAPI Rectangle(HDC hdc, int left, int top, int right, int bottom);

    BOOL WINAPI RoundRect(HDC hdc, int left, int top, int right, int bottom, int width, int height);

    BOOL WINAPI Polyline(HDC hdc, CONST POINT *apt, int cpt);

    BOOL WINAPI AlphaBlend(HDC hdcDest, int xoriginDest, int yoriginDest, int wDest, int hDest, HDC hdcSrc, int xoriginSrc, int yoriginSrc, int wSrc, int hSrc, BLENDFUNCTION ftn);

#define EXPEND_MODE_NONE    0
#define EXPEND_MODE_STRETCH 1
#define EXPEND_MODE_TILE    2

#define FILTER_NONE   0
#define FILTER_FAST   1
#define FILTER_MIDIUM 2
#define FILTER_BEST   3
    BOOL WINAPI DrawBitmapEx(HDC hdc, LPCRECT pRcDest, HBITMAP bmp, LPCRECT pRcSrc, UINT expendMode, BYTE byAlpha);

    BOOL WINAPI DrawBitmap9Patch(HDC hdc, LPCRECT pRcDest, HBITMAP hBmp, LPCRECT pRcSrc, LPCRECT pRcSourMargin, UINT expendMode, BYTE byAlpha);

    BOOL WINAPI TextOutA(HDC hdc, int x, int y, LPCSTR lpString, int c);
    BOOL WINAPI TextOutW(HDC hdc, int x, int y, LPCWSTR lpString, int c);

    LONG WINAPI TabbedTextOutA(HDC hDC,                         // handle to DC
                               int X,                           // x-coord of start
                               int Y,                           // y-coord of start
                               LPCSTR lpString,                 // character string
                               int nCount,                      // number of characters
                               int nTabPositions,               // number of tabs in array
                               CONST LPINT lpnTabStopPositions, // array of tab positions
                               int nTabOrigin                   // start of tab expansion
    );
    LONG WINAPI TabbedTextOutW(HDC hDC,                         // handle to DC
                               int X,                           // x-coord of start
                               int Y,                           // y-coord of start
                               LPCWSTR lpString,                // character string
                               int nCount,                      // number of characters
                               int nTabPositions,               // number of tabs in array
                               CONST LPINT lpnTabStopPositions, // array of tab positions
                               int nTabOrigin                   // start of tab expansion
    );

    DWORD WINAPI GetTabbedTextExtentA(HDC hDC,                        // handle to DC
                                      LPCSTR lpString,                // character string
                                      int nCount,                     // number of characters
                                      int nTabPositions,              // number of tab positions
                                      CONST LPINT lpnTabStopPositions // array of tab positions
    );
    DWORD WINAPI GetTabbedTextExtentW(HDC hDC,                        // handle to DC
                                      LPCWSTR lpString,               // character string
                                      int nCount,                     // number of characters
                                      int nTabPositions,              // number of tab positions
                                      CONST LPINT lpnTabStopPositions // array of tab positions
    );
#ifdef UNICODE
#define TextOut             TextOutW
#define TabbedTextOut       TabbedTextOutW
#define GetTabbedTextExtent GetTabbedTextExtentW
#else
#define TextOut             TextOutA
#define TabbedTextOut       TabbedTextOutA
#define GetTabbedTextExtent GetTabbedTextExtentA
#endif // UNICODE

    BOOL WINAPI SetViewportOrgEx(HDC hdc, int x, int y, LPPOINT lppt);
    BOOL WINAPI GetViewportOrgEx(HDC hdc, LPPOINT lpPoint);
    BOOL WINAPI OffsetViewportOrgEx(HDC hdc, int x, int y, LPPOINT lppt);
    BOOL WINAPI SetWindowOrgEx(HDC hdc,        // handle to device context
                               int X,          // new x-coordinate of window origin
                               int Y,          // new y-coordinate of window origin
                               LPPOINT lpPoint // original window origin
    );
    BOOL WINAPI SetWindowExtEx(HDC hdc,      // handle to device context
                               int nXExtent, // new horizontal window extent
                               int nYExtent, // new vertical window extent
                               LPSIZE lpSize // original window extent
    );
    int WINAPI FillRect(HDC hDC, CONST RECT *lprc, HBRUSH hbr);
    int WINAPI ClearRect(HDC hdc, const RECT *lprc, COLORREF cr);
    int WINAPI FrameRect(HDC hDC, CONST RECT *lprc, HBRUSH hbr);

    BOOL WINAPI InvertRect(HDC hDC, CONST RECT *lprc);

    BOOL WINAPI MoveToEx(HDC hdc, int x, int y, LPPOINT lpPoint);
    BOOL WINAPI LineTo(HDC hdc,   // device context handle
                       int nXEnd, // x-coordinate of ending point
                       int nYEnd  // y-coordinate of ending point
    );

    BOOL WINAPI Ellipse(HDC hdc, int left, int top, int right, int bottom);

    BOOL WINAPI Pie(HDC hdc, int left, int top, int right, int bottom, int xr1, int yr1, int xr2, int yr2);

    BOOL WINAPI Arc(HDC hdc, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

    BOOL WINAPI GetWorldTransform(HDC hdc, LPXFORM lpxf);
    BOOL WINAPI SetWorldTransform(HDC hdc, CONST XFORM *lpxf);

    enum
    {
        R2_BLACK = 1,
        R2_NOTMERGEPEN,
        R2_MASKNOTPEN,
        R2_NOTCOPYPEN,
        R2_MASKPENNOT,
        R2_NOT,
        R2_XORPEN,
        R2_NOTMASKPEN,
        R2_MASKPEN,
        R2_NOTXORPEN,
        R2_NOP,
        R2_MERGENOTPEN,
        R2_COPYPEN,
        R2_MERGEPENNOT,
        R2_MERGEPEN,
        R2_WHITE,

        R2_EXT_CLEAR,
        R2_EXT_SOURCE,
        R2_EXT_OVER,
        R2_EXT_IN,
        R2_EXT_OUT,
        R2_EXT_ATOP,
        R2_EXT_DEST,
        R2_EXT_DEST_OVER,
        R2_EXT_DEST_IN,
        R2_EXT_DEST_OUT,
        R2_EXT_DEST_ATOP,
        R2_EXT_XOR,
        R2_EXT_ADD,
        R2_EXT_SATURATE,

        R2_LAST
    };

    int WINAPI SetROP2(HDC hdc, int rop2);

    COLORREF WINAPI SetTextColor(HDC hdc, COLORREF color);
    COLORREF WINAPI GetTextColor(HDC hdc);

    typedef USHORT COLOR16;

    typedef struct _TRIVERTEX
    {
        LONG x;
        LONG y;
        COLOR16 Red;
        COLOR16 Green;
        COLOR16 Blue;
        COLOR16 Alpha;
    } TRIVERTEX, *PTRIVERTEX, *LPTRIVERTEX;

    typedef struct _GRADIENT_RECT
    {
        ULONG UpperLeft;
        ULONG LowerRight;
    } GRADIENT_RECT, *PGRADIENT_RECT;

#define GRADIENT_FILL_RECT_H   0x00000000
#define GRADIENT_FILL_RECT_V   0x00000001
#define GRADIENT_FILL_TRIANGLE 0x00000002
#define GRADIENT_FILL_OP_FLAG  0x000000ff

    BOOL WINAPI GradientFill(HDC hdc, TRIVERTEX *pVertices, ULONG nVertices, void *pMesh, ULONG nMeshElements, DWORD dwMode);

/* types of LoadImage */
#define IMAGE_BITMAP      0
#define IMAGE_ICON        1
#define IMAGE_CURSOR      2
#define IMAGE_ENHMETAFILE 3

/* loadflags to LoadImage */
#define LR_DEFAULTCOLOR     0x0000
#define LR_MONOCHROME       0x0001
#define LR_COLOR            0x0002
#define LR_COPYRETURNORG    0x0004
#define LR_COPYDELETEORG    0x0008
#define LR_LOADFROMFILE     0x0010
#define LR_LOADTRANSPARENT  0x0020
#define LR_DEFAULTSIZE      0x0040
#define LR_VGACOLOR         0x0080
#define LR_LOADMAP3DCOLORS  0x1000
#define LR_CREATEDIBSECTION 0x2000
#define LR_COPYFROMRESOURCE 0x4000
#define LR_SHARED           0x8000

/* Flags for DrawIconEx.  */
#define DI_MASK        0x0001
#define DI_IMAGE       0x0002
#define DI_NORMAL      (DI_MASK | DI_IMAGE)
#define DI_COMPAT      0x0004
#define DI_DEFAULTSIZE 0x0008
#define DI_NOMIRROR    0x0010

    /* Device parameters for GetDeviceCaps() */
#define DRIVERVERSION 0
#define TECHNOLOGY    2
#define HORZSIZE      4
#define VERTSIZE      6
#define HORZRES       8
#define VERTRES       10
#define BITSPIXEL     12
#define PLANES        14
#define NUMBRUSHES    16
#define NUMPENS       18
#define NUMMARKERS    20
#define NUMFONTS      22
#define NUMCOLORS     24
#define PDEVICESIZE   26
#define CURVECAPS     28
#define LINECAPS      30
#define POLYGONALCAPS 32
#define TEXTCAPS      34
#define CLIPCAPS      36
#define RASTERCAPS    38
#define ASPECTX       40
#define ASPECTY       42
#define ASPECTXY      44
#define LOGPIXELSX    88
#define LOGPIXELSY    90
#define CAPS1         94
#define SIZEPALETTE   104
#define NUMRESERVED   106
#define COLORRES      108

/* Device Technologies */
#define DT_PLOTTER    0 /* Vector plotter                   */
#define DT_RASDISPLAY 1 /* Raster display                   */
#define DT_RASPRINTER 2 /* Raster printer                   */
#define DT_RASCAMERA  3 /* Raster camera                    */
#define DT_CHARSTREAM 4 /* Character-stream, PLP            */
#define DT_METAFILE   5 /* Metafile, VDM                    */
#define DT_DISPFILE   6 /* Display-file                     */

#define PHYSICALWIDTH   110
#define PHYSICALHEIGHT  111
#define PHYSICALOFFSETX 112
#define PHYSICALOFFSETY 113
#define SCALINGFACTORX  114
#define SCALINGFACTORY  115
#define VREFRESH        116
#define DESKTOPVERTRES  117
#define DESKTOPHORZRES  118
#define BLTALIGNMENT    119
#define SHADEBLENDCAPS  120
#define COLORMGMTCAPS   121

    int WINAPI GetDeviceCaps(HDC hdc, int cap);

    HANDLE WINAPI LoadImageW(HINSTANCE hinst, LPCWSTR name, UINT type, INT desiredx, INT desiredy, UINT loadflags);
    HANDLE WINAPI LoadImageA(HINSTANCE hinst, LPCSTR name, UINT type, INT desiredx, INT desiredy, UINT loadflags);

#ifdef _UNICODE
#define LoadImage LoadImageW
#else
#define LoadImage LoadImageA
#endif

    HANDLE WINAPI LoadImageBuf(const void *buf, UINT length, UINT type, INT desiredx, INT desiredy, UINT loadflags);

    HBITMAP WINAPI CreateBitmap(INT width, INT height, UINT planes, UINT bpp, const void *bits);

    void WINAPI SetStretchBltMode(HDC hdc, int mode);

    HICON WINAPI CreateIconIndirect(PICONINFO piconinfo);

    BOOL WINAPI GetIconInfo(HICON hIcon, PICONINFO piconinfo);

    BOOL WINAPI DrawIcon(HDC hDC, int X, int Y, HICON hIcon);

    BOOL WINAPI DrawIconEx(HDC hdc, int xLeft, int yTop, HICON hIcon, int cxWidth, int cyWidth, UINT istepIfAniCur, HBRUSH hbrFlickerFreeDraw, UINT diFlags);

    BOOL WINAPI DestroyIcon(HICON hIcon);

    HICON WINAPI CreateIconFromResourceEx(LPBYTE bits, UINT cbSize, BOOL bIcon, DWORD dwVersion, INT width, INT height, UINT cFlag);

    INT WINAPI LookupIconIdFromDirectoryEx(LPBYTE xdir, BOOL bIcon, INT width, INT height, UINT cFlag);

    BOOL WINAPI UpdateDIBPixmap(HBITMAP bmp, int wid, int hei, int bitsPixel, int stride, CONST VOID *pjBits);

    typedef struct tagTEXTMETRICA
    {
        LONG tmHeight;
        LONG tmAscent;
        LONG tmDescent;
        LONG tmInternalLeading;
        LONG tmExternalLeading;
        LONG tmAveCharWidth;
        LONG tmMaxCharWidth;
        LONG tmWeight;
        LONG tmOverhang;
        LONG tmDigitizedAspectX;
        LONG tmDigitizedAspectY;
        BYTE tmFirstChar;
        BYTE tmLastChar;
        BYTE tmDefaultChar;
        BYTE tmBreakChar;
        BYTE tmItalic;
        BYTE tmUnderlined;
        BYTE tmStruckOut;
        BYTE tmPitchAndFamily;
        BYTE tmCharSet;
    } TEXTMETRICA, *PTEXTMETRICA, NEAR *NPTEXTMETRICA, FAR *LPTEXTMETRICA;
    typedef struct tagTEXTMETRICW
    {
        LONG tmHeight;
        LONG tmAscent;
        LONG tmDescent;
        LONG tmInternalLeading;
        LONG tmExternalLeading;
        LONG tmAveCharWidth;
        LONG tmMaxCharWidth;
        LONG tmWeight;
        LONG tmOverhang;
        LONG tmDigitizedAspectX;
        LONG tmDigitizedAspectY;
        WCHAR tmFirstChar;
        WCHAR tmLastChar;
        WCHAR tmDefaultChar;
        WCHAR tmBreakChar;
        BYTE tmItalic;
        BYTE tmUnderlined;
        BYTE tmStruckOut;
        BYTE tmPitchAndFamily;
        BYTE tmCharSet;
    } TEXTMETRICW, *PTEXTMETRICW, NEAR *NPTEXTMETRICW, FAR *LPTEXTMETRICW;

    BOOL WINAPI GetTextMetricsW(HDC hdc, TEXTMETRICW *txtMetric);
    BOOL WINAPI GetTextMetricsA(HDC hdc, TEXTMETRICA *txtMetric);

    int WINAPI GetTextFaceA(HDC hdc,         // handle to DC
                            int nCount,      // length of typeface name buffer
                            LPSTR lpFaceName // typeface name buffer);
    );

    int WINAPI GetTextFaceW(HDC hdc,          // handle to DC
                            int nCount,       // length of typeface name buffer
                            LPWSTR lpFaceName // typeface name buffer);
    );

#ifdef UNICODE
#define TEXTMETRIC     TEXTMETRICW
#define GetTextMetrics GetTextMetricsW
#define GetTextFace    GetTextFaceW
#else
#define TEXTMETRIC     TEXTMETRICA
#define GetTextMetrics GetTextMetricsA
#define GetTextFace    GetTextFaceA
#endif // UNICODE

#define PAN_CULTURE_LATIN 0

    typedef struct tagPANOSE
    {
        BYTE bFamilyType;
        BYTE bSerifStyle;
        BYTE bWeight;
        BYTE bProportion;
        BYTE bContrast;
        BYTE bStrokeVariation;
        BYTE bArmStyle;
        BYTE bLetterform;
        BYTE bMidline;
        BYTE bXHeight;
    } PANOSE, *LPPANOSE;

    BOOL WINAPI Polygon(HDC hdc, const POINT *apt, int cpt);

#define TA_NOUPDATECP 0
#define TA_UPDATECP   1

#define TA_LEFT   0
#define TA_RIGHT  2
#define TA_CENTER 6

#define TA_TOP      0
#define TA_BOTTOM   8
#define TA_BASELINE 24
#if (WINVER >= 0x0400)
#define TA_RTLREADING 256
#define TA_MASK       (TA_BASELINE + TA_CENTER + TA_UPDATECP + TA_RTLREADING)
#else
#define TA_MASK (TA_BASELINE + TA_CENTER + TA_UPDATECP)
#endif

    UINT WINAPI SetTextAlign(HDC hdc, UINT align);
    UINT WINAPI GetTextAlign(HDC hdc);

    COLORREF WINAPI GetNearestColor(HDC hdc,         // handle to DC
                                    COLORREF crColor // color to be matched
    );

#define ETO_OPAQUE  0x0002
#define ETO_CLIPPED 0x0004
#if (WINVER >= 0x0400)
#define ETO_GLYPH_INDEX    0x0010
#define ETO_RTLREADING     0x0080
#define ETO_NUMERICSLOCAL  0x0400
#define ETO_NUMERICSLATIN  0x0800
#define ETO_IGNORELANGUAGE 0x1000
#endif /* WINVER >= 0x0400 */
#if (_WIN32_WINNT >= _WIN32_WINNT_WIN2K)
#define ETO_PDY 0x2000
#endif // (_WIN32_WINNT >= _WIN32_WINNT_WIN2K)
#if (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
#define ETO_REVERSE_INDEX_MAP 0x10000
#endif

    BOOL WINAPI ExtTextOutA(HDC hdc,          // handle to DC
                            int X,            // x-coordinate of reference point
                            int Y,            // y-coordinate of reference point
                            UINT fuOptions,   // text-output options
                            CONST RECT *lprc, // optional dimensions
                            LPCSTR lpString,  // string
                            UINT cbCount,     // number of characters in string
                            CONST INT *lpDx   // array of spacing values
    );

    BOOL WINAPI ExtTextOutW(HDC hdc,          // handle to DC
                            int X,            // x-coordinate of reference point
                            int Y,            // y-coordinate of reference point
                            UINT fuOptions,   // text-output options
                            CONST RECT *lprc, // optional dimensions
                            LPCWSTR lpString, // string
                            UINT cbCount,     // number of characters in string
                            CONST INT *lpDx   // array of spacing values
    );

#ifdef UNICODE
#define ExtTextOut ExtTextOutW
#else
#define ExtTextOut ExtTextOutA
#endif // UNICODE

    typedef enum Antialias
    {
        ANTIALIAS_DEFAULT = 0,

        /* method */
        ANTIALIAS_NONE,
        ANTIALIAS_GRAY,
        ANTIALIAS_SUBPIXEL,

        /* hints */
        ANTIALIAS_FAST,
        ANTIALIAS_GOOD,
        ANTIALIAS_BEST
    } Antialias;

    Antialias WINAPI GetAntialiasMode(HDC hdc);
    Antialias WINAPI SetAntialiasMode(HDC hdc, Antialias mode);

    COLORREF WINAPI GetPixel(IN HDC hdc, IN int x, IN int y);
    COLORREF WINAPI SetPixel(IN HDC hdc, IN int x, IN int y, IN COLORREF color);

#define PC_RESERVED   0x01 /* palette index used for animation */
#define PC_EXPLICIT   0x02 /* palette index is explicit to device */
#define PC_NOCOLLAPSE 0x04 /* do not match color to system palette */

    typedef struct tagPALETTEENTRY
    {
        BYTE peRed;
        BYTE peGreen;
        BYTE peBlue;
        BYTE peFlags;
    } PALETTEENTRY;

    typedef struct tagLOGPALETTE
    {
        WORD palVersion;
        WORD palNumEntries;
        PALETTEENTRY palPalEntry[1];
    } LOGPALETTE;

    typedef struct tagKERNINGPAIR
    {
        WORD wFirst;
        WORD wSecond;
        int iKernAmount;
    } KERNINGPAIR, *LPKERNINGPAIR;

    typedef struct tagFONTSIGNATURE
    {
        DWORD fsUsb[4];
        DWORD fsCsb[2];
    } FONTSIGNATURE, *PFONTSIGNATURE, FAR *LPFONTSIGNATURE;

    typedef struct _ABC
    {
        int abcA;
        UINT abcB;
        int abcC;
    } ABC, *PABC, NEAR *NPABC, FAR *LPABC;

    typedef struct _ABCFLOAT
    {
        FLOAT abcfA;
        FLOAT abcfB;
        FLOAT abcfC;
    } ABCFLOAT, *PABCFLOAT, NEAR *NPABCFLOAT, FAR *LPABCFLOAT;

#define OUT_DEFAULT_PRECIS        0
#define OUT_STRING_PRECIS         1
#define OUT_CHARACTER_PRECIS      2
#define OUT_STROKE_PRECIS         3
#define OUT_TT_PRECIS             4
#define OUT_DEVICE_PRECIS         5
#define OUT_RASTER_PRECIS         6
#define OUT_TT_ONLY_PRECIS        7
#define OUT_OUTLINE_PRECIS        8
#define OUT_SCREEN_OUTLINE_PRECIS 9
#define OUT_PS_ONLY_PRECIS        10

#define CLIP_DEFAULT_PRECIS   0
#define CLIP_CHARACTER_PRECIS 1
#define CLIP_STROKE_PRECIS    2
#define CLIP_MASK             0xf

#define DEFAULT_QUALITY        0
#define DRAFT_QUALITY          1
#define PROOF_QUALITY          2
#define NONANTIALIASED_QUALITY 3
#define ANTIALIASED_QUALITY    4

#define DEFAULT_PITCH  0
#define FIXED_PITCH    1
#define VARIABLE_PITCH 2

    UINT WINAPI RealizePalette(_In_ HDC hdc);
    HPALETTE WINAPI SelectPalette(_In_ HDC hdc, _In_ HPALETTE hPal, _In_ BOOL bForceBkgd);

    BOOL WINAPI DPtoLP(HDC hdc,          // handle to device context
                       LPPOINT lpPoints, // array of points
                       int nCount        // count of points in array
    );

    BOOL WINAPI LPtoDP(HDC hdc,          // handle to device context
                       LPPOINT lpPoints, // array of points
                       int nCount        // count of points in array
    );

#define CLR_INVALID 0x00FFFFFF

    BOOL WINAPI DrawFrameControl(_In_ HDC, _Inout_ LPRECT, _In_ UINT, _In_ UINT);

    BOOL WINAPI GetCharWidthA(_In_ HDC hdc, _In_ UINT iFirst, _In_ UINT iLast, _Out_writes_(iLast + 1 - iFirst) LPINT lpBuffer);
    BOOL WINAPI GetCharWidthW(_In_ HDC hdc, _In_ UINT iFirst, _In_ UINT iLast, _Out_writes_(iLast + 1 - iFirst) LPINT lpBuffer);
#ifdef UNICODE
#define GetCharWidth GetCharWidthW
#else
#define GetCharWidth GetCharWidthA
#endif // !UNICODE

    HDC WINAPI CreateICW(LPCWSTR lpszDriver,   // driver name
                         LPCWSTR lpszDevice,   // device name
                         LPCWSTR lpszOutput,   // port or file name
                         CONST void *lpdvmInit // optional initialization data
    );

    HDC WINAPI CreateICA(LPCSTR lpszDriver,    // driver name
                         LPCSTR lpszDevice,    // device name
                         LPCSTR lpszOutput,    // port or file name
                         CONST void *lpdvmInit // optional initialization data
    );

    BOOL WINAPI DrawEdge(HDC hdc, LPRECT rc, UINT edge, UINT flags);



    int WINAPI AddFontResource(  LPCSTR lpszFilename  );
    int WINAPI AddFontResourceEx(  LPCSTR lpszFilename, // font file name
                        DWORD fl,             // font characteristics
                        PVOID pdv             // reserved
    );

#ifdef __cplusplus
}
#endif //__cplusplus
#endif //_LINUX_GDI_H_