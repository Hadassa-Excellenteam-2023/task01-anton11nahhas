﻿
cmake_minimum_required (VERSION 3.15)

project ("tasks_week1_Anton_Nahhas")

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()

cmake_minimum_required (VERSION 3.15)
project (HelloWorld)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
add_compile_options (/W4 /permissive- /Zc:externConstexpr /Zc:inline)
endif ()


add_executable (tasks_week1_Anton_Nahhas)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET tasks_week1_Anton_Nahhas PROPERTY CXX_STANDARD 20)
endif()

add_subdirectory (include)
add_subdirectory (src)


