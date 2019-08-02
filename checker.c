/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:07:45 by sadahan           #+#    #+#             */
/*   Updated: 2019/08/02 16:29:34 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					check_if_sorted(t_pile *pile)
{
	t_element		*elem;

	elem = pile->top;
	while (elem->prev != NULL)
	{
		if (elem->nb > elem->prev->nb)
			return (0);
		elem = elem->prev;
	}
	return (1);
}

t_pile				*exe_instructions(t_pile *pile_a, char *instruction)
{
	static t_pile	*pile_b;

	if (!pile_b)
		pile_b = NULL;
	if (!ft_strcmp(instruction, "sa") || !ft_strcmp(instruction, "ss"))
		swap(pile_a);
	if (!ft_strcmp(instruction, "sb") || !ft_strcmp(instruction, "ss"))
		swap(pile_b);
	if (!ft_strcmp(instruction, "pa"))
		pile_a = push(pile_b, pile_a);
	if (!ft_strcmp(instruction, "pb"))
		pile_b = push(pile_a, pile_b);
	if (!ft_strcmp(instruction, "ra") || !ft_strcmp(instruction, "rr"))
		rotate(pile_a);
	if (!ft_strcmp(instruction, "rb") || !ft_strcmp(instruction, "rr"))
		rotate(pile_b);
	if (!ft_strcmp(instruction, "rra") || !ft_strcmp(instruction, "rrr"))
		rrotate(pile_a);
	if (!ft_strcmp(instruction, "rrb") || !ft_strcmp(instruction, "rrr"))
		rrotate(pile_b);
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
		{
			instruction[j] = buff[i];
			i++;
			j++;
		}
		instruction[j] = '\0';
		if (!check_false_instruction(instruction))
		{
			write(2, "Error\n", 6);
			return (pile_a);
		}
		pile_a = exe_instructions(pile_a, instruction);
		i++;
	}
	return (pile_a);
}

void				checker(t_pile *pile_a)
{
	int				ret;
	char			buff[30000];
	int				fd;

	fd = open("inst.txt", O_RDONLY);
	if (fd == -1)
		fd = 0;
	while ((ret = read(fd, buff, 29999)))
		buff[ret] = '\0';
	close(fd);
	pile_a = read_instructions(pile_a, buff);
	print_pile(pile_a);
	if (check_if_sorted(pile_a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
