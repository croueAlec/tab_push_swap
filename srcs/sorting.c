/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:14:14 by acroue            #+#    #+#             */
/*   Updated: 2024/01/19 15:43:19 by acroue           ###   ########.fr       */
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
	len = tab[0].length;
	while (i < len - 1)
	{
		if (tab[i].rank > tab[i + 1].rank)
			return (0);
		i++;
	}
	return (1);
}

void	sort_three(t_a *tab, size_t length)
{
	while (!is_list_sorted(tab))
	{
		if (tab[0].rank > tab[1].rank)
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
		if ((size_t)(tab[0].rank) < (length / 2))
		{
			push(tab, b, tab[0].length, 'b');
			i++;
		}
		else
		{
			rotate(tab, tab[0].length, 'a');
		}
	}
	while (i < length - 3)
	{
		push(tab, b, tab[0].length, 'b');
		i++;
	}
}


