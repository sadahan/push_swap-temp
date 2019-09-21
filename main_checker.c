/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:05:44 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/17 13:24:06 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_pile	*pile_a;

	pile_a = NULL;
	if (ac < 2)
		return (0);
	if (!check_errors(ac, av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ac--;
	if (!(pile_a = init_pile(ft_atoi(av[ac]))))
		return (0);
	while (--ac > 0)
		add_to_top(pile_a, ft_atoi(av[ac]));
	if (!checker(pile_a))
		return (0);
	return (1);
}
