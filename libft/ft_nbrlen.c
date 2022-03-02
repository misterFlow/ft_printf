#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

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