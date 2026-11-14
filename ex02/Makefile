# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busseven <busseven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/14 12:46:49 by busseven          #+#    #+#              #
#    Updated: 2026/11/14 12:47:03 by busseven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp
CC = c++
CXX = c++
OBJS = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = RPN

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

fclean: clean
	rm -rf $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re