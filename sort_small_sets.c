/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_sets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:58:21 by meodev            #+#    #+#             */
/*   Updated: 2025/12/08 04:24:14 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_case1(t_stack *a, int first, int second, int third)
{
	if (first > second && second < third && first < third)
		op_swap(a, 'a');
	else if (first > second && second > third)
	{
		op_swap(a, 'a');
		op_reverse_rotate(a, 'a');
	}
	else if (first > second && second < third && first > third)
		op_rotate(a, 'a');
}

static void	sort_three_case2(t_stack *a, int first, int second, int third)
{
	if (first < second && second > third && first < third)
	{
		op_swap(a, 'a');
		op_rotate(a, 'a');
	}
	else if (first < second && second > third && first > third)
		op_reverse_rotate(a, 'a');
}

void	sort_three_elements(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (is_stack_sorted(a))
		return ;
	first = a->top->data;
	second = a->top->next->data;
	third = a->top->next->next->data;
	sort_three_case1(a, first, second, third);
	sort_three_case2(a, first, second, third);
}

static void	push_min_to_b(t_program *prog)
{
	int	min;
	int	pos;

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
	op_push(prog->a, prog->b, 'b');
}

void	sort_five_elements(t_program *prog)
{
	while (prog->a->size > 3)
		push_min_to_b(prog);
	sort_three_elements(prog->a);
	while (prog->b->size > 0)
		op_push(prog->b, prog->a, 'a');
}
