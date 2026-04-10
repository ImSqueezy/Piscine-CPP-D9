NAME = RPN
FLAGS = -Wall -Wextra -Werror -std=c++98
COMPILE = c++ $(FLAGS)
SRCS = main.cpp RNP.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPILE) $(OBJS) -o $(NAME)

%.o:%.cpp RNP.hpp
	$(COMPILE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean
