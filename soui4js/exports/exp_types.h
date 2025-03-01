#ifndef __EXP_TYPES__H__
#define __EXP_TYPES__H__
#include <souistd.h>
using namespace SOUI;

namespace qjsbind {
	template<>
	Value NewValue(Context& context, ISouiFactoryPtr v)
	{
		JSClassID clsId = JsClass<ISouiFactory>::class_id();
		if (clsId != 0) {
			Value obj = context.NewClassObject(clsId);
			auto _v = new JsProxy<ISouiFactory>(v,false);
			SetSafeThis(obj, _v);
			return obj;
		}
		return undefined_value;
	}

	template<>
	Value NewValue(Context& context, ISwndContainer * v){
		return NewValue(context, (void*)v);
	}

	template<>
	Value NewValue(Context& context, MouseClickId v) {
		return NewValue(context, (int)v);
	}

	template<>
	Value NewValue(Context& context, RepeatMode v) {
		return NewValue(context, (int)v);
	}

	template<typename T>
	Value NewSObject(Context& context, T& v) {
		JSClassID clsId = JsClass<T>::class_id();
		Value obj = context.NewClassObject(clsId);
		T* pv = new T(v);
		JsProxy<T>* _v = new JsProxy<T>(pv, true);
		SetSafeThis(obj, _v);
		return obj;
	}

	template<>
	Value NewValue(Context& context,  CRect v)
	{
		return NewSObject(context, v);
	}
	template<>
	Value NewValue(Context& context,  RECT v)
	{
		return NewSObject(context, v);
	}
	template<>
	Value NewValue(Context& context,  CPoint v)
	{
		return NewSObject(context, v);
	}
	template<>
	Value NewValue(Context& context,  POINT v)
	{
		return NewSObject(context, v);
	}

	template<>
	Value NewValue(Context& context, CSize v)
	{
		return NewSObject(context, v);
	}
	template<>
	Value NewValue(Context& context, SIZE v)
	{
		return NewSObject(context, v);
	}

	template<>
	Value NewValue(Context& context, const wchar_t* v) {
		if (!v) {
			v = L"";
		}
		SStringA str = S_CW2A(v, CP_UTF8);
		return Value(context.context(), JS_NewString(context.context(), str.c_str()));
	}
	//--------------------------------------------------
	template<>
	WeakValue::operator SOUI::RepeatMode() const {
		return (SOUI::RepeatMode)ToInt32();
	}

	template<>
	WeakValue::operator SOUI::RequestType() const {
		return (SOUI::RequestType)ToInt32();
	}

	template<>
	WeakValue::operator SOUI::HttpError() const {
		return (SOUI::HttpError)ToInt32();
	}
	template<>
	WeakValue::operator SOUI::DownloadState() const {
		return (SOUI::DownloadState)ToInt32();
	}
	template<>
	WeakValue::operator SOUI::BUILTIN_RESTYPE() const {
		return (SOUI::BUILTIN_RESTYPE)ToInt32();
	}

	template<>
	WeakValue::operator SOUI::SObjectType() const {
		return (SOUI::SObjectType)ToInt32();
	}

	template<>
	WeakValue::operator SOUI::SingletonType() const {
		return (SOUI::SingletonType)ToInt32();
	}

	template<>
	WeakValue::operator SOUI::XmlEncoding() const {
		return (SOUI::XmlEncoding)ToInt32();
	}

	template<>
	WeakValue::operator SOUI::FilterLevel() const {
		return (SOUI::FilterLevel)ToInt32();
	}
	
	template<>
	WeakValue::operator BYTE() const {
		return (BYTE)ToInt32();
	}

	template<>
	WeakValue::operator char() const {
		if(IsNumber())
			return (char)ToInt32();
		if (!IsString())
			return 0;
		size_t len = 0;
		const char* str = JS_ToCStringLen(context_, &len, value_);
		if (len != 1)
			return 0;
		return *str;
	}

	template<>
	WeakValue::operator wchar_t() const {
		if (IsNumber())
			return (wchar_t)ToInt32();
		if (!IsString())
			return 0;
		size_t len = 0;
		const char* str = JS_ToCStringLen(context_, &len, value_);
		if (len > 3)
			return 0;
		wchar_t ret;
		MultiByteToWideChar(CP_UTF8, 0, str, (int)len, &ret, 1);
		return ret;
	}

	template<>
	WeakValue::operator DWORD() const {
		return ToUint32();
	}

	template<>
	WeakValue::operator SStringA() const {
		std::string str = ToStdString();
		return SStringA(str.c_str(), (int)str.length());
	}

	template<>
	void SetValue(SStringA & dst, const Value& src) {
		dst = (LPCSTR)src;
	}
	template<>
	void SetValue(std::string& dst, const Value& src) {
		dst = (LPCSTR)src;
	}
}
#endif // __EXP_TYPES__H__