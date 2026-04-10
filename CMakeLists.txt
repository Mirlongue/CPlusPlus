cmake_minimum_required(VERSION 3.29)
project(demo)

add_executable(demo main.cpp
                    func/func_base.cpp
                    func/func_factory.cpp
                    func/case/func_case.cpp)

target_include_directories(demo PUBLIC
     ${CMAKE_CURRENT_SOURCE_DIR}/func
     ${CMAKE_CURRENT_SOURCE_DIR}/func/case
)


