#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

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