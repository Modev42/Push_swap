/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:50:49 by meodev            #+#    #+#             */
/*   Updated: 2025/11/16 02:50:50 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	srt_two(t_ps *d)
{
	if (d->a[0] > d->a[1])
		swp_a(d);
}

void	srt_three(t_ps *d)
{
	int	a;
	int	b;
	int	c;

	a = d->a[0];
	b = d->a[1];
	c = d->a[2];
	if (a > b && b > c)
	{
		swp_a(d);
		rrot_a(d);
	}
	else if (a > b && b < c && a > c)
		rot_a(d);
	else if (a > b && b < c && a < c)
		swp_a(d);
	else if (a < b && b > c && a > c)
		rrot_a(d);
	else if (a < b && b > c && a < c)
	{
		swp_a(d);
		rot_a(d);
	}
}
