/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:38:46 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:38:47 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	if ((big == NULL && little == NULL) || (big == NULL && len == 0))
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[b] && b < len)
	{
		l = 0;
		while (big[b + l] == little[l] && b + l < len)
		{
			l++;
			if (little[l] == '\0')
				return ((char *)&big[b]);
		}
		b++;
	}
	return (0);
}
