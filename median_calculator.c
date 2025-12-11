/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median_calculator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:38:34 by meodev            #+#    #+#             */
/*   Updated: 2025/12/08 02:18:36 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_stack_to_array(t_stack *stack, int *arr)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 0;
	while (current)
	{
		arr[i++] = current->data;
		current = current->next;
	}
}

static void	swap_values(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				swap_values(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
}

static int	calculate_fallback_median(t_stack *stack)
{
	int	min;
	int	max;

	min = find_minimum(stack);
	max = find_maximum(stack);
	return (min + (max - min) / 2);
}

int	find_median(t_stack *stack)
{
	int	*arr;
	int	median;

	if (!stack || !stack->top)
		return (0);
	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		return (calculate_fallback_median(stack));
	copy_stack_to_array(stack, arr);
	sort_array(arr, stack->size);
	median = arr[stack->size / 2];
	free(arr);
	return (median);
}
