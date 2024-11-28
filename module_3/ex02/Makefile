NAME = frag_trap

HEADER = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g

SRC_FILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	rm -rf $(OBJ_FILES)
	rm $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re