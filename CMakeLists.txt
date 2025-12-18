cmake_minimum_required(VERSION 3.10)

project(bank)

set(CMAKE_CXX_STANDARD 17)

add_executable(bank

    main.cc
    Account.cc
    Customer.cc
    Transaction.cc
    BankSystem.cc
)

