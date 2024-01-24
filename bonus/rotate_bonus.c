/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:51:49 by acroue            #+#    #+#             */
/*   Updated: 2024/01/24 14:07:30 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate(t_a *tab, size_t len)
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
}

void	reverse_rotate(t_a *tab, size_t len)
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
}

void	r_and_b(t_a *a, t_a *b, size_t len_a, size_t len_b)
{
	rotate(a, len_a);
	rotate(b, len_b);
}

void	reverse_r_and_b(t_a *a, t_a *b, size_t len_a, size_t len_b)
{
	reverse_rotate(a, len_a);
	reverse_rotate(b, len_b);
}
