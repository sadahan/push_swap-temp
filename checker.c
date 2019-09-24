/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:07:45 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/24 18:37:18 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_pile				*exe_instructions(t_pile *pile_a, char *instruction)
{
	static t_pile	*pile_b = NULL;

	if (!ft_strcmp(instruction, "sa") || !ft_strcmp(instruction, "ss"))
		swap(pile_a, NULL, 0);
	if (!ft_strcmp(instruction, "sb") || !ft_strcmp(instruction, "ss"))
		swap(pile_b, NULL, 0);
	if (pile_b && !ft_strcmp(instruction, "pa"))
		if (!(pile_a = push(pile_b, pile_a, NULL, 0)))
			return (NULL);
	if (pile_a && !ft_strcmp(instruction, "pb"))
		if (!(pile_b = push(pile_a, pile_b, NULL, 0)))
			return (NULL);
	if (!ft_strcmp(instruction, "ra") || !ft_strcmp(instruction, "rr"))
		rotate(pile_a, NULL, 0);
	if (!ft_strcmp(instruction, "rb") || !ft_strcmp(instruction, "rr"))
		rotate(pile_b, NULL, 0);
	if (!ft_strcmp(instruction, "rra") || !ft_strcmp(instruction, "rrr"))
		rrotate(pile_a, NULL, 0);
	if (!ft_strcmp(instruction, "rrb") || !ft_strcmp(instruction, "rrr"))
		rrotate(pile_b, NULL, 0);
	return (pile_a);
}

int					check_false_instruction(char *instruction)
{
	if (!ft_strcmp(instruction, "sa") || !ft_strcmp(instruction, "ss")
		|| !ft_strcmp(instruction, "sb") || !ft_strcmp(instruction, "pa")
		|| !ft_strcmp(instruction, "pb") || !ft_strcmp(instruction, "ra")
		|| !ft_strcmp(instruction, "rb") || !ft_strcmp(instruction, "rr")
		|| !ft_strcmp(instruction, "rra") || !ft_strcmp(instruction, "rrr")
		|| !ft_strcmp(instruction, "rrb"))
		return (1);
	return (0);
}

t_pile				*read_instructions(t_pile *pile_a, char *buff)
{
	int				i;
	char			instruction[4];
	int				j;

	i = 0;
	while (buff[i])
	{
		j = 0;
		while (buff[i] != '\n' && j < 4)
			instruction[j++] = buff[i++];
		instruction[j] = '\0';
		if (!check_false_instruction(instruction))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		if (!(pile_a = exe_instructions(pile_a, instruction)))
			return (NULL);
		i++;
	}
	return (pile_a);
}

int					checker(t_pile *pile_a)
{
	int				ret;
	char			buff[2];
	int				fd;
	char			*inst;

	fd = open("inst.txt", O_RDONLY);
	fd = (fd == -1) ? 0 : fd;
	if (!(inst = ft_strnew(0)))
		return (-1);
	while (!ft_strcmp(inst, "\0"))
		while ((ret = read(fd, buff, 1)))
		{
			buff[ret] = '\0';
			inst = ft_strnjoin_free(inst, buff, ret);
		}
	if (!(pile_a = read_instructions(pile_a, inst)))
		return (0);
	close(fd);
	check_if_sorted(pile_a, 1) == 1 ? write(1, "OK\n", 3) : write(1, "KO\n", 3);
	return (1);
}
