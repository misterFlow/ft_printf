/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prct_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguy <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:18:51 by fguy              #+#    #+#             */
/*   Updated: 2022/03/02 20:18:55 by fguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_void_case_ptr(unsigned long long int p)
{
	if (p == '\0')
	{
		write(1, "0x", 2);
		return (2);
	}
	else
		write(1, "0x", 2);
	return (2);
}

int	ft_intlen_ptr(unsigned long long int p, int i)
{
	while (p > 0)
	{
		i++;
		p = p / 16;
	}
	return (i);
}

int	ft_zero_case_ptr(unsigned long long nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (0);
}

char	*ft_dec_to_hexa_ptr(unsigned long long int nb, int nb_mod, int nb_div, int i, char *res, char c)
{
	while (nb > 0)
	{
		nb_mod = nb % 16;
		if (nb_mod <= 9)
		{
			if (nb_mod == 0)
				c = '0';
			else if (nb_mod > 0 && nb_mod <= 9)
				c = nb_mod + '0';
		}
		else if (nb_mod >= 10 && nb_mod <= 15)
			c = nb_mod + 87;
		nb_div = nb / 16;
		nb = nb_div;
		res[--i] = c;
	}
	return (res);
}

int	ft_prct_p(va_list ap)
{
	unsigned long long int	nb;
	unsigned long long int	nb_mod;
	unsigned long long int	nb_div;
	unsigned long long int	p;
	size_t					i;
	char					*res;
	char					c;

	i = 0;
	p = va_arg(ap, unsigned long long int);
	nb = p;
	nb_mod = 0;
	nb_div = 0;
	c = '0';
	ft_void_case_ptr(p);
	i = ft_intlen_ptr(p, i);
	res = malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	ft_zero_case_ptr(nb);
	ft_dec_to_hexa_ptr(nb, nb_mod, nb_div, i, res, c);
	ft_putstr(res);
	i = ft_strlen(res);
	free(res);
	return (i);
}
