cmake_minimum_required(VERSION 3.6)
project(ShortestPathProblem_SoftDev2017)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    bfs.cpp
    bfs.hpp
    bucket.cpp
    bucket.hpp
    Buffer.cpp
    Buffer.hpp
    BufferNode.cpp
    BufferNode.hpp
    cc.cpp
    cc.hpp
    Component.cpp
    Component.hpp
    ComponentCursor.cpp
    ComponentCursor.hpp
    Grails.cpp
    Grails.h
    GrailsNode.cpp
    GrailsNode.h
    graphLibrary.cpp
    graphLibrary.hpp
    HashTable.cpp
    HashTable.hpp
    Index.cpp
    Index.hpp
    IndexNode.cpp
    IndexNode.hpp
    main.cpp
    queue.cpp
    queue.hpp
    scc.cpp
    scc.hpp
    stack.cpp
    stack.hpp
        )

add_executable(ShortestPathProblem_SoftDev2017 ${SOURCE_FILES})