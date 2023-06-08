#pragma once
#include <utilities-def.h>
#include <interface/SEvtArgs-i.h>
#include <interface/STaskLoop-i.h>

SNSBEGIN

typedef void (*FunRunOnUI)(WPARAM wp,LPARAM lp);

#undef INTERFACE
#define INTERFACE INotifyCenter
DECLARE_INTERFACE(INotifyCenter)
{
    /**
     * FireEventSync
     * @brief    ����һ��ͬ��֪ͨ�¼�
     * @param    EventArgs *e -- �¼�����
     * @return
     *
     * Describe  ֻ����UI�߳��е���
     */
    STDMETHOD_(void,FireEventSync)(THIS_ IEvtArgs *e) PURE;

    /**
     * FireEventAsync
     * @brief    ����һ���첽֪ͨ�¼�
     * @param    EventArgs *e -- �¼�����
     * @return
     *
     * Describe  �����ڷ�UI�߳��е��ã�EventArgs
     * *e�����ǴӶ��Ϸ�����ڴ棬���ú�ʹ��Release�ͷ����ü���
     */
    STDMETHOD_(void,FireEventAsync)(THIS_ IEvtArgs *e) PURE;

    /**
     * RegisterEventMap
     * @brief    ע��һ������֪ͨ�Ķ���
     * @param    const ISlotFunctor *slot -- �¼��������
     * @return
     *
     * Describe
     */
    STDMETHOD_(BOOL, RegisterEventMap)(THIS_ const IEvtSlot *slot) PURE;

    /**
     * RegisterEventMap
     * @brief    ע��һ������֪ͨ�Ķ���
     * @param    const ISlotFunctor *slot -- �¼��������
     * @return
     *
     * Describe
     */
    STDMETHOD_(BOOL, UnregisterEventMap)(THIS_ const IEvtSlot *slot) PURE;

    /**
     * RunOnUI
     * @brief    
     * @param    IRunnable * pRunnable -- runnableִ����
	 * @param    BOOL bSync -- ͬ��ִ�б�־
     * @return
     *
     * Describe
     */
	STDMETHOD_(void,RunOnUI)(THIS_ IRunnable * pRunnable,BOOL bSync) PURE;

    /**
     * RunOnUI2
     * @brief    
     * @param    FunRunOnUI fun -- callback function
	 * @param    WPARAM wp -- param 1
	 * @param    LPARAM wp -- param 2
	 * @param    BOOL bSync -- ͬ��ִ�б�־
     * @return
     *
     * Describe
     */
	STDMETHOD_(void,RunOnUI2)(THIS_ FunRunOnUI fun, WPARAM wp, LPARAM lp,BOOL bSync) PURE;

};

SNSEND