CXX = g++
CXXFLAGS  = -pedantic -Wall

SRC = main class
OBJ=$(SRC:%=%.o)
EXE = class_cpp11

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXE) $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(EXE)

.PHONY: all clean
