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

OBJS	= ft_destructors.o ft_malloc.o ft_calloc.o ft_utils.o
SOURCE	= ft_destructors.c ft_malloc.c ft_calloc.c ft_utils.c
HEADER	= ft_alloc.h
OUT	= ft_alloc.a
CC	 = gcc
FLAGS	 = -g -c -Wall -Wextra -Werror
LFLAGS	 = 

all: $(OUT)

$(OUT): $(OBJS)
	ar rcs $(OUT) $(OBJS)

ft_destructors.o: ft_destructors.c
	$(CC) $(FLAGS) ft_destructors.c -std=c99

ft_malloc.o: ft_malloc.c
	$(CC) $(FLAGS) ft_malloc.c -std=c99

ft_utils.o: ft_utils.c
	$(CC) $(FLAGS) ft_utils.c -std=c99

ft_calloc.o: ft_calloc.c
	$(CC) $(FLAGS) ft_calloc.c -std=c99

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(OUT)

re: fclean all

.PHONY: all clean fclean
