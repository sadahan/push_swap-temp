/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_v3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:18:09 by sadahan           #+#    #+#             */
/*   Updated: 2019/09/06 14:16:03 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdio.h>

t_pile			*copy_pile(t_pile *src, int nb_elem)
{
	t_pile		*dest;
	t_element	*elem;

	if (!src)
		return (NULL);
	if (!(dest = init_pile(src->top->nb)))
		exit(EXIT_FAILURE);
	elem = src->top->prev;
	while (nb_elem > 1)
	{
		add_to_bottom(dest, elem->nb);
		elem = elem->prev;
		nb_elem--;
	}
	return (dest);
}

int				median(t_pile *pile, int nb_elem)
{
	t_pile		*temp;
	int			i;
	t_element	*elem;
	int			med;
	
	med = 0;
	i = (nb_elem %2 == 0) ? 1 : 0;
	if (!pile)
		exit(EXIT_FAILURE);
	if (!(temp = copy_pile(pile, nb_elem)))
		exit(EXIT_FAILURE);
	quicksort_list(temp->bottom, temp->top);
	elem = temp->top;
	while (i++ < (nb_elem / 2))
		elem = elem->prev;
	med = elem->nb;
	del_pile(temp);
	elem = NULL;
	return (med);
}

int				check_sort_3(t_pile *pile, int nb_elem, int sens)
{
	t_element	*elem;

	if (!pile)
		return (1);
	elem = pile->top;
	while (nb_elem > 1)
	{
		if ((sens == 1 && elem->nb > elem->prev->nb)
			|| (sens == -1 && elem->nb < elem->prev->nb))
			return (0);
		elem = elem->prev;
		nb_elem--;
	}
	return (1);
}

void			sort_three(t_pile *pile, int nb_elem, int sens, int fd)
{
	t_element *elem;

	if (!pile || nb_elem == 1 || check_sort_3(pile, nb_elem, sens) == 1)
		return ;
	elem = pile->top;
	if (nb_elem >= 2)
	{
		if (sens == 1 && elem->nb > elem->prev->nb)
			swap(pile, "sa", fd);
		if (sens == -1 && elem->nb < elem->prev->nb)
			swap(pile, "sb", fd);
	}
	if (nb_elem == 3 && !check_sort_3(pile, nb_elem, sens))
	{
		if (sens == 1)
		{
			rotate(pile, "ra", fd);
			swap(pile, "sa", fd);
			rrotate(pile, "rra", fd);
			if (pile->top->nb > pile->top->prev->nb)
				swap(pile, "sa", fd);
		}
		if (sens == -1)
		{
			rotate(pile, "rb", fd);
			swap(pile, "sb", fd);
			rrotate(pile, "rrb", fd);
			if (pile->top->nb < pile->top->prev->nb)
				swap(pile, "sb", fd);
		}
	}
}

void			sort_pile_a(t_pile *pile1, t_pile *pile2, int nb_elem, int fd)
{
	int			i;
	t_element	*elem;
	int			pb[100];
	int			p;
	int			r;
	int			med;
	int			j = 0;
	static int 		rot = 0;

	if (!pile1)
		return ;
	if (!pile2)
		pile2 = NULL;
	//printf("A1 : nb-elem = %d\n", nb_elem);
	while (nb_elem > 3)
	{
		med = median(pile1, nb_elem);
		p = 0;
		i = 0;
		r = 0;
		while (i < nb_elem)
		{
			elem = pile1->top;
			if (elem->nb < med)
			{
				if (!(pile2 = push(pile1, pile2, "pb", fd)))
					return ;
				p++;
			}
			else
			{
				rotate(pile1, "ra", fd);
				r++;
			}
			elem = elem->prev;
			i++;
		}
		while (r > 0 && rot > 0)
		{
			rrotate(pile1, "rra", fd);
			r--;
		}
		nb_elem -= p;
		pb[j] = p;
	//	printf("1 : pb[j] = %d\t j = %d\n", pb[j], j);
		j++;
	/*		printf("----niv 1 fA----\n");
								printf("A : \n");
								print_pile(pile1);
						if (pile2)
						{
							printf("B : \n");
							print_pile(pile2);
						}*/
	}
	rot++;
	sort_three(pile1, nb_elem, 1, fd);
	j--;
	i = pb[j];
	sort_three(pile2, i, -1, fd);
	while (i > 0)
	{
		pile1 = push(pile2, pile1, "pa", fd);
		i--;
	}
		/*							printf("----niv 2 fA----\n");
								printf("A : \n");
								print_pile(pile1);
						if (pile2)
						{
							printf("B : \n");
							print_pile(pile2);
						}*/
	while (j > 0)
	{
		j--;
	//		printf("2 : pb[j] = %d\t j = %d\n", pb[j], j);
			nb_elem = sort_pile_b(pile2, pile1, pb[j], fd);
	//		printf("A : nb-elem = %d\n", nb_elem);
			if (pb[j] > 6) // ou nb_elem > 0 ?
			{
				if (rot > 0) // nécessaire ?
				{
					pb[j] = pb[j] - nb_elem;
					j++;
				}
				sort_pile_a(pile1, pile2, nb_elem, fd);
			}
	}
}

int			sort_pile_b(t_pile *pile1, t_pile *pile2, int nb_elem, int fd)
{
	int			i;
	t_element	*elem;
	int			p;
	int			r;
	int			med;
	int			j;

	j = 0;
	if (!pile1 || !pile2)
		return (0);
	i = 0;
	p = 0;
	r = 0;
	if (nb_elem <= 3)
	{
		i = nb_elem;
	//	sort_three(pile2, i, 1, fd);
		sort_three(pile1, i, -1, fd);
		while (i > 0)
		{
			if (!(pile2 = push(pile1, pile2, "pa", fd)))
					return (0);
			i--;
		}
	//	return (p);
	}
	else
	{
		med = median(pile1, nb_elem);
		while (i < nb_elem)
		{
			elem = pile1->top;
			if (elem->nb >= med)
			{
				if (!(pile2 = push(pile1, pile2, "pa", fd)))
					return (0);
				p++;
			}
			else
			{
				rotate(pile1, "rb", fd);
				r++;
			}
			elem = elem->prev;
			i++;
		}
		while (r > 0)
		{
			rrotate(pile1, "rrb", fd);
			r--;
		}
	nb_elem -= p;
//	printf("B : nb_elem = %d\t p = %d\n", nb_elem, p);
	if (nb_elem <= 3 && p <=3)
	{
		i = nb_elem;
		sort_three(pile2, p, 1, fd);
		sort_three(pile1, i, -1, fd);
		while (i > 0)
		{
			if (!(pile2 = push(pile1, pile2, "pa", fd)))
					return (0);
			i--;
		}
	}
	}
						/*						printf("----niv 4 fB----\n");
								printf("A : \n");
								print_pile(pile1);
						if (pile2)
						{
							printf("B : \n");
							print_pile(pile2);
						}*/
	return (p);
}
