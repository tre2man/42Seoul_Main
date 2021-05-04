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

void		*ft_memcpy(void *restrict dst, void *restrict src, unsigned int n)
{
	char	*dstemp = (char*)dst;
	char	*srcemp = (char*)src;

	dstemp = (char*)dst;
	srcemp = (char*)src;
	if (dst != src)
	{
		while(n--)
			*dstemp++ = *srcemp++;
	}
	return (dst);
}
