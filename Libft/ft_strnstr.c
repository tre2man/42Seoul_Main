/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:07:23 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/05 14:18:46 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_strnstr(char *haystack, char *needle, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	correct;

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
