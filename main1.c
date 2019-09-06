/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:44:29 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/06 14:20:31 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void			print_pile(t_pile *pile)
{
	t_element	*elem;

	if (!pile)
		return ;
	elem = pile->top;
	while (elem != NULL)
	{
		ft_putnbr(elem->nb);
		write(1, "\n", 1);
		elem = elem->prev;
	}
}

int				main(int argc, char **argv)
{
	t_pile		*pile_a;
	t_pile		*pile_b;
	int			fd;

	fd = open("inst.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd == -1)
		fd = 1;
	pile_a = NULL;
	pile_b = NULL;
	if (argc < 2)
		return (0);
	if (!check_errors(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	argc--;
	if (!(pile_a = init_pile(ft_atoi(argv[argc]))))
		return (0);
	while (--argc > 0)
		add_to_top(pile_a, ft_atoi(argv[argc]));
//	if (pile_a->nb_elem <= 5)
//		sort_small_pile(pile_a, fd);
//	checker(pile_a);
//	printf("-----\n");
//printf("med = %d\n", median(pile_a, pile_a->nb_elem));
//	quicksort_pile(pile_a, pile_b, pile_a->nb_elem, 1, fd);
//pile_a = perso_sort(pile_a, fd);  // pas tout à fait bon
sort_pile_a(pile_a, pile_b, pile_a->nb_elem, fd);
	if (check_if_sorted(pile_a, 1))
		write(1, "OK\n", 3);
	//	printf("pile A :\n");
//	print_pile(pile_a);
		close(fd);
//		printf("pile B :\n");
//	print_pile(pile_b);
//	printf("-----\n");
//	if (check_if_sorted(perso_sort(pile_a)))
//		write(1, "OK\n", 3);
	//quicksort_list(pile_a->bottom, pile_a->top); // Tri A l'envers //
	//print_pile(pile_a);
	return (1);
}
