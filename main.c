/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:44:29 by sadahan           #+#    #+#             */
/*   Updated: 2019/08/02 15:06:23 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_atoi(const char *str)
{
	int			res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

void			ft_putnbr(int n)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
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
