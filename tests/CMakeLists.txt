include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
      DOWNLOAD_EXTRACT_TIMESTAMP TRUE)

# Для Windows: не перезаписываем настройки компилятора/линкера
set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(${TEST_NAME} test_main.cpp)

# Линкуем тесты с библиотекой проекта, а не с exe
target_link_libraries(${TEST_NAME} PRIVATE ${LIB_NAME} GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${TEST_NAME})
