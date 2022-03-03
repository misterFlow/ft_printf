/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prct_d_i_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguy <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:18:24 by fguy              #+#    #+#             */
/*   Updated: 2022/03/02 20:18:31 by fguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prct_d_i_u(char *format, va_list ap)
{
	int				d;
	unsigned int	u;

	if (*format == 'd' || *format == 'i')
	{
		d = va_arg(ap, int);
		ft_putnbr(d);
		return (ft_nbrlen(d));
	}
	else if (*format == 'u')
	{
		u = va_arg(ap, unsigned int);
		if (u <= 0)
		{
			ft_putnbr(u);
			return (ft_nbrlen(u));
		}
		else if (u > 0)
		{
			ft_putnbr_us(u);
			return (ft_nbrlen_plus(u));
		}
	}
	return (0);
}
