CC = gcc
SRCS = gc.c
BIN = gc

all: clean build run

clean:
	rm -f $(BIN)

build: $(SRCS)
	$(CC) -g -o $(BIN) $(SRCS)

run: clean
	./$(BIN)
