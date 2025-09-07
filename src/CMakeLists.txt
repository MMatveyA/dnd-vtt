# --- Опции приложения ---
set(app_sources main.cpp ui/helplogic.cpp ui/mapslogic.cpp ui/screenmanager.cpp
                ui/gamelogic.cpp resources.qrc)

# --- Создаём библиотеку с исходниками проекта ---
# Основной код вынесем в библиотеку, чтобы её могли использовать тесты
add_library(${LIB_NAME} STATIC ui/helplogic.cpp ui/mapslogic.cpp
                               ui/screenmanager.cpp ui/gamelogic.cpp)

target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/ui)
target_link_libraries(${LIB_NAME} PRIVATE Qt6::Quick)

# --- Создаём исполняемый файл приложения ---
set(app_options)
if(CMAKE_BUILD_TYPE STREQUAL "Release")
  if(APPLE)
    list(APPEND app_options MACOSX_BUNDLE)
  elseif(WIN32)
    list(APPEND app_options WIN32)
  endif()
endif()

qt_add_executable(${PROJECT_NAME} ${app_options} main.cpp resources.qrc)

# Линкуем exe с библиотекой
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_NAME} Qt6::Quick)

# Компиляция
target_compile_options(
  ${PROJECT_NAME}
  PRIVATE $<$<CONFIG:Debug>:${COMMON_WARNINGS} ${DEBUG_FLAGS}>
          $<$<CONFIG:Release>:${COMMON_WARNINGS} ${RELEASE_FLAGS}>)

# Линковка
target_link_options(${PROJECT_NAME} PRIVATE
                    $<$<CONFIG:Debug>:-fsanitize=address,undefined>)

# --- Установка ---
install(
  TARGETS ${PROJECT_NAME}
  BUNDLE DESTINATION .
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
