/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:49:14 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/21 17:51:52 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (*s++ > 0)
			i++;
	return (i);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	if (!(s = malloc(len1 + len2 + 1)))
		return (0);
	if (s1)
		while (*s1)
			s[i++] = *s1++;
	while (*s2)
		s[i++] = *s2++;
	s[i] = *s2;
	return (s);
}

char		*ft_inchar(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (0);
}

void		*ft_memset(void *s, int c, size_t n)
{
	char	*a;

	a = (char *)s;
	while (n--)
		*a++ = c;
	return (s);
}

char		*ft_strdup(const char *s1)
{
	size_t	i;
	char	*a;

	i = 0;
	if (!(a = (char*)malloc((sizeof(char)) * (ft_strlen(s1) + 1))))
		return (0);
	while (i < ft_strlen(s1))
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}