
LEDAROOT=./LEDA

LIBS = -Wl,-rpath=$(LEDAROOT) -L$(LEDAROOT) -lleda -lX11 -lm
INCLUDE = -I$(LEDAROOT)/incl 
CXXFLAGS += $(INCLUDE)

all:
	g++ Vertex.cpp Graph.cpp main.cpp -o build/main -Wall -std=c++11

check:
	g++ Vertex.cpp Graph.cpp concepts/VertexList.cpp -o build/check -Wall -std=c++11

leda:
	g++ Vertex.cpp Graph.cpp concepts/leda.cpp -o build/leda -Wall -std=c++11 $(LIBS)

clean: 
	rm -r build/*