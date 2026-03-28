CC = gcc
CFLAGS = -Wall -g 
TARGET = sentinel
SRC = main.c
LNFLAGS = -lncurses

all:$(TARGET)

$(TARGET):$(SRC)
	make clean && $(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LNFLAGS) && clear && ./$(TARGET)

clean:
	rm -f $(TARGET)