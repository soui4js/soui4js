#pragma once
#ifndef DEF_CAST_IOBJ
#define DEF_CAST_IOBJ(module,x) module->ExportFunc("to"#x,&sobj_cast<x>)
#define DEF_CAST_IOBJ2(module,x,x2) module->ExportFunc("to"#x,&sobj_cast<x2>)
#endif