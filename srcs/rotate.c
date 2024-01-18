/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:51:49 by acroue            #+#    #+#             */
/*   Updated: 2024/01/18 20:06:09 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

static void	ft_swap(t_a *src, t_a *dest)
{
	t_a	tmp;

	tmp = *src;
	*src = *dest;
	*dest = tmp;
}

void	rotate(t_a *tab, size_t len, char c)
{
	size_t	i;
	i = 0;
	// printf("salut\n");
	while (++i < len)
	{
		// printf("\n");
		// tab_print(tab, len);
		// printf("\n");
		ft_swap(&tab[i - 1], &tab[i]);
	}
	if (c == 'a' || c == 'b')
		ft_printf("r%c\n", c);
}

void	reverse_rotate(t_a *tab, size_t len, char c)
{
	// size_t	tmp = len;
	// printf("salut\n");
	while (--len > 0)
	{
		// printf("\n");
		// tab_print(tab, tmp);
		// printf("\n");
		ft_swap(&tab[len], &tab[len - 1]);
	}
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
