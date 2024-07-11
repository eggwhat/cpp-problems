cmake_minimum_required(VERSION 3.28)
project(banking_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(banking_system main.cpp
        person.cpp
        person.h
        i_account.h
        i_funds.h
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
        i_manager.h
        premium_account_manager.cpp
        premium_account_manager.h
        standard_account_manager.cpp
        standard_account_manager.h
        maintenance.cpp
        maintenance.h
        manager_factory.h
        standard_account_manager_factory.cpp
        standard_account_manager_factory.h
        premium_account_manager_factory.cpp
        premium_account_manager_factory.h
        command_line_interface.cpp
        command_line_interface.h
        funds.h
        account.h
        funds.cpp)
