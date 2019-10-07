/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:07:45 by sadahan           #+#    #+#             */
/*   Updated: 2019/10/03 16:06:49 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			check_inst(char *inst, int n)
{
	if (n == 1 && (!ft_strcmp(inst, "sa") || !ft_strcmp(inst, "ss")))
		return (1);
	if (n == 2 && (!ft_strcmp(inst, "ra") || !ft_strcmp(inst, "rr")))
		return (1);
	if (n == 3 && (!ft_strcmp(inst, "rra") || !ft_strcmp(inst, "rrr")))
		return (1);
	return (0);
}

static t_pile		*exe_instructions(t_pile *pile_a, char *inst)
{
	static t_pile	*pile_b = NULL;
	static int		i = 0;

	check_inst(inst, 1) ? swap(pile_a, NULL, 0) : 0;
	if ((!ft_strcmp(inst, "sb") || !ft_strcmp(inst, "ss")) && i > 0)
		swap(pile_b, NULL, 0);
	if (pile_b && !ft_strcmp(inst, "pa") && i > 0)
	{
		if (!(pile_a = push(pile_b, pile_a, NULL, 0)))
			return (NULL);
		i--;
	}
	if (pile_a && !ft_strcmp(inst, "pb") && pile_a->nb_elem > 1)
	{
		if (!(pile_b = push(pile_a, pile_b, NULL, 0)))
			return (NULL);
		i++;
	}
	check_inst(inst, 2) ? rotate(pile_a, NULL, 0) : 0;
	if (i > 0 && (!ft_strcmp(inst, "rb") || !ft_strcmp(inst, "rr")))
		rotate(pile_b, NULL, 0);
	check_inst(inst, 3) ? rrotate(pile_a, NULL, 0) : 0;
	if ((!ft_strcmp(inst, "rrb") || !ft_strcmp(inst, "rrr")) && i > 0)
		rrotate(pile_b, NULL, 0);
	return (pile_a);
}

static int			check_false_instruction(char *instruction)
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

static t_pile		*read_instructions(t_pile *pile_a, char *buff)
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
			del_pile(pile_a);
			free(buff);
			exit(EXIT_FAILURE);
		}
		if (!(pile_a = exe_instructions(pile_a, instruction)))
			return (NULL);
		i++;
	}
	return (pile_a);
}

int					checker(t_pile *pile_a, int pf)
{
	int				fd;
	char			*inst;
	int				nb;

	nb = pile_a->nb_elem;
	fd = open("instructions.txt", O_RDONLY);
	fd = (fd == -1 || pf <= 1) ? 0 : fd;
	if (!(inst = ft_strnew(0)))
		return (0);
	while (fd && !ft_strcmp(inst, "\0"))
		if (!(inst = read_file(inst, fd, pile_a)))
			return (0);
	if (!fd && !(inst = read_fd(inst, fd)))
		return (0);
	if (!(pile_a = read_instructions(pile_a, inst)))
		return (0);
	close(fd);
	(!inst) ? 0 : free(inst);
	if (check_if_sorted(pile_a, 1) && nb == pile_a->nb_elem)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	(pf == 1 || pf == 3) ? print_pile(pile_a) : 0;
	del_pile(pile_a);
	return (1);
}
