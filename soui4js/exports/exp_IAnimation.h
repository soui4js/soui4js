#pragma once
#include <interface/SAnimation-i.h>

void Exp_IAnimation(qjsbind::Module* module)
{
	JsClass<IAnimation> jsCls = module->ExportClass<IAnimation>("IAnimation");
	jsCls.Init(JsClass<IObject>::class_id());
	jsCls.AddFunc( "clone", &IAnimation::clone);
	jsCls.AddFunc( "copy", &IAnimation::copy);
	jsCls.AddFunc( "reset", &IAnimation::reset);
	jsCls.AddFunc( "cancel", &IAnimation::cancel);
	jsCls.AddFunc( "setInterpolator", &IAnimation::setInterpolator);
	jsCls.AddFunc("getInterpolator", &IAnimation::getInterpolator);
	jsCls.AddFunc( "setDuration", &IAnimation::setDuration);
	jsCls.AddFunc( "scaleCurrentDuration", &IAnimation::scaleCurrentDuration);
	jsCls.AddFunc( "setFillBefore", &IAnimation::setFillBefore);
	jsCls.AddFunc( "setFillAfter", &IAnimation::setFillAfter);
	jsCls.AddFunc( "getFillBefore", &IAnimation::getFillBefore);
	jsCls.AddFunc( "getFillAfter", &IAnimation::getFillAfter);
	jsCls.AddFunc( "setStartOffset", &IAnimation::setStartOffset);
	jsCls.AddFunc( "isFillEnabled", &IAnimation::isFillEnabled);
	jsCls.AddFunc( "setFillEnabled", &IAnimation::setFillEnabled);
	jsCls.AddFunc( "setStartTime", &IAnimation::setStartTime);
	jsCls.AddFunc( "start", &IAnimation::start);
	jsCls.AddFunc( "startNow", &IAnimation::startNow);
	jsCls.AddFunc( "setRepeatMode", &IAnimation::setRepeatMode);
	jsCls.AddFunc( "setRepeatCount", &IAnimation::setRepeatCount);
	jsCls.AddFunc( "setZAdjustment", &IAnimation::setZAdjustment);
	jsCls.AddFunc( "getStartTime", &IAnimation::getStartTime);
	jsCls.AddFunc( "getDuration", &IAnimation::getDuration);
	jsCls.AddFunc( "getStartOffset", &IAnimation::getStartOffset);
	jsCls.AddFunc( "getRepeatMode", &IAnimation::getRepeatMode);
	jsCls.AddFunc( "getRepeatCount", &IAnimation::getRepeatCount);
	jsCls.AddFunc( "getZAdjustment", &IAnimation::getZAdjustment);
	jsCls.AddFunc( "setAnimationListener", &IAnimation::setAnimationListener);
	jsCls.AddFunc( "computeDurationHint", &IAnimation::computeDurationHint);
	jsCls.AddFunc( "getTransformation2", &IAnimation::getTransformation2);
	jsCls.AddFunc( "getTransformation", &IAnimation::getTransformation);
	jsCls.AddFunc( "hasStarted", &IAnimation::hasStarted);
	jsCls.AddFunc( "hasEnded", &IAnimation::hasEnded);
	jsCls.AddFunc( "applyTransformation", &IAnimation::applyTransformation);
	jsCls.AddFunc( "hasAlpha", &IAnimation::hasAlpha);
	jsCls.AddFunc( "initialize", &IAnimation::initialize);
	jsCls.AddFunc( "setUserData", &IAnimation::setUserData);
	jsCls.AddFunc( "getUserData", &IAnimation::getUserData);
}
