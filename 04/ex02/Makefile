SRC = Animal.cpp Cat.cpp Dog.cpp Brain.cpp main.cpp
CC = c++
NAME = animal

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
OBJS = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re