/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:43:42 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/24 18:00:51 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "./includes/libft.h"

static int	ft_check_int_len(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		i;

	len = ft_check_int_len(n);
	if ((s = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(s, "-2147483648"));
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	i = len - 1;
	while (i > 0 && n > 9)
	{
		s[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	s[i] = n % 10 + '0';
	s[len] = '\0';
	return (s);
}
