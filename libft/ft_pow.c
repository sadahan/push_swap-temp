/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 19:14:02 by sadahan           #+#    #+#             */
/*   Updated: 2019/01/11 19:14:10 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int n, int p)
{
	if (p == 0)
		return (1);
	return (n = n * ft_pow(n, p - 1));
}