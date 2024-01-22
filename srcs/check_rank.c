/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:34:19 by acroue            #+#    #+#             */
/*   Updated: 2024/01/22 10:40:01 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

#include <stdio.h>

static int	find_smallest_int(t_a *tab, size_t length)
{
	size_t	i;
	int		tmp;

	i = 0;
	while (i < length && tab[i].rank != -1)
		i++;
	tmp = tab[i].value;
	i = 0;
	while (i < length)
	{
		if (tmp > tab[i].value && tab[i].rank == -1)
		{
			tmp = tab[i].value;
			// printf("\t\t%d\n", tmp);
		}
		i++;
	}
	return (tmp);
}

static void	set_rank(t_a *tab)
{
	size_t	i;

	i =0;
	while (i < tab[0].len->total)
	{
		tab[i].rank = -1;
		i++;
	}
}

void	check_rank(t_a *tab, size_t length)
{
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	set_rank(tab);
	while (i < length)
	{
		tmp = find_smallest_int(tab, length);
		// printf("\tsmall : %d\n", tmp);
		j = 0;
		while (j < length)
		{
			if (tmp == tab[j].value)
			{
				tab[j].rank = ++i;
			}
			j++;
		}
	}
}
