CC=gcc
CFLAGS=-Wall -Wextra -g
SRC=bintree.c
OUT=bintree

all: build

build:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: build
	./$(OUT)

clean:
	rm -f $(OUT) 
