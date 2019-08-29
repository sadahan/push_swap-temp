/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:49:18 by sadahan           #+#    #+#             */
/*   Updated: 2019/08/29 13:29:59 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int		pos_biggest_nb(t_pile *pile)
{
	int	i;
	int	pos;
	int	n;
	t_element *elem;

	if (!pile || pile->nb_elem == 1)
		return (0);
	i = 1;
	pos = 0;
	n = pile->bottom->nb;
	elem = pile->bottom->next;
	while (elem)
	{
		if (n < elem->nb)
		{
			n = elem->nb;
			pos = i;
		}
		elem = elem->next;
		i++;
	}
	return (pos); // si < nb_elem/2 --> rra * pos //  si >= nb_elem/2 --> pb x (nb_elem - pos- 1) + ra  
}

int		smaller_than_nb(t_pile *pile, int nb)
{
	int i;
	t_element *elem;

	if (!pile)
		return (-1);
	i = pile->nb_elem - 1;
	elem = pile->bottom;
	if (nb < elem->nb)
		return (0);		// peut etre place en bas de la pile --> rb
	while (elem)
	{
		if (nb < elem->nb)
			i--;
		elem = elem->next;
	}
	return (i); // si i > nb_total_elem/2  --> rb - Sinon si top < top->prev --> sb (ou si nb_elem = 2)
}

t_pile	*perso_sort(t_pile *pile_a)
{
	int	pos;
	int i;
	int n;
	t_pile	*pile_b;
	int count = 0;

	pile_b = NULL;
	// on met plus grand en bas de A
	pos = pos_biggest_nb(pile_a);
	i = 0;
	n = 0;
	if (pos < (pile_a->nb_elem / 2))
		while (pos > 0)
		{
			rrotate(pile_a, "rra");
			count++;
			pos--;
		}
	else
	{
		n = pile_a->nb_elem - pos - 1;
		while (n > 0)
		{
			if (!(pile_b = push(pile_a, pile_b, "pb")))
				exit(EXIT_FAILURE);
			count++;
			n--;
		}
		rotate(pile_a, "ra");
		count++;
	}
//								printf("---------------\nPILE A\n");
//			print_pile(pile_a);
////	printf("---------------\nPILE B\n");
//	print_pile(pile_b);
	// push les elem de a vers b et swap a quand necessaire
	while (pile_a->nb_elem > 2)
	{
		if (pile_a->top->nb > pile_a->top->prev->nb)
		{
			swap(pile_a, "sa");
			count++;
		}
		if (!(pile_b = push(pile_a, pile_b, "pb")))
				exit(EXIT_FAILURE);
		count++;
		if (pile_b->nb_elem > 1)
		{
			i = smaller_than_nb(pile_b, pile_b->top->nb);
			if (i < (pile_b->nb_elem / 2))
			{
				rotate(pile_b, "rb");
				count++;
			}
			else if (pile_b->top->nb < pile_b->top->prev->nb)
			{
				swap(pile_b, "sb");
				count++;
			}
		}
	}
	while (pile_b->nb_elem > 0)
	{
		pos = pos_biggest_nb(pile_b);
		if (pos == (pile_b->nb_elem - 1)) //while pos_biggest == nb_elem-1
			{
				pile_a = push(pile_b, pile_a, "pa");
				count++;
			}
		else if (pos <= (pile_b->nb_elem / 2))
			while (pos > -1)
			{
				rrotate(pile_b, "rrb");
				count++;
				pos--;
			}
		if (pile_b->nb_elem > 1)
		{
			if (pile_b->top->nb < pile_b->top->prev->nb)
			{	
				swap(pile_b, "pb");
				count++;
			}
			else if (pos_biggest_nb(pile_b) != (pile_b->nb_elem - 1))
			{
				rotate(pile_b, "pb");
				count++;
			}
		}
	}
	if (!check_if_sorted(pile_a, 1))
	{
		swap(pile_a, "pa");
		count++;
	}
	printf("%d\n", count);
	return (pile_a);
}
