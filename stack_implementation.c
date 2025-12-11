/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_implementation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:50:33 by meodev            #+#    #+#             */
/*   Updated: 2025/12/08 05:32:34 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_create(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	stack_destroy(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

t_node	*node_create(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	stack_push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = node_create(value);
	if (!new_node)
		error_exit("Memory allocation failed\n");
	if (stack->top)
	{
		new_node->next = stack->top;
		stack->top->prev = new_node;
	}
	stack->top = new_node;
	stack->size++;
}

int	stack_pop(t_stack *stack)
{
	t_node	*node;
	int		value;

	if (!stack || !stack->top)
		return (0);
	node = stack->top;
	value = node->data;
	stack->top = node->next;
	if (stack->top)
		stack->top->prev = NULL;
	free(node);
	stack->size--;
	return (value);
}
