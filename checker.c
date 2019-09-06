/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:07:45 by sadahan           #+#    #+#             */
/*   Updated: 2019/08/30 15:55:15 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int					check_if_sorted(t_pile *pile, int sens)
{
	t_element		*elem;

	elem = NULL;
	if (!pile)
		return (1);
	elem = pile->top;
	while (elem->prev != NULL)
	{
		if (sens == 1 && elem->nb > elem->prev->nb)
			return (0);
		if (sens == -1 && elem->nb < elem->prev->nb)
			return (0);
		elem = elem->prev;
	}
	return (1);
}

t_pile				*exe_instructions(t_pile *pile_a, char *instruction, int fd)
{
	static t_pile	*pile_b = NULL;

	if (!ft_strcmp(instruction, "sa") || !ft_strcmp(instruction, "ss"))
		swap(pile_a, NULL, fd);
	if (!ft_strcmp(instruction, "sb") || !ft_strcmp(instruction, "ss"))
		swap(pile_b, NULL, fd);
	if (!ft_strcmp(instruction, "pa"))
		if (!(pile_a = push(pile_b, pile_a, NULL, fd)))
			return (NULL);
	if (!ft_strcmp(instruction, "pb"))
		if (!(pile_b = push(pile_a, pile_b, NULL, fd)))
			return (NULL);
	if (!ft_strcmp(instruction, "ra") || !ft_strcmp(instruction, "rr"))
		rotate(pile_a, NULL, fd);
	if (!ft_strcmp(instruction, "rb") || !ft_strcmp(instruction, "rr"))
		rotate(pile_b, NULL, fd);
	if (!ft_strcmp(instruction, "rra") || !ft_strcmp(instruction, "rrr"))
		rrotate(pile_a, NULL, fd);
	if (!ft_strcmp(instruction, "rrb") || !ft_strcmp(instruction, "rrr"))
		rrotate(pile_b, NULL, fd);
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

t_pile				*read_instructions(t_pile *pile_a, char *buff, int fd)
{
	int				i;
	char			instruction[4];
	int				j;

	i = 0;
	while (buff[i])
	{
		j = 0;
		while (buff[i] != '\n' && j < 4)
		{
			instruction[j] = buff[i];
			i++;
			j++;
		}
		instruction[j] = '\0';
		if (!check_false_instruction(instruction))
			return (NULL);
		if (!(pile_a = exe_instructions(pile_a, instruction, fd)))
			return (NULL);
		i++;
	}
	return (pile_a);
}

void				checker(t_pile *pile_a)
{
	int				ret;
	char			buff[2];
	int				fd;
	char			inst[30000];

	if (check_if_sorted(pile_a, 1))
	{
		write(1, "OK\n", 3);
		return ;
	}
	fd = open("inst.txt", O_RDONLY);
	fd = (fd == -1) ? 0 : fd;
	while ((ret = read(fd, buff, 1)))
	{
		buff[ret] = '\0';
		ft_strcat(inst, buff);
	}
	close(fd);
	if (!(pile_a = read_instructions(pile_a, inst, fd)))
	{
		write(2, "Error\n", 6);
		return ;
	}
	check_if_sorted(pile_a, 1) == 1 ? write(1, "OK\n", 3) : write(1, "KO\n", 3);
}
