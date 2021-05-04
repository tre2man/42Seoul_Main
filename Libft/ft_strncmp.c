/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:20:33 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/04 17:24:51 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while(n--)
	{
		if(*s1++ != *s2++)
			return (*s1 - *s2);
	}
	return (0);
}

int main()
{
	char s1[] = "hello";
	char s2[] = "heooo";
	for(int i=0;i<5;i++)
	{
		printf("%d ",strncmp(s1,s2,i));
		printf("%d\n",ft_strncmp(s1,s2,i));
	}
	return (0);
}
