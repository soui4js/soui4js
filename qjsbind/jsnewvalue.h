#ifndef __JSNEWVALUE__H__
#define __JSNEWVALUE__H__
#include "jsvalue.h"
#include "jscontext.h"

namespace qjsbind {

	template<class T>
	class JsClass;

	template<typename T>
	Value NewValue(Context& context, T v)
	{
		return undefined_value;
	}

	template<typename T>
	Value NewValue(Context& context, T* v)
	{
		if (!v) {
			return Value(context.context(), JS_NewUint32(context.context(), (uint32_t)0));
		}
		JSClassID clsId = JsClass<T>::class_id();
		if (clsId != 0) {
			Value obj = context.NewClassObject(clsId);
			JsProxy<T> * _v = new JsProxy<T>(v,false);
			SetSafeThis(obj, _v);
			return obj;
		}
		return NewValue(context,(void*)v);
	}

	template<>
	inline Value NewValue(Context& context, WeakValue v)
	{
		return Value(v);
	}

	template<>
	inline Value NewValue(Context& context, void* v)
	{
#ifdef _WIN64
		return Value(context.context(), JS_NewBigUint64(context.context(), (uint64_t)v));
#else
		return Value(context.context(), JS_NewUint32(context.context(), (uint32_t)(uintptr_t)v));
#endif
	}

	template<>
	inline Value NewValue(Context& context, Value v)
	{
		return Value(context.context(), v.CopyValue(context.context()));
	}

	template<>
	inline Value NewValue(Context& context, wchar_t* v)
	{
		return NewValue(context,(void*)v);
	}
	template<>
	inline Value NewValue(Context& context, char* v)
	{
		//todo:hjx
		return NewValue(context, (void*)v);
	}

	#ifdef _WIN32
	template<>
	inline Value NewValue(Context& context, long v)
	{
		return Value(context.context(), JS_NewInt32(context.context(), v));
	}

	template<>
	inline Value NewValue(Context& context, unsigned long v)
	{
		return Value(context.context(), JS_NewUint32(context.context(), v));
	}
	#endif//_WIN32
	
	template<>
	inline Value NewValue(Context& context, bool v) {
		return Value(context.context(), JS_NewBool(context.context(), v));
	}

	template<>
	inline Value NewValue(Context& context, int32_t v) {
		return Value(context.context(), JS_NewInt32(context.context(), v));
	}

	template<>
	inline Value NewValue(Context& context, uint32_t v) {
		return Value(context.context(), JS_NewUint32(context.context(), v));
	}

	template<>
	inline Value NewValue(Context& context, int64_t v) {
		return Value(context.context(), JS_NewInt64(context.context(), v));
	}

	template<>
	inline Value NewValue(Context& context, uint64_t v) {
		return Value(context.context(), JS_NewBigUint64(context.context(), v));
	}

	template<>
	inline Value NewValue(Context& context, double v) {
		return Value(context.context(), JS_NewFloat64(context.context(), v));
	}

	template<>
	inline Value NewValue(Context& context, float v) {
		return Value(context.context(), JS_NewFloat64(context.context(), (double)v));
	}

	template<>
	inline Value NewValue(Context& context, const char* v) {
		if(!v) {
			v="";
		}
		return Value(context.context(), JS_NewString(context.context(), v));
	}

	template<>
	inline Value NewValue(Context& context, std::string v) {
		return Value(context.context(), JS_NewStringLen(context.context(), v.c_str(), v.length()));
	}

}
#endif // __JSNEWVALUE__H__