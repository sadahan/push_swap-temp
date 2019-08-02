/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:26:41 by sadahan           #+#    #+#             */
/*   Updated: 2019/07/30 17:06:38 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				check_if_sorted(t_pile *pile)
{
	t_element	*elem;

	elem = pile->top;
	while (elem->prev != NULL)
	{
		if (elem->nb > elem->prev->nb)
			return (0);
		elem = elem->prev;
	}
	return (1);
}
