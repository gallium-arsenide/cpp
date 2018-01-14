CXX = g++
CXXFLAGS  = -pedantic -Wall

SRC = main BaseClass SomeClass SomeOtherClass ClassWithDiamondProblem
OBJ=$(SRC:%=%.o)
EXE = diamond

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXE) $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(EXE)

.PHONY: all clean
