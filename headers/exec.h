/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:31:34 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:31:37 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "parse.h"
# include "mnsh.h"

int				valid_redir(t_command *cmd);
int				valid_outfile(t_redir *redir);
int				valid_byopenfile(t_redir *redir);

// executor
int				exec_all(t_data *data);
int				pipe_cmd(t_data *data);
int				wait_pipe(int *pid, int amount);
int				err_exec(char *str, int code);

// exe_cmd
int				find_exe_cmd(t_command *cmd, t_data *data);
void			check_exe_cmd(t_command *cmd, t_data *data);
void			dup_cmd(t_command *cmd, t_data *data,
					int end[2], int fd_in);
void			nopipe_cmd(t_command *cmd, t_data *data);
int				exe_paths(t_data *data, t_command *cmd);
int				err_in_execve(char *cmd, int code);
int				is_directory(char *path);

// heredoc
int				send_heredoc(t_data *data, t_command *cmd);

int				check_redir_helper(int type, t_redir *dir);

//exec_data
int				find_exe_cmd_helper(t_command *cmd);

#endif
