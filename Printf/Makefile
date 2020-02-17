# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: creicher <creicher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/08 17:19:43 by ecathryn          #+#    #+#              #
#    Updated: 2020/02/15 19:53:44 by creicher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PFT_INCLUDES = includes
LIBFT_DIR = libft
INCLUDES = -I $(LIBFT_DIR) -I $(PFT_INCLUDES)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC =  $(wildcard src/*.c)
OBJ_DIR = src/obj
SRC_DIR = src
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
OPTMIZATION_FLAGS = -O2 -m64 -Ofast -flto -march=native -funroll-loops

NAME = libftprintf.a
SRC_LIBFT = $(wildcard $(LIBFT_DIR)/*.c)
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

.PHONY: all clean fclean re norm static_checks

all: $(NAME)

$(NAME): $(OBJ_LIBFT) $(OBJ)
	@ echo "START BUILDING $(NAME)"
	@ ar cr $(NAME) $(OBJ) $(OBJ_LIBFT)
	@ echo "SUCCESS"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@ $(CC) -c $(OPTMIZATION_FLAGS) $(CFLAGS) $(INCLUDES) $< -o $@ -g
	@ echo "$@ made"

$(OBJ_DIR):
	@ mkdir $(OBJ_DIR)

$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	@ $(CC) -c $(OPTMIZATION_FLAGS) $(CFLAGS) $< -o $@
	@ echo "$@ made"

clean:
	@ rm -f $(OBJ_LIBFT)
	@ rm -f $(OBJ_DIR)/*
	@ echo "OBJECT FILES DELETED"

fclean: clean
	@ rmdir $(OBJ_DIR)
	@ rm -f $(NAME)
	@ rm -f $(LIBFT_NAME)
	@ echo "$(NAME) DELETED"

re: fclean all

norm:
	@ norminette $(SRC) $(SRC_LIBFT) $(PFT_INCLUDES) $(LIBFT_DIR)/*.h

static_checks:
	@	cppcheck --version
	@	/bin/echo "--------------"
	@	cppcheck \
			--check-library \
			--enable=warning,performance,portability \
			--std=c99 \
			--verbose \
			--error-exitcode=1 \
			--language=c \
			-I $(SRC) $(PFT_INCLUDES)
	@	/bin/echo "--------------"
