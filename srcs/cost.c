/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:48:57 by acroue            #+#    #+#             */
/*   Updated: 2024/01/24 12:43:43 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_biggest_ra(t_a *a, size_t j, size_t len_a, int biggest)
{
	size_t	i;

	if (biggest == -1)
	{
		i = 0;
		biggest = a[i].rank;
		while (i < len_a)
		{
			if (a[i].rank > biggest)
			{
				j = i;
				biggest = a[i].rank;
			}
			i++;
		}
		j++;
	}
	return (j);
}

static int	count_ra(t_a *a, int rank, size_t len_a, int biggest)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	a[a->len->a].rank = -1;
	while (i < len_a)
	{
		if ((a[i].rank < biggest || biggest == -1) && a[i].rank > rank)
		{
			j = i;
			biggest = a[i].rank;
		}
		i++;
	}
	if (biggest == -1)
		j = find_biggest_ra(a, j, len_a, biggest);
	return (j);
}

void	set_total(t_a *b, size_t len_b)
{
	size_t	i;

	i = 0;
	while (i < len_b)
	{
		b[i].cost.total = sum_total(b[i].cost);
		i++;
	}
}

void	compact_rr(t_a *b, size_t len_b)
{
	size_t	i;

	i = 0;
	while (i < len_b)
	{
		while (b[i].cost.ra && b[i].cost.rb)
		{
			b[i].cost.ra--;
			b[i].cost.rb--;
			b[i].cost.rr++;
		}
		while (b[i].cost.rra && b[i].cost.rrb)
		{
			b[i].cost.rra--;
			b[i].cost.rrb--;
			b[i].cost.rrr++;
		}
		i++;
	}
	set_total(b, len_b);
}

void	define_cost(t_a *a, t_a *b, size_t len_b)
{
	size_t	i;

	i = 0;
	while (i < len_b)
	{
		b[i].cost.rb = i;
		b[i].cost.rrb = len_b - i;
		b[i].cost.ra = count_ra(a, b[i].rank, a[0].len->a, -1);
		b[i].cost.rra = a[0].len->a - b[i].cost.ra;
		b[i].cost.rr = 0;
		b[i].cost.rrr = 0;
		i++;
	}
	compare_cost(b, len_b);
	compact_rr(b, len_b);
}
