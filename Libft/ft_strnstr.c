/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:07:23 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/04 17:18:46 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <xlocale.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;
	int	j;
	int	correct;

	i = 0;
	while(haystack[i])
	{
		j = 0;
		correct = 1;
		while(haystack[i + j] && needle[j])
		{
			if(haystack[i + j] != needle[j])
				correct = 0;
			if (i + j + 1 >= len)
				correct = 0;
			j++;
		}
		if(correct)
			return (char*)(haystack + i);
		i++;
	}
	return (NULL);
}

int main()
{
	char big[] = "go go yogurt";
	char little[] = "";
	printf("return(gurt) : %s\n", ft_strnstr(big,little,14));	// return(gurt) : gurt
	printf("return(null) : %s\n", ft_strnstr(big,little,9));	//return(null) : null
	return (0);
}
