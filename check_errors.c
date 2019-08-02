/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:33:43 by sadahan           #+#    #+#             */
/*   Updated: 2019/08/02 11:42:53 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

long int		ft_atoli(const char *str)
{
	long int	res;
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

int				ft_strcmp(const char *s1, const char *s2)
{
	int			i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int				check_errors(int argc, char **argv)
{
	int			i;
	int			n;

	n = argc - 1;
	if (argc < 2)
		return (0);
	while (n > 0)
	{
		i = 0;
		if (argv[n][0] == '-')
			i++;
		while (argv[n][i])
			if (!ft_isdigit(argv[n][i++]))
				return (0);
		if (ft_atoli(argv[n]) > 2147483647 || ft_atoli(argv[n]) < -2147483648)
			return (0);
		i = n;
		while (i-- > 0)
			if (ft_strcmp(argv[n], argv[i]) == 0)
				return (0);
		n--;
	}
	return (1);
}
