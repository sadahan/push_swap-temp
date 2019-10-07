/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:05:44 by sadahan           #+#    #+#             */
/*   Updated: 2019/10/03 16:00:30 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_valid_input(int ac, char **av)
{
	if (ac < 2 || (av[1][0] == '-' && (ft_strcmp(av[1], "-f")
		&& ft_strcmp(av[1], "-p") && ft_strcmp(av[1], "-pf")
			&& ft_strcmp(av[1], "-fp"))))
	{
		write(2, "usage: ./checker [-fp] $ARGS\n", 29);
		return (0);
	}
	if (!check_errors(ac, av))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_pile		*pile_a;
	int			pf;

	pf = 0;
	pile_a = NULL;
	if (!(check_valid_input(ac, av)))
		return (0);
	ac--;
	if (!(pile_a = init_pile(ft_atoi(av[ac]))))
		return (0);
	pf = check_pf(av[1]);
	while (--ac > ((pf > 0) ? 1 : 0))
		add_to_top(pile_a, ft_atoi(av[ac]));
	if (!checker(pile_a, pf))
		return (0);
	return (1);
}
