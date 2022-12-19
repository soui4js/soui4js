//SOUI组件配置

#pragma  once

#include <com-def.h>
#include <string/tstring.h>
#include <commask.h>
#include <com-loader.hpp>

#ifndef SCOM_MASK
#define SCOM_MASK scom_mask_scom_all
#endif 

#define COM_IMGDECODER  _T("imgdecoder-gdip")
#define COM_RENDER_GDI  _T("render-gdi.dll")
#define COM_RENDER_SKIA _T("render-skia.dll")
#define COM_SCRIPT_QJS _T("soui4js.dll")
#define COM_TRANSLATOR _T("translator.dll")
#define COM_LOG4Z   _T("log4z.dll")
#define COM_ZIPRESPROVIDER _T("resprovider-zip.dll")
#define COM_7ZIPRESPROVIDER _T("resprovider-7zip.dll")
#define COM_TASKLOOP _T("taskloop.dll")
#define COM_IPCOBJ _T("SIpcObject.dll")
#define COM_HTTPCLIENT _T("httpclient.dll")


namespace SOUI{

class SComMgr2
{
public:
    SComMgr2(LPCTSTR pszImgDecoder = NULL)
    {
        if(pszImgDecoder) m_strImgDecoder = pszImgDecoder;
        else m_strImgDecoder = COM_IMGDECODER;
    }

	void SetDllPath(const SStringT & strDllPath)
	{
		m_strDllPath = strDllPath;
		if(!m_strDllPath.IsEmpty())
		{
			if(m_strDllPath.Right(1)!=_T("\\"))
			{
				m_strDllPath+=_T("\\");
			}
		}
	}

    BOOL CreateImgDecoder(IObjRef ** ppObj)
    {
        return imgDecLoader.CreateInstance(m_strDllPath+ COM_IMGDECODER,ppObj);
    }
    
    BOOL CreateRender_GDI(IObjRef **ppObj)
    {
        return renderLoader.CreateInstance(m_strDllPath+COM_RENDER_GDI,ppObj);
    }

    BOOL CreateRender_Skia(IObjRef **ppObj)
    {
        return renderLoader.CreateInstance(m_strDllPath+COM_RENDER_SKIA,ppObj);
    }

    BOOL CreateScrpit_Qjs(IObjRef **ppObj)
	{
		return scriptLoader.CreateInstance(m_strDllPath+COM_SCRIPT_QJS,ppObj);
	}

    BOOL CreateTranslator(IObjRef **ppObj)
    {
        return transLoader.CreateInstance(m_strDllPath+COM_TRANSLATOR,ppObj);
    }
    BOOL CreateResProvider_ZIP(IObjRef **ppObj)
    {
        return zipResLoader.CreateInstance(m_strDllPath+COM_ZIPRESPROVIDER,ppObj);
    }

	BOOL CreateResProvider_7ZIP(IObjRef **ppObj)
	{
		return zip7ResLoader.CreateInstance(m_strDllPath+COM_7ZIPRESPROVIDER, ppObj);
	}
	
    BOOL CreateLog4z(IObjRef **ppObj)
    {
        return log4zLoader.CreateInstance(m_strDllPath+COM_LOG4Z,ppObj);
    }

	BOOL CreateTaskLoop(IObjRef **ppObj)
	{
		return taskLoopLoader.CreateInstance(m_strDllPath + COM_TASKLOOP, ppObj);
	}

	BOOL CreateIpcObject(IObjRef **ppObj)
	{
		return ipcLoader.CreateInstance(m_strDllPath + COM_IPCOBJ, ppObj);
	}

	BOOL CreateHttpClient(IObjRef **ppObj)
	{
		return httpClientLoader.CreateInstance(m_strDllPath + COM_HTTPCLIENT, ppObj);
	}
protected:
    //SComLoader实现从DLL的指定函数创建符号SOUI要求的类COM组件。
    SComLoader imgDecLoader;
    SComLoader renderLoader;
    SComLoader transLoader;
    SComLoader scriptLoader;
    SComLoader zipResLoader;
    SComLoader log4zLoader;
    SComLoader zip7ResLoader;
	SComLoader taskLoopLoader;
	SComLoader ipcLoader;
    SComLoader httpClientLoader;

    SStringT m_strImgDecoder;
	SStringT m_strDllPath;
};

}
