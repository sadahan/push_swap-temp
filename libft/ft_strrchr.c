/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:19:43 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/24 18:00:51 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int l;

	l = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + l);
	while (l >= 0)
	{
		if (s[l] == c)
			return ((char *)s + l);
		l--;
	}
	return (NULL);
}
