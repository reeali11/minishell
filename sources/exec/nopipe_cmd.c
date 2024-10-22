/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nopipe_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:47:32 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:47:34 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mnsh.h"

int	err_in_execve(char *cmd, int code)
{
	char	*temp;

	if (code == 1 && !access(cmd, X_OK))
	{
		err_exec(cmd, 4);
		free(cmd);
		return (126);
	}
	if (code == 2)
	{
		temp = ft_substr(cmd, 0, ft_strlen(cmd) - 2);
		if (cmd[ft_strlen(cmd) - 1] == '/' && access(temp, F_OK))
		{
			free(temp);
			return (err_exec(cmd, 2));
		}
		free(temp);
		if (cmd[ft_strlen(cmd) - 1] != '/' && access(cmd, F_OK))
			return (err_exec(cmd, 1));
	}
	return (err_exec(cmd, 0));
}

/*
 */
int	find_exe_cmd(t_command *cmd, t_data *data)
{
	if (ft_strlen(cmd->command) == 0)
		return (err_exec(cmd->command, 0));
	if (is_directory(cmd->command))
		return (err_exec(cmd->command, 3));
	else if (cmd->command[ft_strlen(cmd->command) - 1] == '/')
		return (find_exe_cmd_helper(cmd));
	if (cmd->command[0] != '/' && cmd->command[0] != '.')
	{
		if (exe_paths(data, cmd) != 0)
			return (127);
	}
	else if (!access(cmd->command, F_OK) && (cmd->command[0] == '/'
			|| cmd->command[0] == '.'))
	{
		if (access(cmd->command, X_OK))
			return (err_exec(cmd->command, 4));
		execve(cmd->command, cmd->args, data->envp);
	}
	else if (access(cmd->command, F_OK))
		return (err_in_execve(cmd->command, 1));
	return (err_in_execve(cmd->command, 0));
}

void	check_exe_cmd(t_command *cmd, t_data *data)
{
	int	exit_code;

	exit_code = 0;
	if (cmd->redirections && valid_redir(cmd))
	{
		free2_data(data);
		free1_data(data);
		exit(1);
	}
	if (cmd->builtin != NULL)
	{
		exit_code = cmd->builtin(data, cmd);
		free2_data(data);
		free1_data(data);
		exit(exit_code);
	}
	else if (cmd->command)
		exit_code = find_exe_cmd(cmd, data);
	free2_data(data);
	free1_data(data);
	exit(exit_code);
}

/*
 */
void	dup_cmd(t_command *cmd, t_data *data, int end[2], int fd_in)
{
	if (cmd->prev && dup2(fd_in, STDIN_FILENO) < 0)
		err_all(4);
	close(end[0]);
	if (cmd->next && dup2(end[1], STDOUT_FILENO) < 0)
		err_all(4);
	close(end[1]);
	if (cmd->prev)
		close(fd_in);
	check_exe_cmd(cmd, data);
}

/*
 */
void	nopipe_cmd(t_command *cmd, t_data *data)
{
	int	pid;
	int	status;
	int	exit_status;

	exit_status = -1;
	if (send_heredoc(data, cmd) == EXIT_FAILURE)
		return ;
	pid = fork();
	if (pid < 0)
		err_all(5);
	else if (pid == 0)
		check_exe_cmd(cmd, data);
	if (cmd->builtin == b_export || cmd->builtin == b_cd
		|| cmd->builtin == b_exit || cmd->builtin == b_unset)
		p_builtins(data, cmd);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		exit_status = WEXITSTATUS(status);
	if (g_status_code != HEREDOC_EXIT && exit_status != -1)
		g_status_code = exit_status;
}
