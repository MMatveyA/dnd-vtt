#pragma once
#include <QObject>

class MapsLogic : public QObject {
  Q_OBJECT
public:
  explicit MapsLogic(QObject *parent = nullptr);
};
