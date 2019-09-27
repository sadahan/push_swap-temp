/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 15:20:25 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/27 15:20:53 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char				*read_fd(char *inst, int fd)
{
	int				ret;
	char			buff[2];

	while ((ret = read(fd, buff, 1)))
	{
		buff[ret] = '\0';
		if (!(inst = ft_strnjoin_free(inst, buff, ret)))
			return (NULL);
	}
	return (inst);
}

char				*read_file(char *inst, int fd, t_pile *pile_a)
{
	if (!(inst = read_fd(inst, fd)))
		return (NULL);
	if (!ft_strcmp(inst, "\0") && check_if_sorted(pile_a, 1))
	{
		write(1, "OK\n", 3);
		del_pile(pile_a);
		return (NULL);
	}
	return (inst);
}
