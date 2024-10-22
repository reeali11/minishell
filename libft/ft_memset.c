/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:37:01 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:37:03 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *by, int c, size_t size)
{
	unsigned char	*p;

	p = (unsigned char *) by;
	while (size--)
		*p++ = (unsigned char) c;
	return (by);
}
