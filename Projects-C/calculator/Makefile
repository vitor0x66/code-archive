CC=gcc
CFLAGS=-Wall -Wextra -g
SRC=calculator.c
OUT=calculator

all: build

build:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: build
	./$(OUT)

clean:
	rm -f $(OUT)
