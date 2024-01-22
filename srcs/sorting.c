/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:14:14 by acroue            #+#    #+#             */
/*   Updated: 2024/01/22 10:42:19 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

// int	is_node_sorted(t_a *node, t_a *next)
// {
// 	if (node->value < next->value)
// 		return (1);
// 	else
// 		return (0);
// }

static int	is_list_sorted(t_a *tab)
{
	size_t	len;
	size_t	i;

	i = 0;
	// len = tab[0].length;
	len = 3;
	while (i < len - 1)
	{
		if (tab[i].value > tab[i + 1].value)
			return (0);
		i++;
	}
	return (1);
}

void	sort_three(t_a *tab, size_t length)
{
	while (!is_list_sorted(tab))
	{
		if (tab[0].value > tab[1].value)
			swap(tab, 'a');
		else
			reverse_rotate(tab, length, 'a');
	}
}

void	move_b(t_a *tab, t_a *b, size_t length)
{
	size_t	i;

	i = 0;
	while (((length - i + 1) / 2) > 3 && i < (length / 2))
	{
		if ((size_t)(tab[0].rank) <= (length / 2))
		{
			push_b(tab, b, tab[0].len->a, 'b');
			i++;
		}
		else
		{
			rotate(tab, tab[0].len->a, 'a');
		}
	}
	while (i < length - 3)
	{
		push_b(tab, b, tab[0].len->a, 'b');
		i++;
	}
}


