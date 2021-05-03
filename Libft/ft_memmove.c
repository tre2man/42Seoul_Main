//42헤더 추가

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
    char *destemp;
    const char *srctemp;

    destemp = dest;
    srctemp = src;
    if (dest > src)
    {
        destemp += n;
        srctemp += n;
        while (n--)
            *--destemp = *--srctemp;
    }
    else
    {
        while (n--)
            *--destemp = *--srctemp;
    }
    return (dest);
}

int main()
{
    char str[] = "memmove can be very useful......";
    ft_memmove(str + 20, str + 15, 11);
    puts(str);
    return 0;
}