cmake_minimum_required(VERSION 3.12)

project(BankingSystem
        VERSION 1.0
        DESCRIPTION "Simple Banking System"
        LANGUAGES CXX)

find_package(Boost REQUIRED)

add_subdirectory(src)

add_subdirectory(apps)

