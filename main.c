/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:44:29 by sadahan           #+#    #+#             */
/*   Updated: 2019/08/02 16:21:44 by sadahan          ###   ########.fr       */
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
		elem = elem->prev;
	}
}

int				main(int argc, char **argv)
{
	t_pile		*pile_a;

	pile_a = NULL;
	if (argc < 2)
		return (0);
	if (!check_errors(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	argc--;
	if (!(pile_a = init_pile(ft_atoi(argv[argc]))))
		return (0);
	while (--argc > 0)
		add_to_top(pile_a, ft_atoi(argv[argc]));
	checker(pile_a);
	return (1);
}
