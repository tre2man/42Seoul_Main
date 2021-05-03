/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:54:16 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/03 17:45:14 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *ft_memccpy(void *restrict dst, void *restrict src, int c, size_t n)
{
	char *dstemp;
	char *srctemp;

	dstemp = (char *)dst;
	srctemp = (char *)src;
	if (dst != src)
	{
		while (n--)
		{
			if (*srctemp == (unsigned char)c)
				return (dstemp + 1);
			*dstemp++ = *srctemp++;
		}
	}
	return (NULL);
}

int main()
{
	char dst[10] = "kkkk";
	char src[10] = "asdf";
	char dst1[10] = "kkkk";
	char src1[10] = "asdf";

	printf("%s %s\n", ft_memccpy(dst, src, 'z', 4), dst);
	printf("%s %s\n", memccpy(dst1, src1, 'z', 4), dst1);
}
