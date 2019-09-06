/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:53:34 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/06 16:48:03 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void		add_to_top(t_pile *pile, int data)
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
		temp = pile->top->prev;
		data = pile->top->nb;
		temp->next = NULL;
		//pile->top->prev = NULL;
		//free(pile->top->nb);
		free(pile->top);
		pile->top = temp;
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
		//pile->bottom->next = NULL;
		free(pile->bottom);
		pile->bottom = temp;
		pile->nb_elem--;
	}
	else
		data = del_pile(pile);
	return (data);
}
