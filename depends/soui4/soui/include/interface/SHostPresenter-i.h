#pragma once
#include <interface/shostwnd-i.h>
SNSBEGIN

#undef INTERFACE
#define INTERFACE IHostPresenter
DECLARE_INTERFACE_(IHostPresenter, IObjRef)
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

	STDMETHOD_(void,OnHostCreate)(THIS) PURE;
	STDMETHOD_(void,OnHostDestroy)(THIS) PURE;
	STDMETHOD_(void,OnHostResize)(THIS_ SIZE szHost) PURE;
	STDMETHOD_(void,OnHostPresent)(THIS_ HDC hdc,IRenderTarget *pMemRT,LPCRECT rcDirty,BYTE byAlpha) PURE;
	STDMETHOD_(void,OnHostAlpha)(THIS_ BYTE byAlpha) PURE;
};

SNSEND