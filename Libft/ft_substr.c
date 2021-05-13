/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:54:47 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/13 17:25:43 by namwkim          ###   ########.fr       */
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

static int	ft_malloc_len(size_t start, size_t len, size_t slen)
{
	if (start + len < slen)
		return (len + 1);
	else
		return (slen - start + 1);
}

char		*ft_substr(char const *s, size_t start, size_t len)
{
	char	*a;
	size_t	slen;
	size_t	mallen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start > slen || !*s)
	{
		a = malloc(1);
		*a = '\0';
		return (a);
	}
	mallen = ft_malloc_len(start, len, slen);
	if (!(a = (char*)malloc(sizeof(char) * (mallen))))
		return (0);
	a = ft_assign(a, s, len, start);
	return (a);
}
