# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/02 15:09:23 by sadahan           #+#    #+#              #
#    Updated: 2019/09/06 14:13:05 by sadahan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -Wall -Wextra -Werror main1.c check_errors.c init_del_pile.c manage_pile.c 
checker.c push_swap_rotate.c usual_functions.c small_lists.c quicksort_pile_temp.c quicksort_list.c -I push_swap.h                 

45 65 53 31 46 97 23 50 92 78 21 11 27 70 56 47 96 98 38 89 20 91 37 90 61 39 76 99 4 57 72 73 82 95 22 16 100 12 1 30 9 80 14 6 7 8 25 55 75 64 24 60 81 19 42 71 69 58 79 87 34 32 33 10 44 13 63 93 77 43 5 94 67 49 40 86 59 3 18 17 85 88 29 83 84 35 36 28 62 68 51 48 41 74 54 52 15 26 66 2

 ruby -e "puts (1..500).to_a.shuffle.join(' ')"
# wc -l < "inst.txt" pour compter le nb de lignes (-1 = nb d'instructions) #

# regle all qui compile les deux et regle specifique pour chaque #


NAME1 = checker

NAME2 = push_swap

HEADS = push_swap.h

CC = gcc

LIBFT = ./libft/libft.a

CFLAGS += -Wall -Werror -Wextra

SRCS =

SRCS1 =

SRCS2 = 

OBJS += $(SRCS:%.c=%.o)

OBJS1 += $(SRCS1:%.c=%.o)

OBJS2 += $(SRCS2:%.c=%.o)

.PHONY: all, clean, fclean, re

all: $(NAME1) $(NAME2)

%.o: %.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): make -C libft all

$(NAME1):	$(LIBFT)
			$(OJBS) $(OBJS1) 
			$(CC) $(CFLAGS) $(LIBFT) -o $(NAME1)

$(NAME2):	$(LIBFT) 
			$(CC) $(CFLAGS) $(OJBS) $(OBJS2) $(LIBFT) -o $(NAME2)

clean:
		rm -f $(OBJS)
		make -C libft clean

fclean:		clean
			rm -f $(NAME)
			make -C libft fclean

re:			fclean all
