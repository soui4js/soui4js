#ifndef __JSGFUNC__H__
#define __JSGFUNC__H__
#include "jsarglist.h"

namespace qjsbind {
	template<
		typename T, 
		typename RET
	>
	Value CFun2(Context& context, RET(*fun)(Context* ,T*, ArgList &), T* _this, ArgList& arg_list) {
		return NewValue(context, fun(&context, _this, arg_list));
	}

	template<typename T>
	Value CFun2(Context& context, void (*fun)(Context*, T*, ArgList&), T* _this, ArgList& arg_list) {
		fun(&context,_this, arg_list);
		return undefined_value;
	}

	template<typename T>
	Value CFun2(Context& context, Value(*fun)(Context*, T*, ArgList&), T* _this, ArgList& arg_list) {
		return fun(&context, _this, arg_list);
	}

	template<typename RET>
	Value CFun( Context& context,RET(*fun)(), ArgList& arg_list) {
		return NewValue(context, fun());
	}

	template<typename RET, typename P1>
	Value CFun( Context& context,RET(*fun)(P1), ArgList& arg_list) {
		return NewValue(context, fun((P1)arg_list[0]));
	}

	template<typename RET, typename P1, typename P2>
	Value CFun( Context& context,RET(*fun)(P1, P2), ArgList& arg_list) {
		return NewValue(context, fun((P1)arg_list[0], (P2)arg_list[1]));
	}

	template<typename RET, typename P1, typename P2, typename P3>
	Value CFun( Context& context,RET(*fun)(P1, P2, P3), ArgList& arg_list) {
		return NewValue(context, fun((P1)arg_list[0], (P2)arg_list[1], (P3)arg_list[2]));
	}

	template<typename RET, 
		typename P1, 
		typename P2, 
		typename P3,
		typename P4
	>
	Value CFun( Context& context,RET(*fun)(P1, P2, P3,P4), ArgList& arg_list) {
		return NewValue(context, fun(
			(P1)arg_list[0],
			(P2)arg_list[1],
			(P3)arg_list[2],
			(P4)arg_list[3]
		));
	}

	template<typename RET,
		typename P1,
		typename P2,
		typename P3,
		typename P4,
		typename P5
	>
	Value CFun( Context& context,RET(*fun)(P1, P2, P3, P4,P5), ArgList& arg_list) {
		return NewValue(context, fun(
			(P1)arg_list[0],
			(P2)arg_list[1],
			(P3)arg_list[2],
			(P4)arg_list[3],
			(P5)arg_list[4]
			));
	}

	template<typename RET,
		typename P1,
		typename P2,
		typename P3,
		typename P4,
		typename P5,
		typename P6
	>
	Value CFun( Context& context,RET(*fun)(P1, P2, P3, P4, P5,P6), ArgList& arg_list) {
		return NewValue(context, fun(
			(P1)arg_list[0],
			(P2)arg_list[1],
			(P3)arg_list[2],
			(P4)arg_list[3],
			(P5)arg_list[4],
			(P6)arg_list[5]
		));
	}

	template<typename RET,
		typename P1,
		typename P2,
		typename P3,
		typename P4,
		typename P5,
		typename P6,
		typename P7
	>
	Value CFun( Context& context,RET(*fun)(P1, P2, P3, P4, P5, P6,P7), ArgList& arg_list) {
		return NewValue(context, fun(
			(P1)arg_list[0],
			(P2)arg_list[1],
			(P3)arg_list[2],
			(P4)arg_list[3],
			(P5)arg_list[4],
			(P6)arg_list[5],
			(P7)arg_list[6]
		));
	}

	template<typename RET,
		typename P1,
		typename P2,
		typename P3,
		typename P4,
		typename P5,
		typename P6,
		typename P7,
		typename P8
	>
	Value CFun( Context& context,RET(*fun)(P1, P2, P3, P4, P5, P6, P7,P8), ArgList& arg_list) {
		return NewValue(context, fun(
			(P1)arg_list[0],
			(P2)arg_list[1],
			(P3)arg_list[2],
			(P4)arg_list[3],
			(P5)arg_list[4],
			(P6)arg_list[5],
			(P7)arg_list[6],
			(P8)arg_list[7]
		));
	}

	template<typename RET,
		typename P1,
		typename P2,
		typename P3,
		typename P4,
		typename P5,
		typename P6,
		typename P7,
		typename P8,
		typename P9
	>
	Value CFun( Context& context,RET(*fun)(P1, P2, P3, P4, P5, P6, P7, P8,P9), ArgList& arg_list) {
		return NewValue(context, fun(
			(P1)arg_list[0],
			(P2)arg_list[1],
			(P3)arg_list[2],
			(P4)arg_list[3],
			(P5)arg_list[4],
			(P6)arg_list[5],
			(P7)arg_list[6],
			(P8)arg_list[7],
			(P9)arg_list[8]
		));
	}

	template<typename RET,
		typename P1,
		typename P2,
		typename P3,
		typename P4,
		typename P5,
		typename P6,
		typename P7,
		typename P8,
		typename P9,
		typename P10
	>
	Value CFun( Context& context,RET(*fun)(P1, P2, P3, P4, P5, P6, P7, P8, P9,P10), ArgList& arg_list) {
		return NewValue(context, fun(
			(P1)arg_list[0],
			(P2)arg_list[1],
			(P3)arg_list[2],
			(P4)arg_list[3],
			(P5)arg_list[4],
			(P6)arg_list[5],
			(P7)arg_list[6],
			(P8)arg_list[7],
			(P9)arg_list[8],
			(P10)arg_list[9]
		));
	}
}

namespace qjsbind {
	inline Value CFun(Context& context, void(*fun)(), ArgList& arg_list) {
		fun();
		return undefined_value;
	}

	inline Value CFun(Context& context, Value(*fun)(Context *ctx,ArgList&), ArgList& arg_list) {
		return fun(&context,arg_list);
	}

	template< typename P1>
	Value CFun(Context& context, void(*fun)(P1), ArgList& arg_list) {
		fun((P1)arg_list[0]);
		return undefined_value;
	}

	template<typename P1, typename P2>
	Value CFun(Context& context, void(*fun)(P1, P2), ArgList& arg_list) {
		fun((P1)arg_list[0], (P2)arg_list[1]);
		return undefined_value;
	}

	template< typename P1, typename P2, typename P3>
	Value CFun(Context& context, void(*fun)(P1, P2, P3), ArgList& arg_list) {
		fun((P1)arg_list[0], (P2)arg_list[1], (P3)arg_list[2]);
		return undefined_value;
	}

	template<
		typename P1,
		typename P2,
		typename P3,
		typename P4
	>
	Value CFun(Context& context, void(*fun)(P1, P2, P3, P4), ArgList& arg_list) {
		fun(
			(P1)arg_list[0],
			(P2)arg_list[1],
			(P3)arg_list[2],
			(P4)arg_list[3]
		);
		return undefined_value;
	}

	template<
		typename P1,
		typename P2,
		typename P3,
		typename P4,
		typename P5
	>
	Value CFun(Context& context, void(*fun)(P1, P2, P3, P4, P5), ArgList& arg_list) {
		fun(
			(P1)arg_list[0],
			(P2)arg_list[1],
			(P3)arg_list[2],
			(P4)arg_list[3],
			(P5)arg_list[4]
		);
		return undefined_value;
	}

	template<
		typename P1,
		typename P2,
		typename P3,
		typename P4,
		typename P5,
		typename P6
	>
	Value CFun(Context& context, void(*fun)(P1, P2, P3, P4, P5, P6), ArgList& arg_list) {
		fun(
			(P1)arg_list[0],
			(P2)arg_list[1],
			(P3)arg_list[2],
			(P4)arg_list[3],
			(P5)arg_list[4],
			(P6)arg_list[5]
		);
		return undefined_value;
	}

	template<
		typename P1,
		typename P2,
		typename P3,
		typename P4,
		typename P5,
		typename P6,
		typename P7
	>
	Value CFun(Context& context, void(*fun)(P1, P2, P3, P4, P5, P6, P7), ArgList& arg_list) {
		fun(
			(P1)arg_list[0],
			(P2)arg_list[1],
			(P3)arg_list[2],
			(P4)arg_list[3],
			(P5)arg_list[4],
			(P6)arg_list[5],
			(P7)arg_list[6]
		);
		return undefined_value;
	}

	template<
		typename P1,
		typename P2,
		typename P3,
		typename P4,
		typename P5,
		typename P6,
		typename P7,
		typename P8
	>
	Value CFun(Context& context, void(*fun)(P1, P2, P3, P4, P5, P6, P7, P8), ArgList& arg_list) {
		fun(
			(P1)arg_list[0],
			(P2)arg_list[1],
			(P3)arg_list[2],
			(P4)arg_list[3],
			(P5)arg_list[4],
			(P6)arg_list[5],
			(P7)arg_list[6],
			(P8)arg_list[7]
		);
		return undefined_value;
	}

	template<
		typename P1,
		typename P2,
		typename P3,
		typename P4,
		typename P5,
		typename P6,
		typename P7,
		typename P8,
		typename P9
	>
	Value CFun(Context& context, void(*fun)(P1, P2, P3, P4, P5, P6, P7, P8, P9), ArgList& arg_list) {
		fun(
			(P1)arg_list[0],
			(P2)arg_list[1],
			(P3)arg_list[2],
			(P4)arg_list[3],
			(P5)arg_list[4],
			(P6)arg_list[5],
			(P7)arg_list[6],
			(P8)arg_list[7],
			(P9)arg_list[8]
		);
		return undefined_value;
	}

	template<
		typename P1,
		typename P2,
		typename P3,
		typename P4,
		typename P5,
		typename P6,
		typename P7,
		typename P8,
		typename P9,
		typename P10
	>
	Value CFun(Context& context, void(*fun)(P1, P2, P3, P4, P5, P6, P7, P8, P9, P10), ArgList& arg_list) {
		fun(
			(P1)arg_list[0],
			(P2)arg_list[1],
			(P3)arg_list[2],
			(P4)arg_list[3],
			(P5)arg_list[4],
			(P6)arg_list[5],
			(P7)arg_list[6],
			(P8)arg_list[7],
			(P9)arg_list[8],
			(P10)arg_list[9]
		);
		return undefined_value;
	}
}
#endif // __JSGFUNC__H__