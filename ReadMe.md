[![en](https://img.shields.io/badge/lang-en-red.svg)](https://github.com/cheungxiongwei/qt5_cmake_qml_plugin_example/blob/main/ReadMe.md)
[![zh-CN](https://img.shields.io/badge/lang-pt--br-green.svg)](https://github.com/cheungxiongwei/qt5_cmake_qml_plugin_example/blob/main/ReadMe.zh-CN.md)

This Git repository is used to demonstrate an example of creating a QML plugin using CMake as the build system. The plugin consists of UIKit, which includes various UI components that can be utilized in other QML projects. This example showcases how to create a shared library containing UI elements, and how to register them with the QML engine so they can be used in Qt Quick applications.

The project contains a `main.cpp` file for creating an executable that loads the plugin and uses one of its components (a custom TextButton). The CMakeLists.txt files are configured to properly build the plugin and the example application with necessary dependencies, including Qt 5 or Qt 6.

The following steps can be performed using this Git repository:

1. Clone the repository and navigate to it in the terminal.
2. Use `cmake` to generate a build system (e.g., Makefiles, Visual Studio projects).
3. Build the plugin library and example application using your preferred build tool.
4. Run the example application to see the UIKit components in action.
5. Modify or add new components to the UIKit plugin by editing `UIKitPlugin.cpp`, `UIKitPlugin.h`, and their associated source files.
6. Use the UIKit plugin in your own Qt Quick applications by adding its directory to the QML import path and linking it as a library.