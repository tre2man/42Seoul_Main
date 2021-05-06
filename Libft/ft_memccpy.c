/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:54:16 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/06 18:59:02 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	size_t	*dstemp;
	size_t	*srctemp;

	dstemp = (size_t *)dst;
	srctemp = (size_t *)src;
	if (dst != src)
	{
		while (n--)
		{
			if (*srctemp == (size_t)c)
				return (dstemp + 1);
			*dstemp++ = *srctemp++;
		}
	}
	return (0);
}
