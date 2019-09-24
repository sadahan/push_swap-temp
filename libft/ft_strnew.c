/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:36:45 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/24 18:00:51 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "./includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *new_str;

	if ((new_str = (char *)malloc(sizeof(char) * (size + 1))) == 0)
		return (NULL);
	ft_bzero(new_str, size + 1);
	return (new_str);
}
