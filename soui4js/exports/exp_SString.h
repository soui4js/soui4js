#pragma once
#include <string/sstringa.h>
#include <string/sstringw.h>


SStringW* newStringW(ArgList& args)
{
	if (args.size() == 2)
	{
		SStringA str((const char*)args[0], (int)args[1]);
		return new SStringW(S_CA2W(str, CP_UTF8));
	}
	else {
		SStringA str((const char*)args[0]);
		return new SStringW(S_CA2W(str, CP_UTF8));
	}
}

SStringA* newStringA(ArgList& args)
{
	if (args.size() == 2)
	{
		return new SStringA((const char*)args[0], (int)args[1]);
	}
	else {
		return new SStringA((const char*)args[0]);
	}
}

void Exp_SStringA(qjsbind::Module* module)
{
	JsClass<SStringA> jsCls = module->ExportClass<SStringA>("SStringA");
	jsCls.Init(JsClass<IStringA>::class_id());
	jsCls.AddCtor<newStringA>();
}

void Exp_SStringW(qjsbind::Module* module)
{
	JsClass<SStringW> jsCls = module->ExportClass<SStringW>("SStringW");
	jsCls.Init(JsClass<IStringW>::class_id());
	jsCls.AddCtor<newStringW>();
}
