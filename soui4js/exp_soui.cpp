#include "stdafx.h"
#include <qjsbind.h>
#include <souistd.h>
#include <interface/SFactory-i.h>

//copy from gdip
#define INITGUID
#include <guiddef.h>
DEFINE_GUID(ImageFormatBMP, 0xb96b3cab, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatJPEG, 0xb96b3cae, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatPNG, 0xb96b3caf, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatGIF, 0xb96b3cb0, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatTIFF, 0xb96b3cb1, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
DEFINE_GUID(ImageFormatWEBP, 0xb96b3cb7, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);
#undef INITGUID

using namespace SOUI;
using namespace qjsbind;

#include "exports/exp_basic.h"
#include "exports/exp_enums.h"
#include "exports/exp_IObjRef.h"
#include "exports/exp_IString.h"
#include "exports/exp_IXml.h"
#include "exports/exp_ISouiFac.h"
#include "exports/exp_IApp.h"
#include "exports/exp_IResProvider.h"
#include "exports/exp_IResProviderMgr.h"
#include "exports/exp_ITimer.h"
#include "exports/exp_INativeWnd.h"
#include "exports/exp_IObject.h"
#include "exports/exp_IWindow.h"
#include "exports/exp_ICtrls.h"
#include "exports/exp_IHostWnd.h"
#include "exports/exp_IEvt.h"
#include "exports/exp_IAnimation.h"
#include "exports/exp_IValueAnimator.h"
#include "exports/exp_IInterpolator.h"
#include "exports/exp_IMenu.h"
#include "exports/exp_IMenuEx.h"
#include "exports/exp_IAdapter.h"
#include "exports/exp_ITranslatorMgr.h"
#include "exports/exp_INcPainter.h"
#include "exports/exp_IHttpClient.h"
#include "exports/exp_IImage.h"
#include "exports/exp_ILogMgr.h"
#include "exports/exp_ISkinObj.h"
#include "exports/exp_SString.h"
#include "exports/exp_SHostWnd.h"
#include "exports/exp_MsgHandlerProxy.h"
#include "exports/exp_EvtHandlerProxy.h"
#include "exports/exp_SEventArg.h"
#include "exports/exp_SAdapter.h"
#include "exports/exp_SWindow.h"
#include "exports/exp_Sxml.h"
#include "exports/exp_SMenu.h"
#include "exports/exp_globals.h"
#include "exports/exp_types.h"
#include "exports/exp_SDropTarget.h"
#include "exports/exp_SZipExtractor.h"
#include "exports/exp_SFileOpenDlg.h"
#include "exports/exp_SRegKey.h"
#include "exports/exp_SValueAnimator.h"
#include "exports/exp_IAttrStoarge.h"

namespace SOUI {

	BOOL ExportSoui(qjsbind::Context* context) {
		qjsbind::Module* module = context->NewModule("soui4");
		Exp_Global(module);
		Exp_Basic(module);
		Exp_SEnum(module);
		Exp_IObjRef(module);
		Exp_IStringA(module);
		Exp_IStringW(module);
		Exp_IXml(module);
		Exp_ISouiFactory(module);
		Exp_IApp(module);
		Exp_IResProvider(module);
		Exp_IResProviderMgr(module);
		Exp_ITimer(module);
		Exp_INativeWnd(module);
		Exp_IObject(module);
		Exp_IWindow(module);
		Exp_IHostWnd(module);
		Exp_IHostDialog(module);
		Exp_IEvtArg(module);
		Exp_IEvtSlot(module);
		Exp_IAnimation(module);
		Exp_IValueAnimator(module);
		Exp_IInterpolator(module);
		Exp_IMenu(module);
		Exp_IMenuEx(module);
		Exp_IAdapter(module);
		Exp_INcPainter(module);
		Exp_IHttpClient(module);
		Exp_ISkinObj(module);
		Exp_IImage(module);
		Exp_ICtrls(module);
		Exp_ITranslator(module);
		Exp_ILogMgr(module);
		Exp_IAttrStorage(module);
		Exp_SStringA(module);
		Exp_SStringW(module);
		Exp_JsHostWnd(module);
		Exp_JsHostDialog(module);
		Exp_MsgHandlerProxy(module);
		Exp_EvtHandlerProxy(module);

		Exp_HttpRequest(module);
		Exp_SEventArg(module);
		Exp_SAdapter(module);
		Exp_SDropTarget(module);
		Exp_SXml(module);
		Exp_SMenu(module);
		Exp_SMenuEx(module);
		Exp_SWindow(module);
		Exp_SZipExtractor(module);
		Exp_FileOpenDlg(module);
		Exp_SRegKey(module);
		Exp_SValueAnimator(module);
		return TRUE;
	}

}