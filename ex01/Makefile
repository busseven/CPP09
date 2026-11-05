# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: busseven <busseven@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/05 15:53:01 by busseven          #+#    #+#              #
#    Updated: 2026/11/05 16:03:46 by busseven         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.cpp RPN.cpp
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