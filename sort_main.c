/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 02:50:16 by meodev            #+#    #+#             */
/*   Updated: 2025/11/16 02:50:18 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_ps *d)
{
	int	m;
	int	pos;
	int	i;

	m = d->a[0];
	pos = 0;
	i = 1;
	while (i < d->na)
	{
		if (d->a[i] < m)
		{
			m = d->a[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int	get_pos(t_ps *d)
{
	int	val;
	int	i;
	int	best;
	int	min_diff;
	int	diff;

	val = d->b[0];
	best = 0;
	i = 0;
	min_diff = INT_MAX;
	while (i < d->na)
	{
		diff = d->a[i] - val;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			best = i;
		}
		i++;
	}
	if (min_diff == INT_MAX)
		best = get_min(d);
	return (best);
}

void	mv_to(t_ps *d, int p)
{
	if (p <= d->na / 2)
	{
		while (p-- > 0)
			rot_a(d);
	}
	else
	{
		int count = d->na - p;
		while (count-- > 0)
			rrot_a(d);
	}
}

// Indexleme için yardımcı fonksiyon
static int *get_indexed(int *arr, int size)
{
    int *sorted = malloc(sizeof(int) * size);
    int *indexed = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        sorted[i] = arr[i];
    // Basit bubble sort ile sırala
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (sorted[j] > sorted[j + 1])
            {
                int tmp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = tmp;
            }
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (arr[i] == sorted[j])
                indexed[i] = j;
    free(sorted);
    return indexed;
}

void    srt_all(t_ps *d)
{
    int max = 0;
    int i, j;
    int bit = 0;
    int size = d->size;
    int *indexed = get_indexed(d->a, size);
    for (i = 0; i < size; i++)
        d->a[i] = indexed[i];
    free(indexed);
    for (i = 0; i < size; i++)
        if (d->a[i] > max)
            max = d->a[i];
    while ((max >> bit) != 0)
        bit++;
    for (j = 0; j < bit; j++)
    {
        i = 0;
        int n = d->na;
        while (i < n)
        {
            if (((d->a[0] >> j) & 1) == 0)
                psh_b(d);
            else
                rot_a(d);
            i++;
        }
        while (d->nb > 0)
            psh_a(d);
    }
}
