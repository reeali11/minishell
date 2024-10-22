/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:38:32 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:38:35 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (*s)
	{
		str[i] = f(i, *s);
		i++;
		s++;
	}
	str[i] = '\0';
	return (str);
}

//
// char custom_map(unsigned int index, char c)
// {
// 	if ( c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }

// int	main()
// {
// 	const char *inputString = "Hello, World";
// 	char	*result = ft_strmapi(inputString, custom_map);

// 	if (result)
// 	{
// 		printf("Original String: %s\n", inputString);
// 		printf("Mapped String: %s\n", result);
// 		free(result);
// 	}
// 	else
// 		printf("Memory allocation failed.\n");
// 	return (0);
// }