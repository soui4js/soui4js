#pragma once
#include "regkey.h"

enum {
	SKEY_ROOT = 0,
	SKEY_USER,
	SKEY_MACHINE,
	SKEY_USERS
};
enum {
	REG_READ = 1,
	REG_WRITE = 2,
};

class SRegKey : soui4js::CRegKey {
	typedef soui4js::CRegKey __baseCls;
public:
	SRegKey() {
	}
	~SRegKey() {
	}
	bool Open(int parent,LPCSTR pszSubKey,int mode) {
		HKEY parents[] = {
			HKEY_CLASSES_ROOT,
			HKEY_CURRENT_USER,
			HKEY_LOCAL_MACHINE,
			HKEY_USERS
		};
		if (parent<0 || parent>SKEY_USERS)
			return false;
		HKEY hParent = parents[parent];
		SStringT strSubKey = S_CA2T(pszSubKey, CP_UTF8);
		REGSAM sam = 0;
		if (mode & REG_READ)
			sam |= KEY_READ;
		if (mode & REG_WRITE)
			sam |= KEY_WRITE;
		return ERROR_SUCCESS == __baseCls::Open(hParent, strSubKey, sam);
	}

	void Close() {
		__baseCls::Close();
	}

	LPCSTR GetStringValue(LPCSTR keyName) {
		SStringT strKey = S_CA2T(keyName, CP_UTF8);
		ULONG nChars = 0;
		__baseCls::QueryStringValue(strKey.c_str(), NULL, &nChars);
		SStringT ret;
		TCHAR* buf = ret.GetBufferSetLength(nChars);
		__baseCls::QueryStringValue(strKey.c_str(), buf, &nChars);
		SStringA retU8 = S_CT2A(ret, CP_UTF8);
		return retU8.c_str();
	}

	bool SetStringValue(LPCSTR key, LPCSTR value) {
		SStringT strKey = S_CA2T(key, CP_UTF8);
		SStringT strValue = S_CA2T(value, CP_UTF8);
		return ERROR_SUCCESS == __baseCls::SetStringValue(strKey, strValue);
	}

	DWORD GetDwordValue(LPCSTR keyName) {
		SStringT strKey = S_CA2T(keyName, CP_UTF8);
		DWORD ret = 0;
		__baseCls::QueryDWORDValue(strKey.c_str(), ret);
		return ret;
	}

	bool SetDwordValue(LPCSTR key, DWORD value) {
		SStringT strKey = S_CA2T(key, CP_UTF8);
		return ERROR_SUCCESS == __baseCls::SetDWORDValue(strKey, value);
	}
};

void Exp_SRegKey(qjsbind::Module* module) {
	JsClass<SRegKey> jsCls = module->ExportClass<SRegKey>("SRegKey");
	jsCls.Init();
	jsCls.AddCtor<constructor<SRegKey>>();
	jsCls.AddFunc("Open", &SRegKey::Open);
	jsCls.AddFunc("Close", &SRegKey::Close);
	jsCls.AddFunc("GetStringValue", &SRegKey::GetStringValue);
	jsCls.AddFunc("SetStringValue", &SRegKey::SetStringValue);
	jsCls.AddFunc("GetDwordValue", &SRegKey::GetDwordValue);
	jsCls.AddFunc("SetDwordValue", &SRegKey::SetDwordValue);
}