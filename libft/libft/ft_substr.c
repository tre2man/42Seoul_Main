/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:54:47 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/18 15:29:42 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, size_t start, size_t len)
{
	char	*a;
	size_t	slen;
	size_t	i;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (slen < start + len)
		len = slen - start;
	if (!(a = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		a[i] = s[i + start];
		i++;
	}
	a[i] = '\0';
	return (a);
}
