.PHONY: all clean fclean re

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) -c $(CFLAGS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
