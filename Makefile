# Please complete this Makefile as needed. You can study the Makefile in project 3 to get an idea of how to write Makefile.
# For each target, you need to list the prerequisites, then write the command to make that target
CC = g++
CFLAGS = --std=c++11 -Wall -c
LFLAGS = --std=c++11
SRC = src
OBJ = obj
DOC = doc
TEST = test

all: roman
	@echo "roman compiled"

roman: $(OBJ)/main.o $(OBJ)/roman.o
	$(CC) $(LFLAGS) $(OBJ)/main.o $(OBJ)/roman.o -o ./obj/roman

$(OBJ)/main.o: $(SRC)/main.cpp $(SRC)/roman.hpp
	$(CC) $(CFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/roman.o: $(SRC)/roman.cpp $(SRC)/roman.hpp
	$(CC) $(CFLAGS) $(SRC)/roman.cpp -o $(OBJ)/roman.o


.PHONY: clean doc test

doc:
	doxygen doxyfile

test:
	./test.sh

clean:
	rm -rf $(OBJ)/* roman
