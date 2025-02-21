#ifndef _CTRL_TYPE_H_
#define _CTRL_TYPE_H_

#include <ctypes.h>

/*
 * Scroll bar messages
 */
#define SBM_SETPOS           0x00E0 /*not in win3.1 */
#define SBM_GETPOS           0x00E1 /*not in win3.1 */
#define SBM_SETRANGE         0x00E2 /*not in win3.1 */
#define SBM_SETRANGEREDRAW   0x00E6 /*not in win3.1 */
#define SBM_GETRANGE         0x00E3 /*not in win3.1 */
#define SBM_ENABLE_ARROWS    0x00E4 /*not in win3.1 */
#define SBM_SETSCROLLINFO    0x00E9
#define SBM_GETSCROLLINFO    0x00EA
#define SBM_GETSCROLLBARINFO 0x00EB

#define SIF_RANGE           0x0001
#define SIF_PAGE            0x0002
#define SIF_POS             0x0004
#define SIF_DISABLENOSCROLL 0x0008
#define SIF_TRACKPOS        0x0010
#define SIF_ALL             (SIF_RANGE | SIF_PAGE | SIF_POS | SIF_TRACKPOS)

typedef struct tagSCROLLINFO
{
    UINT cbSize;
    UINT fMask;
    int nMin;
    int nMax;
    UINT nPage;
    int nPos;
    int nTrackPos;
} SCROLLINFO, FAR *LPSCROLLINFO;
typedef SCROLLINFO CONST FAR *LPCSCROLLINFO;

#define TVE_COLLAPSE      0x0001
#define TVE_EXPAND        0x0002
#define TVE_TOGGLE        0x0003
#define TVE_EXPANDPARTIAL 0x4000
#define TVE_COLLAPSERESET 0x8000

/*
 * MEASUREITEMSTRUCT for ownerdraw
 */
typedef struct tagMEASUREITEMSTRUCT
{
    UINT CtlType;
    UINT CtlID;
    UINT itemID;
    UINT itemWidth;
    UINT itemHeight;
    ULONG_PTR itemData;
} MEASUREITEMSTRUCT, NEAR *PMEASUREITEMSTRUCT, FAR *LPMEASUREITEMSTRUCT;

/*
 * DRAWITEMSTRUCT for ownerdraw
 */
typedef struct tagDRAWITEMSTRUCT
{
    UINT CtlType;
    UINT CtlID;
    UINT itemID;
    UINT itemAction;
    UINT itemState;
    HWND hwndItem;
    HDC hDC;
    RECT rcItem;
    ULONG_PTR itemData;
} DRAWITEMSTRUCT, NEAR *PDRAWITEMSTRUCT, FAR *LPDRAWITEMSTRUCT;

/*
 * DELETEITEMSTRUCT for ownerdraw
 */
typedef struct tagDELETEITEMSTRUCT
{
    UINT CtlType;
    UINT CtlID;
    UINT itemID;
    HWND hwndItem;
    ULONG_PTR itemData;
} DELETEITEMSTRUCT, NEAR *PDELETEITEMSTRUCT, FAR *LPDELETEITEMSTRUCT;

/*
 * COMPAREITEMSTUCT for ownerdraw sorting
 */
typedef struct tagCOMPAREITEMSTRUCT
{
    UINT CtlType;
    UINT CtlID;
    HWND hwndItem;
    UINT itemID1;
    ULONG_PTR itemData1;
    UINT itemID2;
    ULONG_PTR itemData2;
    DWORD dwLocaleId;
} COMPAREITEMSTRUCT, NEAR *PCOMPAREITEMSTRUCT, FAR *LPCOMPAREITEMSTRUCT;

#define HDF_LEFT        0x0000 // Same as LVCFMT_LEFT
#define HDF_RIGHT       0x0001 // Same as LVCFMT_RIGHT
#define HDF_CENTER      0x0002 // Same as LVCFMT_CENTER
#define HDF_JUSTIFYMASK 0x0003 // Same as LVCFMT_JUSTIFYMASK
#define HDF_RTLREADING  0x0004 // Same as LVCFMT_LEFT

#define HDF_BITMAP          0x2000
#define HDF_STRING          0x4000
#define HDF_OWNERDRAW       0x8000 // Same as LVCFMT_COL_HAS_IMAGES
#define HDF_IMAGE           0x0800 // Same as LVCFMT_IMAGE
#define HDF_BITMAP_ON_RIGHT 0x1000 // Same as LVCFMT_BITMAP_ON_RIGHT
#define HDF_SORTUP          0x0400
#define HDF_SORTDOWN        0x0200

#define HDF_CHECKBOX    0x0040
#define HDF_CHECKED     0x0080
#define HDF_FIXEDWIDTH  0x0100    // Can't resize the column; same as LVCFMT_FIXED_WIDTH
#define HDF_SPLITBUTTON 0x1000000 // Column is a split button; same as LVCFMT_SPLITBUTTON

#define HOTKEYF_SHIFT   0x01
#define HOTKEYF_CONTROL 0x02
#define HOTKEYF_ALT     0x04
#define HOTKEYF_EXT     0x08

#define HKCOMB_NONE 0x0001
#define HKCOMB_S    0x0002
#define HKCOMB_C    0x0004
#define HKCOMB_A    0x0008
#define HKCOMB_SC   0x0010
#define HKCOMB_SA   0x0020
#define HKCOMB_CA   0x0040
#define HKCOMB_SCA  0x0080

#define SB_LINEUP        0
#define SB_LINELEFT      0
#define SB_LINEDOWN      1
#define SB_LINERIGHT     1
#define SB_PAGEUP        2
#define SB_PAGELEFT      2
#define SB_PAGEDOWN      3
#define SB_PAGERIGHT     3
#define SB_THUMBPOSITION 4
#define SB_THUMBTRACK    5
#define SB_TOP           6
#define SB_LEFT          6
#define SB_BOTTOM        7
#define SB_RIGHT         7
#define SB_ENDSCROLL     8

#define EN_SETFOCUS  0x0100
#define EN_KILLFOCUS 0x0200
#define EN_CHANGE    0x0300
#define EN_UPDATE    0x0400
#define EN_ERRSPACE  0x0500
#define EN_MAXTEXT   0x0501
#define EN_HSCROLL   0x0601
#define EN_VSCROLL   0x0602

#define EM_SETEVENTMASK (WM_USER + 69)
// Event notification masks
#define ENM_NONE              0x00000000
#define ENM_CHANGE            0x00000001
#define ENM_UPDATE            0x00000002
#define ENM_SCROLL            0x00000004
#define ENM_SCROLLEVENTS      0x00000008
#define ENM_DRAGDROPDONE      0x00000010
#define ENM_PARAGRAPHEXPANDED 0x00000020
#define ENM_PAGECHANGE        0x00000040
#define ENM_KEYEVENTS         0x00010000
#define ENM_MOUSEEVENTS       0x00020000
#define ENM_REQUESTRESIZE     0x00040000
#define ENM_SELCHANGE         0x00080000
#define ENM_DROPFILES         0x00100000
#define ENM_PROTECTED         0x00200000
#define ENM_CORRECTTEXT       0x00400000 // PenWin specific
#define ENM_IMECHANGE         0x00800000 // Used by RE1.0 compatibility
#define ENM_LANGCHANGE        0x01000000
#define ENM_OBJECTPOSITIONS   0x02000000
#define ENM_LINK              0x04000000
#define ENM_LOWFIRTF          0x08000000

/*
 * Listbox Return Values
 */
#define LB_OKAY     0
#define LB_ERR      (-1)
#define LB_ERRSPACE (-2)

/*
 * Listbox Notification Codes
 */
#define LBN_ERRSPACE  (-2)
#define LBN_SELCHANGE 1
#define LBN_DBLCLK    2
#define LBN_SELCANCEL 3
#define LBN_SETFOCUS  4
#define LBN_KILLFOCUS 5

#ifndef NOWINMESSAGES

/*
 * Listbox messages
 */
#define LB_ADDSTRING           0x0180
#define LB_INSERTSTRING        0x0181
#define LB_DELETESTRING        0x0182
#define LB_SELITEMRANGEEX      0x0183
#define LB_RESETCONTENT        0x0184
#define LB_SETSEL              0x0185
#define LB_SETCURSEL           0x0186
#define LB_GETSEL              0x0187
#define LB_GETCURSEL           0x0188
#define LB_GETTEXT             0x0189
#define LB_GETTEXTLEN          0x018A
#define LB_GETCOUNT            0x018B
#define LB_SELECTSTRING        0x018C
#define LB_DIR                 0x018D
#define LB_GETTOPINDEX         0x018E
#define LB_FINDSTRING          0x018F
#define LB_GETSELCOUNT         0x0190
#define LB_GETSELITEMS         0x0191
#define LB_SETTABSTOPS         0x0192
#define LB_GETHORIZONTALEXTENT 0x0193
#define LB_SETHORIZONTALEXTENT 0x0194
#define LB_SETCOLUMNWIDTH      0x0195
#define LB_ADDFILE             0x0196
#define LB_SETTOPINDEX         0x0197
#define LB_GETITEMRECT         0x0198
#define LB_GETITEMDATA         0x0199
#define LB_SETITEMDATA         0x019A
#define LB_SELITEMRANGE        0x019B
#define LB_SETANCHORINDEX      0x019C
#define LB_GETANCHORINDEX      0x019D
#define LB_SETCARETINDEX       0x019E
#define LB_GETCARETINDEX       0x019F
#define LB_SETITEMHEIGHT       0x01A0
#define LB_GETITEMHEIGHT       0x01A1
#define LB_FINDSTRINGEXACT     0x01A2
#define LB_SETLOCALE           0x01A5
#define LB_GETLOCALE           0x01A6
#define LB_SETCOUNT            0x01A7
#if (WINVER >= 0x0400)
#define LB_INITSTORAGE   0x01A8
#define LB_ITEMFROMPOINT 0x01A9
#endif /* WINVER >= 0x0400 */
#if defined(_WIN32_WCE) && (_WIN32_WCE >= 0x0400)
#define LB_MULTIPLEADDSTRING 0x01B1
#endif

#if (_WIN32_WINNT >= 0x0501)
#define LB_GETLISTBOXINFO 0x01B2
#endif /* _WIN32_WINNT >= 0x0501 */

#if (_WIN32_WINNT >= 0x0501)
#define LB_MSGMAX 0x01B3
#elif defined(_WIN32_WCE) && (_WIN32_WCE >= 0x0400)
#define LB_MSGMAX 0x01B1
#elif (WINVER >= 0x0400)
#define LB_MSGMAX 0x01B0
#else
#define LB_MSGMAX 0x01A8
#endif

#endif /* !NOWINMESSAGES */

#ifndef NOWINSTYLES

/*
 * Listbox Styles
 */
#define LBS_NOTIFY            0x0001L
#define LBS_SORT              0x0002L
#define LBS_NOREDRAW          0x0004L
#define LBS_MULTIPLESEL       0x0008L
#define LBS_OWNERDRAWFIXED    0x0010L
#define LBS_OWNERDRAWVARIABLE 0x0020L
#define LBS_HASSTRINGS        0x0040L
#define LBS_USETABSTOPS       0x0080L
#define LBS_NOINTEGRALHEIGHT  0x0100L
#define LBS_MULTICOLUMN       0x0200L
#define LBS_WANTKEYBOARDINPUT 0x0400L
#define LBS_EXTENDEDSEL       0x0800L
#define LBS_DISABLENOSCROLL   0x1000L
#define LBS_NODATA            0x2000L
#if (WINVER >= 0x0400)
#define LBS_NOSEL 0x4000L
#endif /* WINVER >= 0x0400 */
#define LBS_COMBOBOX 0x8000L

#define LBS_STANDARD (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)

#endif /* !NOWINSTYLES */
/*
 * Control Manager Structures and Definitions
 */

#ifndef NOWINSTYLES

/*
 * Edit Control Styles
 */
#define ES_LEFT        0x0000L
#define ES_CENTER      0x0001L
#define ES_RIGHT       0x0002L
#define ES_MULTILINE   0x0004L
#define ES_UPPERCASE   0x0008L
#define ES_LOWERCASE   0x0010L
#define ES_PASSWORD    0x0020L
#define ES_AUTOVSCROLL 0x0040L
#define ES_AUTOHSCROLL 0x0080L
#define ES_NOHIDESEL   0x0100L
#define ES_OEMCONVERT  0x0400L
#define ES_READONLY    0x0800L
#define ES_WANTRETURN  0x1000L
#if (WINVER >= 0x0400)
#define ES_NUMBER 0x2000L
#endif /* WINVER >= 0x0400 */

#endif /* !NOWINSTYLES */

/*
 * Edit Control Notification Codes
 */
#define EN_SETFOCUS  0x0100
#define EN_KILLFOCUS 0x0200
#define EN_CHANGE    0x0300
#define EN_UPDATE    0x0400
#define EN_ERRSPACE  0x0500
#define EN_MAXTEXT   0x0501
#define EN_HSCROLL   0x0601
#define EN_VSCROLL   0x0602

#if (_WIN32_WINNT >= 0x0500)
#define EN_ALIGN_LTR_EC 0x0700
#define EN_ALIGN_RTL_EC 0x0701
#endif /* _WIN32_WINNT >= 0x0500 */

#if (WINVER >= 0x0400)
/* Edit control EM_SETMARGIN parameters */
#define EC_LEFTMARGIN  0x0001
#define EC_RIGHTMARGIN 0x0002
#define EC_USEFONTINFO 0xffff
#endif /* WINVER >= 0x0400 */

#if (WINVER >= 0x0500)
/* wParam of EM_GET/SETIMESTATUS  */
#define EMSIS_COMPOSITIONSTRING 0x0001

/* lParam for EMSIS_COMPOSITIONSTRING  */
#define EIMES_GETCOMPSTRATONCE         0x0001
#define EIMES_CANCELCOMPSTRINFOCUS     0x0002
#define EIMES_COMPLETECOMPSTRKILLFOCUS 0x0004
#endif /* WINVER >= 0x0500 */

#ifndef NOWINMESSAGES

/*
 * Edit Control Messages
 */
#define EM_GETSEL              0x00B0
#define EM_SETSEL              0x00B1
#define EM_GETRECT             0x00B2
#define EM_SETRECT             0x00B3
#define EM_SETRECTNP           0x00B4
#define EM_SCROLL              0x00B5
#define EM_LINESCROLL          0x00B6
#define EM_SCROLLCARET         0x00B7
#define EM_GETMODIFY           0x00B8
#define EM_SETMODIFY           0x00B9
#define EM_GETLINECOUNT        0x00BA
#define EM_LINEINDEX           0x00BB
#define EM_SETHANDLE           0x00BC
#define EM_GETHANDLE           0x00BD
#define EM_GETTHUMB            0x00BE
#define EM_LINELENGTH          0x00C1
#define EM_REPLACESEL          0x00C2
#define EM_GETLINE             0x00C4
#define EM_LIMITTEXT           0x00C5
#define EM_CANUNDO             0x00C6
#define EM_UNDO                0x00C7
#define EM_FMTLINES            0x00C8
#define EM_LINEFROMCHAR        0x00C9
#define EM_SETTABSTOPS         0x00CB
#define EM_SETPASSWORDCHAR     0x00CC
#define EM_EMPTYUNDOBUFFER     0x00CD
#define EM_GETFIRSTVISIBLELINE 0x00CE
#define EM_SETREADONLY         0x00CF
#define EM_SETWORDBREAKPROC    0x00D0
#define EM_GETWORDBREAKPROC    0x00D1
#define EM_GETPASSWORDCHAR     0x00D2
#if (WINVER >= 0x0400)
#define EM_SETMARGINS   0x00D3
#define EM_GETMARGINS   0x00D4
#define EM_SETLIMITTEXT EM_LIMITTEXT /* ;win40 Name change */
#define EM_GETLIMITTEXT 0x00D5
#define EM_POSFROMCHAR  0x00D6
#define EM_CHARFROMPOS  0x00D7
#endif /* WINVER >= 0x0400 */

#if (WINVER >= 0x0500)
#define EM_SETIMESTATUS 0x00D8
#define EM_GETIMESTATUS 0x00D9
#endif /* WINVER >= 0x0500 */

#endif /* !NOWINMESSAGES */

/*
 * EDITWORDBREAKPROC code values
 */
#define WB_LEFT        0
#define WB_RIGHT       1
#define WB_ISDELIMITER 2

/*
 * Button Control Styles
 */
#define BS_PUSHBUTTON      0x00000000L
#define BS_DEFPUSHBUTTON   0x00000001L
#define BS_CHECKBOX        0x00000002L
#define BS_AUTOCHECKBOX    0x00000003L
#define BS_RADIOBUTTON     0x00000004L
#define BS_3STATE          0x00000005L
#define BS_AUTO3STATE      0x00000006L
#define BS_GROUPBOX        0x00000007L
#define BS_USERBUTTON      0x00000008L
#define BS_AUTORADIOBUTTON 0x00000009L
#define BS_PUSHBOX         0x0000000AL
#define BS_OWNERDRAW       0x0000000BL
#define BS_TYPEMASK        0x0000000FL
#define BS_LEFTTEXT        0x00000020L
#if (WINVER >= 0x0400)
#define BS_TEXT        0x00000000L
#define BS_ICON        0x00000040L
#define BS_BITMAP      0x00000080L
#define BS_LEFT        0x00000100L
#define BS_RIGHT       0x00000200L
#define BS_CENTER      0x00000300L
#define BS_TOP         0x00000400L
#define BS_BOTTOM      0x00000800L
#define BS_VCENTER     0x00000C00L
#define BS_PUSHLIKE    0x00001000L
#define BS_MULTILINE   0x00002000L
#define BS_NOTIFY      0x00004000L
#define BS_FLAT        0x00008000L
#define BS_RIGHTBUTTON BS_LEFTTEXT
#endif /* WINVER >= 0x0400 */

/*
 * User Button Notification Codes
 */
#define BN_CLICKED       0
#define BN_PAINT         1
#define BN_HILITE        2
#define BN_UNHILITE      3
#define BN_DISABLE       4
#define BN_DOUBLECLICKED 5
#if (WINVER >= 0x0400)
#define BN_PUSHED    BN_HILITE
#define BN_UNPUSHED  BN_UNHILITE
#define BN_DBLCLK    BN_DOUBLECLICKED
#define BN_SETFOCUS  6
#define BN_KILLFOCUS 7
#endif /* WINVER >= 0x0400 */

/*
 * Button Control Messages
 */
#define BM_GETCHECK 0x00F0
#define BM_SETCHECK 0x00F1
#define BM_GETSTATE 0x00F2
#define BM_SETSTATE 0x00F3
#define BM_SETSTYLE 0x00F4
#if (WINVER >= 0x0400)
#define BM_CLICK    0x00F5
#define BM_GETIMAGE 0x00F6
#define BM_SETIMAGE 0x00F7
#endif /* WINVER >= 0x0400 */
#if (WINVER >= 0x0600)
#define BM_SETDONTCLICK 0x00F8
#endif /* WINVER >= 0x0600 */

#if (WINVER >= 0x0400)
#define BST_UNCHECKED     0x0000
#define BST_CHECKED       0x0001
#define BST_INDETERMINATE 0x0002
#define BST_PUSHED        0x0004
#define BST_FOCUS         0x0008
#endif /* WINVER >= 0x0400 */

/*
 * Static Control Constants
 */
#define SS_LEFT           0x00000000L
#define SS_CENTER         0x00000001L
#define SS_RIGHT          0x00000002L
#define SS_ICON           0x00000003L
#define SS_BLACKRECT      0x00000004L
#define SS_GRAYRECT       0x00000005L
#define SS_WHITERECT      0x00000006L
#define SS_BLACKFRAME     0x00000007L
#define SS_GRAYFRAME      0x00000008L
#define SS_WHITEFRAME     0x00000009L
#define SS_USERITEM       0x0000000AL
#define SS_SIMPLE         0x0000000BL
#define SS_LEFTNOWORDWRAP 0x0000000CL
#if (WINVER >= 0x0400)
#define SS_OWNERDRAW   0x0000000DL
#define SS_BITMAP      0x0000000EL
#define SS_ENHMETAFILE 0x0000000FL
#define SS_ETCHEDHORZ  0x00000010L
#define SS_ETCHEDVERT  0x00000011L
#define SS_ETCHEDFRAME 0x00000012L
#define SS_TYPEMASK    0x0000001FL
#endif /* WINVER >= 0x0400 */
#if (WINVER >= 0x0501)
#define SS_REALSIZECONTROL 0x00000040L
#endif                          /* WINVER >= 0x0501 */
#define SS_NOPREFIX 0x00000080L /* Don't do "&" character translation */
#if (WINVER >= 0x0400)
#define SS_NOTIFY        0x00000100L
#define SS_CENTERIMAGE   0x00000200L
#define SS_RIGHTJUST     0x00000400L
#define SS_REALSIZEIMAGE 0x00000800L
#define SS_SUNKEN        0x00001000L
#define SS_EDITCONTROL   0x00002000L
#define SS_ENDELLIPSIS   0x00004000L
#define SS_PATHELLIPSIS  0x00008000L
#define SS_WORDELLIPSIS  0x0000C000L
#define SS_ELLIPSISMASK  0x0000C000L
#endif /* WINVER >= 0x0400 */

#ifndef NOWINMESSAGES
/*
 * Static Control Mesages
 */
#define STM_SETICON 0x0170
#define STM_GETICON 0x0171
#if (WINVER >= 0x0400)
#define STM_SETIMAGE 0x0172
#define STM_GETIMAGE 0x0173
#define STN_CLICKED  0
#define STN_DBLCLK   1
#define STN_ENABLE   2
#define STN_DISABLE  3
#endif /* WINVER >= 0x0400 */
#define STM_MSGMAX 0x0174
#endif /* !NOWINMESSAGES */

/*
 * Combo Box return Values
 */
#define CB_OKAY     0
#define CB_ERR      (-1)
#define CB_ERRSPACE (-2)

/*
 * Combo Box Notification Codes
 */
#define CBN_ERRSPACE     (-1)
#define CBN_SELCHANGE    1
#define CBN_DBLCLK       2
#define CBN_SETFOCUS     3
#define CBN_KILLFOCUS    4
#define CBN_EDITCHANGE   5
#define CBN_EDITUPDATE   6
#define CBN_DROPDOWN     7
#define CBN_CLOSEUP      8
#define CBN_SELENDOK     9
#define CBN_SELENDCANCEL 10

#ifndef NOWINSTYLES

/*
 * Combo Box styles
 */
#define CBS_SIMPLE            0x0001L
#define CBS_DROPDOWN          0x0002L
#define CBS_DROPDOWNLIST      0x0003L
#define CBS_OWNERDRAWFIXED    0x0010L
#define CBS_OWNERDRAWVARIABLE 0x0020L
#define CBS_AUTOHSCROLL       0x0040L
#define CBS_OEMCONVERT        0x0080L
#define CBS_SORT              0x0100L
#define CBS_HASSTRINGS        0x0200L
#define CBS_NOINTEGRALHEIGHT  0x0400L
#define CBS_DISABLENOSCROLL   0x0800L
#if (WINVER >= 0x0400)
#define CBS_UPPERCASE 0x2000L
#define CBS_LOWERCASE 0x4000L
#endif /* WINVER >= 0x0400 */

#endif /* !NOWINSTYLES */

/*
 * Combo Box messages
 */
#ifndef NOWINMESSAGES
#define CB_GETEDITSEL            0x0140
#define CB_LIMITTEXT             0x0141
#define CB_SETEDITSEL            0x0142
#define CB_ADDSTRING             0x0143
#define CB_DELETESTRING          0x0144
#define CB_DIR                   0x0145
#define CB_GETCOUNT              0x0146
#define CB_GETCURSEL             0x0147
#define CB_GETLBTEXT             0x0148
#define CB_GETLBTEXTLEN          0x0149
#define CB_INSERTSTRING          0x014A
#define CB_RESETCONTENT          0x014B
#define CB_FINDSTRING            0x014C
#define CB_SELECTSTRING          0x014D
#define CB_SETCURSEL             0x014E
#define CB_SHOWDROPDOWN          0x014F
#define CB_GETITEMDATA           0x0150
#define CB_SETITEMDATA           0x0151
#define CB_GETDROPPEDCONTROLRECT 0x0152
#define CB_SETITEMHEIGHT         0x0153
#define CB_GETITEMHEIGHT         0x0154
#define CB_SETEXTENDEDUI         0x0155
#define CB_GETEXTENDEDUI         0x0156
#define CB_GETDROPPEDSTATE       0x0157
#define CB_FINDSTRINGEXACT       0x0158
#define CB_SETLOCALE             0x0159
#define CB_GETLOCALE             0x015A
#if (WINVER >= 0x0400)
#define CB_GETTOPINDEX         0x015b
#define CB_SETTOPINDEX         0x015c
#define CB_GETHORIZONTALEXTENT 0x015d
#define CB_SETHORIZONTALEXTENT 0x015e
#define CB_GETDROPPEDWIDTH     0x015f
#define CB_SETDROPPEDWIDTH     0x0160
#define CB_INITSTORAGE         0x0161
#if defined(_WIN32_WCE) && (_WIN32_WCE >= 0x0400)
#define CB_MULTIPLEADDSTRING 0x0163
#endif
#endif /* WINVER >= 0x0400 */

#if (_WIN32_WINNT >= 0x0501)
#define CB_GETCOMBOBOXINFO 0x0164
#endif /* _WIN32_WINNT >= 0x0501 */

#if (_WIN32_WINNT >= 0x0501)
#define CB_MSGMAX 0x0165
#elif defined(_WIN32_WCE) && (_WIN32_WCE >= 0x0400)
#define CB_MSGMAX 0x0163
#elif (WINVER >= 0x0400)
#define CB_MSGMAX 0x0162
#else
#define CB_MSGMAX 0x015B
#endif
#endif /* !NOWINMESSAGES */

#endif //_CTRL_TYPE_H_