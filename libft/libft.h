/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguy <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:50:00 by fguy              #+#    #+#             */
/*   Updated: 2022/03/03 11:50:02 by fguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <ctype.h>
# include <unistd.h>
# include <fcntl.h>

size_t	ft_nbrlen(int nb);
size_t	ft_nbrlen_plus(unsigned int nb);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putnbr_us(unsigned int nb);
void	ft_putstr(const char *str);
size_t	ft_strlen(const char *str);

#endif
