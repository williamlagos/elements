cmake_minimum_required(VERSION 3.16)
project(elements VERSION 1.0.0 LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(vendor)

set(LIB_SOURCES 
    src/modules.cc
    src/ranking.cc 
    src/elements.cc
    src/network.cc
    src/matrix.cc 
    src/tree.cc
    vendor/json.cc 
    vendor/wslib.cc)

set(LIB_HEADERS 
    include/modules.h 
    include/ranking.h 
    include/elements.h 
    include/network.h
    include/matrix.h 
    include/tree.h 
    vendor/tree.hh
    vendor/json.h 
    vendor/httplib.h 
    vendor/wslib.h)

add_library(elements_core STATIC ${LIB_SOURCES} ${LIB_HEADERS})
target_include_directories(elements_core PUBLIC include vendor)

add_executable(elements src/main.cc)
target_link_libraries(elements PRIVATE elements_core)
