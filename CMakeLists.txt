cmake_minimum_required(VERSION 3.27.7)

project(
  qt5_cmake_qml_plugin_example
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)

set(PROJECT_SOURCES main.cpp qml.qrc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(qt5_cmake_qml_plugin_example MANUAL_FINALIZATION
                    ${PROJECT_SOURCES})
  # Define target properties for Android with Qt 6 as: set_property(TARGET
  # qt5_cmake_qml_plugin_example APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
  # ${CMAKE_CURRENT_SOURCE_DIR}/android) For more information, see
  # https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
  if(ANDROID)
    add_library(qt5_cmake_qml_plugin_example SHARED ${PROJECT_SOURCES})
    # Define properties for Android with Qt 5 after find_package() calls as:
    # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
  else()
    add_executable(qt5_cmake_qml_plugin_example ${PROJECT_SOURCES})
  endif()
endif()

target_link_libraries(
  qt5_cmake_qml_plugin_example PRIVATE Qt${QT_VERSION_MAJOR}::Core
                                       Qt${QT_VERSION_MAJOR}::Quick)

add_subdirectory(UIKit)

target_link_libraries(qt5_cmake_qml_plugin_example PRIVATE UIKit)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1. If
# you are developing for iOS or macOS you should consider setting an explicit,
# fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER
                       com.example.qt5_cmake_qml_plugin_example)
endif()
set_target_properties(
  qt5_cmake_qml_plugin_example
  PROPERTIES ${BUNDLE_ID_OPTION} MACOSX_BUNDLE_BUNDLE_VERSION
             ${PROJECT_VERSION} MACOSX_BUNDLE_SHORT_VERSION_STRING
             ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR} MACOSX_BUNDLE
             TRUE WIN32_EXECUTABLE
             TRUE)

include(GNUInstallDirs)
install(
  TARGETS qt5_cmake_qml_plugin_example
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# cmake-format: off
list(APPEND LIST_QML_IMPORT_PATH "${CMAKE_SOURCE_DIR}/UIKit")
list(REMOVE_DUPLICATES LIST_QML_IMPORT_PATH)

set(QML_IMPORT_PATH
    ${LIST_QML_IMPORT_PATH}
    CACHE STRING "Qt Creator 12.0.2 extra qml import paths" FORCE)
# cmake-format: on

if(QT_VERSION_MAJOR EQUAL 6)
  qt_import_qml_plugins(qt5_cmake_qml_plugin_example)
  qt_finalize_executable(qt5_cmake_qml_plugin_example)
endif()
