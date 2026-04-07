CC = gcc
CFLAGS = -Wall -g 
TARGET = inv
SRC = inventory.c

all:$(TARGET)

$(TARGET):$(SRC)
	make clean && $(CC) $(CFLAGS) $(SRC) -o $(TARGET) && ./$(TARGET) && clear &

clean:
	rm -f $(TARGET)