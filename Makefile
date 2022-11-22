CXX=g++
THIRD_PARTY=third_party/
INCLUDE=include/
CXXFLAGS=-Wall -Wconversion -Wextra -I$(INCLUDE) -I$(THIRD_PARTY)
BUILD=build
DOXYGEN=doxygen
DOXYFILE=Doxyfile
MKDIR=mkdir
BUILD_TEST=$(BUILD)/test

carta.o:
	$(CXX) $(CXXFLAGS) -c src/carta.cpp -o $(BUILD)/carta.o
carta_especial.o:
	$(CXX) $(CXXFLAGS) -c src/carta_especial.cpp -o $(BUILD)/carta_especial.o
interface.o:
	$(CXX) $(CXXFLAGS) -c src/interface.cpp -o $(BUILD)/interface.o
jogador.o:
	$(CXX) $(CXXFLAGS) -c src/jogador.cpp -o $(BUILD)/jogador.o
mao.o:
	$(CXX) $(CXXFLAGS) -c src/mao.cpp -o $(BUILD)/mao.o
partida.o:
	$(CXX) $(CXXFLAGS) -c src/partida.cpp -o $(BUILD)/partida.o
pilha.o:
	$(CXX) $(CXXFLAGS) -c src/pilha.cpp -o $(BUILD)/pilha.o

main: carta.o carta_especial.o interface.o jogador.o mao.o partida.o pilha.o
	$(CXX) $(CXXFLAGS) $(BUILD)/carta.o $(BUILD)/carta_especial.o $(BUILD)/interface.o $(BUILD)/jogador.o $(BUILD)/mao.o $(BUILD)/partida.o $(BUILD)/pilha.o src/main.cpp -o $(BUILD)/main

docs:
	$(DOXYGEN) $(DOXYFILE)

test_dir:
	$(MKDIR) -p $(BUILD_TEST)

carta.test: test_dir carta.o
	$(CXX) $(CXXFLAGS) $(BUILD)/carta.o test/carta.cpp -o $(BUILD_TEST)/carta

carta_especial.test: test_dir carta_especial.o carta.o
	$(CXX) $(CXXFLAGS) $(BUILD)/carta_especial.o $(BUILD)/carta.o test/carta_especial.cpp -o $(BUILD_TEST)/carta_especial
interface.test: test_dir interface.o partida.o carta.o jogador.o mao.o pilha.o
	$(CXX) $(CXXFLAGS) $(BUILD)/interface.o $(BUILD)/carta.o $(BUILD)/jogador.o $(BUILD)/mao.o $(BUILD)/partida.o $(BUILD)/pilha.o  test/interface.cpp -o $(BUILD_TEST)/interface
jogador.test: test_dir jogador.o carta.o mao.o
	$(CXX) $(CXXFLAGS) $(BUILD)/jogador.o $(BUILD)/carta.o $(BUILD)/mao.o test/jogador.cpp -o $(BUILD_TEST)/jogador
mao.test: test_dir mao.o carta.o
	$(CXX) $(CXXFLAGS) $(BUILD)/mao.o $(BUILD)/carta.o test/mao.cpp -o $(BUILD_TEST)/mao
partida.test: test_dir partida.o carta.o jogador.o mao.o pilha.o
	$(CXX) $(CXXFLAGS) $(BUILD)/partida.o $(BUILD)/carta.o $(BUILD)/jogador.o $(BUILD)/mao.o $(BUILD)/pilha.o test/partida.cpp -o $(BUILD_TEST)/partida
pilha.test: test_dir pilha.o carta.o
	$(CXX) $(CXXFLAGS) $(BUILD)/pilha.o $(BUILD)/carta.o test/pilha.cpp -o $(BUILD_TEST)/pilha

test: carta.test carta_especial.test interface.test jogador.test mao.test partida.test pilha.test

libuno.so: carta.o carta_especial.o interface.o jogador.o mao.o partida.o pilha.o
	$(CXX) $(CXXFLAGS) -shared $(BUILD)/carta.o $(BUILD)/carta_especial.o $(BUILD)/interface.o $(BUILD)/jogador.o $(BUILD)/mao.o $(BUILD)/partida.o $(BUILD)/pilha.o -o $(BUILD)/libuno.so

all: main docs test libuno.so

clean:
	rm -r $(BUILD)/*