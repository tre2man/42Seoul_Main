/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:54:16 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/08 14:09:52 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	char	*dstemp;
	char	*srctemp;

	dstemp = (char *)dst;
	srctemp = (char *)src;
	if (dst != src)
	{
		while (n--)
		{
			*dstemp = *srctemp;
			if (*srctemp == (char)c)
				return (dstemp + 1);
			dstemp++;
			srctemp++;
		}
	}
	return (0);
}
