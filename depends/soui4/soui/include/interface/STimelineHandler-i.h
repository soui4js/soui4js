#pragma once
#include <utilities-def.h>

SNSBEGIN
/**
 * @struct     ITimelineHandler
 * @brief      ʱ���ᴦ��ӿ�
 *
 * Describe
 */
#undef INTERFACE
#define INTERFACE ITimelineHandler
DECLARE_INTERFACE(ITimelineHandler)
{
    /**
     * @brief ��һ������֡����ӿ�
     * @return
     */
    STDMETHOD_(void, OnNextFrame)(THIS) PURE;
};

#undef INTERFACE
#define INTERFACE ITimelineHandlersMgr
DECLARE_INTERFACE(ITimelineHandlersMgr)
{
    /**
     * @brief ע�ᶯ��֡����ӿ�
     * @param pHandler ITimelineHandler *--����֡����ӿ�
     * @return TRUE--�ɹ�
     */
    STDMETHOD_(BOOL, RegisterTimelineHandler)(THIS_ ITimelineHandler * pHandler) PURE;

    /**
     * @brief ע������֡����ӿ�
     * @param pHandler ITimelineHandler *--����֡����ӿ�
     * @return TRUE--�ɹ�
     */
    STDMETHOD_(BOOL, UnregisterTimelineHandler)(THIS_ ITimelineHandler * pHandler) PURE;
};
SNSEND