#pragma once

#include <interface/SMatrix-i.h>
SNSBEGIN

enum
{
    /**
     * Indicates a transformation that has no effect (alpha = 1 and identity matrix.)
     */
    TYPE_IDENTITY = 0x0,
    /**
     * Indicates a transformation that applies an alpha only (uses an identity matrix.)
     */
    TYPE_ALPHA = 0x1,
    /**
     * Indicates a transformation that applies a matrix only (alpha = 1.)
     */
    TYPE_MATRIX = 0x2,
    /**
     * Indicates a transformation that applies an alpha and a matrix.
     */
    TYPE_BOTH = TYPE_ALPHA | TYPE_MATRIX,
};

#undef INTERFACE
#define INTERFACE ITransformation

DECLARE_INTERFACE(ITransformation)
{
    /**
     * @brief ��ȡ�任����
     * @return IMatrix *--�任����
     */
    STDMETHOD_(IMatrix *, GetMatrix)(THIS) PURE;

    /**
     * @brief ��ȡ͸����
     * @return BYTE--͸����
     */
    STDMETHOD_(BYTE, GetAlpha)(CTHIS) SCONST PURE;

    /**
     * @brief ����͸����
     * @param alpha BYTE--͸����
     * @return
     */
    STDMETHOD_(void, SetAlpha)(THIS_ BYTE alpha) PURE;

    /**
     * @brief ��ձ任����͸����
     * @return
     */
    STDMETHOD_(void, Clear)(THIS) PURE;

    /**
     * @brief ���ñ仯����
     * @param type int--����
     * @return
     */
    STDMETHOD_(void, SetTransformationType)(THIS_ int type) PURE;

    /**
     * @brief ��ϱ任����͸����
     * @param t ITransformation *--�任����
     * @return
     */
    STDMETHOD_(void, Compose)(const ITransformation *t) PURE;
};

SNSEND