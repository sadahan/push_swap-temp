/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_del_pile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:09:31 by sadahan           #+#    #+#             */
/*   Updated: 2019/10/03 15:04:58 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile			*init_pile(int data)
{
	t_pile		*pile;
	t_element	*element;

	if (!(pile = malloc(sizeof(t_pile))))
		return (NULL);
	if (!(element = malloc(sizeof(t_element))))
		return (NULL);
	element->nb = data;
	element->next = NULL;
	element->prev = NULL;
	pile->top = element;
	pile->bottom = element;
	pile->nb_elem = 1;
	return (pile);
}

int				del_pile(t_pile *pile)
{
	int			data;
	t_element	*tmp;

	if (!pile)
		return (0);
	data = pile->top->nb;
	while (pile->top)
	{
		tmp = pile->top;
		pile->top = pile->top->prev;
		free(tmp);
	}
	pile->nb_elem = 0;
	free(pile);
	return (data);
}
