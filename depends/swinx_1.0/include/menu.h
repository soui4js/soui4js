#ifndef _MENU_H__
#define _MENU_H__

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

#ifndef WINUSERAPI
#define WINUSERAPI
#endif

    typedef struct tagMENUITEMINFO
    {
        UINT cbSize;
        UINT fMask;
        UINT fType;
        UINT fState;
        UINT wID;
        HMENU hSubMenu;
        HBITMAP hbmpChecked;
        HBITMAP hbmpUnchecked;
        ULONG_PTR dwItemData;
        LPSTR dwTypeData;
        UINT cch;
        HBITMAP hbmpItem;
    } MENUITEMINFO, *LPMENUITEMINFO, *const LPCMENUITEMINFO;

#define MIIM_BITMAP     0x00000080  // 检索或设置 hbmpItem 成员。
#define MIIM_CHECKMARKS 0x00000008  // 检索或设置 hbmpChecked 和 hbmpUnchecked 成员。
#define MIIM_DATA       0x00000020  // 检索或设置 dwItemData 成员。
#define MIIM_FTYPE      0x00000100  // 检索或设置 fType 成员。
#define MIIM_ID         0x00000002  // 检索或设置 wID 成员。
#define MIIM_STATE      0x00000001  // 检索或设置 fState 成员。
#define MIIM_STRING     0x00000040  // 检索或设置 dwTypeData 成员。
#define MIIM_SUBMENU    0x00000004  // 检索或设置 hSubMenu 成员。
#define MIIM_TYPE       0x00000010  // 检索或设置 fType 和 dwTypeData 成员 MIIM_TYPE 替换为 MIIM_BITMAP、 MIIM_FTYPE和 MIIM_STRING。
#define MFT_BITMAP      0x00000004L // 使用位图显示菜单项。 dwTypeData 成员的低序字是位图句柄，cch 成员将被忽略。MFT_BITMAP 替换为 MIIM_BITMAP 和 hbmpItem。

#define MFT_MENUBARBREAK 0x00000020L // 在菜单栏的新行 (Places菜单项) ，或者在下拉菜单、子菜单或快捷菜单) 的新列 (中。 对于下拉菜单、子菜单或快捷菜单，垂直线将新列与旧列分隔开。
#define MFT_MENUBREAK    0x00000040L // 在菜单栏的新行 (Places菜单项) ，或者在下拉菜单、子菜单或快捷菜单) 的新列 (中。 对于下拉菜单、子菜单或快捷菜单，列不会用垂直线分隔。
#define MFT_OWNERDRAW    0x00000100L // 将绘制菜单项的责任分配给拥有菜单的窗口。 窗口在菜单首次显示之前接收 WM_MEASUREITEM 消息，每当必须更新菜单项的外观时，都会收到 WM_DRAWITEM 消息。 如果指定了此值， 则 dwTypeData 成员包含应用程序定义的值。
#define MFT_RADIOCHECK   0x00000200L // 如果 hbmpChecked 成员为 NULL，则使用单选按钮标记而不是检查标记显示所选菜单项。
#define MFT_RIGHTJUSTIFY 0x00004000L // 将菜单项和任何后续项右对齐。 仅当菜单项位于菜单栏中时，此值才有效。
#define MFT_RIGHTORDER   0x00002000L // 指定菜单从右到左级联， (默认值为从左到右) 。 这用于支持从右到左的语言，例如阿拉伯语和希伯来语。
#define MFT_SEPARATOR    0x00000800L // 指定菜单项是分隔符。 菜单项分隔符显示为水平分隔线。 忽略 dwTypeData 和 cch 成员。 此值仅在下拉菜单、子菜单或快捷菜单中有效。
#define MFT_STRING       0x00000000L // 使用文本字符串显示菜单项。 dwTypeData 成员是指向以 null 结尾的字符串的指针，cch 成员是字符串的长度。MFT_STRING 替换为 MIIM_STRING。

    WINUSERAPI
    HMENU
    WINAPI
    CreatePopupMenu(VOID);

    WINUSERAPI
    BOOL WINAPI DestroyMenu(HMENU hMenu);

    WINUSERAPI
    DWORD
    WINAPI
    CheckMenuItem(HMENU hMenu, UINT uIDCheckItem, UINT uCheck);

    WINUSERAPI
    BOOL WINAPI EnableMenuItem(HMENU hMenu, UINT uIDEnableItem, UINT uEnable);

    WINUSERAPI
    HMENU
    WINAPI
    GetSubMenu(HMENU hMenu, int nPos);

    WINUSERAPI
    UINT WINAPI GetMenuItemID(HMENU hMenu, int nPos);

    WINUSERAPI
    BOOL WINAPI InsertMenuItem(HMENU hmenu, UINT item, BOOL fByPosition, LPCMENUITEMINFO lpmi);

    WINUSERAPI
    BOOL WINAPI SetMenuItemInfo(HMENU hmenu, UINT item, BOOL fByPosition, LPCMENUITEMINFO lpmi);

    WINUSERAPI
    BOOL WINAPI GetMenuItemInfo(HMENU hmenu, UINT item, BOOL fByPosition, LPCMENUITEMINFO lpmi);

    WINUSERAPI
    int WINAPI GetMenuItemCount(HMENU hMenu);

    WINUSERAPI
    BOOL WINAPI InsertMenuA(HMENU hMenu, UINT uPosition, UINT uFlags, UINT_PTR uIDNewItem, LPCSTR lpNewItem);

    WINUSERAPI
    BOOL WINAPI InsertMenuW(HMENU hMenu, UINT uPosition, UINT uFlags, UINT_PTR uIDNewItem, LPCWSTR lpNewItem);

    WINUSERAPI
    BOOL WINAPI AppendMenuA(HMENU hMenu, UINT uFlags, UINT_PTR uIDNewItem, LPCSTR lpNewItem);

    WINUSERAPI
    BOOL WINAPI AppendMenuW(HMENU hMenu, UINT uFlags, UINT_PTR uIDNewItem, LPCWSTR lpNewItem);

    WINUSERAPI
    BOOL WINAPI ModifyMenuA(HMENU hMnu, UINT uPosition, UINT uFlags, UINT_PTR uIDNewItem, LPCSTR lpNewItem);

    WINUSERAPI
    BOOL WINAPI ModifyMenuW(HMENU hMnu, UINT uPosition, UINT uFlags, UINT_PTR uIDNewItem, LPCWSTR lpNewItem);

#ifdef UNICODE
#define InsertMenu InsertMenuW
#define AppendMenu AppendMenuW
#define ModifyMenu ModifyMenuW
#else
#define InsertMenu InsertMenuA
#define AppendMenu AppendMenuA
#define ModifyMenu ModifyMenuA
#endif // UNICDOE

    WINUSERAPI
    BOOL WINAPI RemoveMenu(HMENU hMenu, UINT uPosition, UINT uFlags);

    WINUSERAPI
    BOOL WINAPI DeleteMenu(HMENU hMenu, UINT uPosition, UINT uFlags);

    WINUSERAPI
    BOOL WINAPI SetMenuItemBitmaps(HMENU hMenu, UINT uPosition, UINT uFlags, HBITMAP hBitmapUnchecked, HBITMAP hBitmapChecked);

    WINUSERAPI
    LONG WINAPI GetMenuCheckMarkDimensions(VOID);

    WINUSERAPI
    BOOL WINAPI TrackPopupMenu(HMENU hMenu, UINT uFlags, int x, int y, int nReserved, HWND hWnd, CONST RECT *prcRect);

/* return codes for WM_MENUCHAR */
#define MNC_IGNORE  0
#define MNC_CLOSE   1
#define MNC_EXECUTE 2
#define MNC_SELECT  3

    typedef struct tagTPMPARAMS
    {
        UINT cbSize;    /* Size of structure */
        RECT rcExclude; /* Screen coordinates of rectangle to exclude when positioning */
    } TPMPARAMS;
    typedef TPMPARAMS FAR *LPTPMPARAMS;

    WINUSERAPI
    BOOL WINAPI TrackPopupMenuEx(HMENU, UINT, int, int, HWND, LPTPMPARAMS);

#define MNS_NOCHECK     0x80000000
#define MNS_MODELESS    0x40000000
#define MNS_DRAGDROP    0x20000000
#define MNS_AUTODISMISS 0x10000000
#define MNS_NOTIFYBYPOS 0x08000000
#define MNS_CHECKORBMP  0x04000000

#define MIM_MAXHEIGHT       0x00000001
#define MIM_BACKGROUND      0x00000002
#define MIM_HELPID          0x00000004
#define MIM_MENUDATA        0x00000008
#define MIM_STYLE           0x00000010
#define MIM_APPLYTOSUBMENUS 0x80000000

    typedef struct tagMENUINFO
    {
        DWORD cbSize;
        DWORD fMask;
        DWORD dwStyle;
        UINT cyMax;
        HBRUSH hbrBack;
        DWORD dwContextHelpID;
        ULONG_PTR dwMenuData;
    } MENUINFO, FAR *LPMENUINFO;
    typedef MENUINFO CONST FAR *LPCMENUINFO;

    WINUSERAPI
    BOOL WINAPI GetMenuInfo(HMENU, LPMENUINFO);

    WINUSERAPI
    BOOL WINAPI SetMenuInfo(HMENU, LPCMENUINFO);

    WINUSERAPI
    BOOL WINAPI SetMenuContextHelpId(HMENU hMenu, DWORD dwHelpID);

    WINUSERAPI
    DWORD WINAPI GetMenuContextHelpId(HMENU hMenu);

    WINUSERAPI
    BOOL WINAPI IsMenu(HMENU hMenu);

    WINUSERAPI
    BOOL WINAPI CheckMenuRadioItem(HMENU hmenu, UINT first, UINT last, UINT check, UINT flags);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif
