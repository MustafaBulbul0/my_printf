#include "ft_printf.h"

void print_format(char type, va_list args, int *count)
{
    if (type == 'c')
        ft_write((char[]){(char)va_arg(args, int), '\0'}, 1, count);
    else if (type == 's')
        print_cs(va_arg(args, char *), 's', count);
    else if (type == 'p')
        print_p(va_arg(args, void *), count);
    else if (type == 'd' || type == 'i')
        print_di(va_arg(args, int), count);
    else if (type == 'u')
        print_uxX(va_arg(args, unsigned int), "0123456789", count);
    else if (type == 'x')
        print_uxX(va_arg(args, unsigned int), "0123456789abcdef", count);
    else if (type == 'X')
        print_uxX(va_arg(args, unsigned int), "0123456789ABCDEF", count);
    else if (type == '%')
        ft_write("%", 1, count);
}

int ft_printf(const char *print, ...)
{
    va_list args;
    int count = 0;
    int i = 0;

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
