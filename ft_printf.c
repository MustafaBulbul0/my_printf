/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mubulbul <mubulbul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 08:46:36 by mubulbul          #+#    #+#             */
/*   Updated: 2024/11/09 15:16:13 by mubulbul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(char type, va_list args, int *count)
{
	char	c;

	if (type == 'c')
	{
		c = (char)va_arg(args, int);
		print_cs(&c, 'c', count);
	}
	else if (type == 's')
		print_cs(va_arg(args, char *), 's', count);
	else if (type == 'p')
		print_p(va_arg(args, void *), count);
	else if (type == 'd' || type == 'i')
		print_di(va_arg(args, int), count);
	else if (type == 'u')
		print_uxx(va_arg(args, unsigned int), "0123456789", count);
	else if (type == 'x')
		print_uxx(va_arg(args, unsigned int), "0123456789abcdef", count);
	else if (type == 'X')
		print_uxx(va_arg(args, unsigned int), "0123456789ABCDEF", count);
	else if (type == '%')
		ft_write("%", 1, count);
}

int	ft_printf(const char *print, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, print);
	while (print[i])
	{
		if (print[i] == '%')
		{
			i++;
			print_format(print[i], args, &count);
		}
		else
			ft_write(&print[i], 1, &count);
		i++;
	}
	va_end(args);
	return (count);
}

#include "ft_printf.h"
#include <stdio.h>

int main(void) {
    int count;

    count = ft_printf("Character 1: %c\n", 'A');
    printf("Character 1: %c\n", 'A');
    count = ft_printf("Character 2: %c\n", 'B');
    printf("Character 2: %c\n", 'B');
    count = ft_printf("Character 3: %c\n", 'C');
    printf("Character 3: %c\n", 'C');
    count = ft_printf("Character 4: %c\n", 'D');
    printf("Character 4: %c\n", 'D');
    count = ft_printf("Character 5: %c\n", 'E');
    printf("Character 5: %c\n", 'E');

    printf("\n");

    count = ft_printf("String 1: %s\n", "Hello");
    printf("String 1: %s\n", "Hello");
    count = ft_printf("String 2: %s\n", "World");
    printf("String 2: %s\n", "World");
    count = ft_printf("String 3: %s\n", "42 is the answer");
    printf("String 3: %s\n", "42 is the answer");
    count = ft_printf("String 4: %s\n", "C programming");
    printf("String 4: %s\n", "C programming");
    count = ft_printf("String 5: %s\n", "ft_printf test");
    printf("String 5: %s\n", "ft_printf test");

    printf("\n");

    int num1 = 42;
    int num2 = -15;
    int num3 = 0;
    count = ft_printf("Pointer 1: %p\n", (void*)&num1);
    printf("Pointer 1: %p\n", (void*)&num1);
    count = ft_printf("Pointer 2: %p\n", (void*)&num2);
    printf("Pointer 2: %p\n", (void*)&num2);
    count = ft_printf("Pointer 3: %p\n", (void*)&num3);
    printf("Pointer 3: %p\n", (void*)&num3);
    count = ft_printf("Pointer 4: %p\n", (void*)&num1);
    printf("Pointer 4: %p\n", (void*)&num1);
    count = ft_printf("Pointer 5: %p %p\n", 0 , 0);
    printf("Pointer 5: %p %p\n", 0,0);

    printf("\n");

    count = ft_printf("Decimal 1: %d\n", 123);
    printf("Decimal 1: %d\n", 123);
    count = ft_printf("Decimal 2: %d\n", -456);
    printf("Decimal 2: %d\n", -456);
    count = ft_printf("Decimal 3: %d\n", 789);
    printf("Decimal 3: %d\n", 789);
    count = ft_printf("Decimal 4: %d\n", -101112);
    printf("Decimal 4: %d\n", -101112);
    count = ft_printf("Decimal 5: %d\n", 0);
    printf("Decimal 5: %d\n", 0);

    printf("\n");

    count = ft_printf("Unsigned 1: %u\n", 100);
    printf("Unsigned 1: %u\n", 100);
    count = ft_printf("Unsigned 2: %u\n", 4294967295U);
    printf("Unsigned 2: %u\n", 4294967295U);
    count = ft_printf("Unsigned 3: %u\n", 300);
    printf("Unsigned 3: %u\n", 300);
    count = ft_printf("Unsigned 4: %u\n", 0);
    printf("Unsigned 4: %u\n", 0);
    count = ft_printf("Unsigned 5 (negative): %u\n", -1);
    printf("Unsigned 5 (negative): %u\n", (unsigned int)-1);
    count = ft_printf("Unsigned 6 (negative): %u\n", -2);
    printf("Unsigned 6 (negative): %u\n", (unsigned int)-2);

    printf("\n");

    count = ft_printf("Hexadecimal (lower) 1: %x\n", 255);
    printf("Hexadecimal (lower) 1: %x\n", 255);
    count = ft_printf("Hexadecimal (lower) 2: %x\n", 4095);
    printf("Hexadecimal (lower) 2: %x\n", 4095);
    count = ft_printf("Hexadecimal (lower) 3: %x\n", 16);
    printf("Hexadecimal (lower) 3: %x\n", 16);
    count = ft_printf("Hexadecimal (lower) 4: %x\n", 1);
    printf("Hexadecimal (lower) 4: %x\n", 1);
    count = ft_printf("Hexadecimal (lower) 5: %x\n", 0);
    printf("Hexadecimal (lower) 5: %x\n", 0);

    printf("\n");

    count = ft_printf("Hexadecimal (upper) 1: %X\n", 255);
    printf("Hexadecimal (upper) 1: %X\n", 255);
    count = ft_printf("Hexadecimal (upper) 2: %X\n", 4095);
    printf("Hexadecimal (upper) 2: %X\n", 4095);
    count = ft_printf("Hexadecimal (upper) 3: %X\n", 16);
    printf("Hexadecimal (upper) 3: %X\n", 16);
    count = ft_printf("Hexadecimal (upper) 4: %X\n", 1);
    printf("Hexadecimal (upper) 4: %X\n", 1);
    count = ft_printf("Hexadecimal (upper) 5: %X\n", 0);
    printf("Hexadecimal (upper) 5: %X\n", 0);

    printf("\n");

    count = ft_printf("Percent sign: %%\n");
    printf("Percent sign: %%\n");
    count = ft_printf("Another percent sign: %%\n");
    printf("Another percent sign: %%\n");
    count = ft_printf("Yet another percent sign: %%\n");
    printf("Yet another percent sign: %%\n");
    count = ft_printf("Last percent sign: %%\n");
    printf("Last percent sign: %%\n");
    count = ft_printf("Final percent sign: %%\n");
    printf("Final percent sign: %%\n");

    return 0;
}