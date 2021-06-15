#include "ft_printf.h"
#include <stdio.h>

int main()
{
    char *str = 0x12345;
    ft_printf("[ptr is : %-10p]\n",str);
    printf("[ptr is : %-10p]",str);
    return (0);
}