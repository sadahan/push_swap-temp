/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:38:41 by sadahan           #+#    #+#             */
/*   Updated: 2019/08/29 16:45:53 by sadahan          ###   ########.fr       */
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

int					check_if_sorted(t_pile *pile, int sens);
void				checker(t_pile *pile_a);
t_pile				*read_instructions(t_pile *pile_a, char *buff, int fd);
t_pile				*exe_instructions(t_pile *pile_a, char *instruction,
					int fd);
int					check_false_instruction(char *instruction);
char				*ft_strcat(char *dest, const char *src);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
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
t_pile				*push(t_pile *pile_a, t_pile *pile_b, char *str, int fd);
void				rotate(t_pile *pile, char *str, int fd);
void				rrotate(t_pile *pile, char *str, int fd);
void				swap(t_pile *pile, char *str, int fd);
void				print_pile(t_pile *pile);
void				quicksort_list(t_element *bottom, t_element *top);
t_element			*partition(t_element *bottom, t_element *top);
int					median(t_pile *pile, int nb_elem);
void				quicksort_pile(t_pile *pile1, t_pile *pile2, int nb_elem,
					int sens);
void				sort_small_pile(t_pile *pile, int fd);
t_pile				*perso_sort(t_pile *pile);

#endif
