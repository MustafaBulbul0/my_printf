#include "ft_printf.h"

void ft_write(const char *ptr, int a, int *count)
{
    write(1, ptr, a);
    *count += a;
}

void print_cs(const char *str, char type, int *count)
{
    int j;

    if (str == NULL && type == 's')
    {
        ft_write("(null)", 6, count);
        return;
    }
    if (type == 's')
    {
        j = 0;
        while (str[j])
        {
            ft_write(&str[j], 1, count);
            j++;
        }
    }
    else if (type == 'c')
    {
        ft_write(str, 1, count);
    }
}

void print_p(void *ptr, int *count)
{
    unsigned long long address;
    char *hexa;
    char htoa[15];
    int j = 14;

    if (!ptr)
    {
        ft_write("0x0", 3, count);
        return;
    }
    hexa = "0123456789abcdef";
    address = (unsigned long long)ptr;
    htoa[0] = '0';
    htoa[1] = 'x';
    htoa[j--] = '\0';
    while (address > 0)
    {
        htoa[j--] = hexa[address % 16];
        address /= 16;
    }
    ft_write(htoa, 14, count);
}

void print_di(int num, int *count)
{
    unsigned int n_num;
    char a[10];
    int j;

    j = 0;
    if (num == 0)
    {
        ft_write("0", 1, count);
        return;
    }
    if (num < 0)
    {
        ft_write("-", 1, count);
        n_num = -num;
    }
    else
        n_num = num;
    while (n_num > 0)
    {
        a[j++] = (n_num % 10) + '0';
        n_num /= 10;
    }
    while (j > 0)
        ft_write(&a[--j], 1, count);
}

void print_uxX(unsigned int num, const char *format, int *count)
{
    char r_ptr[11];
    int j;

    j = 0;
    if (num == 0)
    {
        ft_write("0", 1, count);
        return ;
    }
    while (num > 0)
    {
        r_ptr[j++] = format[num % 16];
        num /= 16;
    }
    while (j > 0)
        ft_write(&r_ptr[--j], 1, count);
}