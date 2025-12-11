/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:28:17 by meodev            #+#    #+#             */
/*   Updated: 2025/12/08 04:18:21 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_minimum(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	min = current->data;
	while (current)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	return (min);
}

int	find_maximum(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	max = current->data;
	while (current)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	return (max);
}

int	get_element_position(t_stack *stack, int value)
{
	t_node	*current;
	int		pos;

	if (!stack || !stack->top)
		return (-1);
	current = stack->top;
	pos = 0;
	while (current)
	{
		if (current->data == value)
			return (pos);
		pos++;
		current = current->next;
	}
	return (-1);
}

int	calculate_cost(t_stack *stack, int pos)
{
	int	size;
	int	cost_rotate;
	int	cost_reverse;

	size = stack->size;
	cost_rotate = pos;
	cost_reverse = size - pos;
	if (cost_rotate < cost_reverse)
		return (cost_rotate);
	return (cost_reverse);
}

int	get_chunk_count(int size)
{
	if (size <= 100)
		return (5);
	if (size <= 250)
		return (7);
	return (11);
}
