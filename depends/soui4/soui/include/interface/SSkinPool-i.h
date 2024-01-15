#ifndef _SSKINPOOL_I_H__
#define _SSKINPOOL_I_H__

#include <interface/SSkinobj-i.h>
#include <interface/sxml-i.h>

SNSBEGIN

#undef INTERFACE
#define INTERFACE ISkinPool
DECLARE_INTERFACE_(ISkinPool, IObjRef)
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
     * GetSkin
     * @brief    �����ָ��nameƥ���SkinObj
     * @param    LPCWSTR strSkinName --    Name of Skin Object
     * @return   ISkinObj*  -- �ҵ���Skin Object
     * Describe
     */
    STDMETHOD_(ISkinObj *, GetSkin)(THIS_ LPCWSTR strSkinName, int nScale) PURE;

    /**
     * LoadSkins
     * @brief    ��XML�м���Skin�б�
     * @param    SXmlNode xmlNode --  ����SkinObj��XML��
     * @return   int -- �ɹ����ص�SkinObj����
     * Describe
     */
    STDMETHOD_(int, LoadSkins)(THIS_ IXmlNode * xmlNode) PURE;

    /**
     * AddSkin
     * @brief    ����һ��skinObj����SkinPool
     * @param    ISkinObj* --  SkinObj
     * @return   BOOL -- �����Ƿ�ɹ�,��������ʧ��
     * Describe
     */
    STDMETHOD_(BOOL, AddSkin)(THIS_ ISkinObj * skin) PURE;

    /**
     * RemoveSkin
     * @brief    ɾ��һ��skinObj����
     * @param    ISkinObj* --  SkinObj
     * @return   BOOL -- TRUE-�ɹ�
     * Describe
     */
    STDMETHOD_(BOOL, RemoveSkin)(THIS_ ISkinObj * skin) PURE;

    /**
     * RemoveAll
     * @brief    ɾ��ȫ��skin
     * @return   void
     * Describe
     */
    STDMETHOD_(void, RemoveAll)(THIS) PURE;
};

SNSEND

#endif //_SSKINPOOL_I_H__