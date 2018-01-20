CXX = g++
CXXFLAGS = -pedantic -Wall -std=c++14

SRC = main testlog
OBJ=$(SRC:%=%.o)
HDR= testlog
EXE = logger

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXE) $^

main.o: main.cpp testlog.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ main.cpp

testlog.o: testlog.cpp testlog.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ testlog.cpp


clean:
	rm -f *.o $(EXE)

.PHONY: all clean
