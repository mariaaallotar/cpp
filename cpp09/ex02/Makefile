# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 12:52:33 by maheleni          #+#    #+#              #
#    Updated: 2025/06/02 16:17:16 by maheleni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe
CC = c++ -g
FLAGS =  -Wall -Wextra -Werror -std=c++20
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)
INCLUDES = PmergeMe.hpp

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re