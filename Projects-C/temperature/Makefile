CC=gcc
CFLAGS=-Wall -Wextra -g
SRC=temperature.c
OUT=temperature

all: build

build:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: build
	./$(OUT)

clean:
	rm -f $(OUT)
