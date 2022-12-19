#pragma once
#include "jsnewvalue.h"
#ifndef WINAPI
#define WINAPI __stdcall
#endif

namespace qjsbind {
	//10 params
	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9,
		typename T10
	>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8, T9,T10), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7],
			(T9)arg_list[8],
			(T10)arg_list[9]
			));
	}

	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9,
		typename T10
	>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7],
			(T9)arg_list[8],
			(T10)arg_list[9]
			));
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9,
		typename T10
	>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10), ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7],
			(T9)arg_list[8],
			(T10)arg_list[9]
			);
		return undefined_value;
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9,
		typename T10
	>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) const, ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7],
			(T9)arg_list[8],
			(T10)arg_list[9]
			);
		return undefined_value;
	}
	//9 params
	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9
	>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8, T9), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7],
			(T9)arg_list[8]
			));
	}

	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9
	>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8, T9) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7],
			(T9)arg_list[8]
			));
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9
	>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8, T9), ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7],
			(T9)arg_list[8]
			);
		return undefined_value;
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9
	>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8,T9) const, ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7],
			(T9)arg_list[8]
			);
		return undefined_value;
	}

	//8 params
	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8
	>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2, T3, T4, T5, T6, T7,T8), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7]
			));
	}

	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8
	>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7]
			));
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8
	>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8), ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7]
			);
		return undefined_value;
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8
	>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8) const, ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7]
			);
		return undefined_value;
	}

	//7 params
	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7
	>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2, T3, T4, T5, T6, T7), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6]
			));
	}

	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7
	>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2, T3, T4, T5, T6, T7) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6]
			));
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7
	>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2, T3, T4, T5, T6, T7), ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6]
			);
		return undefined_value;
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7
	>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2, T3, T4, T5, T6, T7) const, ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6]
			);
		return undefined_value;
	}

	//6 params
	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6
	>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2, T3, T4, T5, T6), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5]
			));
	}

	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6
	>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2, T3, T4, T5, T6) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5]
			));
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6
	>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2, T3, T4, T5, T6), ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5]
			);
		return undefined_value;
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6
	>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2, T3, T4, T5, T6) const, ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5]
			);
		return undefined_value;
	}

	//5 params
	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5
	>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2, T3, T4, T5), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4]
			));
	}

	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5
	>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2, T3, T4, T5) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4]
			));
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5
	>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2, T3, T4, T5), ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4]
			);
		return undefined_value;
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5
	>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2, T3, T4, T5) const, ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4]
			);
		return undefined_value;
	}

	//4 params
	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4
	>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2, T3, T4), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3]
			));
	}

	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4
	>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2, T3, T4) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3]
			));
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4
	>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2, T3, T4), ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3]
			);
		return undefined_value;
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4
	>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2, T3, T4) const, ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3]
			);
		return undefined_value;
	}

	//3 params
	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3
	>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2, T3), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)((T1)arg_list[0], (T2)arg_list[1], (T3)arg_list[2]));
	}

	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3
	>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2, T3) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)((T1)arg_list[0], (T2)arg_list[1], (T3)arg_list[2]));
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3
	>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2, T3), ArgList& arg_list) {
		(pThis->*fun)((T1)arg_list[0], (T2)arg_list[1], (T3)arg_list[2]);
		return undefined_value;
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3
	>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2, T3) const, ArgList& arg_list) {
		(pThis->*fun)((T1)arg_list[0], (T2)arg_list[1], (T3)arg_list[2]);
		return undefined_value;
	}

	//2 params
	template<typename T, typename Ret, typename T1, typename T2>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)((T1)arg_list[0], (T2)arg_list[1]));
	}

	template<typename T, typename Ret, typename T1, typename T2>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1, T2) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)((T1)arg_list[0], (T2)arg_list[1]));
	}

	template<typename T, typename T1, typename T2>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2), ArgList& arg_list) {
		(pThis->*fun)((T1)arg_list[0], (T2)arg_list[1]);
		return undefined_value;
	}

	template<typename T, typename T1, typename T2>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1, T2) const, ArgList& arg_list) {
		(pThis->*fun)((T1)arg_list[0], (T2)arg_list[1]);
		return undefined_value;
	}


	//1 params
	template<typename T, typename Ret, typename T1>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)((T1)arg_list[0]));
	}

	template<typename T, typename Ret, typename T1>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(T1) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)((T1)arg_list[0]));
	}

	template<typename T, typename T1>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1), ArgList& arg_list) {
		(pThis->*fun)((T1)arg_list[0]);
		return undefined_value;
	}
	template<typename T, typename T1>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(T1) const, ArgList& arg_list) {
		(pThis->*fun)((T1)arg_list[0]);
		return undefined_value;
	}


	//0 params
	template<typename T, typename Ret>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)(), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)());
	}

	template<typename T, typename Ret>
	Value MemFunC(T* pThis, Context& context, Ret(T::* fun)() const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)());
	}

	template<typename T>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(), ArgList& arg_list) {
		(pThis->*fun)();
		return undefined_value;
	}
	template<typename T>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)() const, ArgList& arg_list) {
		(pThis->*fun)();
		return undefined_value;
	}
}

#pragma once
#include "jsnewvalue.h"

namespace qjsbind {
	//10 params
	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9,
		typename T10
	>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7],
			(T9)arg_list[8],
			(T10)arg_list[9]
			));
	}

	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9,
		typename T10
	>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7],
			(T9)arg_list[8],
			(T10)arg_list[9]
			));
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9,
		typename T10
	>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10), ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7],
			(T9)arg_list[8],
			(T10)arg_list[9]
			);
		return undefined_value;
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9,
		typename T10
	>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) const, ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7],
			(T9)arg_list[8],
			(T10)arg_list[9]
			);
		return undefined_value;
	}
	//9 params
	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9
	>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8, T9), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7],
			(T9)arg_list[8]
			));
	}

	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9
	>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8, T9) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7],
			(T9)arg_list[8]
			));
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9
	>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8, T9), ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7],
			(T9)arg_list[8]
			);
		return undefined_value;
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8,
		typename T9
	>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8, T9) const, ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7],
			(T9)arg_list[8]
			);
		return undefined_value;
	}

	//8 params
	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8
	>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7]
			));
	}

	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8
	>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7]
			));
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8
	>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8), ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7]
			);
		return undefined_value;
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7,
		typename T8
	>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6, T7, T8) const, ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6],
			(T8)arg_list[7]
			);
		return undefined_value;
	}

	//7 params
	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7
	>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6, T7), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6]
			));
	}

	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7
	>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6, T7) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6]
			));
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7
	>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6, T7), ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6]
			);
		return undefined_value;
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6,
		typename T7
	>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6, T7) const, ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5],
			(T7)arg_list[6]
			);
		return undefined_value;
	}

	//6 params
	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6
	>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5]
			));
	}

	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6
	>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5]
			));
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6
	>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6), ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5]
			);
		return undefined_value;
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5,
		typename T6
	>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2, T3, T4, T5, T6) const, ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4],
			(T6)arg_list[5]
			);
		return undefined_value;
	}

	//5 params
	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5
	>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2, T3, T4, T5), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4]
			));
	}

	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5
	>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2, T3, T4, T5) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4]
			));
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5
	>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2, T3, T4, T5), ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4]
			);
		return undefined_value;
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4,
		typename T5
	>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2, T3, T4, T5) const, ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3],
			(T5)arg_list[4]
			);
		return undefined_value;
	}

	//4 params
	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4
	>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2, T3, T4), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3]
			));
	}

	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3,
		typename T4
	>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2, T3, T4) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3]
			));
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4
	>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2, T3, T4), ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3]
			);
		return undefined_value;
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3,
		typename T4
	>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2, T3, T4) const, ArgList& arg_list) {
		(pThis->*fun)(
			(T1)arg_list[0],
			(T2)arg_list[1],
			(T3)arg_list[2],
			(T4)arg_list[3]
			);
		return undefined_value;
	}

	//3 params
	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3
	>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2, T3), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)((T1)arg_list[0], (T2)arg_list[1], (T3)arg_list[2]));
	}

	template<typename T, typename Ret,
		typename T1,
		typename T2,
		typename T3
	>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2, T3) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)((T1)arg_list[0], (T2)arg_list[1], (T3)arg_list[2]));
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3
	>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2, T3), ArgList& arg_list) {
		(pThis->*fun)((T1)arg_list[0], (T2)arg_list[1], (T3)arg_list[2]);
		return undefined_value;
	}

	template<typename T,
		typename T1,
		typename T2,
		typename T3
	>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2, T3) const, ArgList& arg_list) {
		(pThis->*fun)((T1)arg_list[0], (T2)arg_list[1], (T3)arg_list[2]);
		return undefined_value;
	}

	//2 params
	template<typename T, typename Ret, typename T1, typename T2>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)((T1)arg_list[0], (T2)arg_list[1]));
	}

	template<typename T, typename Ret, typename T1, typename T2>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1, T2) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)((T1)arg_list[0], (T2)arg_list[1]));
	}

	template<typename T, typename T1, typename T2>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2), ArgList& arg_list) {
		(pThis->*fun)((T1)arg_list[0], (T2)arg_list[1]);
		return undefined_value;
	}

	template<typename T, typename T1, typename T2>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1, T2) const, ArgList& arg_list) {
		(pThis->*fun)((T1)arg_list[0], (T2)arg_list[1]);
		return undefined_value;
	}


	//1 params
	template<typename T, typename Ret, typename T1>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)((T1)arg_list[0]));
	}

	template<typename T, typename Ret, typename T1>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(T1) const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)((T1)arg_list[0]));
	}

	template<typename T, typename T1>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1), ArgList& arg_list) {
		(pThis->*fun)((T1)arg_list[0]);
		return undefined_value;
	}
	template<typename T, typename T1>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(T1) const, ArgList& arg_list) {
		(pThis->*fun)((T1)arg_list[0]);
		return undefined_value;
	}


	//0 params
	template<typename T, typename Ret>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)(), ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)());
	}

	template<typename T, typename Ret>
	Value MemFunC(T* pThis, Context& context, Ret(WINAPI T::* fun)() const, ArgList& arg_list) {
		return NewValue(context, (pThis->*fun)());
	}

	template<typename T>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)(), ArgList& arg_list) {
		(pThis->*fun)();
		return undefined_value;
	}
	template<typename T>
	Value MemFunC(T* pThis, Context& context, void(WINAPI T::* fun)() const, ArgList& arg_list) {
		(pThis->*fun)();
		return undefined_value;
	}

	template<typename T>
	Value MemFunC(T* pThis, Context& context, void(T::* fun)(ArgList &), ArgList& arg_list) {
		(pThis->*fun)(arg_list);
		return undefined_value;
	}
}

