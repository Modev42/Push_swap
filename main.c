/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:58:27 by meodev            #+#    #+#             */
/*   Updated: 2025/12/08 02:42:10 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_program	*init_program(void)
{
	t_program	*prog;

	prog = malloc(sizeof(t_program));
	if (!prog)
		return (NULL);
	prog->a = stack_create();
	prog->b = stack_create();
	prog->input = NULL;
	prog->arg_count = 0;
	if (!prog->a || !prog->b)
	{
		memory_cleanup(prog, 0);
		return (NULL);
	}
	return (prog);
}

static void	load_stack(t_stack *stack, char **args)
{
	int	i;
	int	count;

	count = 0;
	while (args[count])
		count++;
	i = count - 1;
	while (i >= 0)
	{
		stack_push(stack, (int)convert_to_long(args[i]));
		i--;
	}
}

static void	handle_error_cleanup(t_program *prog, int should_free_input)
{
	if (prog)
	{
		if (should_free_input && prog->input)
			free_tokens(prog->input);
		memory_cleanup(prog, 0);
	}
	write(2, "Error\n", 6);
	exit(1);
}

static void	process_arguments(t_program *prog, int argc, char **argv)
{
	int	should_free;

	should_free = 0;
	if (argc == 2)
	{
		prog->input = tokenize(argv[1], ' ');
		should_free = 1;
	}
	else
		prog->input = &argv[1];
	if (!prog->input || !prog->input[0])
		handle_error_cleanup(prog, should_free);
	if (!validate_args(prog->input))
		handle_error_cleanup(prog, should_free);
	load_stack(prog->a, prog->input);
	if (should_free)
		free_tokens(prog->input);
}

int	main(int argc, char **argv)
{
	t_program	*prog;

	if (argc < 2)
		return (0);
	prog = init_program();
	if (!prog)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	process_arguments(prog, argc, argv);
	sort_stack(prog);
	memory_cleanup(prog, 0);
	return (0);
}
