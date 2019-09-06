/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_pile_a_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:16:37 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/06 16:05:32 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile			*copy_pile(t_pile *src, int nb_elem)
{
	t_pile		*dest;
	t_element	*elem;

	if (!src)
		return (NULL);
	if (!(dest = init_pile(src->top->nb)))
		exit(EXIT_FAILURE);
	elem = src->top->prev;
	while (nb_elem > 1)
	{
		add_to_bottom(dest, elem->nb);
		elem = elem->prev;
		nb_elem--;
	}
	return (dest);
}

int				median(t_pile *pile, int nb_elem)
{
	t_pile		*temp;
	int			i;
	t_element	*elem;
	int			med;

	med = 0;
	i = (nb_elem % 2 == 0) ? 1 : 0;
	if (!pile)
		exit(EXIT_FAILURE);
	if (!(temp = copy_pile(pile, nb_elem)))
		exit(EXIT_FAILURE);
	quicksort_list(temp->bottom, temp->top);
	elem = temp->top;
	while (i++ < (nb_elem / 2))
		elem = elem->prev;
	med = elem->nb;
	del_pile(temp);
	elem = NULL;
	return (med);
}

void			sort_pile_a(t_pile *pile1, t_pile *pile2, int nb_elem, int fd)
{
	int			i;
	int			pb[100];
	int			p;
	int			r;
	int			med;
	int			j;
	static int	rot = 0;

	j = 0;
	if (!pile1)
		return ;
	if (!pile2)
		pile2 = NULL;
	while (nb_elem > 3)
	{
		med = median(pile1, nb_elem);
		p = 0;
		i = 0;
		r = 0;
		while (i < nb_elem)
		{
			if (pile1->top->nb < med)
			{
				if (!(pile2 = push(pile1, pile2, "pb", fd)))
					return ;
				p++;
			}
			else
			{
				rotate(pile1, "ra", fd);
				r++;
			}
			i++;
		}
		while (r > 0 && rot > 0)
		{
			rrotate(pile1, "rra", fd);
			r--;
		}
		nb_elem -= p;
		pb[j] = p;
		j++;
	}
	rot++;
	sort_three(pile1, nb_elem, 1, fd);
	j--;
	i = pb[j];
	sort_three(pile2, i, -1, fd);
	while (i > 0)
	{
		pile1 = push(pile2, pile1, "pa", fd);
		i--;
	}
	while (j > 0)
	{
		j--;
		nb_elem = sort_pile_b(pile2, pile1, pb[j], fd);
		if (pb[j] > 6)
		{
			pb[j] = pb[j] - nb_elem;
			j++;
			sort_pile_a(pile1, pile2, nb_elem, fd);
		}
	}
}

int				sort_pile_b(t_pile *pile1, t_pile *pile2, int nb_elem, int fd)
{
	int			i;
	int			p;
	int			r;
	int			med;

	if (!pile1 || !pile2)
		return (0);
	i = 0;
	p = 0;
	r = 0;
	if (nb_elem <= 3)
	{
		i = nb_elem;
		sort_three(pile1, i, -1, fd);
		while (i > 0)
		{
			if (!(pile2 = push(pile1, pile2, "pa", fd)))
				return (0);
			i--;
		}
		return (p);
	}
	med = median(pile1, nb_elem);
	while (i < nb_elem)
	{
		if (pile1->top->nb >= med)
		{
			if (!(pile2 = push(pile1, pile2, "pa", fd)))
				return (0);
			p++;
		}
		else
		{
			rotate(pile1, "rb", fd);
			r++;
		}
		i++;
	}
	while (r > 0)
	{
		rrotate(pile1, "rrb", fd);
		r--;
	}
	nb_elem -= p;
	if (nb_elem <= 3 && p <= 3)
	{
		i = nb_elem;
		sort_three(pile2, p, 1, fd);
		sort_three(pile1, i, -1, fd);
		while (i > 0)
		{
			if (!(pile2 = push(pile1, pile2, "pa", fd)))
				return (0);
			i--;
		}
	}
	return (p);
}
