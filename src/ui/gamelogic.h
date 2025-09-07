#pragma once
#include <QObject>

/**
 * @class GameLogic
 * @brief Логика игры
 *
 * Класс отвечает за работу работу в процессе игры
 *
 * Пример интеграции:
 * @code
 * GameLogic *game = new GameLogic(this);
 * engine.rootContext()->setContextProperty("gameLogic", game);
 * @endcode
 */
class GameLogic : public QObject {
    Q_OBJECT
  public:
    /**
     * @brief Конструктор логики 
     * @param parent Родительский QObject.
     */
    explicit GameLogic(QObject *parent = nullptr);
};
