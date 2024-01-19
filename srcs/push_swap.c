/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:27:55 by acroue            #+#    #+#             */
/*   Updated: 2024/01/19 16:14:50 by acroue           ###   ########.fr       */
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

void	print_cost(t_a *b, size_t len)
{
	size_t	i;

	i = 0;
	printf("|val| ra| rb|rra|rrb| rr|rrr|tot|\n");
	while (i < len)
	{
		printf("|%3d| %zu | %zu | %zu | %zu | %zu | %zu | %zu |\n", b[i].value,  b[i].cost.ra, b[i].cost.rb, b[i].cost.rra, b[i].cost.rrb ,b[i].cost.rr, b[i].cost.rrr, b[i].cost.total);
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
	sort_three(a, a[0].length);
	tab_print(a, a[0].length);
	printf("\n[\n");
	tab_print(b, b[0].length);
	printf("]\n\n");
	define_cost(a, b, b[0].length);
	print_cost(b, b[0].length);
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
