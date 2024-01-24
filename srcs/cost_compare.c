/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_compare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:42:17 by acroue            #+#    #+#             */
/*   Updated: 2024/01/24 12:45:19 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static t_cost	compare_paths(t_a *b)
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
		b[i].cost = compare_paths(&b[i]);
		i++;
	}
}

size_t	sum_total(t_cost c)
{
	return (c.ra + c.rb + c.rra + c.rrb + c.rr + c.rrr);
}
