#include "UIKitPlugin.h"
#include "src/UIKitTheme.h"
#include <QQmlEngine>

// clang-format off
// ref https://doc.qt.io/qt-6/qtqml-syntax-imports.html
// qml.qrc 添加前缀 /qt-project.org/imports/ 可使用自带的默认导入路径.
// 如需自定义路径，则需要在 main.cpp 函数中添加资源文件前缀路径
// clang-format on

// qml 和 c++ 类统一在这里进行注册
// qml and c++ classes are registered here.
void UIKitPlugin::registerTypes(const char *uri) {

  qDebug() << "UIKitPlugin::registerTypes" << uri;

  qmlRegisterModule(uri, 1, 0);

  // clang-format off
  qmlRegisterType<UIKitTheme>(uri,1,0,"UIKitTheme"); // @uri UIKitTheme.UIKit

  const QByteArray buttons = QByteArray(uri) + ".Buttons";
  qmlRegisterType(QStringLiteral("qrc:/qt-project.org/imports/buttons/TextButton.qml"),buttons, 1, 0, "TextButton"); // @uri TextButton.UIKit.Buttons
  // clang-format on
}

void UIKitPlugin::initializeEngine(QQmlEngine *engine, const char *uri) {
  // 这里注册 qml 单例类、资源初始化等操作
}
