all:
    g++ -c -g main.cpp
    g++ -c -g bfs.cpp
    g++ -c -g buffer.cpp
    g++ -c -g hashTable.cpp
    g++ -c -g index.cpp
    g++ -c -g nodeIndex.cpp
    g++ -c -g nodeList.cpp
    g++ -c -g queue.cpp
    g++ -c -g cc.cpp
    g++ cc.o bfs.o buffer.o hashTable.o index.o nodeIndex.o nodeList.o queue.o main.o