//
// cmake config.h.in
//
/* #undef ENABLE_SOUI_COM_LIB */
/* #undef ENABLE_SOUI_CORE_LIB */
#define OUTPATH_WITHOUT_TYPE

#ifdef ENABLE_SOUI_COM_LIB
    #define LIB_SOUI_COM		//SOUI�������Ϊlib
#else
    #define DLL_SOUI_COM	//SOUI�������Ϊdll
#endif

#ifdef ENABLE_SOUI_CORE_LIB
    #define LIB_CORE		//SOUI �ں˱���Ϊlib
#else
    #define DLL_CORE		//SOUI �ں˱���Ϊdll
#endif

