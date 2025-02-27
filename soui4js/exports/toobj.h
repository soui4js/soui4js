#ifndef __TOOBJ__H__
#define __TOOBJ__H__
#ifndef DEF_CAST_IOBJ
#define DEF_CAST_IOBJ(module,x) module->ExportFunc("to"#x,&sobj_cast<x>)
#endif
#endif // __TOOBJ__H__