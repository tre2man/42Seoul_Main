/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:33:21 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/05 16:49:55 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		*ft_memcpy(void *dst, void *src, unsigned int n)
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
