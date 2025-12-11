/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:30:46 by meodev            #+#    #+#             */
/*   Updated: 2025/12/08 05:30:48 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	text_length(const char *text)
{
	const char	*start;

	start = text;
	while (*text)
		text++;
	return (text - start);
}

char	*copy_text(const char *source)
{
	char	*result;
	int		len;
	int		i;

	len = text_length(source);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = source[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

int	compare_text(const char *t1, const char *t2)
{
	if (!t1 || !t2)
		return (t1 == t2);
	while (*t1 && *t2 && *t1 == *t2)
	{
		t1++;
		t2++;
	}
	return (*t1 == *t2);
}

void	print_text(const char *text)
{
	write(1, text, text_length(text));
}
