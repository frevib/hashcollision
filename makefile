CXX = g++
CXXFLAGS = -Wall -std=c++11
BIN = charindex
OBJ = charindex.o timer.o

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	rm -f *.o $(BIN)

.PHONY: clean all
