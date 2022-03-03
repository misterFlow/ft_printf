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

int	ft_intlen(int i, unsigned int x)
{
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

static int	ft_zero_case(unsigned int nb, char *res)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		free(res);
		return (1);
	}
	return (0);
}

char	*ft_dec_to_hexa(int nb, size_t i, char *format, char *res)
{
	int				nb_mod;
	int				nb_div;
	char			c;

	nb_mod = 0;
	nb_div = 0;
	c = '0';
	while (nb > 0)
	{
		nb_mod = nb % 16;
		if (nb_mod >= 0 && nb_mod <= 9)
		{
			if (nb_mod == 0)
				c = '0';
			while (nb_mod > 0 && nb_mod <= 9)
			{
				c = (nb_mod % 10) + '0';
				nb_mod = nb_mod / 16;
			}
		}
		else if (nb_mod >= 10 && nb_mod <= 15)
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

int	ft_prct_x_xmaj(char *format, va_list ap)
{
	unsigned int	x;
	unsigned int	nb;
	size_t			i;
	char			*res;

	i = 0;
	x = va_arg(ap, unsigned int);
	nb = x;
	i = ft_intlen(i, x);
	res = malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	if (ft_zero_case(nb, res) == 1)
		return (1);
	ft_dec_to_hexa(nb, i, format, res);
	ft_putstr(res);
	i = ft_strlen(res);
	free(res);
	return (i);
}
