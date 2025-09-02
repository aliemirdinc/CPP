NAME = Harl

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Harl.cpp main.cpp

OBJS = $(SRC:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

do: re
	@make clean

go: do
	@./$(NAME)

.PHONY: all clean fclean re do go