/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:48:57 by acroue            #+#    #+#             */
/*   Updated: 2024/01/19 16:23:29 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	a_rotate_cost(t_a *a, int rank, size_t len_a)
{
	size_t	i;

	i = 0;
	while (a[i].rank < rank && i < len_a)
	{
		i++;
	}
	return (i);
}

// void	compare_cost(t_a *b, size_t len_b)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < len_b)
// 	{
		
// 		i++;
// 	}
// }

void	define_cost(t_a *a, t_a *b, size_t len_b)
{
	size_t	i;

	i = 0;
	while (i < len_b)
	{
		b[i].cost.rb = i;
		b[i].cost.rrb = len_b - i;
		b[i].cost.ra = a_rotate_cost(a, b[i].rank, a[0].length);
		b[i].cost.rra = a[0].length - b[i].cost.ra;
		i++;
	}
}
