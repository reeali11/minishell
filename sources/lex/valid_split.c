/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:49:38 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:49:41 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mnsh.h"

// checks for issues in input structure
int	valid_split(t_split *split)
{
	t_word	*ptr;

	ptr = split->first;
	if (ptr && ptr->type == PIPE)
		return (!err_parser(ptr));
	if (ptr && (split->last->type == PIPE || split->last->type == REDIR))
		return (!err_all(0));
	while (ptr)
	{
		if (ptr->type == REDIR && (ptr->next && (ptr->next->type == REDIR
					|| ptr->next->type == PIPE)))
			return (!err_parser(ptr));
		if (ptr->type == PIPE && (ptr->next && ptr->next->type == PIPE))
			return (!err_parser(ptr));
		ptr = ptr->next;
	}
	return (1);
}
