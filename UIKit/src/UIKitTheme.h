#pragma once

#include <QObject>
#include <QQmlEngine>

class UIKitTheme : public QObject {
  Q_OBJECT
  QML_ELEMENT
public:
  explicit UIKitTheme(QObject *parent = nullptr);

signals:
};
