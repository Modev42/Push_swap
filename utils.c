/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:50:27 by meodev            #+#    #+#             */
/*   Updated: 2025/11/16 02:50:28 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	init(t_ps *d, int size)
{
	d->na = 0;
	d->nb = 0;
	d->size = size;
	d->a = malloc(sizeof(int) * size);
	d->b = malloc(sizeof(int) * size);
	if (!d->a || !d->b)
		ft_err();
	for (int i = 0; i < size; i++)
	{
		d->a[i] = 0;
		d->b[i] = 0;
	}
}

int	is_srt(t_ps *d)
{
	int	i;

	i = 0;
	while (i < d->na - 1)
	{
		if (d->a[i] > d->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_dup(t_ps *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->na)
	{
		j = i + 1;
		while (j < d->na)
		{
			if (d->a[i] == d->a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	to_int(char *s)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (*s < '0' || *s > '9')
		ft_err();
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			ft_err();
		s++;
	}
	if (*s != '\0')
		ft_err();
	return ((int)(n * sign));
}

void	free_all(t_ps *d)
{
	free(d->a);
	free(d->b);
}

int	count_args(int ac, char **av)
{
	int		i;
	int		count;
	char	**split;
	int		j;

	i = 1;
	count = 0;
	while (i < ac)
	{
		split = ft_split(av[i]);
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		free_split(split);
		i++;
	}
	return (count);
}
