/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prct_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguy <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:17:18 by fguy              #+#    #+#             */
/*   Updated: 2022/03/02 20:17:24 by fguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prct_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		ft_putstr(s);
	return (ft_strlen(s));
}
