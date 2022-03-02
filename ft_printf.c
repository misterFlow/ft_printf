#include "ft_printf.h"

int	ft_prct(const char *format, va_list ap, int size)
{
	size = 0;
    if (*format == 'd' || *format == 'i' || *format == 'u')
		size = ft_prct_d_i_u((char *)format, ap);
	else if (*format == 'c' || *format == '%')
		size = ft_prct_c_prct((char *)format, ap);
	else if (*format == 's')
		size = ft_prct_s((char *)format, ap);
    else if (*format == 'x' || *format == 'X')
		size = ft_prct_x_X((char *)format, ap);
    else if (*format == 'p')
        size = ft_prct_p((char *)format, ap);
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

int main()
{
    char *p = NULL;
    char c = 'Z';
    char *P = "pointer";

    ft_printf("Test\n");
    printf("Test\n");
    ft_printf("ft_printf for NULL pointer using s %s\n", p);
    printf("   printf for NULL pointer using s %s\n", p);
    ft_printf("ft_printf for NULL pointer using p %p\n", p);
    printf("   printf for NULL pointer using p %p\n", p);
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