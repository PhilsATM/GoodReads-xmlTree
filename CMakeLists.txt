cmake_minimum_required(VERSION 3.10)
project(GoodReadsXMLTree)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(tinyxml2
    external/tinyxml2/tinyxml2.cpp
)

target_include_directories(tinyxml2 PUBLIC
    ${CMAKE_SOURCE_DIR}/external/tinyxml2
)

add_executable(goodreads_tree
    src/main.cpp
    src/node.cpp
    src/parser.cpp
    src/treeFuncs.cpp
)

target_include_directories(goodreads_tree PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/tinyxml2
)

target_link_libraries(goodreads_tree PRIVATE tinyxml2)