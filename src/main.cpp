#include "helplogic.h"
#include "mapslogic.h"
#include "screenmanager.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    ScreenManager screen_manager(&engine);

    screen_manager.registerScreen("Home", "qrc:/qml/home");
    screen_manager.registerScreen("Maps", "qrc:/qml/maps");
    screen_manager.registerScreen("Help", "qrc:/qml/help");

    MapsLogic maps_logic;
    HelpLogic help_logic;

    engine.rootContext()->setContextProperty("screenManager", &screen_manager);
    engine.rootContext()->setContextProperty("mapsLogic", &maps_logic);
    engine.rootContext()->setContextProperty("helpLogic", &help_logic);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
