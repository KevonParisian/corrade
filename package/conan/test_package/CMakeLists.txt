cmake_minimum_required(VERSION 3.5)
project(test_package)

set(CMAKE_VERBOSE_MAKEFILE TRUE)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME} test_package.cpp)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    	CXX_STANDARD 11
    	CXX_STANDARD_REQUIRED ON
    	CXX_EXTENSIONS OFF
)
