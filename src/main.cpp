#include "screenmanager.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    ScreenManager screen_manager(&engine);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
