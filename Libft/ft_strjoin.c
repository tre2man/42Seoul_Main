/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:12:50 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/05 17:21:42 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*s;
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	i;

	len1 = strlen(s1);
	len2 = strlen(s2);
	i = 0;
	s = malloc(len1 + len2 + 1);
	while (*s1)
		s[i++] = *s1++;
	while (*s2)
		s[i++] = *s2++;
	s[i] = *s2;
	return (s);
}
