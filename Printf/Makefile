INCLUDES = -I Libft -I includes
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MAIN_SRC = src/ft_printf.c
SRC = $(filter-out $(MAIN_SRC), $(wildcard src/*.c))
NAME = libftprintf.a

LIB_NAME = libft.a
LIB_DIR = ./Libft
SRC_LIB = $(wildcard $(LIB_DIR)/*.c)
OBJ_LIB = $(SRC_LIB:.c=.o)


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC) $(MAIN_SRC) $(LIB_NAME)
	@ echo "COMPILING AND LINKING $(NAME)"
	@ $(CC) $(CFLAGS) $(SRC) $(MAIN_SRC) -o $(NAME) $(INCLUDES) -L$(LIB_DIR) $(LIB_NAME)
	@ echo "SUCCESS"

$(LIB_NAME): $(OBJ_LIB)
	@ echo "START BUILDING $(LIB_NAME)"
	@ ar crs $(LIB_NAME) $(OBJ_LIB)
	@ echo "$(LIB_NAME) BUILT"

$(LIB_DIR)/%.o: $(LIB_DIR)/%.c
	@ $(CC) -c $(CFLAGS) $< -o $@
	@ echo "$@ made"

clean:
	@ rm -f $(OBJ_LIB)
	@ echo "OBJECT FILES DELETED"

fclean: clean
	@ rm -f $(NAME)
	@ rm -f $(TEST_TARGET)
	rm -f $(LIB_NAME)
	@ echo "$(NAME) $(TEST_TARGET) DELETED"

re: fclean all
