cmake_minimum_required(VERSION 3.13)

project(TestSwig)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB NORMAL_SRCS "${CMAKE_SOURCE_DIR}/src/*.cpp")

set(PACKAGE_TARGET_LANGUAGE "PYTHON")
set(PYTHON_INCLUDE_DIR "D:\\py10\\include")
set(PYTHON_LIBS_DIR "D:\\py10\\libs")
set(CMAKE_CXX_STANDARD 20)

include("cmake/SwigPython.cmake")
include("cmake/SwigCSharp.cmake")

include_directories("${CMAKE_SOURCE_DIR}/src")

if(PACKAGE_TARGET_LANGUAGE STREQUAL "PYTHON")
    BuildPythonLibrary(TestSwig)
elseif(PACKAGE_TARGET_LANGUAGE STREQUAL "CSHARP")
    BuildCSharpLibrary(TestSwig)
else()
    message(FATAL_ERROR "not set language name on PACKAGE_TARGET_LANGUAGE variable")
endif()
