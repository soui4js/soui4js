#pragma once
#include <matrix/SMatrix.h>

Value IMatrix_Data(Context* ctx, IMatrix* _this, ArgList& args) {
    const IxForm* mtx = _this->Data();
    return ctx->NewArrayBuffer((const uint8_t*)mtx->fMat, 9 * sizeof(float));
}

BOOL SMatrix_setMatrix(Context* ctx, SMatrix* _this, ArgList& args) {
    if (args.size() < 1)
        return FALSE;
    size_t szBuf = 0;
    const float* buf = (const float *)args[0].GetArrayBuffer(&szBuf);
    if (szBuf != sizeof(float)*9)
        return FALSE;
    _this->setMatrix(buf);
    return TRUE;
}

SMatrix* SMatrix_rotate(Context* ctx, SMatrix* _this, ArgList& args) {
    _this->rotate(args[0]);
    return _this;
}

SMatrix* SMatrix_translate(Context* ctx, SMatrix* _this, ArgList& args) {
    _this->translate(args[0],args[1]);
    return _this;
}

SMatrix* SMatrix_scale(Context* ctx, SMatrix* _this, ArgList& args) {
    _this->scale(args[0], args[1]);
    return _this;
}

SMatrix* SMatrix_shear(Context* ctx, SMatrix* _this, ArgList& args) {
    _this->shear(args[0], args[1]);
    return _this;
}

void Exp_SMatrix(qjsbind::Module* module)
{
    {
        JsClass<IMatrix> jsCls = module->ExportClass<IMatrix>("IMatrix");
        jsCls.Init();
        jsCls.AddCFunc("Data", &IMatrix_Data);
        jsCls.AddFunc("reset", &IMatrix::reset);
        jsCls.AddFunc("setIdentity", &IMatrix::setIdentity);
        jsCls.AddFunc("isIdentity", &IMatrix::isIdentity);
        jsCls.AddFunc("setTranslate", &IMatrix::setTranslate);
        jsCls.AddFunc("setScale", &IMatrix::setScale);
        jsCls.AddFunc("setScale2", &IMatrix::setScale2);
        jsCls.AddFunc("setRotate", &IMatrix::setRotate);
        jsCls.AddFunc("setRotate2", &IMatrix::setRotate2);
        jsCls.AddFunc("setSkew", &IMatrix::setSkew);
        jsCls.AddFunc("setSkew2", &IMatrix::setSkew2);
    }
    {
        JsClass<SMatrix> jsCls = module->ExportClass<SMatrix>("SMatrix");
        jsCls.Init(JsClass<IMatrix>::class_id());
        jsCls.AddFunc("getAt", &SMatrix::get);
        jsCls.AddFunc("setAt", &SMatrix::set);
        jsCls.AddFunc("invert", &SMatrix::invert);
        jsCls.AddCFunc("setMatrix", &SMatrix_setMatrix);
        jsCls.AddCFunc("rotate", &SMatrix_rotate);
        jsCls.AddCFunc("translate", &SMatrix_translate);
        jsCls.AddCFunc("scale", &SMatrix_scale);
        jsCls.AddCFunc("shear", &SMatrix_shear);
    }
}
