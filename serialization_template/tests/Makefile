CXX = g++
CXXFLAGS  = -pedantic -Wall -lgtest

SRC = tests
OBJ=$(SRC:%=%.o)
EXE = tests

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXE) $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(EXE)

.PHONY: all clean
