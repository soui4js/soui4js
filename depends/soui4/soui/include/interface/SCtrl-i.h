/************************************************************************/
/*   ���ﶨ��ؼ������ӿ�,���нӿڶ���IObjRef�̳�,����ָ���Լ��Ľӿ�ID  */
/************************************************************************/
#pragma once
#include <interface/SWindow-i.h>
#include <interface/SSkinobj-i.h>
#include <interface/SRender-i.h>
#include <interface/sstring-i.h>
#include <interface/SAdapter-i.h>
#include <interface/SListViewItemLocator-i.h>
#include <interface/STreeViewItemLocator-i.h>
#include <interface/STileViewItemLocator-i.h>

SNSBEGIN

#undef INTERFACE
#define INTERFACE ICtrl
DECLARE_INTERFACE_(ICtrl, IObjRef)
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IOsrPanel
DECLARE_INTERFACE_IID_(IOsrPanel, ICtrl, "85A3CD3C-D665-454b-AABC-EE8389BBD914")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief �������б��ж�Ӧ������
     * @param index -- ����ֵ����listview������һ�������ţ���treeview������һ��HTREEITEMֵ
     * @return
     */
    STDMETHOD_(void, SetItemIndex)(THIS_ LPARAM index) PURE;

    /**
     * @brief ��ȡ���б��е�����
     * @return LPARAM ���б��е�����
     */
    STDMETHOD_(LPARAM, GetItemIndex)(CTHIS) SCONST PURE;

    /**
     * @brief �����б�����û�����
     * @param dwData -- �û�����
     * @return
     */
    STDMETHOD_(void, SetItemData)(THIS_ LPARAM dwData) PURE;

    /**
     * @brief ��ȡ���б��е��û�����
     * @return LPARAM ���б��е��û�����
     */
    STDMETHOD_(LPARAM, GetItemData)(CTHIS) SCONST PURE;

	/**
	 * @brief ��panel������ת��Ϊhost����
     * @param[in,out] POINT *pt ��������
     * @return void
	*/
	STDMETHOD_(void,PtToHost)(THIS_ POINT *pt) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IItemPanel
DECLARE_INTERFACE_IID_(IItemPanel, IOsrPanel, "176CDF98-260E-4070-91B5-E6E163F909A4")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief �������б��ж�Ӧ������
     * @param index -- ����ֵ����listview������һ�������ţ���treeview������һ��HTREEITEMֵ
     * @return
     */
    STDMETHOD_(void, SetItemIndex)(THIS_ LPARAM index) PURE;

    /**
     * @brief ��ȡ���б��е�����
     * @return LPARAM ���б��е�����
     */
    STDMETHOD_(LPARAM, GetItemIndex)(CTHIS) SCONST PURE;

    /**
     * @brief �����б�����û�����
     * @param dwData -- �û�����
     * @return
     */
    STDMETHOD_(void, SetItemData)(THIS_ LPARAM dwData) PURE;

    /**
     * @brief ��ȡ���б��е��û�����
     * @return LPARAM ���б��е��û�����
     */
    STDMETHOD_(LPARAM, GetItemData)(CTHIS) SCONST PURE;

    /**
     * @brief ��panel������ת��Ϊhost����
     * @param[in,out] POINT *pt ��������
     * @return void
    */
    STDMETHOD_(void, PtToHost)(THIS_ POINT * pt) SCONST PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief �����б����skin
     * @param pSkin -- �б����skin
     * @return
     */
    STDMETHOD_(void, SetSkin)(THIS_ ISkinObj * pSkin) PURE;

    /**
     * @brief �����б������ɫ����
     * @param crBk -- ������ɫ
     * @param crSelBk -- ѡ��״̬�ı�����ɫ
     * @return
     */
    STDMETHOD_(void, SetColor)(THIS_ COLORREF crBk, COLORREF crSelBk) PURE;
};

#undef INTERFACE
#define INTERFACE IImageWnd
DECLARE_INTERFACE_IID_(IImageWnd, ICtrl, "42148B05-6223-46f6-B903-D42D84038546")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ����skin
     * @param pSkin -- skin����
     * @param iFrame -- skin����ͼ����
     * @param bAutoFree -- �ؼ�����pSkin��־��ΪTRUEʱ���÷������ͷŸ�Skin
     * @return BOOL TRUE-�ɹ���FALSE-ʧ��
     */
    STDMETHOD_(BOOL, SetSkin)(THIS_ ISkinObj * pSkin, int iFrame DEF_VAL(0), BOOL bAutoFree DEF_VAL(TRUE)) PURE;

    /**
     * SImageWnd::GetSkin
     * @brief    ��ȡ��Դ
     * @return   ����ֵISkinObjָ��
     *
     * Describe  ��ȡ��Դ
     */
    STDMETHOD_(ISkinObj *, GetSkin)(THIS) PURE;

    /**
     * SImageWnd::SetImage
     * @param    IBitmap * pBitmap -- ͼƬ����
     * @param    FilterLevel fl -- FilterLevel
     * @return   void
     *
     * Describe  ���û���ͼƬ
     */
    STDMETHOD_(void, SetImage)(THIS_ IBitmapS * pBitmap, FilterLevel fl DEF_VAL(kNone_FilterLevel)) PURE;

    /**
     * @brief ��ȡ��ǰ���õ�IBitmapS����
     * @return IBitmapS * -- ��ǰ���õ�IBitmapS����
     */
    STDMETHOD_(IBitmapS *, GetImage)(THIS) PURE;

    /**
     * SImageWnd::SetIcon
     * @param    int nSubID -- ��ͼ��Skin�е�������
     * @brief    ����ͼ��
     * @return   ����ֵBOOL �ɹ�--TRUE ʧ��--FALSE
     *
     * Describe  ����ͼ��
     */
    STDMETHOD_(BOOL, SetIcon)(THIS_ int nSubID) PURE;
};

#undef INTERFACE
#define INTERFACE IAnimateImgWnd
DECLARE_INTERFACE_IID_(IAnimateImgWnd, ICtrl, "374A5086-AD38-4f15-83E0-002822E2595A")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * SAnimateImgWnd::Start
     * @brief    ��������
     *
     * Describe  ��������
     */
    STDMETHOD_(void, Start)(THIS) PURE;
    /**
     * SAnimateImgWnd::Stop
     * @brief    ֹͣ����
     *
     * Describe  ֹͣ����
     */
    STDMETHOD_(void, Stop)(THIS) PURE;

    /**
     * SAnimateImgWnd::IsPlaying
     * @brief    �ж϶�������״̬
     * @return   ����ֵ�Ƕ���״̬ TRUE -- ������
     *
     * Describe  �ж϶�������״̬
     */
    STDMETHOD_(BOOL, IsPlaying)(CTHIS) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IProgress
DECLARE_INTERFACE_IID_(IProgress, ICtrl, "77407E2D-582B-4ef2-A33A-427C933BAA8C")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////
    /**
     * SProgress::SetValue
     * @brief    ���ý���������ֵ
     * @param    int nValue  --  ����ֵ
     * @return   ����ֵ�� TRUE -- ���óɹ�
     *
     * Describe  ���ý���������ֵ
     */
    STDMETHOD_(BOOL, SetValue)(THIS_ int nValue) PURE;
    /**
     * SProgress::GetValue
     * @brief    ��ȡ����ֵ
     * @return   ����ֵ��int
     *
     * Describe  ��ȡ����ֵ
     */
    STDMETHOD_(int, GetValue)(CTHIS) SCONST PURE;

    /**
     * SProgress::SetRange
     * @param    int nMin  --  ������Сֵ
     * @param    int nMax  --  �������ֵ
     * @brief    ���ý���ֵ��С��ֵ
     *
     * Describe  ���ý���ֵ
     */
    STDMETHOD_(void, SetRange)(THIS_ int nMin, int nMax) PURE;
    /**
     * SProgress::GetRange
     * @param    int nMin  --  ������Сֵ
     * @param    int nMax  --  �������ֵ
     * @brief    ��ȡ����ֵ��С��ֵ
     *
     * Describe  ��ȡ����ֵ
     */
    STDMETHOD_(void, GetRange)(CTHIS_ int *pMin, int *pMax) SCONST PURE;
    /**
     * SProgress::IsVertical
     * @brief    �жϽ������Ƿ�Ϊ��ֱ״̬
     * @return   ����ֵ�� TRUE -- ��ֱ״̬
     *
     * Describe  ��ȡ����ֵ
     */
    STDMETHOD_(BOOL, IsVertical)(CTHIS) SCONST PURE;
};

typedef enum _ScrollBarID
{
    SSB_NULL = 0,
    SSB_HORZ = 1,
    SSB_VERT = 2,
    SSB_BOTH = (SSB_HORZ | SSB_VERT),
} ScrollBarID;

#undef INTERFACE
#define INTERFACE IPanel
DECLARE_INTERFACE_IID_(IPanel, ICtrl, "B1A97BB7-64BE-408f-AC7C-2197CC2F4DD0")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ��ʾ/���ع�����
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) PURE;

    /**
     * @brief Enable/Disable������
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) PURE;

    /**
     * @brief ��ȡ������Enable״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-enable
     */
    STDMETHOD_(BOOL, IsScrollBarEnable)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù���������
     * @param si --����������
     * @param bVertical -- TRUE-��ֱ������
     * @return
     */
    STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) PURE;

    /**
     * @brief ���ù�����λ��
     * @param bVertical -- TRUE-��ֱ������
     * @param nNewPos -- ����λ��
     * @param bRedraw -- �ػ��־
     * @return
     */
    STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ������λ��
     * @param bVertical -- TRUE-��ֱ������
     * @return ������λ��
     */
    STDMETHOD_(int, GetScrollPos)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù�������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param nMinPos -- ��Сֵ
     * @param nMaxPos -- ���ֵ
     * @param bRedraw -- �ػ��־
     * @return TRUE-�ɹ�
     */
    STDMETHOD_(BOOL, SetScrollRange)
    (THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ��������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param lpMinPos -- ��Сֵ
     * @param lpMaxPos -- ���ֵ
     * @return
     */
    STDMETHOD_(BOOL, GetScrollRange)
    (CTHIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST PURE;

    /**
     * @brief ��ѯ����������״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-����
     */
    STDMETHOD_(BOOL, HasScrollBar)(CTHIS_ BOOL bVertical) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IScrollView
DECLARE_INTERFACE_IID_(IScrollView, IPanel, "49B024D6-221D-42d4-902B-AFAAC5AFFE41")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ��ʾ/���ع�����
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) PURE;

    /**
     * @brief Enable/Disable������
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) PURE;

    /**
     * @brief ��ȡ������Enable״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-enable
     */
    STDMETHOD_(BOOL, IsScrollBarEnable)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù���������
     * @param si --����������
     * @param bVertical -- TRUE-��ֱ������
     * @return
     */
    STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) PURE;

    /**
     * @brief ���ù�����λ��
     * @param bVertical -- TRUE-��ֱ������
     * @param nNewPos -- ����λ��
     * @param bRedraw -- �ػ��־
     * @return
     */
    STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ������λ��
     * @param bVertical -- TRUE-��ֱ������
     * @return ������λ��
     */
    STDMETHOD_(int, GetScrollPos)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù�������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param nMinPos -- ��Сֵ
     * @param nMaxPos -- ���ֵ
     * @param bRedraw -- �ػ��־
     * @return TRUE-�ɹ�
     */
    STDMETHOD_(BOOL, SetScrollRange)
    (THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ��������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param lpMinPos -- ��Сֵ
     * @param lpMaxPos -- ���ֵ
     * @return
     */
    STDMETHOD_(BOOL, GetScrollRange)
    (CTHIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST PURE;

    /**
     * @brief ��ѯ����������״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-����
     */
    STDMETHOD_(BOOL, HasScrollBar)(CTHIS_ BOOL bVertical) SCONST PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ��ȡ��ͼ�ߴ�
     * @return SIZE-��ͼ�ߴ�
     */
    STDMETHOD_(SIZE, GetViewSize)(CTHIS) SCONST PURE;

    /**
     * @brief ������ͼ�ߴ�
     * @param szView ��ͼ�ߴ�
     * @return
     */
    STDMETHOD_(void, SetViewSize)(THIS_ SIZE szView) PURE;

    /**
     * @brief ��ȡ��ͼԭ������
     * @return POINT-ԭ������
     */
    STDMETHOD_(POINT, GetViewOrigin)(CTHIS) SCONST PURE;

    /**
     * @brief ������ͼԭ������
     * @param pt ԭ������
     * @return
     */
    STDMETHOD_(void, SetViewOrigin)(THIS_ POINT pt) PURE;
};

typedef enum _HeaderMask
{
    SHDI_WIDTH = 0x0001,
    SHDI_TEXT = 0x0002,
    SHDI_FORMAT = 0x0004,
    SHDI_LPARAM = 0x0008,
    SHDI_ORDER = 0x0010,
    SHDI_VISIBLE = 0x0020,
    SHDI_WEIGHT = 0x0040,
    SHDI_ALL = 0xffff,
} HeaderMask;

/**
 * @struct    _SHDITEM
 * @brief     �б�ͷ��
 *
 * Describe   �б�ͷ��
 */
typedef struct SHDITEM
{
    UINT mask;
    int cx;
    UINT fmt;
    UINT state;
    int iOrder;
    LPTSTR pszText;
    int cchMaxText;
    LPARAM lParam;
    BOOL bDpiAware;
    BOOL bVisible;
    float fWeight;
} SHDITEM, *LPSHDITEM;

#undef INTERFACE
#define INTERFACE IHeaderCtrl
DECLARE_INTERFACE_IID_(IHeaderCtrl, ICtrl, "60A8788F-C775-424f-AA82-DCA9CECE3D45")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * SHeaderCtrl::InsertItem
     * @brief    ��������
     * @param    int iItem --  ��������
     * @param    LPCTSTR pszText  --  �������
     * @param    int nWidth  -- ���
     * @param    BOOL bDpiAware -- dpi aware
     * @param    UINT fmt -- format flag
     * @param    LPARAM lParam -- ���Ӳ���
     * @return   ����int
     *
     * Describe  ��������
     */
    STDMETHOD_(int, InsertItem)
    (THIS_ int iItem, LPCTSTR pszText, int nWidth, UINT fmt, LPARAM lParam, BOOL bDpiAware /*=FALSE*/, float fWeight /*=0.0f*/) PURE;

	STDMETHOD_(int, InsertItemA)
		(THIS_ int iItem, LPCSTR pszText, int nWidth, UINT fmt, LPARAM lParam, BOOL bDpiAware /*=FALSE*/, float fWeight /*=0.0f*/) PURE;

    /**
     * SHeaderCtrl::GetItem
     * @brief    �������
     * @param    int iItem  --  ����
     * @param    SHDITEM *pItem  -- �����б���ṹ
     * @return   ����BOOL
     *
     * Describe  �������
     */
    STDMETHOD_(BOOL, GetItem)(CTHIS_ int iItem, SHDITEM *pItem) SCONST PURE;

    /**
     * @brief ���ñ�ͷ������
     * @param iItem --������
     * @param pItem --������
     * @return
     */
    STDMETHOD_(BOOL, SetItem)(THIS_ int iItem, const SHDITEM *pItem) PURE;

    /**
     * SHeaderCtrl::GetItemCount
     * @brief    ��ȡ�б������
     * @return   ����int
     *
     * Describe  ��ȡ�б������
     */
    STDMETHOD_(UINT, GetItemCount)(CTHIS) SCONST PURE;
    /**
     * SHeaderCtrl::GetTotalWidth
     * @brief    ������п��
     * @return   ����int
     *
     * Describe  ������п��
     */
    STDMETHOD_(int, GetTotalWidth)(CTHIS_ BOOL bMinWid DEF_VAL(FALSE)) SCONST PURE;

    /**
     * @brief ��ͷ�Զ���丸���ڿ�ȱ�־
     * @return TRUE-��ͷ�Զ���丸���ڿ��
     */
    STDMETHOD_(BOOL, IsAutoResize)(CTHIS) SCONST PURE;

    /**
     * SHeaderCtrl::GetItemWidth
     * @brief    ���ָ������
     * @param    int iItem  --  ����
     * @return   ����int
     *
     * Describe  �������
     */
    STDMETHOD_(int, GetItemWidth)(CTHIS_ int iItem) SCONST PURE;

    /**
     * SHeaderCtrl::DeleteItem
     * @brief    ɾ��ָ����
     * @param    int iItem  --  ����
     * @return   ����BOOL
     *
     * Describe  ɾ��ָ����
     */
    STDMETHOD_(BOOL, DeleteItem)(THIS_ int iItem) PURE;

    /**
     * SHeaderCtrl::DeleteAllItems
     * @brief    ɾ��������
     *
     * Describe  �������
     */
    STDMETHOD_(void, DeleteAllItems)(THIS) PURE;

    /**
     * @brief ���ñ�ͷ��������־
     * @param iItem --��ͷ������
     * @param sortFlag --�����־
     * @remark �����־�ᴫ�ݵ��б������ص��ӿ�,�û��ڻص��ӿ���ʵ����������
     */
    STDMETHOD_(void, SetItemSort)(THIS_ int iItem, UINT sortFlag) PURE;

    /**
     * @brief ���ñ�ͷ���Ƿ�����
     * @param iItem --��ͷ������
     * @param visible -- TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(void, SetItemVisible)(THIS_ int iItem, BOOL visible) PURE;

    /**
     * @brief ��ѯ��ͷ���Ƿ�����
     * @param iItem --��ͷ������
     * @return BOOL
     */
    STDMETHOD_(BOOL, IsItemVisible)(CTHIS_ int iItem) SCONST PURE;

    /**
     * @brief    ��ȡ��ͷ��
     * @param    int iOrder  -- show order
	 * @return   int item index
     *
     * Describe  ��ȡ��ͷ���λ��
     */
	STDMETHOD_(int,GetOriItemIndex)(CTHIS_ int iOrder) SCONST PURE;

	/**
     * @brief    ��ȡ��ͷ���λ��
     * @param    int iItem  --  ����
	 * @param    LPRECT prc  --  ��ͷ���λ��
     *
     * Describe  ��ȡ��ͷ���λ��
     */
	STDMETHOD_(void, GetItemRect)(CTHIS_ int iItem,LPRECT prc) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IListView
DECLARE_INTERFACE_IID_(IListView, IPanel, "E584B16A-6BDB-4afb-8BCC-3A1ABACD2FE2")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ��ʾ/���ع�����
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) PURE;

    /**
     * @brief Enable/Disable������
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) PURE;

    /**
     * @brief ��ȡ������Enable״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-enable
     */
    STDMETHOD_(BOOL, IsScrollBarEnable)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù���������
     * @param si --����������
     * @param bVertical -- TRUE-��ֱ������
     * @return
     */
    STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) PURE;

    /**
     * @brief ���ù�����λ��
     * @param bVertical -- TRUE-��ֱ������
     * @param nNewPos -- ����λ��
     * @param bRedraw -- �ػ��־
     * @return
     */
    STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ������λ��
     * @param bVertical -- TRUE-��ֱ������
     * @return ������λ��
     */
    STDMETHOD_(int, GetScrollPos)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù�������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param nMinPos -- ��Сֵ
     * @param nMaxPos -- ���ֵ
     * @param bRedraw -- �ػ��־
     * @return TRUE-�ɹ�
     */
    STDMETHOD_(BOOL, SetScrollRange)
    (THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ��������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param lpMinPos -- ��Сֵ
     * @param lpMaxPos -- ���ֵ
     * @return
     */
    STDMETHOD_(BOOL, GetScrollRange)
    (CTHIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST PURE;

    /**
     * @brief ��ѯ����������״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-����
     */
    STDMETHOD_(BOOL, HasScrollBar)(CTHIS_ BOOL bVertical) SCONST PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief �����б��Adapter
     * @param adapter -- Adapter����
     * @return BOOL
     * @remark ͨ��ֻӦ�����б��ʼ����ʱ����һ�Σ��б�����Ӹ�Adapter�����ü���
     */
    STDMETHOD_(BOOL, SetAdapter)(THIS_ ILvAdapter * adapter) PURE;

    /**
     * @brief ��ȡ�ؼ���Adapter����
     * @return ILvAdapter* - Adapter����
     */
    STDMETHOD_(ILvAdapter *, GetAdapter)(CTHIS) SCONST PURE;

    /**
     * @brief �����б���λ�ö�λ��
     * @param pItemLocator -- λ�ö�λ��
     * @remark  λ�ö�λ����һ���������ź��б���ʾλ���໥ӳ��Ľӿڣ�ͨ��ʵ��λ�ö�λ�����û����Կ����б������ʾ��С
     */
    STDMETHOD_(void, SetItemLocator)(THIS_ IListViewItemLocator * pItemLocator) PURE;

    /**
     * @brief ��ȡλ�ö�λ��
     * @return IListViewItemLocator *
     */
    STDMETHOD_(IListViewItemLocator *, GetItemLocator)(CTHIS) SCONST PURE;

    /**
     * @brief ʹָ���й�������ͼ�ɼ���
     * @param iItem --�к�
     * @return
     */
    STDMETHOD_(void, EnsureVisible)(THIS_ int iItem) PURE;

    /**
     * @brief ѡ��ָ����
     * @param iItem --�к�
     * @param bNotify --����ѡ��״̬�¼���־
     * @return
     */
    STDMETHOD_(void, SetSel)(THIS_ int iItem, BOOL bNotify DEF_VAL(FALSE)) PURE;

    /**
     * @brief ��ȡ��ǰѡ����
     * @return int ѡ����������-1����ǰû��ѡ����
     */
    STDMETHOD_(int, GetSel)(CTHIS) SCONST PURE;

    /**
     * @brief �ȵ����
     * @param pt -- ��������
     * @return IItemPanel *--�����µ�ItemPanel
     */
    STDMETHOD_(IItemPanel *, HitTest)(CTHIS_ const POINT *pt) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IMcListView
DECLARE_INTERFACE_IID_(IMcListView, IPanel, "485AB4B5-6018-4710-BF8E-751FDE53E335")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ��ʾ/���ع�����
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) PURE;

    /**
     * @brief Enable/Disable������
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) PURE;

    /**
     * @brief ��ȡ������Enable״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-enable
     */
    STDMETHOD_(BOOL, IsScrollBarEnable)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù���������
     * @param si --����������
     * @param bVertical -- TRUE-��ֱ������
     * @return
     */
    STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) PURE;

    /**
     * @brief ���ù�����λ��
     * @param bVertical -- TRUE-��ֱ������
     * @param nNewPos -- ����λ��
     * @param bRedraw -- �ػ��־
     * @return
     */
    STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ������λ��
     * @param bVertical -- TRUE-��ֱ������
     * @return ������λ��
     */
    STDMETHOD_(int, GetScrollPos)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù�������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param nMinPos -- ��Сֵ
     * @param nMaxPos -- ���ֵ
     * @param bRedraw -- �ػ��־
     * @return TRUE-�ɹ�
     */
    STDMETHOD_(BOOL, SetScrollRange)
    (THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ��������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param lpMinPos -- ��Сֵ
     * @param lpMaxPos -- ���ֵ
     * @return
     */
    STDMETHOD_(BOOL, GetScrollRange)
    (CTHIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST PURE;

    /**
     * @brief ��ѯ����������״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-����
     */
    STDMETHOD_(BOOL, HasScrollBar)(CTHIS_ BOOL bVertical) SCONST PURE;
    //////////////////////////////////////////////////////////////////////////
    /**
     * @brief �����б��Adapter
     * @param adapter -- Adapter����
     * @return BOOL
     * @remark ͨ��ֻӦ�����б��ʼ����ʱ����һ�Σ��б�����Ӹ�Adapter�����ü���
     */
    STDMETHOD_(BOOL, SetAdapter)(THIS_ IMcAdapter * adapter) PURE;

    /**
     * @brief ��ȡ�ؼ���Adapter����
     * @return ILvAdapter* - Adapter����
     */
    STDMETHOD_(IMcAdapter *, GetAdapter)(CTHIS) SCONST PURE;

    /**
     * @brief �����б���λ�ö�λ��
     * @param pItemLocator -- λ�ö�λ��
     * @remark  λ�ö�λ����һ���������ź��б���ʾλ���໥ӳ��Ľӿڣ�ͨ��ʵ��λ�ö�λ�����û����Կ����б������ʾ��С
     */
    STDMETHOD_(void, SetItemLocator)(THIS_ IListViewItemLocator * pItemLocator) PURE;

    /**
     * @brief ��ȡλ�ö�λ��
     * @return IListViewItemLocator *
     */
    STDMETHOD_(IListViewItemLocator *, GetItemLocator)(CTHIS) SCONST PURE;

    /**
     * @brief ʹָ���й�������ͼ�ɼ���
     * @param iItem --�к�
     * @return
     */
    STDMETHOD_(void, EnsureVisible)(THIS_ int iItem) PURE;

    /**
     * @brief ѡ��ָ����
     * @param iItem --�к�
     * @param bNotify --����ѡ��״̬�¼���־
     * @return
     */
    STDMETHOD_(void, SetSel)(THIS_ int iItem, BOOL bNotify /*= FALSE*/) PURE;

    /**
     * @brief ��ȡ��ǰѡ����
     * @return int ѡ����������-1����ǰû��ѡ����
     */
    STDMETHOD_(int, GetSel)(CTHIS) SCONST PURE;

    /**
     * @brief �ȵ����
     * @param pt -- ��������
     * @return IItemPanel *--�����µ�ItemPanel
     */
    STDMETHOD_(IItemPanel *, HitTest)(CTHIS_ const POINT *pt) SCONST PURE;

    /**
     * @brief ��ȡ��ͷ�ؼ�
     * @return IHeaderCtrl *--��ͷ�ؼ�
     */
    STDMETHOD_(IHeaderCtrl *, GetIHeaderCtrl)(CTHIS) SCONST PURE;

    /**
     * @brief ����һ��
     * @param nIndex --����λ��,-1����append
     * @param pszText --�ı�
     * @param nWidth --ռ�ÿ��
     * @param fmt --��ʾ��ʽ
     * @param lParam --�Զ�������
     * @param bDpiAware --��ȸ�֪dpi����
     * @param fWeight --��ȵ�weight����
     * @return ����λ��
     */
    STDMETHOD_(int, InsertColumn)
    (THIS_ int nIndex, LPCTSTR pszText, int nWidth, UINT fmt, LPARAM lParam DEF_VAL(0), BOOL bDpiAware DEF_VAL(TRUE), float fWeight DEF_VAL(0.0f)) PURE;

    /**
     * @brief ɾ����
     * @param iCol --������
     * @return
     */
    STDMETHOD_(void, DeleteColumn)(THIS_ int iCol) PURE;

    /**
     * @brief ��ȡ����
     * @return int ����
     */
    STDMETHOD_(int, GetColumnCount)(CTHIS) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE ITreeView
DECLARE_INTERFACE_IID_(ITreeView, IPanel, "4FB8BF5D-950C-4f05-861C-FBEB119E4C2B")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ��ʾ/���ع�����
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) PURE;

    /**
     * @brief Enable/Disable������
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) PURE;

    /**
     * @brief ��ȡ������Enable״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-enable
     */
    STDMETHOD_(BOOL, IsScrollBarEnable)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù���������
     * @param si --����������
     * @param bVertical -- TRUE-��ֱ������
     * @return
     */
    STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) PURE;

    /**
     * @brief ���ù�����λ��
     * @param bVertical -- TRUE-��ֱ������
     * @param nNewPos -- ����λ��
     * @param bRedraw -- �ػ��־
     * @return
     */
    STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ������λ��
     * @param bVertical -- TRUE-��ֱ������
     * @return ������λ��
     */
    STDMETHOD_(int, GetScrollPos)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù�������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param nMinPos -- ��Сֵ
     * @param nMaxPos -- ���ֵ
     * @param bRedraw -- �ػ��־
     * @return TRUE-�ɹ�
     */
    STDMETHOD_(BOOL, SetScrollRange)
    (THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ��������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param lpMinPos -- ��Сֵ
     * @param lpMaxPos -- ���ֵ
     * @return
     */
    STDMETHOD_(BOOL, GetScrollRange)
    (CTHIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST PURE;

    /**
     * @brief ��ѯ����������״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-����
     */
    STDMETHOD_(BOOL, HasScrollBar)(CTHIS_ BOOL bVertical) SCONST PURE;
    //////////////////////////////////////////////////////////////////////////
    /**
     * @brief �����б��Adapter
     * @param adapter -- Adapter����
     * @return BOOL
     * @remark ͨ��ֻӦ�����б��ʼ����ʱ����һ�Σ��б�����Ӹ�Adapter�����ü���
     */
    STDMETHOD_(BOOL, SetAdapter)(THIS_ ITvAdapter * adapter) PURE;

    /**
     * @brief ��ȡ�ؼ���Adapter����
     * @return ILvAdapter* - Adapter����
     */
    STDMETHOD_(ITvAdapter *, GetAdapter)(CTHIS) SCONST PURE;

    /**
     * @brief �����б���λ�ö�λ��
     * @param pItemLocator -- λ�ö�λ��
     * @remark  λ�ö�λ����һ���������ź��б���ʾλ���໥ӳ��Ľӿڣ�ͨ��ʵ��λ�ö�λ�����û����Կ����б������ʾ��С
     */
    STDMETHOD_(void, SetItemLocator)(THIS_ ITreeViewItemLocator * pItemLocator) PURE;

    /**
     * @brief ��ȡλ�ö�λ��
     * @return IListViewItemLocator *
     */
    STDMETHOD_(ITreeViewItemLocator *, GetItemLocator)(CTHIS) SCONST PURE;

    /**
     * @brief ʹָ���й�������ͼ�ɼ���
     * @param hItem --HSTREEITEM
     * @return
     */
    STDMETHOD_(void, EnsureVisible)(THIS_ HSTREEITEM hItem) PURE;

    /**
     * @brief ѡ��ָ����
     * @param hItem --HSTREEITEM
     * @param bNotify --����ѡ��״̬�¼���־
     * @return
     */
    STDMETHOD_(void, SetSel)(THIS_ HSTREEITEM hItem, BOOL bNotify DEF_VAL(FALSE)) PURE;

    /**
     * @brief ��ȡ��ǰѡ����
     * @return HSTREEITEM ѡ����������0����ǰû��ѡ����
     */
    STDMETHOD_(HSTREEITEM, GetSel)(CTHIS) SCONST PURE;

    /**
     * @brief �ȵ����
     * @param pt -- ��������
     * @return IItemPanel *--�����µ�ItemPanel
     */
    STDMETHOD_(IItemPanel *, HitTest)(CTHIS_ const POINT *pt) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE ITileView
DECLARE_INTERFACE_IID_(ITileView, IPanel, "3718C98E-9177-4afb-986F-94B03A78F2C3")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ��ʾ/���ع�����
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) PURE;

    /**
     * @brief Enable/Disable������
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) PURE;

    /**
     * @brief ��ȡ������Enable״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-enable
     */
    STDMETHOD_(BOOL, IsScrollBarEnable)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù���������
     * @param si --����������
     * @param bVertical -- TRUE-��ֱ������
     * @return
     */
    STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) PURE;

    /**
     * @brief ���ù�����λ��
     * @param bVertical -- TRUE-��ֱ������
     * @param nNewPos -- ����λ��
     * @param bRedraw -- �ػ��־
     * @return
     */
    STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ������λ��
     * @param bVertical -- TRUE-��ֱ������
     * @return ������λ��
     */
    STDMETHOD_(int, GetScrollPos)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù�������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param nMinPos -- ��Сֵ
     * @param nMaxPos -- ���ֵ
     * @param bRedraw -- �ػ��־
     * @return TRUE-�ɹ�
     */
    STDMETHOD_(BOOL, SetScrollRange)
    (THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ��������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param lpMinPos -- ��Сֵ
     * @param lpMaxPos -- ���ֵ
     * @return
     */
    STDMETHOD_(BOOL, GetScrollRange)
    (CTHIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST PURE;

    /**
     * @brief ��ѯ����������״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-����
     */
    STDMETHOD_(BOOL, HasScrollBar)(CTHIS_ BOOL bVertical) SCONST PURE;
    //////////////////////////////////////////////////////////////////////////
    /**
     * @brief �����б��Adapter
     * @param adapter -- Adapter����
     * @return BOOL
     * @remark ͨ��ֻӦ�����б��ʼ����ʱ����һ�Σ��б�����Ӹ�Adapter�����ü���
     */
    STDMETHOD_(BOOL, SetAdapter)(THIS_ ILvAdapter * adapter) PURE;

    /**
     * @brief ��ȡ�ؼ���Adapter����
     * @return ILvAdapter* - Adapter����
     */
    STDMETHOD_(ILvAdapter *, GetAdapter)(CTHIS) SCONST PURE;

    /**
     * @brief �����б���λ�ö�λ��
     * @param pItemLocator -- λ�ö�λ��
     * @remark  λ�ö�λ����һ���������ź��б���ʾλ���໥ӳ��Ľӿڣ�ͨ��ʵ��λ�ö�λ�����û����Կ����б������ʾ��С
     */
    STDMETHOD_(void, SetItemLocator)(THIS_ ITileViewItemLocator * pItemLocator) PURE;

    /**
     * @brief ��ȡλ�ö�λ��
     * @return ITileViewItemLocator *
     */
    STDMETHOD_(ITileViewItemLocator *, GetItemLocator)(CTHIS) SCONST PURE;

    /**
     * @brief ʹָ���й�������ͼ�ɼ���
     * @param iItem --�к�
     * @return
     */
    STDMETHOD_(void, EnsureVisible)(THIS_ int iItem) PURE;

    /**
     * @brief ѡ��ָ����
     * @param iItem --�к�
     * @param bNotify --����ѡ��״̬�¼���־
     * @return
     */
    STDMETHOD_(void, SetSel)(THIS_ int iItem, BOOL bNotify DEF_VAL(FALSE)) PURE;

    /**
     * @brief ��ȡ��ǰѡ����
     * @return int ѡ����������-1����ǰû��ѡ����
     */
    STDMETHOD_(int, GetSel)(CTHIS) SCONST PURE;

    /**
     * @brief �ȵ����
     * @param pt -- ��������
     * @return IItemPanel *--�����µ�ItemPanel
     */
    STDMETHOD_(IItemPanel *, HitTest)(CTHIS_ const POINT *pt) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IListBox
DECLARE_INTERFACE_IID_(IListBox, IPanel, "4A36DC8A-7378-4a2d-A3AF-D04B0712ACCD")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ��ʾ/���ع�����
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) PURE;

    /**
     * @brief Enable/Disable������
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) PURE;

    /**
     * @brief ��ȡ������Enable״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-enable
     */
    STDMETHOD_(BOOL, IsScrollBarEnable)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù���������
     * @param si --����������
     * @param bVertical -- TRUE-��ֱ������
     * @return
     */
    STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) PURE;

    /**
     * @brief ���ù�����λ��
     * @param bVertical -- TRUE-��ֱ������
     * @param nNewPos -- ����λ��
     * @param bRedraw -- �ػ��־
     * @return
     */
    STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ������λ��
     * @param bVertical -- TRUE-��ֱ������
     * @return ������λ��
     */
    STDMETHOD_(int, GetScrollPos)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù�������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param nMinPos -- ��Сֵ
     * @param nMaxPos -- ���ֵ
     * @param bRedraw -- �ػ��־
     * @return TRUE-�ɹ�
     */
    STDMETHOD_(BOOL, SetScrollRange)
    (THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ��������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param lpMinPos -- ��Сֵ
     * @param lpMaxPos -- ���ֵ
     * @return
     */
    STDMETHOD_(BOOL, GetScrollRange)
    (CTHIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST PURE;

    /**
     * @brief ��ѯ����������״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-����
     */
    STDMETHOD_(BOOL, HasScrollBar)(CTHIS_ BOOL bVertical) SCONST PURE;
    //////////////////////////////////////////////////////////////////////////
    /**
     * SListBox::GetCount
     * @brief    ��ȡ�����
     * @return   ����int
     *
     * Describe  ��ȡ�����
     */
    STDMETHOD_(int, GetCount)(CTHIS) SCONST PURE;

    /**
     * SListBox::GetCurSel
     * @brief    ��ȡ��ǰѡ��������
     * @return   ����int
     *
     * Describe  ��ȡ��ǰѡ��������
     */
    STDMETHOD_(int, GetCurSel)(CTHIS) SCONST PURE;

    /**
     * SListBox::SetCurSel
     * @brief    ����ѡ����
     * @param    int nIndex -- ��ѡ������
     *
     * Describe  ����ѡ����
     */
    STDMETHOD_(BOOL, SetCurSel)(THIS_ int nIndex, BOOL bNotifyChange /* = FALSE*/) PURE;

    /**
     * SListBox::GetTopIndex
     * @brief    ��ȡ��һ���ɼ���¼����
     * @return   ����int
     *
     * Describe
     */
    STDMETHOD_(int, GetTopIndex)(CTHIS) SCONST PURE;

    /**
     * SListBox::SetTopIndex
     * @brief    ���õ�һ���ɼ���¼����
     * @param    int nIndex -- ��һ���ɼ���¼����
     *
     * Describe
     */
    STDMETHOD_(BOOL, SetTopIndex)(THIS_ int nIndex) PURE;

    /**
     * SListBox::GetItemHeight
     * @brief    ��ȡ�߶�
     * @return   ����int
     *
     * Describe  ��ȡ�߶�
     */
    STDMETHOD_(int, GetItemHeight)(CTHIS) SCONST PURE;

    /**
     * SListBox::SetItemHeight
     * @brief    ����ָ����߶�
     * @param    int cyItemHeight -- �߶�
     * @return   ����
     *
     * Describe  ����ָ����߶�
     */
    STDMETHOD_(void, SetItemHeight)(THIS_ int nItemHeight) PURE;

    /**
     * SListBox::GetItemData
     * @brief    ��ȡ��������
     * @param    int nIndex -- ѡ������
     * @return   ����LPARAM
     *
     * Describe  ��ȡ��������
     */
    STDMETHOD_(LPARAM, GetItemData)(CTHIS_ int nIndex) SCONST PURE;

    /**
     * SListBox::SetItemData
     * @brief    ����ѡ�������
     * @param    int nIndex -- ѡ������
     * @param    LPARAM lParam  -- ��������
     * @return   ����BOOL
     *
     * Describe  ����ѡ�������
     */
    STDMETHOD_(BOOL, SetItemData)(THIS_ int nIndex, LPARAM lParam) PURE;

    /**
     * SListBox::GetText
     * @brief    ��ȡָ�����ı�
     * @param    int nIndex -- ѡ������
     * @param    BOOL bRawText -- ԭʼ���ݱ�־
     * @return   SStringT,�б����ԭʼ�ַ���
     *
     * Describe  ��ȡָ�����ı�
     */
    STDMETHOD_(BOOL, GetIText)
    (CTHIS_ int nIndex, BOOL bRawText /*= FALSE*/, IStringT *str) SCONST PURE;

    /**
     * SListBox::DeleteAll
     * @brief    ɾ������
     *
     * Describe  ɾ������
     */
    STDMETHOD_(void, DeleteAll)(THIS) PURE;

    /**
     * SListBox::DeleteString
     * @brief    ����ָ�����ı�
     * @param    int nIndex -- ѡ������
     * @return   ����BOOL
     *
     * Describe  ����ָ�����ı�
     */
    STDMETHOD_(BOOL, DeleteString)(THIS_ int nIndex) PURE;

    /**
     * SListBox::AddString
     * @brief    ����ı�
     * @param    LPCTSTR lpszItem -- �ı�
     * @param    int nImage -- ͼ��
     * @param    LPARAM lParam -- ��������
     * @return   ����int ����
     *
     * Describe  ����ı�
     */
    STDMETHOD_(int, AddString)
    (THIS_ LPCTSTR lpszItem, int nImage /*= -1*/, LPARAM lParam /*= 0*/) PURE;

    /**
     * SListBox::InsertString
     * @brief    �����ı�
     * @param    int nIndex  -- ����
     * @param    LPCTSTR lpszItem -- �ı�
     * @param    int nImage -- ͼ��
     * @param    LPARAM lParam -- ��������
     * @return   ����int ����
     *
     * Describe  ��ĳ������ı�
     */
    STDMETHOD_(int, InsertString)
    (THIS_ int nIndex, LPCTSTR lpszItem, int nImage /*= -1*/, LPARAM lParam /*= 0*/) PURE;

    /**
     * SListBox::EnsureVisible
     * @brief    ����ĳ����ʾ
     * @param    int nIndex  -- ����
     *
     * Describe  ����ĳ����ʾ
     */
    STDMETHOD_(void, EnsureVisible)(THIS_ int nIndex) PURE;

    /**
     * @brief �����ַ������б��е�λ��
     * @param iFindAfter --��ʼ����
     * @param pszText --Ŀ���ַ���
     * @return int �ҵ���������-1����û���ҵ�
     */
    STDMETHOD_(int, FindString)(CTHIS_ int iFindAfter, LPCTSTR pszText) SCONST PURE;

	STDMETHOD_(BOOL, SetItemImage)(THIS_ int nIndex,int iImage) PURE;

	STDMETHOD_(int, GetItemImage)(THIS_ int nIndex) PURE;
};

#undef INTERFACE
#define INTERFACE IComboBase
DECLARE_INTERFACE_IID_(IComboBase, ICtrl, "2BF10693-BEBD-4497-B6B5-5380BA8401EC")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////
    /**
     * SComboBoxBase::GetCurSel
     * @brief    ��ȡѡ��ֵ����
     * @return   ����int
     *
     * Describe  ��ȡ��ǰѡ������
     */
    STDMETHOD_(int, GetCurSel)(CTHIS) SCONST PURE;

    /**
     * SComboBoxBase::GetCount
     * @brief    ��ȡ���������
     * @return   ����int
     *
     * Describe  ��ȡ���������
     */
    STDMETHOD_(int, GetCount)(CTHIS) SCONST PURE;

    /**
     * SComboBoxBase::SetCurSel
     * @brief    ���õ�ǰѡ��
     * @param    int iSel -- ѡ������
     *
     * Describe  ���õ�ǰѡ��
     */
    STDMETHOD_(BOOL, SetCurSel)(THIS_ int iSel) PURE;

    /**
     * @brief ��ȡָ�����ı�����
     * @param iItem --������
     * @param bRawText --��ȡԭʼ�ı���־
     * @param[out] str ����ַ�������
     * @return BOOL TRUE-�ɹ�
     * @remark bRawTextΪTRUEʱ���δ������ı�
     */
    STDMETHOD_(BOOL, GetItemText)(CTHIS_ int iItem, BOOL bRawText, IStringT *str) SCONST PURE;
	STDMETHOD_(BOOL, GetItemTextA)(CTHIS_ int iItem, BOOL bRawText, IStringA *str) SCONST PURE;

    /**
     * FindString
     * @brief    �����ַ���λ��
     * @param    LPCTSTR pszFind --  ����Ŀ��
     * @param    int nAfter --  ��ʼλ��
     * @return   int -- Ŀ��������ʧ�ܷ���-1��
     * Describe
     */
    STDMETHOD_(int, FindString)
    (THIS_ LPCTSTR pszFind, int nAfter /* = -1*/, BOOL bPartMatch /* = TRUE*/) PURE;
	STDMETHOD_(int, FindStringA)
		(THIS_ LPCSTR pszFind, int nAfter /* = -1*/, BOOL bPartMatch /* = TRUE*/) PURE;

	//////////////////////////////////////////////////////////////////////////
    /**
     * SComboBoxBase::DropDown
     * @brief    �����¼�
     *
     * Describe  �����¼�
     */
    STDMETHOD_(void, DropDown)(THIS) PURE;

    /**
     * SComboBoxBase::CloseUp
     * @brief    �����ر�
     *
     * Describe  �����ر�
     */
    STDMETHOD_(void, CloseUp)(THIS) PURE;

    /**
     * @brief ��ѯDropDown״̬��־
     * @return TRUE-��ǰComboBaseΪ�����б�
     * @remark �ڲ�ʹ�÷���
     */
    STDMETHOD_(BOOL, IsDropdown)(CTHIS) SCONST PURE;

    /**
     * @brief ��������״̬��־
     * @param bDropdown -- TRUE:�����б�
     * @return
     * @remark �ڲ�ʹ�÷���
     */
    STDMETHOD_(void, SetDropdown)(THIS_ BOOL bDropdown) PURE;
};

#undef INTERFACE
#define INTERFACE IComboBox
DECLARE_INTERFACE_IID_(IComboBox, IComboBase, "AC6C72BB-51BE-4216-ADA5-B394283DC9CF")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////
    /**
     * SComboBoxBase::GetCurSel
     * @brief    ��ȡѡ��ֵ����
     * @return   ����int
     *
     * Describe  ��ȡ��ǰѡ������
     */
    STDMETHOD_(int, GetCurSel)(CTHIS) SCONST PURE;

    /**
     * SComboBoxBase::GetCount
     * @brief    ��ȡ���������
     * @return   ����int
     *
     * Describe  ��ȡ���������
     */
    STDMETHOD_(int, GetCount)(CTHIS) SCONST PURE;

    /**
     * SComboBoxBase::SetCurSel
     * @brief    ���õ�ǰѡ��
     * @param    int iSel -- ѡ������
     *
     * Describe  ���õ�ǰѡ��
     */
    STDMETHOD_(BOOL, SetCurSel)(THIS_ int iSel) PURE;

    /**
     * @brief ��ȡָ�����ı�����
     * @param iItem --������
     * @param bRawText --��ȡԭʼ�ı���־
     * @param[out] str ����ַ�������
     * @return BOOL TRUE-�ɹ�
     * @remark bRawTextΪTRUEʱ���δ������ı�
     */
    STDMETHOD_(BOOL, GetItemText)(CTHIS_ int iItem, BOOL bRawText, IStringT *str) SCONST PURE;

	STDMETHOD_(BOOL, GetItemTextA)(CTHIS_ int iItem, BOOL bRawText, IStringA *str) SCONST PURE;

    /**
     * FindString
     * @brief    �����ַ���λ��
     * @param    LPCTSTR pszFind --  ����Ŀ��
     * @param    int nAfter --  ��ʼλ��
     * @return   int -- Ŀ��������ʧ�ܷ���-1��
     * Describe
     */
    STDMETHOD_(int, FindString)
    (THIS_ LPCTSTR pszFind, int nAfter /* = -1*/, BOOL bPartMatch /* = TRUE*/) PURE;
	STDMETHOD_(int, FindStringA)
		(THIS_ LPCSTR pszFind, int nAfter /* = -1*/, BOOL bPartMatch /* = TRUE*/) PURE;

    /**
     * SComboBoxBase::DropDown
     * @brief    �����¼�
     *
     * Describe  �����¼�
     */
    STDMETHOD_(void, DropDown)(THIS) PURE;

    /**
     * SComboBoxBase::CloseUp
     * @brief    �����ر�
     *
     * Describe  �����ر�
     */
    STDMETHOD_(void, CloseUp)(THIS) PURE;

    /**
     * @brief ��ѯDropDown״̬��־
     * @return TRUE-��ǰComboBaseΪ�����б�
     * @remark �ڲ�ʹ�÷���
     */
    STDMETHOD_(BOOL, IsDropdown)(CTHIS) SCONST PURE;

    /**
     * @brief ��������״̬��־
     * @param bDropdown -- TRUE:�����б�
     * @return
     * @remark �ڲ�ʹ�÷���
     */
    STDMETHOD_(void, SetDropdown)(THIS_ BOOL bDropdown) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * SComboBox::GetItemData
     * @brief    ��ȡ��������
     * @param    UINT iItem -- ѡ��ֵ
     *
     * Describe  ��ȡ��������
     */
    STDMETHOD_(LPARAM, GetItemData)(CTHIS_ UINT iItem) SCONST PURE;

    /**
     * SComboBox::SetItemData
     * @brief    ���ø�������
     * @param    UINT iItem -- ����ֵ
     * @param    LPARAM lParam -- ����ֵ
     *
     * Describe  ���ø�������
     */
    STDMETHOD_(BOOL, SetItemData)(THIS_ UINT iItem, LPARAM lParam) PURE;

    /**
     * SComboBox::InsertItem
     * @brief    ��������
     * @param    UINT iPos -- λ��
     * @param    LPCTSTR pszText -- �ı�ֵ
     * @param    int iIcon -- ͼ��
     * @param    LPARAM lParam -- ����ֵ
     *
     * Describe  ��������
     */
    STDMETHOD_(int, InsertItem)(THIS_ int iPos, LPCTSTR pszText, int iIcon, LPARAM lParam) PURE;
	STDMETHOD_(int, InsertItemA)(THIS_ int iPos, LPCSTR pszText, int iIcon, LPARAM lParam) PURE;
    /**
     * SComboBox::DeleteString
     * @brief    ɾ��ĳһ��
     * @param    UINT iItem -- ����ֵ
     *
     * Describe  ɾ��ĳһ��
     */
    STDMETHOD_(BOOL, DeleteString)(THIS_ int iPos) PURE;
    /**
     * SComboBox::ResetContent
     * @brief    ɾ��������
     *
     * Describe  ���ø�������
     */
    STDMETHOD_(void, ResetContent)(THIS) PURE;

    /**
     * @brief ��ȡIListBox�ӿ�
     * @return IListBox *
     */
    STDMETHOD_(IListBox *, GetIListBox)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IComboView
DECLARE_INTERFACE_IID_(IComboView, IComboBase, "EADE040E-0D6A-47a3-882F-F70A94FC253D")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////
    /**
     * SComboBoxBase::GetCurSel
     * @brief    ��ȡѡ��ֵ����
     * @return   ����int
     *
     * Describe  ��ȡ��ǰѡ������
     */
    STDMETHOD_(int, GetCurSel)(CTHIS) SCONST PURE;

    /**
     * SComboBoxBase::GetCount
     * @brief    ��ȡ���������
     * @return   ����int
     *
     * Describe  ��ȡ���������
     */
    STDMETHOD_(int, GetCount)(CTHIS) SCONST PURE;

    /**
     * SComboBoxBase::SetCurSel
     * @brief    ���õ�ǰѡ��
     * @param    int iSel -- ѡ������
     *
     * Describe  ���õ�ǰѡ��
     */
    STDMETHOD_(BOOL, SetCurSel)(THIS_ int iSel) PURE;

    /**
     * @brief ��ȡָ�����ı�����
     * @param iItem --������
     * @param bRawText --��ȡԭʼ�ı���־
     * @param[out] str ����ַ�������
     * @return BOOL TRUE-�ɹ�
     * @remark bRawTextΪTRUEʱ���δ������ı�
     */
    STDMETHOD_(BOOL, GetItemText)(CTHIS_ int iItem, BOOL bRawText, IStringT *str) SCONST PURE;

    /**
     * FindString
     * @brief    �����ַ���λ��
     * @param    LPCTSTR pszFind --  ����Ŀ��
     * @param    int nAfter --  ��ʼλ��
     * @return   int -- Ŀ��������ʧ�ܷ���-1��
     * Describe
     */
    STDMETHOD_(int, FindString)
    (THIS_ LPCTSTR pszFind, int nAfter /* = -1*/, BOOL bPartMatch /* = TRUE*/) PURE;

    /**
     * SComboBoxBase::DropDown
     * @brief    �����¼�
     *
     * Describe  �����¼�
     */
    STDMETHOD_(void, DropDown)(THIS) PURE;

    /**
     * SComboBoxBase::CloseUp
     * @brief    �����ر�
     *
     * Describe  �����ر�
     */
    STDMETHOD_(void, CloseUp)(THIS) PURE;

    /**
     * @brief ��ѯDropDown״̬��־
     * @return TRUE-��ǰComboBaseΪ�����б�
     * @remark �ڲ�ʹ�÷���
     */
    STDMETHOD_(BOOL, IsDropdown)(CTHIS) SCONST PURE;

    /**
     * @brief ��������״̬��־
     * @param bDropdown -- TRUE:�����б�
     * @return
     * @remark �ڲ�ʹ�÷���
     */
    STDMETHOD_(void, SetDropdown)(THIS_ BOOL bDropdown) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ��ȡListView�ӿ�
     * @return IListView *
     */
    STDMETHOD_(IListView *, GetIListView)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE IDateTimePicker
DECLARE_INTERFACE_IID_(IDateTimePicker, ICtrl, "6DB1EF42-AED7-4a36-8011-BE2AD7B45953")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ����ʱ��
     * @param wYear --��
     * @param wMonth --��
     * @param wDay --��
     * @param wHour --ʱ
     * @param wMinute --��
     * @param wSecond --��
     * @return
     */
    STDMETHOD_(void, SetTime)
    (THIS_ WORD wYear, WORD wMonth, WORD wDay, WORD wHour, WORD wMinute, WORD wSecond) PURE;

    /**
     * @brief ��ȡ��ǰʱ��
     * @param[out] wYear --��
     * @param[out] wMonth --��
     * @param[out] wDay --��
     * @param[out] wHour --ʱ
     * @param[out] wMinute --��
     * @param[out] wSecond --��
     * @return
     */
    STDMETHOD_(void, GetTime)
    (CTHIS_ WORD * wYear, WORD * wMonth, WORD * wDay, WORD * wHour, WORD * wMinute, WORD * wSecond) SCONST PURE;

    /**
     * @brief �ر������б�
     * @return
     */
    STDMETHOD_(void, CloseUp)(THIS) PURE;

    /**
     * @brief ��ʾ�����б�
     * @return
     */
    STDMETHOD_(void, DropDown)(THIS) PURE;

    /**
     * @brief �������
     * @return
     */
    STDMETHOD_(void, Clear)(THIS) PURE;
};

typedef int(__cdecl *FunTreeSortCallback)(void *pCtx, const void *phItem1, const void *phItem2);

#define STVI_ROOT  ((HSTREEITEM)0xFFFF0000) //=TVI_ROOT
#define STVI_FIRST ((HSTREEITEM)0xFFFF0001) //=TVI_FIRST
#define STVI_LAST  ((HSTREEITEM)0xFFFF0002) //=TVI_LAST

#undef INTERFACE
#define INTERFACE ITreeCtrl
DECLARE_INTERFACE_IID_(ITreeCtrl, IPanel, "8FACB4B5-DD66-4755-AFD0-7DA8BB15611A")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ��ʾ/���ع�����
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) PURE;

    /**
     * @brief Enable/Disable������
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) PURE;

    /**
     * @brief ��ȡ������Enable״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-enable
     */
    STDMETHOD_(BOOL, IsScrollBarEnable)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù���������
     * @param si --����������
     * @param bVertical -- TRUE-��ֱ������
     * @return
     */
    STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) PURE;

    /**
     * @brief ���ù�����λ��
     * @param bVertical -- TRUE-��ֱ������
     * @param nNewPos -- ����λ��
     * @param bRedraw -- �ػ��־
     * @return
     */
    STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ������λ��
     * @param bVertical -- TRUE-��ֱ������
     * @return ������λ��
     */
    STDMETHOD_(int, GetScrollPos)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù�������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param nMinPos -- ��Сֵ
     * @param nMaxPos -- ���ֵ
     * @param bRedraw -- �ػ��־
     * @return TRUE-�ɹ�
     */
    STDMETHOD_(BOOL, SetScrollRange)
    (THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ��������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param lpMinPos -- ��Сֵ
     * @param lpMaxPos -- ���ֵ
     * @return
     */
    STDMETHOD_(BOOL, GetScrollRange)
    (CTHIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST PURE;

    /**
     * @brief ��ѯ����������״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-����
     */
    STDMETHOD_(BOOL, HasScrollBar)(CTHIS_ BOOL bVertical) SCONST PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ����һ��HSTREEITEM
     * @param lpszItem --��ʾ�ı�
     * @param nImage --ͼƬ����
     * @param nSelectedImage --ѡ��״̬��ͼƬ����
     * @param lParam --�Զ�������
     * @param hParent --��HSTREEITEM
     * @param hInsertAfter --ǰ����ֵ�HSTREEITEM
     * @return HSTREEITEM--�²���HSTREEITEM
     */
    STDMETHOD_(HSTREEITEM, InsertItem)
    (THIS_ LPCTSTR lpszItem, int nImage, int nSelectedImage, LPARAM lParam, HSTREEITEM hParent DEF_VAL(STVI_ROOT), HSTREEITEM hInsertAfter DEF_VAL(STVI_LAST)) PURE;

	STDMETHOD_(HSTREEITEM, InsertItemA)
		(THIS_ LPCSTR lpszItem, int nImage, int nSelectedImage, LPARAM lParam, HSTREEITEM hParent DEF_VAL(STVI_ROOT), HSTREEITEM hInsertAfter DEF_VAL(STVI_LAST)) PURE;

    /**
     * @brief ɾ��һ��HSTREEITEM
     * @param hItem --��ɾ��HSTREEITEM
     * @return BOOL
     */
    STDMETHOD_(BOOL, RemoveItem)(THIS_ HSTREEITEM hItem) PURE;

    /**
     * @brief ɾ����������
     * @return
     */
    STDMETHOD_(void, RemoveAllItems)(THIS) PURE;

    /**
     * @brief ��ȡ���ڵ�
     * @return HSTREEITEM --���ڵ�
     */
    STDMETHOD_(HSTREEITEM, GetRootItem)(CTHIS) SCONST PURE;

    /**
     * @brief ��ȡָ���ڵ����һ���ֵܽ��
     * @param hItem --ָ���ڵ�
     * @return HSTREEITEM--��һ���ֵܽ��
     */
    STDMETHOD_(HSTREEITEM, GetNextSiblingItem)(CTHIS_ HSTREEITEM hItem) SCONST PURE;

    /**
     * @brief ��ȡָ���ڵ����һ���ֵܽ��
     * @param hItem --ָ���ڵ�
     * @return HSTREEITEM--��һ���ֵܽ��
     */
    STDMETHOD_(HSTREEITEM, GetPrevSiblingItem)(CTHIS_ HSTREEITEM hItem) SCONST PURE;

    /**
     * @brief ��ȡָ�������ӽڵ�
     * @param hItem --ָ�����
     * @param bFirst -- TRUE����ȡ��һ���ӽڵ㣬FALSE:��ȡ���һ���ӽڵ�
     * @return HSTREEITEM--�ӽڵ�
     */
    STDMETHOD_(HSTREEITEM, GetChildItem)
    (CTHIS_ HSTREEITEM hItem, BOOL bFirst DEF_VAL(TRUE)) SCONST PURE;

    /**
     * @brief ��ȡָ�����ĸ��ڵ�
     * @param hItem --ָ�����
     * @return HSTREEITEM--���ڵ�
     */
    STDMETHOD_(HSTREEITEM, GetParentItem)(CTHIS_ HSTREEITEM hItem) SCONST PURE;

    /**
     * @brief ��ȡѡ�н��
     * @return HSTREEITEM--ѡ�н��
     */
    STDMETHOD_(HSTREEITEM, GetSelectedItem)(CTHIS) SCONST PURE;

    /**
     * @brief ��ȡ��һ�����
     * @param hItem -- ��ǰ���
     * @return HSTREEITEM--��һ�����
     * @remark ���ӽڵ�ʱ�ǵ�һ���ӽڵ㣬����Ϊ��һ���ֵܽ�㣬Ҳû���ֵ����Ǹ��ڵ����һ���ֵ�
     */
    STDMETHOD_(HSTREEITEM, GetNextItem)(CTHIS_ HSTREEITEM hItem) SCONST PURE;

    /**
     * @brief �����ӽڵ�
     * @param hItem --��ǰ�ڵ�
     * @param sortFunc --����ص�����
     * @param pCtx --�ص�������Context
     * @return
     */
    STDMETHOD_(void, SortChildren)
    (THIS_ HSTREEITEM hItem, FunTreeSortCallback sortFunc, void *pCtx) PURE;

    /**
     * @brief ѡ��ָ����
     * @param hItem --ָ����
     * @param bEnsureVisible --�Զ��������ɼ�����־
     * @return
     */
    STDMETHOD_(BOOL, SelectItem)(THIS_ HSTREEITEM hItem, BOOL bEnsureVisible DEF_VAL(TRUE)) PURE;

    /**
     * @brief ��ȡָ������ı�����
     * @param hItem --ָ����
     * @param[out] strText --�ı�����
     * @return BOOL
     * @remark ��֧�ַ���
     */
    STDMETHOD_(BOOL, GetItemText)(CTHIS_ HSTREEITEM hItem, IStringT * strText) SCONST PURE;
    STDMETHOD_(BOOL, GetItemTextA)(CTHIS_ HSTREEITEM hItem, IStringA* strText) SCONST PURE;

    /**
     * @brief �����ı�����
     * @param hItem --ָ����
     * @param lpszItem  --�ı�����
     * @return BOOL
     */
    STDMETHOD_(BOOL, SetItemText)(THIS_ HSTREEITEM hItem, LPCTSTR lpszItem) PURE;
    STDMETHOD_(BOOL, SetItemTextA)(THIS_ HSTREEITEM hItem, LPCSTR lpszItem) PURE;

    /**
     * @brief ��ȡָ�����ͼ����ʾ����
     * @param hItem --ָ����
     * @param nImage --ͼƬ����
     * @param nSelectedImage --ѡ��״̬ͼƬ����
     * @return BOOL
     */
    STDMETHOD_(BOOL, GetItemImage)
    (CTHIS_ HSTREEITEM hItem, int *nImage, int *nSelectedImage) SCONST PURE;

    /**
     * @brief ����ָ�����ͼƬ����
     * @param hItem --ָ����
     * @param nImage --ͼƬ����
     * @param nSelectedImage --ѡ��״̬ͼƬ����
     * @return BOOL
     */
    STDMETHOD_(BOOL, SetItemImage)(THIS_ HSTREEITEM hItem, int nImage, int nSelectedImage) PURE;

    /**
     * @brief ��ȡָ������Զ�������
     * @param hItem --ָ����
     * @return LPARAM--�Զ�������
     */
    STDMETHOD_(LPARAM, GetItemData)(CTHIS_ HSTREEITEM hItem) SCONST PURE;

    /**
     * @brief ����ָ������Զ�������
     * @param hItem --ָ����
     * @param lParam --�Զ�������
     * @return BOOL
     */
    STDMETHOD_(BOOL, SetItemData)(THIS_ HSTREEITEM hItem, LPARAM lParam) PURE;

    /**
     * @brief ��ѯָ�����Ƿ�������
     * @param hItem --ָ����
     * @return BOOL TRUE:������
     */
    STDMETHOD_(BOOL, ItemHasChildren)(CTHIS_ HSTREEITEM hItem) SCONST PURE;

    /**
     * @brief ��ȡָ�����Check״̬
     * @param hItem --ָ����
     * @return int 0--unchecked,1--checked,2--part checked
     */
    STDMETHOD_(int, GetCheckState)(CTHIS_ HSTREEITEM hItem) SCONST PURE;

    /**
     * @brief ����ָ�����Check״̬
     * @param hItem --ָ����
     * @param bCheck --TRUE:checked
     * @return
     */
    STDMETHOD_(BOOL, SetCheckState)(THIS_ HSTREEITEM hItem, BOOL bCheck) PURE;

    /**
     * @brief չ����������ָ���������
     * @param hItem --ָ����
     * @param nCode --��־λ
     * @return
     */
    STDMETHOD_(BOOL, Expand)(THIS_ HSTREEITEM hItem, UINT nCode DEF_VAL(TVE_EXPAND)) PURE;

    /**
     * @brief ʹָ����������ɼ���
     * @param hItem  --ָ����
     * @return
     */
    STDMETHOD_(BOOL, EnsureVisible)(THIS_ HSTREEITEM hItem) PURE;
};

#undef INTERFACE
#define INTERFACE IHotKeyCtrl
DECLARE_INTERFACE_IID_(IHotKeyCtrl, ICtrl, "8839DDF0-84CE-4bca-8BE4-FF55928E3A55")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * SHotKeyCtrl::SetRule
     * @brief    ���ù���
     * @param    WORD wInvalidComp --
     * @param    WORD wModifier  --
     *
     * Describe  ���ù���
     */
    STDMETHOD_(void, SetRule)(THIS_ WORD wInvalidComp, WORD wModifier) PURE;

    /**
     * SHotKeyCtrl::SetHotKey
     * @brief    �����ȼ�
     * @param    WORD vKey --
     * @param    WORD wModifiers  --
     *
     * Describe  �����ȼ�
     */
    STDMETHOD_(void, SetHotKey)(THIS_ WORD wKey, WORD wModifiers) PURE;

    /**
     * SHotKeyCtrl::GetHotKey
     * @brief    ��ȡ�ȼ�
     * @param    WORD &vKey --
     * @param    WORD wModifiers  --
     *
     * Describe  ��ȡ�ȼ�
     */
    STDMETHOD_(void, GetHotKey)(CTHIS_ WORD * wKey, WORD * wModifers) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IRichEdit
DECLARE_INTERFACE_IID_(IRichEdit, IPanel, "6B72BCCE-9D42-4fb8-9CF4-F8F9605ACA9A")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ��ʾ/���ع�����
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, ShowScrollBar)(THIS_ int wBar, BOOL bShow) PURE;

    /**
     * @brief Enable/Disable������
     * @param wBar ��������־,see ScrollBarID
     * @param bShow TRUE-��ʾ��FALSE-����
     * @return
     */
    STDMETHOD_(BOOL, EnableScrollBar)(THIS_ int wBar, BOOL bEnable) PURE;

    /**
     * @brief ��ȡ������Enable״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-enable
     */
    STDMETHOD_(BOOL, IsScrollBarEnable)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù���������
     * @param si --����������
     * @param bVertical -- TRUE-��ֱ������
     * @return
     */
    STDMETHOD_(void, SetScrollInfo)(THIS_ SCROLLINFO si, BOOL bVertical) PURE;

    /**
     * @brief ���ù�����λ��
     * @param bVertical -- TRUE-��ֱ������
     * @param nNewPos -- ����λ��
     * @param bRedraw -- �ػ��־
     * @return
     */
    STDMETHOD_(BOOL, SetScrollPos)(THIS_ BOOL bVertical, int nNewPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ������λ��
     * @param bVertical -- TRUE-��ֱ������
     * @return ������λ��
     */
    STDMETHOD_(int, GetScrollPos)(CTHIS_ BOOL bVertical) SCONST PURE;

    /**
     * @brief ���ù�������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param nMinPos -- ��Сֵ
     * @param nMaxPos -- ���ֵ
     * @param bRedraw -- �ػ��־
     * @return TRUE-�ɹ�
     */
    STDMETHOD_(BOOL, SetScrollRange)
    (THIS_ BOOL bVertical, int nMinPos, int nMaxPos, BOOL bRedraw) PURE;

    /**
     * @brief ��ȡ��������Χ
     * @param bVertical -- TRUE-��ֱ������
     * @param lpMinPos -- ��Сֵ
     * @param lpMaxPos -- ���ֵ
     * @return
     */
    STDMETHOD_(BOOL, GetScrollRange)
    (CTHIS_ BOOL bVertical, LPINT lpMinPos, LPINT lpMaxPos) SCONST PURE;

    /**
     * @brief ��ѯ����������״̬
     * @param bVertical -- TRUE-��ֱ������
     * @return TRUE-����
     */
    STDMETHOD_(BOOL, HasScrollBar)(CTHIS_ BOOL bVertical) SCONST PURE;
	//////////////////////////////////////////////////////////////////////////

    /**
     * IRichEdit::SaveRtf
     * @brief     �������ݵ�RTF�ļ�
     * @param LPCTSTR pszFileName -- �ļ���
     * @return    DWORD ���ݳ���
     *
     * Describe
     */
    STDMETHOD_(DWORD, SaveRtf)(THIS_ LPCTSTR pszFileName) PURE;

    /**
     * IRichEdit::LoadRtf
     * @brief     ��RTF�ļ���������
     * @param LPCTSTR pszFileName -- �ļ���
     * @return    DWORD ���ݳ���
     *
     * Describe
     */
    STDMETHOD_(DWORD, LoadRtf)(THIS_ LPCTSTR pszFileName) PURE;

    /**
     * IRichEdit::SetSel
     * @brief     ����ѡ��
     * @param     long nStartChar -- ��ʼ�ַ�����
     * @param     long nEndChar -- �����ַ�����
     * @param     BOOL bNoScroll -- ��ֹ������־
     *
     * Describe   ����ѡ��, ֧�ֳ����ı�
     */
    STDMETHOD_(void, SetSel)(THIS_ long nStartChar, long nEndChar, BOOL bNoScroll) PURE;
    /**
     * IRichEdit::ReplaceSel
     * @brief     �滻ѡ����
     * @param     LPCWSTR pszText -- �滻����
     * @param     BOOL bCanUndo -- ����Undo��־
     *
     * Describe   �滻ѡ����
     */
    STDMETHOD_(void, ReplaceSel)(THIS_ LPCTSTR pszText, BOOL bCanUndo DEF_VAL(TRUE)) PURE;
    /**
     * IRichEdit::GetWordWrap
     * @brief
     * @return   ����BOOL
     *
     * Describe
     */
    STDMETHOD_(BOOL, GetWordWrap)(CTHIS) SCONST PURE;
    /**
     * IRichEdit::SetWordWrap
     * @brief
     * @param     BOOL fWordWrap -- word wrap��־
     *
     * Describe
     */
    STDMETHOD_(void, SetWordWrap)(THIS_ BOOL fWordWrap) PURE;

    /**
     * IRichEdit::GetReadOnly
     * @brief    �ж��Ƿ�ֻ��
     * @return   ����BOOL
     *
     * Describe  �ж��Ƿ�ֻ��
     */
    STDMETHOD_(BOOL, GetReadOnly)(CTHIS) SCONST PURE;

    /**
     * IRichEdit::SetReadOnly
     * @brief     ����ֻ��
     * @param     BOOL bReadOnly -- �Ƿ�ֻ��
     * @return    ����BOOL
     *
     * Describe   ����ֻ��
     */
    STDMETHOD_(BOOL, SetReadOnly)(THIS_ BOOL bReadOnly) PURE;

    /**
     * IRichEdit::GetLimitText
     * @brief     ��ȡ��С�ı�����
     * @return    ����BOOL
     *
     * Describe   ��ȡ��С�ı�����
     */
    STDMETHOD_(LONG, GetLimitText)(CTHIS) SCONST PURE;

    /**
     * IRichEdit::SetLimitText
     * @brief     ������С�ı�����
     * @param     int nLength -- ����
     * @return    ����BOOL
     *
     * Describe   ������С�ı�����
     */
    STDMETHOD_(BOOL, SetLimitText)(THIS_ int nLength) PURE;

    /**
     * IRichEdit::GetDefaultAlign
     * @brief     ��ȡ���뷽ʽ
     * @return    ����WORD
     *
     * Describe   ������С�ı�����
     */
    STDMETHOD_(WORD, GetDefaultAlign)(CTHIS) SCONST PURE;

    /**
     * IRichEdit::SetDefaultAlign
     * @brief     ����Ĭ�϶��뷽ʽ
     * @param     WORD wNewAlign -- ���뷽ʽ
     *
     * Describe   ����Ĭ�϶��뷽ʽ
     */
    STDMETHOD_(void, SetDefaultAlign)(THIS_ WORD wNewAlign) PURE;

    /**
     * IRichEdit::GetRichTextFlag
     * @brief     ��ȡ��־
     * @return    ����BOOL
     *
     * Describe   ��ȡ��־
     */
    STDMETHOD_(BOOL, GetRichTextFlag)(CTHIS) SCONST PURE;

    /**
     * IRichEdit::SetRichTextFlag
     * @brief     ���ñ�־
     * @param     BOOL fRich -- ��־
     *
     * Describe   ���ñ�־
     */
    STDMETHOD_(void, SetRichTextFlag)(THIS_ BOOL fRich) PURE;

    /**
     * IRichEdit::SetRichTextFlag
     * @brief     ���ñ�־
     * @param     BOOL fRich -- ��־
     * @return    ����LONG
     *
     * Describe   ���ñ�־
     */
    STDMETHOD_(LONG, GetDefaultLeftIndent)(CTHIS) SCONST PURE;

    /**
     * IRichEdit::SetDefaultLeftIndent
     * @brief     ��������
     * @param     LONG lNewIndent -- �����ַ���
     *
     * Describe   ��������
     */
    STDMETHOD_(void, SetDefaultLeftIndent)(THIS_ LONG lNewIndent) PURE;

    /**
     * IRichEdit::SetSaveSelection
     * @brief
     * @param     BOOL fSaveSelection
     * @return    ����BOOL
     *
     * Describe
     */
    STDMETHOD_(BOOL, SetSaveSelection)(THIS_ BOOL fSaveSelection) PURE;

    /**
     * IRichEdit::SetDefaultTextColor
     * @brief     Ĭ���ı���ɫ
     * @param     COLORREF cr -- ��ɫ
     * @return    ����COLORREF
     *
     * Describe   ����Ĭ���ı���ɫ
     */
    STDMETHOD_(COLORREF, SetDefaultTextColor)(THIS_ COLORREF cr) PURE;
};

#undef INTERFACE
#define INTERFACE ITabPage
DECLARE_INTERFACE_IID_(ITabPage, ICtrl, "7E1C8BBF-1F87-4174-A30C-6CE3E4A47A13")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

	/**
     * GetTitle
     * @brief    ��ȡ����
     * @return   LPCTSTR --- ����
     *
     * Describe  ��ȡ����
     */
    STDMETHOD_(LPCTSTR,GetTitle)(CTHIS) SCONST PURE;

    /**
     * SetTitle
     * @brief    ���ñ���
     * @param    LPCTSTR lpszTitle --- ����
     *
     * Describe  ���ñ���
     */
    STDMETHOD_(void,SetTitle)(THIS_ LPCTSTR lpszTitle) PURE;

    /**
     * GetIconIndex
     * @brief    ��ȡͼ������
     * @return   int, ͼ������
     */
    STDMETHOD_(int,GetIconIndex)(CTHIS) SCONST PURE;

    /**
     * SetIconIndex
     * @brief    ����ͼ������
	 * @param    int iIcon -- ͼ������
     * @return   void
     */
    STDMETHOD_(void,SetIconIndex)(THIS_ int iIcon) PURE;
};

#undef INTERFACE
#define INTERFACE ITabCtrl
DECLARE_INTERFACE_IID_(ITabCtrl, ICtrl, "CAD40CB4-A0E5-4bea-9CE6-8DFC45DEFFD4")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * ITabCtrl::GetCurSel
     * @brief    ��ȡ��ǰѡ��
     * @return   ����int
     *
     * Describe  ��ȡ��ǰѡ��
     */
    STDMETHOD_(int, GetCurSel)(CTHIS) SCONST PURE;

    /**
     * ITabCtrl::SetCurSel
     * @brief    ���õ�ǰѡ��
     * @param    int nIndex -- ����
     * @return   ����BOOL
     *
     * Describe  ��ȡ��ǰѡ��
     */
    STDMETHOD_(BOOL, SetCurSel)(THIS_ int nIndex) PURE;

    /**
     * ITabCtrl::SetItemTitle
     * @brief    ���ñ���
     * @param    int nIndex  -- ����
     * @param    LPCTSTR lpszTitle  -- ����
     * @return   ����BOOL
     *
     * Describe  ��ȡ��ǰѡ��
     */
    STDMETHOD_(BOOL, SetItemTitle)(THIS_ int nIndex, LPCTSTR lpszTitle) PURE;

    /**
     * ITabCtrl::InsertItem
     * @brief    ����tabҳ��
     * @param    LPCWSTR lpContent  -- XML������page��Ϣ
     * @param    int iInsert  -- λ��
     * @return   ���ز���λ��
     *
     * Describe  ����tabҳ��
     */
    STDMETHOD_(int, InsertItem)(THIS_ LPCWSTR lpContent, int iInsert /* = -1*/) PURE;

    /**
     * ITabCtrl::GetItemCount
     * @brief    ��ȡtabҳ����
     * @return   ����int
     *
     * Describe  ��ȡtabҳ����
     */
    STDMETHOD_(int, GetItemCount)(CTHIS) SCONST PURE;

    /**
     * ITabCtrl::GetItem
     * @brief    ��ȡָ��tabҳ��
     * @param    int nIndex -- ����
     * @return   ����int
     *
     * Describe  ��ȡ��ǰѡ��
     */
    STDMETHOD_(ITabPage *, GetPage)(THIS_ int nIndex) PURE;

    /**
     * ITabCtrl::RemoveItem
     * @brief    ɾ��ָ��tabҳ��
     * @param    int nIndex -- ����
     * @param    int nSelPage -- ѡ��ҳ��
     * @return   ɾ��ָ��tabҳ��
     *
     * Describe  ��ȡ��ǰѡ��
     */
    STDMETHOD_(BOOL, RemoveItem)(THIS_ int nIndex, int iSelPage /*= 0*/) PURE;

    /**
     * ITabCtrl::RemoveAllItems
     * @brief    ɾ������ҳ��
     *
     * Describe  ɾ������ҳ��
     */
    STDMETHOD_(void, RemoveAllItems)(THIS) PURE;

    /**
     * ITabCtrl::GetPageIndex
     * @brief    ��ȡָ��ҳ�������
     * @param    LPCTSTR pszName -- ��ѯ�ַ���
     * @param    BOOL bTitle --
     * TRUE:pszName�������page��title����,FALSE��pszName�������page��name����
     * @return   �ҵ���ҳ��������
     *
     * Describe
     */
    STDMETHOD_(int, GetPageIndex)(THIS_ LPCTSTR pszName, BOOL bTitle) PURE;
};

#undef INTERFACE
#define INTERFACE IEdit
DECLARE_INTERFACE_IID_(IEdit, ICtrl, "E682E0FF-1B1C-4a15-AB43-552E705B2560"){
	/**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ��ȡ��ʾ�ַ���
	 * @param[out] IStringT *pStr--��ʾ�ַ���
     * @return void
	 * @remark ����ʹ��SetAttribute
     */
	STDMETHOD_(void,GetCueText)(CTHIS_ IStringT *pStr) SCONST PURE;

    /**
     * @brief ��ȡ��ʾ�ַ�����ɫ
     * @return COLORREF--��ʾ�ַ�����ɫ
	 * @remark ����ʹ��SetAttribute
     */
	STDMETHOD_(COLORREF,GetCueColor)(CTHIS) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE ISpinButtonCtrl
DECLARE_INTERFACE_IID_(ISpinButtonCtrl, ICtrl, "C04997B9-E2AA-48bf-AEA5-FF1A03561F8C")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;
    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ����ֵ
     * @param nValue --��ֵ
     * @return
     */
    STDMETHOD_(void, SetValue)(THIS_ int nValue) PURE;

    /**
     * @brief ���÷�Χ
     * @param nMin --��Сֵ
     * @param nMax --���ֵ
     * @return
     */
    STDMETHOD_(void, SetRange)(THIS_ int nMin, int nMax) PURE;

    /**
     * @brief ���ò���
     * @param nStep --����
     * @return
     */
    STDMETHOD_(void, SetStep)(THIS_ UINT nStep) PURE;

    /**
     * @brief ��ȡֵ
     * @return int --��ǰֵ
     */
    STDMETHOD_(int, GetValue)(CTHIS) SCONST PURE;

    /**
     * @brief ��ȡ�����Ĵ��ڶ���
     * @return IWindow *--�����Ĵ��ڶ���
     */
    STDMETHOD_(IWindow *, GetIBuddy)(CTHIS) SCONST PURE;
};

#undef INTERFACE
#define INTERFACE IIconWnd
DECLARE_INTERFACE_IID_(IIconWnd, ICtrl, "8BBD8033-9955-41FD-8C3D-19FE702A9DB0")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

	/**
     * @brief    SetIcon
     * @param    HICON hIcon -- ͼ����Դ���
     * @return   void
     *
     * Describe  ͼ����Դ
     */
    STDMETHOD_(void, SetIcon)(THIS_ HICON hIcon) PURE;
};


#undef INTERFACE
#define INTERFACE IRealWnd
DECLARE_INTERFACE_IID_(IRealWnd, ICtrl, "3E9F9B19-68D1-47f1-9011-2F8B98C0A628")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    STDMETHOD_(const IStringT*, GetRealClassName)(CTHIS) SCONST PURE;

	STDMETHOD_(const IStringT*, GetRealWindowName)(CTHIS) SCONST PURE;

	STDMETHOD_(DWORD, GetRealStyle)(CTHIS) SCONST PURE;

	STDMETHOD_(DWORD, GetRealStyleEx)(CTHIS) SCONST PURE;

	STDMETHOD_(IXmlNode*, GetRealParam)(CTHIS) PURE;

	/**
     * SRealWnd::GetRealHwnd
     * @brief    ��ȡ���ھ��
     * @param    BOOL bAutoCreate -- �Զ�����
     * @return   ����HWND
     *
     * Describe  ��ȡ���ھ��
     */
	STDMETHOD_(HWND, GetRealHwnd)(THIS_ BOOL bAutoCreate DEF_VAL(TRUE)) PURE;


    /**
     * SRealWnd::SetData
     * @brief    ��ȡ��������
     * @param    LPVOID lpData -- ��������
     *
     * Describe  ��ȡ��������
     */
    STDMETHOD_(void,SetData)(THIS_ LPVOID lpData) PURE;

    /**
     * SRealWnd::GetData
     * @brief    ��ȡ��������
     * @return   ����LPVOID
     *
     * Describe  ��ȡ��������
     */
    STDMETHOD_(LPVOID,GetData)(THIS) PURE;
};

typedef enum _StackViewAniStyle{
	kAniNone=0,
	kFadeInOut,
	kMoveInOut,
	kPushInOut
}StackViewAniStyle;

#undef INTERFACE
#define INTERFACE IStackView
DECLARE_INTERFACE_IID_(IStackView, ICtrl, "1A7172D8-F45B-45fe-A73E-2B7F07E7EB70")
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

    /**
     * @brief ת��ΪIWindow*�ӿ�
     * @return IWindow*�ӿ�
     */
    STDMETHOD_(IWindow *, ToIWindow)(THIS) PURE;

    //////////////////////////////////////////////////////////////////////////

	STDMETHOD_(BOOL,SelectPage)(THIS_ int iView,BOOL enableAnimate DEF_VAL(TRUE)) PURE;
	STDMETHOD_(void,SetAniStyle)(THIS_ StackViewAniStyle aniStyle) PURE;
	STDMETHOD_(void,SetAniDir)(THIS_ BOOL bVert) PURE;	
	STDMETHOD_(IWindow*,GetSelPage)(CTHIS) SCONST PURE;
	STDMETHOD_(IWindow*,GetPage)(CTHIS_ int iPage) SCONST PURE;
};

SNSEND