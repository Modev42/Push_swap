/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:51:01 by meodev            #+#    #+#             */
/*   Updated: 2025/11/16 02:51:02 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_ps
{
	int	*a;
	int	*b;
	int	na;
	int	nb;
	int	size; // toplam eleman sayısı
} t_ps;

/* ops_push.c */
void	psh_a(t_ps *d);
void	psh_b(t_ps *d);

/* ops_swap.c */
void	swp_a(t_ps *d);
void	swp_b(t_ps *d);

/* ops_rotate.c */
void	rot_a(t_ps *d);
void	rot_b(t_ps *d);
void	rrot_a(t_ps *d);
void	rrot_b(t_ps *d);

/* utils.c */
int		to_int(char *s);
void	ft_err(void);
int		is_dup(t_ps *d);
int		is_srt(t_ps *d);
void	init(t_ps *d, int size);
void	free_all(t_ps *d);

/* sort_small.c */
void	srt_two(t_ps *d);
void	srt_three(t_ps *d);

/* sort_main.c */
int		get_min(t_ps *d);
int		get_pos(t_ps *d);
void	mv_to(t_ps *d, int p);
void	srt_all(t_ps *d);

/* split.c */
char	**ft_split(char *str);
void	free_split(char **arr);
int		count_args(int ac, char **av);

#endif
