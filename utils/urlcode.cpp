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


/*
int main()
{
	char str[] = "http://www.baidu.com/s?ie=utf-8&f=8&tn=baidu&wd=��ʱ����";
	char *pUrl = NULL; // �洢url�����׵�ַ
	char *pSrc = NULL; // �洢�����Ԫ���׵�ַ

	printf("����ǰ��%s\n", str);

	urlencode(&pUrl, str, strlen(str)); // ����
	printf("�����%s\n", pUrl);

	urldecode(&pSrc, pUrl, strlen(pUrl)); // ����
	printf("�����%s\n", pSrc);

	if (pUrl)
		free(pUrl); // �ͷ��ڴ�
	if (pSrc)
		free(pSrc); // �ͷ��ڴ�
	_getch();
	return 0;
}
*/

// GB2312����תurl����
std::string urlencode(const char* cszSrc, size_t nLen) // ����
{
	size_t i = 0, nIndex = 0;
	size_t len = nLen;
	char hex[] = "0123456789ABCDEF";
	char ch;
	char* pNew = NULL;

	char * lpszDest = (char *)malloc(nLen *3 * sizeof(char) + 1); // ����һ�����ȴ洢'\0'

	for (i = 0; i < nLen; i++) {
		ch = cszSrc[i];
		if ((ch >= '0' && ch <= '9') ||
			(ch >= 'a' && ch <= 'z') ||
			(ch >= 'A' && ch <= 'Z') ||
			ch == '-' || ch == '_' || ch == '.' || ch == '~') {
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


// url���뺯��
std::string urldecode(const char* pszUrl, size_t nLen) // ����
{
	size_t i = 0, nIndex = 0;
	char ch;
	char* pNew = NULL;

	char *lpszDest = (char *)malloc(nLen * sizeof(char));
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
