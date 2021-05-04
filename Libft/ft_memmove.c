/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:45:21 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/04 16:50:44 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
            *destemp++ = *srctemp++;
    }
    return (dest);
}

int main()
{
    char str[] = "memmove can be very useful......";
    ft_memmove(str + 15, str + 20, 3);
    puts(str);
    return 0;
}
