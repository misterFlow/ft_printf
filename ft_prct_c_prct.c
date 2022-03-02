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
    return (0);
}