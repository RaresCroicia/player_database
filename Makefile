CC=g++
EXEC=database
VAL_FILE=valgrind-result.out
SRC=src
CFLAGS=-Wall -lm -std=c++11 -g

all: clean build

build: $(EXEC)

$(EXEC): source.o player.o utils.o
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp
	$(CC) -c $^

run: clean build
	./$(EXEC)

clean:
	@rm -rf *.o $(SRC)/*.o $(EXEC) $(SRC)/*/*.o