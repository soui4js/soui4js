#pragma once

enum {
	Ani_None=0,
	Ani_Int,
	Ani_Float,
	Ani_Color,
	Ani_Unknown=1000
};

class JsValueAnimator : public JsThisOwner , public IAnimatorListener , public IAnimatorUpdateListener {
public:
	JsValueAnimator() {}

	BOOL LoadAniamtor(LPCSTR resId) {
		SStringT strId = S_CA2T(resId, CP_UTF8);
		IValueAnimator* ani = SApplication::getSingleton().LoadValueAnimator(strId);
		if (!ani) return FALSE;
		m_animator = ani;
		ani->addUpdateListener(this);
		ani->addListener(this);
		return TRUE;
	}

	IValueAnimator* GetIValueAnimator() {
		return m_animator;
	}
	int GetAniType() const {
		if (!m_animator)
			return Ani_None;
		if (m_animator->IsClass(SIntAnimator::GetClassName()))
			return Ani_Int;
		if (m_animator->IsClass(SFloatAnimator::GetClassName()))
			return Ani_Float;
		if (m_animator->IsClass(SColorAnimator::GetClassName()))
			return Ani_Color;
		return Ani_Unknown;
	}

	float GetFraction() const {
		if (!m_animator)
			return 0.f;
		return m_animator->getAnimatedFraction();
	}
protected:
	STDMETHOD_(void, onAnimationStart)(THIS_ IValueAnimator* pAnimator) {
		if (!m_onAnimationStart.IsObject())
			return;
		qjsbind::Context& ctx = *m_onAnimationStart.context();
		qjsbind::Value args[] = {
			NewValue(ctx, pAnimator)
		};
		ctx.Call(GetJsThis(), m_onAnimationStart, ARRAYSIZE(args), args);
	}
	STDMETHOD_(void, onAnimationEnd)(THIS_ IValueAnimator* pAnimator) {
		if (!m_onAnimationEnd.IsObject())
			return;
		qjsbind::Context& ctx = *m_onAnimationEnd.context();
		qjsbind::Value args[] = {
			NewValue(ctx, pAnimator)
		};
		ctx.Call(GetJsThis(), m_onAnimationEnd, ARRAYSIZE(args), args);

	}
	STDMETHOD_(void, onAnimationRepeat)(THIS_ IValueAnimator* pAnimator) {
		if (!m_onAnimationRepeat.IsObject())
			return;
		qjsbind::Context& ctx = *m_onAnimationRepeat.context();
		qjsbind::Value args[] = {
			NewValue(ctx, pAnimator)
		};
		ctx.Call(GetJsThis(), m_onAnimationRepeat, ARRAYSIZE(args), args);
	}

	STDMETHOD_(void, onAnimationUpdate)(THIS_ IValueAnimator* pAnimator) {
		if (!m_onAnimationUpdate.IsObject())
			return;
		qjsbind::Context& ctx = *m_onAnimationUpdate.context();
		qjsbind::Value args[] = {
			NewValue(ctx, pAnimator)
		};
		ctx.Call(GetJsThis(), m_onAnimationUpdate, ARRAYSIZE(args), args);
	}
public:
	const WeakValue& GetJsThis() const override {
		if (m_cbHandler.IsObject())
			return m_cbHandler;
		else
			return JsThisOwner::GetJsThis();
	}

	static void Mark(JsValueAnimator* pThis, JS_MarkFunc* mark_fun) {
		pThis->m_onAnimationUpdate.Mark(mark_fun);
		pThis->m_onAnimationStart.Mark(mark_fun);
		pThis->m_onAnimationEnd.Mark(mark_fun);
		pThis->m_onAnimationRepeat.Mark(mark_fun);
		pThis->m_cbHandler.Mark(mark_fun);
	}

public:
	Value m_onAnimationStart;
	Value m_onAnimationEnd;
	Value m_onAnimationRepeat;
	Value m_onAnimationUpdate;
	Value m_cbHandler;
protected:
	SAutoRefPtr<IValueAnimator> m_animator;
};


void Exp_SValueAnimator(qjsbind::Module* module) {
	JsClass<JsValueAnimator > jsCls = module->ExportClass<JsValueAnimator>("SValueAnimator");
	jsCls.Init<JsValueAnimator::Mark>();
	jsCls.AddCtor<constructor<JsValueAnimator>>();
	jsCls.AddGetSet("cbHandler", &JsValueAnimator::m_cbHandler);
	jsCls.AddGetSet("onAnimationStart", &JsValueAnimator::m_onAnimationStart);
	jsCls.AddGetSet("onAnimationEnd", &JsValueAnimator::m_onAnimationEnd);
	jsCls.AddGetSet("onAnimationRepeat", &JsValueAnimator::m_onAnimationRepeat);
	jsCls.AddGetSet("onAnimationUpdate", &JsValueAnimator::m_onAnimationUpdate);
	jsCls.AddFunc("LoadAniamtor", &JsValueAnimator::LoadAniamtor);
	jsCls.AddFunc("GetIValueAnimator", &JsValueAnimator::GetIValueAnimator);
	jsCls.AddFunc("GetAniType", &JsValueAnimator::GetAniType);
	jsCls.AddFunc("GetFraction", &JsValueAnimator::GetFraction);
}
