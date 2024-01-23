/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:26:39 by acroue            #+#    #+#             */
/*   Updated: 2024/01/23 19:28:54 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	swap(t_a *tab, char c)
{
	t_a	tmp;

	if (!tab)
		return ;
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
}

void	super_swap(t_a *a, t_a *b)
{
	swap(a, 0);
	swap(b, 0);
	ft_printf("ss\n");
}

int	push_b(t_a *a, t_a *b, size_t len, char c)
{
	t_a		tmp;
	t_len	*length;

	len = 0;
	length = b->len;
	if (length->a > 0)
	{
		if (c == 'b')
			ft_putendl_fd("pb", 1);
		tmp = a[0];
		rotate(a, length->a, 0);
		b[b->len->b] = tmp;
		length->a--;
		length->b++;
		reverse_rotate(b, length->b, 0);
	}
	return (0);
}

int	push_a(t_a *b, t_a *a, size_t len, char c)
{
	t_a		tmp;
	t_len	*length;

	len = 0;
	length = b->len;
	if (length->b > 0)
	{
		if (c == 'a')
			ft_putendl_fd("pa", 1);
		tmp = b[0];
		rotate(b, length->b, 0);
		a[a->len->a] = tmp;
		length->a++;
		length->b--;
		reverse_rotate(a, length->a, 0);
	}
	return (0);
}
