/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 18:51:08 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/24 18:00:51 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "./includes/libft.h"

char	*ft_strnjoin_free(char *s1, char *s2, int n)
{
	char	*dest;

	if (!s1 || !s2)
		return (0);
	if (!(dest = ft_strnew(sizeof(char) * (ft_strlen(s1) + n))))
		return (0);
	ft_strcpy(dest, s1);
	ft_strncat(dest, s2, n);
	ft_strdel((char**)&s1);
	return (dest);
}
