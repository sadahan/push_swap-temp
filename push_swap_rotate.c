/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:35:31 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/28 13:31:43 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile			*push(t_pile *pile_a, t_pile *pile_b, char *str, int fd)
{
	int			data;

	data = 0;
	if (!pile_a || pile_a->nb_elem < 1)
		return (pile_b);
	if (pile_a)
	{
		data = del_top(pile_a);
		if (!pile_b)
		{
			if (!(pile_b = init_pile(data)))
				return (NULL);
		}
		else
			add_to_top(pile_b, data);
	}
	if (str)
	{
		ft_putstr_fd(str, fd);
		ft_putchar_fd('\n', fd);
	}
	return (pile_b);
}

void			rotate(t_pile *pile, char *str, int fd)
{
	int			data;

	data = 0;
	if (!pile || pile->nb_elem <= 1)
		return ;
	data = del_top(pile);
	add_to_bottom(pile, data);
	if (str)
	{
		ft_putstr_fd(str, fd);
		ft_putchar_fd('\n', fd);
	}
}

void			rrotate(t_pile *pile, char *str, int fd)
{
	int			data;

	data = 0;
	if (!pile || pile->nb_elem <= 1)
		return ;
	data = del_bottom(pile);
	add_to_top(pile, data);
	if (str)
	{
		ft_putstr_fd(str, fd);
		ft_putchar_fd('\n', fd);
	}
}

void			swap(t_pile *pile, char *str, int fd)
{
	int			data1;
	int			data2;

	data1 = 0;
	data2 = 0;
	if (!pile || pile->nb_elem <= 1)
		return ;
	if (pile->nb_elem == 2)
		rotate(pile, NULL, fd);
	else
	{
		data1 = del_top(pile);
		data2 = del_top(pile);
		add_to_top(pile, data1);
		add_to_top(pile, data2);
	}
	if (str)
	{
		ft_putstr_fd(str, fd);
		ft_putchar_fd('\n', fd);
	}
}
