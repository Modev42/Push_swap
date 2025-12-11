/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_sets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev  <meodev@student.42kocaeli.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:53:50 by meodev            #+#    #+#             */
/*   Updated: 2025/12/10 21:17:55 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	should_rotate_b(t_program *prog, int chunk_max, int chunk_size)
{
	if (prog->b->size > 1)
	{
		if (prog->b->top->data < chunk_max - (chunk_size / 2))
			return (1);
	}
	return (0);
}

static int	count_in_chunk(t_stack *stack, int chunk_max)
{
	t_node	*current;
	int		count;

	current = stack->top;
	count = 0;
	while (current)
	{
		if (current->data <= chunk_max)
			count++;
		current = current->next;
	}
	return (count);
}

static void	push_one_chunk(t_program *prog, int chunk_max, int chunk_size)
{
	int	to_push;
	int	pushed;
	int	rotations;

	to_push = count_in_chunk(prog->a, chunk_max);
	pushed = 0;
	rotations = 0;
	while (pushed < to_push && prog->a->size > 3)
	{
		if (prog->a->top->data <= chunk_max)
		{
			op_push(prog->a, prog->b, 'b');
			pushed++;
			rotations = 0;
			if (should_rotate_b(prog, chunk_max, chunk_size))
				op_rotate(prog->b, 'b');
		}
		else
		{
			op_rotate(prog->a, 'a');
			rotations++;
			if (rotations >= prog->a->size)
				break ;
		}
	}
}

void	push_chunks_to_b(t_program *prog)
{
	int	chunk_count;
	int	chunk_size;
	int	range;
	int	min;
	int	i;

	min = find_minimum(prog->a);
	range = find_maximum(prog->a) - min;
	chunk_count = get_chunk_count(prog->a->size);
	chunk_size = range / chunk_count;
	i = 0;
	while (i < chunk_count && prog->a->size > 3)
	{
		push_one_chunk(prog, min + ((i + 1) * chunk_size), chunk_size);
		i++;
	}
}
