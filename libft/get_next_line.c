/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:27:38 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/28 12:58:29 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int		forward_stock(char **stock, int i)
{
	char		*temp;

	temp = *stock;
	if (!(*stock = ft_strdup(temp + i)))
		return (-1);
	free(temp);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char	*stock[(long)INTMAX + 1];
	char		buff[BUFF_SIZE + 1];
	int			ret;
	int			i;

	if (!line || fd < 0)
		return (-1);
	if (!stock[fd])
		if (!(stock[fd] = ft_strnew(0)))
			return (-1);
	ret = 0;
	while (!(ft_strchr(stock[fd], '\n'))
		&& (ret = read(fd, buff, BUFF_SIZE)) > 0)
		stock[fd] = ft_strnjoin_free(stock[fd], buff, ret);
	if (ret == -1)
		return (-1);
	i = 0;
	while (stock[fd][i] && stock[fd][i] != '\n')
		i++;
	if (!(*line = ft_strsub(stock[fd], 0, i)))
		return (-1);
	if (stock[fd][i] == '\n')
		i++;
	forward_stock(&stock[fd], i);
	return (i == 0 ? 0 : 1);
}
