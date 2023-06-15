#pragma once
#ifndef DEF_CAST_IOBJ
#define DEF_CAST_IOBJ(module,x) module->ExportFunc("to"#x,&sobj_cast<x>)
#endif