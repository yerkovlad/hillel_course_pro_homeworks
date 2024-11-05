cmake_minimum_required(VERSION 3.10)

project(BankTransactions)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(BankTransactions
    main.cpp
    Logger.cpp
    Transaction.cpp
    ShortReportVisitor.cpp
    DetailedReportVisitor.cpp
)

target_include_directories(BankTransactions PUBLIC "${PROJECT_SOURCE_DIR}")