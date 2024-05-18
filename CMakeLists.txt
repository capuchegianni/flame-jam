cmake_minimum_required(VERSION 3.10)
project(toufeutouflam)

set(CMAKE_CXX_STANDARD 20)

set(WARNING_FLAGS -Wall -W -g -g3 -std=c++20)
set(SFML_FLAGS -lsfml-graphics -lsfml-window -lsfml-system)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

include_directories(include)

set(src
    src/main.cpp
    src/Game/Game.cpp
    src/Game/Menu/Menu.cpp
    src/Game/Game/Game.cpp
    src/Game/Input.cpp
)

add_executable(toufeutouflam ${src})
target_compile_options(toufeutouflam PRIVATE ${WARNING_FLAGS} ${SFML_FLAGS})
target_link_libraries(toufeutouflam sfml-graphics sfml-window sfml-system config++)