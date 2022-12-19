#pragma once
#include <helper/SMenu.h>
#include <helper/SMenuEx.h>

void Exp_SMenu(qjsbind::Module* module)
{
	JsClass<SMenu> jsCls = module->ExportClass<SMenu>("SMenu");
	jsCls.Init(JsClass<IMenu>::class_id());
	jsCls.AddCtor<constructor<SMenu>>();
}

void Exp_SMenuEx(qjsbind::Module* module)
{
	JsClass<SMenuEx> jsCls = module->ExportClass<SMenuEx>("SMenuEx");
	jsCls.Init(JsClass<IMenuEx>::class_id());
	jsCls.AddCtor<constructor<SMenuEx>>();
}