/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:51:16 by meodev            #+#    #+#             */
/*   Updated: 2025/12/08 04:31:17 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_token_end(char **result, const char **text,
				const char **token_start, int *token_idx)
{
	result[*token_idx] = extract_token(*token_start, *text);
	if (!result[*token_idx])
		return (0);
	(*token_idx)++;
	*token_start = NULL;
	return (1);
}

static int	process_text(char **result, const char *text, char sep)
{
	const char	*token_start;
	int			token_idx;

	(void)sep;
	token_idx = 0;
	token_start = NULL;
	while (*text || token_start)
	{
		if (!token_start && !is_whitespace(*text) && *text)
			token_start = text;
		else if (token_start && (is_whitespace(*text) || !*text))
		{
			if (!handle_token_end(result, &text, &token_start, &token_idx))
				return (0);
		}
		if (*text)
			text++;
	}
	result[token_idx] = NULL;
	return (1);
}

char	**tokenize(const char *text, char separator)
{
	char	**result;
	int		total_tokens;

	total_tokens = count_tokens(text, separator);
	result = malloc(sizeof(char *) * (total_tokens + 1));
	if (!result)
		return (NULL);
	if (!process_text(result, text, separator))
	{
		cleanup_tokens(result, total_tokens);
		return (NULL);
	}
	return (result);
}

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

long	convert_to_long(const char *text)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (is_whitespace(*text))
		text++;
	if (*text == '-' || *text == '+')
	{
		if (*text == '-')
			sign = -1;
		text++;
	}
	while (is_numeric(*text))
	{
		result = result * 10 + (*text - '0');
		text++;
	}
	return (result * sign);
}
