#pragma once
#include "base64.h"
#include <string>
#include "stdafx.h"
#include <jsvalue.h>
using namespace qjsbind;

std::string Base64Encode(Value &v) {
	size_t szSrc = 0;
	const uint8_t* src = v.GetArrayBuffer(&szSrc);
	if (!src) {
		return"";
	}
	char* buf = new char[BASE64_ENCODE_OUT_SIZE(szSrc)+1];
	int len = (int)base64_encode(src, szSrc, buf);
	std::string ret(buf, len);
	delete[]buf;
	return ret;
}

Value Base64Decode(Value& v) {
	std::string src = v.ToStdString();
	unsigned char* buf = new unsigned char[BASE64_DECODE_OUT_SIZE(src.length())];
	size_t len = (size_t)base64_decode(src.c_str(), src.length(), buf);
	Value ret = v.context()->NewArrayBuffer(buf, len);
	delete[]buf;

	buf = ret.GetArrayBuffer(&len);
	return ret;
}