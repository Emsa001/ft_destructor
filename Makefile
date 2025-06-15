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
FLAGS	 = -g -Wall -Wextra -Werror -DDEBUG=0

all: $(OUT)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(OUT): $(OBJS)
	ar rcs $(OUT) $(OBJS)

executable: all
	$(CC) $(FLAGS) main.c ft_alloc.a -o ft_alloc
	make clean

clean:
	rm -f $(OBJS)
	rm -rf ft_alloc.dSYM

fclean: clean
	rm -f $(OUT)
	rm -f ft_alloc

re: fclean all

.PHONY: all executable clean fclean re