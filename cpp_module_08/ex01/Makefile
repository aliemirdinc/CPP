# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldinc <aldinc@student.42istanbul.com.tr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 13:13:59 by aldinc            #+#    #+#              #
#    Updated: 2026/01/27 13:14:03 by aldinc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Span.cpp main.cpp

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