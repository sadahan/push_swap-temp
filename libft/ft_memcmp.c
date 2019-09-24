/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:14:20 by sadahan           #+#    #+#             */
/*   Updated: 2019/01/17 14:12:20 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			i;

	temp1 = (unsigned char*)s1;
	temp2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (*temp1 != *temp2)
			return (*temp1 - *temp2);
		i++;
		temp1++;
		temp2++;
	}
	return (0);
}
