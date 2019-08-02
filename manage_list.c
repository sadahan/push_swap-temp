/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usual_list_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:53:34 by sadahan           #+#    #+#             */
/*   Updated: 2019/08/02 16:10:06 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			add_to_bottom(t_pile *pile, int data)
{
	t_element	*new;

	if (!pile)
		return ;
	if (!(new = malloc(sizeof(t_element))))
		exit(EXIT_FAILURE);
	new->nb = data;
	pile->bottom->prev = new;
	new->next = pile->bottom;
	new->prev = NULL;
	pile->bottom = new;
}

void			add_to_top(t_pile *pile, int data)
{
	t_element	*new;

	if (!pile)
		return ;
	if (!(new = malloc(sizeof(t_element))))
		exit(EXIT_FAILURE);
	new->nb = data;
	pile->top->next = new;
	new->next = NULL;
	new->prev = pile->top;
	pile->top = new;
}

int				del_top(t_pile *pile)
{
	int			data;
	t_element	*temp;

	data = 0;
	if (pile->bottom != pile->top)
	{
		temp = pile->top->prev;
		data = pile->top->nb;
		temp->next = NULL;
		pile->top->prev = NULL;
		free(pile->top);
		pile->top = temp;
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
	if (pile->bottom != pile->top)
	{
		temp = pile->bottom->next;
		data = pile->bottom->nb;
		temp->prev = NULL;
		pile->bottom->next = NULL;
		free(pile->bottom);
		pile->bottom = temp;
	}
	else
		data = del_pile(pile);
	return (data);
}
