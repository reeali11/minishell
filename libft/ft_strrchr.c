/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:38:53 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:38:54 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = (int)ft_strlen(s);
	s += len;
	while (len >= 0)
	{
		if ((unsigned char)(*s) == (unsigned char)c)
			return ((char *)s);
		s--;
		len--;
	}
	return (NULL);
}

// char	*ft_strrchr(const char *str, int c)
// {
// 	char	*result;
// 	if (!(char)c)
// 		return (NULL);
// 	result = 0;
// 	while (*str)
// 	{
// 		if (*str == (char)c)
// 			result = (char *)str;
// 		str++;
// 	}
// 	return (result);
// }
