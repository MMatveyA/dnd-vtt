cmake_minimum_required(VERSION 3.21)
project(
  dnd-vtt
  VERSION 0.1
  LANGUAGES CXX)
set(LIB_NAME "${PROJECT_NAME}_lib")
set(TEST_NAME "${PROJECT_NAME}_test")

set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE
      Debug
      CACHE STRING "Build type" FORCE)
endif()

set(COMMON_WARNINGS
    -Wall
    -Wextra
    -Wpedantic
    -Wconversion
    -Wsign-conversion
    -Wshadow
    -Wnon-virtual-dtor)

set(DEBUG_FLAGS -O0 -g -fno-omit-frame-pointer)

set(RELEASE_FLAGS -O3 -DNDEBUG)

find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
  message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
  set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE};--warnings-as-errors=*")
endif()

find_program(CLANG_FORMAT_EXE NAMES "clang-format")
if(CLANG_FORMAT_EXE)
  message(STATUS "clang-format found: ${CLANG_FORMAT_EXE}")
  add_custom_target(
    format
    COMMAND ${CLANG_FORMAT_EXE} -i ${CMAKE_SOURCE_DIR}/src/*.cpp
            ${CMAKE_SOURCE_DIR}/include/*.hpp
    COMMENT "Running clang-format on source files")
endif()

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Quick)
qt_standard_project_setup()

add_subdirectory(src)

if(BUILD_TESTING)
  enable_testing()
  add_subdirectory(tests)
endif()
