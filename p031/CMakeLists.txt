cmake_minimum_required ( VERSION 3.5.1 )
project ( p031 )
add_executable ( prog p031.cpp )
target_compile_features ( prog PRIVATE cxx_range_for )
set( CMAKE_CXX_COMPILER "/usr/bin/clang++" )
set( CMAKE_CXX_FLAGS "-Wall" )
set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )
include_directories("../headers")
