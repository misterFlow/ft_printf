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

/*int	ft_void_case_ptr(unsigned long long int p)
{
	write(1, "0x", 2);
	return (2);
}*/

int	ft_intlen_ptr(unsigned long long int p, size_t i)
{
	unsigned long long int	nb;

	i = 0;
	nb = p;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		i++;
		nb = nb / 16;
	}
	return (i);
}

int	ft_zero_case_ptr(unsigned long long p, char *res)
{
	unsigned long long int	nb;

	nb = p;
	if (nb == 0)
	{
		write(1, "0", 1);
		free(res);
		return (1);
	}
	return (0);
}

char	*ft_dec_to_hexa_ptr(unsigned long long int nb, int i, char *res, char c)
{
	unsigned long long int	nb_mod;
	unsigned long long int	nb_div;

	nb_mod = 0;
	nb_div = 0;
	while (nb > 0)
	{
		nb_mod = nb % 16;
		if (nb_mod <= 9)
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
			c = nb_mod + 87;
		nb_div = nb / 16;
		nb = nb_div;
		res[--i] = c;
	}
	return (res);
}

int	ft_prct_p(va_list ap)
{
	unsigned long long int	p;
	size_t					i;
	char					*res;
	char					c;

	i = 0;
	p = va_arg(ap, unsigned long long int);
	c = '0';
	write(1, "0x", 2);
	i = ft_intlen_ptr(p, i);
	res = malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	if (ft_zero_case_ptr(p, res) == 1)
		return (1 + 2);
	ft_dec_to_hexa_ptr(p, i, res, c);
	ft_putstr(res);
	i = ft_strlen(res);
	free(res);
	return (i + 2);
}
