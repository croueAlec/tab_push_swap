/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:14:14 by acroue            #+#    #+#             */
/*   Updated: 2024/01/19 13:44:36 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	move_b(t_a *tab, t_a *b, size_t length)
{
	size_t	i;

	i = 0;
	while (((length - i + 1) / 2) > 3 && i < (length / 2))
	{
		if ((size_t)(tab[i].rank) <= (length / 2))
		{
			push(tab, b, tab[0].length, 'b');
			i++;
		}
		else
		{
			rotate(tab, tab[0].length, 'a');
		}
	}
	while (i < length - 3)
	{
		push(tab, b, tab[0].length, 'b');
		i++;
	}
}


