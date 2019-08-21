/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadahan <sadahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:11:18 by sadahan           #+#    #+#             */
/*   Updated: 2019/08/21 14:19:02 by sadahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "push_swap.h"

int					check_if_sorted(t_pile *pile, int sens);
void				checker(t_pile *pile_a);
t_pile				*read_instructions(t_pile *pile_a, char *buff);
t_pile				*exe_instructions(t_pile *pile_a, char *instruction);
int					check_false_instruction(char *instruction);
char				*ft_strcat(char *dest, const char *src);

#endif
