cmake_minimum_required(VERSION 3.5)
project(cmake_wrapper)

include(conanbuildinfo.cmake)
conan_basic_setup()

include(${CMAKE_SOURCE_DIR}/CMakeListsOriginal.txt)
