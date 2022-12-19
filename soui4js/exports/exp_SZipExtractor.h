#pragma once

BOOL MkPath(const std::string& path, const std::string& root);

class SZipExtractor {
	enum State {
		state_get_count=0,
		state_prog,
		state_result,
	};
public:
	SZipExtractor():m_pResProvider(NULL), m_msgLoop(NULL){
		m_evt = CreateEvent(NULL, FALSE, TRUE, NULL);
	}

	~SZipExtractor() {
		WaitForSingleObject(m_evt, INFINITE);
		CloseHandle(m_evt);
		if(m_msgLoop) m_msgLoop->RemoveTasksForObject(this);
	}

	BOOL Open(BOOL b7Zip, LPCSTR pszPath, LPCSTR pszPsw) {
		if (m_pResProvider)
			return FALSE;
		if (b7Zip) {
			m_pResProvider = Create7ZResProvider(NULL, pszPath, pszPsw);
		}
		else {
			m_pResProvider = CreateZipResProvider(NULL, pszPath, pszPsw);
		}
		return m_pResProvider != NULL;
	}

	void ExtractTo(LPCSTR pszPath) {
		m_msgLoop = SApplication::getSingletonPtr()->GetMsgLoop();
		ITaskLoop* pTaskLoop = SApplication::getSingletonPtr()->GetTaskLoop();
		if (!pTaskLoop) {
			//on error
			_OnExtractCallback(state_result,false,0);
			return;
		}
		std::string strPath(pszPath);
		ResetEvent(m_evt);
		STaskHelper::post(pTaskLoop, this, &SZipExtractor::_ExtractTo, strPath, false);
	}
private:
	static BOOL CALLBACK EnumFileCountCB(LPCTSTR pszFile, LPARAM lp) {
		int* fileCount = (int*)lp;
		(*fileCount)++;
		return TRUE;
	}

	struct ExtractInfo{
		SZipExtractor* pThis;
		SStringT dstPath;
		int iFile;
		int nFileCount;
		BOOL bOK;
	};

	static BOOL CALLBACK EnumFileExtractCB(LPCTSTR pszFile, LPARAM lp) {
		ExtractInfo* info = (ExtractInfo*)lp;
		info->iFile++;
		size_t sz = info->pThis->m_pResProvider->GetRawBufferSize(NULL, pszFile);
		SStringT strFile(pszFile);
		int pos = strFile.ReverseFind('\\');
		if (pos != -1) {
			SStringT path = strFile.Left(pos);
			SStringA pathU8 = S_CT2A(path, CP_UTF8);
			SStringA rootU8 = S_CT2A(info->dstPath, CP_UTF8);
			if (!MkPath(pathU8.c_str(), rootU8.c_str()))
				return FALSE;
		}
		SStringT strTarget = info->dstPath + _T("\\") + pszFile;
		FILE* f = NULL;
		BOOL bOK = FALSE;
		do {
			f= _tfopen(strTarget.c_str(), _T("wb"));
			if (!f) break;
			char* pBuf = (char*)malloc(sz);
			if (!pBuf) break;
			if (!info->pThis->m_pResProvider->GetRawBuffer(NULL, pszFile, pBuf, sz)) {
				free(pBuf);
				break;
			}
			fwrite(pBuf, 1, sz, f);
			free(pBuf);
			bOK = TRUE;
		} while (false);
		if (f) fclose(f);
		info->pThis->OnProg(info->iFile, info->nFileCount);
		info->bOK = bOK;
		return bOK;
	}
	void OnProg(int iFile, int nFileCount) {
		STaskHelper::post(m_msgLoop, this, &SZipExtractor::_OnExtractCallback, state_prog, iFile, nFileCount);
	}

	void _OnExtractCallback(int state, int p1, int p2) {
		if (m_onMsg.IsFunction()) {
			Context* ctx = m_onMsg.context();
			Value args[] = { 
				NewValue(*ctx,state),
				NewValue(*ctx,p1),
				NewValue(*ctx,p2),
			};
			ctx->Call(m_cbHandler, m_onMsg, 3, args);
		}
	}

	void _ExtractTo(const std::string& strPath) {
		//count file size
		int fileCount = 0;
		m_pResProvider->EnumFile(EnumFileCountCB, (LPARAM) & fileCount);
		STaskHelper::post(m_msgLoop, this, &SZipExtractor::_OnExtractCallback,state_get_count, fileCount,0);
		//extract files.
		SStringT strPath2 = S_CA2T(strPath.c_str(),CP_UTF8);

		ExtractInfo info = { this,strPath2,0,fileCount,FALSE};
		m_pResProvider->EnumFile(EnumFileExtractCB, (LPARAM)&info);
		STaskHelper::post(m_msgLoop, this, &SZipExtractor::_OnExtractCallback, state_result, info.bOK,0);
		SetEvent(m_evt);
	}

	IResProvider* m_pResProvider;
	SAutoRefPtr<IMessageLoop> m_msgLoop;
	HANDLE m_evt;
public:
	static void Mark(SZipExtractor* pThis, JS_MarkFunc* mark_fun) {
		pThis->m_cbHandler.Mark(mark_fun);
		pThis->m_onMsg.Mark(mark_fun);
	}

	Value m_cbHandler;
	Value m_onMsg;
};

void Exp_SZipExtractor(Module* module) {
	JsClass< SZipExtractor> jsCls = module->ExportClass<SZipExtractor>("SZipExtractor");
	jsCls.Init<SZipExtractor::Mark>();
	jsCls.AddCtor<constructor<SZipExtractor>>();
	jsCls.AddFunc("Open", &SZipExtractor::Open);
	jsCls.AddFunc("ExtractTo", &SZipExtractor::ExtractTo);
	jsCls.AddGetSet("cbHandler", &SZipExtractor::m_cbHandler);
	jsCls.AddGetSet("onMsg", &SZipExtractor::m_onMsg);
}