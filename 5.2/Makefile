# Simple Makefile for main.c
# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = main
SOURCE = main.c

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Clean up generated files
clean:
	rm -f $(TARGET)

# Force rebuild
rebuild: clean all

# Phony targets (not actual files)
.PHONY: all clean rebuild
