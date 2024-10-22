/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:49:28 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:49:29 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mnsh.h"

// frees split structure
void	free_split(t_split *split)
{
	t_word	*del;
	t_word	*ptr;

	if (!split)
		return ;
	ptr = split->first;
	while (ptr)
	{
		free(ptr->cont);
		del = ptr;
		ptr = ptr->next;
		free(del);
	}
	free(split);
}

// splits input to space-separated words
int	input2words(char *input, t_split *split)
{
	int	i;

	i = 0;
	while (input[i])
	{
		while (input[i] && is_space(input[i]))
			i++;
		if (input[i])
		{
			if (pre_label_word(input, &i, split) == 0)
				return (0);
		}
	}
	return (1);
}

// splits input, checks errors, expands env,
// combines quotes, and sorts type
t_split	*input2split(char *input, t_data *data)
{
	t_split	*split;

	split = (t_split *)ft_calloc(1, sizeof(t_split));
	if (!split)
	{
		err_all(1);
		return (0);
	}
	if (input2words(input, split) == 0 || valid_split(split) == 0)
	{
		free_split(split);
		return (0);
	}
	if (expand_env(split, data) == 0 || exp_define_quote(split) == 0)
	{
		free_split(split);
		return (0);
	}
	label_word(split);
	return (split);
}

void	label_word(t_split *split)
{
	t_word	*ptr;

	ptr = split->first;
	if (ptr && ptr->type == STR)
		ptr->type = CMD;
	while (ptr)
	{
		if (ptr->prev && ptr->type == STR && ptr->prev->type == PIPE)
			ptr->type = CMD;
		else if (ptr->prev && ptr->prev->type == REDIR)
			ptr->type = PATH;
		else if (ptr->type == STR)
			ptr->type = ARG;
		ptr = ptr->next;
	}
}
