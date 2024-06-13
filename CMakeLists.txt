cmake_minimum_required(VERSION 3.10)
project(Tethis VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(CPack)

file(GLOB_RECURSE sources CMAKE_CONFIGURE_DEPENDS "src/**/*.hpp" "src/**/*.h" "src/**/*.cpp" "src/**/*.c")

include_directories(
    src/**
    /usr/include/**
    /usr/local/include/**
)

add_executable(Tethis src/main.cpp ${sources})

target_compile_features(Tethis PUBLIC cxx_std_20)