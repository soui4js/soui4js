#pragma once
#include "exp_md5.h"
#include "fileop.h"
#include "exp_base64.h"
#include "urlcode.h"
#include "sysapi.h"
#include "TextDecoder.h"

using namespace qjsbind;

/*
 手动实现输入输出参数转换时使用下面形式
 */
//Value Test(qjsbind::Context *ctx, ArgList& args) {
//	SLOGI2("test") << args.size();
//	return undefined_value;
//}


void Exp_Utils(qjsbind::Module* module)
{
	//module->ExportFunc("Test", &Test);
	module->ExportFunc("Md5", &Md5);
	module->ExportFunc("FileMd5", &FileMd5);
	module->ExportFunc("FileMd5Ex", &FileMd5Ex);
	module->ExportFunc("DelFile", &fileop::DelFile);
	module->ExportFunc("DelDir", &fileop::DelDir);
	module->ExportFunc("SelectFile", &fileop::SelectFile);
	module->ExportFunc("CopyFile", &fileop::JsCopyFile);
	module->ExportFunc("CopyDir", &fileop::JsCopyDir);

	module->ExportFunc("Base64Decode", &Base64Decode);
	module->ExportFunc("Base64Encode", &Base64Encode);

	module->ExportFunc("UrlDecode", &urldecode);
	module->ExportFunc("UrlEncode", &urlencode);

	module->ExportFunc("PlaySound", &sysapi::JsPlaySound);
	module->ExportFunc("GetModuleFileName", &sysapi::JsGetModuleFileName);
	module->ExportFunc("WString2String", &WString2String);
	module->ExportFunc("String2WString", &String2WString);
	module->ExportFunc("Buffer2String", &Buffer2String);
}
