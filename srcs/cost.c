/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:48:57 by acroue            #+#    #+#             */
/*   Updated: 2024/01/23 19:28:19 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static t_cost	diag(t_a *b, t_cost cst)
{
	size_t	top_down;
	size_t	down_top;
	size_t	total;

	top_down = (*b).cost.ra + (*b).cost.rrb;
	down_top = (*b).cost.rra + (*b).cost.rb;
	total = cst.ra + cst.rb + cst.rra + cst.rrb;
	if (total > top_down && top_down < down_top)
	{
		ft_bzero(&cst, sizeof(t_cost));
		cst.ra = (*b).cost.ra;
		cst.rrb = (*b).cost.rrb;
	}
	else if (total > down_top && down_top < top_down)
	{
		ft_bzero(&cst, sizeof(t_cost));
		cst.rra = (*b).cost.rra;
		cst.rb = (*b).cost.rb;
	}
	else if (top_down > total && down_top > total)
	{
		return (cst);
	}
	return (cst);
}

static int	up_down(t_a *b)
{
	size_t	up;
	size_t	down;

	up = (*b).cost.ra;
	if ((*b).cost.rb > up)
		up = (*b).cost.rb;
	down = (*b).cost.rra;
	if ((*b).cost.rrb > down)
		down = (*b).cost.rrb;
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
		b[i].cost.ra = count_ra(a, b[i].rank, a[0].len->a, -1);
		b[i].cost.rra = a[0].len->a - b[i].cost.ra;
		b[i].cost.rr = 0;
		b[i].cost.rrr = 0;
		i++;
	}
	compare_cost(b, len_b);
	compact_rr(b, len_b);
}
