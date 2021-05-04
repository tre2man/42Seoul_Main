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

void *ft_memccpy(void *restrict dst, void *restrict src, int c, unsigned int n)
{
	unsigned char *dstemp;
	unsigned char *srctemp;

	dstemp = (unsigned char *)dst;
	srctemp = (unsigned char *)src;
	if (dst != src)
	{
		while (n--)
		{
			if (*srctemp == (unsigned char)c)
				return (dstemp + 1);
			*dstemp++ = *srctemp++;
		}
	}
	return (0);
}

