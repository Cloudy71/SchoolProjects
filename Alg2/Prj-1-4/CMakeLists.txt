cmake_minimum_required(VERSION 3.9)
project(Prj-1-4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:/Users/User/Documents/GIT_SchoolProjects/Alg2/Prj-1-4/cmake-build-debug/binaries")
set(CMAKE_CXX_FLAGS "-static")

add_executable(Prj-1-4 main.cpp List.h List.cpp ProjectListImpl.cpp ProjectListAdds.h)