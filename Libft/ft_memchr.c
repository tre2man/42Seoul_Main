/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 11:50:04 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/04 12:13:52 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char *a;

	a = s;
	while(n--)
	{
		if (*a == c)
			return ((void*)a);
		a++;
	}
	return (NULL);
}

int main()
{
	char test[100] = "12345";
	printf("%s\n",ft_memchr(test, '3', 5));
	printf("%s",memchr(test, '3', 5));
	return (0);
}
