/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_del_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 16:09:31 by sadahan           #+#    #+#             */
/*   Updated: 2019/08/02 16:10:01 by sadahan          ###   ########.fr       */
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
