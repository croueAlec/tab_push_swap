/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:27:55 by acroue            #+#    #+#             */
/*   Updated: 2024/01/19 13:41:44 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	tab_print(t_a *tab, size_t len)
{
	size_t i;
	i = 0;
	while (i < len)
	{
		printf("%d (%d) [%zu-%zu]\n", tab[i].value, tab[i].rank, tab[i].length, tab[i].length_total);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	*str;
	char	*tmp;
	size_t	list_length;
	t_a		*a;
	t_a		*b;

	if (argc == 1)
		return (rprint("too few arguments"), 0);
	tmp = ft_jointab(&argv[1], 0, 0);
	if (!tmp)
		return (0);
	str = ft_strtrim(tmp, " ");
	list_length = ft_count_words(str, 32);
	free(tmp);
	a = make_a(str, list_length);
	b = make_b(list_length);
	if (!a || !b)
		return (free(a), free(b), 0);
	check_rank(a, list_length);
	move_b(a, b, list_length);
	tab_print(a, a[0].length);
	printf("\n\n[\n");
	tab_print(b, b[0].length);
	printf("]\n\n");
	return (free(a), free(b), 0);
}

/*
	reverse_rotate(a, list_length, 'a');
	printf("========================\n");
	tab_print(a, a[0].length);
	rotate(a, list_length, 'a');
	printf("========================\n");
	tab_print(a, a[0].length);
	// first_push(a, b);
	push(a, b, a[0].length, 'b');
	printf("========================\n");
	tab_print(a, list_length);
	printf("-------------------------\n");
	tab_print(b, list_length);
	printf("-------------------------\n");
	push(a, b, list_length, 'b');
	tab_print(a, list_length);
	printf("-------------------------\n");
	tab_print(b, list_length);
	// push(b, a, list_length, 0);
	// push(b, a, list_length, 0);
	// printf("|||||||||||||||||||||||||||\n");
	// tab_print(b, list_length);
*/
