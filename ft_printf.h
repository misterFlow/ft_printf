#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

int     ft_prct_c_prct(char *format, va_list ap);
int     ft_prct_d_i_u(char *format, va_list ap);
int     ft_prct_p(va_list ap);
int     ft_prct_s(va_list ap);
int     ft_prct_x_X(char *format, va_list ap);
int     ft_printf(const char *format, ...);

#endif