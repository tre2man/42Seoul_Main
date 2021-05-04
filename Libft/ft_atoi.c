/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:27:46 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/04 17:44:56 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_atoi(const char *str)
{
	int	ans;
	int minus;

	ans = 0;
	minus = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		ans = (ans * 10) + minus * (*str - '0');
		str++;	
	}
	return (ans);
}

int main()
{
	char str[] = "-2147483648";
	printf("%d %d",ft_atoi(str), atoi(str));
}
