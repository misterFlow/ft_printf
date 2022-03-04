/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prct_x_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguy <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:19:13 by fguy              #+#    #+#             */
/*   Updated: 2022/03/02 20:19:16 by fguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_intlen(unsigned int x)
{
	size_t	i;

	i = 0;
	if (x == 0)
		return (1);
	while (x > 0)
	{
		i++;
		x = x / 16;
	}
	return (i);
}

char	ft_check_x_xmaj_numeric(int nb_mod)
{
	char	c;

	if (nb_mod == 0)
		c = '0';
	while (nb_mod > 0 && nb_mod <= 9)
	{
		c = (nb_mod % 10) + '0';
		nb_mod = nb_mod / 16;
	}
	return (c);
}

char	ft_check_x_xmaj_alpha(char *format, int nb_mod, char c)
{
	if (*format == 'x')
		c = nb_mod + 87;
	else if (*format == 'X')
		c = nb_mod + 55;
	return (c);
}

char	*ft_dec_to_hexa(unsigned int x, size_t i, char *res, char *format)
{
	int		nb_mod;
	int		nb_div;
	char	c;

	nb_mod = 0;
	nb_div = 0;
	while (x > 0)
	{
		nb_mod = x % 16;
		if (nb_mod >= 0 && nb_mod <= 9)
			c = ft_check_x_xmaj_numeric(nb_mod);
		else if (nb_mod >= 10 && nb_mod <= 15)
			c = ft_check_x_xmaj_alpha(format, nb_mod, c);
		nb_div = x / 16;
		x = nb_div;
		res[--i] = c;
	}
	return (res);
}

int	ft_prct_x_xmaj(char *format, va_list ap)
{
	unsigned int	x;
	size_t			i;
	char			*res;

	x = va_arg(ap, unsigned int);
	i = ft_intlen(x);
	res = malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	if (x == 0)
	{
		write(1, "0", 1);
		free(res);
		return (1);
	}
	ft_dec_to_hexa(x, i, res, format);
	ft_putstr(res);
	i = ft_strlen(res);
	free(res);
	return (i);
}
