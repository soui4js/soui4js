#pragma once
#include <interface/Sxml-i.h>

void Slog(const char*);
namespace qjsbind {
	Value NewValue(Context& context, SXmlNode v)
	{
		JSClassID clsId = JsClass<SXmlNode>::class_id();
		Value obj = context.NewClassObject(clsId);
		JsProxy<SXmlNode>* _v = new JsProxy<SXmlNode>(new SXmlNode(v), true);
		SetSafeThis(obj, _v);
		return obj;
	}
	Value NewValue(Context& context, SXmlAttr v)
	{
		JSClassID clsId = JsClass<SXmlAttr>::class_id();
		Value obj = context.NewClassObject(clsId);
		JsProxy<SXmlAttr>* _v = new JsProxy<SXmlAttr>(new SXmlAttr(v), true);
		SetSafeThis(obj, _v);
		return obj;
	}
}


void Exp_SXml(qjsbind::Module* module)
{
	{
		JsClass<SXmlAttr> jsCls = module->ExportClass<SXmlAttr>("SXmlAttr");
		jsCls.Init(JsClass<IXmlAttr>::class_id());
		jsCls.AddCtor<constructor<SXmlAttr, const SXmlAttr &>>();
		jsCls.AddFunc("Next", &SXmlAttr::next_attribute);
		jsCls.AddFunc("Prev", &SXmlAttr::previous_attribute);
	}
	{
		JsClass<SXmlNode> jsCls = module->ExportClass<SXmlNode>("SXmlNode");
		jsCls.Init(JsClass<IXmlNode>::class_id());
		jsCls.AddCtor<constructor<SXmlNode, const SXmlNode &>>();
		jsCls.AddFunc("Attribute", (SXmlAttr (SXmlNode::*)(const wchar_t *,bool) const) & SXmlNode::attribute);
		jsCls.AddFunc("FirstAttribute", &SXmlNode::first_attribute);
		jsCls.AddFunc("LastAttribute", &SXmlNode::last_attribute);

		jsCls.AddFunc("Child", &SXmlNode::child);
		jsCls.AddFunc("FirstChild", &SXmlNode::first_child);
		jsCls.AddFunc("LastChild", &SXmlNode::last_child);
		jsCls.AddFunc("NextSibling", (SXmlNode (SXmlNode::*)() const) & SXmlNode::next_sibling);
		jsCls.AddFunc("NextSibling2", (SXmlNode(SXmlNode::*)(const wchar_t*,bool) const) & SXmlNode::next_sibling);
		jsCls.AddFunc("PrevSibling", (SXmlNode(SXmlNode::*)() const) & SXmlNode::previous_sibling);
		jsCls.AddFunc("PrevSibling2", (SXmlNode(SXmlNode::*)(const wchar_t*, bool) const) & SXmlNode::previous_sibling);
	}
	{
		JsClass<SXmlDoc> jsCls = module->ExportClass<SXmlDoc>("SXmlDoc");
		jsCls.Init(JsClass<IXmlDoc>::class_id());
		jsCls.AddCtor<constructor<SXmlDoc>>();
		jsCls.AddFunc("Root", &SXmlDoc::root);
	}
}
