/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:59:29 by meodev            #+#    #+#             */
/*   Updated: 2025/12/08 04:01:31 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_program *prog)
{
	if (is_stack_sorted(prog->a))
		return ;
	if (prog->a->size == 2)
		op_swap(prog->a, 'a');
	else if (prog->a->size == 3)
		sort_three_elements(prog->a);
	else if (prog->a->size <= 5)
		sort_five_elements(prog);
	else
		sort_large_stack(prog);
}
