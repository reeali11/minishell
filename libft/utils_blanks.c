/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_blanks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:41:47 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:41:49 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_precision(t_formats *formats, int no_digit)
{
	int	np;
	int	n_blank;

	np = 0;
	n_blank = formats->precision - no_digit;
	np += ft_putnchar('0', n_blank, &(formats->err));
	if (formats->err < 0)
		return (formats->err);
	return (np);
}

int	print_width(t_formats *formats, int len_total, char c)
{
	int	np;
	int	n_blank;

	np = 0;
	n_blank = formats->width - len_total;
	np += ft_putnchar(c, n_blank, &(formats->err));
	if (formats->err < 0)
		return (formats->err);
	return (np);
}

void	ft_putnbr(long n, int *p_np, int *err)
{
	char	c;
	long	nbr;

	nbr = n;
	if (n < 0)
		nbr = -n;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, p_np, err);
		if (*err < 0)
			return ;
	}
	c = nbr % 10 + '0';
	*p_np += ft_putnchar(c, 1, err);
	if (*err < 0)
		return ;
}
