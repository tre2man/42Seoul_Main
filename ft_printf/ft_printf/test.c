#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a;
	//char *str = "123";
	a = printf("[%d]", -1);
	printf("\n%d\n", a - 2);
	a = ft_printf("[%d]", -1);
	printf("\n%d\n", a - 2);
}