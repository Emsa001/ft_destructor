# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 14:20:53 by escura            #+#    #+#              #
#    Updated: 2024/05/04 15:33:34 by escura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS	= ft_destructors.o ft_allocs.o ft_utils.o ft_init.o
SOURCE	= ft_destructors.c ft_allocs.c ft_utils.c ft_init.c
HEADER	= ft_alloc.h
OUT	= ft_alloc.a
CC	 = gcc
FLAGS	 = -g -c -Wall -Wextra -Werror
LFLAGS	 = 

all: $(OUT)

$(OUT): $(OBJS)
	ar rcs $(OUT) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OUT)

re: fclean all

.PHONY: all clean fclean
