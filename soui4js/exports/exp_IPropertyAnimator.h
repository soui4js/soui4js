#pragma once
#include "interface/SPropertyAnimator-i.h"
void Exp_IPropertyAnimator(qjsbind::Module* module) {
    {
        JsClass<IPropertyValuesHolder> jsCls = module->ExportClass<IPropertyValuesHolder>("IPropertyValuesHolder");
        jsCls.Init(JsClass<IObjRef>::class_id());
        jsCls.AddFunc("SetPropertyName", &IPropertyValuesHolder::SetPropertyName);
        jsCls.AddFunc("GetPropertyName", &IPropertyValuesHolder::GetPropertyName);
        jsCls.AddFunc("SetIntValues", &IPropertyValuesHolder::SetIntValues);
        jsCls.AddFunc("SetFloatValues", &IPropertyValuesHolder::SetFloatValues);
        jsCls.AddFunc("SetColorRefValues", &IPropertyValuesHolder::SetColorRefValues);
        jsCls.AddFunc("SetByteValues", &IPropertyValuesHolder::SetByteValues);
        jsCls.AddFunc("GetValueType", &IPropertyValuesHolder::GetValueType);
        jsCls.AddFunc("GetValueSize", &IPropertyValuesHolder::GetValueSize);
        jsCls.AddFunc("GetKeyFrameWeights", &IPropertyValuesHolder::GetKeyFrameWeights);
        jsCls.AddFunc("SetKeyFrameWeights", &IPropertyValuesHolder::SetKeyFrameWeights);
        jsCls.AddFunc("GetKeyframeCount", &IPropertyValuesHolder::GetKeyframeCount);
        jsCls.AddFunc("GetAnimatedValue", &IPropertyValuesHolder::GetAnimatedValue);       
    }
    {
        JsClass<IPropertyAnimator> jsCls = module->ExportClass<IPropertyAnimator>("IPropertyAnimator");
        jsCls.Init(JsClass<IValueAnimator>::class_id());
        jsCls.AddFunc("SetTarget", &IPropertyAnimator::SetTarget);
        jsCls.AddFunc("GetTarget", &IPropertyAnimator::GetTarget);
        jsCls.AddFunc("SetPropertyValuesHolder", &IPropertyAnimator::SetPropertyValuesHolder);
        jsCls.AddFunc("SetPropertyValuesHolders", &IPropertyAnimator::SetPropertyValuesHolders);
        jsCls.AddFunc("GetPropertyValuesHolderByName", &IPropertyAnimator::GetPropertyValuesHolderByName);
        jsCls.AddFunc("GetPropertyValuesHolderByIndex", &IPropertyAnimator::GetPropertyValuesHolderByIndex);
        jsCls.AddFunc("GetPropertyValuesHolderCount", &IPropertyAnimator::GetPropertyValuesHolderCount);
    }
}