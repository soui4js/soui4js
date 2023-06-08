#pragma once
#include <interface/obj-ref-i.h>
#include <interface/SResProvider-i.h>
#include <interface/STranslator-i.h>
#include <interface/stooltip-i.h>
#include <interface/slog-i.h>
#include <interface/SAttrStorage-i.h>
#include <interface/smsgloop-i.h>
#include <interface/shostwnd-i.h>
#include <interface/SResProviderMgr-i.h>
#include <interface/SRealWndHandler-i.h>
#include <interface/SRender-i.h>
#include <interface/SScriptModule-i.h>
#include <interface/SAnimation-i.h>
#include <interface/SValueAnimator-i.h>
#include <interface/SNotifyCenter-i.h>
#include <interface/SObjFactory-i.h>
#include <interface/SHostPresenter-i.h>
#include <interface/STaskLoop-i.h>

SNSBEGIN

typedef enum _SingletonType
{
	SINGLETON_UIDEF = 0,
	SINGLETON_SWNDMGR,
	SINGLETON_TIMERGENERATOR,
	SINGLETON_FONTPOOL,
	SINGLETON_WINDOWFINDER,
	SINGLETON_TEXTSERVICEHELPER,
	SINGLETON_RICHEDITMENUDEF,
	SINGLETON_SIMPLEWNDHELPER,
	SINGLETON_HOSTMGR,
	SINGLETON_NOTIFYCENTER,

	SINGLETON_COUNT,
}SingletonType;

typedef struct IApplication IApplication;
typedef IObject *(* FunCreateObject)(const IApplication * app,LPCWSTR pszName,SObjectType nType);
typedef ITaskLoop * (*FunCrateTaskLoop)();

#undef INTERFACE
#define INTERFACE IApplication
DECLARE_INTERFACE_(IApplication, IObjRef)
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
     * @brief ��ȡ��ǰapp��hModule
     * @return HMODULE--��ǰapp��hModule
     */
    STDMETHOD_(HMODULE, GetModule)(CTHIS) SCONST PURE;

    /**
     * @brief ��ָ����ResProvider�����ϵͳ��Դ
     * @param pResProvider �ṩϵͳ��Դ����Դ��
     * @return UINT 0-�ɹ�,����-ʧ��
     */
    STDMETHOD_(UINT, LoadSystemNamedResource)(THIS_ IResProvider * pResProvider) PURE;

    /**
     * @brief ��ȡ����ӿ�
     * @return ITranslatorMgr *--����ӿ�
     */
    STDMETHOD_(ITranslatorMgr *, GetTranslator)(THIS) PURE;

    /**
     * @brief ���÷���ӿ�
     * @param pTrans -- ����ӿ�
     * @return void
     * @remark ����ӿڿ���ͨ�����ط���ģ��������
     */
    STDMETHOD_(void, SetTranslator)(THIS_ ITranslatorMgr * pTrans) PURE;

    /**
     * @brief ��ȡToolTip�೧
     * @return IToolTipFactory *--ToolTip�೧
     */
    STDMETHOD_(IToolTipFactory *, GetToolTipFactory)(THIS) PURE;

    /**
     * @brief ����tooltip�೧
     * @param IToolTipFactory * pToolTipFac -- tooltip�೧
     * @return void
     * @remark ͨ��ʵ��tooltip�೧�����Զ���tooltip����ʾЧ��
     */
    STDMETHOD_(void, SetToolTipFactory)(THIS_ IToolTipFactory * pToolTipFac) PURE;

    /**
     * @brief �趨MsgLoop�೧
     * @param IMsgLoopFactory * pMsgLoopFac -- MsgLoop�೧
     * @return BOOL TRUE-�ɹ�
     */
    STDMETHOD_(BOOL, SetMsgLoopFactory)(THIS_ IMsgLoopFactory * pMsgLoopFac) PURE;

    /**
     * @brief ��ȡ��ǰ��MsgLoop�೧
     * @return IMsgLoopFactory *--MsgLoop�೧
     */
    STDMETHOD_(IMsgLoopFactory *, GetMsgLoopFactory)(THIS) PURE;

    /**
     * @brief ������־���ģ��
     * @param ILog4zManager *pLogMgr --��־���ģ��
     * @return
     */
    STDMETHOD_(void, SetLogManager)(THIS_ ILogMgr * pLogMgr) PURE;

    /**
     * @brief ��ȡ��־���ģ��
     * @return  ILog4zManager *--��־���ģ��
     */
    STDMETHOD_(ILogMgr *, GetLogManager)(THIS) PURE;

    /**
     * @brief �������Գ־þ��೧
     * @param IAttrStorageFactory* pAttrStorageFactory --���Գ־þ��೧
     * @remark
     * ʵ�ָýӿڲ����ø�SApp�����Ա���SObjectͨ��SetAttribute���õ����ԣ���GetAttributeʱ�ṩ����
     */
    STDMETHOD_(void, SetAttrStorageFactory)(THIS_ IAttrStorageFactory * pAttrStorageFactory) PURE;

    /**
     * @brief ��ȡ���Գ־þ��೧
     * @return IAttrStorageFactory *--���Գ־þ��೧
     */
    STDMETHOD_(IAttrStorageFactory *, GetAttrStorageFactory)(THIS) PURE;

    /**
     * @brief ������Ϣѭ�����г���
     * @param HWND hMainWnd -- �����ھ��
     * @return int -- �����˳��ķ���ֵ
     */
    STDMETHOD_(int, Run)(THIS_ HWND hMainWnd) PURE;

	/**
     * @brief �˳���Ϣѭ��
     * @return void
	 * @param int nCode -- thread quit code
	 * @remark ����PostQuitMessage
     */
	STDMETHOD_(void, Quit)(THIS_ int nCode) PURE;
    /**
     * @brief ��ȡ����������
     * @return HWND--��Run�������趨�Ĵ���
     */
    STDMETHOD_(HWND, GetMainWnd)(THIS) PURE;

    /**
     * @brief ����ǰUI�̵߳�msgLoop���浽SApp��
     * @param IMessageLoop *pMsgLoop -- msgLoop
	 * @param BOOL bReplace -- �滻��־
     * @return BOOL TRUE-�ɹ�
     * @remark �ڶ�UI�̳߳����У���Ҫ�������̵߳�msgLoop����SApp����
     */
    STDMETHOD_(BOOL, AddMsgLoop)(THIS_ IMessageLoop * pMsgLoop,BOOL bReplace DEF_VAL(FALSE)) PURE;

    /**
     * @brief ��SApp��ɾ����ǰ�̵߳�msgLoop
     * @return BOOL TRUE-�ɹ�
     */
    STDMETHOD_(BOOL, RemoveMsgLoop)(THIS) PURE;

    /**
     * @brief ��ȡָ��UI�̵߳�msgLoop
     * @param DWORD dwThreadID--�߳�ID
     * @return IMessageLoop *--ָ���̵߳�msgloop
     */
    STDMETHOD_(IMessageLoop *, GetMsgLoop)(CTHIS_ DWORD dwThreadID) SCONST PURE;

    /**
     * @brief ��ȡIResProviderMgr�ӿ�
     * @return IResProviderMgr *--IResProviderMgr�ӿ�
     */
    STDMETHOD_(IResProviderMgr *, GetResProviderMgr)(THIS) PURE;

    /**
     * GetRealWndHander
     * @brief    ���RealWndHander
     * @return   IRealWndHandler * -- RealWndHander
     * Describe
     */
    STDMETHOD_(IRealWndHandler *, GetRealWndHander)(THIS) PURE;

    /**
     * SetRealWndHandler
     * @brief    ����RealWnd����ӿ�
     * @param    IRealWndHandler * pRealHandler --  RealWnd����ӿ�
     * @return   void
     * Describe
     */
    STDMETHOD_(void, SetRealWndHandler)(THIS_ IRealWndHandler * pRealHandler) PURE;

    /**
     * GetRenderFactory
     * @brief    ��õ�ǰ����Ⱦģ��
     * @return   IRenderFactory * ��Ⱦģ��ָ��
     *
     * Describe
     */
    STDMETHOD_(IRenderFactory *, GetRenderFactory)(THIS) PURE;

    /**
     * SetScriptModule
     * @brief    ����SOUI��ʹ�õĽű�ģ���೧
     * @param    IScriptFactory *pScriptModule --  �ű�ģ���೧
     * @return   void
     *
     * Describe
     */
    STDMETHOD_(void, SetScriptFactory)(THIS_ IScriptFactory * pScriptModule) PURE;

    /**
     * @brief ��ʼ��XML��Դ��name-idӳ���
     * @param pNames const LPCWSTR *--�ؼ�����
     * @param nIds const int *--�ؼ�ID��
     * @param nCount int--�ؼ�����
     * @return
     * @remark ���ݱ���residbuilder�����Զ�����
     */
    STDMETHOD_(void, InitXmlNamedID)(THIS_ const LPCWSTR *pNames, const int *nIds, int nCount) PURE;

    /**
     * @brief ����ԴID����XML
     * @param strResId LPCTSTR--��ԴID��Ϊtype:name��ʽ
     * @return IXmlDoc *--XML Doc
     * @remark ʹ����ɺ����Rlease�ͷ�
     */
    STDMETHOD_(IXmlDoc *, LoadXmlDocment)(THIS_ LPCTSTR strResId) PURE;
	STDMETHOD_(IXmlDoc *, LoadXmlDocmentA)(THIS_ LPCSTR strResId) PURE;

    /**
     * @brief ����Դ���ض�����Դ
     * @param strResId LPCTSTR--������ԴID
     * @return IAnimation* ��������
     * @remark ʹ����ɺ����Rlease�ͷ�
     */
    STDMETHOD_(IAnimation *, LoadAnimation)(THIS_ LPCTSTR strResId) PURE;
	STDMETHOD_(IAnimation *, LoadAnimationA)(THIS_ LPCSTR strResId) PURE;

    /**
     * @brief ����Դ������ֵ������Դ
	 * @param strResId LPCTSTR--������ԴID
     * @return IValueAnimator* ��ֵ��������
     * @remark ʹ����ɺ����Rlease�ͷ�
     */
    STDMETHOD_(IValueAnimator *, LoadValueAnimator)(THIS_ LPCTSTR strResId) PURE;
	STDMETHOD_(IValueAnimator *, LoadValueAnimatorA)(THIS_ LPCSTR strResId) PURE;

    /**
     * @brief ����Դ����ͼƬ
	 * @param strResId LPCTSTR--ͼƬ��ԴID
     * @return IBitmapS* ͼƬ����
     * @remark ʹ����ɺ����Rlease�ͷ�
     */
	STDMETHOD_(IBitmapS *,LoadImage)(THIS_ LPCTSTR strResId) PURE;
	STDMETHOD_(IBitmapS *,LoadImageA)(THIS_ LPCSTR strResId) PURE;

    /**
     * @brief ����Դ���ط����
	 * @param strResId LPCTSTR--�������ԴID
     * @return ITranslator* ���������
     * @remark ʹ����ɺ����Rlease�ͷ�
     */
	STDMETHOD_(ITranslator *,LoadTranslator)(THIS_ LPCTSTR strResId) PURE;
	STDMETHOD_(ITranslator *,LoadTranslatorA)(THIS_ LPCSTR strResId) PURE;

    /**
     * @brief ʹ�÷����
	 * @param ITranslator * trModule--�����
     * @return BOOL, TRUE--�ɹ�
     */
	STDMETHOD_(BOOL,InstallTranslator)(THIS_ ITranslator * trModule) PURE;

	/**
     * @brief ж�ط����
	 * @param REFGUID langId--�����ID
     * @return BOOL, TRUE--�ɹ�
     */
	STDMETHOD_(BOOL,UnnstallTranslator)(THIS_  REFGUID langId) PURE;

	/**
     * @brief ����NotifyCenter
	 * @param BOOL bEnable -- �Ƿ�����
	 * @param int interval -- �����¼�ʱ����
     * @return void
     */
	STDMETHOD_(void,EnableNotifyCenter)(THIS_ BOOL bEnable,int interval DEF_VAL(20)) PURE;

	/**
     * @brief ��ȡSApp�ڲ�����ļ�����������
	 * @param SingletonType type -- �ڲ���������
     * @return void * -- ��������ָ��
	 * @remark Ŀǰ��Ҫͨ������ȡINotifyCenter*,�Ա�C����ʹ��
     */
	STDMETHOD_(void*,GetInnerSingleton)(THIS_ SingletonType type) PURE;

	/**
     * @brief �����Զ����CreateObject�ص�����
	 * @param LPCWSTR pszName -- ������XML�е�����
	 * @param SObjectType nType -- ����ID
     * @return IObjRef * -- ����������
     */
	STDMETHOD_(IObject *,CreateObject)(CTHIS_ LPCWSTR pszName,SObjectType nType) SCONST PURE;

	/**
     * @brief ����CreateObject�Ļص�
	 * @param FunCreateObject cbCreateObj -- CreateObject�Ļص�����
     * @return void
     */
	STDMETHOD_(void,SetCreateObjectCallback)(THIS_ FunCreateObject cbCreateObj) PURE;

	/**
     * @brief ע����չ����
	 * @param const IObjectFactory *objFac -- �����೧
	 * @param BOOL bReplace -- �滻�����೧��־
     * @return BOOL, TRUE--�ɹ�
     */
	STDMETHOD_(BOOL,RegisterObjFactory)(THIS_ const IObjectFactory *objFac,BOOL bReplace DEF_VAL(FALSE)) PURE;

	/**
     * @brief ��ע����չ����
	 * @param const IObjectFactory *objFac -- �����೧
     * @return BOOL, TRUE--�ɹ�
     */
	STDMETHOD_(BOOL,UnregisterObjFactory)(THIS_ const IObjectFactory *objFac) PURE;

	/**
     * @brief ����Ĭ������
	 * @param LPCWSTR pszFontInfo -- ��������, �ο�fontpool
     * @return void
     */
	STDMETHOD_(void,SetDefaultFontInfo)(THIS_ LPCWSTR pszFontInfo) PURE;

	/**
     * @brief ����TaskLoop����
	 * @param int nCount -- taskloop��������
	 * @param Priority priority -- taskloop���߳����ȼ�
	 * @param BOOL bAutoStart -- �Զ�������־
     * @return BOOL, TRUE--�ɹ�
     */
	STDMETHOD_(BOOL,CreateTaskLoop)(THIS_ int nCount,Priority priority,BOOL bAutoStart DEF_VAL(TRUE)) PURE;

	/**
     * @brief ��ȡTaskLoop����
	 * @param int iTaskLoop -- taskloop����
     * @return ITaskLoop * -- taskloop�ӿ�,ʧ�ܷ���NULL
     */
	STDMETHOD_(ITaskLoop *, GetTaskLoop)(THIS_ int iTaskLoop DEF_VAL(0)) PURE;

	/**
     * @brief ���ô���TaskLoop����Ļص��ӿ�
	 * @param FunCrateTaskLoop cbCreateTaskLoop -- ����TaskLoop����Ļص��ӿ�
     * @return void
     */
	STDMETHOD_(void, SetCreateTaskLoopCallback)(THIS_ FunCrateTaskLoop cbCreateTaskLoop) PURE;

	 /**
     * CreateScriptModule
     * @brief    �����ű�ģ�����
     * @param [out] IScriptModule **ppScriptModule -- �ű�ģ�����
     * @return   HRESULT -- S_OK �����ɹ�
     *
     * Describe
     */
    STDMETHOD_(HRESULT,CreateScriptModule)(THIS_ IScriptModule **ppScriptModule) PURE;

};

SNSEND