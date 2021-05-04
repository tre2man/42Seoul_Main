/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 12:16:03 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/04 12:20:10 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

size_t		ft_strlen(const char *s)
{
	size_t i;
	
	i = 0;
	while(*s++)
		i++;
	return (i);
}

int main()
{
	char str[100] = "";
	printf("%u\n",strlen(str));
	printf("%u\n",ft_strlen(str));
	return (0);
}
	
