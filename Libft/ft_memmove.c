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

void *ft_memmove(void *dest, const void *src, unsigned int n)
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
