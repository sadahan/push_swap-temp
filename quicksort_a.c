/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:49:33 by sadahan           #+#    #+#             */
/*   Updated: 2019/10/02 14:33:41 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pile	*sort_elem_a(t_pile *pile1, t_pile *pile2, int nb_elem,
				int fd_rot)
{
	int			med;
	int			r;
	int			fd;

	fd = (fd_rot < 0 ? -fd_rot : fd_rot);
	if (!pile1)
		return (NULL);
	if (!pile2)
		pile2 = NULL;
	med = median(pile1, nb_elem);
	r = 0;
	while (nb_elem--)
	{
		if (pile1->top->nb >= med)
		{
			rotate(pile1, "ra", fd);
			r++;
		}
		else if (!(pile2 = push(pile1, pile2, "pb", fd)))
			return (NULL);
	}
	while (r-- > 0 && fd_rot > 0)
		rrotate(pile1, "rra", fd);
	return (pile2);
}

void			sort_pile_a(t_pile *pile1, t_pile *pile2, int nb_elem, int fd)
{
	int			pb[100];
	int			j;
	static int	rot = 0;

	if (!pile1)
		return ;
	if ((j = 0) && !pile2)
		pile2 = NULL;
	while (nb_elem > 3)
	{
		pile2 = sort_elem_a(pile1, pile2, nb_elem, (rot ? fd : -fd));
		pb[j++] = nb_elem / 2;
		nb_elem -= nb_elem / 2;
	}
	sort_three_a(pile1, nb_elem, fd);
	sort_three_b(pile2, pile1, pb[--j], fd);
	while ((rot = 1) && j-- > 0)
	{
		nb_elem = sort_pile_b(pile2, pile1, pb[j], fd);
		if (pb[j] > 6)
		{
			pb[j++] -= nb_elem;
			sort_pile_a(pile1, pile2, nb_elem, fd);
		}
	}
}
