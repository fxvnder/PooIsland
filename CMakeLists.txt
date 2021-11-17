cmake_minimum_required(VERSION 3.20)
project(PooIsland)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        REQUIRED)

add_executable(PooIsland main.cpp program.cpp interface.cpp interface.h ficheiros.cpp ficheiros.h)
target_link_libraries(PooIsland
        Qt5::Core
        )

