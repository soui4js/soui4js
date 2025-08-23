﻿//
// cmake config.h.in
//
/* #undef ENABLE_SOUI_COM_LIB */
/* #undef ENABLE_SOUI_CORE_LIB */
#define OUTPATH_WITHOUT_TYPE
/* #undef ENABLE_SOUI_ACC */
/* #undef ENABLE_SOUI_SPY */

#ifdef _WIN32
#ifdef ENABLE_SOUI_SPY
#define DISABLE_SWNDSPY 0
#else
#define DISABLE_SWNDSPY 1
#endif//ENABLE_SOUI_SPY

#ifdef ENABLE_SOUI_ACC
#define SOUI_ENABLE_ACC
#endif//ENABLE_SOUI_ACC
#else
#define DISABLE_SWNDSPY 1
#endif

#ifdef ENABLE_SOUI_COM_LIB
    #define LIB_SOUI_COM		//SOUI组件编译为lib
#else
    #define DLL_SOUI_COM	//SOUI组件编译为dll
#endif

#ifdef ENABLE_SOUI_CORE_LIB
    #define LIB_CORE		//SOUI 内核编译为lib
#else
    #define DLL_CORE		//SOUI 内核编译为dll
#endif

