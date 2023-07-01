#include <interface/SAnimation-i.h>


void Exp_IValueAnimator(qjsbind::Module* module)
{
	{
		JsClass<IValueAnimator> jsCls = module->ExportClass<IValueAnimator>("IValueAnimator");
		jsCls.Init(JsClass<IObject>::class_id());
		jsCls.AddFunc("setDuration", &IValueAnimator::setDuration);
		jsCls.AddFunc("getDuration", &IValueAnimator::getDuration);
		jsCls.AddFunc("getTotalDuration", &IValueAnimator::getTotalDuration);
		jsCls.AddFunc("setCurrentPlayTime", &IValueAnimator::setCurrentPlayTime);
		jsCls.AddFunc("setCurrentFraction", &IValueAnimator::setCurrentFraction);
		jsCls.AddFunc("getAnimatedFraction", &IValueAnimator::getAnimatedFraction);
		jsCls.AddFunc("getCurrentPlayTime", &IValueAnimator::getCurrentPlayTime);
		jsCls.AddFunc("getStartDelay", &IValueAnimator::getStartDelay);
		jsCls.AddFunc("setStartDelay", &IValueAnimator::setStartDelay);
		jsCls.AddFunc("setRepeatCount", &IValueAnimator::setRepeatCount);
		jsCls.AddFunc("getRepeatCount", &IValueAnimator::getRepeatCount);
		jsCls.AddFunc("setRepeatMode", &IValueAnimator::setRepeatMode);
		jsCls.AddFunc("getRepeatMode", &IValueAnimator::getRepeatMode);
		jsCls.AddFunc("setInterpolator", &IValueAnimator::setInterpolator);
		jsCls.AddFunc("getInterpolator", &IValueAnimator::getInterpolator);
		jsCls.AddFunc("start", &IValueAnimator::start);
		jsCls.AddFunc("end", &IValueAnimator::end);
		jsCls.AddFunc("isRunning", &IValueAnimator::isRunning);
		jsCls.AddFunc("isStarted", &IValueAnimator::isStarted);
		jsCls.AddFunc("reverse", &IValueAnimator::reverse);
		jsCls.AddFunc("clone", &IValueAnimator::clone);
	}
	{
		JsClass<IAnimatorGroup> jsCls = module->ExportClass<IAnimatorGroup>("IAnimatorGroup");
		jsCls.Init(JsClass<IObjRef>::class_id());
		jsCls.AddFunc("AddAnimator", &IAnimatorGroup::AddAnimator);
		jsCls.AddFunc("RemoveAnimator", &IAnimatorGroup::RemoveAnimator);
		jsCls.AddFunc("SetListener", &IAnimatorGroup::SetListener);
	}

}