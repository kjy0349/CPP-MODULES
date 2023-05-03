SRC = ./main.cpp ./BitcoinExchange.cpp

CC = c++
NAME = btc

CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
OBJS = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re