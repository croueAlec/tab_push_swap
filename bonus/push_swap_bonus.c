/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:27:55 by acroue            #+#    #+#             */
/*   Updated: 2024/01/24 14:24:37 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_list_sorted(t_a *tab, size_t list_length)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = list_length;
	while (i < len - 1)
	{
		if (tab[i].value > tab[i + 1].value)
			return (0);
		i++;
	}
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

int	check_instructions(char *line)
{
	if (ft_memcmp(line, "sa\n", 3))
		return (0);
	if (ft_memcmp(line, "sb\n", 3))
		return (0);
	if (ft_memcmp(line, "ss\n", 3))
		return (0);
	if (ft_memcmp(line, "pa\n", 3))
		return (0);
	if (ft_memcmp(line, "pb\n", 3))
		return (0);
	if (ft_memcmp(line, "ra\n", 3))
		return (0);
	if (ft_memcmp(line, "rb\n", 3))
		return (0);
	if (ft_memcmp(line, "rr\n", 3))
		return (0);
	if (ft_memcmp(line, "rra\n", 4))
		return (0);
	if (ft_memcmp(line, "rrb\n", 4))
		return (0);
	if (ft_memcmp(line, "rrr\n", 4))
		return (0);
	return (1);
}

char	**getting_line(void)
{
	char	*line;
	char	*res;
	int		fd;
	char	**res_tab;

	fd = open(STDIN_FILENO, O_RDONLY);
	if (fd < 1)
		return (NULL);
	res = get_next_line(fd);
	while (res)
	{
		line = get_next_line(fd);
		if (check_instructions(line))
			return (free(res), (void)ft_putstr("Error"), NULL);
		res = ft_sep_join(res, line, "|");
		free(line);
	}
	res_tab = ft_split(res, '|');
	return (free(res), res_tab);
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
	if (!tmp)
		return (0);
	str = ft_strtrim(tmp, " ");
	list_length = ft_count_words(str, 32);
	free(tmp);
	a = make_a(str, list_length);
	b = make_b(list_length);
	if (!define_len_struct(a, b, list_length) || !basic_check(a, list_length))
		return (free(a), free(b), 0);
	apply_checker(getting_line(), a, b);
	if (b->len->b != 0 || !is_list_sorted(a, a->len->a))
		return (ft_putendl_fd("KO", 1), free(a->len), free(a), free(b), 0);
	return (free(a->len), free(a), free(b), 0);
}
