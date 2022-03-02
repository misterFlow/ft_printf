#include "ft_printf.h"

int ft_intlen(int i, unsigned int x)
{
    while (x > 0)
    {
        i++;
        x = x / 16;
    }
    return (i);
}

int ft_zero_case(unsigned int nb, char *res)
{
    if (nb == 0)
    {
        write(1, "0", 1);
        free(res);
        return (1);
    }
    return (0);
}

char    *ft_dec_to_hexa(int  nb_mod, int nb_div, int nb, int i, char *format, char *res, char c)
{
    while (nb > 0)
    {
        nb_mod = nb % 16;
        if (nb_mod >= 0 && nb_mod <=9)
            {
                if (nb_mod == 0)
                    c = '0';
                else if (nb_mod > 0 && nb_mod <= 9)
                    c = nb_mod + '0';
            }
        else if (nb_mod >= 10 && nb_mod <=15)
        {
            if (*format == 'x')
                c = nb_mod + 87;
            else if (*format == 'X')
                c = nb_mod + 55;
        }
        nb_div = nb / 16;
        nb = nb_div;
        res[--i] = c;
    }
    return (res);
}

int ft_prct_x_X(char *format, va_list ap)
{
    unsigned int    nb;
    size_t          i;
    char            *res, c;
    int             nb_mod, nb_div;

    i = 0;

    unsigned int x = va_arg(ap, unsigned int);
    nb = x;
    nb_mod = nb_div = 0;
    c = '0';

    ft_intlen(i, x);
    res = malloc(sizeof(char) * (i + 1));
    res[i] = '\0';
    ft_zero_case(nb, res);
    ft_dec_to_hexa(nb_mod, nb_div, nb, i, format, res, c);
    ft_putstr(res);
    free(res);
    return(ft_strlen(res));
}