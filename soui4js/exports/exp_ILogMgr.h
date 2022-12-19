#pragma once
#include <interface/slog-i.h>

class JsLogFileBuilder : public TObjRefImpl<IOutputFileBuilder>, JsThisOwner{
public:
	JsLogFileBuilder() {}

	const WeakValue& GetJsThis() const override {
		if (m_cbHandler.IsObject())
			return m_cbHandler;
		else
			return JsThisOwner::GetJsThis();
	}

	//生成LOG文件名
	//至少应该包含pszLogName，及curFileIndex这两个参数
	STDMETHOD_(BOOL, buildOutputFile)
		(CTHIS_ char* pszFileName, int nLen, const char* pszLogName, unsigned long pid, int curFileIndex) SCONST {
		if (!m_funBuildOutputFile.IsFunction())
			return FALSE;
		Context* ctx = m_funBuildOutputFile.context();
		Value args[] = {
			NewValue(*ctx,pszLogName),
			NewValue(*ctx,pid),
			NewValue(*ctx,curFileIndex)
		};
		Value ret = ctx->Call(GetJsThis(), m_funBuildOutputFile, ARRAYSIZE(args), args);
		if (!ret.IsString())
			return FALSE;
		std::string str = ret.ToStdString();
		if (str.length() >= (size_t)nLen)
			return FALSE;
		strcpy(pszFileName, str.c_str());
		return TRUE;

	}

	static void Mark(JsLogFileBuilder* pThis, JS_MarkFunc *markFun) {
		pThis->m_cbHandler.Mark(markFun);
		pThis->m_funBuildOutputFile.Mark(markFun);
	}

	Value m_cbHandler;
	Value m_funBuildOutputFile;
};

void Exp_ILogMgr(Module* module) {
	{
		JsClass<ILogMgr> jsCls = module->ExportClass<ILogMgr>("ILogMgr");
		jsCls.Init(JsClass<IObjRef>::class_id());
		jsCls.AddFunc("config", &ILogMgr::config);
		jsCls.AddFunc("configFromString", &ILogMgr::configFromString);
		jsCls.AddFunc("start", &ILogMgr::start);
		jsCls.AddFunc("stop", &ILogMgr::stop);
		jsCls.AddFunc("isLoggerEnable", &ILogMgr::isLoggerEnable);
		jsCls.AddFunc("enableLogger", &ILogMgr::enableLogger);
		jsCls.AddFunc("setLoggerName", &ILogMgr::setLoggerName);
		jsCls.AddFunc("setLoggerPath", &ILogMgr::setLoggerPath);
		jsCls.AddFunc("setLoggerLevel", &ILogMgr::setLoggerLevel);
		jsCls.AddFunc("setLoggerFileLine", &ILogMgr::setLoggerFileLine);
		jsCls.AddFunc("setLoggerDisplay", &ILogMgr::setLoggerDisplay);
		jsCls.AddFunc("setLoggerOutFile", &ILogMgr::setLoggerOutFile);
		jsCls.AddFunc("setLoggerLimitsize", &ILogMgr::setLoggerLimitsize);
		jsCls.AddFunc("setOutputFileBuilder", &ILogMgr::setOutputFileBuilder);
	}
	{
		JsClass<JsLogFileBuilder> jsCls = module->ExportClass<JsLogFileBuilder>("JsLogFileBuilder");
		jsCls.Init<JsLogFileBuilder::Mark>(JsClass<IObjRef>::class_id());
		jsCls.AddCtor<constructor<JsLogFileBuilder>>(TRUE);
		jsCls.AddGetSet("cbHandler",&JsLogFileBuilder::m_cbHandler);
		jsCls.AddGetSet("onBuildOutputFile", &JsLogFileBuilder::m_funBuildOutputFile);
	}
}