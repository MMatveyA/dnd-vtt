#pragma once
#include <QObject>

/**
 * @class MapsLogic
 * @brief Логика управления пользовательскими картами (DnD).
 *
 * Класс отвечает за работу с пользовательскими картами, добавляемыми
 * в приложение. В будущем он будет предоставлять API для:
 * - добавления новых карт (из файлов или ресурсов);
 * - хранения списка карт;
 * - удаления и переименования карт;
 * - выборки карт для отображения в QML.
 *
 * Пример интеграции:
 * @code
 * MapsLogic *maps = new MapsLogic(this);
 * engine.rootContext()->setContextProperty("mapsLogic", maps);
 * @endcode
 */
class MapsLogic : public QObject {
    Q_OBJECT
  public:
    /**
     * @brief Конструктор логики управления картами.
     * @param parent Родительский QObject.
     */
    explicit MapsLogic(QObject *parent = nullptr);
};
