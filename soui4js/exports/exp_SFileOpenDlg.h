#pragma once
#include "souidlgs.h"

typedef HRESULT (WINAPI * FunSHCreateItemFromParsingName)(PCWSTR, IBindCtx*, REFIID, void**);

class SFileOpenDlg {
	CShellFileDialog *modernDlg;
	CFileDialog		 *oldDlg;
public:
	SFileOpenDlg():bSave(false),flag(0),  modernDlg(NULL),oldDlg(NULL){

	}

	~SFileOpenDlg() {
		if (modernDlg) {
			delete modernDlg;
		}
		if (oldDlg) {
			delete oldDlg;
		}
	}
	int DoModal() {
		return DoModal2(GetActiveWindow());
	}
	int DoModal2(HWND hOwner) {
		if (!modernDlg)
		{
			delete modernDlg;
			modernDlg = NULL;
		}
		if (oldDlg) {
			delete oldDlg;
			oldDlg = NULL;
		}
		SStringW strExt = S_CA2W(defExt, CP_UTF8);
		SStringW strName = S_CA2W(defName, CP_UTF8);
		std::vector<COMDLG_FILTERSPEC> filters;
		if (filterPairs.empty()) {
			COMDLG_FILTERSPEC all = { L"all files",L"*.*" };
			filters.push_back(all);
		}
		else {
			for (auto & it : filterPairs) {
				COMDLG_FILTERSPEC filter = { it.first.c_str(),it.second.c_str() };
				filters.push_back(filter);
			}
		}

		modernDlg = new CShellFileDialog(bSave,strName.c_str(),flag,strExt.c_str(), &filters[0],filters.size());
		if (!modernDlg->IsNull())
		{
			if (!defaultFolder.IsEmpty()) {
				IShellItem* folderItem = NULL;
				SStringW strDefFolder = S_CA2W(defaultFolder.c_str(), CP_UTF8);
				HMODULE hShell = LoadLibrary(_T("shell32.dll"));
				if (hShell)
				{
					FunSHCreateItemFromParsingName funSHCreateItemFromParsingName = (FunSHCreateItemFromParsingName)GetProcAddress(hShell, "SHCreateItemFromParsingName");
					if(funSHCreateItemFromParsingName &&
						funSHCreateItemFromParsingName(strDefFolder.c_str(), NULL, IID_PPV_ARGS(&folderItem)) == S_OK) {
						modernDlg->GetPtr()->SetFolder(folderItem);
						folderItem->Release();
					}
					FreeLibrary(hShell);
				}
			}
			return modernDlg->DoModal(hOwner);
		}
		else {
			delete modernDlg;
			modernDlg = NULL;

			SStringT strExt2 = S_CW2T(strExt);
			SStringT strName2 = S_CW2T(strName);
			
			SStringW strFilter;
			if (filterPairs.empty()) {
				strFilter=L"All Files(*.*)|*.*|";
			}
			else {
				for (auto it : filterPairs) {
					strFilter += SStringT().Format(L"%s|%s|",it.first.c_str(),it.second.c_str());
				}
			}
			strFilter += L"|";
			SStringW strFilter2 = S_CW2T(strFilter);
			oldDlg = new CFileDialog(bSave, strExt2.c_str(), strName2.c_str(), flag, strFilter2.c_str());
			//if (!defaultFolder.empty());
			return oldDlg->DoModal(hOwner);
		}
	}

	void AddFilter(LPCSTR name, LPCSTR pattern) {
		SStringW nameW = S_CA2W(name, CP_UTF8);
		SStringW patternW = S_CA2W(pattern, CP_UTF8);
		filterPairs.push_back(std::make_pair<wstring, wstring>(nameW.c_str(), patternW.c_str()));
	}

	string GetFilePath() const{
		if (modernDlg) {
			SStringW path;
			modernDlg->GetFilePath(path);
			SStringA pathA = S_CW2A(path, CP_UTF8);
			return string(pathA.c_str(), pathA.GetLength());
		}
		else {
			SStringT path;
			oldDlg->GetFilePath(path);
			SStringA pathA = S_CT2A(path, CP_UTF8);
			return string(pathA.c_str(), pathA.GetLength());
		}
	}

	string GetFileTitle() const {
		if (modernDlg) {
			SStringW path;
			modernDlg->GetFileTitle(path);
			SStringA pathA = S_CW2A(path, CP_UTF8);
			return string(pathA.c_str(), pathA.GetLength());
		}
		else {
			SStringT path = oldDlg->m_szFileTitle;
			SStringA pathA = S_CT2A(path, CP_UTF8);
			return string(pathA.c_str(), pathA.GetLength());
		}
	}
public:
	bool	 bSave;
	SStringA defExt;
	SStringA defName;
	SStringA defaultFolder;
	std::list<std::pair<std::wstring, std::wstring>> filterPairs;
	int		 flag;
};

void Exp_FileOpenDlg(Module* module) {
	JsClass<SFileOpenDlg> jsCls = module->ExportClass<SFileOpenDlg>("SFileOpenDlg");
	jsCls.Init();
	jsCls.AddCtor<constructor<SFileOpenDlg>>();
	jsCls.AddGetSet("isSave", &SFileOpenDlg::bSave);
	jsCls.AddGetSet("defExt", &SFileOpenDlg::defExt);
	jsCls.AddGetSet("defName", &SFileOpenDlg::defName);
	jsCls.AddGetSet("defaultFolder", &SFileOpenDlg::defaultFolder);
	jsCls.AddGetSet("flag", &SFileOpenDlg::flag);
	jsCls.AddFunc("AddFilter", &SFileOpenDlg::AddFilter);
	jsCls.AddFunc("GetFilePath", &SFileOpenDlg::GetFilePath);
	jsCls.AddFunc("GetFileTitle", &SFileOpenDlg::GetFileTitle);
	jsCls.AddFunc("DoModal", &SFileOpenDlg::DoModal);
	jsCls.AddFunc("DoModal2", &SFileOpenDlg::DoModal2);

}