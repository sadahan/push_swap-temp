/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort-list_cp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:37:54 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/21 18:37:21 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_swap(int *a, int *b)
{
	int			temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_element		*partition(t_element *bottom, t_element *top)
{
	int			pivot;
	t_element	*i;
	t_element	*j;

	pivot = top->nb;
	i = bottom->prev;
	j = bottom;
	while (j != top)
	{
		if (j->nb <= pivot)
		{
			if (i == NULL)
				i = bottom;
			else
				i = i->next;
			ft_swap(&(i->nb), &(j->nb));
		}
		j = j->next;
	}
	if (i == NULL)
		i = bottom;
	else
		i = i->next;
	ft_swap(&(i->nb), &(top->nb));
	return (i);
}

void			quicksort_list(t_element *bottom, t_element *top)
{
	t_element	*pivot;

	pivot = NULL;
	if (top && bottom && top != bottom && bottom != top->next)
	{
		pivot = partition(bottom, top);
		quicksort_list(bottom, pivot->prev);
		quicksort_list(pivot->next, top);
	}
}
