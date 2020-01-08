# simple Makefile
# Nooreldean Koteb G01085380
# CS262, lab section 209
# Lab6

CC= gcc
CFLAGS=-g -Wall
TARGET= BinaryLSB_Manipulation

all:$(TARGET)
$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
clean:
	rm $(TARGET)
