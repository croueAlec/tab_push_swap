/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:26:05 by acroue            #+#    #+#             */
/*   Updated: 2024/01/23 19:31:56 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_smallest_total(t_a *b, size_t len_b)
{
	size_t	i;
	size_t	small_tot;

	i = 0;
	small_tot = b[0].cost.total;
	while (i < len_b)
	{
		if (b[i].cost.total < small_tot)
		{
			small_tot = b[i].cost.total;
		}
		i++;
	}
	return (small_tot);
}

void	apply_cost(t_a *a, t_a *b, size_t i, size_t len_b)
{
	size_t	small_tot;
	t_cost	cost;

	while (len_b--)
	{
		i = 0;
		define_cost(a, b, b->len->b);
		small_tot = find_smallest_total(b, b[0].len->b);
		while (b[i].cost.total != small_tot)
			i++;
		cost = b[i].cost;
		while (cost.ra--)
			rotate(a, a[0].len->a, 'a');
		while (cost.rb--)
			rotate(b, b[0].len->b, 'b');
		while (cost.rra--)
			reverse_rotate(a, a[0].len->a, 'a');
		while (cost.rrb--)
			reverse_rotate(b, b[0].len->b, 'b');
		while (cost.rr--)
			r_and_b(a, b, a[0].len->a, b[0].len->b);
		while (cost.rrr--)
			reverse_r_and_b(a, b, a[0].len->a, b[0].len->b);
		push_a(b, a, b[0].len->b, 'a');
	}
}
