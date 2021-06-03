#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main()
{
	char	*a = malloc(10);
	ft_strlcpy(a, "Hello", 6);
	printf("%s", a);
}
