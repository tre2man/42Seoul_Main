/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:57:56 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/08 14:29:01 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*a;
	unsigned int	len;
	unsigned int	i;

	if (!s || !f)
		return (0);
	i = 0;
	len = ft_strlen(s);
	if (!(a = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
	{
		if (!(a[i] = f(i, s[i])))
			a[i] = '\0';
		i++;
	}
	a[i] = '\0';
	return (a);
}