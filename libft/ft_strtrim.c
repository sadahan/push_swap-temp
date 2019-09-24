/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:16:45 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/24 18:00:51 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./includes/libft.h"
#include <string.h>

static int	ft_trim_len(char const *s)
{
	int		max_len;
	int		trim_len;
	int		i;

	max_len = ft_strlen(s) - 1;
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
	{
		i++;
		if (!s[i])
			return (ft_strlen(s));
	}
	while (max_len > 0 && (s[max_len] == ' ' || s[max_len] == '\t'
		|| s[max_len] == '\n'))
		max_len--;
	trim_len = max_len + 1 - i;
	return (trim_len);
}

static char	*ft_trim(char const *s, char *new_str, int i, int len)
{
	int		j;
	int		x;

	j = 0;
	while (i < len)
	{
		while (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			new_str[j++] = s[i++];
		x = 0;
		while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		{
			if (!s[i + 1])
			{
				new_str[j] = '\0';
				return (new_str);
			}
			x++;
			i++;
		}
		i -= x;
		while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			new_str[j++] = s[i++];
	}
	new_str[j] = '\0';
	return (new_str);
}

char		*ft_strtrim(char const *s)
{
	char	*new_str;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if ((new_str = (char *)malloc(sizeof(char) * (ft_trim_len(s) + 1))) == 0)
		return (NULL);
	if (s[0] != ' ' && s[0] != '\t' && s[0] != '\n' && s[len - 1] != ' ' &&
		s[len - 1] != '\t' && s[len - 1] != '\n')
		ft_strcpy(new_str, s);
	else
	{
		i = 0;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		ft_trim(s, new_str, i, len);
	}
	return (new_str);
}
