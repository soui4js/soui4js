#ifndef __EXP_IOBJECT__H__
#define __EXP_IOBJECT__H__
#include <interface/sobject-i.h>

Value IObject_GetAttribute(Context* ctx, IObject* _this, ArgList& args) {
	if (args.size() < 1)
		return undefined_value;
	SStringW attrName = S_CA2W((const char*)args[0],CP_UTF8);
	SStringW strOut;
	if (!_this->GetAttribute(attrName, &strOut))
		return undefined_value;
	SStringA strU8 = S_CW2A(strOut, CP_UTF8);
	return ctx->NewString(strU8, strU8.GetLength());
}

void Exp_IObject(qjsbind::Module* module)
{
	JsClass<IObject> jsCls = module->ExportClass<IObject>("IObject");
	jsCls.Init(JsClass<IObjRef>::class_id());
	jsCls.AddFunc("IsClass", &IObject::IsClass);
	jsCls.AddFunc("GetObjectClass", &IObject::GetObjectClass);
	jsCls.AddFunc("GetObjectType", &IObject::GetObjectType);

	jsCls.AddFunc("GetID", &IObject::GetID);
	jsCls.AddFunc("SetID", &IObject::SetID);
	jsCls.AddFunc("GetName", &IObject::GetNameA);
	jsCls.AddFunc("SetName", &IObject::SetName);

	jsCls.AddFunc("InitFromXml", &IObject::InitFromXml);
	jsCls.AddFunc("SetAttribute", &IObject::SetAttributeA);
	jsCls.AddCFunc("GetAttribute", &IObject_GetAttribute);
	jsCls.AddFunc("SetAttrHandler", &IObject::SetAttrHandler);
}

#endif // __EXP_IOBJECT__H__