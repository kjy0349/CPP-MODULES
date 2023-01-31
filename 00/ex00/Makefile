SRC = ./megaphone.cpp

CC = c++
NAME = megaphone

CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
OBJS = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re