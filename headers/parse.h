/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:33:45 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:33:48 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "mnsh.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdbool.h>
# include "lex.h"

# define CLEAR_SCREEN_SEQ "\033[2J\033[H"

typedef struct s_command	t_command;
typedef struct s_redir		t_redir;

typedef struct s_data
{
	struct s_command	*cmds;
	char				*input;
	char				**envp;
	char				**paths;
	char				*pwd;
	char				*old_pwd;
	int					pipes;
	int					*pid;
	bool				reset;
	bool				heredoc;
}	t_data;

typedef struct s_command
{
	char				*command;
	char				**args;
	t_redir				*redirections;
	struct s_command	*next;
	int					(*builtin)(t_data *, t_command *);
	struct s_command	*prev;
	char				*filename_hd;
}	t_command;

typedef struct s_redir
{
	char			*path;
	int				type;
	int				fd;
	struct s_redir	*next;
	struct s_redir	*prev;
}	t_redir;

typedef enum e_redir
{
	IGNORE,
	OPEN,
	APPEND,
	WRITE,
	INPUT,
	HEREDOC,
}	t_redir_type;

int			is_space(char c);
int			is_quote(char c);
int			is_symbol(char c);
void		skip_quotes(int *i, char *input);
void		skip_space(char *input, int *j);
void		push_cmd(t_data *data, t_command *cmd);

int			valid_input(char *input);
int			split2cmds(t_split *split, t_data *data);
char		**init_args(t_word *start, char *command);
int			parse_all(t_data *data);
char		*ft_getenv(char *var, t_data *data);
t_word		*init_cmd(t_word *ptr, t_command *new_cmd);
char		*expand_err(char *cont, int *i);
char		*replace_env(char *str, int *i, char *exp, int len);
void		last_in_redir(t_command *cmd);
void		last_out_redir(t_command *cmd);
t_command	*push_redir(t_command *cmd, t_word *ptr);
int			count_args(t_word *start, char *command);

#endif
