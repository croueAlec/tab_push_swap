/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:10:49 by acroue            #+#    #+#             */
/*   Updated: 2024/01/24 19:53:35 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_len
{
	size_t		a;
	size_t		b;
	size_t		total;
}	t_len;

typedef struct s_a
{
	int				value;
	struct s_len	*len;
}	t_a;

/* checker_bonus.c */
int	apply_checker(char **instructions, t_a *a, t_a *b);
/* make_tab_bonus.c */
t_a		*make_a(char *str, size_t len);
t_a		*make_b(size_t len);
/* operators_bonus.c */
void	swap(t_a *tab);
void	super_swap(t_a *a, t_a *b);
int		push_b(t_a *a, t_a *b, size_t len);
int		push_a(t_a *b, t_a *a, size_t len);
/* parsing_bonus.c */
char	*ft_jointab(char **tab, size_t i, int length);
/* rotate_bonus.c */
void	rotate(t_a *tab, size_t len);
void	reverse_rotate(t_a *tab, size_t len);
void	r_and_b(t_a *a, t_a *b, size_t len_a, size_t len_b);
void	reverse_r_and_b(t_a *a, t_a *b, size_t len_a, size_t len_b);

#endif
