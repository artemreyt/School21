SOURCES = $(wildcard srcs/*.c)
OBJ = *.o
INCLUDES = ./includes/
CC = gcc
FLAGS = -Wall -Wextra -Werror
TARGET = libft.a

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJ)
	ar cr $(TARGET) $(OBJ)

$(OBJ): $(SOURCES)
	$(CC) -c $(SOURCES) -I $(INCLUDES)

clean: $(OBJECTS)
	rm -rf $(OBJ)

fclean: clean
	rm $(TARGET)

re: fclean all
