/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usual_list_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:53:34 by sadahan           #+#    #+#             */
/*   Updated: 2019/08/02 15:04:31 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile			*init_pile(int data)
{
	t_pile		*pile;
	t_element	*element;

	if (!(pile = malloc(sizeof(t_pile))))
		exit(EXIT_FAILURE);
	if (!(element = malloc(sizeof(t_element))))
		exit(EXIT_FAILURE);
	element->nb = data;
	element->next = NULL;
	element->prev = NULL;
	pile->top = element;
	pile->bottom = element;
	return (pile);
}

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

int				del_pile(t_pile *pile)
{
	int			data;

	data = 0;
	while (pile->bottom != pile->top)
		del_top(pile);
	data = pile->top->nb;
	pile->top = NULL;
	pile->bottom = NULL;
	free(pile->top);
	free(pile->bottom);
	free(pile);
	return (data);
}

t_pile			*push(t_pile *pile_a, t_pile *pile_b)
{
	int			data;

	if (!pile_a)
		return (pile_b);
	data = del_top(pile_a);
	if (!pile_b)
	{
		if (!(pile_b = init_pile(data)))
			exit(EXIT_FAILURE);
	}
	else
		add_to_top(pile_b, data);
	return (pile_b);
}

void			rotate(t_pile *pile)
{
	int			data;

	if (!pile || (pile->top == pile->bottom))
		return ;
	data = del_top(pile);
	add_to_bottom(pile, data);
}

void			rrotate(t_pile *pile)
{
	int			data;

	if (!pile || (pile->top == pile->bottom))
		return ;
	data = del_bottom(pile);
	add_to_top(pile, data);
}

void			swap(t_pile *pile)
{
	int			data1;
	int			data2;

	if (!pile || (pile->top == pile->bottom))
		return ;
	data1 = del_top(pile);
	data2 = del_top(pile);
	add_to_top(pile, data1);
	add_to_top(pile, data2);
}
