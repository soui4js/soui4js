#pragma once
#include <interface/sobject-i.h>

SNSBEGIN

#undef INTERFACE
#define INTERFACE ICaret
DECLARE_INTERFACE_(ICaret, IObject)
{
#include <interface/SobjectApi.h>
    //-----------------------------------------------------------------------------------

    /**
     * @brief ��ʼ�����
     * @param hBmp --����λͼ������Ϊ��
     * @param nWid --�����
     * @param nHei --���߶�
     * @return BOOL TRUE-�ɹ�
     */
    STDMETHOD_(BOOL, Init)(THIS_ HBITMAP hBmp, int nWid, int nHei) PURE;

    /**
     * @brief ���ù��λ��
     * @param x -- X
     * @param y -- Y
     * @return
     */
    STDMETHOD_(void, SetPosition)(THIS_ int x, int y) PURE;

    /**
     * @brief ���ù����ʾ״̬
     * @param bVisible --��ʾ״̬
     * @param owner --��������
     * @return BOOL TRUE-�ɹ�
     */
    STDMETHOD_(BOOL, SetVisible)(THIS_ BOOL bVisible, SWND owner) PURE;

    /**
     * @brief ��ȡ�����ʾ״̬
     * @return BOOL TRUE-��ʾ
     */
    STDMETHOD_(BOOL, IsVisible)(CTHIS) SCONST PURE;

    /**
     * @brief ���ƹ��
     * @param pRT --���ƹ���RenderTarget
     * @return
     */
    STDMETHOD_(void, Draw)(THIS_ IRenderTarget * pRT) PURE;

    /**
     * @brief ��ȡ�����ʾ����
     * @return RECT
     */
    STDMETHOD_(RECT, GetRect)(CTHIS) SCONST PURE;
};

SNSEND