#pragma once
#include <interface/SAdapter-i.h>

SNSBEGIN

#undef INTERFACE
#define INTERFACE ITileViewItemLocator
DECLARE_INTERFACE_(ITileViewItemLocator, IObjRef)
{
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
    //--------------------------------------------------

    /**
     * @brief ���ù�����������
     * @param pAdapter ILvAdapter *--������ָ��
     * @return void
     */
    STDMETHOD_(void, SetAdapter)(THIS_ ILvAdapter * pAdapter) PURE;

    /**
     * @brief ���ݼ������仯�����Ӧ����
     * @return
     */
    STDMETHOD_(void, OnDataSetChanged)(THIS) PURE;

    /**
     * @brief ��ȡ����߶�
     * @param iItem int -- ��������
     * @return int--����߶�
     */
    STDMETHOD_(int, GetItemHeight)(CTHIS_ int iItem) SCONST PURE;

    /**
     * @brief �趨����ĸ߶�
     * @param iItem int--��������
     * @param nHeight int--����߶�
     * @return
     */
    STDMETHOD_(void, SetItemHeight)(THIS_ int iItem, int nHeight) PURE;

    /**
     * @brief ��ȡ�������ʾλ��
     * @param iItem int--��������
     * @return RECT--������ʾ����
     * @remark ��ȡitem��CRect(�����TileView)
     */
    STDMETHOD_(RECT, GetItemRect)(THIS_ int iItem) PURE;

    /**
     * @brief ����TileView���
     * @param width int--���
     * @param bDpiAware BOOL--dpi aware flag
     * @return
     * @remark ��TileView��OnSize�е���
     */
    STDMETHOD_(void, SetTileViewWidth)(THIS_ int width, BOOL bDpiAware) PURE;

    /**
     * @brief ��ȡitem���С���λ��
     * @param iItem int--��������
     * @param [out] row int*--�к�
     * @param [out] col int*--�к�
     * @return
     */
    STDMETHOD_(void, GetItemRowAndColIndex)(THIS_ int iItem, int *row, int *col) PURE;

    /**
     * @brief �Ƿ�Ϊһ�е����һ��Ԫ��
     * @param iItem int--��������
     * @return TRUE--��
     */
    STDMETHOD_(BOOL, IsLastInRow)(THIS_ int iItem) PURE;

    /**
     * @brief ��ȡ��һ�У�ͬһ�е�Ԫ��index
     * @param iItem int--��������
     * @return int--��һ�У�ͬһ�е�Ԫ��index
     */
    STDMETHOD_(int, GetUpItem)(THIS_ int iItem) PURE;

    /**
     * @brief ��ȡ��һ�У�ͬһ�е�Ԫ��index
     * @param iItem int--��������
     * @return int--��һ�У�ͬһ�е�Ԫ��index
     */
    STDMETHOD_(int, GetDownItem)(THIS_ int iItem) PURE;

    /**
     * @brief �����б���ʾ�ܸ߶�
     * @return int--�б���ʾ�ܸ߶�
     */
    STDMETHOD_(int, GetTotalHeight)(THIS) PURE;

    /**
     * @brief ��ȡ�����ڹ������ϵ�Yλ��
     * @param iItem int--��������
     * @return int--Y��λ��
     */
    STDMETHOD_(int, Item2Position)(THIS_ int iItem) PURE;

    /**
     * @brief ��������λ��ת���ɱ�������
     * @param position int--������λ��
     * @return int--��������
     */
    STDMETHOD_(int, Position2Item)(THIS_ int position) PURE;

    /**
     * @brief ��ȡ�й����߶�
     * @return int--�й����߶�
     */
    STDMETHOD_(int, GetScrollLineSize)(CTHIS) SCONST PURE;

    /**
     * @brief ��ȡ�б�߾�
     * @return int--�б�߾�
     */
    STDMETHOD_(int, GetMarginSize)(CTHIS) SCONST PURE;

    /**
     * @brief ���÷Ŵ���
     * @param scale int--�Ŵ�������100Ϊ����
     * @return
     */
    STDMETHOD_(int, SetScale)(THIS_ int scale) PURE;

    /**
     * @brief ��ȡ����
     * @return int--����
     */
    STDMETHOD_(int, GetCountInRow)(CTHIS) SCONST PURE;

    /**
     * @brief ��ȡ�и�
     * @return int--�и�
     */
    STDMETHOD_(int, GetItemLineHeight)(CTHIS) SCONST PURE;

    /**
     * @brief ��ȡ������ʾ���
     * @return int--������ʾ���
     */
    STDMETHOD_(int, GetItemWidth)(CTHIS) SCONST PURE;
};

SNSEND