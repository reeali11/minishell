/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:38:13 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:38:15 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dest, const char	*src, size_t size)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	i;
	size_t	space;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (size <= len_dest)
		return (size + len_src);
	space = size - len_dest - 1;
	i = 0;
	while (i < space && src[i])
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}

// int	main()
// {
// 	char destination[5] = "Hello, ";
// 	const char *source = "World!";

// 	size_t buffer_size = sizeof(destination);

// 	size_t result = ft_strlcat(destination, source, buffer_size);

// 	printf("Concatenated String: %s\n", destination);
// 	printf("Resulting Length: %zu\n", result);

// 	return 0;
// }