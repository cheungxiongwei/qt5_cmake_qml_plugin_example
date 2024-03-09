cmake_minimum_required(VERSION 3.27.7)

project(
  UIKit
  VERSION 1.0.0
  LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick Qml QuickCompiler)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick Qml
                                                       QuickCompiler)

# qtquick_compiler_add_resources(RESOURCES qml.qrc)

add_library(
  ${PROJECT_NAME} SHARED
  UIKitPlugin.h
  UIKitPlugin.cpp
  src/UIKitTheme.h
  src/UIKitTheme.cpp
  ${RESOURCES}
  qml.qrc
  UIKit.qmltypes)
# cmake-format: off
# target_compile_definitions(${PROJECT_NAME}PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
# cmake-format: on

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick
          Qt${QT_VERSION_MAJOR}::Qml)

target_compile_options(${PROJECT_NAME}
                       PRIVATE "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4)
endif()

if(QT_VERSION_MAJOR EQUAL 6)
  qt_import_qml_plugins(${PROJECT_NAME})
  qt_finalize_executable(${PROJECT_NAME})
endif()

add_custom_command(
  TARGET ${PROJECT_NAME}
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_DIR}/qmldir
          $<TARGET_FILE_DIR:${PROJECT_NAME}>/qmldir)
