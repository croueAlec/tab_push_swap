/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:26:34 by acroue            #+#    #+#             */
/*   Updated: 2024/01/23 15:36:29 by acroue           ###   ########.fr       */
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

typedef struct	s_len
{
	size_t		a;
	size_t		b;
	size_t		total;
}	t_len;

typedef struct s_a
{
	int				value;
	int				rank;
	struct s_len	*len;
	struct s_cost	cost;
}	t_a;

/* apply_cost.c */
void	apply_cost(t_a *a, t_a *b, size_t len_a, size_t len_b);
/* check_rank.c */
void	check_rank(t_a *tab, size_t length);
/* cost.c */
void	define_cost(t_a *a, t_a *b, size_t len_b);
/* push_swap.c */
void	tab_print(t_a *tab, size_t len);
void	print_cost(t_a *b, size_t len);
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
int		push_b(t_a *a, t_a *b, size_t len, char c);
int		push_a(t_a *b, t_a *a, size_t len, char c);
/* rotate.c */
void	rotate(t_a *tab, size_t len, char c);
void	reverse_rotate(t_a *tab, size_t len, char c);
void	r_and_b(t_a *a, t_a *b, size_t len_a, size_t len_b);
void	reverse_r_and_b(t_a *a, t_a *b, size_t len_a, size_t len_b);
/* sorting.c */
int		is_list_sorted(t_a *tab, size_t list_length);
void	sort_three(t_a *tab, size_t length);
void	move_b(t_a *tab, t_a *b, size_t length);

#endif
