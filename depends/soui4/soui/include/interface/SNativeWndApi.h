//!�������
/*!
 */
STDMETHOD_(long, AddRef)(THIS) PURE;

//!�ͷ�����
/*!
 */
STDMETHOD_(long, Release)(THIS) PURE;

//!�ͷŶ���
/*!
 */
STDMETHOD_(void, OnFinalRelease)(THIS) PURE;
//////////////////////////////////////////////////////////////////////////

/**
 * @brief ����һ��Native����
 * @param lpWindowName ������
 * @param dwStyle ����style
 * @param dwExStyle ����exStyle
 * @param x ������ʾλ��X
 * @param y ������ʾλ��Y
 * @param nWidth ������ʾ���
 * @param nHeight ������ʾ�߶�
 * @param hWndParent ������
 * @param nID ����ID
 * @param lpParam ���Ӳ���
 * @return ����HWND
 */
STDMETHOD_(HWND, CreateNative)
(THIS_ LPCTSTR lpWindowName, DWORD dwStyle, DWORD dwExStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, int nID, LPVOID lpParam) PURE;

/**
 * @brief ��ȡ����HWND
 * @return ����HWND
 */
STDMETHOD_(HWND, GetHwnd)(THIS) PURE;

/**
 * @brief ��SNativeWnd�������໯һ��HWND
 * @param hWnd Ŀ��HWND
 * @return TRUE-�ɹ�
 */
STDMETHOD_(BOOL, SubclassWindow)(THIS_ HWND hWnd) PURE;

/**
 * @brief �����໯
 * @param bForce Ϊ���ǣ������ǰ���ڵ�wndproc����SNativeWnd����Ĵ��ڹ���Ҳִ�з����໯
 * @return ִ�з����໯�Ĵ���HWND
 */
STDMETHOD_(HWND, UnsubclassWindow)(THIS_ BOOL bForce /*= FALSE*/) PURE;

/**
 * @brief ��ȡ��ǰ�Ĵ�����Ϣ����
 * @return ������Ϣ����ָ��
 */
STDMETHOD_(const MSG *, GetCurrentMessage)(CTHIS) SCONST PURE;

/**
 * @brief ��ȡ����ID
 */
STDMETHOD_(int, GetDlgCtrlID)(CTHIS) SCONST PURE;

/**
 * @brief ��ȡ����Style
 */
STDMETHOD_(DWORD, GetStyle)(CTHIS) SCONST PURE;

/**
 * @brief ��ȡ����exStyle
 */
STDMETHOD_(DWORD, GetExStyle)(CTHIS) SCONST PURE;

/**
 * @brief ��ȡ���ڹ�������
 * @param nIndex ��������
 * @return ����ֵ
 */
STDMETHOD_(LONG_PTR, GetWindowLongPtr)(CTHIS_ int nIndex) SCONST PURE;

/**
 * @brief ���ô��ڹ�������
 * @param nIndex ��������
 * @param dwNewLong ����ֵ
 * @return ԭ����ֵ
 */
STDMETHOD_(LONG_PTR, SetWindowLongPtr)(THIS_ int nIndex, LONG_PTR dwNewLong) PURE;

/**
 * @brief ��ȡ������
 * @return ������HWND
 */
STDMETHOD_(HWND, GetParent)(THIS) PURE;

/**
 * @brief ���ø�����
 * @param hWndNewParent �¸�����HWND
 * @return ԭ������HWND
 */
STDMETHOD_(HWND, SetParent)(THIS_ HWND hWndNewParent) PURE;

/**
 * @brief ��ȡ���ڵ�enable״̬
 * @return TRUE-enable
 */
STDMETHOD_(BOOL, IsWindowEnabled)(CTHIS) SCONST PURE;

/**
 * @brief �޸Ĵ���style
 * @param dwRemove ���Ƴ���־λ
 * @param dwAdd �����ӱ�־λ
 * @param nFlags Window positioning flags
 * @return TRUE-SUCCEED
 */
STDMETHOD_(BOOL, ModifyStyle)(THIS_ DWORD dwRemove, DWORD dwAdd, UINT nFlags /*=0*/) PURE;

/**
 * @brief �޸Ĵ���exStyle
 * @param dwRemove ���Ƴ���־λ
 * @param dwAdd �����ӱ�־λ
 * @param nFlags Window positioning flags
 * @return TRUE-SUCCEED
 */
STDMETHOD_(BOOL, ModifyStyleEx)(THIS_ DWORD dwRemove, DWORD dwAdd, UINT nFlags /*=0*/) PURE;

/**
 * @brief ���ô��ڵ�Pos
 * @param hWndInsertAfter zorderλ��
 * @param x
 * @param y
 * @param cx
 * @param cy
 * @param nFlags ��־λ
 * @return TRUE-SUCCEED
 */
STDMETHOD_(BOOL, SetWindowPos)
(THIS_ HWND hWndInsertAfter, int x, int y, int cx, int cy, UINT nFlags) PURE;

/**
 * @brief ���ھ���
 * @param hWndCenter ��Ծ��д���
 * @return TRUE-SUCCEED
 */
STDMETHOD_(BOOL, CenterWindow)(THIS_ HWND hWndCenter /*= NULL*/) PURE;

/**
 * @brief ���ٴ���
 * @return TRUE-SUCCEED
 */
STDMETHOD_(BOOL, DestroyWindow)(THIS) PURE;

/**
 * @brief ����Ƿ�Ϊ��ЧHWND
 * @return
 */
STDMETHOD_(BOOL, IsWindow)(CTHIS) SCONST PURE;

/**
 * @brief ˢ�´���
 * @param bErase �����������
 * @return TRUE-SUCCEED
 */
STDMETHOD_(BOOL, Invalidate)(THIS_ BOOL bErase /*= TRUE*/) PURE;

/**
 * @brief ˢ�´���ָ������
 * @param lpRect ��ˢ������
 * @param bErase �����������
 * @return TRUE-SUCCEED
 */
STDMETHOD_(BOOL, InvalidateRect)(THIS_ LPCRECT lpRect, BOOL bErase /* = TRUE*/) PURE;

/**
 * @brief ��ȡ����λ��
 * @param[out] lpRect ����λ��
 * @return TRUE-SUCCEED
 */
STDMETHOD_(BOOL, GetWindowRect)(CTHIS_ LPRECT lpRect) SCONST PURE;

/**
 * @brief ��ȡ���ڿͻ���λ��
 * @param[out] lpRect �ͻ���λ��
 * @return TRUE-SUCCEED
 */
STDMETHOD_(BOOL, GetClientRect)(CTHIS_ LPRECT lpRect) SCONST PURE;

/**
 * @brief ����Դ��ڵ�����ת��Ϊ��Ļ����
 * @param[in][out] lpPoint ��ת������
 * @return TRUE-SUCCEED
 */
STDMETHOD_(BOOL, ClientToScreen)(CTHIS_ LPPOINT lpPoint) SCONST PURE;

/**
 * @brief ����Դ��ڵľ�������ת��Ϊ��Ļ����
 * @param[in][out] lpRect ��ת������
 * @return TRUE-SUCCEED
 */
STDMETHOD_(BOOL, ClientToScreen2)(CTHIS_ LPRECT lpRect) SCONST PURE;

/**
 * @brief ����Ļ����ת��Ϊ��������
 * @param[in][out] lpPoint ��ת������
 * @return TRUE-SUCCEED
 */
STDMETHOD_(BOOL, ScreenToClient)(CTHIS_ LPPOINT lpPoint) SCONST PURE;

/**
 * @brief ����Ļ��������ת��Ϊ��������
 * @param[in][out] lpRect ��ת������
 * @return TRUE-SUCCEED
 */
STDMETHOD_(BOOL, ScreenToClient2)(CTHIS_ LPRECT lpRect) SCONST PURE;

/**
 * @brief ��һ�鴰������ת��Ϊ�������һ�����ڵ�����
 * @param hWndTo Ŀ�괰��
 * @param[in][out] lpPoint ��������
 * @param nCount ���鳤��
 * @return TRUE-SUCCEED
 */
STDMETHOD_(int, MapWindowPoints)(CTHIS_ HWND hWndTo, LPPOINT lpPoint, UINT nCount) SCONST PURE;

/**
 * @brief ��һ�����ھ���ӳ��Ϊ�������һ�����ڵľ���
 * @param hWndTo Ŀ�괰��
 * @param[in][out] lpRect ��ת������
 * @return TRUE-SUCCEED
 */
STDMETHOD_(int, MapWindowRect)(CTHIS_ HWND hWndTo, LPRECT lpRect) SCONST PURE;

/**
 * @brief ����һ�˶�ʱ��
 * @param nIDEvent ��ʱ��ID
 * @param nElapse ��ʱ(ms)
 * @param lpfnTimer ��ʱ����������Ϊnullʱ����WM_TIMER��Ϣ
 * @return ��ʱ��ID
 */
STDMETHOD_(UINT_PTR, SetTimer)
(THIS_ UINT_PTR nIDEvent, UINT nElapse, void(CALLBACK *lpfnTimer)(HWND, UINT, UINT_PTR, DWORD) /*= NULL*/) PURE;

/**
 * @brief ɾ��һ����ʱ��
 * @param nIDEvent ��ʱ��ID
 * @return
 */
STDMETHOD_(BOOL, KillTimer)(THIS_ UINT_PTR nIDEvent) PURE;

/**
 * @brief ��ȡ���ڵĿͻ���DC
 * @return �ͻ���DC
 */
STDMETHOD_(HDC, GetDC)(THIS) PURE;

/**
 * @brief ��ȡ����DC
 * @return ����DC
 */
STDMETHOD_(HDC, GetWindowDC)(THIS) PURE;

/**
 * @brief �ͷ�DC
 * @param hDC DC
 * @return
 */
STDMETHOD_(int, ReleaseDC)(THIS_ HDC hDC) PURE;

/**
 * @brief ����һ�����
 * @param hBitmap ���λͼ
 * @return
 */
STDMETHOD_(BOOL, CreateCaret)(THIS_ HBITMAP hBitmap) PURE;

/**
 * @brief ���ع��
 * @return
 */
STDMETHOD_(BOOL, HideCaret)(THIS) PURE;

/**
 * @brief ��ʾ���
 * @return
 */
STDMETHOD_(BOOL, ShowCaret)(THIS) PURE;

/**
 * @brief ��ȡ��ǰ����겶���HWND
 * @return ��겶���HWND
 */
STDMETHOD_(HWND, GetCapture)(THIS) PURE;

/**
 * @brief ����ǰ��������Ϊ�����������
 * @return ǰһ��HWND
 */
STDMETHOD_(HWND, SetCapture)(THIS) PURE;

/**
 * @brief �˳���겶��
 * @return
 */
STDMETHOD_(BOOL, ReleaseCapture)(THIS) PURE;

/**
 * @brief �ô��ڳ�Ϊ���ռ�������Ľ��㴰��
 * @return ǰһ�����㴰��
 */
STDMETHOD_(HWND, SetFocus)(THIS) PURE;

/**
 * @brief ͬ��ִ��һ����Ϣ�����ڴ������
 * @param message msg id
 * @param wParam
 * @param lParam
 * @return ��Ϣ������ֵ
 */
STDMETHOD_(LRESULT, SendMessage)
(THIS_ UINT message, WPARAM wParam /*= 0*/, LPARAM lParam /*= 0*/) PURE;

/**
 * @brief �첽ִ��һ����Ϣ�����ڴ������
 * @param message msg id
 * @param wParam
 * @param lParam
 * @return ��Ϣ������ֵ
 */
STDMETHOD_(BOOL, PostMessage)
(THIS_ UINT message, WPARAM wParam /*= 0*/, LPARAM lParam /*= 0*/) PURE;

STDMETHOD_(BOOL, SendNotifyMessage)
(THIS_ UINT message, WPARAM wParam /*= 0*/, LPARAM lParam /*= 0*/) PURE;

/**
 * @brief ���ô��ڱ���
 * @param lpszString �����ı�
 * @return
 */
STDMETHOD_(BOOL, SetWindowText)(THIS_ LPCTSTR lpszString) PURE;

/**
 * @brief ��ȡ���ڱ����ı�
 * @param lpszStringBuf ������
 * @param nMaxCount ����������
 * @return lpszStringBufΪnullʱ�������ݳ���
 */
STDMETHOD_(int, GetWindowText)(CTHIS_ LPTSTR lpszStringBuf, int nMaxCount) SCONST PURE;

/**
 * @brief ��ѯ�Ƿ�Ϊ��С��״̬
 * @return TRUE-��С��
 */
STDMETHOD_(BOOL, IsIconic)(CTHIS) SCONST PURE;

/**
 * @brief ��ѯ�Ƿ�Ϊ���״̬
 * @return TRUE-���
 */
STDMETHOD_(BOOL, IsZoomed)(CTHIS) SCONST PURE;

/**
 * @brief ��ѯ�����Ƿ�ɼ�
 * @return TRUE-�ɼ�
 */
STDMETHOD_(BOOL, IsWindowVisible)(CTHIS) SCONST PURE;

/**
 * @brief �ƶ�����λ��
 * @param x
 * @param y
 * @param nWidth
 * @param nHeight
 * @param bRepaint ˢ�´��ڱ�־
 * @return
 */
STDMETHOD_(BOOL, MoveWindow)
(THIS_ int x, int y, int nWidth, int nHeight, BOOL bRepaint /*= TRUE*/) PURE;

/**
 * @brief �ƶ�����λ��
 * @param lpRect Ŀ��λ��
 * @param bRepaint ˢ�±�־
 * @return
 */
STDMETHOD_(BOOL, MoveWindow2)(THIS_ LPCRECT lpRect, BOOL bRepaint /*= TRUE*/) PURE;

/**
 * @brief ��ʾ����
 * @param nCmdShow ��ʾ��־
 * @return
 */
STDMETHOD_(BOOL, ShowWindow)(THIS_ int nCmdShow) PURE;

/**
 * @brief ���ô�����������
 * @param hRgn ��������
 * @param bRedraw ˢ�±�־
 * @return
 */
STDMETHOD_(int, SetWindowRgn)(THIS_ HRGN hRgn, BOOL bRedraw /*=TRUE*/) PURE;

/**
 * @brief ���ô��ڵķֲ�����
 * @param crKey ͸��ɫ
 * @param bAlpha ͸����
 * @param dwFlags ��־λ
 * @return
 */
STDMETHOD_(BOOL, SetLayeredWindowAttributes)
(THIS_ COLORREF crKey, BYTE bAlpha, DWORD dwFlags) PURE;

/**
 * @brief ���·ֲ㴰��
 * @param hdcDst
 * @param pptDst
 * @param psize
 * @param hdcSrc
 * @param pptSrc
 * @param crKey
 * @param pblend
 * @param dwFlags
 * @return
 */
STDMETHOD_(BOOL, UpdateLayeredWindow)
(THIS_ HDC hdcDst, POINT *pptDst, SIZE *psize, HDC hdcSrc, POINT *pptSrc, COLORREF crKey, BLENDFUNCTION *pblend, DWORD dwFlags) PURE;

/**
 * @brief ���ô�����Ϣ������
 * @param fun ��Ϣ������
 * @param ctx ��Ϣ������Context
 * @return
 */
STDMETHOD_(void, SetMsgHandler)(THIS_ FunMsgHandler fun, void *ctx) PURE;

/**
 * @brief ��ȡ������Ϣ�������
 * @return ��Ϣ�������
 */
STDMETHOD_(MsgHandlerInfo *, GetMsgHandler)(THIS) PURE;
