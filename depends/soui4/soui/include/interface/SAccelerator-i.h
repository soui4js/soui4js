#pragma once
#include <utilities-def.h>

SNSBEGIN

enum
{
    Mod_None = 0,
    Mod_Alt = 1,
    Mod_Ctrl = 2,
    Mod_Shift = 4,
};

#undef INTERFACE
#define INTERFACE IAccelerator
DECLARE_INTERFACE(IAccelerator)
{
    /**
     * GetModifier
     * @brief    ��ü��ټ�������λ
     * @return   WORD -- ���ټ������μ�
     * Describe
     */
    STDMETHOD_(WORD, GetModifier)(CTHIS) SCONST PURE;

    /**
     * GetKey
     * @brief    ��ü��ټ�������
     * @return   WORD -- ���ټ�������
     * Describe
     */
    STDMETHOD_(WORD, GetKey)(CTHIS) SCONST PURE;

    /**
     * GetAcc
     * @brief    ��ü��ټ�
     * @return   DWORD -- ���ټ�
     * Describe
     */
    STDMETHOD_(DWORD, GetAcc)(CTHIS) SCONST PURE;
};

/**
 * @struct     IAcceleratorTarget
 * @brief      ���ټ����µĴ���ӿ�
 *
 * Describe ��Ҫע����̼��ټ�������Ҫʵ�ֱ��ӿ�
 */
#undef INTERFACE
#define INTERFACE IAcceleratorTarget
DECLARE_INTERFACE(IAcceleratorTarget)
{
    /**
     * OnAcceleratorPressed
     * @brief
     * @param    const CAccelerator & accelerator --  ���µļ��ټ�
     * @return   bool -- ���ټ���������true
     * Describe
     */
    STDMETHOD_(BOOL, OnAcceleratorPressed)(THIS_ const IAccelerator *acc) PURE;
};

/**
 * @struct     IAcceleratorMgr
 * @brief      ���ټ�����ӿ�
 *
 * Describe
 */
#undef INTERFACE
#define INTERFACE IAcceleratorMgr
DECLARE_INTERFACE(IAcceleratorMgr)
{
    // Register a keyboard accelerator for the specified target. If multiple
    // targets are registered for an accelerator, a target registered later has
    // higher priority.
    // Note that we are currently limited to accelerators that are either:
    // - a key combination including Ctrl or Alt
    // - the escape key
    // - the enter key
    // - any F key (F1, F2, F3 ...)
    // - any browser specific keys (as available on special keyboards)
    STDMETHOD_(void, RegisterAccelerator)
    (THIS_ const IAccelerator *pAcc, IAcceleratorTarget *target) PURE;

    // Unregister the specified keyboard accelerator for the specified target.
    STDMETHOD_(void, UnregisterAccelerator)
    (THIS_ const IAccelerator *pAcc, IAcceleratorTarget *target) PURE;

    // Unregister all keyboard accelerator for the specified target.
    STDMETHOD_(void, UnregisterAccelerators)(THIS_ IAcceleratorTarget * target) PURE;
};

SNSEND