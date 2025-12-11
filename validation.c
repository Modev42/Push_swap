/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:51:24 by meodev            #+#    #+#             */
/*   Updated: 2025/12/08 05:01:25 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicates(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (compare_text(args[i], args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_range(const char *arg)
{
	long	num;

	num = convert_to_long(arg);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

static int	check_format(const char *arg)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i] && is_numeric(arg[i]))
	{
		has_digit = 1;
		i++;
	}
	if (!has_digit)
		return (0);
	while (arg[i] && is_whitespace(arg[i]))
		i++;
	if (arg[i] != '\0')
		return (0);
	return (1);
}

int	validate_args(char **args)
{
	int	i;

	if (!check_duplicates(args))
		return (0);
	i = 0;
	while (args[i])
	{
		if (!check_format(args[i]))
			return (0);
		if (!check_range(args[i]))
			return (0);
		i++;
	}
	return (1);
}

void	error_exit(const char *msg)
{
	print_text(msg);
	exit(1);
}
