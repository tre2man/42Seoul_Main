/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:46:45 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/06 18:50:02 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destemp;
	const char	*srctemp;

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
