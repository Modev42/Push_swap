/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:50:01 by meodev            #+#    #+#             */
/*   Updated: 2025/11/16 02:50:04 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swp_a(t_ps *d)
{
	int	tmp;

	if (d->na < 2)
		return ;
	tmp = d->a[0];
	d->a[0] = d->a[1];
	d->a[1] = tmp;
	write(1, "sa\n", 3);
}

void	swp_b(t_ps *d)
{
	int	tmp;

	if (d->nb < 2)
		return ;
	tmp = d->b[0];
	d->b[0] = d->b[1];
	d->b[1] = tmp;
	write(1, "sb\n", 3);
}
