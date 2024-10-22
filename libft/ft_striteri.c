/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:38:00 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:38:02 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// int	print_sample(int	index, char	*c)
// {
// 	printf("Character at index %d: %c\n", index, *c);
// 	return (0);
// }

// int	main()
// {
// 	char testString[] = "0123456 ";

// 	printf("Original String: %s\n", testString);
//    	printf("Applying the function:\n");
// 	// Test the ft_striter function with the sample function
// 	ft_striteri(testString, print_sample);
//     return 0;
// }