#pragma once

enum {
	Ani_None=0,
	Ani_Int,
	Ani_Float,
	Ani_Color,
	Ani_Point,
	Ani_Size,
	Ani_Rect,
	Ani_Unknown=1000
};

class JsValueAnimator : public JsThisOwner , public IAnimatorListener , public IAnimatorUpdateListener {
public:
	JsValueAnimator() {}

	~JsValueAnimator() {
		if (m_animator) {
			m_animator->removeListener(this);
			m_animator->removeUpdateListener(this);
		}
	}

	void InitAnimator(IValueAnimator* ani) {
		assert(ani);
		if (m_animator) {
			m_animator->removeListener(this);
			m_animator->removeUpdateListener(this);
			m_animator = NULL;
			m_aniType = Ani_Unknown;
		}
		m_animator = ani;
		m_animator->addUpdateListener(this);
		m_animator->addListener(this);
		m_aniType = _GetAniType(m_animator);
	}

	bool CopyFrom(IValueAnimator* ani) {
		if (!ani)
			return false;
		IValueAnimator *ani2 =(ani->clone());
		InitAnimator(ani2);
		ani2->Release();
		return true;
	}

	bool LoadAniamtor(LPCSTR resId) {
		SStringT strId = S_CA2T(resId, CP_UTF8);
		IValueAnimator* ani = SApplication::getSingleton().LoadValueAnimator(strId);
		if (!ani) return FALSE;
		InitAnimator(ani);
		ani->Release();
		return TRUE;
	}

	IValueAnimator* GetIValueAnimator() {
		return m_animator;
	}

	float GetFraction() const {
		if (!m_animator)
			return 0.f;
		return m_animator->getAnimatedFraction();
	}

	int GetAniType() const {
		return m_aniType;
	}

	bool Start(ITimelineHandlersMgr* aniMgr) {
		if (!m_animator)
			return false;
		m_animator->start(aniMgr);
		return true;
	}

	template<typename T>
	bool setRange(T from,T to) {
		return false;
	}

	template<>
	bool setRange(int from, int to) {
		SIntAnimator* ani = sobj_cast<SIntAnimator>(m_animator);
		if (!ani) return false;
		ani->setRange(from, to);
		return true;
	}
	template<>
	bool setRange(float from, float to) {
		SFloatAnimator* ani = sobj_cast<SFloatAnimator>(m_animator);
		if (!ani) return false;
		ani->setRange(from, to);
		return true;
	}
	template<>
	bool setRange(COLORREF from, COLORREF to) {
		SColorAnimator* ani = sobj_cast<SColorAnimator>(m_animator);
		if (!ani) return false;
		ani->setRange(from, to);
		return true;
	}
	template<>
	bool setRange(POINT from, POINT to) {
		SPointAnimator* ani = sobj_cast<SPointAnimator>(m_animator);
		if (!ani) return false;
		ani->setRange(from, to);
		return true;
	}
	template<>
	bool setRange(SIZE from, SIZE to) {
		SSizeAnimator* ani = sobj_cast<SSizeAnimator>(m_animator);
		if (!ani) return false;
		ani->setRange(from, to);
		return true;
	}
	template<>
	bool setRange(RECT from, RECT to) {
		SRectAnimator* ani = sobj_cast<SRectAnimator>(m_animator);
		if (!ani) return false;
		ani->setRange(from, to);
		return true;
	}
protected:
	int _GetAniType(IValueAnimator* ani) const {
		if (!ani)
			return Ani_None;
		if (ani->IsClass(SIntAnimator::GetClassName()))
			return Ani_Int;
		if (ani->IsClass(SFloatAnimator::GetClassName()))
			return Ani_Float;
		if (ani->IsClass(SColorAnimator::GetClassName()))
			return Ani_Color;
		if (ani->IsClass(SPointAnimator::GetClassName()))
			return Ani_Point;
		if (ani->IsClass(SSizeAnimator::GetClassName()))
			return Ani_Size;
		if (ani->IsClass(SRectAnimator::GetClassName()))
			return Ani_Rect;

		return Ani_Unknown;
	}

	template<typename T>
	bool GetValue(T& value) const {
		return false;
	}
	template<>
	bool GetValue(int& value) const {
		SIntAnimator* ani = sobj_cast<SIntAnimator>(m_animator);
		if (!ani)
			return false;
		value = ani->getValue();
		return true;
	}

	template<>
	bool GetValue(float& value) const {
		SFloatAnimator* ani = sobj_cast<SFloatAnimator>(m_animator);
		if (!ani)
			return false;
		value = ani->getValue();
		return true;
	}

	template<>
	bool GetValue(COLORREF& value) const {
		SColorAnimator* ani = sobj_cast<SColorAnimator>(m_animator);
		if (!ani)
			return false;
		value = ani->getValue();
		return true;
	}

	template<>
	bool GetValue(POINT& value) const {
		SPointAnimator* ani = sobj_cast<SPointAnimator>(m_animator);
		if (!ani)
			return false;
		value = ani->getValue();
		return true;
	}

	template<>
	bool GetValue(SIZE& value) const {
		SSizeAnimator* ani = sobj_cast<SSizeAnimator>(m_animator);
		if (!ani)
			return false;
		value = ani->getValue();
		return true;
	}

	template<>
	bool GetValue(RECT& value) const {
		SRectAnimator* ani = sobj_cast<SRectAnimator>(m_animator);
		if (!ani)
			return false;
		value = ani->getValue();
		return true;
	}


	template<typename T>
	Value GetJsValue(Context& ctx) {
		T v;
		if (GetValue(v))
			return NewValue(ctx, v);
		else
			return undefined_value;
	}

protected:
	STDMETHOD_(void, onAnimationStart)(THIS_ IValueAnimator* pAnimator) {
		if (!m_onAnimationStart.IsObject())
			return;
		qjsbind::Context& ctx = *m_onAnimationStart.context();
		qjsbind::Value args[] = {
			NewValue(ctx, JsThisOwner::GetJsThis())
		};
		ctx.Call(GetJsThis(), m_onAnimationStart, ARRAYSIZE(args), args);
	}
	STDMETHOD_(void, onAnimationEnd)(THIS_ IValueAnimator* pAnimator) {
		if (!m_onAnimationEnd.IsObject())
			return;
		qjsbind::Context& ctx = *m_onAnimationEnd.context();
		qjsbind::Value args[] = {
			NewValue(ctx, JsThisOwner::GetJsThis())
		};
		ctx.Call(GetJsThis(), m_onAnimationEnd, ARRAYSIZE(args), args);
	}
	STDMETHOD_(void, onAnimationRepeat)(THIS_ IValueAnimator* pAnimator) {
		if (!m_onAnimationRepeat.IsObject())
			return;
		qjsbind::Context& ctx = *m_onAnimationRepeat.context();
		qjsbind::Value args[] = {
			NewValue(ctx, JsThisOwner::GetJsThis())
		};
		ctx.Call(GetJsThis(), m_onAnimationRepeat, ARRAYSIZE(args), args);
	}

	STDMETHOD_(void, onAnimationUpdate)(THIS_ IValueAnimator* pAnimator) {
		if (!m_onAnimationUpdate.IsObject())
			return;
		qjsbind::Context& ctx = *m_onAnimationUpdate.context();
		Value val=undefined_value;
		switch (m_aniType) {
		case Ani_Int:
			val = GetJsValue<int>(ctx);
			break;
		case Ani_Float:
			val = GetJsValue<float>(ctx);
			break;
		case Ani_Color:
			val = GetJsValue<COLORREF>(ctx);
			break;
		case Ani_Point:
			val = GetJsValue<POINT>(ctx);
			break;
		case Ani_Size:
			val = GetJsValue<SIZE>(ctx);
			break;
		case Ani_Rect:
			val = GetJsValue<RECT>(ctx);
			break;
		}
		qjsbind::Value args[] = {
			NewValue(ctx, JsThisOwner::GetJsThis()),
			val
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
	int   m_aniType;
protected:
	SAutoRefPtr<IValueAnimator> m_animator;
};

class JsAnimatorGroup : public SAnimatorGroup, public JsThisOwner, public IAnimatorGroupListerer {
public:
	JsAnimatorGroup() {
		SetListener(this);
	}

	~JsAnimatorGroup() {
	}

	STDMETHOD_(void, OnAnimatorGroupEnd)(THIS_ IAnimatorGroup* pGroup) {
		if (!m_onAnimatorGroupEnd.IsFunction())
			return;
		qjsbind::Context& ctx = *m_onAnimatorGroupEnd.context();
		qjsbind::Value args[] = {
			NewValue(ctx, JsThisOwner::GetJsThis())
		};
		ctx.Call(GetJsThis(), m_onAnimatorGroupEnd, ARRAYSIZE(args), args);
	}

	const WeakValue& GetJsThis() const override {
		if (m_cbHandler.IsObject())
			return m_cbHandler;
		else
			return JsThisOwner::GetJsThis();
	}


	Value m_cbHandler;
	Value m_onAnimatorGroupEnd;

	static void Mark(JsAnimatorGroup* pThis, JS_MarkFunc* mark_fun) {
		pThis->m_cbHandler.Mark(mark_fun);
		pThis->m_onAnimatorGroupEnd.Mark(mark_fun);
	}
protected:
	std::map<IValueAnimator*, AniState> m_lstAnimator;
};

bool JsValueAnimator_SetRange(Context* ctx, JsValueAnimator* _this, ArgList& args) {
	if (args.size() < 2)
		return false;
	switch (_this->GetAniType()) {
	case Ani_Int:
	{
		int val = args[0];
		int to = args[1];
		return _this->setRange(val,to);
	}
		break;
	case Ani_Float:
	{
		float val = args[0];
		float to = args[1];
		return _this->setRange(val, to);
	}
	break;
	case Ani_Color:
	{
		COLORREF val = args[0].ToUint32();
		COLORREF to = args[1].ToUint32();
		return _this->setRange(val, to);
	}
	break;
	case Ani_Point:
	{
		POINT val = args[0];
		POINT to = args[1];
		return _this->setRange(val, to);
	}
	break;
	case Ani_Size:
	{
		SIZE val = args[0];
		SIZE to = args[1];
		return _this->setRange(val, to);
	}
	break;
	case Ani_Rect:
	{
		RECT val = args[0];
		RECT to = args[1];
		return _this->setRange(val, to);
	}
	break;
	}
	return false;
}


void Exp_SValueAnimator(qjsbind::Module* module) {
	{
		JsClass<JsValueAnimator > jsCls = module->ExportClass<JsValueAnimator>("SValueAnimator");
		jsCls.Init<JsValueAnimator::Mark>();
		jsCls.AddCtor<constructor<JsValueAnimator>>(TRUE);
		jsCls.AddGetSet("cbHandler", &JsValueAnimator::m_cbHandler);
		jsCls.AddGetSet("onAnimationStart", &JsValueAnimator::m_onAnimationStart);
		jsCls.AddGetSet("onAnimationEnd", &JsValueAnimator::m_onAnimationEnd);
		jsCls.AddGetSet("onAnimationRepeat", &JsValueAnimator::m_onAnimationRepeat);
		jsCls.AddGetSet("onAnimationUpdate", &JsValueAnimator::m_onAnimationUpdate);
		jsCls.AddFunc("LoadAniamtor", &JsValueAnimator::LoadAniamtor);
		jsCls.AddFunc("CopyFrom", &JsValueAnimator::CopyFrom);
		jsCls.AddFunc("GetIValueAnimator", &JsValueAnimator::GetIValueAnimator);
		jsCls.AddFunc("GetAniType", &JsValueAnimator::GetAniType);
		jsCls.AddFunc("GetFraction", &JsValueAnimator::GetFraction);
		jsCls.AddFunc("Start", &JsValueAnimator::Start);
		jsCls.AddCFunc("SetRange", JsValueAnimator_SetRange);
	}
	{
		JsClass<JsAnimatorGroup > jsCls = module->ExportClass<JsAnimatorGroup>("SAnimatorGroup");
		jsCls.Init<JsAnimatorGroup::Mark>(JsClass<IAnimatorGroup>::class_id());
		jsCls.AddCtor<constructor<JsAnimatorGroup>>(TRUE);
		jsCls.AddGetSet("cbHandler", &JsAnimatorGroup::m_cbHandler);
		jsCls.AddGetSet("onAnimatorGroupEnd", &JsAnimatorGroup::m_onAnimatorGroupEnd);
	}
}
