/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:42:05 by meodev            #+#    #+#             */
/*   Updated: 2025/12/08 03:29:06 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap(t_stack *stack, char stack_name)
{
	int	temp;

	if (!stack || stack->size < 2)
		return ;
	temp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = temp;
	write(1, "s", 1);
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

void	op_push(t_stack *from, t_stack *to, char to_name)
{
	int	value;

	if (stack_is_empty(from))
		return ;
	value = stack_pop(from);
	stack_push(to, value);
	write(1, "p", 1);
	write(1, &to_name, 1);
	write(1, "\n", 1);
}

static void	rotate_helper(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	first = stack->top;
	stack->top = first->next;
	stack->top->prev = NULL;
	last = stack->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	op_rotate(t_stack *stack, char stack_name)
{
	if (!stack || stack->size < 2)
		return ;
	rotate_helper(stack);
	write(1, "r", 1);
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}
