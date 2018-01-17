CXX = g++
CXXFLAGS  = -pedantic -Wall

SRC = main MyVector
OBJ=$(SRC:%=%.o)
EXE = serialization

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXE) $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(EXE)

.PHONY: all clean
