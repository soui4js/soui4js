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

#define kLogTag "soui4js-host"

SStringT GetDataDir()
{
	#ifdef __APPLE__
	char szBundle[MAX_PATH] = { 0 };
	GetAppleBundlePath(szBundle, MAX_PATH);
	return SStringA().Format(_T("%s/Contents/Resources/data"),szBundle);
	#else
	TCHAR szCurrentDir[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szCurrentDir, sizeof(szCurrentDir));
	LPTSTR lpInsertPos = _tcsrchr(szCurrentDir, _T(PATH_SLASH));
	_tcscpy(lpInsertPos, _T("\0"));
	return szCurrentDir;
	#endif
}

#if !defined(_WIN32) || defined(__MINGW32__)
SStringT GetFontPath(){
	#ifdef __APPLE__
	char szBundle[MAX_PATH] = { 0 };
	GetAppleBundlePath(szBundle, MAX_PATH);
	return SStringA().Format(_T("%s/Contents/Resources/fonts/simsun.ttc"),szBundle);
	#else
	TCHAR szCurrentDir[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szCurrentDir, sizeof(szCurrentDir));
	LPTSTR lpInsertPos = _tcsrchr(szCurrentDir, _T(PATH_SLASH));
	_tcscpy(lpInsertPos, _T("/simsun.ttc"));
	return szCurrentDir;
	#endif	
}
#endif // _WIN32

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
#ifdef _WIN32
		if(render.Find(L"gdi")!=-1)
			bLoaded = comMgr.CreateRender_GDI((IObjRef * *)& pRenderFactory);
		else if(render.Find(L"d2d")!=-1)
			bLoaded = comMgr.CreateRender_D2D((IObjRef**)&pRenderFactory);
		else
			bLoaded = comMgr.CreateRender_Skia((IObjRef**)&pRenderFactory);
#else
		bLoaded = comMgr.CreateRender_GDI((IObjRef * *)& pRenderFactory);
#endif//_WIN32
		SASSERT_FMT(bLoaded, _T("load interface [render] failed!"));
		if(!bLoaded) break;
		SAutoRefPtr<IImgDecoderFactory> pImgDecoderFactory;
		LPCTSTR pszImgDecoderName = NULL;
#ifdef _WIN32
		if (imgDecoder.Find(L"wic") != -1)
			pszImgDecoderName = _T("imgdecoder-wic");
		else if(imgDecoder.Find(L"gdip") != -1)
			pszImgDecoderName = _T("imgdecoder-gdip");
		else if (imgDecoder.Find(L"stb") != -1)
			pszImgDecoderName = _T("imgdecoder-stb");
		else
			pszImgDecoderName = _T("imgdecoder-stb");
#else
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
	SStringT strDataDir = GetDataDir();
	IResProvider* sysResProvider;
	BOOL bLoaded = comMgr.CreateResProvider_ZIP((IObjRef**)&sysResProvider);
	SASSERT_FMT(bLoaded, _T("load interface [%s] failed!"), _T("resprovider_zip"));
	SStringA strPath=SStringA().Format("%s/soui-sys-resource.zip",strDataDir.c_str());
	ZIPRES_PARAM param;
	ZipFile(&param,theApp->GetRenderFactory(),strPath);
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
	SAutoRefPtr<IScriptFactory> pScriptFactory;
	bLoaded = comMgr.CreateScrpit_Qjs((IObjRef * *)& pScriptFactory);
	SASSERT_FMT(bLoaded, _T("load interface [%s] failed!"), _T("scirpt_qjs"));
	theApp->SetScriptFactory(pScriptFactory);
	return bLoaded;
}

int Run(HINSTANCE hInstance, const SStringA &strDir ,const SStringA& jsfile)
{
	HRESULT hRes = OleInitialize(NULL);
	SASSERT(SUCCEEDED(hRes));
	int nRet = 0;
	{
		SouiFactory souiFac;
		SComMgr2 comMgr;
		IApplication* theApp = souiFac.CreateApp(NULL, hInstance);
		if (InitApp(comMgr, theApp))
		{
			LoadSystemRes(theApp, souiFac, comMgr);//load system resource
			LoadScriptModule(theApp, comMgr); //load script module.


			SAutoRefPtr<IScriptModule> script;
			theApp->CreateScriptModule(&script); //create a qjs instance

			if (script->executeScriptFile(strDir + "/" + jsfile))//load qjs script
				nRet = script->executeMain(hInstance, strDir.c_str(), NULL);//execute the main function defined in lua script
			else {
				SStringT msg = SStringT().Format(_T("load js file %s failed!"), S_CA2T(jsfile).c_str());
				MessageBox(0, msg, _T("error"), MB_OK);
				nRet = -1;
			}
		}
		theApp->Release();
	}
	OleUninitialize();
	return nRet;
}

#if defined(_WIN32) && !defined(__MINGW32__)
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpstrCmdLine, int nCmdShow)
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	int argc = 0;
	LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);
	SStringA jsfile = "main.js";//default to run main.js
	SStringW appDir = S_CT2W(GetDataDir());
	SStringW strDir = appDir;
	if (argc > 1)
	{
		strDir = argv[1];
		if (argc > 2)
			jsfile = S_CW2A(argv[2],CP_UTF8);
	}
	LocalFree(argv);
	if (strDir != appDir && strDir.Find(L":")==-1) {
		//receive relative app path.
		strDir.Format(L"%s\\%s", appDir.c_str(), strDir.c_str());
	}
	//strDir = "/home/flyhigh/work/soui4js/build/bin/ws_client";
	SetCurrentDirectoryW(strDir);
	int nRet = Run(hInstance,S_CW2A(strDir,CP_UTF8),jsfile);
	WSACleanup();
	return nRet;
}
#else
int main(int argc, char** argv) {
	for(int i=0;i<argc;i++){
		printf("arg %d=%s\n",i,argv[i]);
	}
	SStringA jsfile = "main.js";//default to run main.js
	SStringA appDir = S_CT2A(GetDataDir());
	SStringT fontPath = GetFontPath();
	AddFontResource(fontPath);
	SStringA strDir = appDir;
	if (argc > 1)
	{
		strDir = argv[1];
		if (argc > 2)
		 	jsfile = argv[2];
	}
	if(strDir != appDir && strDir[0]!='/'){
		//receive relative app path.
		strDir.Format("%s/%s",appDir.c_str(),strDir.c_str());
	}
	SetCurrentDirectoryA(strDir);
	HINSTANCE hInst = GetModuleHandle(NULL);
	return Run(hInst,strDir,jsfile);
}
#endif//_WIN32