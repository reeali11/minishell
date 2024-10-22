/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:34:13 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:34:16 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elem, size_t size)
{
	unsigned char	*array;

	array = (unsigned char *)malloc(num_elem * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, num_elem * size);
	return ((void *)array);
}
