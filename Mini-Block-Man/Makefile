CC = gcc
CFLAGS = -Wall -g 
TARGET = mbm
SRC = game.c
RAYLIBFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all:$(TARGET)

$(TARGET):$(SRC)
	make clean && $(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(RAYLIBFLAGS) && clear && ./$(TARGET)

clean:
	rm -f $(TARGET)