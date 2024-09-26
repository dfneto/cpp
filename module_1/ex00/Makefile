NAME = zombie00

HEADER = Zombie.hpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_FILES = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -I.


clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re