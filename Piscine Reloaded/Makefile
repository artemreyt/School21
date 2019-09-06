SOURSES = $(wildcard ./srcs/*)
OBJECTS = $(SOURCES:.cpp=.o)
INCLUDES = ./includes/
CC = gcc
FLAGS = -Wall -Wextra -Werror
TARGET = libft.a

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJECS)
	ar cr $(TARGET) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) -c $(SOURCES) -I $(INCLUDES)

clean: $(OBJECTS)
	rm -rf $(OBJECTS)

fclean: clean
	rm $(TARGET)

re: fclean all
