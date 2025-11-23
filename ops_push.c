/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 01:40:23 by meodev            #+#    #+#             */
/*   Updated: 2025/11/18 21:49:51 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	psh_a(t_ps *d)
{
	int	i;

	if (d->nb == 0)
		return ;
	i = d->na;
	while (i > 0)
	{
		d->a[i] = d->a[i - 1];
		i--;
	}
	d->a[0] = d->b[0];
	i = 0;
	while (i < d->nb - 1)
	{
		d->b[i] = d->b[i + 1];
		i++;
	}
	d->na++;
	d->nb--;
	write(1, "pa\n", 3);
}

void	psh_b(t_ps *d)
{
	int	i;

	if (d->na == 0)
		return ;
	i = d->nb;
	while (i > 0)
	{
		d->b[i] = d->b[i - 1];
		i--;
	}
	d->b[0] = d->a[0];
	i = 0;
	while (i < d->na - 1)
	{
		d->a[i] = d->a[i + 1];
		i++;
	}
	d->nb++;
	d->na--;
	write(1, "pb\n", 3);
}
