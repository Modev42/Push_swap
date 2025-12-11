/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:50:33 by meodev            #+#    #+#             */
/*   Updated: 2025/12/08 05:32:34 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_peek(t_stack *stack)
{
	if (!stack || !stack->top)
		return (0);
	return (stack->top->data);
}

int	stack_is_empty(t_stack *stack)
{
	return (!stack || stack->size == 0);
}
