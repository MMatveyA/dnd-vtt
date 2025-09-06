#pragma once
#include <QMap>
#include <QObject>
#include <QQmlApplicationEngine>

class ScreenManager : public QObject {
    Q_OBJECT
  public:
    explicit ScreenManager(QQmlApplicationEngine *engine,
                           QObject *parent = nullptr);

    Q_INVOKABLE QStringList availableScreens() const;
    Q_INVOKABLE QString getScreenQml(const QString &name) const;

    void registerScreen(const QString &name, const QString &qmlFile);

  private:
    /// Имя -> путь к QML
    QMap<QString, QString> modules;
};
