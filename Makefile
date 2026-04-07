CC       = gcc
CFLAGS   = -Wall -Wextra -O2
INCLUDES = -I./include

SRC      = $(wildcard ./src/*.c)
OBJ      = $(SRC:.c=.o)
TARGET   = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

./src/%.o: ./src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean