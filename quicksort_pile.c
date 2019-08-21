/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:59:57 by sadahan           #+#    #+#             */
/*   Updated: 2019/08/17 09:57:36 by sadahan          ###   ########.fr       */
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
	
	i = 1;
	if (!pile)
		exit(EXIT_FAILURE);
	if (!(temp = copy_pile(pile, nb_elem)))
		exit(EXIT_FAILURE);
	quicksort_list(temp->bottom, temp->top);
	elem = temp->top;
	while (i++ < (nb_elem / 2))
		elem = elem->prev;
	return (elem->nb);
}
