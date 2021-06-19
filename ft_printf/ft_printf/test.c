#include "ft_printf.h"
#ifndef _STDIO_H_
	#include <stdio.h>
#endif

int main()
{
	printf("[%p]\n", 0);
	ft_printf("[%p]\n", 0);
	return (0);
}