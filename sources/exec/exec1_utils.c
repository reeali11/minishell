/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec1_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:47:17 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:47:19 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mnsh.h"

int	find_exe_cmd_helper(t_command *cmd)
{
	char	*tmp;
	char	*tmp1;

	tmp1 = ft_strtrim(cmd->command, "/");
	if (cmd->command[0] == '/')
		tmp = ft_strjoin("/", tmp1);
	else
		tmp = ft_strdup(tmp1);
	free(tmp1);
	if (!access(tmp, F_OK))
	{
		free(tmp);
		return (err_exec(cmd->command, 2));
	}
	else
	{
		free(tmp);
		return (err_exec(cmd->command, 1));
	}
}
