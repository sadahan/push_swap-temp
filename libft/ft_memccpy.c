/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:56:49 by sadahan           #+#    #+#             */
/*   Updated: 2019/01/11 14:52:28 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*temp2;
	const char	*temp1;
	size_t		i;

	temp2 = (char *)dest;
	temp1 = (const char *)src;
	i = 0;
	while (i < n)
	{
		temp2[i] = temp1[i];
		if ((unsigned char)temp2[i] == (unsigned char)c)
		{
			i++;
			return (dest + i);
		}
		i++;
	}
	return (NULL);
}
