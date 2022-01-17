cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(poo_projeto VERSION 0.1.0)

#include(CTest)
#enable_testing()

add_library(Projeto_Lib STATIC
        src/interface.h
        src/interface.cpp
        src/files.cpp
        src/files.h
        src/program.cpp
        src/program.h
        src/commands.cpp
        src/commands.h
        src/island.cpp
        src/island.h
        src/tile.cpp
        src/tile.h
        src/utils.cpp
        src/utils.h
        #src/vector.cpp # removed due to linking issues with the template class
        src/vector.h
        src/workers.cpp
        src/workers.h
        src/buildings.cpp
        src/buildings.h
        src/interpreter.cpp
        src/interpreter.h
        src/resources.h
        src/resources.cpp)
target_include_directories(Projeto_Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC Projeto_Lib)