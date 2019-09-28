/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:53:34 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/28 13:05:35 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			add_to_bottom(t_pile *pile, int data)
{
	t_element	*new;

	new = NULL;
	if (!pile)
		exit(EXIT_FAILURE);
	if (!(new = malloc(sizeof(t_element))))
		exit(EXIT_FAILURE);
	new->nb = data;
	pile->bottom->prev = new;
	new->next = pile->bottom;
	new->prev = NULL;
	pile->bottom = new;
	pile->nb_elem++;
}

void			add_to_top(t_pile *pile, int data)
{
	t_element	*new;

	new = NULL;
	if (!pile)
		exit(EXIT_FAILURE);
	if (!(new = malloc(sizeof(t_element))))
		exit(EXIT_FAILURE);
	new->nb = data;
	pile->top->next = new;
	new->next = NULL;
	new->prev = pile->top;
	pile->top = new;
	pile->nb_elem++;
}

int				del_top(t_pile *pile)
{
	int			data;
	t_element	*temp;

	data = 0;
	if (pile->nb_elem > 1)
	{
		temp = pile->top;
		data = pile->top->nb;
		pile->top = pile->top->prev;
		free(temp);
		pile->nb_elem--;
	}
	else
		data = del_pile(pile);
	return (data);
}

int				del_bottom(t_pile *pile)
{
	int			data;
	t_element	*temp;

	data = 0;
	if (pile->nb_elem > 1)
	{
		temp = pile->bottom->next;
		data = pile->bottom->nb;
		temp->prev = NULL;
		free(pile->bottom);
		pile->bottom = temp;
		pile->nb_elem--;
	}
	else
		data = del_pile(pile);
	return (data);
}

int				check_if_sorted(t_pile *pile, int sens)
{
	t_element	*elem;

	elem = NULL;
	if (!pile)
		return (1);
	elem = pile->top;
	while (elem->prev != NULL)
	{
		if (sens == 1 && elem->nb > elem->prev->nb)
			return (0);
		if (sens == -1 && elem->nb < elem->prev->nb)
			return (0);
		elem = elem->prev;
	}
	return (1);
}
