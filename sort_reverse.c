/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:44:49 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/26 15:15:33 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_reverse(t_pile *pile_a, int fd)
{
	t_pile	*pile_b;
	int		p;
	int		nb_elem;

	p = 0;
	pile_b = NULL;
	if (!pile_a)
		return ;
	nb_elem = pile_a->nb_elem - 1;
	while (nb_elem--)
	{
		rrotate(pile_a, "rra", fd);
		if (!(pile_b = push(pile_a, pile_b, "pb", fd)))
			return ;
		p++;
	}
	while (p--)
		if (!(pile_a = push(pile_b, pile_a, "pa", fd)))
			return ;
}
