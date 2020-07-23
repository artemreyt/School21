# ------------------ Libft ---------------------#

LIBFT_DIR = Libft
LIBFT_NAME = libft.a
LIBFT_INCLUDE_DIR = $(LIBFT_DIR)

# ------------------ Libft ---------------------#

# ------------------ StackPair library -------------------- #

STACK_PAIR_SRC_DIR = src/StackPair
INT_STACK_SRC_DIR = $(STACK_PAIR_SRC_DIR)/IntStack

STACK_PAIR_INCLUDE_DIR = include/StackPair
INT_STACK_INCLUDE_DIR = $(STACK_PAIR_INCLUDE_DIR)/IntStack

STACK_PAIR_OBJ_DIR = $(STACK_PAIR_SRC_DIR)/obj
INT_STACK_OBJ_DIR  = $(INT_STACK_SRC_DIR)/obj

STACK_PAIR_SRC = $(wildcard $(STACK_PAIR_SRC_DIR)/*.c)
INT_STACK_SRC = $(wildcard $(INT_STACK_SRC_DIR)/*.c)

STACK_PAIR_OBJ = $(addprefix $(STACK_PAIR_OBJ_DIR)/, $(notdir $(STACK_PAIR_SRC:.c=.o)))
INT_STACK_OBJ = $(addprefix $(INT_STACK_OBJ_DIR)/, $(notdir $(INT_STACK_SRC:.c=.o)))

STACK_PAIR_LIB_NAME = libStackPair.a

# ------------------ StackPair library -------------------- #

# ------------------ Checker ------------------ #

CHECKER_LIB_SRC_DIR = src/Checker
CHECKER_LIB_INCLUDE_DIR = include/Checker
CHECKER_OBJ_DIR = $(CHECKER_LIB_SRC_DIR)/obj

CHECKER_EXEC_SRC = $(CHECKER_LIB_SRC_DIR)/checker_main.c
CHECKER_LIB_SRC = $(filter-out $(CHECKER_EXEC_SRC), $(wildcard $(CHECKER_LIB_SRC_DIR)/*.c))

CHECKER_EXEC_OBJ = $(addprefix $(CHECKER_OBJ_DIR)/, $(notdir $(CHECKER_EXEC_SRC:.c=.o)))
CHECKER_LIB_OBJ = $(addprefix $(CHECKER_OBJ_DIR)/, $(notdir $(CHECKER_LIB_SRC:.c=.o)))

CHECKER_LIB_NAME = libChecker.a
CHECKER_EXEC_NAME = checker

# ------------------ Checker ------------------ #

# ------------------ Push_Swap ------------------- #

PUSH_SWAP_SRC_DIR = src/Push_Swap
PUSH_SWAP_INCLUDE_DIR = include/Push_Swap
PUSH_SWAP_OBJ_DIR = $(PUSH_SWAP_SRC_DIR)/obj

PUSH_SWAP_SRC = $(wildcard $(PUSH_SWAP_SRC_DIR)/*.c)

PUSH_SWAP_OBJ = $(addprefix $(PUSH_SWAP_OBJ_DIR)/, $(notdir $(PUSH_SWAP_SRC:.c=.o)))

PUSH_SWAP_EXEC_NAME = push_swap

# ------------------ Push_Swap ------------------- #

# ------------------ Compiler settings ----------------- #

CFLAGS = -Wall -Wextra -Werror
CC = gcc

# ------------------ Compiler settings ----------------- #

LIBS_DIR = libs

all: $(LIBS_DIR)/$(LIBFT_NAME) $(CHECKER_EXEC_NAME) $(PUSH_SWAP_EXEC_NAME)


# -------------- Checker targets ---------------- #

$(CHECKER_EXEC_NAME): $(CHECKER_EXEC_OBJ) $(LIBS_DIR)/$(CHECKER_LIB_NAME) $(LIBS_DIR)/$(STACK_PAIR_LIB_NAME) $(LIBS_DIR)/$(LIBFT_NAME)
	@ make "Building $@".prepare_msg
	$(CC) $(CFLAGS) $^ -o $@
	@ make "Executable $@ built".success_msg

$(LIBS_DIR)/$(CHECKER_LIB_NAME): $(CHECKER_LIB_OBJ) | $(LIBS_DIR)
	@ make "Building $@".prepare_msg
	ar crs $(LIBS_DIR)/$(CHECKER_LIB_NAME) $(CHECKER_LIB_OBJ)
	@ make "$@ built".success_msg

$(CHECKER_OBJ_DIR)/%.o: $(CHECKER_LIB_SRC_DIR)/%.c | $(CHECKER_OBJ_DIR)
	$(CC) -c $(CFLAGS) -I $(CHECKER_LIB_INCLUDE_DIR) -I $(STACK_PAIR_INCLUDE_DIR) \
	-I $(LIBFT_INCLUDE_DIR) -I $(INT_STACK_INCLUDE_DIR) $< -o $@

# -------------- Checker targets ---------------- #


# -------------- Stack Pair targets --------------- #

$(LIBS_DIR)/$(STACK_PAIR_LIB_NAME): $(STACK_PAIR_OBJ) $(INT_STACK_OBJ) | $(LIBS_DIR)
	@ make "Building $@".prepare_msg
	ar crs $@ $^
	@ make "$@ built".success_msg

$(STACK_PAIR_OBJ_DIR)/%.o: $(STACK_PAIR_SRC_DIR)/%.c | $(STACK_PAIR_OBJ_DIR)
	$(CC) -c $(CFLAGS) -I $(STACK_PAIR_INCLUDE_DIR) -I $(INT_STACK_INCLUDE_DIR) \
	-I $(LIBFT_INCLUDE_DIR) $< -o $@

$(INT_STACK_OBJ_DIR)/%.o: $(INT_STACK_SRC_DIR)/%.c | $(INT_STACK_OBJ_DIR)
	$(CC) -c $(CFLAGS) -I $(INT_STACK_INCLUDE_DIR) -I $(LIBFT_INCLUDE_DIR) $< -o $@

# -------------- Stack Pair targets --------------- #


# -------------- Push_Swap targets --------------- #

$(PUSH_SWAP_EXEC_NAME): $(PUSH_SWAP_OBJ) $(LIBS_DIR)/$(CHECKER_LIB_NAME) $(LIBS_DIR)/$(STACK_PAIR_LIB_NAME) $(LIBS_DIR)/$(LIBFT_NAME)
	@ make "Building $@".prepare_msg
	$(CC) $(CFLAGS) $^ -o $@
	@ make "Executable $@ built".success_msg

$(PUSH_SWAP_OBJ_DIR)/%.o: $(PUSH_SWAP_SRC_DIR)/%.c | $(PUSH_SWAP_OBJ_DIR)
	$(CC) -c $(CFLAGS) -I $(PUSH_SWAP_INCLUDE_DIR) -I $(CHECKER_LIB_INCLUDE_DIR) -I $(LIBFT_INCLUDE_DIR) \
		-I $(STACK_PAIR_INCLUDE_DIR) -I $(INT_STACK_INCLUDE_DIR) -I $(LIBFT_INCLUDE_DIR)/printf_includes \
		$< -o $@

# -------------- Push_Swap targets --------------- #


$(LIBS_DIR):
	mkdir $(LIBS_DIR)

$(LIBS_DIR)/$(LIBFT_NAME): $(LIBS_DIR)
	@ make -C $(LIBFT_DIR)
	@ mv $(LIBFT_DIR)/$(LIBFT_NAME) $(LIBS_DIR)


# -------------- Utils --------------- #

%/obj:
	@ mkdir $@

%.success_msg:
	@ echo "\x1b[1;32m$*\x1b[0m"

%.prepare_msg:
	@ echo "\x1b[33m$*\x1b[0m"
# -------------- Utils --------------- #

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(CHECKER_LIB_OBJ) $(CHECKER_EXEC_OBJ) $(STACK_PAIR_OBJ) $(INT_STACK_OBJ) \
		$(PUSH_SWAP_OBJ)
	rm -rf $(LIBS_DIR)

fclean: clean
	@ rm -f $(CHECKER_EXEC_NAME) $(PUSH_SWAP_EXEC_NAME)

re: fclean all
