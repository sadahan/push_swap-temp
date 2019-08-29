/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:59:57 by sadahan           #+#    #+#             */
/*   Updated: 2019/08/29 16:46:11 by sadahan          ###   ########.fr       */
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

void			sort_three(t_pile *pile, int nb_elem, int sens, int fd)
{
	t_element *elem;

	if (!pile || nb_elem == 1 || check_if_sorted(pile, sens))
		return ;
	elem = pile->top;
	if (nb_elem >= 2)
	{
		if (sens == 1 && elem->nb > elem->prev->nb)
			swap(pile, "sa", fd);
		if (sens == -1 && elem->nb < elem->prev->nb)
			swap(pile, "sb", fd);
	}
	if (nb_elem == 3 && !check_if_sorted(pile, sens))
	{
		rotate(pile, "ra", fd); // rb ?
		swap(pile, "sa", fd); // sb?
		rrotate(pile, "rra", fd); //rrb ?
		if (sens == 1 && elem->nb > elem->prev->nb)
			swap(pile, "sa", fd);
		if (sens == -1 && elem->nb < elem->prev->nb)
			swap(pile, "sb", fd);
	}
	
}

void			quicksort_pile(t_pile *pile1, t_pile *pile2, int nb_elem, int sens)
{
	int			i;
	t_element	*elem;
	int			p;
	int			r;
	int			med;
	int			fd;

	fd = open ("instructions.txt", O_RDONLY);
	if (!pile1)
		return ;
	if (!pile2)
		pile2 = NULL;
	while (nb_elem > 3)
	{
		med = median(pile1, nb_elem);
		p = 0;
		i = 0;
		r = 0;
		while (i < nb_elem)
		{
			elem = pile1->top;
			if ((sens == 1 && elem->nb < med) || (sens == -1 && elem->nb >= med))
			{
				if (!(pile2 = push(pile1, pile2, "ra", fd))) //rb?
					return ;
				p++;
			}
			else
			{
				rotate(pile1, "ra", fd); //rb?
				r++; // ajouter rrotate
			}
			elem = elem->prev;
			i++;
		}
		nb_elem -= p;
	}
	sort_three(pile1, nb_elem, sens, fd);
	//	quicksort_pile(pile2, pile1, p, -1);
								printf("--------\n");
								printf("A : \n");
								print_pile(pile1);
								printf("B : \n");
								print_pile(pile2);
}

/*
	- tri A sur nb_elem puis sur nb-elem/2 jusqu'a nb_elem <= 3
	- tri A + B sur nb_elem <= 3
	- tri B sur nb_elem x2  
	- re tri A + B si nb_elem <= 3
	- re tri A si precedent tri B sur nb_elem > 6
	- re tri B
	...
*/

/*void		rec_quicksort(t_pile *pile1, t_pile *pile2, int nb_elem, int med, int sens)
{
	int p;
	int r;

	if (nb_elem % 2 == 0)
		p = r = nb_elem / 2;
	else
	{
		a vers b :
		p = nb_elem / 2 + 1;
		r = nb_elem / 2;
		b vers a :
		inverse
	}
	quicksort_pile(pile1, pile2, )
	
	med = median(pile1, nb_elem);
}
*/