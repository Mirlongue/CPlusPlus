cmake_minimum_required(VERSION 3.29)

project(demo)

add_executable(demo
    main.cpp
    sub/cas_00.cpp
    sub/cas_01.cpp
    sub/cas_02.cpp
    sub/cas_03.cpp
    sub/cas_04.cpp
    sub/cas_05.cpp
    sub/cas_06.cpp
    sub/cas_07.cpp
    sub/cas_08.cpp
    sub/cas_09.cpp
    sub/cas_10.cpp
    sub/cas_11.cpp
    sub/cas_12.cpp
    )

target_compile_options(demo PRIVATE -fno-inline -fno-access-control)
