#include "screenmanager.h"

ScreenManager::ScreenManager(QQmlApplicationEngine *engine, QObject *parent)
    : QObject(parent) {
    Q_UNUSED(engine)
}

QStringList ScreenManager::availableScreens() const { return modules.keys(); }

QString ScreenManager::getScreenQml(const QString &name) const {
    return modules.value(name, "");
}

void ScreenManager::registerScreen(const QString &name,
                                   const QString &qmlFile) {
    modules[name] = qmlFile;
}
