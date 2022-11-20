CXX=g++
INCLUDE=include/
CXXFLAGS=-Wall -Wconversion -Wextra -I$(INCLUDE)
BUILD=build


main:
	$(CXX) $(CXXFLAGS) src/main.cpp -o $(BUILD)/main

all: main