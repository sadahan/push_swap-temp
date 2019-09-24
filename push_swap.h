/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:38:41 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/24 18:46:38 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "./libft/includes/libft.h"

typedef	struct		s_elem
{
	int				nb;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_element;

typedef	struct		s_pile
{
	t_element		*top;
	t_element		*bottom;
	int				nb_elem;
}					t_pile;

int					check_if_sorted(t_pile *pile, int sens);
int					checker(t_pile *pile_a);
t_pile				*read_instructions(t_pile *pile_a, char *buff);
t_pile				*exe_instructions(t_pile *pile_a, char *instruction);
int					check_false_instruction(char *instruction);
int					check_errors(int argc, char **argv);
t_pile				*init_pile(int data);
void				add_to_bottom(t_pile *pile, int data);
void				add_to_top(t_pile *pile, int data);
int					del_top(t_pile *pile);
int					del_bottom(t_pile *pile);
int					del_pile(t_pile *pile);
t_pile				*push(t_pile *pile_a, t_pile *pile_b, char *str, int fd);
void				rotate(t_pile *pile, char *str, int fd);
void				rrotate(t_pile *pile, char *str, int fd);
void				swap(t_pile *pile, char *str, int fd);
void				print_pile(t_pile *pile);
void				quicksort_list(t_element *bottom, t_element *top);
t_element			*partition(t_element *bottom, t_element *top);
int					median(t_pile *pile, int nb_elem);
void				quicksort_pile(t_pile *pile1, t_pile *pile2, int nb_elem,
					int sens, int fd);
void				sort_small_pile(t_pile *pile, int fd);
t_pile				*perso_sort(t_pile *pile, int fd);
int					sort_pile_b(t_pile *pile1, t_pile *pile2, int nb_elem, int fd);
void				sort_pile_a(t_pile *pile1, t_pile *pile2, int nb_elem,
					int fd);
int					check_sort_3(t_pile *pile, int nb_elem, int sens);
void				sort_three(t_pile *pile, int nb_elem, int sens, int fd);

#endif
