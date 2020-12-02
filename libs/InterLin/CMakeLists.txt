cmake_minimum_required(VERSION 3.0)

project(InterLin)

file(GLOB LIB_SRC src/*.cpp)

add_library(InterLin ${LIB_SRC})