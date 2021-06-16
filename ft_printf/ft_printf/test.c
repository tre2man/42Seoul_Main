#include "ft_printf.h"
#ifndef _STDIO_H_
	#include <stdio.h>
#endif

int main()
{
	printf("[%7.3s]\n", "12345");
	ft_printf("[%7.3s]\n", "12345");
	return (0);
}