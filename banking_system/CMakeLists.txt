cmake_minimum_required(VERSION 3.12)

project(BankingSystem
        VERSION 1.0
        DESCRIPTION "Simple Banking System"
        LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
endif()


find_package(Boost REQUIRED)

add_subdirectory(src)

add_subdirectory(apps)

