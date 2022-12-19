#pragma once
#include "exp_md5.h"
#include "fileop.h"
#include "exp_base64.h"
#include "urlcode.h"
#include "sysapi.h"

using namespace qjsbind;

void Exp_Utils(qjsbind::Module* module)
{
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
}
