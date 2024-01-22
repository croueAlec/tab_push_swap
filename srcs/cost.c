/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:48:57 by acroue            #+#    #+#             */
/*   Updated: 2024/01/22 10:42:56 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

static int	a_rotate_cost(t_a *a, int rank, size_t len_a)
{
	size_t	i;

	i = 0;
	while (a[i].rank < rank && i < len_a)
	{
		printf("%d vs %d\n", a[i].rank, rank);
		i++;
	}
	return (i);
}

static t_cost	diag(t_a *b, t_cost cst)
{
	size_t	top_down;
	size_t	down_top;
	size_t	total;

	top_down = (*b).cost.ra + (*b).cost.rrb;
	down_top = (*b).cost.rra + (*b).cost.rb;
	total = cst.ra + cst.rb + cst.rra + cst.rrb;
	printf("\t\\%zu\t/%zu\t%zu\n", top_down, down_top, total);
	if (total > top_down && top_down < down_top)
	{
		printf("\tA\n\n");
		ft_bzero(&cst, sizeof(t_cost));
		cst.ra = (*b).cost.ra;
		cst.rrb = (*b).cost.rrb;
	}
	else if (total > down_top && down_top < top_down)
	{
		printf("\t\tB\n\n");
		ft_bzero(&cst, sizeof(t_cost));
		cst.rra = (*b).cost.rra;
		cst.rb = (*b).cost.rb;
	}
	else if (top_down > total && down_top > total)
	{
		printf("\t\t\tC\n\n");
		return (cst);
	}
	return (cst);
}

static int	up_down(t_a *b)
{
	size_t	up;
	size_t	down;
	// t_cost		result;

	// ft_bzero(&result, sizeof(t_cost));
	up = (*b).cost.ra;
	if ((*b).cost.rb > up)
		up = (*b).cost.rb;
	down = (*b).cost.rra;
	if ((*b).cost.rrb > down)
		down = (*b).cost.rrb;
	// if (up <= down)
	// {
	// 	result.ra = (*b).cost.ra;
	// 	result.rb = (*b).cost.rb;
	// }
	// else
	// {
	// 	result.rra = (*b).cost.rra;
	// 	result.rrb = (*b).cost.rrb;
	// }
	if (up > down)
		return (1);
	return (0);
}

static t_cost justice(t_a *b)
{
	t_cost	tmp;

	tmp = (*b).cost;
	if (up_down(b))
	{
		tmp.ra = 0;
		tmp.rb = 0;
	}
	else
	{
		tmp.rra = 0;
		tmp.rrb = 0;
	}
	printf("%d\n", b[0].value);
	return (diag(b, tmp));
}

void	compare_cost(t_a *b, size_t len_b)
{
	size_t	i;

	i = 0;
	while (i < len_b)
	{
		b[i].cost = justice(&b[i]);
		i++;
	}
}

static size_t	sum_total(t_cost c)
{
	return (c.ra + c.rb + c.rra + c.rrb + c.rr + c.rrr);
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
		b[i].cost.ra = a_rotate_cost(a, b[i].rank, a[0].len->a);
		b[i].cost.rra = a[0].len->a - b[i].cost.ra;
		i++;
	}
	compare_cost(b, len_b);
	compact_rr(b, len_b);
}
