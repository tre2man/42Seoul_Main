/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:02:09 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/04 16:06:44 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char		*strchr(const char *s, int c)
{
	char *a;

	a = (char*)s;
	while(*a++)
	{
		if(*a == (unsigned char)c)
			return (a);
	}
	return (NULL);
}

int main()
{
	strchr("123",100);
	return (0);
}
