/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prct_c_prct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguy <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:17:46 by fguy              #+#    #+#             */
/*   Updated: 2022/03/02 20:17:52 by fguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_prct_c_prct(char *format, va_list ap)
{
    char    c;
    if (*format == 'c')
    {
        c = va_arg(ap, int);
        write(1, &c, 1);
        return (1);
    }
    else if (*format == '%')
    {
        write(1, "%", 1);
        return (1);
    }
    return  (0);
}
