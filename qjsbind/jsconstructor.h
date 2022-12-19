#pragma once
#include "jsarglist.h"

namespace qjsbind {
    // constructor
    template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5>
    T* constructor(ArgList& args)
    {
        return new T(
            (T1)args[0],
            (T2)args[1],
            (T3)args[2],
            (T4)args[3],
            (T5)args[4]
        );
    }

    template<typename T, typename T1, typename T2, typename T3, typename T4>
    T* constructor(ArgList& args)
    {
        return new T(
            (T1)args[0],
            (T2)args[1],
            (T3)args[2],
            (T4)args[3]
        );
    }

    template<typename T, typename T1, typename T2, typename T3>
    T* constructor(ArgList& args)
    {
        return new T(
            (T1)args[0],
            (T2)args[1],
            (T3)args[2]
        );
    }

    template<typename T, typename T1, typename T2>
    T* constructor(ArgList& args)
    {
        return new T(
            (T1)args[0],
            (T2)args[1]
        );
    }

    template<typename T, typename T1>
    T* constructor(ArgList& args)
    {
        return new T(
            (T1)args[0]
        );
    }

    template<typename T>
    T* constructor(ArgList& args)
    {
        return new T();
    }

}