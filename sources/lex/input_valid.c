/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:49:16 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:49:19 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mnsh.h"

// checks if char is present in string
static int	invalid_char(char *input, char c)
{
	int	i;
	int	len;

	len = (int)ft_strlen(input);
	if (!ft_strchr(input, c))
		return (0);
	i = 0;
	while (i < len)
	{
		while (input[i] && is_space(input[i]))
			i++;
		if (input[i] && is_quote(input[i]))
			skip_quotes(&i, input);
		if (input[i] && input[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// checks if this string has open/invalid quotes
static int	open_quotes(char *input)
{
	int	open;
	int	i;
	int	quote;

	open = 0;
	i = 0;
	while (input && input[i])
	{
		while (input[i] && !is_quote(input[i]))
			i++;
		if (is_quote(input[i]))
		{
			open = 1;
			quote = input[i];
			i++;
		}
		while (input[i] && input[i] != quote)
			i++;
		if (input[i] && input[i] == quote)
		{
			open = 0;
			i++;
		}
	}
	return (open);
}

// checks for basic input issues
int	valid_input(char *input)
{
	if (open_quotes(input))
		return (!err_all(2));
	if (invalid_char(input, ';'))
		return (!err_token_invalid("';'"));
	if (invalid_char(input, '&'))
		return (!err_token_invalid("'&'"));
	if (invalid_char(input, '\\'))
		return (!err_token_invalid("'\\'"));
	return (1);
}
