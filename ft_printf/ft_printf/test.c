#include "ft_printf.h"
#ifndef _STDIO_H_
#include <stdio.h>
#endif

int main()
{
	printf("[%p %p]\n", __LONG_MAX__ *2UL+1UL, -(__LONG_MAX__ *2UL+1UL));
	ft_printf("[%p %p]\n", __LONG_MAX__ *2UL+1UL, -(__LONG_MAX__ *2UL+1UL));
	return (0);
}