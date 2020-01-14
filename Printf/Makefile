INCLUDES = -I Libft -I includes
CC = gcc
CFLAGS = # -Wall -Werror -Wextra
SRC =  $(wildcard src/*.c)
OBJ_DIR = src/obj
SRC_DIR = src
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

NAME = libftprintf.a

LIBFT_NAME = libft.a
LIBFT_DIR = ./Libft
SRC_LIBFT = $(wildcard $(LIBFT_DIR)/*.c)
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJ)
	@ echo "START BUILDING $(NAME)"
	@ ar cr $(NAME) $(OBJ)
	@ echo "SUCCESS"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ $(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@
	@ echo "$@ made"

$(LIBFT_NAME): $(OBJ_LIBFT)
	@ echo "START BUILDING $(LIBFT_NAME)"
	@ ar crs $(LIBFT_NAME) $(OBJ_LIBFT)
	@ echo "$(LIBFT_NAME) BUILT"

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	@ $(CC) -c $(CFLAGS) $< -o $@
	@ echo "$@ made"

clean:
	@ rm -f $(OBJ_LIBFT)
	@ rm -f $(OBJ_DIR)/*
	@ echo "OBJECT FILES DELETED"

fclean: clean
	@ rm -f $(NAME)
	@ rm -f $(LIBFT_NAME)
	@ echo "$(NAME) and $(LIBFT_NAME) DELETED"

re: fclean all
