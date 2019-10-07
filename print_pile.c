/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:59:52 by sadahan           #+#    #+#             */
/*   Updated: 2019/10/03 15:44:58 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				check_pf(char *av)
{
	if (!ft_strcmp(av, "-p"))
		return (1);
	if (!ft_strcmp(av, "-f"))
		return (2);
	if (!ft_strcmp(av, "-fp") || !ft_strcmp(av, "-pf"))
		return (3);
	return (0);
}

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
