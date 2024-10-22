/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:46:30 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:46:32 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mnsh.h"

int	b_env(t_data *data, t_command *cmds)
{
	int	i;

	(void)cmds;
	i = 0;
	while (data->envp[i])
	{
		ft_putendl_fd(data->envp[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}

char	**bubble_sort(char **arr, int n)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (ft_strncmp(arr[j], arr[j + 1], ft_strlen(arr[j])
					+ ft_strlen(arr[j + 1])) > 0)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

char	**sort_env(char **env)
{
	int		i;
	char	**sorted;

	i = 0;
	while (env && env[i])
		i++;
	sorted = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!sorted)
	{
		err_all(1);
		return (0);
	}
	i = -1;
	while (env && env[++i])
		sorted[i] = ft_strdup(env[i]);
	return (bubble_sort(sorted, i));
}

void	do_sort_env(t_data *data)
{
	int		i;
	char	**sorted;
	char	*temp;

	sorted = sort_env(data->envp);
	i = 0;
	while (sorted && sorted[i])
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		temp = ft_substr(sorted[i], 0, is_equalsign(sorted[i]));
		ft_putstr_fd(temp, STDOUT_FILENO);
		free(temp);
		ft_putstr_fd("\"", STDOUT_FILENO);
		ft_putstr_fd(&sorted[i][is_equalsign(sorted[i])], STDOUT_FILENO);
		ft_putendl_fd("\"", STDOUT_FILENO);
		i++;
	}
	free_double_ptr((void **)sorted);
	return ;
}
