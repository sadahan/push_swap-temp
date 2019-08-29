# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/02 15:09:23 by sadahan           #+#    #+#              #
#    Updated: 2019/08/29 16:44:06 by sadahan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -Wall -Wextra -Werror main1.c check_errors.c init_del_pile.c manage_pile.c checker.c push_swap_rotate.c usual_functions.c small_lists.c quicksort_pile.c quicksort_list.c -I push_swap.h                 


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
