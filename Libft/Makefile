.PHONY: all clean fclean test re

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = libft.a
TEST_SRC = $(wildcard test_src/*.c)
CC = gcc
CFLAGS = -Wall -Wextra -Werror


all: $(TARGET)

$(TARGET): $(OBJ)
	ar crs $(TARGET) $(OBJ)

$(OBJ): $(SRC)
	$(CC) -c $(CFLAGS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm $(TARGET)

re: fclean all

test: $(TARGET) $(TEST_SRC)
	$(CC) $(CFLAGS) -o test.out -L. $(TARGET) -I ./ $(TEST_SRC)