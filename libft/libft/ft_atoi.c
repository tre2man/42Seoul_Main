/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 13:58:15 by namwkim           #+#    #+#             */
/*   Updated: 2021/05/23 12:21:14 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_iscontrol(char c)
{
	if (9 <= c && c <= 13)
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	long long	ans;
	int			minus;

	ans = 0;
	minus = 1;
	while (*str != '+' && *str != '-' && *str
			&& (ft_iscontrol(*str) || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		ans = (ans * 10) + minus * (*str - '0');
		if (ans > INT32_MAX)
			return (-1);
		else if (ans < INT32_MIN)
			return (0);
		str++;
	}
	return ((int)ans);
}
