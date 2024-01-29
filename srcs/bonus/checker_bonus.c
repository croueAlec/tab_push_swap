/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:53:48 by acroue            #+#    #+#             */
/*   Updated: 2024/01/29 20:33:41 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	apply_instructions(char *line, t_a *a, t_a *b)
{
	if (!ft_memcmp(line, "sa\n", 3))
		swap(a, a->len->a);
	if (!ft_memcmp(line, "sb\n", 3))
		swap(b, b->len->b);
	if (!ft_memcmp(line, "ss\n", 3))
		super_swap(a, b);
	if (!ft_memcmp(line, "pa\n", 3))
		push_a(b, a, b->len->b);
	if (!ft_memcmp(line, "pb\n", 3))
		push_b(a, b, a->len->a);
	if (!ft_memcmp(line, "ra\n", 3))
		rotate(a, a->len->a);
	if (!ft_memcmp(line, "rb\n", 3))
		rotate(b, b->len->b);
	if (!ft_memcmp(line, "rr\n", 3))
		r_and_b(a, b, a->len->a, b->len->b);
	if (!ft_memcmp(line, "rra\n", 4))
		reverse_rotate(a, a->len->a);
	if (!ft_memcmp(line, "rrb\n", 4))
		reverse_rotate(b, b->len->b);
	if (!ft_memcmp(line, "rrr\n", 4))
		reverse_r_and_b(a, b, a->len->a, b->len->b);
}

int	apply_checker(char **instructions, t_a *a, t_a *b)
{
	size_t	i;

	i = 0;
	if (!instructions)
	{
		return (0);
	}
	while (instructions[i])
	{
		apply_instructions(instructions[i], a, b);
		free(instructions[i]);
		i++;
	}
	free(instructions);
	return (1);
}

void	check_no_input(t_a *a, size_t *boolean)
{
	if (!a || *boolean == 0)
		return ;
	if (!is_list_sorted(a, a->len->a))
		ft_putstr("KO");
	else
		ft_putendl_fd("OK", 1);
}

void	free_all(t_a *a, t_a *b, t_len *len)
{
	if (len)
		free(len);
	free(a);
	free(b);
}
