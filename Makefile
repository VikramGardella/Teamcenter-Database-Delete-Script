SOURCES = main.cpp Item.cpp
OBJECTS = main.o Item.o

deleteScript: main.cpp Item.cpp
	g++ -o deleteScript main.cpp Item.cpp

CXXFLAGS = -std=c++11 -D_GNU_SOURCE -Wall
