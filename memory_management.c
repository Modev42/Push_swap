/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:31:50 by meodev            #+#    #+#             */
/*   Updated: 2025/12/08 01:31:54 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	memory_cleanup(t_program *prog, int free_input)
{
	if (!prog)
		return ;
	if (prog->a)
		stack_destroy(prog->a);
	if (prog->b)
		stack_destroy(prog->b);
	if (free_input && prog->input)
		free_tokens(prog->input);
	free(prog);
}
