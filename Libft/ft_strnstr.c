/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:07:23 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/08 14:30:00 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	correct;

	if (!ft_strncmp(haystack, needle, INT32_MAX))
		return (haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		correct = 1;
		while (haystack[i + j] && needle[j])
		{
			if (haystack[i + j] != needle[j])
				correct = 0;
			if (i + j + 1 >= len)
				correct = 0;
			j++;
		}
		if (correct)
			return (char*)(haystack + i);
		i++;
	}
	return (0);
}
