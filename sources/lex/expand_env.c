/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:49:06 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:49:08 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mnsh.h"

// replaces the environment var with its value
char	*replace_env(char *str, int *i, char *exp, int len)
{
	char	*full;
	int		j;
	int		k;

	full = (char *)ft_calloc((ft_strlen(str) - len) + ft_strlen(exp) + 2,
			sizeof(char));
	if (!full)
		err_all(1);
	j = -1;
	k = (*i) - len - 1;
	while (full && ++j < k)
		full[j] = str[j];
	k = 0;
	while (full && k < (int)ft_strlen(exp))
		full[j++] = exp[k++];
	k = (*i);
	while (full && k < (int)ft_strlen(str))
		full[j++] = str[k++];
	if (str)
		free(str);
	if (exp)
		free(exp);
	*i = 0;
	return (full);
}

// finds location of env and allocates memory for replacement
int	found_env(char *old, int *i, t_word *word, t_data *data)
{
	int		len;
	char	*var;
	int		j;
	char	*env;

	len = found_env_helper(word, old, i);
	if (len < 0)
		return (1);
	var = (char *)ft_calloc(len + 1, sizeof(char));
	if (!var)
		return (!err_all(1));
	j = 0;
	(*i)++;
	while (j < len)
		var[j++] = old[(*i)++];
	env = ft_getenv(var, data);
	if (!env)
		return (0);
	word->cont = replace_env(old, i, env, len);
	free(var);
	if (!word->cont)
		return (0);
	return (1);
}

// expands env variables except in quotes, expand_err = $?
int	expand_env_str(t_word *word, t_data *data)
{
	int	i;

	i = 0;
	while (word->cont && word->cont[i])
	{
		if (word->cont[i] == '$' && word->cont[i + 1] && word->cont[i
				+ 1] == '?')
			word->cont = expand_err(word->cont, &i);
		else if (word->cont[i] == '$' && word->cont[i + 1]
			&& is_valid_symbol(word->cont[i + 1]))
			i = i + 2;
		else if (word->cont[i] == '$' && word->cont[i + 1])
		{
			if (!found_env(word->cont, &i, word, data))
				return (0);
		}
		else
			i++;
	}
	return (1);
}

// expands env variables in double quotes
int	expand_var_quote(t_word *word, t_data *data)
{
	int	i;

	if (!ft_strchr(word->cont, '$'))
		return (1);
	i = 0;
	while (word->cont[i])
	{
		if (word->cont[i] == '$' && word->cont[i + 1] && word->cont[i
				+ 1] == '?')
			word->cont = expand_err(word->cont, &i);
		else if (word->cont[i] == '$' && !found_env(word->cont, &i, word, data))
			return (0);
		else if (word->cont[i] == '\'')
			skip_quotes(&i, word->cont);
		else if (word->cont[i] == '\"')
			word->cont = expand_env_quotes(word, &i, data);
		else
			i++;
	}
	return (1);
}

// redirects tokens to expanders
// where is type of ARG, CMD, PATH ?
int	expand_env(t_split *split, t_data *data)
{
	t_word	*ptr;
	int		success;

	success = 1;
	ptr = split->first;
	while (ptr)
	{
		if (ptr->type == STR || ptr->type == CMD || ptr->type == ARG
			|| ptr->type == PATH)
			success = expand_env_str(ptr, data);
		else if (ptr->type == QUOTE)
			success = expand_var_quote(ptr, data);
		if (!success)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
