/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:51:09 by meodev            #+#    #+#             */
/*   Updated: 2025/12/08 05:11:10 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_tokens(const char *text, char sep)
{
	int	count;
	int	in_token;

	(void)sep;
	count = 0;
	in_token = 0;
	while (*text)
	{
		if (is_whitespace(*text))
			in_token = 0;
		else if (!in_token)
		{
			in_token = 1;
			count++;
		}
		text++;
	}
	return (count);
}

char	*extract_token(const char *start, const char *end)
{
	char	*token;
	int		len;
	int		i;

	len = end - start;
	token = malloc(len + 1);
	if (!token)
		return (NULL);
	i = 0;
	while (i < len)
	{
		token[i] = start[i];
		i++;
	}
	token[i] = '\0';
	return (token);
}

void	cleanup_tokens(char **tokens, int count)
{
	while (count > 0)
		free(tokens[--count]);
	free(tokens);
}
