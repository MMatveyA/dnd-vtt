#pragma once
#include <QMap>
#include <QObject>
#include <QQmlApplicationEngine>

/**
 * @class ScreenManager
 * @brief Класс для управления экранами (QML-модулями) в приложении.
 *
 * ScreenManager служит центральной точкой для регистрации, хранения и
 * предоставления доступа к экранам (QML-файлам).
 * Он позволяет модульно расширять приложение новыми экранами и
 * переключаться между ними из QML-кода.
 *
 * Основные возможности:
 * - Регистрация экранов по имени с привязкой к QML-файлам.
 * - Получение списка доступных экранов.
 * - Доступ к пути QML-файла по имени.
 * - Интеграция с QML через Q_INVOKABLE методы.
 *
 * Пример использования в C++:
 * @code
 * QQmlApplicationEngine engine;
 * ScreenManager manager(&engine);
 * manager.registerScreen("MainMenu", "qrc:/ui/MainMenu.qml");
 * manager.registerScreen("Settings", "qrc:/ui/Settings.qml");
 * @endcode
 *
 * Пример вызова из QML:
 * @code
 * ListView {
 *     model: screenManager.availableScreens()
 *     delegate: Text { text: modelData }
 * }
 *
 * Loader {
 *     id: loader
 *     source: screenManager.getScreenQml("Settings")
 * }
 * @endcode
 */
class ScreenManager : public QObject {
  Q_OBJECT
public:
  /**
   * @brief Конструктор менеджера экранов.
   * @param engine Указатель на QQmlApplicationEngine, с которым работает
   * менеджер.
   * @param parent Родительский объект Qt.
   */
  explicit ScreenManager(QQmlApplicationEngine *engine,
                         QObject *parent = nullptr);

  /**
   * @brief Получить список зарегистрированных экранов.
   * @return Список строк — имена доступных экранов.
   *
   * Доступен из QML для динамического построения интерфейсов.
   */
  Q_INVOKABLE QStringList availableScreens() const;

  /**
   * @brief Получить путь к QML-файлу по имени экрана.
   * @param name Имя экрана, зарегистрированного ранее.
   * @return Строка с путем к QML-файлу или пустая строка, если экран не найден.
   *
   * Доступен из QML, удобно использовать в Loader или StackView.
   */
  Q_INVOKABLE QString getScreenQml(const QString &name) const;

  /**
   * @brief Зарегистрировать новый экран.
   * @param name Имя экрана (ключ).
   * @param qmlFile Путь к QML-файлу (обычно в ресурсе, например
   * "qrc:/ui/Main.qml").
   *
   * Если экран с таким именем уже существует, запись будет перезаписана.
   */
  void registerScreen(const QString &name, const QString &qmlFile);

private:
  /// Имя -> путь к QML
  QMap<QString, QString> modules;
};
