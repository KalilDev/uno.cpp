CXX=g++
THIRD_PARTY=third_party/
INCLUDE=include/
CXXFLAGS=-Wall -Wconversion -Wextra -I$(INCLUDE) -I$(THIRD_PARTY)
BUILD=build


add.o:
	$(CXX) $(CXXFLAGS) -c src/add.cpp -o $(BUILD)/add.o

main: add.o
	$(CXX) $(CXXFLAGS) $(BUILD)/add.o src/main.cpp -o $(BUILD)/main

all: main