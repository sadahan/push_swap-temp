/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:49:53 by sadahan           #+#    #+#             */
/*   Updated: 2019/10/02 14:52:25 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		sort_elem_b(t_pile *pile1, t_pile *pile2, int nb_elem, int fd)
{
	int			p;
	int			r;
	int			med;
	int			rot;

	if (!pile1 || !pile2)
		return (0);
	rot = (nb_elem == pile1->nb_elem ? 0 : 1);
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
	while (rot == 1 && r-- > 0)
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
		if (!(sort_three_b(pile1, pile2, nb_elem, fd)))
			return (0);
		return (p);
	}
	p = sort_elem_b(pile1, pile2, nb_elem, fd);
	nb_elem -= p;
	if (nb_elem <= 3 && p <= 3)
	{
		sort_three_a(pile2, p, fd);
		if (!(sort_three_b(pile1, pile2, nb_elem, fd)))
			return (0);
	}
	return (p);
}
