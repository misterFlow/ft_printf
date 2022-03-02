#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

void	ft_putstr(const char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}