#pragma once
#include <shellapi.h>

class SDropTarget :public IDropTarget
{
public:
	SDropTarget():m_hdrop(NULL),nRef(1)
	{
	}

	virtual ~SDropTarget() {}

	//////////////////////////////////////////////////////////////////////////
	// IUnknown
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(
		/* [in] */ REFIID riid,
		/* [iid_is][out] */  void __RPC_FAR* __RPC_FAR* ppvObject)
	{
		HRESULT hr = S_FALSE;
		if (riid == __uuidof(IUnknown))
			*ppvObject = (IUnknown*)this, hr = S_OK;
		else if (riid == __uuidof(IDropTarget))
			*ppvObject = (IDropTarget*)this, hr = S_OK;
		if (SUCCEEDED(hr)) AddRef();
		return hr;
	}

	virtual ULONG STDMETHODCALLTYPE AddRef(void) { return ++nRef; }

	virtual ULONG STDMETHODCALLTYPE Release(void) {
		ULONG uRet = --nRef;
		if (uRet == 0) delete this;
		return uRet;
	}

	//////////////////////////////////////////////////////////////////////////
	// IDropTarget

	virtual HRESULT STDMETHODCALLTYPE DragEnter(
		/* [unique][in] */  IDataObject* pDataObj,
		/* [in] */ DWORD grfKeyState,
		/* [in] */ POINTL pt,
		/* [out][in] */  DWORD* pdwEffect)
	{
		*pdwEffect = DROPEFFECT_LINK;
		return S_OK;
	}

	virtual HRESULT STDMETHODCALLTYPE DragOver(
		/* [in] */ DWORD grfKeyState,
		/* [in] */ POINTL pt,
		/* [out][in] */  DWORD* pdwEffect)
	{
		*pdwEffect = DROPEFFECT_LINK;
		return S_OK;
	}

	virtual HRESULT STDMETHODCALLTYPE DragLeave(void)
	{
		return S_OK;
	}

	virtual HRESULT STDMETHODCALLTYPE Drop(
		/* [unique][in] */  IDataObject* pDataObj,
		/* [in] */ DWORD grfKeyState,
		/* [in] */ POINTL pt,
		/* [out][in] */  DWORD* pdwEffect)
	{
		FORMATETC format =
		{
			CF_HDROP, 0, DVASPECT_CONTENT, -1, TYMED_HGLOBAL
		};
		STGMEDIUM medium;
		if (FAILED(pDataObj->GetData(&format, &medium)))
		{
			return S_FALSE;
		}

		m_hdrop = static_cast<HDROP>(GlobalLock(medium.hGlobal));

		if (!m_hdrop)
		{
			return S_FALSE;
		}

		if (m_onDrop.IsFunction()) {
			Context* ctx = m_onDrop.context();
			int nFiles = DragQueryFile(m_hdrop, -1, NULL, 0); 
			Value args[1] = { NewValue(*ctx,nFiles) };
			ctx->Call(m_cbHandler, m_onDrop, 1, args);
		}
		DragFinish(m_hdrop);
		m_hdrop = NULL;
		GlobalUnlock(medium.hGlobal);

		*pdwEffect = DROPEFFECT_LINK;
		return S_OK;
	}


	BOOL GetDropFileName(int iFile, IStringA* out) {
		if (!m_hdrop)
			return FALSE;
		int cnt = DragQueryFile(m_hdrop, -1, NULL, 0);
		if (iFile < 0 || iFile >= cnt)
			return FALSE;
		int bufSize = DragQueryFile(m_hdrop, iFile, NULL, 0);
		SStringT strBuf;
		TCHAR* buf = strBuf.GetBufferSetLength(bufSize);
		DragQueryFile(m_hdrop, iFile, buf, bufSize + 1);
		strBuf.ReleaseBuffer();
		SStringA bufA = S_CT2A(strBuf, CP_UTF8);
		out->Copy(&bufA);
		return TRUE;
	}

	static void Mark(SDropTarget* pThis, JS_MarkFunc* mark_fun) {
		pThis->m_cbHandler.Mark(mark_fun);
		pThis->m_onDrop.Mark(mark_fun);
	}
protected:
	int nRef;

	HDROP m_hdrop;
public:
	Value m_cbHandler;
	Value m_onDrop;
};


void Exp_SDropTarget(qjsbind::Module* module) {
	{
		JsClass<SDropTarget> jsCls = module->ExportClass<SDropTarget>("SDropTarget");
		jsCls.Init<SDropTarget::Mark>();
		jsCls.AddCtor<constructor< SDropTarget>>();
		jsCls.AddFunc("GetDropFileName", &SDropTarget::GetDropFileName);
		jsCls.AddGetSet("cbHandler", &SDropTarget::m_cbHandler);
		jsCls.AddGetSet("onDrop", &SDropTarget::m_onDrop);
	}
}
