#pragma once
#include <interface/SResProvider-i.h>

void Exp_IResProvider(qjsbind::Module* module)
{
	JsClass<IResProvider> jsCls = module->ExportClass<IResProvider>("IResProvider");
	jsCls.Init(JsClass<IObjRef>::class_id());
	jsCls.AddFunc("Init", &IResProvider::Init);
	jsCls.AddFunc("HasResource", &IResProvider::HasResource);
	jsCls.AddFunc("LoadIcon", &IResProvider::LoadIcon);
	jsCls.AddFunc("LoadBitmap", &IResProvider::LoadBitmap);
	jsCls.AddFunc("LoadCursor", &IResProvider::LoadCursor);
	jsCls.AddFunc("LoadImage", &IResProvider::LoadImage);
	jsCls.AddFunc("LoadImgX", &IResProvider::LoadImgX);
	jsCls.AddFunc("GetRawBufferSize", &IResProvider::GetRawBufferSize);
	jsCls.AddFunc("GetRawBuffer", &IResProvider::GetRawBuffer);
	jsCls.AddFunc("EnumResource", &IResProvider::EnumResource);
}
