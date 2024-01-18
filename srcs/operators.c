/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:26:39 by acroue            #+#    #+#             */
/*   Updated: 2024/01/18 21:04:02 by acroue           ###   ########.fr       */
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

void	change_length(t_a *stack, int diff)
{
	size_t	len;
	len = stack[0].length + diff;
	while (len > 0)
	{
		stack[len - 1].length += diff;
		len--;
	}
}

void	first_push(t_a *a, t_a *b)
{
	b[0] = a[0];
	b[0].length = 1;
	ft_bzero(a, sizeof(t_a));
	rotate(a, a[1].length_total, 0);
	change_length(a, -1);
	ft_putstr("pb\n");
}

int	push(t_a *src, t_a *dest, size_t len, char c)
{
	len = 0;
	t_a	tmp;
	if (!src)
		return (0);
	if (dest[0].rank == -2)
		return (first_push(src, dest), 0);
	ft_printf("p%c", c);
	tmp = src[0];
	reverse_rotate(dest, dest[0].length, 0);
	dest[0] = tmp;
	dest[0].length = dest[1].length;
	change_length(src, -1);
	change_length(dest, +1);
	ft_bzero(src, sizeof(t_a));
	rotate(src, src[1].length, 0);
	return (0);
}


// faire fonctionner la fonction push et on verra ensuite
