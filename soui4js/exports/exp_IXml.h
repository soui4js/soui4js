#pragma once
#include <interface/Sxml-i.h>

void Exp_IXml(qjsbind::Module* module)
{
	{
		JsClass<IXmlAttr> jsCls = module->ExportClass<IXmlAttr>("IXmlAttr");
		jsCls.Init(JsClass<IObjRef>::class_id());
		jsCls.AddFunc( "GetPrivPtr", &IXmlAttr::GetPrivPtr);
		jsCls.AddFunc( "IsEmpty", &IXmlAttr::Empty);
		jsCls.AddFunc( "Name", &IXmlAttr::Name);
		jsCls.AddFunc( "Value", &IXmlAttr::Value);
		jsCls.AddFunc( "set_userdata", &IXmlAttr::set_userdata);
		jsCls.AddFunc( "get_userdata", &IXmlAttr::get_userdata);

		jsCls.AddFunc("AsInt", &IXmlAttr::AsInt);
		jsCls.AddFunc("AsUint", &IXmlAttr::AsUint);
		jsCls.AddFunc("AsFloat", &IXmlAttr::AsFloat);
		jsCls.AddFunc("AsDouble", &IXmlAttr::AsDouble);
		jsCls.AddFunc("AsBool", &IXmlAttr::AsBool);
	}
	{
		JsClass<IXmlNode> jsCls = module->ExportClass<IXmlNode>("IXmlNode");
		jsCls.Init(JsClass<IObjRef>::class_id());
		jsCls.AddFunc("ToString", &IXmlNode::ToString);
		jsCls.AddFunc("GetPrivPtr", &IXmlNode::GetPrivPtr);
		jsCls.AddFunc("IsEmpty", &IXmlNode::Empty);
		jsCls.AddFunc("Name", &IXmlNode::Name);
		jsCls.AddFunc("Value", &IXmlNode::Value);
		jsCls.AddFunc("set_userdata", &IXmlNode::set_userdata);
		jsCls.AddFunc("get_userdata", &IXmlNode::get_userdata);

		jsCls.AddFunc("AppendChild", &IXmlNode::AppendChild);
		jsCls.AddFunc("PrependChild", &IXmlNode::PrependChild);
		jsCls.AddFunc("AppendCopyNode", &IXmlNode::AppendCopyNode);
		jsCls.AddFunc("PrependCopyNode", &IXmlNode::PrependCopyNode);

		jsCls.AddFunc("AppendAttribute", &IXmlNode::AppendAttribute);
		jsCls.AddFunc("PrependAttribute", &IXmlNode::PrependAttribute);
		jsCls.AddFunc("AppendCopyAttribute", &IXmlNode::AppendCopyAttribute);
		jsCls.AddFunc("PrependCopyAttribute", &IXmlNode::PrependCopyAttribute);

		jsCls.AddFunc("RemoveAttribute", &IXmlNode::RemoveAttribute);
		jsCls.AddFunc("RemoveChild", &IXmlNode::RemoveChild);
		jsCls.AddFunc("RemoveAllChilden", &IXmlNode::RemoveAllChilden);
	}
	{
		JsClass<IXmlDoc> jsCls = module->ExportClass<IXmlDoc>("IXmlDoc");
		jsCls.Init(JsClass<IObjRef>::class_id());
		jsCls.AddFunc( "GetPrivPtr", &IXmlDoc::GetPrivPtr);

		jsCls.AddFunc( "Reset", &IXmlDoc::Reset);
		jsCls.AddFunc( "Copy", &IXmlDoc::Copy);
		jsCls.AddFunc( "LoadString", &IXmlDoc::LoadString);
		jsCls.AddFunc( "LoadFile", &IXmlDoc::LoadFileA);
		jsCls.AddFunc( "LoadBuffer", &IXmlDoc::LoadBuffer);
		jsCls.AddFunc( "LoadBufferInplace", &IXmlDoc::LoadBufferInplace);

		jsCls.AddFunc( "LoadBufferInplaceOwn", &IXmlDoc::LoadBufferInplaceOwn);
		jsCls.AddFunc( "GetParseResult", &IXmlDoc::GetParseResult);
		jsCls.AddFunc( "SaveBinary", &IXmlDoc::SaveBinary);
		jsCls.AddFunc( "SaveFile", &IXmlDoc::SaveFileA);
		jsCls.AddFunc("Root", &IXmlDoc::Root);
	}
}
