CXX = g++
CXXFLAGS  = -pedantic -Wall -lgtest

SRC = test
OBJ=$(SRC:%=%.o)
EXE = test

all: $(EXE)

$(EXE): test.cpp
	$(CXX) $(CXXFLAGS) -o $(EXE) $^

clean:
	rm -f *.o $(EXE)

.PHONY: all clean
