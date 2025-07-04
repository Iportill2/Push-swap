#include <unistd.h>
#include <stdarg.h>
int ft_printf(const char *format, ...) { 
    int len = 0; 
    while (format[len]) len++; 
    write(1, format, len); 
    return len; 
}
