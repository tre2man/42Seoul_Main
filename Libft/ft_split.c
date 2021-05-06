/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:33:33 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/06 18:14:26 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_countwords(char const *s, char c)
{
	unsigned int	i;
	unsigned int	ans;

	i = 1;
	ans = 0;
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

static char			*ft_cutstr(char *s, char c)
{
	char			*word;
	unsigned int	i;

	i = 0;
	while (s[i] != c)
		i++;
	word = malloc(i + 1);
	i = 0;
	while (*s != c)
		word[i++] = *s++;
	word[i] = '\0';
	return (word);
}

static char			*ft_nextstr(char *s, char c)
{
	while (*s != c)
		s++;
	return (s);
}

char				**ft_split(char const *s, char c)
{
	char			**ans;
	char			*a;
	char			*temp;
	unsigned int	i;
	unsigned int	words;

	if (!s || !c)
		return (0);
	i = 0;
	words = ft_countwords(s, c);
	a = (char*)s;
	ans = malloc(sizeof(char*) * words + 1);
	while (*a && words--)
	{
		while (*a == c)
			a++;
		ans[i++] = ft_cutstr(a, c);
		a = ft_nextstr(a, c);
	}
	ans[i] = 0;
	return (ans);
}