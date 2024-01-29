/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:27:55 by acroue            #+#    #+#             */
/*   Updated: 2024/01/29 15:23:00 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	basic_check(t_a *a, size_t list_length)
{
	if (list_length == 1)
		return (0);
	if (list_length == 2)
	{
		if (a[0].value > a[1].value)
			swap(a, 'a');
		return (0);
	}
	if (list_length == 3)
	{
		sort_three(a, list_length);
		return (0);
	}
	if (is_list_sorted(a, list_length))
		return (0);
	return (1);
}

static t_len	*define_len_struct(t_a *a, t_a *b, size_t list_length)
{
	t_len	*len;
	size_t	i;

	i = 0;
	if (!a || !b)
		return (NULL);
	len = ft_calloc(1, sizeof(t_len));
	if (!len)
		return (NULL);
	while (i < list_length)
	{
		a[i].len = len;
		b[i].len = len;
		i++;
	}
	a->len->a = list_length;
	b->len->b = 0;
	a->len->total = list_length;
	return (len);
}

void	right_side_up(t_a *a, size_t len_a)
{
	size_t	i;

	i = 0;
	if (a[0].rank == 1)
		return ;
	while (a[i].rank != 1)
		i++;
	if (!a->len->total % 2)
		a->len->total++;
	if (i <= (a->len->total) / 2)
	{
		while (i--)
		{
			rotate(a, len_a, 'a');
		}
	}
	else
	{
		while (i++ < a->len->total)
		{
			reverse_rotate(a, len_a, 'a');
		}
	}
}

void	free_all(t_a *a, t_a *b, t_len *len)
{
	if (len)
		free(len);
	free(a);
	free(b);
}

int	main(int argc, char *argv[])
{
	char	*str;
	char	*tmp;
	size_t	list_length;
	t_a		*a;
	t_a		*b;

	if (argc == 1)
		return (0);
	tmp = ft_jointab(&argv[1], 0, 0);
	str = ft_strtrim(tmp, " ");
	if (!tmp || !str)
		return (free(tmp), 0);
	list_length = ft_count_words(str, 32);
	free(tmp);
	a = make_a(str, list_length);
	b = make_b(list_length);
	if (!define_len_struct(a, b, list_length) || !basic_check(a, list_length))
		return (free_all(a, b, b->len), 0);
	check_rank(a, list_length);
	move_b(a, b, list_length);
	sort_three(a, a[0].len->a);
	apply_cost(a, b, 0, b[0].len->b);
	right_side_up(a, a->len->a);
	return (free_all(a, b, a->len), 0);
}
