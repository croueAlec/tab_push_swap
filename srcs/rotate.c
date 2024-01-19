/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:51:49 by acroue            #+#    #+#             */
/*   Updated: 2024/01/19 12:57:53 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	rotate(t_a *tab, size_t len, char c)
{
	size_t	i;
	t_a		tmp;

	i = 0;
	tmp = tab[0];
	while (++i < len)
	{
		tab[i - 1] = tab[i];
	}
	tab[i - 1] = tmp;
	if (c == 'a' || c == 'b')
		ft_printf("r%c\n", c);
}

void	reverse_rotate(t_a *tab, size_t len, char c)
{
	t_a	tmp;

	len--;
	tmp = tab[len];
	while (len > 0)
	{
		tab[len] = tab[len - 1];
		len--;
	}
	tab[0] = tmp;
	if (c == 'a' || c == 'b')
		ft_printf("rr%c\n", c);
}

void	r_and_b(t_a *a, t_a *b, size_t len_a, size_t len_b)
{
	rotate(a, len_a, 0);
	rotate(b, len_b, 0);
	ft_putstr("rr\n");
}

void	reverse_r_and_b(t_a *a, t_a *b, size_t len_a, size_t len_b)
{
	reverse_rotate(a, len_a, 0);
	reverse_rotate(b, len_b, 0);
	ft_putstr("rrr\n");
}
