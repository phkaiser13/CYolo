CC = gcc
CFLAGS = -Iinclude -IExternal/include -Wall -O2
LDFLAGS = -LExternal/lib -lonnxruntime

SRC = src/main.c src/ort_wrapper.c
OBJ = $(SRC:.c=.o)
BIN = yolo_test

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ) $(BIN)
