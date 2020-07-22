.PHONY: all clean fclean re

LIBFT_SRC_DIR = libft_src
PRINTF_SRC_DIR = printf_src

LIBFT_SRC = $(wildcard $(LIBFT_SRC_DIR)/*.c)
PRINTF_SRC = $(wildcard $(PRINTF_SRC_DIR)/*.c)

LIBFT_OBJ_DIR = $(LIBFT_SRC_DIR)/obj
PRINTF_OBJ_DIR = $(PRINTF_SRC_DIR)/obj

LIBFT_OBJ = $(addprefix $(LIBFT_OBJ_DIR)/, $(notdir $(LIBFT_SRC:.c=.o)))
PRINTF_OBJ = $(addprefix $(PRINTF_OBJ_DIR)/, $(notdir $(PRINTF_SRC:.c=.o)))

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I printf_includes -I ./
OPTMIZATION_FLAGS = -O2 -funroll-loops

all: $(NAME)

$(NAME): $(LIBFT_OBJ) $(PRINTF_OBJ)
	@ echo "BUILDING $(NAME)"
	@ ar crs $(NAME) $(LIBFT_OBJ) $(PRINTF_OBJ)
	@ echo "\x1b[1;32mSUCCESS\x1b[0m"

$(LIBFT_OBJ_DIR)/%.o: $(LIBFT_SRC_DIR)/%.c | $(LIBFT_OBJ_DIR)
	@ $(CC) -c $(OPTMIZATION_FLAGS) $(CFLAGS) $(INCLUDES) $< -o $@ -g
	@ echo "$@ made"

$(LIBFT_OBJ_DIR):
	@ mkdir $(LIBFT_OBJ_DIR)

$(PRINTF_OBJ_DIR)/%.o: $(PRINTF_SRC_DIR)/%.c | $(PRINTF_OBJ_DIR)
	@ $(CC) -c $(OPTMIZATION_FLAGS) $(CFLAGS) $(INCLUDES) $< -o $@ -g
	@ echo "$@ made"

$(PRINTF_OBJ_DIR):
	@ mkdir $(PRINTF_OBJ_DIR)

clean:
	@ rm -rf $(LIBFT_OBJ_DIR) $(PRINTF_OBJ_DIR)

fclean: clean
	@ rm -f $(NAME)

re: fclean all
