/**
 * @file main.cpp
 * @brief Точка входа в приложение DnD VTT.
 *
 * Здесь создаётся QGuiApplication и настраивается QQmlApplicationEngine.
 * Подключаются основные модули приложения:
 * - ScreenManager для управления QML-экранами;
 * - MapsLogic для управления пользовательскими картами;
 * - HelpLogic для отображения справочной информации.
 *
 * В QML-контекст пробрасываются объекты screenManager, mapsLogic и helpLogic,
 * чтобы их можно было использовать в интерфейсе.
 *
 * После загрузки главного QML-файла (qrc:/qml/main) приложение переходит в
 * основной цикл событий.
 */

#include "ui/gamelogic.h"
#include "ui/helplogic.h"
#include "ui/mapslogic.h"
#include "ui/screenmanager.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    ScreenManager screen_manager(&engine);

    screen_manager.registerScreen("Game", "qrc:/qml/game");
    screen_manager.registerScreen("Help", "qrc:/qml/help");
    screen_manager.registerScreen("Home", "qrc:/qml/home");
    screen_manager.registerScreen("Maps", "qrc:/qml/maps");

    GameLogic game_logic;
    MapsLogic maps_logic;
    HelpLogic help_logic;

    engine.rootContext()->setContextProperty("screenManager", &screen_manager);
    engine.rootContext()->setContextProperty("mapsLogic", &maps_logic);
    engine.rootContext()->setContextProperty("helpLogic", &help_logic);
    engine.rootContext()->setContextProperty("gameLogic", &game_logic);

    engine.load(QUrl(QStringLiteral("qrc:/qml/main")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
