/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:28:23 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/24 18:00:51 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdlib.h>
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t d_l;
	size_t size_max;
	size_t s_l;

	d_l = ft_strlen(dest);
	s_l = ft_strlen(src);
	if (d_l >= size)
		return (s_l + size);
	size_max = (size - 1) - d_l;
	i = 0;
	while (src[i] != '\0' && i < size_max)
	{
		dest[d_l + i] = src[i];
		i++;
	}
	dest[d_l + i] = '\0';
	return (d_l + s_l);
}
