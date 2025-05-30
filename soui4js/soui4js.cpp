﻿// luaScriptModule.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <event/SEventSlot.h>
#include <string/strcpcvt.h>
#include <commgr2.h>
#ifdef WIN32
#include <Winsock2.h>
//#include <souistd.h>
#pragma comment(lib,"Ws2_32.lib")
#endif
#include "soui4js.h"
using namespace qjsbind;
using namespace SOUI;

extern "C" void soui4js_printer(const char* szLog,int len);

static void Soui4jsLog(const char* tag, const char* pLogStr, int level, const char* file, int line, const char* fun, void* retAddr)
{
    SApplication* theApp = SApplication::getSingletonPtr();
    ILogMgr* pLogMgr = theApp ? theApp->GetLogManager() : NULL;
    BOOL bLog = false;
    if (pLogMgr && pLogMgr->prePushLog(level))
    {
        bLog = pLogMgr->pushLog(level, tag, pLogStr, file, line, fun, retAddr);
    }
    {
        DWORD tid = GetCurrentThreadId();
        int nLen = printf("tid=%u,%s,%s %s %s:%d\n", tid, tag, pLogStr, fun, file, line);
        //flushall();
        fflush(stdout);
    }
}

namespace SOUI
{
    class QjsMsgLoop : public SMessageLoop
    {
        qjsbind::Context* m_ctx;
    public:
        QjsMsgLoop(qjsbind::Context *ctx, IMessageLoop* pParentLoop) :SMessageLoop(pParentLoop),m_ctx(ctx) {
        }

        ~QjsMsgLoop() {
        }

        BOOL WINAPI WaitMsg() override{
            RunIdle();
            if(m_bQuit)
                return FALSE;
            HANDLE handles[MAXIMUM_WAIT_OBJECTS-1] = { 0 };
            int rws = 0, msgs = 0;
            uint32_t waitTime = INFINITE;
            int nObjects = js_prepare_waitlist(m_ctx->context(), handles, MAXIMUM_WAIT_OBJECTS - 1, &rws, &msgs,&waitTime);
            int nRet = MsgWaitForMultipleObjects(nObjects, handles, FALSE, waitTime, QS_ALLINPUT | QS_ALLEVENTS);
            if (nRet == WAIT_TIMEOUT || (nRet >= WAIT_OBJECT_0 && nRet < WAIT_OBJECT_0 + nObjects)) {
                //signal by waitable objects.
                js_handle_waitresult(m_ctx->context(), nRet, rws, msgs);
                return FALSE;
            }
            else {
                return TRUE;
            }
        }
    };

    BOOL ExportSoui(qjsbind::Context* context);

    Soui4Js::Soui4Js(qjsbind::Runtime* pRuntime)
    {
        m_context = new qjsbind::Context(pRuntime);
        m_context->SetLogFunc(soui4js_printer);

        ExportSoui(m_context);
    }


    Soui4Js::~Soui4Js()
    {
        delete m_context;
    }

    LPCSTR Soui4Js::getIdentifierString() const
    {
        return "soui4.script.js";
    }

    IIdleHandler* Soui4Js::getIdleHandler(THIS){
        return NULL;
    }

    BOOL Soui4Js::executeScriptFile( LPCSTR pszScriptFile )
    {
        SStringW str = S_CA2W(pszScriptFile, CP_UTF8);
        FILE* f = _wfopen(str.c_str(), L"rb");
        if (!f) return FALSE;
        fseek(f, 0, SEEK_END);
        long len = ftell(f);
        fseek(f, 0, SEEK_SET);
        char* buf = (char*)malloc(len+1);
        if (!buf) {
            fclose(f);
            return FALSE;
        }
        int nReaded= (int)fread(buf, 1, len, f);
        buf[nReaded] = 0;
        fclose(f);
        Value val;
        if (str.EndsWith(L"bjs")) {
            js_std_eval_binary(m_context->context(), (uint8_t*)buf, nReaded, 0);
        }
        else {
            val = m_context->Eval(buf, nReaded, pszScriptFile, JS_EVAL_TYPE_MODULE);
        }
        free(buf);
        if (val.IsException()) {
            m_context->DumpError();
            return FALSE;
        }
        return TRUE;
    }


    void Soui4Js::executeScriptBuffer( const char* buff, size_t sz )
    {
        m_context->Eval(buff, (int)sz, "<eval>");
    }

    BOOL Soui4Js::executeScriptedEventHandler( LPCSTR handler_name, IEvtArgs *pArg)
    {
        qjsbind::Value global = m_context->Global();
        if (!global.HasProperty(handler_name))
        {
            SLOGE2("qjs_log") << "global this has no object named as "<<handler_name;
            return FALSE;
        }
        qjsbind::Value fun = global.GetProperty(handler_name);
        if (!fun.IsFunction()) {
            SLOGE2("qjs_log") << handler_name <<" is not function in global this";
            return FALSE;
        }
        qjsbind::Value arg = NewValue(*m_context, pArg);
        qjsbind::Value ret = m_context->Call(global, fun, 1, &arg);
        if (ret.IsException()) {
            m_context->DumpError();
            return FALSE;
        }
        return TRUE;
    }

	SComMgr2  g_comMgr;

    static ITaskLoop* CreateTaskLoop() {
        ITaskLoop* pTaskLoop = NULL;
        g_comMgr.CreateTaskLoop((IObjRef**)&pTaskLoop);
        return pTaskLoop;
    }

	int Soui4Js::executeMain(THIS_ HINSTANCE hInst,LPCSTR pszWorkDir, LPCSTR pszArgs)
	{
#ifdef WIN32
        WORD wVersionRequested;
        WSADATA wsaData;
        int err;
        wVersionRequested = MAKEWORD(2, 2);
        err = WSAStartup(wVersionRequested, &wsaData);
#endif // WIN32       

        qjsbind::Value args[3];
        args[0] = NewValue(*m_context, hInst);
        args[1] = NewValue(*m_context, pszWorkDir);
        args[2] = NewValue(*m_context, pszArgs);
        

        SApplication* pApp = SApplication::getSingletonPtr();
        TCHAR szVscDebug[500];
        if(GetEnvironmentVariable(_T("QUICKJS_DEBUG_ADDRESS"),szVscDebug, 500)>0)
            Log::setLogCallback(Soui4jsLog);
        QjsMsgLoop* msgLoop = new QjsMsgLoop(m_context, NULL);
        pApp->AddMsgLoop(msgLoop, TRUE);
        msgLoop->Release();        
        pApp->SetCreateTaskLoopCallback(CreateTaskLoop);
        
        pApp->CreateTaskLoop(1,Normal,TRUE);
        qjsbind::Value ret = m_context->Invoke(m_context->Global(), "main", 3, args);
#ifdef WIN32
        WSACleanup();
#endif // WIN32

        if (ret.IsException())
        {
            m_context->DumpError();
            return -1;
        }
		return ret.ToInt32();
	}

    SScriptFactory::SScriptFactory() {
        m_runtime = new qjsbind::Runtime();
    }

    SScriptFactory::~SScriptFactory() {
        js_set_printer(NULL);
        delete m_runtime;
    }

    HRESULT SScriptFactory::CreateScriptModule( IScriptModule ** ppScriptModule )
    {
        *ppScriptModule= new SOUI::Soui4Js(m_runtime);
        return S_OK;
    }

	namespace SCRIPT_QJS
	{
		BOOL SCreateInstance(IObjRef ** ppScript)
		{
			*ppScript= new SOUI::SScriptFactory;
			return TRUE;
		}
	}
}

EXTERN_C BOOL Soui4Js_SCreateInstance(IObjRef ** ppScript)
{
	return SOUI::SCRIPT_QJS::SCreateInstance(ppScript);
}

//////////////////////////////////////////////////////////////////////////
