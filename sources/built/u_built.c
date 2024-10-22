/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_built.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:47:05 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:47:08 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mnsh.h"

// This function updates the data struct with the new paths
void	update_path(t_data *data)
{
	char	*tmp;

	tmp = ft_strdup(data->pwd);
	free(data->old_pwd);
	data->old_pwd = tmp;
	free(data->pwd);
	data->pwd = getcwd(NULL, 0);
}

size_t	is_equalsign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i + 1);
		i++;
	}
	return (0);
}

int	invalid_symbols(char *str, int f)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (f && i == (int)is_equalsign(str) - 1)
			break ;
		if (str[i] == '|' || str[i] == '<' || str[i] == '>' || str[i] == '['
			|| str[i] == ']' || str[i] == '=' || str[i] == '\''
			|| str[i] == '\"' || str[i] == ' ' || str[i] == ','
			|| str[i] == '.'
			|| str[i] == '*' || str[i] == ':' || str[i] == '/' || str[i] == '{'
			|| str[i] == '^' || str[i] == '%' || str[i] == '#' || str[i] == '@'
			|| str[i] == '!' || str[i] == '~' || str[i] == '-' || str[i] == '?'
			|| str[i] == '&' || str[i] == '}' || str[i] == '+' || str[i] == '$')
			return (1);
	}
	return (0);
}

int	is_valid_symbol(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '[' || c == ']'
		|| c == '\'' || c == '\"' || c == ' ' || c == ',' || c == '.'
		|| c == ':' || c == '/' || c == '{' || c == '}' || c == '+' || c == '^'
		|| c == '%' || c == '#' || c == '@' || c == '!' || c == '~' || c == '='
		|| c == '-' || c == '?' || c == '&' || c == '*');
}
