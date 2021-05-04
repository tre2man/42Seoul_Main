/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:21:22 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/04 14:32:59 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t			ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t		i;

	i = 0;
	while(dst[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

int main()
{
	char src[] = "hello";
	char dst[] = "goods";	
	char src1[] = "hello";
	char dst1[] = "goods";	
	printf("%ld %s\n",strlcpy(dst, src, 3), dst);
	printf("%ld %s",ft_strlcpy(dst1, src1, 3), dst1);
}
