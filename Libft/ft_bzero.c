/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:23:53 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/03 16:30:06 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	char *a = (char*)s;
	while (n--)
		*a++ = 0;
}

int main()
{
	char test1[10] = "asdf";
	char test2[10] = "asdf";
	int temp = 1;

	ft_bzero(test1, temp);
	bzero(test2, temp);

	printf("%s\n%s", test1, test2);
	return (0);
}
