/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:26:05 by acroue            #+#    #+#             */
/*   Updated: 2024/01/22 17:38:12 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

static int	find_smallest_total(t_a *b, size_t len_b) // trouver le soucis ici
{
	size_t	i;
	size_t	small_tot;

	i = 0;
	small_tot = b[0].cost.total;
	// printf("LA\t\t%zu\n", small_tot);
	while (i < len_b)
	{
		if (b[i].cost.total < small_tot)
		{
			small_tot = b[i].cost.total;
			// printf("LA\t\t%zu\n", small_tot);
		}
		i++;
	}
	return (small_tot);
}

void	apply_cost(t_a *a, t_a *b, size_t len_a, size_t len_b)
{
	size_t	i;
	size_t	small_tot;
	t_cost	cost;

	(void)len_a;
	while (len_b)
	{
		i = 0;
		// tab_print(a, a->len->a);
		define_cost(a, b, b->len->b);
		small_tot = find_smallest_total(b, b[0].len->b);
		// print_cost(b, b->len->b);
		while (b[i].cost.total != small_tot)
			i++;
		cost = b[i].cost;
		// printf("\033[1;31m%d %zu %zu %zu %zu %zu %zu ICI\033[0m\n", b[i].value, b[i].cost.ra, b[i].cost.rb, b[i].cost.rra, b[i].cost.rrb, b[i].cost.rr, b[i].cost.rrr);
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
			reverse_r_and_b(a, b ,a[0].len->a, b[0].len->b);
		push_a(b, a, b[0].len->b, 'a');
		len_b--;
	}
}
