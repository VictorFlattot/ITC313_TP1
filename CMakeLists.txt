cmake_minimum_required(VERSION 3.23)
project(ITC313_TP1)

set(CMAKE_CXX_STANDARD 11)

add_executable(ITC313_TP1 src/main.cpp src/date.cpp src/book.cpp src/writer.cpp src/reader.cpp src/reader.h src/loan.cpp src/library.cpp src/test/test.h src/test/test.cpp src/test/dateTest.cpp src/test/dateTest.h)
