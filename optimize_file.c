/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:18:17 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/27 18:17:53 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_new_file(char **inst, int fd)
{
	int		i;

	i = 0;
	fd = (fd == -1 ? 1 : fd);
	while (inst[i])
	{
		if (ft_strcmp(inst[i], "\0"))
		{
			ft_putstr_fd(inst[i], fd);
			ft_putchar_fd('\n', fd);
		}
		i++;
	}
}

static int	check_useless_instructions(char *inst1, char *inst2, int type)
{
	if (type == 1 && ((!ft_strcmp(inst1, "sa") && !ft_strcmp(inst2, "sb"))
		|| (!ft_strcmp(inst1, "sb") && !ft_strcmp(inst2, "sa"))))
		return (1);
	if (type == 2 && ((!ft_strcmp(inst1, "ra") && !ft_strcmp(inst2, "rb"))
		|| (!ft_strcmp(inst1, "rb") && !ft_strcmp(inst2, "ra"))))
		return (1);
	if (type == 3 && ((!ft_strcmp(inst1, "rra") && !ft_strcmp(inst2, "rrb"))
		|| (!ft_strcmp(inst1, "rrb") && !ft_strcmp(inst2, "rra"))))
		return (1);
	if (type == 4 && ((!ft_strcmp(inst1, "ra") && !ft_strcmp(inst2, "rra"))
			|| (!ft_strcmp(inst1, "rra") && !ft_strcmp(inst2, "ra"))
			|| (!ft_strcmp(inst1, "rb") && !ft_strcmp(inst2, "rrb"))
			|| (!ft_strcmp(inst1, "rrb") && !ft_strcmp(inst2, "rb"))))
		return (1);
	return (0);
}

static char	**remove_useless_instructions(char **inst, int i, int j)
{
	if (check_useless_instructions(inst[i], inst[j], 1))
		inst[i] = ft_strcpy(inst[i], "ss");
	else if (check_useless_instructions(inst[i], inst[j], 2))
		inst[i] = ft_strcpy(inst[i], "rr");
	else if (check_useless_instructions(inst[i], inst[j], 3))
		inst[i] = ft_strcpy(inst[i], "rrr");
	if (!ft_strcmp(inst[i], "ss") || !ft_strcmp(inst[i], "rr")
		|| !ft_strcmp(inst[i], "rrr"))
		inst[j] = ft_strcpy(inst[j], "\0");
	return (inst);
}

static char	**optimize_file(char **inst)
{
	int		i;
	int		j;
	int		change;

	i = 0;
	j = 1;
	while (inst[i] && inst[j])
	{
		change = 0;
		if (!(inst = remove_useless_instructions(inst, i, j)))
			return (NULL);
		while (check_useless_instructions(inst[i], inst[j], 4) && (change = 1))
		{
			inst[i] = ft_strcpy(inst[i], "\0");
			while (!ft_strcmp(inst[i], "\0"))
				i--;
			inst[j] = ft_strcpy(inst[j], "\0");
			j++;
		}
		while (inst[i] && (!ft_strcmp(inst[i], "\0") || !change--))
			i++;
		while (inst[j] && (j <= i || !ft_strcmp(inst[j], "\0")))
			j++;
	}
	return (inst);
}

void		optimize_instructions(int fd, int fd2)
{
	char	*inst;
	int		ret;
	char	buff[2];
	char	**inst_tab;

	if (!(fd = open("inst.txt", O_RDONLY)))
		return ;
	if (!(inst = ft_strnew(0)))
		return ;
	while (!ft_strcmp(inst, "\0"))
		while ((ret = read(fd, buff, 1)))
		{
			buff[ret] = '\0';
			inst = ft_strnjoin_free(inst, buff, ret);
		}
	close(fd);
	if (!(inst_tab = ft_strsplit(inst, '\n')))
		return ;
	inst_tab = optimize_file(inst_tab);
	write_new_file(inst_tab, fd2);
}
