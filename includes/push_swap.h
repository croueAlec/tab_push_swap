/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:26:34 by acroue            #+#    #+#             */
/*   Updated: 2024/01/18 21:04:25 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_cost
{
	size_t		ra;
	size_t		rb;
	size_t		rra;
	size_t		rrb;
	size_t		rr;
	size_t		rrr;
	size_t		total;
}	t_cost;

typedef struct s_a
{
	int				value;
	int				rank;
	size_t			length;
	size_t			length_total;
	struct s_cost	cost;
}	t_a;

/* push_swap.c */
void	tab_print(t_a *tab, size_t len);
/* parsing.c */
char	*ft_jointab(char **tab, size_t i, int length);
void	rprint(char *str);
/* make_tab.c */
t_a		*make_a(char *str, size_t len);
t_a		*make_b(size_t len);
/* operators.c */
void	swap(t_a *tab, char c);
void	super_swap(t_a *a, t_a *b);
void	first_push(t_a *a, t_a *b);
int		push(t_a *src, t_a *dest, size_t len, char c);
/* rotate.c */
void	rotate(t_a *tab, size_t len, char c);
void	reverse_rotate(t_a *tab, size_t len, char c);

#endif
