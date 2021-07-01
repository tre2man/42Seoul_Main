/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:33:06 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/08 16:14:05 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (src[i])
		i++;
	while (dst[j] && j < dstsize)
		j++;
	while (src[k] && j + 1 < dstsize)
	{
		dst[j] = src[k];
		j++;
		k++;
	}
	if (k)
		dst[j] = '\0';
	return (i + j - k);
}
