#pragma once
#include "SAttrStorage.h"

void Exp_IAttrStorage(qjsbind::Module* module)
{
	JsClass<JsAttrStorageFactory> jsCls = module->ExportClass<JsAttrStorageFactory>("JsAttrStorageFactory");
	jsCls.Init<JsAttrStorageFactory::Mark>(JsClass<IObjRef>::class_id());
	jsCls.AddCtor<qjsbind::constructor<JsAttrStorageFactory>>();
	jsCls.AddSet("cbHandler", &JsAttrStorageFactory::m_cbHandler);
	jsCls.AddSet("onNeedStorage", &JsAttrStorageFactory::m_onNeedStorage);
}