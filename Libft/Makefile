.PHONY: all clean fclean re

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = libft.a
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
	rm -f $(TARGET)

re: fclean all
