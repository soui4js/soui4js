#include "stdafx.h"
#include "fileop.h"
#include <shellapi.h>
#pragma comment(lib,"shell32.lib")

using namespace SOUI;

namespace fileop {
	BOOL DelDir(LPCSTR pszDir, BOOL bAllowUndo) {
		SStringT strDir = S_CA2T(pszDir, CP_UTF8);
		TCHAR szBuf[MAX_PATH + 1] = { 0 };
		_tcscpy(szBuf, strDir.c_str());
		SHFILEOPSTRUCT fileOp = { 0 };
		fileOp.wFunc = FO_DELETE;
		fileOp.pFrom = szBuf;
		fileOp.fFlags = FOF_NOCONFIRMATION | FOF_SILENT;
		if (bAllowUndo) {
			fileOp.fFlags |= FOF_ALLOWUNDO;
		}
		int nRet = SHFileOperation(&fileOp);
		return nRet==0;
	}

	BOOL DelFile(LPCSTR pszDir, BOOL bAllowUndo) {
		SStringT strDir = S_CA2T(pszDir, CP_UTF8);
		TCHAR szBuf[MAX_PATH + 1] = { 0 };
		_tcscpy(szBuf, strDir.c_str());
		SHFILEOPSTRUCT fileOp = { 0 };
		fileOp.wFunc = FO_DELETE;
		fileOp.pFrom = szBuf;
		fileOp.fFlags = FOF_NOCONFIRMATION | FOF_SILENT | FOF_FILESONLY;
		if (bAllowUndo) {
			fileOp.fFlags |= FOF_ALLOWUNDO;
		}
		int nRet = SHFileOperation(&fileOp);
		return nRet==0;
	}

	BOOL SelectFile(LPCSTR pszFile) {
		SStringT strFile = S_CA2T(pszFile, CP_UTF8);
		SStringT strCmd = SStringT().Format(_T("/select,%s"), strFile.c_str());
		return (int)ShellExecute(NULL, _T("open"), _T("explorer.exe"), strCmd.c_str(), NULL, SW_SHOWNORMAL)>32;
	}

	BOOL JsCopyFile(LPCSTR pszFrom, LPCSTR pszTo,BOOL bReplace) {
		SStringT strFrom = S_CA2T(pszFrom, CP_UTF8);
		SStringT strTo = S_CA2T(pszTo, CP_UTF8);
		return CopyFile(strFrom.c_str(), strTo.c_str(), !bReplace);
	}

	BOOL JsCopyDir(LPCSTR pszFrom, LPCSTR pszTo){
		SStringT strFrom = S_CA2T(pszFrom, CP_UTF8);
		SStringT strTo = S_CA2T(pszTo, CP_UTF8);
		TCHAR szFrom[MAX_PATH + 1] = { 0 };
		TCHAR szTo[MAX_PATH + 1] = { 0 };
		_tcscpy(szFrom, strFrom.c_str());
		_tcscpy(szTo, strTo.c_str());
		SHFILEOPSTRUCT fileOp = { 0 };
		fileOp.wFunc = FO_COPY;
		fileOp.pFrom = szFrom;
		fileOp.pTo = szTo;
		fileOp.fFlags = FOF_NOCONFIRMATION | FOF_SILENT | FOF_NOCONFIRMMKDIR;
		int nRet = SHFileOperation(&fileOp);
		return nRet==0;
	}

}