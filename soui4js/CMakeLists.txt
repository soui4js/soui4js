set(PROJECT_NAME soui4js)


set(SOUI4JS_HEADER
    "stdafx.h"
    "exports/exp_basic.h"
    "exports/exp_enums.h"
    "exports/exp_EvtHandlerProxy.h"
    "exports/exp_globals.h"
    "exports/exp_IAdapter.h"
    "exports/exp_IAnimation.h"
    "exports/exp_IApp.h"
    "exports/exp_IAttrStoarge.h"
    "exports/exp_ICtrls.h"
    "exports/exp_IEvt.h"
    "exports/exp_IHostWnd.h"
    "exports/exp_IHttpClient.h"
    "exports/exp_IImage.h"
    "exports/exp_IInterpolator.h"
    "exports/exp_ILogMgr.h"
    "exports/exp_IMenu.h"
    "exports/exp_IMenuEx.h"
    "exports/exp_INativeWnd.h"
    "exports/exp_INcPainter.h"
    "exports/exp_IObject.h"
    "exports/exp_IObjRef.h"
    "exports/exp_IResProvider.h"
    "exports/exp_IResProviderMgr.h"
    "exports/exp_ISkinObj.h"
    "exports/exp_ISouiFac.h"
    "exports/exp_IString.h"
    "exports/exp_ITimer.h"
    "exports/exp_ITranslatorMgr.h"
    "exports/exp_IValueAnimator.h"
    "exports/exp_IWindow.h"
    "exports/exp_IXml.h"
    "exports/exp_MsgHandlerProxy.h"
    "exports/exp_SAdapter.h"
    "exports/exp_SDropTarget.h"
    "exports/exp_SEventArg.h"
    "exports/exp_SFileOpenDlg.h"
    "exports/exp_SHostWnd.h"
    "exports/exp_SMatrix.h"
    "exports/exp_SMenu.h"
    "exports/exp_SRegKey.h"
    "exports/exp_SString.h"
    "exports/exp_SValueAnimator.h"
    "exports/exp_Sxml.h"
    "exports/exp_SZipExtractor.h"
    "exports/exp_types.h"
    "exports/regkey.h"
    "exports/SAttrStorage.h"
    "exports/SFuncSlot.h"
    "exports/souidlgs.h"
    "exports/toobj.h"
    "resource.h"
    "soui4js.h"
)
source_group("Headers" FILES ${SOUI4JS_HEADER})

set(SOUI4JS_SRC
    "exp_soui.cpp"
    "soui4js.cpp"
    "stdafx.cpp"
)
source_group("Sources" FILES ${SOUI4JS_SRC})


################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${SOUI4JS_HEADER} ${SOUI4JS_SRC})


target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/qjsbind
    ${CMAKE_SOURCE_DIR}/depends/quickjs/include
    ${CMAKE_SOURCE_DIR}/depends/soui4/include/config
    ${CMAKE_SOURCE_DIR}/depends/soui4/include/utilities/include
    ${CMAKE_SOURCE_DIR}/depends/soui4/include/SOUI/include
    ${CMAKE_SOURCE_DIR}/depends/soui4/include/components
)

if (CMAKE_SYSTEM_NAME MATCHES Windows)
target_link_directories(${PROJECT_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/depends/quickjs/lib_win/$(Platform)
${CMAKE_SOURCE_DIR}/depends/soui4/lib_win/$(Platform)
)
target_link_libraries(${PROJECT_NAME} qjsbind libquickjs soui4 utilities4)
else()
target_link_directories(${PROJECT_NAME} PRIVATE
${CMAKE_SOURCE_DIR}/depends/quickjs/lib_deb/x64
${CMAKE_SOURCE_DIR}/depends/soui4/lib_deb/x64
)
target_link_libraries(${PROJECT_NAME} qjsbind quickjs soui4 utilities4)
endif()

################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    qjsbind
)

