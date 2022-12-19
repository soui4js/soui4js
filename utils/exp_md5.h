#pragma once
#include <string>
#include <stdint.h>
#include "md5.h"
//#include <quickjs.h>

std::string MDPrint(unsigned char digest[16])
{
	char szBuf[16 * 2 + 1] = { 0 };
	for (int i = 0; i < 16; i++)
		sprintf(szBuf + 2 * i, "%02x", digest[i]);
	return std::string(szBuf, 32);
}

std::string Md5(const char* buf, int length) {
	unsigned char digest[16];
	MD5_CTX context;
	MD5Init(&context);
	MD5Update(&context, (const unsigned char*)buf, length);
	MD5Final(digest, &context);
	return MDPrint(digest);
}

std::string FileMd5Ex(LPCSTR pszFileName, int64_t maxLen) {
	wchar_t szPath[MAX_PATH];
	if (ERROR_INSUFFICIENT_BUFFER == MultiByteToWideChar(CP_UTF8, 0, pszFileName, -1, szPath, MAX_PATH))
		return "err: file name too long";
	FILE* f = _wfopen(szPath,L"rb");
	std::string ret;
	if (f) {
		unsigned char digest[16];
		unsigned char buf[1024];
		MD5_CTX context;
		MD5Init(&context);
		int64_t pos = 0;
		while (!feof(f))
		{
			if (maxLen > 0 && pos >= maxLen)
				break;
			int nReaded = fread(buf, 1, 1024, f);
			pos += nReaded;
			if (nReaded > 0) {
				MD5Update(&context, buf, nReaded);
			}
			else {
				break;
			}
		}
		fclose(f);
		MD5Final(digest, &context);
		ret = MDPrint(digest);
	}
	return ret;
}

std::string FileMd5(LPCSTR pszFileName) {
	return FileMd5Ex(pszFileName, -1);
}
