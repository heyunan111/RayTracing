cmake_minimum_required(VERSION 3.27.0)
project(RayTracing VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(RayTracing main.cpp vec3.hpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
