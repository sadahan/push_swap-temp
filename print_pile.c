/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:59:52 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/27 17:24:48 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			print_pile(t_pile *pile)
{
	t_element	*elem;

	if (!pile)
		return ;
	elem = pile->top;
	while (elem != NULL)
	{
		ft_putnbr(elem->nb);
		write(1, " ", 1);
		elem = elem->prev;
	}
}
