/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:31:42 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:31:44 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

# include "parse.h"

typedef struct s_word	t_word;
typedef struct s_data	t_data;

typedef struct s_split
{
	int		cmds;
	t_word	*first;
	t_word	*last;
}	t_split;

typedef struct s_word
{
	char			*cont;
	int				index;
	int				type;
	struct s_word	*next;
	struct s_word	*prev;
}	t_word;

typedef enum e_word_type
{
	CMD,
	FLAG,
	REDIR,
	PATH,
	PIPE,
	QUOTE,
	ARG,
	STR,
}	t_word_type;

t_split	*input2split(char *input, t_data *data);
int		valid_split(t_split *split);
int		push_word(t_split *split, char *c, int type);
void	free_split(t_split *split);
int		pre_label_word(char *input, int *i, t_split *split);
int		exp_define_quote(t_split *split);
t_word	*create_word(char *c, int type);
int		expand_env(t_split *split, t_data *data);
void	label_word(t_split *split);
char	*expand_env_quotes(t_word *word, int *i, t_data *data);
int		found_env(char *old, int *i, t_word *word, t_data *data);
int		found_env_helper(t_word *word, char *old, int *i);

#endif
