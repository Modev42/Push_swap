/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 01:29:26 by meodev            #+#    #+#             */
/*   Updated: 2025/11/18 21:13:44 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse(t_ps *d, int ac, char **av)
{
	int		j;
	char	**split;
	int		i = 1;

	while (i < ac)
	{
		split = ft_split(av[i]);
		j = 0;
		while (split[j])
		{
			d->a[d->na] = to_int(split[j]);
			d->na++;
			j++;
		}
		free_split(split);
		i++;
	}
}

void	choose_sort(t_ps *d)
{
	if (d->na == 2)
		srt_two(d);
	else if (d->na == 3)
		srt_three(d);
	else
		srt_all(d);
}

int	main(int ac, char **av)
{
	t_ps	d;
	int size;

	if (ac < 2)
		ft_err();
	size = count_args(ac, av);
	init(&d, size);
	parse(&d, ac, av);
	if (is_dup(&d))
		ft_err();
	if (is_srt(&d))
	{
		free_all(&d);
		return (0);
	}
	choose_sort(&d);
	free_all(&d);
	return (0);
}
