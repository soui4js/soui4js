#pragma once
#include <interface/SResProviderMgr-i.h>

void Exp_IResProviderMgr(qjsbind::Module* module)
{
	JsClass<IResProviderMgr> jsCls = module->ExportClass<IResProviderMgr>("IResProviderMgr");
	jsCls.Init(JsClass<IObjRef>::class_id());

	jsCls.AddFunc("AddResProvider", &IResProviderMgr::AddResProviderA);
	jsCls.AddFunc("RemoveResProvider", &IResProviderMgr::RemoveResProvider);
	jsCls.AddFunc("RemoveAll", &IResProviderMgr::RemoveAll);
	jsCls.AddFunc("GetHeadResProvider", &IResProviderMgr::GetHeadResProvider);
	jsCls.AddFunc("GetTailResProvider", &IResProviderMgr::GetTailResProvider);
	jsCls.AddFunc("SetFilePrefix", &IResProviderMgr::SetFilePrefix);


	jsCls.AddFunc("HasResource", &IResProviderMgr::HasResource);
	jsCls.AddFunc("LoadIcon", &IResProviderMgr::LoadIcon);
	jsCls.AddFunc("LoadBitmap", &IResProviderMgr::LoadBitmap);
	jsCls.AddFunc("LoadCursor", &IResProviderMgr::LoadCursor);
	jsCls.AddFunc("LoadImage", &IResProviderMgr::LoadImage);
	jsCls.AddFunc("LoadImgX", &IResProviderMgr::LoadImgX);
	jsCls.AddFunc("GetRawBufferSize", &IResProviderMgr::GetRawBufferSize);
	jsCls.AddFunc("GetRawBuffer", &IResProviderMgr::GetRawBuffer);
}
