all:	
	g++ -c -g -std=c++11 bfs.cpp
	g++ -c -g -std=c++11 bucket.cpp
	g++ -c -g -std=c++11 Buffer.cpp
	g++ -c -g -std=c++11 BufferNode.cpp
	g++ -c -g -std=c++11 graphLibrary.cpp
	g++ -c -g -std=c++11 Grails.cpp
	g++ -c -g -std=c++11 GrailsNode.cpp
	g++ -c -g -std=c++11 HashTable.cpp
	g++ -c -g -std=c++11 Index.cpp
	g++ -c -g -std=c++11 IndexNode.cpp
	g++ -c -g -std=c++11 queue.cpp
	g++ -c -g -std=c++11 cc.cpp
	g++ -c -g -std=c++11 scc.cpp
	g++ -c -g -std=c++11 Component.cpp
	g++ -c -g -std=c++11 ComponentCursor.cpp
	g++ -c -g -std=c++11 cc.cpp
	g++ -c -g -std=c++11 main.cpp
	g++ -c -g -std=c++11 Stack.cpp
	g++ main.o cc.o Grails.o Stack.o GrailsNode.o Component.o ComponentCursor.o scc.o queue.o bfs.o bucket.o Buffer.o BufferNode.o graphLibrary.o HashTable.o Index.o IndexNode.o
