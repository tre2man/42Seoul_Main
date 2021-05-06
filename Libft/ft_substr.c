/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:54:47 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/06 18:57:53 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, size_t start, size_t len)
{
	char	*a;
	size_t	slen;
	size_t	i;

	i = 0;
	slen = ft_strlen(s);
	if (slen + 1 < start-- + len)
		return (0);
	a = malloc(len + 1);
	while (s[start])
		a[i++] = s[start++];
	a[i] = s[start];
	return (a);
}
