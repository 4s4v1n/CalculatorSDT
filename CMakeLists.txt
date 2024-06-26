cmake_minimum_required(VERSION 3.5)

project(Calculator VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS
        Core
        Gui
        Qml
        Quick
)

qt_standard_project_setup()
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HDR_FILES
        model/converter/converter_decimal_to_p.hpp
        model/converter/converter_p_to_decimal.hpp
        model/editor/editor.hpp
        model/number/real_number.hpp
        model/processor/processor.hpp
        model/exception/number_exception.hpp
        model/exception/calculation_exception.hpp
        model/exception/conversion_exception.hpp
        model/memory/memory.hpp
        controller/controller.hpp
)
set(SRC_FILES
        main.cpp
        model/converter/converter_decimal_to_p.cpp
        model/converter/converter_p_to_decimal.cpp
        model/editor/editor.cpp
        model/number/real_number.cpp
        model/processor/processor.cpp
        model/exception/number_exception.cpp
        model/exception/calculation_exception.cpp
        model/exception/conversion_exception.cpp
        model/memory/memory.cpp
        controller/controller.cpp
)

qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${HDR_FILES}
        ${SRC_FILES}
)

qt_add_qml_module(${PROJECT_NAME}
    URI Converter
    VERSION 1.0
    QML_FILES
        view/main.qml
        view/components/BottomPanel.qml
        view/components/TopPanel.qml
        view/conversion.js
        view/pages/MainPage.qml
        view/pages/ReferencePage.qml
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
)

#qt_finalize_executable(${PROJECT_NAME})
