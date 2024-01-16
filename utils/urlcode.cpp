#include "stdafx.h"
#include "urlcode.h"

#ifdef __GUN_C__
#define HEX_TO_DEC(ch) \
({ \
	char ret = -1; \
	if (ch >= '0' && ch <= '9') ret = ch - '0'; \
	else if (ch >= 'a' && ch <= 'z') ret = ch - 'a' + 10; \
	else if (ch >= 'A' && ch <= 'Z') ret = ch - 'A' + 10; \
	else ret = -1; \
	ret;\
})
#else
static inline int hex2dec(const char ch)
{
	if (ch >= '0' && ch <= '9') return ch - '0';
	if (ch >= 'a' && ch <= 'z') return ch - 'a' + 10;
	if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 10;
	return -1;
}
#endif

// utf8编码转url编码
std::string urlencode(const char* cszSrc) // 编码
{
	int nLen = strlen(cszSrc);
	size_t i = 0, nIndex = 0;
	const char* reserved = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789"
		"-._~:/?=&";
	const char hex[] = "0123456789ABCDEF";

	size_t j = 0;
	char ch;
	char* pNew = NULL;

	char* lpszDest = (char*)malloc(nLen * 3 * sizeof(char) + 1); // 增加一个长度存储'\0'

	for (i = 0; i < nLen; i++) {
		ch = cszSrc[i];
		if (isalnum(ch) || strchr(reserved, ch) != NULL) {
			lpszDest[nIndex++] = ch;
		}
		else if (ch == ' ') {
			lpszDest[nIndex++] = '+';
		}
		else {
			int tmp = ch;
			if (ch < 0)
				tmp += 256;
			lpszDest[nIndex++] = '%';
			lpszDest[nIndex++] = hex[tmp / 16];
			lpszDest[nIndex++] = hex[tmp % 16];
		}
	}
	std::string ret(lpszDest, nIndex);
	free(lpszDest);
	return ret;
}


// url解码函数
std::string urldecode(const char* pszUrl) // 解码
{
	size_t i = 0, nIndex = 0;
	char ch;
	char* pNew = NULL;

	int nLen = strlen(pszUrl);
	char* lpszDest = (char*)malloc(nLen * sizeof(char));
	memset(lpszDest, '\0', nLen);

	for (i = 0; i < nLen; ++i) {
		ch = pszUrl[i];
		if (ch != '%') {
			lpszDest[nIndex++] = ch;
		}
		else {
			char h = pszUrl[++i];
			char l = pszUrl[++i];

#ifdef __GUN_C__
			int num = (HEX_TO_DEC(h) << 4) | HEX_TO_DEC(l);
#else
			int num = (hex2dec(h) << 4) | hex2dec(l);
#endif
			lpszDest[nIndex++] = num;
		}
	}

	std::string ret(lpszDest, nIndex);
	free(lpszDest);
	return ret;
}
