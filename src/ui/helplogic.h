#pragma once
#include <QObject>

/**
 * @class HelpLogic
 * @brief Логика для окна справочной информации.
 *
 * На данный момент класс является заготовкой, но в будущем может быть
 * расширен методами для:
 * - Загрузки и отображения справочных текстов.
 * - Навигации по разделам справки.
 * - Поиска по справочному материалу.
 *
 * Пример использования:
 * @code
 * HelpLogic *help = new HelpLogic(this);
 * engine.rootContext()->setContextProperty("helpLogic", help);
 * @endcode
 */
class HelpLogic : public QObject {
  Q_OBJECT
public:
  /**
   * @brief Конструктор логики справочного окна.
   * @param parent Родительский QObject.
   */
  explicit HelpLogic(QObject *parent = nullptr);
};
