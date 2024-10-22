/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini1_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:51:22 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:51:24 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mnsh.h"

void	ini1_data(t_data *data, char **envp)
{
	rl_catch_signals = 0;
	rl_event_hook = event;
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	data->cmds = 0;
	data->paths = 0;
	data->pwd = 0;
	data->old_pwd = 0;
	data->pipes = 0;
	data->pid = 0;
	data->envp = 0;
	data->reset = false;
	if (*envp != 0)
		data->envp = dup_arr(envp);
	find_pwd(data);
}
