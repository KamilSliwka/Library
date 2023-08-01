cmake_minimum_required(VERSION 3.24)
project(Library)

set(CMAKE_CXX_STANDARD 17)

add_executable(Library main.cpp Book.cpp Book.h Library.cpp Library.h)
