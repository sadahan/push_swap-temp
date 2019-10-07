/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:44:29 by sadahan           #+#    #+#             */
/*   Updated: 2019/10/04 15:31:41 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_valid_input(int argc, char **argv)
{
	if (argc < 2 || (argv[1][0] == '-' && (ft_strcmp(argv[1], "-f"))))
	{
		write(2, "usage: ./push_swap [-f] $ARGS\n", 30);
		return (0);
	}
	if (!check_errors(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

static int		resolve(t_pile *pile_a, t_pile *pile_b, int nb_elem, int fd)
{
	if (!check_if_sorted(pile_a, 1) && nb_elem <= 5)
	{
		sort_small_pile(pile_a, fd);
		return (1);
	}
	else if (check_if_sorted(pile_a, -1))
	{
		sort_reverse(pile_a, fd);
		return (1);
	}
	else if (!check_if_sorted(pile_a, 1))
	{
		sort_pile_a(pile_a, pile_b, nb_elem, fd);
		return (1);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_pile		*pile_a;
	t_pile		*pile_b;
	int			fd;
	int			fd2;

	fd = open("temp_inst.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (!(check_valid_input(argc, argv)))
		return (0);
	if (argv[1][0] == '-' && ft_strchr(argv[1], 'f'))
		fd2 = open("instructions.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else
		fd2 = 1;
	fd = (fd == -1 ? 1 : fd);
	pile_b = NULL;
	if (!(pile_a = init_pile(ft_atoi(argv[--argc]))))
		return (0);
	while (--argc > (!ft_strcmp(argv[1], "-f") ? 1 : 0))
		add_to_top(pile_a, ft_atoi(argv[argc]));
		print_pile(pile_a);
	if (pile_a->nb_elem > 1 && resolve(pile_a, pile_b, pile_a->nb_elem, fd) && fd != 1)
		optimize_instructions(fd, fd2);
	del_pile(pile_a);
	close(fd);
	close(fd2);
	return (1);
}
