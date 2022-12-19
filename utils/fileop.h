#pragma once
namespace fileop
{
	BOOL DelFile(LPCSTR utf8name, BOOL bAllowUndo);
	BOOL DelDir(LPCSTR utf8name, BOOL bAllowUndo);
	BOOL SelectFile(LPCSTR pszFile);
	BOOL JsCopyFile(LPCSTR pszFrom, LPCSTR pszTo, BOOL bReplace);
	BOOL JsCopyDir(LPCSTR pszFrom, LPCSTR pszTo);
}

