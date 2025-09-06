#pragma once
#include <QObject>

class HelpLogic : public QObject {
    Q_OBJECT
  public:
    explicit HelpLogic(QObject *parent = nullptr);
};
