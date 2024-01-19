/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:26:39 by acroue            #+#    #+#             */
/*   Updated: 2024/01/19 13:42:19 by acroue           ###   ########.fr       */
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

void	change_length(t_a *stack, size_t diff)
{
	size_t	len;
	len = diff + 1;
	// printf("|%zu|\n", len);
	ft_bzero(&stack[diff], sizeof(t_a));
	while (--len > 0)
	{
		// printf("%zu\t%d\n",len , stack[len - 1].value);
		stack[len - 1].length = diff;
	}
}

int	push(t_a *src, t_a *dest, size_t len, char c)
{
	len = 0;
	t_a	tmp;
	if (src[0].length > 0)
	{
		if (c == 'a' || c == 'b')
			ft_printf("p%c\n", c);
		tmp = src[0];
		rotate(src, src[0].length, 0);
		change_length(src, src[0].length - 1);
		dest[dest->length] = tmp;
		change_length(dest, src[0].length_total - src[0].length);
		reverse_rotate(dest, dest[0].length, 0);
	}
	return (0);
}

// faire fonctionner la fonction push et on verra ensuite
