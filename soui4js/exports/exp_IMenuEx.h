#pragma once
#include <interface/smenuex-i.h>

void Exp_IMenuEx(qjsbind::Module* module)
{
	JsClass<IMenuEx> jsCls = module->ExportClass<IMenuEx>("IMenuEx");
	jsCls.Init(JsClass<IObjRef>::class_id());

	jsCls.AddFunc( "LoadMenu", &IMenuEx::LoadMenuA);
	jsCls.AddFunc( "LoadMenu2", &IMenuEx::LoadMenu2);
	jsCls.AddFunc( "InsertMenu", &IMenuEx::InsertMenu);
	jsCls.AddFunc( "AppendMenu", &IMenuEx::AppendMenu);
	jsCls.AddFunc( "CheckMenuItem", &IMenuEx::CheckMenuItem);
	jsCls.AddFunc( "CheckMenuRadioItem", &IMenuEx::CheckMenuRadioItem);
	jsCls.AddFunc( "DeleteMenu", &IMenuEx::DeleteMenu);
	jsCls.AddFunc( "TrackPopupMenu", &IMenuEx::TrackPopupMenu);
	jsCls.AddFunc( "DestroyMenu", &IMenuEx::DestroyMenu);
	jsCls.AddFunc( "ModifyMenuString", &IMenuEx::ModifyMenuString);
	jsCls.AddFunc( "SetMenuUserData", &IMenuEx::SetMenuUserData);
	jsCls.AddFunc( "GetMenuUserData", &IMenuEx::GetMenuUserData);
	jsCls.AddFunc( "GetContextHelpId", &IMenuEx::GetContextHelpId);
	jsCls.AddFunc( "SetContextHelpId", &IMenuEx::SetContextHelpId);
	jsCls.AddFunc( "GetSubMenu", &IMenuEx::GetSubMenu);

	module->ExportFunc("EndMenuEx", EndMenuEx);
}