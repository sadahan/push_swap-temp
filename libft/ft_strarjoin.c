/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:48:53 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/24 18:00:51 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>
#include <string.h>

static int	ft_tablen(char **tab)
{
	int		i;
	int		j;
	int		len;

	len = 0;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			len++;
			j++;
		}
		len++;
		i++;
	}
	return (len);
}

char		*ft_strarjoin(char **tab, char c)
{
	char	*new_str;
	int		i;
	int		j;
	int		k;

	if (!tab || !(new_str = malloc(sizeof(char) * ft_tablen(tab))))
		return (NULL);
	i = 0;
	k = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			new_str[k++] = tab[i][j];
			j++;
		}
		new_str[k++] = c;
		i++;
	}
	new_str[--k] = '\0';
	return (new_str);
}
