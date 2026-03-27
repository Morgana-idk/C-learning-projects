CC = gcc
CFLAGS = -Wall -g
TARGET = sentinel
SRC = main.c

all:$(TARGET)

$(TARGET):$(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)