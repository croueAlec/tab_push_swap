/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:20:48 by acroue            #+#    #+#             */
/*   Updated: 2024/01/18 20:29:32 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>


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
	while (i < len - 1) // retirer le - 1 si probleme de check
	{
		value = tab[i].value;
		// printf("\ncheck %d :", value);
		j = i + 1;
		while (j < len)
		{
			// printf(" %d", temp->value);
			if (value == tab[j].value)
				return (rprint("duplicate number"), 0);
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
		return (free(str), perror("Malloc fail tab"), NULL);
	tmp = str;
	while (i++ < len)
	{
		ln = ft_atol(str);
		index = move_index(str, ln);
		if (!(ln <= INT_MAX && ln >= INT_MIN) || index == 0)
			return (rprint("invalid number"), NULL);
		tab[i - 1].value = (int)ln;
		tab[i - 1].length_total = len;
		tab[i - 1].length = len;
		str += index;
	}
	tab_print(tab, len);
	if (!check_tab(tab, len))
		return (free(tmp), NULL);
	return (free(tmp), tab);
}

t_a	*make_b(size_t len)
{
	t_a	*b;

	b = ft_calloc(len, sizeof(t_a));
	if (!b)
		return (NULL);
	b[0].rank = -2;
	return (b);
}

