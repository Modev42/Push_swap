/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_operations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:30:56 by meodev            #+#    #+#             */
/*   Updated: 2025/12/08 04:21:28 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_buffer(char *buffer, int len, int is_negative)
{
	if (is_negative)
		buffer[len++] = '-';
	while (len > 0)
		write(1, &buffer[--len], 1);
}

void	print_number(int num)
{
	char	buffer[12];
	int		i;
	int		is_negative;

	is_negative = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	i = 0;
	if (num == 0)
		buffer[i++] = '0';
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	write_buffer(buffer, i, is_negative);
}

int	is_alphabetic(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}
