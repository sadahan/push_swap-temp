/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:36:09 by sadahan           #+#    #+#             */
/*   Updated: 2019/01/10 16:07:33 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*temp2;
	const char	*temp1;

	temp2 = (char *)dest;
	temp1 = (const char *)src;
	while (n--)
		temp2[n] = temp1[n];
	return (dest);
}
