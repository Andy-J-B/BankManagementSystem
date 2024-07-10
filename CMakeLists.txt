cmake_minimum_required(VERSION 3.28)
project(BankManagementSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(BankManagementSystem main.cpp
        sqlite.cpp
        Account.cpp
        BankManagement.cpp
        EmptyDataCollectionException.cpp
        sqlite3.c
        sqlite3.h
        Stack.cpp
        Sqlite.h
        ExceededTryLimitException.cpp
        ExceededTryLimitException.h
        WrongPasswordException.cpp
        WrongPasswordException.h)
