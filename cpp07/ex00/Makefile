# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maheleni <maheleni@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 12:52:33 by maheleni          #+#    #+#              #
#    Updated: 2025/04/14 12:31:42 by maheleni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prog
CC = c++
FLAGS =  -Wall -Wextra -Werror -std=c++11
SRCS = main.cpp
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