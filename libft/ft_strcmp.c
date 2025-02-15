/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:37:49 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:37:51 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (!ft_strncmp(s1, s2, ft_strlen(s2))
		&& !ft_strncmp(s1, s2, ft_strlen(s1)))
		return (0);
	return (1);
}
