/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:16:37 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/06 15:51:51 by sadahan          ###   ########.fr       */
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

int				check_sort_3(t_pile *pile, int nb_elem, int sens)
{
	t_element	*elem;

	if (!pile)
		return (1);
	elem = pile->top;
	while (nb_elem > 1)
	{
		if ((sens == 1 && elem->nb > elem->prev->nb)
			|| (sens == -1 && elem->nb < elem->prev->nb))
			return (0);
		elem = elem->prev;
		nb_elem--;
	}
	return (1);
}

void			sort_three(t_pile *pile, int nb_elem, int sens, int fd)
{
	if (!pile || nb_elem == 1 || check_sort_3(pile, nb_elem, sens) == 1)
		return ;
	if (nb_elem >= 2)
	{
		if (sens == 1 && pile->top->nb > pile->top->prev->nb)
			swap(pile, "sa", fd);
		if (sens == -1 && pile->top->nb < pile->top->prev->nb)
			swap(pile, "sb", fd);
	}
	if (nb_elem == 3 && !check_sort_3(pile, nb_elem, sens))
	{
		rotate(pile, sens == 1 ? "ra" : "rb", fd);
		swap(pile, sens == 1 ? "sa" : "sb", fd);
		rrotate(pile, sens == 1 ? "rra" : "rrb", fd);
		if (sens == 1 && pile->top->nb > pile->top->prev->nb)
			swap(pile, "sa", fd);
		if (sens == -1 && pile->top->nb < pile->top->prev->nb)
			swap(pile, "sb", fd);
	}
}
