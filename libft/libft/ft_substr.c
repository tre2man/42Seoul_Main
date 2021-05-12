/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:54:47 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/08 14:32:02 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_assign(char *a, char const *s, size_t len, size_t start)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}

char		*ft_substr(char const *s, size_t start, size_t len)
{
	char	*a;
	size_t	slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start > slen || !*s)
	{
		a = malloc(1);
		*a = '\0';
		return (a);
	}
	if (start + len > slen)
		a = (char*)malloc(sizeof(char) * (len + 1));
	else if (!(a = (char*)malloc(sizeof(char) * (slen - start + 1))))
		return (0);
	a = ft_assign(a, s, len, start);
	return (a);
}
