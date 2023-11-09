cmake_minimum_required(VERSION 3.13)

project(TestSwig VERSION 1.0 LANGUAGES CXX)
### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB NORMAL_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

configure_file (
    "${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/version.h"
)


set(PACKAGE_TARGET_LANGUAGE "PYTHON")
set(PYTHON_INCLUDE_DIR "D:\\py10\\include")
set(PYTHON_LIBS_DIR "D:\\py10\\libs")
set(CMAKE_CXX_STANDARD 20)

include("cmake/SwigPython.cmake")
include("cmake/SwigCSharp.cmake")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")

if(PACKAGE_TARGET_LANGUAGE STREQUAL "PYTHON")
    BuildPythonLibrary(TestSwig)
elseif(PACKAGE_TARGET_LANGUAGE STREQUAL "CSHARP")
    BuildCSharpLibrary(TestSwig)
else()
    message(FATAL_ERROR "not set language name on PACKAGE_TARGET_LANGUAGE variable")
endif()
