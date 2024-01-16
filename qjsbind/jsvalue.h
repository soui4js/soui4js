#pragma once
extern "C" {
#include <quickjs.h>
#include <quickjs-libc.h>
}
#include <map>
#include "jsproxy.h"

namespace qjsbind {

#define QJS_DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&) ;          \
  TypeName& operator=(const TypeName&)

	class Value;
	class Context;

	//弱引用值
	class WeakValue {
	public:
		WeakValue()
			:context_(nullptr), value_(JS_UNDEFINED)
		{
		}

		WeakValue(JSContext* ctx)
			:context_(ctx), value_(JS_UNDEFINED)
		{
		}

		WeakValue(JSContext* ctx, const JSValueConst& value)
			:context_(ctx), value_(value)
		{
		}

		WeakValue(const WeakValue& value)
			:context_(value.context_),
			value_(value.value_)
		{
		}

		WeakValue& operator=(const WeakValue& value) {
			context_ = value.context_;
			value_ = value.value_;
			return *this;
		}

		operator JSValue() const {
			return value_;
		}

		int tag() {
			return JS_VALUE_GET_TAG(value_);
		}


		Context* context() const {
			return reinterpret_cast<Context*>(
				JS_GetContextOpaque(context_));
		}

		bool IsNumber() const {
			return JS_IsNumber(value_)!=0;
		}

		bool IsBigInt() const {
			return JS_IsBigInt(context_, value_) != 0;
		}

		bool IsBigFloat() const {
			return JS_IsBigFloat(value_) != 0;
		}

		bool IsBigDecimal() const {
			return JS_IsBigDecimal(value_) != 0;
		}

		bool IsBool() const {
			return JS_IsBool(value_) != 0;
		}

		bool IsNull() const {
			return JS_IsNull(value_) != 0;
		}

		bool IsUndefined() const {
			return JS_IsUndefined(value_) != 0;
		}

		bool IsException() const {
			return JS_IsException(value_) != 0;
		}

		bool IsUninitialized() const {
			return JS_IsUninitialized(value_) != 0;
		}

		bool IsString() const {
			return JS_IsString(value_) != 0;
		}

		bool IsSymbol() const {
			return JS_IsSymbol(value_) != 0;
		}

		bool IsObject() const {
			return JS_IsObject(value_) != 0;
		}

		bool IsArray() const {
			return JS_IsArray(context_, value_) != 0;
		}

		bool IsArrayBuffer() const {
			return JS_IsArrayBuffer(context_, value_) != 0;
		}

		bool IsFunction()const {
			if (!context_) return false;
			return JS_IsFunction(context_, value_) != 0;
		}

		bool ToBool() const {
			return JS_ToBool(context_, value_) == 1;
		}

		bool IsError() const {
			return JS_IsError(context_, value_) != 0;
		}

		int32_t ToInt32() const {
			int32_t value = 0;
			if (JS_IsBigInt(context_, value_))
			{
				int64_t value64;
				JS_ToInt64(context_, &value64, value_);
				value = (int32_t)value64;
				return value;
			}
			else
			{
				JS_ToInt32(context_, &value, value_);
				return value;
			}
		}

		operator int32_t() const {
			return ToInt32();
		}

		operator short() const {
			return (short)ToInt32();
		}

		uint32_t ToUint32() const {
			uint32_t value = 0;
			if (JS_IsBigInt(context_, value_))
			{
				int64_t value64;
				JS_ToInt64(context_, &value64, value_);
				value = (int32_t)value64;
				return value;
			} else{
				JS_ToUint32(context_, &value, value_);
				return value;
			}
		}

		operator uint32_t() const {
			return ToUint32();
		}

		operator unsigned short() const {
			return (unsigned short)ToUint32();
		}

		template<typename T>
		operator T() const {
			if (IsObject()) {
				JsProxy<T> *pThis=NULL;
				if (!GetSafeThis(value_, &pThis)) {
					JS_ThrowTypeError(context_, "no this pointer exist");
					return T();
				}
				return *pThis->GetObj();
			}
			else
			{
				assert(false);
				return *(T*)(void*)ToInt64();
			}
		}

		operator bool() const {
			if (IsBool()) {
				return ToBool();
			}
			else
			{
				assert(false);
				return false;
			}
		}

		//todo: x86下，由于uint64_t和JSValue类型相同，会导致程序定义冲突。
		//uint64_t如果要在函数的参数中使用，只能是在64位下。
#ifdef _WIN64
		operator uint64_t() const {
			return ToUint64();
		}
#endif
		template<typename T>
		operator T*() {
			if (IsObject()) {
				JSClassID id = JS_GetClassID(value_);
				JsProxy<T>* pThis;
				if (!GetSafeThis(value_, &pThis)) {
					JS_ThrowTypeError(context_, "no this pointer exist");
					return NULL;
				}
				T* ret = pThis->GetObj();
				return ret;
			}
			else
			{
#ifdef _WIN64
				return (T*)(void*)ToInt64();
#else
				return (T*)(void*)ToUint32();
#endif
			}
		}

		unsigned long ToULong() const {
#ifdef WIN64
			return (unsigned long)ToBigInt64();
#else
			return (unsigned long)ToUint32();
#endif
		}

		int64_t ToInt64() const {
			int64_t value = 0;
			JS_ToInt64(context_, &value, value_);
			return value;
		}

		uint64_t ToUint64() const {
			int64_t value = 0;
			JS_ToInt64(context_, &value, value_);
			return (uint64_t)value;
		}

		operator long() const {
			return ToInt32();
		}
		operator int64_t() const {
			return ToInt64();
		}

		float ToFloat() const {
			double value = 0;
			JS_ToFloat64(context_, &value, value_);
			return (float)value;
		}

		operator float() const {
			return ToFloat();
		}

		double ToFloat64() const {
			double value = 0;
			JS_ToFloat64(context_, &value, value_);
			return value;
		}

		operator double() const {
			return ToFloat64();
		}

		int64_t ToBigInt64() const {
			int64_t value = 0;
			JS_ToBigInt64(context_, &value, value_);
			return value;
		}

		int64_t ToInt64Ext() const {
			int64_t value = 0;
			JS_ToInt64Ext(context_, &value, value_);
			return value;
		}

		std::string ToStdString() const {
			if (!IsString()) {
				JSValue value = JS_ToString(context_, value_);
				size_t len;
				const char* str = JS_ToCStringLen(context_, &len, value);
				JS_FreeValue(context_, value);
				return std::string(str, len);
			}

			size_t len;
			const char* str = JS_ToCStringLen(context_, &len, value_);
			return std::string(str, len);
		}

		operator const char* () const {
			if (!IsString())
				return NULL;
			return JS_ToCStringLen(context_, NULL, value_);
		}

		uint8_t* ToBuffer(size_t* psize) const;

		void SetOpaque(void* opaque) {
			JS_SetOpaque(value_, opaque);
		}

		void* GetOpaque(JSClassID class_id) const {
			return JS_GetOpaque2(context_, value_, class_id);
		}


		//proto接口
		void SetPropertyFunctionList(const JSCFunctionListEntry* tab,
			int len) {
			JS_SetPropertyFunctionList(context_, value_, tab, len);
		}

		void SetConstructor(JSCFunction* func, const char* name) {
			JSValue func_obj = JS_NewCFunction2(context_, func, name, 1, JS_CFUNC_constructor, 0);
			JS_SetConstructor(context_, func_obj, value_);
		}

		//gc标记
		void Mark(JS_MarkFunc* mark_func) {
			if (context_) {
				JSRuntime* rt = JS_GetRuntime(context_);
				JS_MarkValue(rt, value_, mark_func);
//				context_ = NULL;
			}
		}

		//获取属性
		Value GetProperty(const char* prop) const;
		Value GetProperty(uint32_t idx) const;

		//获取数组的长度
		size_t length() const;

		std::map<std::string, Value>
			GetProperties(int flags = JS_GPN_STRING_MASK | JS_GPN_SYMBOL_MASK);

		bool HasProperty(const char* prop) const {
			if (!context_) {
				return false;
			}
			auto atom = JS_NewAtom(context_, prop);
			bool has = JS_HasProperty(context_, value_, atom) != 0;
			JS_FreeAtom(context_, atom);
			return has;
		}

		bool HasProperty(uint32_t idx) const {
			if (!context_) {
				return false;
			}
			auto atom = JS_NewAtomUInt32(context_, idx);
			bool has = JS_HasProperty(context_, value_, atom) != 0;
			JS_FreeAtom(context_, atom);
			return has;
		}

		bool DeleteProperty(const char* prop) {
			if (!context_) {
				return false;
			}
			auto atom = JS_NewAtom(context_, prop);
			int rslt = JS_DeleteProperty(context_, value_, atom, 0);
			JS_FreeAtom(context_, atom);
			return rslt == 1;
		}

		bool DeleteProperty(uint32_t idx) {
			if (!context_) {
				return false;
			}
			auto atom = JS_NewAtomUInt32(context_, idx);
			int rslt = JS_DeleteProperty(context_, value_, atom, 0);
			JS_FreeAtom(context_, atom);
			return rslt == 1;
		}

		bool SetProperty(const char* key, const WeakValue& value) {
			if (!context_) {
				return false;
			}
			return JS_SetPropertyStr(context_, value_, key,
				JS_DupValue(context_, value.value_)) == 0;
		}


		bool SetPropertyString(uint32_t key, const char* value) {
			if (!context_) {
				return false;
			}
			return JS_SetPropertyUint32(context_, value_, key, JS_NewString(context_, value)) == 0;
		}

		bool SetPropertyString(uint32_t key, const char* value, size_t len) {
			if (!context_) {
				return false;
			}
			return JS_SetPropertyUint32(context_, value_, key, JS_NewStringLen(context_, value, len)) == 0;
		}

		bool SetPropertyInt32(uint32_t key, int32_t value) {
			if (!context_) {
				return false;
			}
			return JS_SetPropertyUint32(context_, value_, key, JS_NewInt32(context_, value)) == 0;
		}

		bool SetPropertyInt64(uint32_t key, int64_t value) {
			if (!context_) {
				return false;
			}
			return JS_SetPropertyUint32(context_, value_, key, JS_NewInt64(context_, value)) == 0;
		}

		bool SetPropertyFloat32(uint32_t key, float value) {
			if (!context_) {
				return false;
			}
			return JS_SetPropertyUint32(context_, value_, key, JS_NewFloat64(context_, value)) == 0;
		}

		bool SetPropertyFloat64(uint32_t key, double value) {
			if (!context_) {
				return false;
			}
			return JS_SetPropertyUint32(context_, value_, key, JS_NewFloat64(context_, value)) == 0;
		}

		bool SetPropertyString(const char* key, const char* value) {
			if (!context_) {
				return false;
			}
			return JS_SetPropertyStr(context_, value_, key, JS_NewString(context_, value)) == 0;
		}

		bool SetPropertyString(const char* key, const char* value, size_t len) {
			if (!context_) {
				return false;
			}
			return JS_SetPropertyStr(context_, value_, key, JS_NewStringLen(context_, value, len)) == 0;
		}

		bool SetPropertyInt32(const char* key, int32_t value) {
			if (!context_) {
				return false;
			}
			return JS_SetPropertyStr(context_, value_, key, JS_NewInt32(context_, value)) == 0;
		}

		bool SetPropertyInt64(const char* key, int64_t value) {
			if (!context_) {
				return false;
			}
			return JS_SetPropertyStr(context_, value_, key, JS_NewInt64(context_, value)) == 0;
		}

		bool SetPropertyFloat32(const char* key, float value) {
			if (!context_) {
				return false;
			}
			return JS_SetPropertyStr(context_, value_, key, JS_NewFloat64(context_, value)) == 0;
		}

		bool SetPropertyFloat64(const char* key, double value) {
			if (!context_) {
				return false;
			}
			return JS_SetPropertyStr(context_, value_, key, JS_NewFloat64(context_, value)) == 0;
		}

		bool SetPrototype(const Value& value);
		Value GetPrototype();

		uint8_t* GetArrayBuffer(size_t* psize) {
			return JS_GetArrayBuffer(context_, psize, value_);
		}

	protected:
		friend class ConstValue;
		friend class Value;
		JSContext* context_;
		JSValue value_;
	};


	//强引用值
	class Value :public WeakValue {
	public:
		Value()
			:WeakValue()
		{
		}

		Value(JSContext* ctx)
			:WeakValue(ctx)
		{
		}

		Value(JSContext* ctx, JSValue&& value)
			:WeakValue(ctx, value)
		{
			value = JS_UNDEFINED;
		}

		Value(JSContext* ctx, const JSValueConst& value)
			:WeakValue(ctx, JS_DupValue(ctx, value))
		{
		}

		Value(const Value& value) 
			:WeakValue(value.context_, JS_DupValue(value.context_, value.value_))
		{
		}

		Value(const WeakValue& value)
			:WeakValue(value.context_, JS_DupValue(value.context_, value.value_))
		{
		}

		Value(Value&& value) 
			:WeakValue(value.context_, value.value_)
		{
			value.value_ = JS_UNDEFINED;
		}

		~Value() {
			if (context_) {
				JS_FreeValue(context_, value_);
			}
		}

		Value& operator=(const Value& value) {
			JSValue temp = JS_DupValue(value.context_, value.value_);
			JS_FreeValue(value.context_, value_);
			context_ = value.context_;
			value_ = temp;
			return *this;
		}

		JSValue CopyValue(JSContext *ctx=nullptr) const {
			if (!ctx) ctx = context_;
			return JS_DupValue(ctx, value_);
		}

		JSValue Release() {
			JSValue value = value_;
			value_ = JS_UNDEFINED;
			return value;
		}

		bool operator ==(const Value& src) const {
			return context_ == src.context_ && memcmp(&value_, &src.value_,sizeof(JSValue))==0;
		}

		bool SetProperty(const char* key, const Value& value) {
			return JS_SetPropertyStr(context_, value_, key,
				JS_DupValue(context_, value.value_)) == 0;
		}


		bool SetProperty(const char* key, Value&& value) {
			JSValue temp = value.value_;
			value.value_ = JS_UNDEFINED;
			return JS_SetPropertyStr(context_, value_, key, temp) == 0;
		}

		bool SetProperty(uint32_t key, const Value& value) {
			return JS_SetPropertyUint32(context_, value_, key,
				JS_DupValue(context_, value.value_)) == 0;
		}

		bool SetProperty(uint32_t key, Value&& value) {
			JSValue temp = value.value_;
			value.value_ = JS_UNDEFINED;
			return JS_SetPropertyUint32(context_, value_, key, temp) == 0;
		}
	};

	extern const Value undefined_value;
	extern const Value null_value;
	extern const Value true_value;
	extern const Value false_value;
	extern const Value exception_value;
	extern const Value uninit_value;

	class JsThisOwner {
	public:
		void SetJsThis(Value& jsThis) {
			m_jsThis = jsThis;
		}
		virtual const WeakValue & GetJsThis() const{
			return m_jsThis;
		}
	protected:
		WeakValue m_jsThis;
	};

}