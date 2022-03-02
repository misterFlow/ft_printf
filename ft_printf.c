/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguy <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:19:33 by fguy              #+#    #+#             */
/*   Updated: 2022/03/02 20:19:37 by fguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prct(const char *format, va_list ap, int size)
{
	size = 0;
    if (*format == 'd' || *format == 'i' || *format == 'u')
		size = ft_prct_d_i_u((char *)format, ap);
	else if (*format == 'c' || *format == '%')
		size = ft_prct_c_prct((char *)format, ap);
	else if (*format == 's')
		size = ft_prct_s(ap);
    else if (*format == 'x' || *format == 'X')
		size = ft_prct_x_X((char *)format, ap);
    else if (*format == 'p')
        size = ft_prct_p(ap);
    return (size);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     size;
    int     i;

    size = 0;
    i = 0;
    va_start(ap, format);

    while (*format != '\0')
    {
        if (*format != '%')
        {
            write(1, format, 1);
            i++;
        }
        else if (*format == '%')
        {
            size = ft_prct(format + 1, ap, size);
            format++;
        }
        format++;
    }
    va_end(ap);
    return (size + i);
}
