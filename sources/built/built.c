/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:46:55 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:46:56 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mnsh.h"

int	(*builtin_fcn_name(char *str))(t_data *data, t_command *cmds)
{
	static void	*builtins[7][2] = {{"echo", b_echo}, {"cd", b_cd}, {"pwd",
		b_pwd}, {"export", b_export}, {"unset", b_unset}, {"env", b_env},
	{"exit", b_exit}};
	int			i;

	i = 0;
	while (str && i < 7)
	{
		if (!ft_strncmp(builtins[i][0], str, ft_strlen((builtins[i][0])))
			&& !ft_strncmp(builtins[i][0], str, ft_strlen(str)))
			return (builtins[i][1]);
		i++;
	}
	return (NULL);
}

int	p_extract_path(t_data *data, char *str)
{
	char	*tmp;
	int		ret;

	ret = -1;
	tmp = find_path_ret(str, data);
	if (tmp)
	{
		ret = chdir(tmp);
		free(tmp);
	}
	return (ret);
}
