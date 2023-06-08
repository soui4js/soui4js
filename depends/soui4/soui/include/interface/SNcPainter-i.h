#pragma once
#include <interface/SWindow-i.h>

SNSBEGIN

#undef INTERFACE
#define INTERFACE INcPainter
DECLARE_INTERFACE_(INcPainter, IObject)
{
#include <interface/SobjectApi.h>

    //--------------------------------------------------------------------------------

    /**
     * @brief ��ȡ���Ʒǿͻ����ĸ�����
     * @return IWindow *--root
     */
    STDMETHOD_(IWindow *, GetRoot)(THIS) PURE;
};

SNSEND