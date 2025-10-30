#pragma once
#include "interface/SAnimatorSet-i.h"
#include "exp_IValueAnimator.h"
void Exp_IAnimatorSet(qjsbind::Module* module) {
    {
        JsClass<IAnimatorSet> jsCls = module->ExportClass<IAnimatorSet>("IAnimatorSet");
        jsCls.Init(JsClass<IValueAnimator>::class_id());
        jsCls.AddFunc("AddAnimator", &IAnimatorSet::AddAnimator);
        jsCls.AddFunc("AddAnimatorAfter", &IAnimatorSet::AddAnimatorAfter);
        jsCls.AddFunc("AddAnimatorWith", &IAnimatorSet::AddAnimatorWith);
        jsCls.AddFunc("RemoveAnimator", &IAnimatorSet::RemoveAnimator);
        jsCls.AddFunc("RemoveAllAnimators", &IAnimatorSet::RemoveAllAnimators);
        jsCls.AddFunc("GetAnimatorCount", &IAnimatorSet::GetAnimatorCount);
        jsCls.AddFunc("GetAnimatorAt", &IAnimatorSet::GetAnimatorAt);
        jsCls.AddFunc("SetPlayMode", &IAnimatorSet::SetPlayMode);
        jsCls.AddFunc("GetPlayMode", &IAnimatorSet::GetPlayMode);
    }
    
}