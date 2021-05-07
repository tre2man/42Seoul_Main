/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:33:21 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/06 18:48:07 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, void *src, size_t n)
{
	char	*dstemp;
	char	*srcemp;

	dstemp = (char*)dst;
	srcemp = (char*)src;
	if (dst != src)
	{
		while (n--)
			*dstemp++ = *srcemp++;
	}
	return (dst);
}
