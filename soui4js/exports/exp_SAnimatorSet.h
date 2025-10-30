#pragma once
#include "interface/SAnimatorSet-i.h"
#include "interface/SValueAnimator-i.h"
#include "interface/SApp-i.h"
#include "exp_SValueAnimator.h"
#include <valueAnimator/SAnimatorSet.h>


class JsAnimatorSet : public JsValueAnimator {
public:
    JsAnimatorSet() {
        m_animatorSet.Attach(new SAnimatorSet);
        InitAnimator(m_animatorSet);
    }

    ~JsAnimatorSet() {

    }   

    IAnimatorSet* GetIAnimatorSet() {
        return m_animatorSet;
    }

    void AddAnimator(JsValueAnimator* pAnimator) {
        if (!m_animatorSet) return;
        m_animatorSet->AddAnimator(pAnimator->GetIValueAnimator());
    }

    void AddAnimatorAfter(JsValueAnimator* pAnimator, JsValueAnimator* pAfterAnimator) {
        if (!m_animatorSet) return;
        m_animatorSet->AddAnimatorAfter(pAnimator->GetIValueAnimator(), pAfterAnimator->GetIValueAnimator());
    }

    void AddAnimatorWith(JsValueAnimator* pAnimator, JsValueAnimator* pWithAnimator) {
        if (!m_animatorSet) return;
        m_animatorSet->AddAnimatorWith(pAnimator->GetIValueAnimator(), pWithAnimator->GetIValueAnimator());
    }

    void RemoveAnimator(JsValueAnimator* pAnimator) {
        if (!m_animatorSet) return;
        m_animatorSet->RemoveAnimator(pAnimator->GetIValueAnimator());
    }

    void RemoveAllAnimators() {
        if (m_animatorSet) {
            m_animatorSet->RemoveAllAnimators();
        }
    }

    int GetAnimatorCount() {
        if (!m_animatorSet) return 0;
        return m_animatorSet->GetAnimatorCount();
    }

    qjsbind::Value GetAnimatorAt(int index) {
        if (!m_animatorSet) return qjsbind::undefined_value;
		qjsbind::Context* ctx = m_jsThis.context();
		return qjsbind::NewValue(*ctx, m_animatorSet->GetAnimatorAt(index));
    }

    void SetPlayMode(int mode) {
        if (m_animatorSet) {
            m_animatorSet->SetPlayMode((AnimatorSetPlayMode)mode);
        }
    }

    int GetPlayMode() {
        if (!m_animatorSet) return SEQUENCE;
        return m_animatorSet->GetPlayMode();
    }


public:
    const WeakValue& GetJsThis() const override {
        if (m_cbHandler.IsObject())
            return m_cbHandler;
        else
            return JsThisOwner::GetJsThis();
    }

protected:
    SAutoRefPtr<IAnimatorSet> m_animatorSet;
};

void Exp_SAnimatorSet(qjsbind::Module* module) {
    {
        // Export IAnimatorSet as SAnimatorSet
        JsClass<JsAnimatorSet> jsCls = module->ExportClass<JsAnimatorSet>("SAnimatorSet");
        jsCls.Init(JsClass<JsValueAnimator>::class_id());
        jsCls.AddCtor<constructor<JsAnimatorSet>>();
		jsCls.AddFunc("GetIAnimatorSet", &JsAnimatorSet::GetIAnimatorSet);
        jsCls.AddFunc("AddAnimator", &JsAnimatorSet::AddAnimator);
        jsCls.AddFunc("AddAnimatorAfter", &JsAnimatorSet::AddAnimatorAfter);
        jsCls.AddFunc("AddAnimatorWith", &JsAnimatorSet::AddAnimatorWith);
        jsCls.AddFunc("RemoveAnimator", &JsAnimatorSet::RemoveAnimator);
        jsCls.AddFunc("RemoveAllAnimators", &JsAnimatorSet::RemoveAllAnimators);
        jsCls.AddFunc("GetAnimatorCount", &JsAnimatorSet::GetAnimatorCount);
        jsCls.AddFunc("GetAnimatorAt", &JsAnimatorSet::GetAnimatorAt);
        jsCls.AddFunc("SetPlayMode", &JsAnimatorSet::SetPlayMode);
        jsCls.AddFunc("GetPlayMode", &JsAnimatorSet::GetPlayMode);
    }
}