/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tab_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:20:48 by acroue            #+#    #+#             */
/*   Updated: 2024/01/29 11:07:28 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static size_t	num_len(long n)
{
	size_t	length;

	length = 1;
	if (n < 0 && length++)
		n *= -1;
	while (n >= 10)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static size_t	move_index(char *str, long ln)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		j++;
	while (ft_isdigit(str[i + j]))
		j++;
	if (num_len(ln) != j)
		return (0);
	return (i + j);
}

static int	check_tab(t_a *tab, size_t len)
{
	size_t	i;
	size_t	j;
	int		value;

	i = 0;
	if (!tab)
		return (0);
	while (i < len - 1)
	{
		value = tab[i].value;
		j = i + 1;
		while (j < len)
		{
			if (value == tab[j].value)
				return ((void)ft_putstr("Error"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

t_a	*make_a(char *str, size_t len)
{
	t_a		*tab;
	size_t	i;
	long	ln;
	size_t	index;
	char	*tmp;

	i = 0;
	tab = ft_calloc(len, sizeof(t_a));
	if (!tab)
		return (free(str), NULL);
	tmp = str;
	while (i++ < len)
	{
		ln = ft_atol(str);
		index = move_index(str, ln);
		if (!(ln <= INT_MAX && ln >= INT_MIN) || index == 0)
			return ((void)ft_putstr("Error"), free(tab), free(tmp), NULL);
		tab[i - 1].value = (int)ln;
		str += index;
	}
	if (!check_tab(tab, len))
		return (free(tmp), free(tab), NULL);
	return (free(tmp), tab);
}

t_a	*make_b(size_t len)
{
	t_a	*b;

	b = ft_calloc(len, sizeof(t_a));
	if (!b)
		return (NULL);
	return (b);
}
