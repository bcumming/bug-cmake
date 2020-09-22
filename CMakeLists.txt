cmake_minimum_required(VERSION 3.6)
project(example)
enable_language(CXX)

# required to use in pthon .so files
set(CMAKE_CXX_FLAGS "-fPIC")
set(CMAKE_CXX_STANDARD 11)

# Set up pybind.
# Add support for pybind by adding the directory of pybind11, instead of using
# find_package().
add_subdirectory(pybind11)

pybind11_add_module(tmod tmod.cpp)

