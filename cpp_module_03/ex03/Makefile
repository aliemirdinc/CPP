# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldinc42 <aldinc42@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/04 11:48:29 by aldinc42          #+#    #+#              #
#    Updated: 2025/09/04 12:01:36 by aldinc42         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = open

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 #-Wshadow

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

go: re
	@make clean
	@clear
	@./$(NAME)

.PHONY: all clean fclean re go