CXX = g++
CXXFLAGS = -Wall -std=c++17
INCLUDES = -Imodules
LIBS = -lsqlite3

SRC = $(wildcard src/*.cpp modules/*.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = miniFarmacia

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC) $(LIBS)

clean:
	rm -f $(OBJ) $(EXEC)
