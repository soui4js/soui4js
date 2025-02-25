// dui-demo.cpp : main source file
//

#include "stdafx.h"
#define SYS_NAMED_RESOURCE _T("soui-sys-resource.dll")
#include "commgr2.h"
#include <SouiFactory.h>
#ifdef WIN32
#include <Shellapi.h>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Shell32.lib")

#endif // WIN32
#include <resprovider-zip/zipresprovider-param.h>

using namespace SOUI;


void SetDefaultDir()
{
	TCHAR szCurrentDir[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szCurrentDir, sizeof(szCurrentDir));

	LPTSTR lpInsertPos = _tcsrchr(szCurrentDir, _T('/'));
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
#ifdef _WIN32
		if (imgDecoder.Find(L"wic") != -1)
			pszImgDecoderName = _T("imgdecoder-wic");
		else if(imgDecoder.Find(L"png") != -1)
			pszImgDecoderName = _T("imgdecoder-png");
		else if (imgDecoder.Find(L"stb") != -1)
			pszImgDecoderName = _T("imgdecoder-stb");
		else
			pszImgDecoderName = _T("imgdecoder-stb");
#else
		if (imgDecoder.Find(L"wic") != -1)
			pszImgDecoderName = _T("libimgdecoder-wic");
		else if (imgDecoder.Find(L"png") != -1)
			pszImgDecoderName = _T("libimgdecoder-png");
		else if (imgDecoder.Find(L"stb") != -1)
			pszImgDecoderName = _T("libimgdecoder-stb");
		else
			pszImgDecoderName = _T("libimgdecoder-stb");
#endif//_WIN32
		bLoaded = comMgr.CreateImgDecoder((IObjRef * *)& pImgDecoderFactory,pszImgDecoderName);
		SASSERT_FMT(bLoaded, _T("load interface [%s] failed!"), _T("imgdecoder"));
		if(!bLoaded) break;

		pRenderFactory->SetImgDecoderFactory(pImgDecoderFactory);
	}while(false);
	if (!bLoaded)
		return FALSE;
	theApp->SetRenderFactory(pRenderFactory);
	return TRUE;
};

BOOL LoadSystemRes(IApplication *theApp,SouiFactory & souiFac,SComMgr2 & comMgr)
{
	#ifdef _WIN32
	HMODULE hModSysResource = LoadLibrary(SYS_NAMED_RESOURCE);
	if (!hModSysResource)
		return FALSE;
	IResProvider* sysResProvider = souiFac.CreateResProvider(RES_PE);
	sysResProvider->Init((WPARAM)hModSysResource, 0);
	theApp->LoadSystemNamedResource(sysResProvider);
	sysResProvider->Release();
	FreeLibrary(hModSysResource);	
	return TRUE;
	#else

	IResProvider* sysResProvider;
	BOOL bLoaded = comMgr.CreateResProvider_ZIP((IObjRef**)&sysResProvider);
	SASSERT_FMT(bLoaded, _T("load interface [%s] failed!"), _T("resprovider_zip"));

	ZIPRES_PARAM param;
	ZipFile(&param,theApp->GetRenderFactory(),"soui-sys-resource.zip");
	bLoaded = sysResProvider->Init((WPARAM)&param, 0);
	SASSERT(bLoaded);
	if(bLoaded){
		theApp->LoadSystemNamedResource(sysResProvider);
	}
	sysResProvider->Release();
	return bLoaded;
	#endif
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

	SStringA jsfile="main.js";//default to run main.js
#ifdef _WIN32
	SetCurrentDirectoryW(L"D:\\work\\soui4js\\out\\vs2022\\bin\\Debug");
#else
	SetCurrentDirectory("/home/flyhigh/work/soui4js/build/bin64");
#endif//_WIN32
	int nRet = 0;
	{
#if WIN32
		WSADATA wsaData;
		WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif // WIN32

		SouiFactory souiFac;
		SComMgr2 comMgr;
		IApplication* theApp = souiFac.CreateApp(NULL, hInstance);
		if(InitApp(comMgr, theApp))
		{
			LoadSystemRes(theApp, souiFac,comMgr);//load system resource
			LoadScriptModule(theApp, comMgr); //load script module.

			WCHAR szDir[MAX_PATH];
			GetCurrentDirectoryW(MAX_PATH, szDir);
			SStringA strDir = S_CW2A(szDir,CP_UTF8);
			SAutoRefPtr<IScriptModule> script;
			theApp->CreateScriptModule(&script); //create a qjs instance

			if(script->executeScriptFile(strDir+"/"+ jsfile))//load qjs script
				nRet = script->executeMain(hInstance,strDir.c_str(),NULL);//execute the main function defined in lua script
			else {

				MessageBox(0, lpstrCmdLine, _T("error"), MB_OK);
				nRet = -1;
			}
		}
		theApp->Release();
#if WIN32
		WSACleanup();
#endif // WIN32

	}
	OleUninitialize();
	return nRet;
}

#ifndef _WIN32
int main(int argc, char** argv) {
	HINSTANCE hInst = GetModuleHandle(NULL);
	return _tWinMain(hInst, 0, NULL, SW_SHOWNORMAL);
}
#endif//_WIN32