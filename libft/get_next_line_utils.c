/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:40:32 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:40:34 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_len(char	*s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	gnl_strchr(char	*buffer, char chr)
{
	size_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == chr)
			return (1);
		i++;
	}
	return (0);
}

void	gnl_bzero(void *s, size_t n)
{
	size_t	i;
	char	*cast;

	i = 0;
	cast = (char *)s;
	while (i < n)
	{
		cast[i] = '\0';
		i++;
	}
}

void	*gnl_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (gnl_calloc(1, 1));
	ptr = malloc(count * size * sizeof(char));
	if (!ptr)
		return (NULL);
	gnl_bzero(ptr, count * size);
	return (ptr);
}
