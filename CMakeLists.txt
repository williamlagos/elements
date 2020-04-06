cmake_minimum_required(VERSION 3.16)
project(elements)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_BUILD_TYPE DEBUG)
set(LOCAL_UNIX_INCLUDE /usr/local/include)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(vendor)
set(SOURCES 
    src/main.cc 
    src/modules.cc
    src/ranking.cc 
    src/elements.cc
    src/network.cc
    src/matrix.cc 
    src/tree.cc
    vendor/json.cc 
    vendor/wslib.cc)
set(INCLUDE 
    include/utils.h 
    include/modules.h 
    include/ranking.h 
    include/elements.h 
    include/network.h
    include/matrix.h 
    include/tree.h 
    vendor/json.h 
    vendor/httplib.h 
    vendor/wslib.h)
add_executable(elements ${SOURCES} ${INCLUDE})
