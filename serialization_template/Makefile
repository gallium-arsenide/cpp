CXX = g++
CXXFLAGS = -pedantic -Wall

SRC = main
OBJ=$(SRC:%=%.o)
HDR= SeDePrimitive.hpp SeDeVector.hpp
EXE = serialization

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXE) $^

main.o: main.cpp SeDeVector.hpp SeDePrimitive.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ main.cpp

clean:
	rm -f *.o $(EXE)

.PHONY: all clean
