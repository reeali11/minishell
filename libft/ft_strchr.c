/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:37:43 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:37:45 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)(*s) == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (!(char)c)
		return ((char *)s);
	return (NULL);
}

// char	*ft_strchr(const char *str, int c)
// {
// 	if (!(char)c)
// 		return (NULL);
// 	while (*str)
// 	{
// 		if (*str == (char)c)
// 			return ((char *)str);
// 		str++;
// 	}
// 	return (NULL);
// }
