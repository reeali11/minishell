/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:33:58 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:34:00 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int			sign;	
	long long	value;
	long long	value_next;

	value = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		value_next = value * 10 + sign * (*str - '0');
		if (value_next > value && sign == -1)
			return (0);
		if (value_next < value && sign == 1)
			return (-1);
		value = value_next;
		str++;
	}
	return (value);
}
