cmake_minimum_required(VERSION 3.28)
project(banking_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(banking_system main.cpp
        person.cpp
        person.h
        i_account.h
        i_funds.h
        i_manager.h
        standard_account.cpp
        standard_account.h
        premium_account.cpp
        premium_account.h
        funds_pln.cpp
        funds_pln.h
        funds_usd.cpp
        funds_usd.h
        funds_eur.cpp
        funds_eur.h
        premium_account_manager.cpp
        premium_account_manager.h
        standard_account_manager.cpp
        standard_account_manager.h)
