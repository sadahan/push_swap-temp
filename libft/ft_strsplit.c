/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 10:25:34 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/28 12:44:10 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./includes/libft.h"

static int	count_words(const char *s, char c)
{
	int		no_c;
	int		words;
	int		i;

	i = 0;
	no_c = 0;
	words = 1;
	if (!s[i])
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] != c)
		{
			i++;
			no_c = 1;
		}
		if (s[i] == c)
		{
			if (no_c)
				words++;
			no_c = 0;
			i++;
		}
	}
	return (words);
}

static int	word_len(const char *s, int i, int c)
{
	int		len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (!s || (split = malloc(sizeof(char *) * (count_words(s, c) + 1))) == 0)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			k = 0;
			if ((split[j] = malloc(word_len(s, i, c) + 1)) == 0)
				return (0);
			while (s[i] && s[i] != c)
				split[j][k++] = s[i++];
			split[j++][k] = '\0';
		}
	}
	split[j] = 0;
	return (split);
}
