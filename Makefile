CXX=g++
THIRD_PARTY=third_party/
INCLUDE=include/
CXXFLAGS=-Wall -Wconversion -Wextra -I$(INCLUDE) -I$(THIRD_PARTY)
BUILD=build
DOXYGEN=doxygen
DOXYFILE=Doxyfile
MKDIR=mkdir
BUILD_TEST=$(BUILD)/test

add.o:
	$(CXX) $(CXXFLAGS) -c src/add.cpp -o $(BUILD)/add.o

main: add.o
	$(CXX) $(CXXFLAGS) $(BUILD)/add.o src/main.cpp -o $(BUILD)/main

docs:
	$(DOXYGEN) $(DOXYFILE)

test_dir:
	$(MKDIR) -p $(BUILD_TEST)

add.test: test_dir add.o
	$(CXX) $(CXXFLAGS) $(BUILD)/add.o test/add.cpp -o $(BUILD_TEST)/add

test: add.test

all: main docs test

clean:
	rm -r $(BUILD)/*