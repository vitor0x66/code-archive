CC=gcc
CFLAGS=-Wall -Wextra -g
SRC=atm.c file.c
OUT=atm

all: build

build:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: build
	./$(OUT)

clean:
	rm -f $(OUT)
