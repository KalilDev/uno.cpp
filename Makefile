CXX=g++
THIRD_PARTY=third_party/
INCLUDE=include/
CXXFLAGS=-std=c++17 -Werror -Wall -Wconversion -Wextra -Wno-unknown-pragmas -fPIC -g -I$(INCLUDE) -I$(THIRD_PARTY)
BUILD=build
DOXYGEN=doxygen
DOXYFILE=Doxyfile
MKDIR=mkdir
BUILD_TEST=$(BUILD)/test

build_dir:
	$(MKDIR) -p $(BUILD)

util.o: build_dir src/util.cpp
	$(CXX) $(CXXFLAGS) -c src/util.cpp -o $(BUILD)/util.o
carta.o: build_dir src/carta.cpp
	$(CXX) $(CXXFLAGS) -c src/carta.cpp -o $(BUILD)/carta.o
carta_especial.o: build_dir src/carta_especial.cpp
	$(CXX) $(CXXFLAGS) -c src/carta_especial.cpp -o $(BUILD)/carta_especial.o
interface.o: build_dir src/interface.cpp
	$(CXX) $(CXXFLAGS) -c src/interface.cpp -o $(BUILD)/interface.o
jogador.o: build_dir src/jogador.cpp
	$(CXX) $(CXXFLAGS) -c src/jogador.cpp -o $(BUILD)/jogador.o
mao.o: build_dir src/mao.cpp
	$(CXX) $(CXXFLAGS) -c src/mao.cpp -o $(BUILD)/mao.o
partida.o: build_dir src/partida.cpp
	$(CXX) $(CXXFLAGS) -c src/partida.cpp -o $(BUILD)/partida.o
pilha.o: build_dir src/pilha.cpp
	$(CXX) $(CXXFLAGS) -c src/pilha.cpp -o $(BUILD)/pilha.o

docs: include/capi.h include/carta.hpp include/carta_especial.hpp include/interface.hpp include/jogador.hpp include/mao.hpp include/partida.hpp include/pilha.hpp include/util.hpp
	$(DOXYGEN) $(DOXYFILE)

test_dir:
	$(MKDIR) -p $(BUILD_TEST)

carta.test: test_dir carta.o util.o
	$(CXX) $(CXXFLAGS) $(BUILD)/carta.o $(BUILD)/util.o test/carta.cpp -o $(BUILD_TEST)/carta
carta_especial.test: test_dir carta_especial.o carta.o util.o
	$(CXX) $(CXXFLAGS) $(BUILD)/carta_especial.o $(BUILD)/carta.o test/carta_especial.cpp -o $(BUILD_TEST)/carta_especial
interface.test: test_dir interface.o partida.o carta.o carta_especial.o jogador.o mao.o pilha.o util.o
	$(CXX) $(CXXFLAGS) $(BUILD)/interface.o $(BUILD)/carta.o $(BUILD)/carta_especial.o $(BUILD)/jogador.o $(BUILD)/mao.o $(BUILD)/partida.o $(BUILD)/pilha.o $(BUILD)/util.o test/interface.cpp -o $(BUILD_TEST)/interface
jogador.test: test_dir jogador.o carta.o carta_especial.o mao.o util.o
	$(CXX) $(CXXFLAGS) $(BUILD)/jogador.o $(BUILD)/carta.o $(BUILD)/carta_especial.o $(BUILD)/mao.o $(BUILD)/util.o test/jogador.cpp -o $(BUILD_TEST)/jogador
mao.test: test_dir mao.o carta.o carta_especial.o util.o
	$(CXX) $(CXXFLAGS) $(BUILD)/mao.o $(BUILD)/carta.o $(BUILD)/carta_especial.o $(BUILD)/util.o test/mao.cpp -o $(BUILD_TEST)/mao
partida.test: test_dir partida.o carta.o carta_especial.o jogador.o mao.o pilha.o util.o
	$(CXX) $(CXXFLAGS) $(BUILD)/partida.o $(BUILD)/carta.o $(BUILD)/carta_especial.o $(BUILD)/jogador.o $(BUILD)/mao.o $(BUILD)/pilha.o $(BUILD)/util.o test/partida.cpp -o $(BUILD_TEST)/partida
pilha.test: test_dir pilha.o carta.o carta_especial.o
	$(CXX) $(CXXFLAGS) $(BUILD)/pilha.o $(BUILD)/carta.o $(BUILD)/carta_especial.o test/pilha.cpp -o $(BUILD_TEST)/pilha
util.test: test_dir util.o
	$(CXX) $(CXXFLAGS) $(BUILD)/util.o test/util.cpp -o $(BUILD_TEST)/util

tests: carta.test carta_especial.test interface.test jogador.test mao.test partida.test pilha.test util.test

libuno.so: carta.o carta_especial.o interface.o jogador.o mao.o partida.o pilha.o util.o
	$(CXX) $(CXXFLAGS) -shared $(BUILD)/carta.o $(BUILD)/carta_especial.o $(BUILD)/interface.o $(BUILD)/jogador.o $(BUILD)/mao.o $(BUILD)/partida.o $(BUILD)/pilha.o $(BUILD)/util.o -o $(BUILD)/libuno.so

run_tests: tests
	-$(BUILD_TEST)/carta
	-$(BUILD_TEST)/carta_especial
	-$(BUILD_TEST)/interface
	-$(BUILD_TEST)/jogador
	-$(BUILD_TEST)/mao
	-$(BUILD_TEST)/partida
	-$(BUILD_TEST)/pilha
	-$(BUILD_TEST)/util

all: docs tests libuno.so

clean:
	rm -r $(BUILD)/*