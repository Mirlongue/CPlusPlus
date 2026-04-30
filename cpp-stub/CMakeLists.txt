cmake_minimum_required(VERSION 3.29)

project(demo)

add_executable(demo
    main.cpp
    sub/cas_0.cpp)

target_compile_options(demo PRIVATE -fno-inline -fno-access-control)
