#ifndef __EXP_SSTRING__H__
#define __EXP_SSTRING__H__
#include <string/sstringa.h>
#include <string/sstringw.h>


SStringW* newStringW(ArgList& args)
{
	if (args.size() == 2)
	{
		SStringA str((const char*)args[0], (int)args[1]);
		return new SStringW(S_CA2W(str, CP_UTF8));
	}
	else if(args.size()==1){
		SStringA str((const char*)args[0]);
		return new SStringW(S_CA2W(str, CP_UTF8));
	}else{
		return new SStringW();
	}
}

SStringA* newStringA(ArgList& args)
{
	if (args.size() == 2)
	{
		return new SStringA((const char*)args[0], (int)args[1]);
	}
	else if(args.size()==1){
		return new SStringA((const char*)args[0]);
	}else{
		return new SStringA();
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

#endif // __EXP_SSTRING__H__