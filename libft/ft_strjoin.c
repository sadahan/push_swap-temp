/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:05:18 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/24 18:00:51 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "./includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		size;
	char	*temp;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if ((new_str = (char *)malloc(sizeof(char) * (size + 1))) == 0)
		return (NULL);
	temp = ft_strdup(s1);
	new_str = ft_strcat(temp, s2);
	return (new_str);
}
