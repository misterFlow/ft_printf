/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fguy <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 20:19:56 by fguy              #+#    #+#             */
/*   Updated: 2022/03/02 20:19:58 by fguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
