/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:50:36 by meodev            #+#    #+#             */
/*   Updated: 2025/11/16 02:50:37 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_a(t_ps *d)
{
	int	tmp;
	int	i;

	if (d->na < 2)
		return ;
	tmp = d->a[0];
	i = 0;
	while (i < d->na - 1)
	{
		d->a[i] = d->a[i + 1];
		i++;
	}
	d->a[d->na - 1] = tmp;
	write(1, "ra\n", 3);
}

void	rot_b(t_ps *d)
{
	int	tmp;
	int	i;

	if (d->nb < 2)
		return ;
	tmp = d->b[0];
	i = 0;
	while (i < d->nb - 1)
	{
		d->b[i] = d->b[i + 1];
		i++;
	}
	d->b[d->nb - 1] = tmp;
	write(1, "rb\n", 3);
}

void	rrot_a(t_ps *d)
{
	int	tmp;
	int	i;

	if (d->na < 2)
		return ;
	tmp = d->a[d->na - 1];
	i = d->na - 1;
	while (i > 0)
	{
		d->a[i] = d->a[i - 1];
		i--;
	}
	d->a[0] = tmp;
	write(1, "rra\n", 4);
}

void	rrot_b(t_ps *d)
{
	int	tmp;
	int	i;

	if (d->nb < 2)
		return ;
	tmp = d->b[d->nb - 1];
	i = d->nb - 1;
	while (i > 0)
	{
		d->b[i] = d->b[i - 1];
		i--;
	}
	d->b[0] = tmp;
	write(1, "rrb\n", 4);
}
