#ifndef __EXP_ITRANSLATORMGR__H__
#define __EXP_ITRANSLATORMGR__H__
#include <interface/STranslator-i.h>

BOOL ITranslator_tr(Context* ctx, ITranslator* _this, ArgList& args) {
    if (args.size() < 3)
        return FALSE;
    IStringW* src = (IStringW*)args[0];
    IStringW* trCtx = (IStringW*)args[2];
    IStringW* out = (IStringW*)args[3];
    int bufLen = _this->tr(src, trCtx, NULL, 0);
    wchar_t *buf = out->GetBufferSetLength(bufLen);
    _this->tr(src, trCtx, buf, bufLen);
    out->ReleaseBuffer(-1);
    return TRUE;
}

Value ITranslator_guid(Context* ctx, ITranslator* _this, ArgList& args) {
    GUID id = _this->guid();
    return ctx->NewArrayBuffer((const uint8_t*)&id, sizeof(id));
}

BOOL ITranslatorMgr_UninstallTranslator(Context* ctx, ITranslatorMgr* _this, ArgList& args) {
    if (args.size() < 1)
        return FALSE;
    size_t szBuf = 0;
    const uint8_t* buf = args[0].GetArrayBuffer(&szBuf);
    if (szBuf != sizeof(GUID))
        return FALSE;
    GUID id;
    memcpy(&id, buf, sizeof(id));
    return _this->UninstallTranslator(id);
}

void Exp_ITranslator(qjsbind::Module* module)
{
    {
        JsClass<ITranslator> jsCls = module->ExportClass<ITranslator>("ITranslator");
        jsCls.Init(JsClass<IObjRef>::class_id());
        jsCls.AddFunc("Load", &ITranslator::Load);
        jsCls.AddFunc("GetName", &ITranslator::GetNameA);
        jsCls.AddFunc("NameEqual", &ITranslator::NameEqualA);
        jsCls.AddCFunc("guid", &ITranslator_guid);
        jsCls.AddCFunc("tr", &ITranslator_tr);
        jsCls.AddFunc("getFontInfo", &ITranslator::getFontInfo);
    }
    {
        JsClass<ITranslatorMgr> jsCls = module->ExportClass<ITranslatorMgr>("ITranslatorMgr");
        jsCls.Init(JsClass<IObjRef>::class_id());
        jsCls.AddFunc("IsValid", &ITranslatorMgr::IsValid);
        jsCls.AddFunc("SetLanguage", &ITranslatorMgr::SetLanguageA);
        jsCls.AddFunc("GetLanguage", &ITranslatorMgr::GetLanguageA);
        jsCls.AddFunc("CreateTranslator", &ITranslatorMgr::CreateTranslator);
        jsCls.AddFunc("InstallTranslator", &ITranslatorMgr::InstallTranslator);
        jsCls.AddCFunc("UninstallTranslator", &ITranslatorMgr_UninstallTranslator);
        jsCls.AddFunc("tr", &ITranslatorMgr::tr);
    }
}

#endif // __EXP_ITRANSLATORMGR__H__