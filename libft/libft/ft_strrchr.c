/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:20:22 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/08 15:30:06 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
