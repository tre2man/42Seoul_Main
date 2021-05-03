/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:33:21 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/03 16:51:08 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void		*ft_memcpy(void *restrict dst, void *restrict src, size_t n)
{
	char	*dstemp = (char*)dst;
	char	*srcemp = (char*)src;
	if (dst != src)
	{
		while(n--)
			*dstemp++ = *srcemp++;
	}
	return (dst);
}

int main()
{
	char test1[10] = "asdf";
	char test2[10] = "zxcv";

	memcpy(test2, test1, 20);
	printf("%s",test2);
	return (0);
}
