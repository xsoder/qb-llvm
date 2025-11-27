cmake_minimum_required(VERSION 3.5...4.0)
project(
  qb
  VERSION 0.0.1
  LANGUAGES CXX
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_BUILD_TYPE DEBUG)
set(CXX_STANDARD C++17)
set(CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS_DEBUG "-DNDEBUG -g -Wall -Wextra -Wpedantic")

set(PROJECT_SOURCE_DIR src/)

file(GLOB SOURCES "src/*.cpp")
add_executable(qb ${SOURCES})
