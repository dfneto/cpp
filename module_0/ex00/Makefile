NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC_FILES = megaphone.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf $(OBJ_FILES)
	rm $(NAME)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re