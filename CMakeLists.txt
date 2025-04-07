cmake_minimum_required(VERSION 3.30)
project(cpp_oop_review)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

#buscar la carpeta include en los directorios
include_directories(${PROJECT_SOURCE_DIR}/include)

#define the executable target
add_executable(cpp_oop_review main.cpp
        src/Resource.cpp
        src/Executable.cpp
        src/UsableResource.cpp
        src/ConsumableResource.cpp
        include/Task.cpp)
