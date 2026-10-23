cmake_minimum_required(VERSION 3.31)
project(gfx-base LANGUAGES CXX)

# Required for intellisense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Dependencies
include(CTest) # Required before Dependencies.cmake to provide BUILD_TESTING
include(cmake/Dependencies.cmake) # Utilizes CPM to download dependencies

# Core library
add_subdirectory(src/lib)

# Executable 
add_executable(gfx-base)
target_sources(gfx-base
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src/main.cpp
)
target_include_directories(gfx-base PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)
target_link_libraries(gfx-base PRIVATE core)

# Test target
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
