#pragma once
#include <interface/SApp-i.h>

BOOL ITranslatorMgr_UninstallTranslator(Context* ctx, ITranslatorMgr* _this, ArgList& args);

BOOL IApplication_UnnstallTranslator(Context* ctx, IApplication* _this, ArgList& args) {
	return ITranslatorMgr_UninstallTranslator(ctx, _this->GetTranslator(), args);
}

BOOL IApplication_InitXmlNamedID(Context* ctx, IApplication* _this, ArgList& args) {
	BOOL bRet = FALSE;
	if (args.size() >= 2) {
		if (args[0].IsArray() && args[1].IsArray()) {
			uint32_t lenName = args[0].length();
			uint32_t lenId = args[1].length();
			if (lenName == lenId) {
				wchar_t (*name)[MAX_NAME] = (wchar_t(*)[MAX_NAME])malloc(sizeof(wchar_t) * lenName * MAX_NAME);
				LPCWSTR* arrNames = new LPCWSTR[lenName];
				int* ids = (int*)malloc(sizeof(int) * lenId);
				for (int i = 0; i < lenId; i++) {
					std::string strName = args[0].GetProperty(i).ToStdString();
					SStringW strWname = S_CA2W(strName.c_str(), CP_UTF8);
					if (strWname.GetLength() < MAX_NAME) {
						wcscpy(name[i], strWname);
					}
					ids[i] = args[1].GetProperty(i).ToInt32();
					arrNames[i] = name[i];
				}
				_this->InitXmlNamedID(arrNames, ids, lenId);
				free(name);
				free(ids);
				free(arrNames);
				bRet = TRUE;
			}
		}
	}
	return bRet;
}

void Exp_IApp(qjsbind::Module* module)
{
	JsClass<IApplication> jsCls = module->ExportClass<IApplication>("IApplication");
	jsCls.Init(JsClass<IObjRef>::class_id());
	jsCls.AddFunc("GetModule", &IApplication::GetModule);

	jsCls.AddFunc("LoadSystemNamedResource", &IApplication::LoadSystemNamedResource);
	jsCls.AddFunc("GetTranslator", &IApplication::GetTranslator);
	jsCls.AddFunc("SetTranslator", &IApplication::SetTranslator);
	jsCls.AddFunc("GetToolTipFactory", &IApplication::GetToolTipFactory);
	jsCls.AddFunc("SetToolTipFactory", &IApplication::SetToolTipFactory);
	jsCls.AddFunc("SetMsgLoopFactory", &IApplication::SetMsgLoopFactory);
	jsCls.AddFunc("GetMsgLoopFactory", &IApplication::GetMsgLoopFactory);
	jsCls.AddFunc("SetLogManager", &IApplication::SetLogManager);
	jsCls.AddFunc("GetLogManager", &IApplication::GetLogManager);
	jsCls.AddFunc("SetAttrStorageFactory", &IApplication::SetAttrStorageFactory);
	jsCls.AddFunc("GetAttrStorageFactory", &IApplication::GetAttrStorageFactory);
	jsCls.AddFunc("Run", &IApplication::Run);
	jsCls.AddFunc("Quit", &IApplication::Quit);

	jsCls.AddFunc("GetMainWnd", &IApplication::GetMainWnd);
	jsCls.AddFunc("AddMsgLoop", &IApplication::AddMsgLoop);
	jsCls.AddFunc("RemoveMsgLoop", &IApplication::RemoveMsgLoop);
	jsCls.AddFunc("GetMsgLoop", &IApplication::GetMsgLoop);
	jsCls.AddFunc("GetResProviderMgr", &IApplication::GetResProviderMgr);
	jsCls.AddFunc("SetRealWndHandler", &IApplication::SetRealWndHandler);
	jsCls.AddFunc("GetRenderFactory", &IApplication::GetRenderFactory);
	jsCls.AddFunc("SetRenderFactory", &IApplication::SetRenderFactory);
	jsCls.AddFunc("SetScriptFactory", &IApplication::SetScriptFactory);
	jsCls.AddCFunc("InitXmlNamedID", &IApplication_InitXmlNamedID);
	jsCls.AddFunc("LoadXmlDocment", &IApplication::LoadXmlDocmentU8);
	jsCls.AddFunc("LoadAnimation", &IApplication::LoadAnimationU8);
	jsCls.AddFunc("LoadValueAnimator", &IApplication::LoadValueAnimatorU8);
	jsCls.AddFunc("LoadImage", &IApplication::LoadImageU8);
	jsCls.AddFunc("LoadTranslator", &IApplication::LoadTranslatorU8);
	jsCls.AddFunc("InstallTranslator", &IApplication::InstallTranslator);
	jsCls.AddCFunc("UninstallTranslator", &IApplication_UnnstallTranslator);

	jsCls.AddFunc("EnableNotifyCenter", &IApplication::EnableNotifyCenter);

	jsCls.AddFunc("CreateObject", &IApplication::CreateObject);
	jsCls.AddFunc("SetCreateObjectCallback", &IApplication::SetCreateObjectCallback);
}
