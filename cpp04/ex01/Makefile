# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 14:58:54 by maheleni          #+#    #+#              #
#    Updated: 2025/03/25 13:56:21 by maheleni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prog
CC = c++
FLAGS =  -Wall -Wextra -Werror -std=c++11
SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FlAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FlAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re