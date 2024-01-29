/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:26:39 by acroue            #+#    #+#             */
/*   Updated: 2024/01/29 14:53:06 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_a *tab, size_t len)
{
	t_a	tmp;

	if (!tab || len <= 1)
		return ;
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
}

void	super_swap(t_a *a, t_a *b)
{
	swap(a, a->len->a);
	swap(b, b->len->b);
}

int	push_b(t_a *a, t_a *b, size_t len)
{
	t_a		tmp;
	t_len	*length;

	len = 0;
	length = b->len;
	if (length->a > 0)
	{
		tmp = a[0];
		rotate(a, length->a);
		b[b->len->b] = tmp;
		length->a--;
		length->b++;
		reverse_rotate(b, length->b);
	}
	return (0);
}

int	push_a(t_a *b, t_a *a, size_t len)
{
	t_a		tmp;
	t_len	*length;

	len = 0;
	length = b->len;
	if (length->b > 0)
	{
		tmp = b[0];
		rotate(b, length->b);
		a[a->len->a] = tmp;
		length->a++;
		length->b--;
		reverse_rotate(a, length->a);
	}
	return (0);
}
