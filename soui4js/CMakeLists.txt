set(PROJECT_NAME soui4js)


set(Headers
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
    "exports/exp_Worker.h"
    "exports/regkey.h"
    "exports/SAttrStorage.h"
    "exports/SFuncSlot.h"
    "exports/souidlgs.h"
    "exports/toobj.h"
    "resource.h"
    "soui4js.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "exp_soui.cpp"
    "soui4js.cpp"
    "stdafx.cpp"
)
source_group("Sources" FILES ${Sources})


################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} SHARED ${Sources})


target_precompile_headers(${PROJECT_NAME} PRIVATE
    "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/stdafx.h>"
)

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "${OUTPUT_DIRECTORY}soui4js"
        TARGET_NAME_RELEASE "${OUTPUT_DIRECTORY}soui4js"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "soui4js"
        TARGET_NAME_RELEASE "soui4js"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_CURRENT_SOURCE_DIR}/"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_SOURCE_DIR}/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "${CMAKE_SOURCE_DIR}/$<CONFIG>"
        OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/$<CONFIG>"
    )
endif()


    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/.;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/swinx/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../qjsbind;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/quickjs/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/soui/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/utilities/include;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/config;"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/components"
    )


################################################################################
# Dependencies
################################################################################
add_dependencies(${PROJECT_NAME}
    qjsbind
)

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "libquickjs.a;"
        "qjsbind;"
        "soui4;"
        "utilities4"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set(ADDITIONAL_LIBRARY_DEPENDENCIES
        "libquickjs.a;"
        "qjsbind;"
        "soui4;"
        "utilities4"
    )
endif()
target_link_libraries(${PROJECT_NAME} PUBLIC "${ADDITIONAL_LIBRARY_DEPENDENCIES}")

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_link_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/lib/x64;"
        "${OUTPUT_DIRECTORY};"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/quickjs/bin/x64"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_link_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/soui4/lib/x86;"
        "${OUTPUT_DIRECTORY};"
        "${CMAKE_CURRENT_SOURCE_DIR}/../depends/quickjs/bin/x86"
    )
endif()

