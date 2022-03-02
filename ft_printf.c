#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = nb * -1;
		}
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
		}
		ft_putchar((nb % 10) + '0');
	}
}

void	ft_putnbr_us(unsigned int nb)
{
	if (nb == 4294967295)
	    ft_putstr("4294967295");
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_nbrlen(int nb)
{
	size_t	i;

	if (nb == 0)
		return (1);
	else if (nb < 0)
		i = 1;
	else if (nb > 0)
		i = 0;
	while (nb)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

size_t	ft_nbrlen_plus(unsigned int nb)
{
	size_t	i;

	i = 0;
	while (nb)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int prct(const char *format, va_list ap, size_t idx)
{
    if (format[idx + 1] == 'd' || format[idx + 1] == 'i' || format[idx + 1] == 'u')
    {
        if (format[idx + 1] == 'd' || format[idx + 1] == 'i')
        {
            int d = va_arg(ap, int);
            ft_putnbr(d);
            return (ft_nbrlen(d));
        }
        else if (format[idx + 1] == 'u')
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
    }
    else if (format[idx + 1] == 'c' || format[idx + 1] == '%')
    {
        char    c;

        if (format[idx + 1] == 'c')
        {
            c = va_arg(ap, int);
            write(1, &c, 1);
            return (1);
        }
        else if (format[idx + 1] == '%')
        {
            write(1, "%", 1);
            return (1);
        }
    }
    else if (format[idx + 1] == 's')
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
    else if (format[idx + 1] == 'x' || format[idx + 1] == 'X')
    {   
        unsigned int    nb;
        size_t          i;
        char            *res;
        char            c;
        int             nb_mod;
        int             nb_div;

        i = 0;

        unsigned int x = va_arg(ap, unsigned int);
        nb = x;
        
        while (x > 0)
        {
            i++;
            x = x / 16;
        }
        res = malloc(sizeof(char) * (i + 1));
        res[i] = '\0';
        if (nb == 0)
        {
            write(1, "0", 1);
            free(res);
            return (1);
        }
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
                if (format[idx + 1] == 'x')
                    c = nb_mod + 87;
                else if (format[idx + 1] == 'X')
                    c = nb_mod + 55;
            }
            nb_div = nb / 16;
            nb = nb_div;
            res[--i] = c;
        }
        ft_putstr(res);
        free(res);
    }
    else if (format[idx + 1] == 'p')
    {
        unsigned long long int      nb;
        size_t                      i;
        char                        *res;
        char                        c;
        unsigned long long int      nb_mod;
        unsigned long long int      nb_div;

        i = 0;

        unsigned long long int p = va_arg(ap, unsigned long long int);
        nb = p;
        
        write(1, "0x", 2);
        while (p > 0)
        {
            i++;
            p = p / 16;
        }
        res = malloc(sizeof(char) * (i + 1));
        res[i] = '\0';
        if (nb == 0)
        {
            write(1, "0", 1);
            free(res);
            return (1);
        }
        while (nb > 0)
        {
            nb_mod = nb % 16;
            if (nb_mod <=9)
                {
                    if (nb_mod == 0)
                        c = '0';
                    else if (nb_mod > 0 && nb_mod <= 9)
                        c = nb_mod + '0';
                }
            else if (nb_mod >= 10 && nb_mod <=15)
                c = nb_mod + 87;
            nb_div = nb / 16;
            nb = nb_div;
            res[--i] = c;
        }
        ft_putstr(res);
        free(res);
    }
    return (0);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     size;
    size_t  idx;
    int     i;

    size = 0;
    idx = 0;
    i = 0;
    va_start(ap, format);

    while (format[idx] != '\0')
    {
        if (format[idx] != '%')
        {
            write(1, &format[idx], 1);
            i++;
        }
        else if (format[idx] == '%')
        {
            /*size = size + */prct(format, ap, idx);
            format++;
        }
        idx++; //or format++;
    }
    va_end(ap);
    return (size + i);
}

int main()
{
    char *p = NULL;
    char c = 'Z';
    char *P = "pointer";

    ft_printf("Test\n");
    printf("Test\n");
    printf("%s", p);
    ft_printf("\n");
    printf("\n");
    ft_printf("Florian Florian\n");
    printf("Florian Florian\n");
    ft_printf("ft_printf for d: %d %d\n", 12, 5678);
    printf("   printf for d: %d %d\n", 12, 5678);
    ft_printf("ft_printf for i: %i, %i\n", 123444, 5678);
    printf("   printf for i: %i, %i\n", 123444, 5678);
    ft_printf("ft_printf for s: %s, %s\n", "coucou", "c'est nous");
    printf("   printf for s: %s, %s\n", "coucou", "c'est nous");
    ft_printf("ft_printf for c: %c & %c\n", 'A', c);
    printf("   printf for c: %c & %c\n", 'A', c);
    ft_printf("%u %u %d\n", -2, 2, 'a');
    printf("%u %u %d\n", -2, 2, 'a');
    ft_printf("%% %%d %d %i %u %c %s\n", 42, 21, 84, 'F', "success");
    printf("%% %%d %d %i %u %c %s\n", 42, 21, 84, 'F', "success");
    ft_printf("ft_printf for x: %x\n", 42424242);
    printf("   printf for x: %x\n", 42424242);
    ft_printf("ft_printf for x: %X\n", 42424242);
    printf("   printf for x: %X\n", 42424242);
    ft_printf("ft_printf for p: %p\n", P);
    printf("   printf for p: %p\n", P);
    return (0);
}