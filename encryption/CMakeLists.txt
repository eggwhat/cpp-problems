cmake_minimum_required(VERSION 3.28)
project(encryption)

set(CMAKE_CXX_STANDARD 14)

add_executable(encryption main.cpp caesar.cpp caesar.h i_encryption.h
        modern_caesar.cpp
        modern_caesar.h)
