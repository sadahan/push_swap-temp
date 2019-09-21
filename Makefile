# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/02 15:09:23 by sadahan           #+#    #+#              #
#    Updated: 2019/09/20 11:00:46 by sadahan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

HEADS = push_swap.h

CC = gcc

CFLAGS += -Wall -Werror -Wextra

SRCS = init_del_pile.c manage_pile.c push_swap_rotate.c check_errors.c usual_functions.c

SRCS1 = main_checker.c checker.c

SRCS2 = main_push_swap.c quicksort_a.c quicksort_b.c small_lists.c quicksort_pile.c quicksort_list.c

OBJS += $(SRCS:%.c=%.o)

OBJS1 += $(SRCS1:%.c=%.o)

OBJS2 += $(SRCS2:%.c=%.o)

.PHONY: all, clean, fclean, re

all: $(NAME1) $(NAME2)

%.o: %.c Makefile $(HEADS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME1):	$(OBJS) $(OBJS1)
			$(CC) $(CFLAGS) $(OBJS) $(OBJS1) -I $(HEADS) -o $(NAME1)

$(NAME2):	$(OBJS) $(OBJS2)
			$(CC) $(CFLAGS) $(OBJS) $(OBJS2) -I $(HEADS) -o $(NAME2)

clean:	
		rm -f $(OBJS) $(OBJS1) $(OBJS2)

fclean:	clean
		rm -f $(NAME1) $(NAME2)

re:		fclean all
