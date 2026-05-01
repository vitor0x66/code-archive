CC=gcc
CFLAGS=-Wall -Wextra -g
SRC=binarysearch.c
OUT=binarysearch

all: build

build:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: build
	./$(OUT)

clean:
	rm -f $(OUT)
