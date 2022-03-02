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

int ft_prct_d_i_u(char *format, va_list ap)
{
    if (*format == 'd' || *format == 'i')
    {
        int d = va_arg(ap, int);
        ft_putnbr(d);
        return (ft_nbrlen(d));
    }
    else if (*format == 'u')
    {
        unsigned int u = va_arg(ap, unsigned int);
        //when given a negative integer to a variable typed as unsiged int, the printf function returns the MAX INT value for an unsigned int which is 4294967294
        //it appears the va_arg is expecting an unsigned int and since it finds a negative integer, it already transforms it to MAX INT 4294967294
        if (u <= 0) //the compiler with some flags will not allow neither comparison 'if (u < 0)' which is always FALSE nor 'if (u >= 0) which is always TRUE
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
