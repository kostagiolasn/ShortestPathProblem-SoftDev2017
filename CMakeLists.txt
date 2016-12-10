cmake_minimum_required(VERSION 3.6)
project(ShortestPathProblem_SoftDev2017)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    cc.cpp
    cc.hpp
    updateIndex.cpp
    updateIndex.hpp
    bfs.cpp
    bfs.hpp
    buffer.cpp
    buffer.hpp
    hashTable.cpp
    hashTable.hpp
    index.cpp
    index.hpp
    main.cpp
    nodeIndex.cpp
    nodeIndex.hpp
    nodeList.cpp
    nodeList.hpp
    queue.cpp
    queue.hpp
)

add_executable(ShortestPathProblem_SoftDev2017 ${SOURCE_FILES})