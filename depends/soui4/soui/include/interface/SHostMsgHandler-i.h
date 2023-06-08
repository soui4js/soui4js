#pragma once

SNSBEGIN

#undef INTERFACE
#define INTERFACE IHostMsgHandler
DECLARE_INTERFACE(IHostMsgHandler)
{
    /**
     * @brief ��Ӧ������Ϣ
     * @param bRelayout BOOL--�ز��ֱ�־
     * @param uMsg UINT--��ϢID
     * @param wp WPARAM--��Ϣ����1
     * @param lp LPARAM--��Ϣ����2
     * @return
     * @remark Ŀǰֻ�޸�ϵͳ����ʱʹ��
     */
    STDMETHOD_(void, OnHostMsg)(THIS_ BOOL bRelayout, UINT uMsg, WPARAM wp, LPARAM lp) PURE;
};

SNSEND