/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:39:28 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/27 15:09:48 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sort_3_elem(t_pile *pile, int sens, int fd)
{
	t_element	*elem;

	elem = pile->top->prev;
	if (check_if_sorted(pile, sens))
		return ;
	if (pile->nb_elem == 2 || (pile->top->nb > elem->nb
		&& pile->top->nb > pile->bottom->nb))
		sens == 1 ? rotate(pile, "ra", fd) : rotate(pile, "rb", fd);
	if (!check_if_sorted(pile, sens))
	{
		if (elem->nb > pile->top->nb && pile->top->nb > pile->bottom->nb)
			sens == 1 ? rrotate(pile, "rra", fd) : rrotate(pile, "rrb", fd);
		else
			sens == 1 ? swap(pile, "sa", fd) : swap(pile, "sb", fd);
	}
	if (!check_if_sorted(pile, sens))
		sens == 1 ? rotate(pile, "ra", fd) : rotate(pile, "rb", fd);
}

void			sort_small_pile(t_pile *pile_a, int fd)
{
	int			med;
	t_pile		*pile_b;
	int			i;

	i = 0;
	pile_b = NULL;
	med = median(pile_a, pile_a->nb_elem);
	if (pile_a->nb_elem <= 3)
		sort_3_elem(pile_a, 1, fd);
	if (check_if_sorted(pile_a, 1))
		return ;
	while (pile_a->nb_elem > 3)
	{
		if (pile_a->top->nb < med)
		{
			pile_b = push(pile_a, pile_b, "pb", fd);
			i++;
		}
		else
			rotate(pile_a, "ra", fd);
	}
	sort_3_elem(pile_a, 1, fd);
	sort_3_elem(pile_b, -1, fd);
	while (i-- > 0)
		pile_a = push(pile_b, pile_a, "pa", fd);
}
