/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:49:33 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/21 17:03:54 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*typedef	struct	s_stock
{
	int			fd;
	int			nb;
}				t_stock;*/

/*int				sort_elem_a(t_pile *pile1, t_pile *pile2, int nb_elem,
					int fd, int rot)
{
	int med, r, p;
	if (!pile1)
		return (0);
		med = median(pile1, nb_elem);
		p = 0;
		r = 0;
		while (nb_elem--)
		{
			pile1->top->nb < med ? p++ : r++;
			if (pile1->top->nb >= med)
				rotate(pile1, "ra", fd);
			else if (!(pile2 = push(pile1, pile2, "pb", fd)))
				return (0);
		}
		while (r-- > 0 && rot > 0)
			rrotate(pile1, "rra", fd);
		return (p);
}*/

void			sort_pile_a(t_pile *pile1, t_pile *pile2, int nb_elem, int fd)
{
	int			i;
	int			pb[100];
	int			p;
	int			r;
	int			med;
	int			j;
	static int	rot = 0;

	i = 0;
	p = 0;
	j = 0;
	if (!pile1)
		return ;
	if (!pile2)
		pile2 = NULL;
	while (nb_elem > 3)
	{
		med = median(pile1, nb_elem);
		i = 0;
		p = 0;
		r = 0;
		while (i++ < nb_elem)
		{
			pile1->top->nb < med ? p++ : r++;
			if (pile1->top->nb >= med)
				rotate(pile1, "ra", fd);
			else if (!(pile2 = push(pile1, pile2, "pb", fd)))
				return ;
		}
		while (r-- > 0 && rot > 0)
			rrotate(pile1, "rra", fd);
	//	p = sort_elem_a(pile1, pile2, nb_elem, fd, rot);
		nb_elem -= p;
		pb[j] = p;
	//	printf("p = %d\tnb_elem = %d\n", p, nb_elem);
		j++;
	}
	rot++;
	sort_three(pile1, nb_elem, 1, fd);
	i = pb[--j];
	sort_three(pile2, i, -1, fd);
	while (i-- > 0)
		if (!(pile1 = push(pile2, pile1, "pa", fd)))
			return ;
	while (j-- > 0)
	{
		nb_elem = sort_pile_b(pile2, pile1, pb[j], fd);
	//	printf("pb[j] = %d\tnb_elem = %d\n", pb[j], nb_elem);
		if (pb[j] > 6)
		{
			pb[j] = pb[j] - nb_elem;
			j++;
			sort_pile_a(pile1, pile2, nb_elem, fd);
		}
	}
}
