cmake_minimum_required(VERSION 3.9)
project(Bank)

set(CMAKE_CXX_STANDARD 11)

add_executable(Bank main.cpp Bank.cpp Bank.h Client.cpp Client.h Account.cpp Account.h PartnerAccount.cpp PartnerAccount.h CreditAccount.cpp CreditAccount.h)