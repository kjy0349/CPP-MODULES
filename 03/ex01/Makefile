SRC = ClapTrap.cpp ScavTrap.cpp main.cpp
CC = c++
NAME = trap

CPPFLAGS = -Wall -Wextra -Werror
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