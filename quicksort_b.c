/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:49:53 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/19 16:14:34 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				sort_3_b(t_pile *pile1, t_pile *pile2, int nb_elem, int fd)
{
	int			i;

	i = nb_elem;
	if (!pile1 || !pile2)
		return (0);
	sort_three(pile1, i, -1, fd);
	while (i-- > 0)
		if (!(pile2 = push(pile1, pile2, "pa", fd)))
			return (0);
	return (1);
}

int				sort_elem_b(t_pile *pile1, t_pile *pile2, int nb_elem, int fd)
{
	int			p;
	int			r;
	int			med;

	if (!pile1 || !pile2)
		return (0);
	p = 0;
	r = 0;
	med = median(pile1, nb_elem);
	while (nb_elem--)
	{
		(pile1->top->nb < med) ? r++ : p++;
		if (pile1->top->nb < med)
			rotate(pile1, "rb", fd);
		else if (!(pile2 = push(pile1, pile2, "pa", fd)))
				return (0);
	}
	while (r-- > 0)
		rrotate(pile1, "rrb", fd);
	return (p);
}

int				sort_pile_b(t_pile *pile1, t_pile *pile2, int nb_elem, int fd)
{
	int			i;
	int			p;

	if (!pile1 || !pile2)
		return (0);
	i = 0;
	p = 0;
	if (nb_elem <= 3)
	{
		if (!(sort_3_b(pile1, pile2, nb_elem, fd)))
			return (0);
		return (p);
	}
	p = sort_elem_b(pile1, pile2, nb_elem, fd);
	nb_elem -= p;
	if (nb_elem <= 3 && p <= 3)
	{
		sort_three(pile2, p, 1, fd);
		if (!(sort_3_b(pile1, pile2, nb_elem, fd)))
			return (0);
	}
	return (p);
}
