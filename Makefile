CXX=g++
THIRD_PARTY=third_party/
INCLUDE=include/
CXXFLAGS=-Wall -Wconversion -Wextra -I$(INCLUDE) -I$(THIRD_PARTY)
BUILD=build
DOXYGEN=doxygen
DOXYFILE=Doxyfile


add.o:
	$(CXX) $(CXXFLAGS) -c src/add.cpp -o $(BUILD)/add.o

main: add.o
	$(CXX) $(CXXFLAGS) $(BUILD)/add.o src/main.cpp -o $(BUILD)/main

docs:
	$(DOXYGEN) $(DOXYFILE)

all: main docs