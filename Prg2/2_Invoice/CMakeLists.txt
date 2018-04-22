cmake_minimum_required(VERSION 3.10)
project(SchoolProject)

set(CMAKE_CXX_STANDARD 11)

add_executable(SchoolProject main.cpp Invoice.cpp Invoice.h Person.cpp Person.h InvoiceItem.cpp InvoiceItem.h)