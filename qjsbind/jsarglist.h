#pragma once
#include "jsvalue.h"
#include <assert.h>
#include <array>

namespace qjsbind {

	//参数列表
	class ArgList {
	public:
		enum {
			MaxArgCount = 16
		};

		ArgList()
			:size_(0)
		{
		}

		ArgList(JSContext* context, int argc, JSValueConst* argv)
			:size_(argc)
		{
			assert(size_ < MaxArgCount);
			for (size_t i = 0; i < size_; ++i) {
				args_[i] = Value(context, argv[i]);
			}
		}

		inline size_t size() const {
			return size_;
		}

		Value operator[](size_t idx) const {
			if (idx >= size_) {
				return undefined_value;
			}
			return args_[idx];
		}

		Value & operator[](size_t idx)  {
			assert(idx < size_);
			return args_[idx];
		}

		Value & arg(size_t idx)  {
			assert(idx < size_);
			return args_[idx];
		}

		Value arg(size_t idx) const {
			if (idx >= size_) {
				return undefined_value;
			}
			return args_[idx];
		}

		Value* parg(size_t idx) {
			if (idx >= size_)
				return NULL;
			return &args_[idx];
		}
	private:
		QJS_DISALLOW_COPY_AND_ASSIGN(ArgList);
		size_t size_;
		std::array<Value, MaxArgCount> args_;
	};

}
