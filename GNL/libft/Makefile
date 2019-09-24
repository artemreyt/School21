.PHONY: all clean fclean re

SRC = $(wildcard srcs/*.c)
OBJ = *.o
NAME = libft.a
CC = clang
HEADER_DIR = includes
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) -c $(CFLAGS) $(SRC) -I $(HEADER_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
