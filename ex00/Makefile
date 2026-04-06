FLAGS = -Wall -Wextra -Werror -std=c++98
COMPILE = c++ $(FLAGS)
NAME = btc

SRCS = main.cpp BitcoinExchange.cpp
OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILE) $(OBJS) -o $(NAME)

%.o:%.c BitcoinExchange.hpp
	$(COMPILE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
