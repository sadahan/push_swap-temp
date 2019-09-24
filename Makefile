# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/02 15:09:23 by sadahan           #+#    #+#              #
#    Updated: 2019/09/24 18:46:59 by sadahan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

HEADS = push_swap.h

CC = gcc

CFLAGS += -Wall -Werror -Wextra

SRCS =	init_del_pile.c manage_pile.c push_swap_rotate.c check_errors.c \
		print_pile.c

SRCS1 =	main_checker.c checker.c

SRCS2 =	main_push_swap.c quicksort_a.c quicksort_b.c small_lists.c \
		quicksort_pile.c quicksort_list.c

LIBFT = ./libft/libft.a

OBJS += $(SRCS:%.c=%.o)

OBJS1 += $(SRCS1:%.c=%.o)

OBJS2 += $(SRCS2:%.c=%.o)

.PHONY: all, clean, fclean, re

all: $(NAME1) $(NAME2)

$(LIBFT): 
			make -C libft all

%.o: %.c Makefile $(HEADS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME1):	$(LIBFT) $(OBJS) $(OBJS1)
			$(CC) $(CFLAGS) $(OBJS) $(OBJS1) $(LIBFT) -I $(HEADS) -o $(NAME1)

$(NAME2):	$(LIBFT) $(OBJS) $(OBJS2)
			$(CC) $(CFLAGS) $(OBJS) $(OBJS2) $(LIBFT) -I $(HEADS) -o $(NAME2)

clean:	
		rm -f $(OBJS) $(OBJS1) $(OBJS2)
		make -C libft clean

fclean:	clean
		rm -f $(NAME1) $(NAME2)
		make -C libft fclean

re:		fclean all
