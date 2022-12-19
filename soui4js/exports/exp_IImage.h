#pragma once
#include <interface/SRender-i.h>


BOOL IBitmapS_Save(Context* ctx, IBitmapS* _this, ArgList& args) {
	if (args.size() < 1)
		return FALSE;
	SStringW strPath = S_CA2W((const char*)args[0], CP_UTF8);
	wchar_t ext[20] = { 0 };
	_wsplitpath(strPath, NULL, NULL, NULL, ext);
	static GUID fmts[] = {
		ImageFormatBMP,
		ImageFormatJPEG,
		ImageFormatPNG,
		ImageFormatGIF,
		ImageFormatTIFF,
		ImageFormatWEBP
	};
	int idx = -1;
	SStringW strExt(ext);
	strExt.MakeLower();
	if (strExt == L"bmp") idx = 0;
	else if (strExt == L"jpg" || strExt == L"jpeg") idx = 1;
	else if (strExt == L"gif") idx = 2;
	else if (strExt == L"tiff") idx = 3;
	else if (strExt == L"webp") idx = 4;
	if (idx == -1)
		return FALSE;
	return _this->Save(strPath, &fmts[idx])==S_OK;
}

void Exp_IImage(Module* module) {
	JsClass<IBitmapS> jsCls = module->ExportClass<IBitmapS>("IBitmapS");
	jsCls.Init(JsClass<IObjRef>::class_id());
	jsCls.AddFunc("Width", &IBitmapS::Width);
	jsCls.AddFunc("Height", &IBitmapS::Height);
	jsCls.AddFunc("Clone", &IBitmapS::Clone);
	jsCls.AddCFunc("Save", &IBitmapS_Save);
}