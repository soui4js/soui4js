#pragma once
#include <interface/obj-ref-i.h>
#include <interface/SEvtArgs-i.h>

SNSBEGIN

#undef INTERFACE
#define INTERFACE ITimer
DECLARE_INTERFACE_(ITimer, IObjRef)
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

    //////////////////////////////////////////////////////////////////////////

	/**
     * StartTimer
     * @brief    ������ʱ��
     * @param    int nElapse --  ��ʱ(ms)
	 * @param    BOOL bRepeat -- �ظ���־
	 * @param    LPARAM uData -- Timer �Զ������
     * @return   BOOL, TRUE--�ɹ�
     * Describe
     */
	STDMETHOD_(BOOL,StartTimer)(THIS_ int nElapse,BOOL bRepeat,LPARAM uData DEF_VAL(0)) PURE;

	/**
     * KillTimer
     * @brief    ֹͣ��ʱ��
     * @return   void
     * Describe
     */
	STDMETHOD_(void,KillTimer)(THIS) PURE;
};

SNSEND