#ifndef __WIN4XCB_H_
#define __WIN4XCB_H_

#ifndef WINVER
#define WINVER 0x0500
#endif // WINVER
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0502
#endif //_WIN32_WINNT

#include <ctypes.h>
#include <winuser.h>
#include <class.h>
#include <ctrl_types.h>
#include <wnd.h>
#include <region.h>
#include <gdi.h>
#include <winerror.h>
#include <unknwn.h>
#include <objbase.h>
#include <objidl.h>
#include <oleidl.h>
#include <oaidl.h>
#include <ole2.h>
#include <oleauto.h>
#include <dlfcn.h>
#include <tchar.h>
#include <strapi.h>
#include <commctrl.h>
#include <error.h>
#include <sysapi.h>
#include <fileapi.h>
#include <menu.h>
#include <hook.h>
#include <winnls.h>
#include <richedit.h>
#include <multimon.h>
#include <shellapi.h>

#undef NULL
#define NULL 0

#endif //__WIN4XCB_H_
