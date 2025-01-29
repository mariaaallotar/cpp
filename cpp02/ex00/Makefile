# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 12:03:44 by maheleni          #+#    #+#              #
#    Updated: 2025/01/23 11:40:15 by maheleni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed
CC = c++
FLAGS =  -Wall -Wextra -Werror -std=c++11
SRCS = main.cpp Fixed.cpp
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