#pragma once

#include <interface/obj-ref-i.h>
#include <interface/sapp-i.h>
#include <interface/shostwnd-i.h>
#include <interface/sstring-i.h>
#include <interface/sxml-i.h>
#include <interface/SResProvider-i.h>
#include <interface/SEvtArgs-i.h>
#include <interface/smenu-i.h>
#include <interface/smenuex-i.h>
#include <interface/STimer-i.h>
#include <soui_exp.h>
SNSBEGIN

#undef INTERFACE
#define INTERFACE ISouiFactory
DECLARE_INTERFACE_(ISouiFactory, IObjRef)
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

	/** CreateApp
	 * @brief ����IApp����
	 * @return IApplication * -- App����
	 */
	STDMETHOD_(IApplication *, CreateApp)(THIS_ IRenderFactory *pRenderFac,HMODULE hInst,LPCTSTR pszHostClassName DEF_VAL(_T("SOUIHOST")), BOOL bImeApp DEF_VAL(FALSE)) PURE;

	/** CreateNativeWnd
	 * @brief �������ڶ���
	 * @return INativeWnd * -- ���ڶ���
	 */
	STDMETHOD_(INativeWnd *, CreateNativeWnd)(THIS) PURE;

	/** CreateHostWnd
	 * @brief ����SOUI���ڶ���
	 * @return IHostWnd * -- SOUI���ڶ���
	 */
	STDMETHOD_(IHostWnd *, CreateHostWnd)(THIS_ LPCTSTR pszResID DEF_VAL(NULL)) PURE;


	/** CreateHostDialog
	 * @brief ����SOUI�Ի������
	 * @return IHostDialog * -- SOUI�Ի������
	 */
	STDMETHOD_(IHostDialog *, CreateHostDialog)(THIS_ LPCTSTR pszResID DEF_VAL(NULL)) PURE;

	/** CreateStringA
	 * @brief ����IStringA����
	 * @return IStringA * -- �ַ�������
	 */
	STDMETHOD_(IStringA *, CreateStringA)(THIS_ LPCSTR pszSrc) PURE;

	/** CreateStringW
	 * @brief ����IStringW����
	 * @return IStringW * -- �ַ�������
	 */
	STDMETHOD_(IStringW *, CreateStringW)(THIS_ LPCWSTR pszSrc) PURE;

	/** CreateXmlDoc
	 * @brief ����IXmlDoc����
	 * @return IXmlDoc * -- Xml����
	 */
	STDMETHOD_(IXmlDoc *, CreateXmlDoc)(THIS) PURE;

	/** CreateResProvider
	 * @brief ����IResProvider����
	 * @return IResProvider * -- ��Դ������
	 */
	STDMETHOD_(IResProvider*, CreateResProvider)(THIS_ BUILTIN_RESTYPE resType) PURE;

	/** CreateFuncSlot
	 * @brief ����IEvtSlot����
	 * @return IEvtSlot * -- Event Slot����
	 */
	STDMETHOD_(IEvtSlot *, CreateFuncSlot)(THIS_ FunCallback fun, void *ctx) PURE;

	/** CreateMenu
	 * @brief ����Menu����
	 * @return IMenu * -- Menu����
	 */
	STDMETHOD_(IMenu*, CreateMenu)(THIS_  HMENU hMenu DEF_VAL(NULL)) PURE;

	/** CreateMenuEx
	 * @brief ����MenuEx����
	 * @return IMenuEx * -- MenuEx����
	 */
	STDMETHOD_(IMenuEx*,CreateMenuEx)(THIS) PURE;

	/** CreateTimer
	 * @brief ������ʱ������
	 * @return ITimer * -- ��ʱ������
	 */
	STDMETHOD_(ITimer*,CreateTimer)(THIS_ IEvtSlot *pEvtSlot) PURE;
};

SNSEND

#ifdef __cplusplus
typedef SOUI::ISouiFactory * ISouiFactoryPtr;
#else
typedef ISouiFactory * ISouiFactoryPtr;
#endif

EXTERN_C ISouiFactoryPtr SOUI_EXP CreateSouiFactory();
