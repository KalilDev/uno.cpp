CXX=g++
INCLUDE=include/
CXXFLAGS=-Wall -Wconversion -Wextra -I$(INCLUDE)
BUILD=build


add.o:
	$(CXX) $(CXXFLAGS) -c src/add.cpp -o $(BUILD)/add.o

main: add.o
	$(CXX) $(CXXFLAGS) $(BUILD)/add.o src/main.cpp -o $(BUILD)/main

all: main