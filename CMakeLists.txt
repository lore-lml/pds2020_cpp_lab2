cmake_minimum_required(VERSION 3.15)
project(lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp classes/Directory.cpp classes/Directory.h classes/Base.h classes/File.cpp classes/File.h)