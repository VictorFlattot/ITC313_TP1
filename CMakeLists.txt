cmake_minimum_required(VERSION 3.23)
project(Library)

set(CMAKE_CXX_STANDARD 11)

add_executable(Library src/main.cpp src/date.cpp src/book.cpp src/writer.cpp src/reader.cpp src/reader.h src/loan.cpp src/library.cpp)
