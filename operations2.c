/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:49:21 by meodev            #+#    #+#             */
/*   Updated: 2025/12/08 04:11:19 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_helper(t_stack *stack)
{
	t_node	*last;
	t_node	*second_last;

	last = stack->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
}

void	op_reverse_rotate(t_stack *stack, char stack_name)
{
	if (!stack || stack->size < 2)
		return ;
	reverse_rotate_helper(stack);
	write(1, "rr", 2);
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}
