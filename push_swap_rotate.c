/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 13:35:31 by sadahan           #+#    #+#             */
/*   Updated: 2019/08/02 16:08:16 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile			*push(t_pile *pile_a, t_pile *pile_b)
{
	int			data;

	if (!pile_a)
		return (pile_b);
	data = del_top(pile_a);
	if (!pile_b)
	{
		if (!(pile_b = init_pile(data)))
			exit(EXIT_FAILURE);
	}
	else
		add_to_top(pile_b, data);
	return (pile_b);
}

void			rotate(t_pile *pile)
{
	int			data;

	if (!pile || (pile->top == pile->bottom))
		return ;
	data = del_top(pile);
	add_to_bottom(pile, data);
}

void			rrotate(t_pile *pile)
{
	int			data;

	if (!pile || (pile->top == pile->bottom))
		return ;
	data = del_bottom(pile);
	add_to_top(pile, data);
}

void			swap(t_pile *pile)
{
	int			data1;
	int			data2;

	if (!pile || (pile->top == pile->bottom))
		return ;
	data1 = del_top(pile);
	data2 = del_top(pile);
	add_to_top(pile, data1);
	add_to_top(pile, data2);
}
