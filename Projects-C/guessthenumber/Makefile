CC=gcc
CFLAGS=-Wall -Wextra -g
SRC=guessthenumber.c
OUT=guessthenumber

all: build

build:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: build
	./$(OUT)

clean:
	rm -f $(OUT)
