// dui-demo.cpp : main source file
//

#include "stdafx.h"
#define SYS_NAMED_RESOURCE _T("soui-sys-resource.dll")
#include "commgr2.h"
#include <SouiFactory.h>
#include <WinSock2.h>
#include <Shellapi.h>

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Shell32.lib")
using namespace SOUI;


void SetDefaultDir()
{
	TCHAR szCurrentDir[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szCurrentDir, sizeof(szCurrentDir));

	LPTSTR lpInsertPos = _tcsrchr(szCurrentDir, _T('\\'));
	_tcscpy(lpInsertPos + 1, _T("\0"));
	SetCurrentDirectory(szCurrentDir);
}

BOOL InitApp(SComMgr2 & comMgr,IApplication *theApp){
	SAutoRefPtr<IRenderFactory> pRenderFactory;
	SXmlDoc xmlConfig;
	SStringW imgDecoder = L"gdip";
	SStringW render = L"skia";
	if (xmlConfig.LoadFileW(L"config.xml", xml_parse_default, enc_auto)) {
		SXmlNode root = xmlConfig.root().child(L"config");
		if (root) {
			imgDecoder = root.child(L"imgDecoder").child_value();
			imgDecoder.MakeLower();
			render = root.child(L"render").child_value();
			render.MakeLower();
		}
	}
	BOOL bLoaded = TRUE;
	do{
		if(render.Find(L"gdi")!=-1)
			bLoaded = comMgr.CreateRender_GDI((IObjRef * *)& pRenderFactory);
		else if(render.Find(L"d2d")!=-1)
			bLoaded = comMgr.CreateRender_D2D((IObjRef**)&pRenderFactory);
		else
			bLoaded = comMgr.CreateRender_Skia((IObjRef**)&pRenderFactory);
		SASSERT_FMT(bLoaded, _T("load interface [render] failed!"));
		if(!bLoaded) break;
		SAutoRefPtr<IImgDecoderFactory> pImgDecoderFactory;
		LPCTSTR pszImgDecoderName = NULL;
		if (imgDecoder.Find(L"wic") != -1)
			pszImgDecoderName = _T("imgdecoder-wic.dll");
		else if(imgDecoder.Find(L"png") != -1)
			pszImgDecoderName = _T("imgdecoder-png.dll");
		else if (imgDecoder.Find(L"stb") != -1)
			pszImgDecoderName = _T("imgdecoder-stb.dll");
		else
			pszImgDecoderName = _T("imgdecoder-gdip.dll");
		bLoaded = comMgr.CreateImgDecoder(pszImgDecoderName,(IObjRef * *)& pImgDecoderFactory);
		SASSERT_FMT(bLoaded, _T("load interface [%s] failed!"), _T("imgdecoder"));
		if(!bLoaded) break;

		pRenderFactory->SetImgDecoderFactory(pImgDecoderFactory);
	}while(false);
	if (!bLoaded)
		return FALSE;
	theApp->SetRenderFactory(pRenderFactory);
	return TRUE;
};

BOOL LoadSystemRes(IApplication *theApp,SouiFactory & souiFac)
{
	HMODULE hModSysResource = LoadLibrary(SYS_NAMED_RESOURCE);
	if (!hModSysResource)
		return FALSE;

	IResProvider* sysResProvider = souiFac.CreateResProvider(RES_PE);
	sysResProvider->Init((WPARAM)hModSysResource, 0);
	theApp->LoadSystemNamedResource(sysResProvider);
	sysResProvider->Release();
	FreeLibrary(hModSysResource);
	return TRUE;
}

BOOL LoadScriptModule(IApplication*theApp,SComMgr2 & comMgr)
{
	BOOL bLoaded =FALSE;
	SAutoRefPtr<IScriptFactory> pScriptLuaFactory;
	bLoaded = comMgr.CreateScrpit_Qjs((IObjRef * *)& pScriptLuaFactory);
	SASSERT_FMT(bLoaded, _T("load interface [%s] failed!"), _T("scirpt_qjs"));
	theApp->SetScriptFactory(pScriptLuaFactory);
	return bLoaded;
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpstrCmdLine, int nCmdShow)
{
	HRESULT hRes = OleInitialize(NULL);
	SASSERT(SUCCEEDED(hRes));
	int argc = 0;
	LPWSTR *argv = CommandLineToArgvW(GetCommandLineW(), &argc);
	SStringA jsfile="main.js";//default to run main.js
	if (argc > 1)
	{
		SetCurrentDirectoryW(argv[1]);
		if (argc > 2)
			jsfile = S_CW2A(argv[2],CP_UTF8);
	}
	else
		SetDefaultDir();
	LocalFree(argv);
	int nRet = 0;
	{
		WSADATA wsaData;
		WSAStartup(MAKEWORD(2, 2), &wsaData);

		SouiFactory souiFac;
		SComMgr2 comMgr;
		IApplication* theApp = souiFac.CreateApp(NULL, hInstance);
		if(InitApp(comMgr, theApp))
		{
			LoadSystemRes(theApp, souiFac);//load system resource
			LoadScriptModule(theApp, comMgr); //load script module.

			TCHAR szDir[MAX_PATH];
			GetCurrentDirectory(MAX_PATH, szDir);
			SStringA strDir = S_CT2A(szDir, CP_UTF8);
			SAutoRefPtr<IScriptModule> script;
			theApp->CreateScriptModule(&script); //create a qjs instance

			if(script->executeScriptFile(strDir+"\\"+ jsfile))//load qjs script
				nRet = script->executeMain(hInstance,strDir.c_str(),NULL);//execute the main function defined in lua script
			else {

				MessageBox(0, lpstrCmdLine, _T("error"), MB_OK);
				nRet = -1;
			}
		}
		theApp->Release();
		WSACleanup();
	}
	OleUninitialize();
	return nRet;
}
