
LEDAROOT=./LEDA

#LIBS = -Wl,-rpath=$(LEDAROOT) -L$(LEDAROOT) -lleda -lX11 -lm
#INCLUDE = -I$(LEDAROOT)/incl 
CXXFLAGS += -Wall -std=c++11

all: build/main.o build/Vertex.o build/Graph.o
	g++ build/main.o build/Vertex.o build/Graph.o -o build/main $(LDFLAGS)

check: build/Vertex.o build/Graph.o
	g++ build/Vertex.o build/Graph.o -o build/check $(LDFLAGS)

build/Vertex.o: Vertex.cpp Vertex.hpp
	g++ -c -o $@ $< $(CXXFLAGS)

build/Graph.o: Graph.cpp Graph.hpp Vertex.hpp
	g++ -c -o $@ $< $(CXXFLAGS)

build/main.o: main.cpp Graph.hpp Vertex.hpp
	g++ -c -o $@ $< $(CXXFLAGS)

example:
	g++ example.cpp -o build/example $(CXXFLAGS)

clean: 
	rm -r build/*