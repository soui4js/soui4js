#pragma once
#include <interface/smenu-i.h>


void Exp_IMenu(qjsbind::Module* module)
{
	JsClass<IMenu> jsCls = module->ExportClass<IMenu>("IMenu");
	jsCls.Init(JsClass<IObjRef>::class_id());
	jsCls.AddFunc("Attach", &IMenu::Attach);
	jsCls.AddFunc("Detach", &IMenu::Detach);
	jsCls.AddFunc("GetHMenu", &IMenu::GetHMenu);
	jsCls.AddFunc("LoadMenu", &IMenu::LoadMenuA);
	jsCls.AddFunc("LoadMenu2", &IMenu::LoadMenu2);
	jsCls.AddFunc("SetIconSkin", &IMenu::SetIconSkin);
	jsCls.AddFunc("InsertMenu", &IMenu::InsertMenu);
	jsCls.AddFunc("AppendMenu", &IMenu::AppendMenu);
	jsCls.AddFunc("CheckMenuItem", &IMenu::CheckMenuItem);
	jsCls.AddFunc("CheckMenuRadioItem", &IMenu::CheckMenuRadioItem);
	jsCls.AddFunc("DeleteMenu", &IMenu::DeleteMenu);
	jsCls.AddFunc("TrackPopupMenu", &IMenu::TrackPopupMenu);
	jsCls.AddFunc("DestroyMenu", &IMenu::DestroyMenu);
	jsCls.AddFunc("ModifyMenuString", &IMenu::ModifyMenuString);
	jsCls.AddFunc("SetMenuUserData", &IMenu::SetMenuUserData);
	jsCls.AddFunc("GetMenuUserData", &IMenu::GetMenuUserData);
	jsCls.AddFunc("GetContextHelpId", &IMenu::GetContextHelpId);
	jsCls.AddFunc("SetContextHelpId", &IMenu::SetContextHelpId);
	jsCls.AddFunc("GetSubMenu", &IMenu::GetSubMenu);

}