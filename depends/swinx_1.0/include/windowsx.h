#ifndef _WINDOWSX_H_
#define _WINDOWSX_H_

#define DeletePen(hpen)      DeleteObject((HGDIOBJ)(HPEN)(hpen))
#define SelectPen(hdc, hpen) ((HPEN)SelectObject((hdc), (HGDIOBJ)(HPEN)(hpen)))
#define GetStockPen(i)       ((HPEN)GetStockObject(i))

#define DeleteBrush(hbr)      DeleteObject((HGDIOBJ)(HBRUSH)(hbr))
#define SelectBrush(hdc, hbr) ((HBRUSH)SelectObject((hdc), (HGDIOBJ)(HBRUSH)(hbr)))
#define GetStockBrush(i)      ((HBRUSH)GetStockObject(i))

#define DeleteRgn(hrgn) DeleteObject((HGDIOBJ)(HRGN)(hrgn))

#define GetWindowInstance(hwnd) ((HMODULE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE))

#define GetWindowStyle(hwnd)   ((DWORD)GetWindowLong(hwnd, GWL_STYLE))
#define GetWindowExStyle(hwnd) ((DWORD)GetWindowLong(hwnd, GWL_EXSTYLE))

#define GetWindowOwner(hwnd) GetWindow(hwnd, GW_OWNER)

#define GetFirstChild(hwnd)   GetTopWindow(hwnd)
#define GetFirstSibling(hwnd) GetWindow(hwnd, GW_HWNDFIRST)
#define GetLastSibling(hwnd)  GetWindow(hwnd, GW_HWNDLAST)
#define GetNextSibling(hwnd)  GetWindow(hwnd, GW_HWNDNEXT)
#define GetPrevSibling(hwnd)  GetWindow(hwnd, GW_HWNDPREV)

#define GetWindowID(hwnd) GetDlgCtrlID(hwnd)

#define SubclassWindow(hwnd, lpfn) ((WNDPROC)SetWindowLongPtr((hwnd), GWLP_WNDPROC, (LPARAM)(WNDPROC)(lpfn)))

#define IsMinimized(hwnd) IsIconic(hwnd)
#define IsMaximized(hwnd) IsZoomed(hwnd)
#define IsRestored(hwnd)  ((GetWindowStyle(hwnd) & (WS_MINIMIZE | WS_MAXIMIZE)) == 0L)

#ifndef SNDMSG
#define SNDMSG ::SendMessage
#endif // SNDMSG

#define SetWindowFont(hwnd, hfont, fRedraw) FORWARD_WM_SETFONT((hwnd), (hfont), (fRedraw), SNDMSG)

#define GetWindowFont(hwnd) FORWARD_WM_GETFONT((hwnd), SNDMSG)

#define DeleteFont(hfont)      DeleteObject((HGDIOBJ)(HFONT)(hfont))
#define SelectFont(hdc, hfont) ((HFONT)SelectObject((hdc), (HGDIOBJ)(HFONT)(hfont)))
#define GetStockFont(i)        ((HFONT)GetStockObject(i))

#define DeleteBitmap(hbm)      DeleteObject((HGDIOBJ)(HBITMAP)(hbm))
#define SelectBitmap(hdc, hbm) ((HBITMAP)SelectObject((hdc), (HGDIOBJ)(HBITMAP)(hbm)))

#define InsetRect(lprc, dx, dy) InflateRect((lprc), -(dx), -(dy))

#define GET_WM_COMMAND_MPS(id, hwnd, cmd) (WPARAM) MAKELONG(id, cmd), (LPARAM)(hwnd)

#endif //_WINDOWSX_H_