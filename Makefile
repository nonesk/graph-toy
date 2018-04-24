
LEDAROOT=./LEDA

LIBS = -Wl,-rpath=$(LEDAROOT) -L$(LEDAROOT) -lleda -lX11 -lm
INCLUDE = -I$(LEDAROOT)/incl 
CXXFLAGS += $(INCLUDE) -Wall -std=c++11

all:
	g++ Vertex.cpp Graph.cpp main.cpp -o build/main $(CXXFLAGS)

check: build/Vertex.o build/Graph.o
	g++ build/Vertex.o build/Graph.o -o build/check $(CXXFLAGS)

build/Vertex.o: Vertex.cpp Vertex.hpp
	g++ -c -o build/Vertex.o Vertex.cpp $(CXXFLAGS)

build/Graph.o: Graph.cpp Graph.hpp Vertex.hpp
	g++ -c -o build/Graph.o Graph.cpp $(CXXFLAGS)

clean: 
	rm -r build/*