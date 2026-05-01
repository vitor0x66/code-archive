CC=gcc
CFLAGS=-Wall -Wextra -g
SRC=image_compression.c
OUT=image-compression

all: build

build:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: build
	./$(OUT)

clean:
	rm -f $(OUT)
