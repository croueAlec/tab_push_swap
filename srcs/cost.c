/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:48:57 by acroue            #+#    #+#             */
/*   Updated: 2024/01/23 15:53:38 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

// static int	a_rotate_cost(t_a *a, int rank, size_t len_a)
// {
// 	size_t	i;

// 	i = 0;
// 	while (a[i].rank < rank && i < len_a)
// 	{
// 		printf("%d vs %d\n", a[i].rank, rank);
// 		i++;
// 	}
// 	return (i);
// }

// static int	test(t_a *a, int rank, size_t len_a)
// {
// 	size_t	i;
// 	size_t	j;

// 	// rank++;
// 	i = 0;
// 	j = 0;
// 	a[a->len->a].rank = -1;
// 	// printf("\033[0;35m");
// 	// tab_print(a, a->len->total);
// 	// printf("\033[0m\n");
// 	if ((size_t)rank == a->len->total)
// 	{
// 		// printf("\t\t\t\033[0;34m BIGGEST \033[0m");
// 		while (a[i].rank != rank)
// 		{
// 			rank--;
// 			i = 0;
// 			while (a[i].rank != rank && i < len_a)
// 				i++;
// 		}
// 		return (i + 1);
// 	}
// 	while (a[i].rank != rank && j < len_a)
// 	{
// 		rank++;
// 		i = 0;
// 		while (a[i].rank != rank && i < len_a)
// 		{
// 			// printf("\033[0;35m");
// 			// printf("%d vs %d\n", a[i].rank, rank);
// 			// printf("\033[0m");
// 			i++;
// 		}
// 		// printf("\n");
// 		j++;
// 	}
// 	return (i);
// }

// static int	test_deux(t_a *a, size_t len_a)
// {
// 	int	biggest;
// 	size_t	i;
// 	size_t	biggest_index;

// 	i = 0;
// 	biggest = a[0].rank;
// 	biggest_index = 0;
// 	while (i < len_a)
// 	{
// 		if (a[i].rank > biggest)
// 		{
// 			biggest = a[i].rank;
// 			biggest_index = i;
// 		}
// 		i++;
// 	}
// 	return (biggest_index);
// }

// static int	test(t_a *a, int rank, size_t len_a)
// {
// 	size_t	i;

// 	i = 0;
// 	if ((size_t)rank == a->len->total)
// 		return (test_deux(a, len_a));
// 	while (a[i].rank < rank && i < len_a)
// 	{
// 		i++;
// 	}
// 	printf("ICIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII %zu\n", i);
// 	return (i);
// }

static int	test(t_a *a, int rank, size_t len_a)
{
	size_t	i;
	size_t	j;
	int		biggest;

	i = 0;
	j = 0;
	a[a->len->a].rank = -1;
	biggest = -1;
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

// static int midas(t_a *a, int rank, size_t len_a)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	a[a->len->a].rank = -1;
// 	while ((size_t)rank <= a->len->total)
// 	{
// 		rank++;
// 		i = 0;
// 		while (a[i].rank != rank && i < len_a)
// 		{
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (i);
// }

static t_cost	diag(t_a *b, t_cost cst)
{
	size_t	top_down;
	size_t	down_top;
	size_t	total;

	top_down = (*b).cost.ra + (*b).cost.rrb;
	down_top = (*b).cost.rra + (*b).cost.rb;
	total = cst.ra + cst.rb + cst.rra + cst.rrb;
	// printf("\t\\%zu\t/%zu\t%zu\n", top_down, down_top, total);
	if (total > top_down && top_down < down_top)
	{
		// printf("\tA\n\n");
		ft_bzero(&cst, sizeof(t_cost));
		cst.ra = (*b).cost.ra;
		cst.rrb = (*b).cost.rrb;
	}
	else if (total > down_top && down_top < top_down)
	{
		// printf("\t\tB\n\n");
		ft_bzero(&cst, sizeof(t_cost));
		cst.rra = (*b).cost.rra;
		cst.rb = (*b).cost.rb;
	}
	else if (top_down > total && down_top > total)
	{
		// printf("\t\t\tC\n\n");
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
	// printf("%d\n", b[0].value);
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
			// printf("\033[1;32m%d compact rr\033[0m\n", b[i].value);
			b[i].cost.ra--;
			b[i].cost.rb--;
			b[i].cost.rr++;
		}
		while (b[i].cost.rra && b[i].cost.rrb)
		{
			// printf("\033[1;32m%d compact rrr\033[0m\n", b[i].value);
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
		b[i].cost.ra = test(a, b[i].rank, a[0].len->a);
		// printf("\t%zu\n", b[i].cost.ra);
		// sleep(1);
		b[i].cost.rra = a[0].len->a - b[i].cost.ra;
		b[i].cost.rr = 0;
		b[i].cost.rrr = 0;
		i++;
	}
	compare_cost(b, len_b);
	compact_rr(b, len_b);
}

// 10 8 7 5 9 14 3 6 20 15 19 12 2 1 11 13 16 4 18 17
