/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:33:43 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/27 11:56:01 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		while (argv[n][i] && (n > 1 || argv[1][0] != '-'))
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
