# Minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.0)

# Name of the project
project(CConducao)

set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_FLAGS "-std=c++17 -lstdc++fs -g") 

# Add all the source files needed to build the executable
add_executable(
    CConducao
    src/main.cpp 
    src/CCondutividade.cpp 
    src/CFluxoCalor.cpp 
)

# Include the directory where MyLibrary project is. Otherwise, we can't use the
# library
add_subdirectory(libs/InterLin)
# add_subdirectory(libs/qcustomplot/src)

# Link the executable and the library together
target_link_libraries(CConducao InterLin)
# target_link_libraries(CConducao InterLin qcustomplot)