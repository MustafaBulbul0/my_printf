#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int     ft_printf(const char *print, ...);
void    print_format(char type, va_list args, int *count);
void    ft_write(const char *ptr, int a, int *count);
void    print_cs(const char *str, char type, int *count);
void    print_p(void *ptr, int *count);
void    print_di(int num, int *count);
void    print_uxX(unsigned int num, const char *format, int *count);

#endif