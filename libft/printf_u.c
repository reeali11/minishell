/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:41:33 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:41:35 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	3 cases:
	(1) (prc-zero)(1234)(width-blank) for "%-. "
	(2) (width-blank)(prc-zero)(1234) for ".0" no "-"
	(3) (width-blank)(1234) for " no 0" "no ." no "-"
	(4) (wdt-zero)(1234) for "0" no "-" no "."
*/

static int	print_u1(t_formats *formats, unsigned int u)

{
	int	np;

	np = 0;
	if (formats->zero == 0)
	{
		np += print_width(formats, formats->len_total, ' ');
		if (formats->err < 0)
			return (formats->err);
	}
	else
	{
		np += print_width(formats, formats->len_total, '0');
		if (formats->err < 0)
			return (formats->err);
	}
	ft_putpnbr(u, formats, &np);
	if (formats->err < 0)
		return (formats->err);
	return (np);
}

static int	print_u2(t_formats *formats, unsigned int u)
{
	int	np;

	np = 0;
	if (formats->minus == 0 && formats->dot == 1)
	{
		np += print_width(formats, formats->len_total, ' ');
		if (formats->err < 0)
			return (formats->err);
	}
	np += print_precision(formats, formats->len_digit);
	if (formats->err < 0)
		return (formats->err);
	ft_putpnbr(u, formats, &np);
	if (formats->err < 0)
		return (formats->err);
	if (formats->minus == 1)
	{
		np += print_width(formats, formats->len_total, ' ');
		if (formats->err < 0)
			return (formats->err);
	}
	return (np);
}

int	print_u(unsigned int u, t_formats *formats)
{
	int	np;

	np = 0;
	formats->len_digit = len_uint(u, *formats, 10);
	formats->len_total = total_len(formats->precision, formats->len_digit);
	if (formats->minus == 0 && formats->dot == 0)
	{
		np += print_u1(formats, u);
		if (formats->err < 0)
			return (formats->err);
	}
	else
	{
		np += print_u2(formats, u);
		if (formats->err < 0)
			return (formats->err);
	}
	return (np);
}
