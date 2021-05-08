/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:33:21 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/08 14:15:05 by namwkim          ###   ########.fr       */
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
