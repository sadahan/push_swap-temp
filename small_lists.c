/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:39:28 by sadahan           #+#    #+#             */
/*   Updated: 2019/08/29 16:44:23 by sadahan          ###   ########.fr       */
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

void			sort_small_pile(t_pile *pile, int fd)
{
	int			med;
	t_pile		*pile_tmp;
	int			i;

	i = 0;
	pile_tmp = NULL;
	med = median(pile, pile->nb_elem);
	if (pile->nb_elem <= 3)
		sort_3_elem(pile, 1, fd);
	if (check_if_sorted(pile, 1))
		return ;
	while (pile->nb_elem > 3)
	{
		if (pile->top->nb < med)
		{
			pile_tmp = push(pile, pile_tmp, "pb", fd);
			i++;
		}
		else
			rotate(pile, "ra", fd);
	}
	sort_3_elem(pile, 1, fd);
	sort_3_elem(pile_tmp, -1, fd);
	while (i-- > 0)
		pile = push(pile_tmp, pile, "pa", fd);
}
