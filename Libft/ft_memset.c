/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:38:48 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/03 16:10:30 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	i = 0;

	char	*a = (char*)b;
	while ((i < len) && (a + i))
	{
		*(a + i) = c;
		i++;
	}
	return (b);
}
	

int			main()
{
	char		test1[10] = "asdf";
	char		test2[10] = "asdf";
	int		i = 0;
	int		temp = 1;

	printf("%lu %lu\n", sizeof(test1), sizeof(test2));	
	ft_memset(test1, temp, strlen(test1));
	while (i < 10)
		printf("%d ", test1[i++]);
	
	printf("\n");
	i = 0;

	memset(test2, temp, strlen(test2));
	while (i < 10)
		printf("%d ", test2[i++]);
	
	return (0);
}
