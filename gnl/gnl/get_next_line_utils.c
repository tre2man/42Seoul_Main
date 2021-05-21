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

char			*ft_save(char *s)
{
	static char	*saved;
	static char *back;
	char		*next;
	
	saved = (char*)malloc(sizeof(char) * 1000);
	back = (char*)malloc(sizeof(char) * 1000);
	
	saved = ft_strjoin((const char*)saved, (const char*)back);
	saved = ft_strjoin(saved, s);
	back = ft_strrchr((const char*)s, '\n');
	if (back)
		ft_strjoin(back, next);
	return (saved);
}

size_t			ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	if (!(s = malloc(len1 + len2 + 1)))
		return (0);
	while (*s1)
		s[i++] = *s1++;
	while (*s2)
		s[i++] = *s2++;
	s[i] = *s2;
	return (s);
}

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			j = i;
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		j = i;
	if (j == -1)
		return (0);
	return ((char*)s + j);
}
