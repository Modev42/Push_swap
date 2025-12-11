/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medoev <meodev@student.42kocaeli.com       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:50:06 by meodev            #+#    #+#             */
/*   Updated: 2025/12/10 21:17:55 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_max(t_program *prog, int max, int pos)
{
	int	size;

	size = prog->b->size;
	if (pos <= size / 2)
	{
		while (prog->b->top->data != max)
			op_rotate(prog->b, 'b');
	}
	else
	{
		while (prog->b->top->data != max)
			op_reverse_rotate(prog->b, 'b');
	}
}

void	push_back_to_a(t_program *prog)
{
	int	max;
	int	pos;
	int	min;

	while (prog->b->size > 0)
	{
		max = find_maximum(prog->b);
		pos = get_element_position(prog->b, max);
		rotate_to_max(prog, max, pos);
		op_push(prog->b, prog->a, 'a');
	}
	min = find_minimum(prog->a);
	pos = get_element_position(prog->a, min);
	if (pos <= prog->a->size / 2)
	{
		while (prog->a->top->data != min)
			op_rotate(prog->a, 'a');
	}
	else
	{
		while (prog->a->top->data != min)
			op_reverse_rotate(prog->a, 'a');
	}
}

void	sort_large_stack(t_program *prog)
{
	int		chunk_count;

	chunk_count = get_chunk_count(prog->a->size);
	push_chunks_to_b(prog);
	while (prog->a->size > 0)
		op_push(prog->a, prog->b, 'b');
	push_back_to_a(prog);
}
