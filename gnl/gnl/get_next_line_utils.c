/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:49:14 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/17 15:48:44 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_beforestr(char *str)
{
	static char	*before;
	char		*temp;

	before = (char*)malloc(sizeof(char) * 65);
	temp = before;
	str += ft_strlen(str);
	ft_strjoin(temp, str);
	return (before);
}

char		*ft_strjoin(char *s1, char *s2)
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

size_t		ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

size_t		ft_newstrlen(char *s)
{
	size_t	i;

	i = 0;
	while (*s > 0 && *s != '\n')
	{
		i++;
		s++;
	}
	return (i);	
}