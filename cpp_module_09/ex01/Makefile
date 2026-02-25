# **************************************************************************** #
#                                                                              #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: aldinc <aldinc@student.42istanbul.com.tr>    +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#   Created: 2026/02/25 17:47:01 by aldinc              #+#    #+#             #
#   Updated: 2026/02/25 17:47:04 by aldinc             ###   ########.fr       #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = RPN.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

go: re
	@./$(NAME)
	@make fclean

.PHONY: all clean fclean re go