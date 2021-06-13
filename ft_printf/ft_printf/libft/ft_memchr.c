/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:50:04 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/18 09:59:27 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	const char	*a;

	a = s;
	while (n--)
	{
		if ((unsigned char)*a == (unsigned char)c)
			return ((void*)a);
		a++;
	}
	return (0);
}
