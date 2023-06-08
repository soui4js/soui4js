#pragma once

#include <interface/sobject-i.h>

SNSBEGIN

#undef INTERFACE
#define INTERFACE IEvtArgs
DECLARE_INTERFACE_(IEvtArgs, IObject)
{
#include <interface/SobjectApi.h>

    //-------------------------------------------------------------------------------------------

    /**
     * @brief ��ȡ�¼����Ͷ���
     * @return IObject *--�¼����Ͷ���
     */
    STDMETHOD_(IObject *, Sender)(THIS) PURE;

    /**
     * @brief ��ȡ�¼����Ͷ���ID
     * @return int--�¼����Ͷ���ID
     */
    STDMETHOD_(int, IdFrom)(CTHIS) SCONST PURE;

    /**
     * @brief �����¼��ķ��Ͷ���ID
     * @param id int--���Ͷ���ID
     * @return
     */
    STDMETHOD_(void, SetIdFrom)(THIS_ int id) PURE;

    /**
     * @brief ��ȡ�¼����Ͷ���Name
     * @return LPCWSTR--�¼����Ͷ���Name
     */
    STDMETHOD_(LPCWSTR, NameFrom)(CTHIS) SCONST PURE;

    /**
     * @brief �����¼����Ͷ���Name
     * @param name LPCWSTR--�¼����Ͷ���Name
     * @return
     */
    STDMETHOD_(void, SetNameFrom)(THIS_ LPCWSTR name) PURE;

    /**
     * @brief ��ȡ�¼��Ƿ���Ҫð�ݴ���
     * @return BOOL TRUE--ð�ݴ���
     */
    STDMETHOD_(BOOL, IsBubbleUp)(CTHIS) SCONST PURE;

    /**
     * @brief �����¼���ð�ݴ���
     * @param bBubbleUp BOOL, FALSE--��ֹ����
     * @return
     */
    STDMETHOD_(void, SetBubbleUp)(THIS_ BOOL bBubbleUp) PURE;

    /**
     * @brief ��ȡ�¼��������
     * @return UINT �¼��������
     */
    STDMETHOD_(UINT, HandleCount)(CTHIS) SCONST PURE;

    /**
     * @brief �����¼��������
     * @return
     */
    STDMETHOD_(void, IncreaseHandleCount)(THIS) PURE;

    /**
     * @brief ��ȡ�¼�������������ݽṹ��ָ��
     * @return �¼�������������ݽṹ��ָ��
     * @remark ��ͬ�¼����������ͬ�����ݣ���ȡָ����ת��Ϊ�ṹ��ָ�롣��Ҫ��C�ӿ�ʹ�á�
     */
    STDMETHOD_(LPVOID, Data)(THIS) PURE;
};

/*!
\brief
    Defines abstract interface which will be used when constructing various
    functor objects that bind slots to signals (or in CEGUI terms, handlers to
    events).
*/
#undef INTERFACE
#define INTERFACE IEvtSlot
DECLARE_INTERFACE_(IEvtSlot, IObjRef)
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

    /**
     * @brief ִ���¼�
     * @param pArg IEvtArgs* �¼�����
     * @return BOOL TRUE--��Ӧ���¼����¼���������ʹ�ü���, FALSE--�¼�û����Ӧ
     */
    STDMETHOD_(BOOL, Run)(THIS_ IEvtArgs * pArg) PURE;

    /**
     * @brief cloneһ���¼���
     * @return IEvtSlot * clone�����Ķ���
     */
    STDMETHOD_(IEvtSlot *, Clone)(CTHIS) SCONST PURE;

    /**
     * @brief �ж�����IEvtSlot�Ƿ����
     * @param sour IEvtSlot * �Ƚϵ�IEvtSlot
     * @return
     */
    STDMETHOD_(BOOL, Equal)(CTHIS_ const IEvtSlot *sour) SCONST PURE;

    /**
     * @brief ��ȡIEvtSlot����
     * @return UINT IEvtSlot����
     */
    STDMETHOD_(UINT, GetSlotType)(CTHIS) SCONST PURE;
};

/**
 * @brief �¼�����ص�
 * @param pEvt IEvtArgs * �¼�����
 * @param Ctx void * �¼�����������
 * @return BOOL TRUE--�¼����������Ӵ������
 */
typedef BOOL (*FunCallback)(IEvtArgs *pEvt, void *Ctx);

#define EventArgs IEvtArgs
SNSEND