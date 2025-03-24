#ifndef __WINUSER_H_
#define __WINUSER_H_

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#ifndef WINVER
#define WINVER 0x0600
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif

#define VER_PLATFORM_WIN32s        0
#define VER_PLATFORM_WIN32_WINDOWS 1
#define VER_PLATFORM_WIN32_NT      2

    typedef LRESULT(CALLBACK *WNDPROC)(HWND, UINT, WPARAM, LPARAM);

/*
 * ShowWindow() Commands
 */
#define SW_HIDE            0
#define SW_SHOWNORMAL      1
#define SW_NORMAL          1
#define SW_SHOWMINIMIZED   2
#define SW_SHOWMAXIMIZED   3
#define SW_MAXIMIZE        3
#define SW_SHOWNOACTIVATE  4
#define SW_SHOW            5
#define SW_MINIMIZE        6
#define SW_SHOWMINNOACTIVE 7
#define SW_SHOWNA          8
#define SW_RESTORE         9
#define SW_SHOWDEFAULT     10
#define SW_FORCEMINIMIZE   11
#define SW_MAX             11

    /*
     * Window Messages
     */

#define WM_NULL    0x0000
#define WM_CREATE  0x0001
#define WM_DESTROY 0x0002
#define WM_MOVE    0x0003
#define WM_SIZE    0x0005

#define WM_ACTIVATE 0x0006
/*
 * WM_ACTIVATE state values
 */
#define WA_INACTIVE    0
#define WA_ACTIVE      1
#define WA_CLICKACTIVE 2

#define WM_SETFOCUS        0x0007
#define WM_KILLFOCUS       0x0008
#define WM_ENABLE          0x000A
#define WM_SETREDRAW       0x000B
#define WM_SETTEXT         0x000C
#define WM_GETTEXT         0x000D
#define WM_GETTEXTLENGTH   0x000E
#define WM_PAINT           0x000F
#define WM_CLOSE           0x0010
#define WM_QUERYENDSESSION 0x0011
#define WM_QUERYOPEN       0x0013
#define WM_ENDSESSION      0x0016
#define WM_QUIT            0x0012
#define WM_ERASEBKGND      0x0014
#define WM_SYSCOLORCHANGE  0x0015
#define WM_SHOWWINDOW      0x0018
#define WM_CTLCOLOR        0x0019 /* Added from windowsx.h */
#define WM_WININICHANGE    0x001A
#define WM_SETTINGCHANGE   WM_WININICHANGE

#define WM_ACTIVATEAPP   0x001C
#define WM_FONTCHANGE    0x001D
#define WM_CANCELMODE    0x001F
#define WM_SETCURSOR     0x0020
#define WM_MOUSEACTIVATE 0x0021
#define WM_CHILDACTIVATE 0x0022

#define WM_GETMINMAXINFO 0x0024
#define WM_NEXTDLGCTL    0x0028

    /*
     * Struct pointed to by WM_GETMINMAXINFO lParam
     */
    typedef struct tagMINMAXINFO
    {
        POINT ptReserved;
        POINT ptMaxSize;
        POINT ptMaxPosition;
        POINT ptMinTrackSize;
        POINT ptMaxTrackSize;
    } MINMAXINFO, *PMINMAXINFO, *LPMINMAXINFO;

#define WM_DRAWITEM          0x002B
#define WM_MEASUREITEM       0x002C
#define WM_DELETEITEM        0x002D
#define WM_VKEYTOITEM        0x002E
#define WM_CHARTOITEM        0x002F
#define WM_SETFONT           0x0030
#define WM_GETFONT           0x0031
#define WM_SETHOTKEY         0x0032
#define WM_GETHOTKEY         0x0033
#define WM_QUERYDRAGICON     0x0037
#define WM_COMPAREITEM       0x0039
#define WM_GETOBJECT         0x003D
#define WM_WINDOWPOSCHANGING 0x0046
#define WM_WINDOWPOSCHANGED  0x0047

#define WM_POWER 0x0048
/*
 * wParam for WM_POWER window message and DRV_POWER driver notification
 */
#define PWR_OK             1
#define PWR_FAIL           (-1)
#define PWR_SUSPENDREQUEST 1
#define PWR_SUSPENDRESUME  2
#define PWR_CRITICALRESUME 3

#define WM_COPYDATA 0x004A

    /*
     * lParam of WM_COPYDATA message points to...
     */
    typedef struct tagCOPYDATASTRUCT
    {
        ULONG_PTR dwData;
        DWORD cbData;
        PVOID lpData;
    } COPYDATASTRUCT, *PCOPYDATASTRUCT;

#define WM_NOTIFY                 0x004E
#define WM_INPUTLANGCHANGEREQUEST 0x0050
#define WM_INPUTLANGCHANGE        0x0051
#define WM_TCARD                  0x0052
#define WM_HELP                   0x0053
#define WM_USERCHANGED            0x0054
#define WM_NOTIFYFORMAT           0x0055

#define WM_CONTEXTMENU   0x007B
#define WM_STYLECHANGING 0x007C
#define WM_STYLECHANGED  0x007D
#define WM_DISPLAYCHANGE 0x007E
#define WM_GETICON       0x007F
#define WM_SETICON       0x0080

#define WM_NCCREATE        0x0081
#define WM_NCDESTROY       0x0082
#define WM_NCCALCSIZE      0x0083
#define WM_NCHITTEST       0x0084
#define WM_NCPAINT         0x0085
#define WM_NCACTIVATE      0x0086
#define WM_GETDLGCODE      0x0087
#define WM_NCMOUSEMOVE     0x00A0
#define WM_NCLBUTTONDOWN   0x00A1
#define WM_NCLBUTTONUP     0x00A2
#define WM_NCLBUTTONDBLCLK 0x00A3
#define WM_NCRBUTTONDOWN   0x00A4
#define WM_NCRBUTTONUP     0x00A5
#define WM_NCRBUTTONDBLCLK 0x00A6
#define WM_NCMBUTTONDOWN   0x00A7
#define WM_NCMBUTTONUP     0x00A8
#define WM_NCMBUTTONDBLCLK 0x00A9

#define WM_KEYFIRST    0x0100
#define WM_KEYDOWN     0x0100
#define WM_KEYUP       0x0101
#define WM_CHAR        0x0102
#define WM_DEADCHAR    0x0103
#define WM_SYSKEYDOWN  0x0104
#define WM_SYSKEYUP    0x0105
#define WM_SYSCHAR     0x0106
#define WM_SYSDEADCHAR 0x0107
#define WM_UNICHAR     0x0109
#define WM_KEYLAST     0x0109
#define UNICODE_NOCHAR 0xFFFF

#define WM_IME_STARTCOMPOSITION 0x010D
#define WM_IME_ENDCOMPOSITION   0x010E
#define WM_IME_COMPOSITION      0x010F
#define WM_IME_KEYLAST          0x010F

#define WM_INITDIALOG    0x0110
#define WM_COMMAND       0x0111
#define WM_SYSCOMMAND    0x0112
#define WM_TIMER         0x0113
#define WM_HSCROLL       0x0114
#define WM_VSCROLL       0x0115
#define WM_INITMENU      0x0116
#define WM_INITMENUPOPUP 0x0117
#define WM_MENUSELECT    0x011F
#define WM_MENUCHAR      0x0120
#define WM_ENTERIDLE     0x0121

#define WM_MOUSEFIRST    0x0200
#define WM_MOUSEMOVE     0x0200
#define WM_LBUTTONDOWN   0x0201
#define WM_LBUTTONUP     0x0202
#define WM_LBUTTONDBLCLK 0x0203
#define WM_RBUTTONDOWN   0x0204
#define WM_RBUTTONUP     0x0205
#define WM_RBUTTONDBLCLK 0x0206
#define WM_MBUTTONDOWN   0x0207
#define WM_MBUTTONUP     0x0208
#define WM_MBUTTONDBLCLK 0x0209
#define WM_MOUSEWHEEL    0x020A
#define WM_XBUTTONDOWN   0x020B
#define WM_XBUTTONUP     0x020C
#define WM_XBUTTONDBLCLK 0x020D
#define WM_MOUSEHWHEEL   0x020E

#define WM_MOUSELAST 0x020E

#define WM_CTLCOLORMSGBOX    0x0132
#define WM_CTLCOLOREDIT      0x0133
#define WM_CTLCOLORLISTBOX   0x0134
#define WM_CTLCOLORBTN       0x0135
#define WM_CTLCOLORDLG       0x0136
#define WM_CTLCOLORSCROLLBAR 0x0137
#define WM_CTLCOLORSTATIC    0x0138
#define MN_GETHMENU          0x01E1

#define GET_KEYSTATE_WPARAM(wParam)     (LOWORD(wParam))
#define GET_NCHITTEST_WPARAM(wParam)    ((short)LOWORD(wParam))
#define GET_XBUTTON_WPARAM(wParam)      (HIWORD(wParam))

/* Value for rolling one detent */
#define WHEEL_DELTA                    120
#define GET_WHEEL_DELTA_WPARAM(wParam) ((short)HIWORD(wParam))

/* Setting to scroll one page for SPI_GET/SETWHEELSCROLLLINES */
#define WHEEL_PAGESCROLL (UINT_MAX)

#define WM_PARENTNOTIFY  0x0210
#define WM_ENTERMENULOOP 0x0211
#define WM_EXITMENULOOP  0x0212

#define WM_NEXTMENU       0x0213
#define WM_SIZING         0x0214
#define WM_CAPTURECHANGED 0x0215
#define WM_MOVING         0x0216

#define WM_ENTERSIZEMOVE 0x0231
#define WM_EXITSIZEMOVE  0x0232
#define WM_DROPFILES     0x0233

#define WM_IME_SETCONTEXT      0x0281
#define WM_IME_NOTIFY          0x0282
#define WM_IME_CONTROL         0x0283
#define WM_IME_COMPOSITIONFULL 0x0284
#define WM_IME_SELECT          0x0285
#define WM_IME_CHAR            0x0286
#define WM_IME_REQUEST         0x0288
#define WM_IME_KEYDOWN         0x0290
#define WM_IME_KEYUP           0x0291

#define WM_MOUSEHOVER   0x02A1
#define WM_MOUSELEAVE   0x02A3
#define WM_NCMOUSEHOVER 0x02A0
#define WM_NCMOUSELEAVE 0x02A2

#define WM_CUT               0x0300
#define WM_COPY              0x0301
#define WM_PASTE             0x0302
#define WM_CLEAR             0x0303
#define WM_UNDO              0x0304
#define WM_RENDERFORMAT      0x0305
#define WM_RENDERALLFORMATS  0x0306
#define WM_DESTROYCLIPBOARD  0x0307
#define WM_DRAWCLIPBOARD     0x0308
#define WM_PAINTCLIPBOARD    0x0309
#define WM_VSCROLLCLIPBOARD  0x030A
#define WM_SIZECLIPBOARD     0x030B
#define WM_ASKCBFORMATNAME   0x030C
#define WM_CHANGECBCHAIN     0x030D
#define WM_HSCROLLCLIPBOARD  0x030E
#define WM_QUERYNEWPALETTE   0x030F
#define WM_PALETTEISCHANGING 0x0310
#define WM_PALETTECHANGED    0x0311
#define WM_HOTKEY            0x0312

#define WM_PRINT       0x0317
#define WM_PRINTCLIENT 0x0318

#define WM_MSG_W2A   0x0330 //
#define WM_INTERNAL  0x0350 // internal message
#define WM_REG_FIRST 0x2000 // registered message start
#define WM_APP       0x8000

#define QS_KEY            0x0001                                                        //队列中WM_KEYUP、WM_KEYDOWN、WM_SYSKEYUP或WM_SYSKEYDOWN消息。
#define QS_MOUSEMOVE      0x0002                                                        // 	队列中WM_MOUSEMOVE消息。
#define QS_MOUSEBUTTON    0x0004                                                        // 	鼠标按钮消息 (WM_LBUTTONUP、 WM_RBUTTONDOWN等) 。
#define QS_POSTMESSAGE    0x0008                                                        // 	队列中) (此处列出的消息以外的消息。 有关详细信息，请参阅 PostMessage。无论是否在筛选消息，调用 GetMessage 或 PeekMessage 时，此值都将被清除。
#define QS_TIMER          0x0010                                                        // 	队列中WM_TIMER消息。
#define QS_PAINT          0x0020                                                        // 	队列中WM_PAINT消息。
#define QS_SENDMESSAGE    0x0040                                                        // 	另一个线程或应用程序发送的消息在队列中。 有关详细信息，请参阅 SendMessage。
#define QS_HOTKEY         0x0080                                                        // 	队列中WM_HOTKEY消息。
#define QS_ALLPOSTMESSAGE 0x0100                                                        // 	队列中) (此处列出的消息以外的消息。 有关详细信息，请参阅 PostMessage。调用 GetMessage 或 PeekMessage 而不筛选消息时，将清除此值。
#define QS_RAWINPUT       0x0400                                                        // 	Windows XP 及更新版本：原始输入消息位于队列中。 有关详细信息，请参阅 原始输入。
#define QS_TOUCH          0x0800                                                        // 	Windows 8及更新：触摸输入消息在队列中。 有关详细信息，请参阅 触摸输入。
#define QS_POINTER        0x1000                                                        // 	Windows 8及更新：指针输入消息位于队列中。 有关详细信息，请参阅 指针输入。
#define QS_MOUSE          (QS_MOUSEMOVE | QS_MOUSEBUTTON)                               // 	WM_LBUTTONUP、WM_RBUTTONDOWN等 (WM_MOUSEMOVE消息或鼠标按钮消息。
#define QS_INPUT          (QS_MOUSE | QS_KEY | QS_RAWINPUT | QS_TOUCH | QS_POINTER)     //	输入消息位于队列中。
#define QS_ALLEVENTS      (QS_INPUT | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY) // 	输入、 WM_TIMER、 WM_PAINT、 WM_HOTKEY或发布的消息在队列中。
#define QS_ALLINPUT       (QS_INPUT | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY | QS_SENDMESSAGE)

/*
 * NOTE: All Message Numbers below 0x0400 are RESERVED.
 *
 * Private Window Messages Start Here:
 */
#define WM_USER 0x0400

/*
 * WM_NCHITTEST and MOUSEHOOKSTRUCT Mouse Position Codes
 */
#define HTERROR       (-2)
#define HTTRANSPARENT (-1)
#define HTNOWHERE     0
#define HTCLIENT      1
#define HTCAPTION     2
#define HTSYSMENU     3
#define HTGROWBOX     4
#define HTSIZE        HTGROWBOX
#define HTMENU        5
#define HTHSCROLL     6
#define HTVSCROLL     7
#define HTMINBUTTON   8
#define HTMAXBUTTON   9
#define HTLEFT        10
#define HTRIGHT       11
#define HTTOP         12
#define HTTOPLEFT     13
#define HTTOPRIGHT    14
#define HTBOTTOM      15
#define HTBOTTOMLEFT  16
#define HTBOTTOMRIGHT 17
#define HTBORDER      18
#define HTREDUCE      HTMINBUTTON
#define HTZOOM        HTMAXBUTTON
#define HTSIZEFIRST   HTLEFT
#define HTSIZELAST    HTBOTTOMRIGHT
#define HTOBJECT      19
#define HTCLOSE       20
#define HTHELP        21

/*
 * SendMessageTimeout values
 */
#define SMTO_NORMAL             0x0000
#define SMTO_BLOCK              0x0001
#define SMTO_ABORTIFHUNG        0x0002
#define SMTO_NOTIMEOUTIFNOTHUNG 0x0008
#define SMTO_ERRORONEXIT        0x0020

/*
 * WM_MOUSEACTIVATE Return Codes
 */
#define MA_ACTIVATE         1
#define MA_ACTIVATEANDEAT   2
#define MA_NOACTIVATE       3
#define MA_NOACTIVATEANDEAT 4

/*
 * WM_SETICON / WM_GETICON Type Codes
 */
#define ICON_SMALL  0
#define ICON_BIG    1
#define ICON_SMALL2 2

/*
 * WM_SIZE message wParam values
 */
#define SIZE_RESTORED  0
#define SIZE_MINIMIZED 1
#define SIZE_MAXIMIZED 2
#define SIZE_MAXSHOW   3
#define SIZE_MAXHIDE   4

/*
 * Obsolete constant names
 */
#define SIZENORMAL     SIZE_RESTORED
#define SIZEICONIC     SIZE_MINIMIZED
#define SIZEFULLSCREEN SIZE_MAXIMIZED
#define SIZEZOOMSHOW   SIZE_MAXSHOW
#define SIZEZOOMHIDE   SIZE_MAXHIDE

    /*
     * WM_WINDOWPOSCHANGING/CHANGED struct pointed to by lParam
     */
    typedef struct tagWINDOWPOS
    {
        HWND hwnd;
        HWND hwndInsertAfter;
        int x;
        int y;
        int cx;
        int cy;
        UINT flags;
    } WINDOWPOS, *LPWINDOWPOS, *PWINDOWPOS;

    /*
     * WM_NCCALCSIZE parameter structure
     */
    typedef struct tagNCCALCSIZE_PARAMS
    {
        RECT rgrc[3];
        PWINDOWPOS lppos;
    } NCCALCSIZE_PARAMS, *LPNCCALCSIZE_PARAMS;

/*
 * WM_NCCALCSIZE "window valid rect" return values
 */
#define WVR_ALIGNTOP    0x0010
#define WVR_ALIGNLEFT   0x0020
#define WVR_ALIGNBOTTOM 0x0040
#define WVR_ALIGNRIGHT  0x0080
#define WVR_HREDRAW     0x0100
#define WVR_VREDRAW     0x0200
#define WVR_REDRAW      (WVR_HREDRAW | WVR_VREDRAW)
#define WVR_VALIDRECTS  0x0400

#ifndef NOKEYSTATES

/*
 * Key State Masks for Mouse Messages
 */
#define MK_LBUTTON 0x0001
#define MK_RBUTTON 0x0002
#define MK_SHIFT   0x0004
#define MK_CONTROL 0x0008
#define MK_MBUTTON 0x0010
#if (_WIN32_WINNT >= 0x0500)
#define MK_XBUTTON1 0x0020
#define MK_XBUTTON2 0x0040
#endif /* _WIN32_WINNT >= 0x0500 */

#endif /* !NOKEYSTATES */

#ifndef NOTRACKMOUSEEVENT
#if (_WIN32_WINNT >= 0x0400)

#define TME_HOVER 0x00000001
#define TME_LEAVE 0x00000002
#if (WINVER >= 0x0500)
#define TME_NONCLIENT 0x00000010
#endif /* WINVER >= 0x0500 */
#define TME_QUERY  0x40000000
#define TME_CANCEL 0x80000000

#define HOVER_DEFAULT 0xFFFFFFFF
#endif /* _WIN32_WINNT >= 0x0400 */

#if (_WIN32_WINNT >= 0x0400)
    typedef struct tagTRACKMOUSEEVENT
    {
        DWORD cbSize;
        DWORD dwFlags;
        HWND hwndTrack;
        DWORD dwHoverTime;
    } TRACKMOUSEEVENT, *LPTRACKMOUSEEVENT;

    BOOL WINAPI TrackMouseEvent(LPTRACKMOUSEEVENT lpEventTrack);
#endif /* _WIN32_WINNT >= 0x0400 */

#if (_WIN32_WINNT >= 0x0400)

#endif /* _WIN32_WINNT >= 0x0400 */

#endif /* !NOTRACKMOUSEEVENT */

#ifndef NOWINSTYLES

/*
 * Window Styles
 */
#define WS_OVERLAPPED   0x00000000L
#define WS_POPUP        0x80000000L
#define WS_CHILD        0x40000000L
#define WS_MINIMIZE     0x20000000L
#define WS_VISIBLE      0x10000000L
#define WS_DISABLED     0x08000000L
#define WS_CLIPSIBLINGS 0x04000000L
#define WS_CLIPCHILDREN 0x02000000L
#define WS_MAXIMIZE     0x01000000L
#define WS_CAPTION      0x00C00000L /* WS_BORDER | WS_DLGFRAME  */
#define WS_BORDER       0x00800000L
#define WS_DLGFRAME     0x00400000L
#define WS_VSCROLL      0x00200000L
#define WS_HSCROLL      0x00100000L
#define WS_SYSMENU      0x00080000L
#define WS_THICKFRAME   0x00040000L
#define WS_GROUP        0x00020000L
#define WS_TABSTOP      0x00010000L

#define WS_MINIMIZEBOX 0x00020000L
#define WS_MAXIMIZEBOX 0x00010000L

#define WS_TILED       WS_OVERLAPPED
#define WS_ICONIC      WS_MINIMIZE
#define WS_SIZEBOX     WS_THICKFRAME
#define WS_TILEDWINDOW WS_OVERLAPPEDWINDOW

/*
 * Common Window Styles
 */
#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)

#define WS_POPUPWINDOW (WS_POPUP | WS_BORDER | WS_SYSMENU)

#define WS_CHILDWINDOW (WS_CHILD)

/*
 * Extended Window Styles
 */
#define WS_EX_DLGMODALFRAME  0x00000001L
#define WS_EX_NOPARENTNOTIFY 0x00000004L
#define WS_EX_TOPMOST        0x00000008L
#define WS_EX_ACCEPTFILES    0x00000010L
#define WS_EX_TRANSPARENT    0x00000020L
#if (WINVER >= 0x0400)
#define WS_EX_MDICHILD    0x00000040L
#define WS_EX_TOOLWINDOW  0x00000080L
#define WS_EX_WINDOWEDGE  0x00000100L
#define WS_EX_CLIENTEDGE  0x00000200L
#define WS_EX_CONTEXTHELP 0x00000400L

#endif /* WINVER >= 0x0400 */
#if (WINVER >= 0x0400)

#define WS_EX_RIGHT          0x00001000L
#define WS_EX_LEFT           0x00000000L
#define WS_EX_RTLREADING     0x00002000L
#define WS_EX_LTRREADING     0x00000000L
#define WS_EX_LEFTSCROLLBAR  0x00004000L
#define WS_EX_RIGHTSCROLLBAR 0x00000000L

#define WS_EX_CONTROLPARENT 0x00010000L
#define WS_EX_STATICEDGE    0x00020000L
#define WS_EX_APPWINDOW     0x00040000L

#define WS_EX_OVERLAPPEDWINDOW (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#define WS_EX_PALETTEWINDOW    (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)

#endif /* WINVER >= 0x0400 */

#if (_WIN32_WINNT >= 0x0500)
#define WS_EX_LAYERED    0x00080000
#define WS_EX_COMPOSITED 0x02000000L
#endif /* _WIN32_WINNT >= 0x0500 */

#if (WINVER >= 0x0500)
#define WS_EX_NOINHERITLAYOUT 0x00100000L // Disable inheritence of mirroring by children
#define WS_EX_LAYOUTRTL       0x00400000L // Right to left mirroring
#endif                                    /* WINVER >= 0x0500 */

#if (_WIN32_WINNT >= 0x0500)
#define WS_EX_NOACTIVATE 0x08000000L
#endif /* _WIN32_WINNT >= 0x0500 */

/*
 * Class styles
 */
#define CS_VREDRAW         0x0001
#define CS_HREDRAW         0x0002
#define CS_DBLCLKS         0x0008
#define CS_OWNDC           0x0020
#define CS_CLASSDC         0x0040
#define CS_PARENTDC        0x0080
#define CS_NOCLOSE         0x0200
#define CS_SAVEBITS        0x0800
#define CS_BYTEALIGNCLIENT 0x1000
#define CS_BYTEALIGNWINDOW 0x2000
#define CS_GLOBALCLASS     0x4000

#define CS_IME 0x00010000
#if (_WIN32_WINNT >= 0x0501)
#define CS_DROPSHADOW 0x00020000
#endif /* _WIN32_WINNT >= 0x0501 */

    //-----------------------------------------------------------------
    typedef struct tagCREATESTRUCT
    {
        LPVOID lpCreateParams;
        HINSTANCE hInstance;
        HMENU hMenu;
        HWND hwndParent;
        uint32_t cy;
        uint32_t cx;
        int y;
        int x;
        LONG style;
        LPCSTR lpszName;
        LPCSTR lpszClass;
        DWORD dwExStyle;
    } CREATESTRUCT, *LPCREATESTRUCT;

#define OCM__BASE   (WM_USER + 0x1c00)
#define OCM_COMMAND (OCM__BASE + WM_COMMAND)

#define OCM_CTLCOLORBTN       (OCM__BASE + WM_CTLCOLORBTN)
#define OCM_CTLCOLOREDIT      (OCM__BASE + WM_CTLCOLOREDIT)
#define OCM_CTLCOLORDLG       (OCM__BASE + WM_CTLCOLORDLG)
#define OCM_CTLCOLORLISTBOX   (OCM__BASE + WM_CTLCOLORLISTBOX)
#define OCM_CTLCOLORMSGBOX    (OCM__BASE + WM_CTLCOLORMSGBOX)
#define OCM_CTLCOLORSCROLLBAR (OCM__BASE + WM_CTLCOLORSCROLLBAR)
#define OCM_CTLCOLORSTATIC    (OCM__BASE + WM_CTLCOLORSTATIC)

#define OCM_DRAWITEM     (OCM__BASE + WM_DRAWITEM)
#define OCM_MEASUREITEM  (OCM__BASE + WM_MEASUREITEM)
#define OCM_DELETEITEM   (OCM__BASE + WM_DELETEITEM)
#define OCM_VKEYTOITEM   (OCM__BASE + WM_VKEYTOITEM)
#define OCM_CHARTOITEM   (OCM__BASE + WM_CHARTOITEM)
#define OCM_COMPAREITEM  (OCM__BASE + WM_COMPAREITEM)
#define OCM_HSCROLL      (OCM__BASE + WM_HSCROLL)
#define OCM_VSCROLL      (OCM__BASE + WM_VSCROLL)
#define OCM_PARENTNOTIFY (OCM__BASE + WM_PARENTNOTIFY)
#define OCM_NOTIFY       (OCM__BASE + WM_NOTIFY)

#define ODT_MENU     1
#define ODT_LISTBOX  2
#define ODT_COMBOBOX 3
#define ODT_BUTTON   4
#define ODT_STATIC   5

#define SM_CXSCREEN          0
#define SM_CYSCREEN          1
#define SM_CXVSCROLL         2
#define SM_CYHSCROLL         3
#define SM_CYCAPTION         4
#define SM_CXBORDER          5
#define SM_CYBORDER          6
#define SM_CXDLGFRAME        7
#define SM_CYDLGFRAME        8
#define SM_CYVTHUMB          9
#define SM_CXHTHUMB          10
#define SM_CXICON            11
#define SM_CYICON            12
#define SM_CXCURSOR          13
#define SM_CYCURSOR          14
#define SM_CYMENU            15
#define SM_CXFULLSCREEN      16
#define SM_CYFULLSCREEN      17
#define SM_CYKANJIWINDOW     18
#define SM_MOUSEPRESENT      19
#define SM_CYVSCROLL         20
#define SM_CXHSCROLL         21
#define SM_DEBUG             22
#define SM_SWAPBUTTON        23
#define SM_RESERVED1         24
#define SM_RESERVED2         25
#define SM_RESERVED3         26
#define SM_RESERVED4         27
#define SM_CXMIN             28
#define SM_CYMIN             29
#define SM_CXSIZE            30
#define SM_CYSIZE            31
#define SM_CXFRAME           32
#define SM_CYFRAME           33
#define SM_CXMINTRACK        34
#define SM_CYMINTRACK        35
#define SM_CXDOUBLECLK       36
#define SM_CYDOUBLECLK       37
#define SM_CXICONSPACING     38
#define SM_CYICONSPACING     39
#define SM_MENUDROPALIGNMENT 40
#define SM_PENWINDOWS        41
#define SM_DBCSENABLED       42
#define SM_CMOUSEBUTTONS     43
#define SM_CXEDGE            45
#define SM_CYEDGE            46

#define SM_CXDRAG 68
#define SM_CYDRAG 69

#define DT_TOP                  0x00000000
#define DT_LEFT                 0x00000000
#define DT_CENTER               0x00000001
#define DT_RIGHT                0x00000002
#define DT_VCENTER              0x00000004
#define DT_BOTTOM               0x00000008
#define DT_WORDBREAK            0x00000010
#define DT_SINGLELINE           0x00000020
#define DT_EXPANDTABS           0x00000040
#define DT_TABSTOP              0x00000080
#define DT_NOCLIP               0x00000100
#define DT_EXTERNALLEADING      0x00000200
#define DT_CALCRECT             0x00000400
#define DT_NOPREFIX             0x00000800
#define DT_INTERNAL             0x00001000
#define DT_EDITCONTROL          0x00002000
#define DT_PATH_ELLIPSIS        0x00004000
#define DT_END_ELLIPSIS         0x00008000
#define DT_MODIFYSTRING         0x00010000
#define DT_RTLREADING           0x00020000
#define DT_WORD_ELLIPSIS        0x00040000
#define DT_NOFULLWIDTHCHARBREAK 0x00080000
#define DT_HIDEPREFIX           0x00100000
#define DT_PREFIXONLY           0x00200000

/*
 * Virtual Keys, Standard Set
 */
#define VK_LBUTTON 0x01
#define VK_RBUTTON 0x02
#define VK_CANCEL  0x03
#define VK_MBUTTON 0x04 /* NOT contiguous with L & RBUTTON */

    /*
     * 0x07 : unassigned
     */

#define VK_BACK 0x08
#define VK_TAB  0x09

    /*
     * 0x0A - 0x0B : reserved
     */

#define VK_CLEAR  0x0C
#define VK_RETURN 0x0D

#define VK_SHIFT   0x10
#define VK_CONTROL 0x11
#define VK_MENU    0x12
#define VK_PAUSE   0x13
#define VK_CAPITAL 0x14

#define VK_KANA    0x15
#define VK_HANGEUL 0x15 /* old name - should be here for compatibility */
#define VK_HANGUL  0x15
#define VK_JUNJA   0x17
#define VK_FINAL   0x18
#define VK_HANJA   0x19
#define VK_KANJI   0x19

#define VK_ESCAPE 0x1B

#define VK_CONVERT    0x1C
#define VK_NONCONVERT 0x1D
#define VK_ACCEPT     0x1E
#define VK_MODECHANGE 0x1F

#define VK_SPACE    0x20
#define VK_PRIOR    0x21
#define VK_NEXT     0x22
#define VK_END      0x23
#define VK_HOME     0x24
#define VK_LEFT     0x25
#define VK_UP       0x26
#define VK_RIGHT    0x27
#define VK_DOWN     0x28
#define VK_SELECT   0x29
#define VK_PRINT    0x2A
#define VK_EXECUTE  0x2B
#define VK_SNAPSHOT 0x2C
#define VK_INSERT   0x2D
#define VK_DELETE   0x2E
#define VK_HELP     0x2F

    /*
     * VK_0 - VK_9 are the same as ASCII '0' - '9' (0x30 - 0x39)
     * 0x40 : unassigned
     * VK_A - VK_Z are the same as ASCII 'A' - 'Z' (0x41 - 0x5A)
     */

#define VK_LWIN 0x5B
#define VK_RWIN 0x5C
#define VK_APPS 0x5D

    /*
     * 0x5E : reserved
     */

#define VK_SLEEP 0x5F

#define VK_NUMPAD0   0x60
#define VK_NUMPAD1   0x61
#define VK_NUMPAD2   0x62
#define VK_NUMPAD3   0x63
#define VK_NUMPAD4   0x64
#define VK_NUMPAD5   0x65
#define VK_NUMPAD6   0x66
#define VK_NUMPAD7   0x67
#define VK_NUMPAD8   0x68
#define VK_NUMPAD9   0x69
#define VK_MULTIPLY  0x6A
#define VK_ADD       0x6B
#define VK_SEPARATOR 0x6C
#define VK_SUBTRACT  0x6D
#define VK_DECIMAL   0x6E
#define VK_DIVIDE    0x6F
#define VK_F1        0x70
#define VK_F2        0x71
#define VK_F3        0x72
#define VK_F4        0x73
#define VK_F5        0x74
#define VK_F6        0x75
#define VK_F7        0x76
#define VK_F8        0x77
#define VK_F9        0x78
#define VK_F10       0x79
#define VK_F11       0x7A
#define VK_F12       0x7B
#define VK_F13       0x7C
#define VK_F14       0x7D
#define VK_F15       0x7E
#define VK_F16       0x7F
#define VK_F17       0x80
#define VK_F18       0x81
#define VK_F19       0x82
#define VK_F20       0x83
#define VK_F21       0x84
#define VK_F22       0x85
#define VK_F23       0x86
#define VK_F24       0x87

    /*
     * 0x88 - 0x8F : unassigned
     */

#define VK_NUMLOCK 0x90
#define VK_SCROLL  0x91

/*
 * NEC PC-9800 kbd definitions
 */
#define VK_OEM_NEC_EQUAL 0x92 // '=' key on numpad

/*
 * Fujitsu/OASYS kbd definitions
 */
#define VK_OEM_FJ_JISHO   0x92 // 'Dictionary' key
#define VK_OEM_FJ_MASSHOU 0x93 // 'Unregister word' key
#define VK_OEM_FJ_TOUROKU 0x94 // 'Register word' key
#define VK_OEM_FJ_LOYA    0x95 // 'Left OYAYUBI' key
#define VK_OEM_FJ_ROYA    0x96 // 'Right OYAYUBI' key

/*
 * 0x97 - 0x9F : unassigned
 */

/*
 * VK_L* & VK_R* - left and right Alt, Ctrl and Shift virtual keys.
 * Used only as parameters to GetAsyncKeyState() and GetKeyState().
 * No other API or message will distinguish left and right keys in this way.
 */
#define VK_LSHIFT   0xA0
#define VK_RSHIFT   0xA1
#define VK_LCONTROL 0xA2
#define VK_RCONTROL 0xA3
#define VK_LMENU    0xA4
#define VK_RMENU    0xA5

    /*
     * 0xB8 - 0xB9 : reserved
     */

#define VK_OEM_1      0xBA // ';:' for US
#define VK_OEM_PLUS   0xBB // '+' any country
#define VK_OEM_COMMA  0xBC // ',' any country
#define VK_OEM_MINUS  0xBD // '-' any country
#define VK_OEM_PERIOD 0xBE // '.' any country
#define VK_OEM_2      0xBF // '/?' for US
#define VK_OEM_3      0xC0 // '`~' for US

    /*
     * 0xC1 - 0xD7 : reserved
     */

    /*
     * 0xD8 - 0xDA : unassigned
     */

#define VK_OEM_4 0xDB //  '[{' for US
#define VK_OEM_5 0xDC //  '\|' for US
#define VK_OEM_6 0xDD //  ']}' for US
#define VK_OEM_7 0xDE //  ''"' for US
#define VK_OEM_8 0xDF

    /*
     * 0xE0 : reserved
     */

    /*
     * Various extended or enhanced keyboards
     */
#define VK_OEM_AX   0xE1 //  'AX' key on Japanese AX kbd
#define VK_OEM_102  0xE2 //  "<>" or "\|" on RT 102-key kbd.
#define VK_ICO_HELP 0xE3 //  Help key on ICO
#define VK_ICO_00   0xE4 //  00 key on ICO

#if (WINVER >= 0x0400)
#define VK_PROCESSKEY 0xE5
#endif /* WINVER >= 0x0400 */

#define VK_ICO_CLEAR 0xE6

/*
 * 0xE0 : reserved
 */

/*
 * Various extended or enhanced keyboards
 */
#define VK_OEM_AX    0xE1 //  'AX' key on Japanese AX kbd
#define VK_OEM_102   0xE2 //  "<>" or "\|" on RT 102-key kbd.
#define VK_ICO_HELP  0xE3 //  Help key on ICO
#define VK_ICO_00    0xE4 //  00 key on ICO
#define VK_ICO_CLEAR 0xE6

/*
 * 0xE8 : unassigned
 */

/*
 * Nokia/Ericsson definitions
 */
#define VK_OEM_RESET   0xE9
#define VK_OEM_JUMP    0xEA
#define VK_OEM_PA1     0xEB
#define VK_OEM_PA2     0xEC
#define VK_OEM_PA3     0xED
#define VK_OEM_WSCTRL  0xEE
#define VK_OEM_CUSEL   0xEF
#define VK_OEM_ATTN    0xF0
#define VK_OEM_FINISH  0xF1
#define VK_OEM_COPY    0xF2
#define VK_OEM_AUTO    0xF3
#define VK_OEM_ENLW    0xF4
#define VK_OEM_BACKTAB 0xF5

#define VK_ATTN      0xF6
#define VK_CRSEL     0xF7
#define VK_EXSEL     0xF8
#define VK_EREOF     0xF9
#define VK_PLAY      0xFA
#define VK_ZOOM      0xFB
#define VK_NONAME    0xFC
#define VK_PA1       0xFD
#define VK_OEM_CLEAR 0xFE

#define MONITOR_DEFAULTTONULL    0x00000000
#define MONITOR_DEFAULTTOPRIMARY 0x00000001
#define MONITOR_DEFAULTTONEAREST 0x00000002

    typedef struct tagMONITORINFO
    {
        DWORD cbSize;
        RECT rcMonitor;
        RECT rcWork;
        DWORD dwFlags;
    } MONITORINFO, *LPMONITORINFO;

#define HWND_DESKTOP   ((HWND)0)
#define HWND_TOP       ((HWND)0)
#define HWND_BOTTOM    ((HWND)1)
#define HWND_TOPMOST   ((HWND)-1)
#define HWND_NOTOPMOST ((HWND)-2)
#define HWND_MESSAGE   ((HWND)-3)
#define HWND_BROADCAST ((HWND)-4)

#define SWP_NOSIZE         0x0001
#define SWP_NOMOVE         0x0002
#define SWP_NOZORDER       0x0004
#define SWP_NOREDRAW       0x0008
#define SWP_NOACTIVATE     0x0010
#define SWP_FRAMECHANGED   0x0020 /* The frame changed: send WM_NCCALCSIZE */
#define SWP_SHOWWINDOW     0x0040
#define SWP_HIDEWINDOW     0x0080
#define SWP_NOCOPYBITS     0x0100
#define SWP_NOOWNERZORDER  0x0200 /* Don't do owner Z ordering */
#define SWP_NOSENDCHANGING 0x0400 /* Don't send WM_WINDOWPOSCHANGING */

#define SWP_DRAWFRAME    SWP_FRAMECHANGED
#define SWP_NOREPOSITION SWP_NOOWNERZORDER

#define POINTSTOPOINT(pt, pts)                       \
    {                                                \
        (pt).x = (LONG)(SHORT)LOWORD(*(LONG *)&pts); \
        (pt).y = (LONG)(SHORT)HIWORD(*(LONG *)&pts); \
    }

#define POINTTOPOINTS(pt) (MAKELONG((short)((pt).x), (short)((pt).y)))
#define MAKEWPARAM(l, h)  ((WPARAM)(DWORD)MAKELONG(l, h))
#define MAKELPARAM(l, h)  ((LPARAM)(DWORD)MAKELONG(l, h))

#define LWA_COLORKEY 0x00000001
#define LWA_ALPHA    0x00000002

#define IS_INTRESOURCE(_r)  ((((ULONG_PTR)(_r)) >> 16) == 0)
#define MAKEINTRESOURCEA(x) ((LPSTR)(ULONG_PTR)(WORD((x))))
#define MAKEINTRESOURCEW(x) ((LPWSTR)(ULONG_PTR)(WORD((x))))
#ifdef UNICODE
#define MAKEINTRESOURCE MAKEINTRESOURCEW
#else
#define MAKEINTRESOURCE MAKEINTRESOURCEA
#endif // UNICODE

#define MAKEINTATOM(i) (LPTSTR)((ULONG_PTR)((WORD)(i)))
#define INVALID_ATOM   ((ATOM)0)

#define IDC_NODROP MAKEINTRESOURCE(1)
#define IDC_MOVE   MAKEINTRESOURCE(2)
#define IDC_COPY   MAKEINTRESOURCE(3)
#define IDC_LINK   MAKEINTRESOURCE(4)

#define IDC_ARROW       MAKEINTRESOURCE(32512)
#define IDC_IBEAM       MAKEINTRESOURCE(32513)
#define IDC_WAIT        MAKEINTRESOURCE(32514)
#define IDC_CROSS       MAKEINTRESOURCE(32515)
#define IDC_UPARROW     MAKEINTRESOURCE(32516)
#define IDC_SIZE        MAKEINTRESOURCE(32640) /* OBSOLETE: use IDC_SIZEALL */
#define IDC_ICON        MAKEINTRESOURCE(32641) /* OBSOLETE: use IDC_ARROW */
#define IDC_SIZENWSE    MAKEINTRESOURCE(32642)
#define IDC_SIZENESW    MAKEINTRESOURCE(32643)
#define IDC_SIZEWE      MAKEINTRESOURCE(32644)
#define IDC_SIZENS      MAKEINTRESOURCE(32645)
#define IDC_SIZEALL     MAKEINTRESOURCE(32646)
#define IDC_NO          MAKEINTRESOURCE(32648) /*not in win3.1 */
#define IDC_HAND        MAKEINTRESOURCE(32649)
#define IDC_APPSTARTING MAKEINTRESOURCE(32650) /*not in win3.1 */
#define IDC_HELP        MAKEINTRESOURCE(32651)

/*
 * EVENT DEFINITION
 */
#define EVENT_MIN 0x00000001
#define EVENT_MAX 0x7FFFFFFF

#define WAIT_FAILED   ((DWORD)0xFFFFFFFF)
#define WAIT_OBJECT_0 ((STATUS_WAIT_0) + 0)

#define WAIT_ABANDONED   ((STATUS_ABANDONED_WAIT_0) + 0)
#define WAIT_ABANDONED_0 ((STATUS_ABANDONED_WAIT_0) + 0)

#define WAIT_IO_COMPLETION STATUS_USER_APC

#define TPM_LEFTBUTTON   0x0000L
#define TPM_RIGHTBUTTON  0x0002L
#define TPM_LEFTALIGN    0x0000L
#define TPM_CENTERALIGN  0x0004L
#define TPM_RIGHTALIGN   0x0008L
#define TPM_TOPALIGN     0x0000L
#define TPM_VCENTERALIGN 0x0010L
#define TPM_BOTTOMALIGN  0x0020L

#define TPM_HORIZONTAL 0x0000L /* Horz alignment matters more */
#define TPM_VERTICAL   0x0040L /* Vert alignment matters more */
#define TPM_NONOTIFY   0x0080L /* Don't send any notification msgs */
#define TPM_RETURNCMD  0x0100L

/* CallMsgFilter() values */
#define MSGF_DIALOGBOX  0
#define MSGF_MESSAGEBOX 1
#define MSGF_MENU       2
#define MSGF_MOVE       3
#define MSGF_SIZE       4
#define MSGF_SCROLLBAR  5
#define MSGF_NEXTWINDOW 6
#define MSGF_MAX        8
#define MSGF_USER       0x1000
#define MSGF_DDEMGR     0x8001

    /* Hook values */
    enum
    {
        WH_MIN = 0,
        WH_MSGFILTER = 0,
        WH_KEYBOARD,
        WH_GETMESSAGE,
        WH_CALLWNDPROC,
        WH_SYSMSGFILTER,
        WH_MOUSE,
        WH_CALLWNDPROCRET,
        WH_MAX,
    };

#define WH_MINHOOK WH_MIN
#define WH_MAXHOOK WH_MAX

/* Hook action codes */
#define HC_ACTION      0
#define HC_GETNEXT     1
#define HC_SKIP        2
#define HC_NOREMOVE    3
#define HC_NOREM       HC_NOREMOVE
#define HC_SYSMODALON  4
#define HC_SYSMODALOFF 5

    /* Mouse hook structure */
    typedef struct
    {
        POINT pt;
        HWND hwnd;
        UINT wHitTestCode;
        ULONG_PTR dwExtraInfo;
    } MOUSEHOOKSTRUCT, *PMOUSEHOOKSTRUCT, *LPMOUSEHOOKSTRUCT;

    typedef struct
    {
        struct
        { /* MOUSEHOOKSTRUCT */
            POINT pt;
            HWND hwnd;
            UINT wHitTestCode;
            ULONG_PTR dwExtraInfo;
        } DUMMYSTRUCTNAME;
        DWORD mouseData;
    } MOUSEHOOKSTRUCTEX, *PMOUSEHOOKSTRUCTEX, *LPMOUSEHOOKSTRUCTEX;

    typedef struct
    {
        LPARAM lParam;
        WPARAM wParam;
        UINT message;
        HWND hwnd;
    } CWPSTRUCT, *PCWPSTRUCT, *LPCWPSTRUCT;

    typedef struct
    {
        LRESULT lResult;
        LPARAM lParam;
        WPARAM wParam;
        DWORD message;
        HWND hwnd;
    } CWPRETSTRUCT, *PCWPRETSTRUCT, *LPCWPRETSTRUCT;

#define MB_OK               0x00000000L
#define MB_OKCANCEL         0x00000001L
#define MB_ABORTRETRYIGNORE 0x00000002L
#define MB_YESNOCANCEL      0x00000003L
#define MB_YESNO            0x00000004L
#define MB_RETRYCANCEL      0x00000005L
#if (WINVER >= 0x0500)
#define MB_CANCELTRYCONTINUE 0x00000006L
#endif /* WINVER >= 0x0500 */

#define MB_ICONHAND        0x00000010L
#define MB_ICONQUESTION    0x00000020L
#define MB_ICONEXCLAMATION 0x00000030L
#define MB_ICONASTERISK    0x00000040L

#define MB_USERICON    0x00000080L
#define MB_ICONWARNING MB_ICONEXCLAMATION
#define MB_ICONERROR   MB_ICONHAND

#define MB_ICONINFORMATION MB_ICONASTERISK
#define MB_ICONSTOP        MB_ICONHAND

#define MB_APPLMODAL   0x00000000L
#define MB_SYSTEMMODAL 0x00001000L
#define MB_TASKMODAL   0x00002000L
#if (WINVER >= 0x0400)
#define MB_HELP 0x00004000L // Help Button
#endif                      /* WINVER >= 0x0400 */

#define MB_NOFOCUS              0x00008000L
#define MB_SETFOREGROUND        0x00010000L
#define MB_DEFAULT_DESKTOP_ONLY 0x00020000L

#if (WINVER >= 0x0400)
#define MB_TOPMOST    0x00040000L
#define MB_RIGHT      0x00080000L
#define MB_RTLREADING 0x00100000L

#endif /* WINVER >= 0x0400 */

#define MB_DEFBUTTON1 0x00000000L
#define MB_DEFBUTTON2 0x00000100L
#define MB_DEFBUTTON3 0x00000200L
#define MB_DEFBUTTON4 0x00000300L

#define GWL_WNDPROC    (-4)
#define GWL_HINSTANCE  (-6)
#define GWL_HWNDPARENT (-8)
#define GWL_ID         (-12)
#define GWL_STYLE      (-16)
#define GWL_EXSTYLE    (-20)
#define GWL_USERDATA   (-21)
#define GWL_OPAQUE     (-22)

#define GWLP_HWNDPARENT GWL_HWNDPARENT
#define GWLP_WNDPROC    GWL_WNDPROC
#define GWLP_OPAQUE     GWL_OPAQUE
#define GWLP_HINSTANCE  GWL_HINSTANCE
#define GWLP_USERDATA   GWL_USERDATA
#define GWLP_ID         GWL_ID

#define EVENT_OBJECT_FOCUS           0x8005 // hwnd + ID + idChild is focused item
#define EVENT_OBJECT_SELECTION       0x8006 // hwnd + ID + idChild is selected item (if only one), or idChild is OBJID_WINDOW if complex
#define EVENT_OBJECT_SELECTIONADD    0x8007 // hwnd + ID + idChild is item added
#define EVENT_OBJECT_SELECTIONREMOVE 0x8008 // hwnd + ID + idChild is item removed
#define EVENT_OBJECT_SELECTIONWITHIN 0x8009 // hwnd + ID + idChild is parent of changed selected items

    /*
     * NOTES:
     * There is only one "focused" child item in a parent.  This is the place
     * keystrokes are going at a given moment.  Hence only send a notification
     * about where the NEW focus is going.  A NEW item getting the focus already
     * implies that the OLD item is losing it.
     *
     * SELECTION however can be multiple.  Hence the different SELECTION
     * notifications.  Here's when to use each:
     *
     * (1) Send a SELECTION notification in the simple single selection
     *     case (like the focus) when the item with the selection is
     *     merely moving to a different item within a container.  hwnd + ID
     *     is the container control, idChildItem is the new child with the
     *     selection.
     *
     * (2) Send a SELECTIONADD notification when a new item has simply been added
     *     to the selection within a container.  This is appropriate when the
     *     number of newly selected items is very small.  hwnd + ID is the
     *     container control, idChildItem is the new child added to the selection.
     *
     * (3) Send a SELECTIONREMOVE notification when a new item has simply been
     *     removed from the selection within a container.  This is appropriate
     *     when the number of newly selected items is very small, just like
     *     SELECTIONADD.  hwnd + ID is the container control, idChildItem is the
     *     new child removed from the selection.
     *
     * (4) Send a SELECTIONWITHIN notification when the selected items within a
     *     control have changed substantially.  Rather than propagate a large
     *     number of changes to reflect removal for some items, addition of
     *     others, just tell somebody who cares that a lot happened.  It will
     *     be faster an easier for somebody watching to just turn around and
     *     query the container control what the new bunch of selected items
     *     are.
     */

#define EVENT_OBJECT_STATECHANGE 0x800A // hwnd + ID + idChild is item w/ state change
/*
 * Examples of when to send an EVENT_OBJECT_STATECHANGE include
 *      * It is being enabled/disabled (USER does for windows)
 *      * It is being pressed/released (USER does for buttons)
 *      * It is being checked/unchecked (USER does for radio/check buttons)
 */
#define EVENT_OBJECT_LOCATIONCHANGE 0x800B // hwnd + ID + idChild is moved/sized item

    /*
     * Note:
     * A LOCATIONCHANGE is not sent for every child object when the parent
     * changes shape/moves.  Send one notification for the topmost object
     * that is changing.  For example, if the user resizes a top level window,
     * USER will generate a LOCATIONCHANGE for it, but not for the menu bar,
     * title bar, scrollbars, etc.  that are also changing shape/moving.
     *
     * In other words, it only generates LOCATIONCHANGE notifications for
     * real windows that are moving/sizing.  It will not generate a LOCATIONCHANGE
     * for every non-floating child window when the parent moves (the children are
     * logically moving also on screen, but not relative to the parent).
     *
     * Now, if the app itself resizes child windows as a result of being
     * sized, USER will generate LOCATIONCHANGEs for those dudes also because
     * it doesn't know better.
     *
     * Note also that USER will generate LOCATIONCHANGE notifications for two
     * non-window sys objects:
     *      (1) System caret
     *      (2) Cursor
     */

#define EVENT_OBJECT_NAMECHANGE        0x800C // hwnd + ID + idChild is item w/ name change
#define EVENT_OBJECT_DESCRIPTIONCHANGE 0x800D // hwnd + ID + idChild is item w/ desc change
#define EVENT_OBJECT_VALUECHANGE       0x800E // hwnd + ID + idChild is item w/ value change
#define EVENT_OBJECT_PARENTCHANGE      0x800F // hwnd + ID + idChild is item w/ new parent
#define EVENT_OBJECT_HELPCHANGE        0x8010 // hwnd + ID + idChild is item w/ help change
#define EVENT_OBJECT_DEFACTIONCHANGE   0x8011 // hwnd + ID + idChild is item w/ def action change
#define EVENT_OBJECT_ACCELERATORCHANGE 0x8012 // hwnd + ID + idChild is item w/ keybd accel change

#define EVENT_OBJECT_INVOKED              0x8013 // hwnd + ID + idChild is item invoked
#define EVENT_OBJECT_TEXTSELECTIONCHANGED 0x8014 // hwnd + ID + idChild is item w? test selection change

/*
 * EVENT_OBJECT_CONTENTSCROLLED
 * Sent when ending the scrolling of a window object.
 *
 * Unlike the similar event (EVENT_SYSTEM_SCROLLEND), this event will be
 * associated with the scrolling window itself. There is no difference
 * between horizontal or vertical scrolling.
 *
 * This event should be posted whenever scroll action is completed, including
 * when it is scrolled by scroll bars, mouse wheel, or keyboard navigations.
 *
 *   example:
 *          hwnd == window that is scrolling
 *          idObject == OBJID_CLIENT
 *          idChild == CHILDID_SELF
 */
#define EVENT_OBJECT_CONTENTSCROLLED 0x8015

#define EVENT_OBJECT_CREATE  0x8000 // hwnd + ID + idChild is created item
#define EVENT_OBJECT_DESTROY 0x8001 // hwnd + ID + idChild is destroyed item
#define EVENT_OBJECT_SHOW    0x8002 // hwnd + ID + idChild is shown item
#define EVENT_OBJECT_HIDE    0x8003 // hwnd + ID + idChild is hidden item
#define EVENT_OBJECT_REORDER 0x8004 // hwnd + ID + idChild is parent of zordering children

#define CHILDID_SELF 0

#define ALTERNATE     1
#define WINDING       2
#define POLYFILL_LAST 2

#define SC_SIZE       0xF000
#define SC_MOVE       0xF010
#define SC_MINIMIZE   0xF020
#define SC_MAXIMIZE   0xF030
#define SC_NEXTWINDOW 0xF040
#define SC_PREVWINDOW 0xF050
#define SC_CLOSE      0xF060
#define SC_VSCROLL    0xF070
#define SC_HSCROLL    0xF080
#define SC_MOUSEMENU  0xF090
#define SC_KEYMENU    0xF100
#define SC_ARRANGE    0xF110
#define SC_RESTORE    0xF120
#define SC_TASKLIST   0xF130
#define SC_SCREENSAVE 0xF140
#define SC_HOTKEY     0xF150

#define MAX_PATH 1000

#pragma pack(push, 1)
    typedef struct tagRGBQUAD
    {
        BYTE rgbBlue;
        BYTE rgbGreen;
        BYTE rgbRed;
        BYTE rgbReserved;
    } RGBQUAD, *LPRGBQUAD;
#pragma pack(pop)

#define MF_BYCOMMAND  0x00000000L
#define MF_BYPOSITION 0x00000400L

#define MF_SEPARATOR 0x00000800L

#define MF_ENABLED  0x00000000L
#define MF_GRAYED   0x00000001L
#define MF_DISABLED 0x00000002L

#define MF_UNCHECKED       0x00000000L
#define MF_CHECKED         0x00000008L
#define MF_USECHECKBITMAPS 0x00000200L

#define MF_STRING    0x00000000L
#define MF_BITMAP    0x00000004L
#define MF_OWNERDRAW 0x00000100L

#define MF_POPUP        0x00000010L
#define MF_MENUBARBREAK 0x00000020L
#define MF_MENUBREAK    0x00000040L

#define MF_UNHILITE 0x00000000L
#define MF_HILITE   0x00000080L

#if (WINVER >= 0x0400)
#define MF_DEFAULT 0x00001000L
#endif /* WINVER >= 0x0400 */
#define MF_SYSMENU 0x00002000L
#define MF_HELP    0x00004000L
#if (WINVER >= 0x0400)
#define MF_RIGHTJUSTIFY 0x00004000L
#endif /* WINVER >= 0x0400 */

#define MF_MOUSESELECT 0x00008000L
#if (WINVER >= 0x0400)
#define MF_END 0x00000080L /* Obsolete -- only used by old RES files */
#endif                     /* WINVER >= 0x0400 */

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

#define DEFAULT_QUALITY 0
#define DRAFT_QUALITY   1
#define PROOF_QUALITY   2
#if (WINVER >= 0x0400)
#define NONANTIALIASED_QUALITY 3
#define ANTIALIASED_QUALITY    4
#endif /* WINVER >= 0x0400 */

#define CLEARTYPE_QUALITY         5
#define CLEARTYPE_NATURAL_QUALITY 6

#define PM_NOREMOVE 0x0000 // Messages are not removed from the queue after processing by PeekMessage.
#define PM_REMOVE   0x0001 // Messages are removed from the queue after processing by PeekMessage.
#define PM_NOYIELD  0x0002 // Prevents the system from releasing any thread that is waiting for the caller to go idle

    BOOL WINAPI SetRect(LPRECT lprc, int xLeft, int yTop, int xRight, int yBottom);

    BOOL WINAPI SetRectEmpty(LPRECT lprc);

    BOOL WINAPI CopyRect(LPRECT lprcDst, CONST RECT *lprcSrc);

    BOOL WINAPI InflateRect(LPRECT lprc, int dx, int dy);

    BOOL WINAPI IntersectRect(LPRECT lprcDst, CONST RECT *lprcSrc1, CONST RECT *lprcSrc2);

    BOOL WINAPI UnionRect(LPRECT lprcDst, CONST RECT *lprcSrc1, CONST RECT *lprcSrc2);

    BOOL WINAPI SubtractRect(LPRECT lprcDst, CONST RECT *lprcSrc1, CONST RECT *lprcSrc2);

    BOOL WINAPI OffsetRect(LPRECT lprc, int dx, int dy);

    BOOL WINAPI IsRectEmpty(CONST RECT *lprc);

    BOOL WINAPI EqualRect(CONST RECT *lprc1, CONST RECT *lprc2);

    BOOL WINAPI PtInRect(CONST RECT *lprc, POINT pt);

/*
 * GetWindow() Constants
 */
#define GW_HWNDFIRST  0
#define GW_HWNDLAST   1
#define GW_HWNDNEXT   2
#define GW_HWNDPREV   3
#define GW_OWNER      4
#define GW_CHILD      5
#define GW_CHILDFIRST GW_CHILD
#define GW_CHILDLAST  6
#define GW_PARENT     7

#define FIELD_OFFSET(type, field)             ((LONG)offsetof(type, field))
#define RTL_FIELD_SIZE(type, field)           (sizeof(((type *)0)->field))
#define RTL_SIZEOF_THROUGH_FIELD(type, field) (FIELD_OFFSET(type, field) + RTL_FIELD_SIZE(type, field))

    typedef struct _ICONINFO
    {
        BOOL fIcon;
        DWORD xHotspot;
        DWORD yHotspot;
        HBITMAP hbmMask;
        HBITMAP hbmColor;
    } ICONINFO, *PICONINFO;

#define COLOR_SCROLLBAR           0
#define COLOR_BACKGROUND          1
#define COLOR_ACTIVECAPTION       2
#define COLOR_INACTIVECAPTION     3
#define COLOR_MENU                4
#define COLOR_WINDOW              5
#define COLOR_WINDOWFRAME         6
#define COLOR_MENUTEXT            7
#define COLOR_WINDOWTEXT          8
#define COLOR_CAPTIONTEXT         9
#define COLOR_ACTIVEBORDER        10
#define COLOR_INACTIVEBORDER      11
#define COLOR_APPWORKSPACE        12
#define COLOR_HIGHLIGHT           13
#define COLOR_HIGHLIGHTTEXT       14
#define COLOR_BTNFACE             15
#define COLOR_BTNSHADOW           16
#define COLOR_GRAYTEXT            17
#define COLOR_BTNTEXT             18
#define COLOR_INACTIVECAPTIONTEXT 19
#define COLOR_BTNHIGHLIGHT        20
/* win95 colors */
#define COLOR_3DDKSHADOW  21
#define COLOR_3DLIGHT     22
#define COLOR_INFOTEXT    23
#define COLOR_INFOBK      24
#define COLOR_DESKTOP     COLOR_BACKGROUND
#define COLOR_3DFACE      COLOR_BTNFACE
#define COLOR_3DSHADOW    COLOR_BTNSHADOW
#define COLOR_3DHIGHLIGHT COLOR_BTNHIGHLIGHT
#define COLOR_3DHILIGHT   COLOR_BTNHIGHLIGHT
#define COLOR_BTNHILIGHT  COLOR_BTNHIGHLIGHT
/* win98 colors */
#define COLOR_ALTERNATEBTNFACE        25 /* undocumented, constant name unknown */
#define COLOR_HOTLIGHT                26
#define COLOR_GRADIENTACTIVECAPTION   27
#define COLOR_GRADIENTINACTIVECAPTION 28
/* win2k/xp colors */
#define COLOR_MENUHILIGHT 29
#define COLOR_MENUBAR     30

/* WM_CTLCOLOR values */
#define CTLCOLOR_MSGBOX    0
#define CTLCOLOR_EDIT      1
#define CTLCOLOR_LISTBOX   2
#define CTLCOLOR_BTN       3
#define CTLCOLOR_DLG       4
#define CTLCOLOR_SCROLLBAR 5
#define CTLCOLOR_STATIC    6

#ifndef UMDF_USING_NTSTATUS
#ifndef WIN32_NO_STATUS
/*lint -save -e767 */
#define STATUS_WAIT_0                     ((DWORD)0x00000000L)
#define STATUS_ABANDONED_WAIT_0           ((DWORD)0x00000080L)
#define STATUS_USER_APC                   ((DWORD)0x000000C0L)
#define STATUS_TIMEOUT                    ((DWORD)0x00000102L)
#define STATUS_PENDING                    ((DWORD)0x00000103L)
#define DBG_EXCEPTION_HANDLED             ((DWORD)0x00010001L)
#define DBG_CONTINUE                      ((DWORD)0x00010002L)
#define STATUS_SEGMENT_NOTIFICATION       ((DWORD)0x40000005L)
#define STATUS_FATAL_APP_EXIT             ((DWORD)0x40000015L)
#define DBG_REPLY_LATER                   ((DWORD)0x40010001L)
#define DBG_TERMINATE_THREAD              ((DWORD)0x40010003L)
#define DBG_TERMINATE_PROCESS             ((DWORD)0x40010004L)
#define DBG_CONTROL_C                     ((DWORD)0x40010005L)
#define DBG_PRINTEXCEPTION_C              ((DWORD)0x40010006L)
#define DBG_RIPEXCEPTION                  ((DWORD)0x40010007L)
#define DBG_CONTROL_BREAK                 ((DWORD)0x40010008L)
#define DBG_COMMAND_EXCEPTION             ((DWORD)0x40010009L)
#define DBG_PRINTEXCEPTION_WIDE_C         ((DWORD)0x4001000AL)
#define STATUS_GUARD_PAGE_VIOLATION       ((DWORD)0x80000001L)
#define STATUS_DATATYPE_MISALIGNMENT      ((DWORD)0x80000002L)
#define STATUS_BREAKPOINT                 ((DWORD)0x80000003L)
#define STATUS_SINGLE_STEP                ((DWORD)0x80000004L)
#define STATUS_LONGJUMP                   ((DWORD)0x80000026L)
#define STATUS_UNWIND_CONSOLIDATE         ((DWORD)0x80000029L)
#define DBG_EXCEPTION_NOT_HANDLED         ((DWORD)0x80010001L)
#define STATUS_ACCESS_VIOLATION           ((DWORD)0xC0000005L)
#define STATUS_IN_PAGE_ERROR              ((DWORD)0xC0000006L)
#define STATUS_INVALID_HANDLE             ((DWORD)0xC0000008L)
#define STATUS_INVALID_PARAMETER          ((DWORD)0xC000000DL)
#define STATUS_NO_MEMORY                  ((DWORD)0xC0000017L)
#define STATUS_ILLEGAL_INSTRUCTION        ((DWORD)0xC000001DL)
#define STATUS_NONCONTINUABLE_EXCEPTION   ((DWORD)0xC0000025L)
#define STATUS_INVALID_DISPOSITION        ((DWORD)0xC0000026L)
#define STATUS_ARRAY_BOUNDS_EXCEEDED      ((DWORD)0xC000008CL)
#define STATUS_FLOAT_DENORMAL_OPERAND     ((DWORD)0xC000008DL)
#define STATUS_FLOAT_DIVIDE_BY_ZERO       ((DWORD)0xC000008EL)
#define STATUS_FLOAT_INEXACT_RESULT       ((DWORD)0xC000008FL)
#define STATUS_FLOAT_INVALID_OPERATION    ((DWORD)0xC0000090L)
#define STATUS_FLOAT_OVERFLOW             ((DWORD)0xC0000091L)
#define STATUS_FLOAT_STACK_CHECK          ((DWORD)0xC0000092L)
#define STATUS_FLOAT_UNDERFLOW            ((DWORD)0xC0000093L)
#define STATUS_INTEGER_DIVIDE_BY_ZERO     ((DWORD)0xC0000094L)
#define STATUS_INTEGER_OVERFLOW           ((DWORD)0xC0000095L)
#define STATUS_PRIVILEGED_INSTRUCTION     ((DWORD)0xC0000096L)
#define STATUS_STACK_OVERFLOW             ((DWORD)0xC00000FDL)
#define STATUS_DLL_NOT_FOUND              ((DWORD)0xC0000135L)
#define STATUS_ORDINAL_NOT_FOUND          ((DWORD)0xC0000138L)
#define STATUS_ENTRYPOINT_NOT_FOUND       ((DWORD)0xC0000139L)
#define STATUS_CONTROL_C_EXIT             ((DWORD)0xC000013AL)
#define STATUS_DLL_INIT_FAILED            ((DWORD)0xC0000142L)
#define STATUS_CONTROL_STACK_VIOLATION    ((DWORD)0xC00001B2L)
#define STATUS_FLOAT_MULTIPLE_FAULTS      ((DWORD)0xC00002B4L)
#define STATUS_FLOAT_MULTIPLE_TRAPS       ((DWORD)0xC00002B5L)
#define STATUS_REG_NAT_CONSUMPTION        ((DWORD)0xC00002C9L)
#define STATUS_HEAP_CORRUPTION            ((DWORD)0xC0000374L)
#define STATUS_STACK_BUFFER_OVERRUN       ((DWORD)0xC0000409L)
#define STATUS_INVALID_CRUNTIME_PARAMETER ((DWORD)0xC0000417L)
#define STATUS_ASSERTION_FAILURE          ((DWORD)0xC0000420L)
#define STATUS_ENCLAVE_VIOLATION          ((DWORD)0xC00004A2L)
#define STATUS_INTERRUPTED                ((DWORD)0xC0000515L)
#define STATUS_THREAD_NOT_RUNNING         ((DWORD)0xC0000516L)
#define STATUS_ALREADY_REGISTERED         ((DWORD)0xC0000718L)
#if defined(STATUS_SUCCESS) || (_WIN32_WINNT > 0x0500) || (_WIN32_FUSION >= 0x0100)
#define STATUS_SXS_EARLY_DEACTIVATION   ((DWORD)0xC015000FL)
#define STATUS_SXS_INVALID_DEACTIVATION ((DWORD)0xC0150010L)
#endif
/*lint -restore */
#endif
#endif /* UMDF_USING_NTSTATUS */

#define MAXIMUM_WAIT_OBJECTS 64 // Maximum number of wait objects

/*
 * Owner draw actions
 */
#define ODA_DRAWENTIRE 0x0001
#define ODA_SELECT     0x0002
#define ODA_FOCUS      0x0004

/*
 * Owner draw state
 */
#define ODS_SELECTED 0x0001
#define ODS_GRAYED   0x0002
#define ODS_DISABLED 0x0004
#define ODS_CHECKED  0x0008
#define ODS_FOCUS    0x0010
#if (WINVER >= 0x0400)
#define ODS_DEFAULT      0x0020
#define ODS_COMBOBOXEDIT 0x1000
#endif /* WINVER >= 0x0400 */
#if (WINVER >= 0x0500)
#define ODS_HOTLIGHT 0x0040
#define ODS_INACTIVE 0x0080
#if (_WIN32_WINNT >= 0x0500)
#define ODS_NOACCEL     0x0100
#define ODS_NOFOCUSRECT 0x0200
#endif /* _WIN32_WINNT >= 0x0500 */
#endif /* WINVER >= 0x0500 */

    /* MapVirtualKey translation types */
#define MAPVK_VK_TO_VSC    0
#define MAPVK_VSC_TO_VK    1
#define MAPVK_VK_TO_CHAR   2
#define MAPVK_VSC_TO_VK_EX 3
#define MAPVK_VK_TO_VSC_EX 4

    typedef struct tagNMHDR
    {
        HWND hwndFrom;
        UINT_PTR idFrom;
        UINT code; // NM_ code
    } NMHDR;
    typedef NMHDR FAR *LPNMHDR;

#define SPI_GETBEEP               1
#define SPI_SETBEEP               2
#define SPI_GETMOUSE              3
#define SPI_SETMOUSE              4
#define SPI_GETBORDER             5
#define SPI_SETBORDER             6
#define SPI_GETKEYBOARDSPEED      10
#define SPI_SETKEYBOARDSPEED      11
#define SPI_LANGDRIVER            12
#define SPI_ICONHORIZONTALSPACING 13
#define SPI_GETSCREENSAVETIMEOUT  14
#define SPI_SETSCREENSAVETIMEOUT  15
#define SPI_GETSCREENSAVEACTIVE   16
#define SPI_SETSCREENSAVEACTIVE   17
#define SPI_GETGRIDGRANULARITY    18
#define SPI_SETGRIDGRANULARITY    19
#define SPI_SETDESKWALLPAPER      20
#define SPI_SETDESKPATTERN        21
#define SPI_GETKEYBOARDDELAY      22
#define SPI_SETKEYBOARDDELAY      23
#define SPI_ICONVERTICALSPACING   24
#define SPI_GETICONTITLEWRAP      25
#define SPI_SETICONTITLEWRAP      26
#define SPI_GETMENUDROPALIGNMENT  27
#define SPI_SETMENUDROPALIGNMENT  28
#define SPI_SETDOUBLECLKWIDTH     29
#define SPI_SETDOUBLECLKHEIGHT    30
#define SPI_GETICONTITLELOGFONT   31
#define SPI_SETDOUBLECLICKTIME    32
#define SPI_SETMOUSEBUTTONSWAP    33
#define SPI_SETICONTITLELOGFONT   34
#define SPI_GETFASTTASKSWITCH     35
#define SPI_SETFASTTASKSWITCH     36
#define SPI_SETDRAGFULLWINDOWS    37
#define SPI_GETDRAGFULLWINDOWS    38
#define SPI_GETNONCLIENTMETRICS   41
#define SPI_SETNONCLIENTMETRICS   42
#define SPI_GETMINIMIZEDMETRICS   43
#define SPI_SETMINIMIZEDMETRICS   44
#define SPI_GETICONMETRICS        45
#define SPI_SETICONMETRICS        46
#define SPI_SETWORKAREA           47
#define SPI_GETWORKAREA           48
#define SPI_SETPENWINDOWS         49
#define SPI_GETFILTERKEYS         50
#define SPI_SETFILTERKEYS         51
#define SPI_GETTOGGLEKEYS         52
#define SPI_SETTOGGLEKEYS         53
#define SPI_GETMOUSEKEYS          54
#define SPI_SETMOUSEKEYS          55
#define SPI_GETSHOWSOUNDS         56
#define SPI_SETSHOWSOUNDS         57
#define SPI_GETSTICKYKEYS         58
#define SPI_SETSTICKYKEYS         59
#define SPI_GETACCESSTIMEOUT      60
#define SPI_SETACCESSTIMEOUT      61
#define SPI_GETSERIALKEYS         62
#define SPI_SETSERIALKEYS         63
#define SPI_GETSOUNDSENTRY        64
#define SPI_SETSOUNDSENTRY        65
#define SPI_GETHIGHCONTRAST       66
#define SPI_SETHIGHCONTRAST       67
#define SPI_GETKEYBOARDPREF       68
#define SPI_SETKEYBOARDPREF       69
#define SPI_GETSCREENREADER       70
#define SPI_SETSCREENREADER       71
#define SPI_GETANIMATION          72
#define SPI_SETANIMATION          73
#define SPI_GETFONTSMOOTHING      74
#define SPI_SETFONTSMOOTHING      75
#define SPI_SETDRAGWIDTH          76
#define SPI_SETDRAGHEIGHT         77
#define SPI_SETHANDHELD           78
#define SPI_GETLOWPOWERTIMEOUT    79
#define SPI_GETPOWEROFFTIMEOUT    80
#define SPI_SETLOWPOWERTIMEOUT    81
#define SPI_SETPOWEROFFTIMEOUT    82
#define SPI_GETLOWPOWERACTIVE     83
#define SPI_GETPOWEROFFACTIVE     84
#define SPI_SETLOWPOWERACTIVE     85
#define SPI_SETPOWEROFFACTIVE     86
#define SPI_SETCURSORS            87
#define SPI_SETICONS              88
#define SPI_GETDEFAULTINPUTLANG   89
#define SPI_SETDEFAULTINPUTLANG   90
#define SPI_SETLANGTOGGLE         91
#define SPI_GETWINDOWSEXTENSION   92
#define SPI_SETMOUSETRAILS        93
#define SPI_GETMOUSETRAILS        94
#define SPI_GETSNAPTODEFBUTTON    95
#define SPI_SETSNAPTODEFBUTTON    96
#define SPI_SETSCREENSAVERRUNNING 97
#define SPI_SCREENSAVERRUNNING    SPI_SETSCREENSAVERRUNNING
#define SPI_GETMOUSEHOVERWIDTH    98
#define SPI_SETMOUSEHOVERWIDTH    99
#define SPI_GETMOUSEHOVERHEIGHT   100
#define SPI_SETMOUSEHOVERHEIGHT   101
#define SPI_GETMOUSEHOVERTIME     102
#define SPI_SETMOUSEHOVERTIME     103
#define SPI_GETWHEELSCROLLLINES   104
#define SPI_SETWHEELSCROLLLINES   105
#define SPI_GETMENUSHOWDELAY      106
#define SPI_SETMENUSHOWDELAY      107
#define SPI_GETWHEELSCROLLCHARS   108
#define SPI_SETWHEELSCROLLCHARS   109
#define SPI_GETSHOWIMEUI          110
#define SPI_SETSHOWIMEUI          111
#define SPI_GETMOUSESPEED         112
#define SPI_SETMOUSESPEED         113
#define SPI_GETSCREENSAVERRUNNING 114
#define SPI_GETDESKWALLPAPER      115
#define SPI_GETAUDIODESCRIPTION   116
#define SPI_SETAUDIODESCRIPTION   117

#define SPI_GETACTIVEWINDOWTRACKING     0x1000
#define SPI_SETACTIVEWINDOWTRACKING     0x1001
#define SPI_GETMENUANIMATION            0x1002
#define SPI_SETMENUANIMATION            0x1003
#define SPI_GETCOMBOBOXANIMATION        0x1004
#define SPI_SETCOMBOBOXANIMATION        0x1005
#define SPI_GETLISTBOXSMOOTHSCROLLING   0x1006
#define SPI_SETLISTBOXSMOOTHSCROLLING   0x1007
#define SPI_GETGRADIENTCAPTIONS         0x1008
#define SPI_SETGRADIENTCAPTIONS         0x1009
#define SPI_GETKEYBOARDCUES             0x100A
#define SPI_SETKEYBOARDCUES             0x100B
#define SPI_GETMENUUNDERLINES           SPI_GETKEYBOARDCUES
#define SPI_SETMENUUNDERLINES           SPI_SETKEYBOARDCUES
#define SPI_GETACTIVEWNDTRKZORDER       0x100C
#define SPI_SETACTIVEWNDTRKZORDER       0x100D
#define SPI_GETHOTTRACKING              0x100E
#define SPI_SETHOTTRACKING              0x100F
#define SPI_GETMENUFADE                 0x1012
#define SPI_SETMENUFADE                 0x1013
#define SPI_GETSELECTIONFADE            0x1014
#define SPI_SETSELECTIONFADE            0x1015
#define SPI_GETTOOLTIPANIMATION         0x1016
#define SPI_SETTOOLTIPANIMATION         0x1017
#define SPI_GETTOOLTIPFADE              0x1018
#define SPI_SETTOOLTIPFADE              0x1019
#define SPI_GETCURSORSHADOW             0x101A
#define SPI_SETCURSORSHADOW             0x101B
#define SPI_GETMOUSESONAR               0x101C
#define SPI_SETMOUSESONAR               0x101D
#define SPI_GETMOUSECLICKLOCK           0x101E
#define SPI_SETMOUSECLICKLOCK           0x101F
#define SPI_GETMOUSEVANISH              0x1020
#define SPI_SETMOUSEVANISH              0x1021
#define SPI_GETFLATMENU                 0x1022
#define SPI_SETFLATMENU                 0x1023
#define SPI_GETDROPSHADOW               0x1024
#define SPI_SETDROPSHADOW               0x1025
#define SPI_GETBLOCKSENDINPUTRESETS     0x1026
#define SPI_SETBLOCKSENDINPUTRESETS     0x1027
#define SPI_GETUIEFFECTS                0x103E
#define SPI_SETUIEFFECTS                0x103F
#define SPI_GETDISABLEOVERLAPPEDCONTENT 0x1040
#define SPI_SETDISABLEOVERLAPPEDCONTENT 0x1041
#define SPI_GETCLIENTAREAANIMATION      0x1042
#define SPI_SETCLIENTAREAANIMATION      0x1043
#define SPI_GETCLEARTYPE                0x1048
#define SPI_SETCLEARTYPE                0x1049
#define SPI_GETSPEECHRECOGNITION        0x104A
#define SPI_SETSPEECHRECOGNITION        0x104B
#define SPI_GETFOREGROUNDLOCKTIMEOUT    0x2000
#define SPI_SETFOREGROUNDLOCKTIMEOUT    0x2001
#define SPI_GETACTIVEWNDTRKTIMEOUT      0x2002
#define SPI_SETACTIVEWNDTRKTIMEOUT      0x2003
#define SPI_GETFOREGROUNDFLASHCOUNT     0x2004
#define SPI_SETFOREGROUNDFLASHCOUNT     0x2005
#define SPI_GETCARETWIDTH               0x2006
#define SPI_SETCARETWIDTH               0x2007
#define SPI_GETMOUSECLICKLOCKTIME       0x2008
#define SPI_SETMOUSECLICKLOCKTIME       0x2009
#define SPI_GETFONTSMOOTHINGTYPE        0x200A
#define SPI_SETFONTSMOOTHINGTYPE        0x200B
#define SPI_GETFONTSMOOTHINGCONTRAST    0x200C
#define SPI_SETFONTSMOOTHINGCONTRAST    0x200D
#define SPI_GETFOCUSBORDERWIDTH         0x200E
#define SPI_SETFOCUSBORDERWIDTH         0x200F
#define SPI_GETFOCUSBORDERHEIGHT        0x2010
#define SPI_SETFOCUSBORDERHEIGHT        0x2011
#define SPI_GETFONTSMOOTHINGORIENTATION 0x2012
#define SPI_SETFONTSMOOTHINGORIENTATION 0x2013

/* WM_PRINT flags */
#define PRF_CHECKVISIBLE 0x00000001L
#define PRF_NONCLIENT    0x00000002L
#define PRF_CLIENT       0x00000004L
#define PRF_ERASEBKGND   0x00000008L
#define PRF_CHILDREN     0x00000010L
#define PRF_OWNED        0x00000020L

/*
 * Dialog Codes
 */
#define DLGC_WANTARROWS      0x0001 /* Control wants arrow keys         */
#define DLGC_WANTTAB         0x0002 /* Control wants tab keys           */
#define DLGC_WANTALLKEYS     0x0004 /* Control wants all keys           */
#define DLGC_WANTMESSAGE     0x0004 /* Pass message to control          */
#define DLGC_HASSETSEL       0x0008 /* Understands EM_SETSEL message    */
#define DLGC_DEFPUSHBUTTON   0x0010 /* Default pushbutton               */
#define DLGC_UNDEFPUSHBUTTON 0x0020 /* Non-default pushbutton           */
#define DLGC_RADIOBUTTON     0x0040 /* Radio button                     */
#define DLGC_WANTCHARS       0x0080 /* Want WM_CHAR messages            */
#define DLGC_STATIC          0x0100 /* Static item: don't include       */
#define DLGC_BUTTON          0x2000 /* Button item: can be checked      */

    /*
     * Predefined Clipboard Formats
     */
#define CF_TEXT         1
#define CF_BITMAP       2
#define CF_METAFILEPICT 3
#define CF_SYLK         4
#define CF_DIF          5
#define CF_TIFF         6
#define CF_OEMTEXT      7
#define CF_DIB          8
#define CF_PALETTE      9
#define CF_PENDATA      10
#define CF_RIFF         11
#define CF_WAVE         12
#define CF_UNICODETEXT  13
#define CF_ENHMETAFILE  14
#if (WINVER >= 0x0400)
#define CF_HDROP  CF_TEXT
#define CF_LOCALE 16
#endif /* WINVER >= 0x0400 */
#if (WINVER >= 0x0500)
#define CF_DIBV5 17
#endif /* WINVER >= 0x0500 */

#if (WINVER >= 0x0500)
#define CF_MAX 18
#elif (WINVER >= 0x0400)
#define CF_MAX 17
#else
#define CF_MAX 15
#endif

    typedef BOOL(CALLBACK *PROPENUMPROCA)(HWND, LPCSTR, HANDLE);
    typedef BOOL(CALLBACK *PROPENUMPROCW)(HWND, LPCWSTR, HANDLE);

    typedef BOOL(CALLBACK *PROPENUMPROCEXA)(HWND, LPSTR, HANDLE, ULONG_PTR);
    typedef BOOL(CALLBACK *PROPENUMPROCEXW)(HWND, LPWSTR, HANDLE, ULONG_PTR);

    typedef int(CALLBACK *EDITWORDBREAKPROCA)(LPSTR lpch, int ichCurrent, int cch, int code);
    typedef int(CALLBACK *EDITWORDBREAKPROCW)(LPWSTR lpch, int ichCurrent, int cch, int code);

#ifdef UNICODE
    typedef PROPENUMPROCW PROPENUMPROC;
    typedef PROPENUMPROCEXW PROPENUMPROCEX;
    typedef EDITWORDBREAKPROCW EDITWORDBREAKPROC;
#else  /* !UNICODE */
    typedef PROPENUMPROCA PROPENUMPROC;
    typedef PROPENUMPROCEXA PROPENUMPROCEX;
    typedef EDITWORDBREAKPROCA EDITWORDBREAKPROC;
#endif /* UNICODE */

/* Storage instantiation modes */
#define STGM_DIRECT     0x00000000L
#define STGM_TRANSACTED 0x00010000L
#define STGM_SIMPLE     0x08000000L

#define STGM_READ      0x00000000L
#define STGM_WRITE     0x00000001L
#define STGM_READWRITE 0x00000002L

#define STGM_SHARE_DENY_NONE  0x00000040L
#define STGM_SHARE_DENY_READ  0x00000030L
#define STGM_SHARE_DENY_WRITE 0x00000020L
#define STGM_SHARE_EXCLUSIVE  0x00000010L

#define STGM_PRIORITY        0x00040000L
#define STGM_DELETEONRELEASE 0x04000000L
#if (WINVER >= 400)
#define STGM_NOSCRATCH 0x00100000L
#endif /* WINVER */

#define STGM_CREATE      0x00001000L
#define STGM_CONVERT     0x00020000L
#define STGM_FAILIFTHERE 0x00000000L

#define STGM_NOSNAPSHOT 0x00200000L
#if (_WIN32_WINNT >= 0x0500)
#define STGM_DIRECT_SWMR 0x00400000L
#endif

    typedef DWORD STGFMT;

#define STGFMT_STORAGE 0
#define STGFMT_NATIVE  1
#define STGFMT_FILE    3
#define STGFMT_ANY     4
#define STGFMT_DOCFILE 5

/*
 * EnableScrollBar() flags
 */
#define ESB_ENABLE_BOTH  0x0000
#define ESB_DISABLE_BOTH 0x0003

#define ESB_DISABLE_LEFT  0x0001
#define ESB_DISABLE_RIGHT 0x0002

#define ESB_DISABLE_UP   0x0001
#define ESB_DISABLE_DOWN 0x0002

#define ESB_DISABLE_LTUP ESB_DISABLE_LEFT
#define ESB_DISABLE_RTDN ESB_DISABLE_RIGHT

#define MAKEWORD(a, b)    ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))
#define MAKELONG(a, b)    ((LONG)(((WORD)(((DWORD_PTR)(a)) & 0xffff)) | ((DWORD)((WORD)(((DWORD_PTR)(b)) & 0xffff))) << 16))
#define MAKELRESULT(l, h) ((LRESULT)(DWORD)MAKELONG(l, h))
#define LOWORD(l)         ((WORD)(((DWORD_PTR)(l)) & 0xffff))
#define HIWORD(l)         ((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff))
#define LOBYTE(w)         ((BYTE)(((DWORD_PTR)(w)) & 0xff))
#define HIBYTE(w)         ((BYTE)((((DWORD_PTR)(w)) >> 8) & 0xff))

    /*
     * WM_KEYUP/DOWN/CHAR HIWORD(lParam) flags
     */
#define KF_EXTENDED 0x0100
#define KF_DLGMODE  0x0800
#define KF_MENUMODE 0x1000
#define KF_ALTDOWN  0x2000
#define KF_REPEAT   0x4000
#define KF_UP       0x8000

    BOOL WINAPI MessageBeep(_In_ UINT uType);

#define SW_SCROLLCHILDREN 0x0001 /* Scroll children within *lprcScroll. */
#define SW_INVALIDATE     0x0002 /* Invalidate after scrolling */
#define SW_ERASE          0x0004 /* If SW_INVALIDATE, don't send WM_ERASEBACKGROUND */
#if (WINVER >= 0x0500)
#define SW_SMOOTHSCROLL 0x0010 /* Use smooth scrolling */
#endif                         /* WINVER >= 0x0500 */

// FInd/Replace options
#ifndef FR_DOWN
#define FR_DOWN      0x00000001
#define FR_WHOLEWORD 0x00000002
#define FR_MATCHCASE 0x00000004
#endif

#define DM_GETDEFID (WM_USER + 0)
#define DM_SETDEFID (WM_USER + 1)

#define HWND_DESKTOP ((HWND)0)

    typedef struct tagSTYLESTRUCT
    {
        DWORD styleOld;
        DWORD styleNew;
    } STYLESTRUCT, *LPSTYLESTRUCT;

#define DLL_PROCESS_ATTACH 1
#define DLL_THREAD_ATTACH  2
#define DLL_THREAD_DETACH  3
#define DLL_PROCESS_DETACH 0

#define DFC_CAPTION 1
#define DFC_MENU    2
#define DFC_SCROLL  3
#define DFC_BUTTON  4
#if (WINVER >= 0x0500)
#define DFC_POPUPMENU 5
#endif /* WINVER >= 0x0500 */

#define DFCS_CAPTIONCLOSE   0x0000
#define DFCS_CAPTIONMIN     0x0001
#define DFCS_CAPTIONMAX     0x0002
#define DFCS_CAPTIONRESTORE 0x0003
#define DFCS_CAPTIONHELP    0x0004

#define DFCS_MENUARROW           0x0000
#define DFCS_MENUCHECK           0x0001
#define DFCS_MENUBULLET          0x0002
#define DFCS_MENUARROWRIGHT      0x0004
#define DFCS_SCROLLUP            0x0000
#define DFCS_SCROLLDOWN          0x0001
#define DFCS_SCROLLLEFT          0x0002
#define DFCS_SCROLLRIGHT         0x0003
#define DFCS_SCROLLCOMBOBOX      0x0005
#define DFCS_SCROLLSIZEGRIP      0x0008
#define DFCS_SCROLLSIZEGRIPRIGHT 0x0010

#define DFCS_BUTTONCHECK      0x0000
#define DFCS_BUTTONRADIOIMAGE 0x0001
#define DFCS_BUTTONRADIOMASK  0x0002
#define DFCS_BUTTONRADIO      0x0004
#define DFCS_BUTTON3STATE     0x0008
#define DFCS_BUTTONPUSH       0x0010

#define DFCS_INACTIVE 0x0100
#define DFCS_PUSHED   0x0200
#define DFCS_CHECKED  0x0400

#if (WINVER >= 0x0500)
#define DFCS_TRANSPARENT 0x0800
#define DFCS_HOT         0x1000
#endif /* WINVER >= 0x0500 */

#define DFCS_ADJUSTRECT 0x2000
#define DFCS_FLAT       0x4000
#define DFCS_MONO       0x8000

/* 3D border styles */
#define BDR_RAISEDOUTER 0x0001
#define BDR_SUNKENOUTER 0x0002
#define BDR_RAISEDINNER 0x0004
#define BDR_SUNKENINNER 0x0008

#define BDR_OUTER  (BDR_RAISEDOUTER | BDR_SUNKENOUTER)
#define BDR_INNER  (BDR_RAISEDINNER | BDR_SUNKENINNER)
#define BDR_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#define BDR_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)

#define EDGE_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#define EDGE_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)
#define EDGE_ETCHED (BDR_SUNKENOUTER | BDR_RAISEDINNER)
#define EDGE_BUMP   (BDR_RAISEDOUTER | BDR_SUNKENINNER)

/* Border flags */
#define BF_LEFT   0x0001
#define BF_TOP    0x0002
#define BF_RIGHT  0x0004
#define BF_BOTTOM 0x0008

#define BF_TOPLEFT     (BF_TOP | BF_LEFT)
#define BF_TOPRIGHT    (BF_TOP | BF_RIGHT)
#define BF_BOTTOMLEFT  (BF_BOTTOM | BF_LEFT)
#define BF_BOTTOMRIGHT (BF_BOTTOM | BF_RIGHT)
#define BF_RECT        (BF_LEFT | BF_TOP | BF_RIGHT | BF_BOTTOM)

#define BF_DIAGONAL 0x0010

// For diagonal lines, the BF_RECT flags specify the end point of the
// vector bounded by the rectangle parameter.
#define BF_DIAGONAL_ENDTOPRIGHT    (BF_DIAGONAL | BF_TOP | BF_RIGHT)
#define BF_DIAGONAL_ENDTOPLEFT     (BF_DIAGONAL | BF_TOP | BF_LEFT)
#define BF_DIAGONAL_ENDBOTTOMLEFT  (BF_DIAGONAL | BF_BOTTOM | BF_LEFT)
#define BF_DIAGONAL_ENDBOTTOMRIGHT (BF_DIAGONAL | BF_BOTTOM | BF_RIGHT)

#define BF_MIDDLE 0x0800 /* Fill in the middle */
#define BF_SOFT   0x1000 /* For softer buttons */
#define BF_ADJUST 0x2000 /* Calculate the space left over */
#define BF_FLAT   0x4000 /* For flat rather than 3D borders */
#define BF_MONO   0x8000 /* For monochrome borders */

    typedef BOOL(CALLBACK *DRAWSTATEPROC)(HDC hdc, LPARAM lData, WPARAM wData, int cx, int cy);
/* Image type */
#define DST_COMPLEX    0x0000
#define DST_TEXT       0x0001
#define DST_PREFIXTEXT 0x0002
#define DST_ICON       0x0003
#define DST_BITMAP     0x0004

/* State type */
#define DSS_NORMAL   0x0000
#define DSS_UNION    0x0010 /* Gray string appearance */
#define DSS_DISABLED 0x0020
#define DSS_DEFAULT  0x0040 /* Make it bold */
#define DSS_MONO     0x0080
#if (_WIN32_WINNT >= 0x0500)
#define DSS_HIDEPREFIX 0x0200
#define DSS_PREFIXONLY 0x0400
#endif /* _WIN32_WINNT >= 0x0500 */
#define DSS_RIGHT 0x8000

#define CW_USEDEFAULT ((INT)0x80000000)

/* AnimateWindow() flags */
#define AW_SLIDE        0x00040000
#define AW_ACTIVATE     0x00020000
#define AW_BLEND        0x00080000
#define AW_HIDE         0x00010000
#define AW_CENTER       0x00000010
#define AW_HOR_POSITIVE 0x00000001
#define AW_HOR_NEGATIVE 0x00000002
#define AW_VER_POSITIVE 0x00000004
#define AW_VER_NEGATIVE 0x00000008


//
// Process dwCreationFlag values
//

#define DEBUG_PROCESS                     0x00000001
#define DEBUG_ONLY_THIS_PROCESS           0x00000002
#define CREATE_SUSPENDED                  0x00000004
#define DETACHED_PROCESS                  0x00000008

#define CREATE_NEW_CONSOLE                0x00000010
#define NORMAL_PRIORITY_CLASS             0x00000020
#define IDLE_PRIORITY_CLASS               0x00000040
#define HIGH_PRIORITY_CLASS               0x00000080

#define REALTIME_PRIORITY_CLASS           0x00000100
#define CREATE_NEW_PROCESS_GROUP          0x00000200
#define CREATE_UNICODE_ENVIRONMENT        0x00000400
#define CREATE_SEPARATE_WOW_VDM           0x00000800

#define CREATE_SHARED_WOW_VDM             0x00001000
#define CREATE_FORCEDOS                   0x00002000
#define BELOW_NORMAL_PRIORITY_CLASS       0x00004000
#define ABOVE_NORMAL_PRIORITY_CLASS       0x00008000

#define INHERIT_PARENT_AFFINITY           0x00010000
#define INHERIT_CALLER_PRIORITY           0x00020000    // Deprecated
#define CREATE_PROTECTED_PROCESS          0x00040000
#define EXTENDED_STARTUPINFO_PRESENT      0x00080000

#define PROCESS_MODE_BACKGROUND_BEGIN     0x00100000
#define PROCESS_MODE_BACKGROUND_END       0x00200000
#define CREATE_SECURE_PROCESS             0x00400000

#define CREATE_BREAKAWAY_FROM_JOB         0x01000000
#define CREATE_PRESERVE_CODE_AUTHZ_LEVEL  0x02000000
#define CREATE_DEFAULT_ERROR_MODE         0x04000000
#define CREATE_NO_WINDOW                  0x08000000

#define PROFILE_USER                      0x10000000
#define PROFILE_KERNEL                    0x20000000
#define PROFILE_SERVER                    0x40000000
#define CREATE_IGNORE_SYSTEM_DEFAULT      0x80000000


#ifdef __cplusplus
}
#endif //__cplusplus

#endif // !NOWINSTYLES
#endif //__WINUSER_H_