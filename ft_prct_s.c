#include "ft_printf.h"

int ft_prct_s(va_list ap)
{
    char *s = va_arg(ap, char *);

    if (s == 0)
    {
        write(1, "(null", 6);
        return(6);
    }
    else
        ft_putstr(s);
    return(ft_strlen(s));
}