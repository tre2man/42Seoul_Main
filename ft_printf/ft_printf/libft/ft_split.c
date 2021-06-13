/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:33:33 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/23 17:12:11 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_freestr(char **str)
{
	size_t		i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

static size_t	ft_countwords(char const *s, char c)
{
	size_t		i;
	size_t		ans;

	i = 1;
	ans = 0;
	if (!*s)
		return (0);
	if (s[0] != c)
		ans++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			ans++;
		i++;
	}
	return (ans);
}

static char		*ft_cutstr(char *s, char c)
{
	char		*word;
	size_t		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (*s && *s != c)
		word[i++] = *s++;
	word[i] = '\0';
	return (word);
}

static char		*ft_nextstr(char *s, char c)
{
	while (*s && *s != c)
		s++;
	return (s);
}

char			**ft_split(char const *s, char c)
{
	char		**ans;
	char		*a;
	size_t		i;
	size_t		words;

	if (!s)
		return (0);
	i = 0;
	words = ft_countwords(s, c);
	a = (char*)s;
	if (!(ans = (char**)malloc(sizeof(char*) * (words + 1))))
		return (0);
	while (*a && words--)
	{
		while (*a == c)
			a++;
		if (!(ans[i++] = ft_cutstr(a, c)))
		{
			ft_freestr(ans);
			return (0);
		}
		a = ft_nextstr(a, c);
	}
	ans[i] = 0;
	return (ans);
}
