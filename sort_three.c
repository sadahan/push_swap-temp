/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:20:05 by sadahan           #+#    #+#             */
/*   Updated: 2019/10/02 16:49:47 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			sort_three_a(t_pile *pile, int nb_elem, int fd)
{
	if (!pile || nb_elem == 1 || check_sort_3(pile, nb_elem, 1) == 1)
		return ;
	if (pile->top->nb > pile->top->prev->nb)
		swap(pile, "sa", fd);
	if (nb_elem == 3 && !check_sort_3(pile, nb_elem, 1))
	{
		rotate(pile, "ra", fd);
		swap(pile, "sa", fd);
		rrotate(pile, "rra", fd);
		if (pile->top->nb > pile->top->prev->nb)
			swap(pile, "sa", fd);
	}
}

static int		resolve_1(t_pile *pile1, t_pile *pile2, int fd)
{
	rotate(pile1, "rb", fd);
	swap(pile1, "sb", fd);
	if (!(pile2 = push(pile1, pile2, "pa", fd)))
		return (0);
	if (!(pile2 = push(pile1, pile2, "pa", fd)))
		return (0);
	rrotate(pile1, "rrb", fd);
	return (1);
}

static int		resolve_2(t_pile *pile1, t_pile *pile2, int fd)
{
	if (!(pile2 = push(pile1, pile2, "pa", fd)))
		return (0);
	swap(pile1, "sb", fd);
	return (1);
}

static int		resolve_3(t_pile *pile1, t_pile *pile2, int fd)
{
	rotate(pile1, "rb", fd);
	swap(pile1, "sb", fd);
	if (!(pile2 = push(pile1, pile2, "pa", fd)))
		return (0);
	rrotate(pile1, "rrb", fd);
	return (1);
}

int				sort_three_b(t_pile *pile1, t_pile *pile2, int n, int fd)
{
	if (!pile1 || !pile2)
		return (0);
	if ((n == 2 || (!check_sort_3(pile1, n, 1) && !check_sort_3(pile1, n, -1)))
		&& pile1->top->nb < pile1->top->prev->nb)
		swap(pile1, "sb", fd);
	if (n == 3 && !check_sort_3(pile1, n, -1))
	{
		if (check_sort_3(pile1, n, 1) && n--)
		{
			if (!resolve_1(pile1, pile2, fd))
				return (0);
		}
		else if (pile1->top->nb > pile1->top->prev->prev->nb)
		{
			if (!resolve_2(pile1, pile2, fd))
				return (0);
		}
		else if (!resolve_3(pile1, pile2, fd))
			return (0);
		n--;
	}
	while (n-- > 0)
		if (!(pile2 = push(pile1, pile2, "pa", fd)))
			return (0);
	return (1);
}
