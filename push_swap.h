/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:38:41 by sadahan           #+#    #+#             */
/*   Updated: 2019/08/17 09:57:34 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

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

void				ft_putchar(char c);
void				ft_putnbr(int n);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					check_errors(int argc, char **argv);
long int			ft_atoli(const char *str);
t_pile				*init_pile(int data);
void				add_to_bottom(t_pile *pile, int data);
void				add_to_top(t_pile *pile, int data);
int					del_top(t_pile *pile);
int					del_bottom(t_pile *pile);
int					del_pile(t_pile *pile);
t_pile				*push(t_pile *pile_a, t_pile *pile_b);
void				rotate(t_pile *pile);
void				rrotate(t_pile *pile);
void				swap(t_pile *pile);
void				print_pile(t_pile *pile);
void				quicksort_list(t_element *bottom, t_element *top);
t_element			*partition(t_element *bottom, t_element *top);
int					median(t_pile *pile, int nb_elem);


t_pile	*perso_sort(t_pile *pile);

#endif
