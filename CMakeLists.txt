cmake_minimum_required(VERSION 3.30)
project(MathLib)

set(CMAKE_CXX_STANDARD 20)

add_library(math_lib SHARED
        src/math_lib.cpp
        src/capi/wrapper.cpp
)

target_include_directories(math_lib PUBLIC include)

if(WIN32)
    target_compile_definitions(math_lib PRIVATE MATH_LIB_EXPORTS)
endif()

find_package(GTest REQUIRED)
add_executable(math_lib_test  test/math_lib_test.cpp)
target_link_libraries(math_lib_test GTest::GTest GTest::Main math_lib)

enable_testing()
add_test(NAME math_lib_test COMMAND math_lib_test)