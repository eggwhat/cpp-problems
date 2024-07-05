cmake_minimum_required(VERSION 3.28)
project(banking_system)

set(CMAKE_CXX_STANDARD 14)

add_executable(banking_system main.cpp
        bank_account.h
        person.cpp
        person.h
        checking_account.cpp
        checking_account.h
        saving_account.cpp
        saving_account.h
        i_account.h
        i_account_balance.h
        i_funds.h)
